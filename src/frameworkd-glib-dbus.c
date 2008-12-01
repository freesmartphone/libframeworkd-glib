/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
 *              quickdev
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Public License as published by
 *  the Free Software Foundation; version 2 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-bindings.h>
#include "ogsmd/frameworkd-glib-ogsmd-dbus.h"
#include "ogsmd/frameworkd-glib-ogsmd-call.h"
#include "ogsmd/frameworkd-glib-ogsmd-sim.h"
#include "ogsmd/frameworkd-glib-ogsmd-network.h"
#include "ogsmd/frameworkd-glib-ogsmd-device.h"
#include "ogsmd/frameworkd-glib-ogsmd-sms.h"
#include "odeviced/frameworkd-glib-odeviced-dbus.h"
#include "odeviced/frameworkd-glib-odeviced-idlenotifier.h"
#include "odeviced/frameworkd-glib-odeviced-powersupply.h"
#include "dialer-marshal.h"

DBusGConnection* bus;

void lose (const char *str, ...)
{
    va_list args;

    va_start (args, str);

    vfprintf (stderr, str, args);
    fputc ('\n', stderr);

    va_end (args);

    exit (1);
}

void lose_gerror (const char *prefix, GError *error)
{
    lose ("%s: %s, %d (%s), code %d", prefix, error->message, error->domain, g_quark_to_string(error->domain), error->code);
}


GError* dbus_handle_errors(GError *dbus_error) {
    const char *error_name;
    GError *error = NULL;
    if(dbus_error->domain == DBUS_GERROR) {
        if(dbus_error->code == DBUS_GERROR_REMOTE_EXCEPTION) {
            error_name = dbus_g_error_get_name(dbus_error);

            if(!strncmp(error_name, SIM_INTERFACE, strlen(SIM_INTERFACE))) {
                error = ogsmd_sim_handle_errors(dbus_error);
            } else if(!strncmp(error_name, CALL_INTERFACE, strlen(CALL_INTERFACE))) {
                error = ogsmd_call_handle_errors(dbus_error);
            } else if(!strncmp(error_name, NETWORK_INTERFACE, strlen(NETWORK_INTERFACE))) {
                error =  ogsmd_network_handle_errors(dbus_error);
            } else if(!strncmp(error_name, DEVICE_INTERFACE, strlen(DEVICE_INTERFACE))) {
                error = ogsmd_device_handle_errors(dbus_error);
            } else {
                lose_gerror ("Failed to handle dbus error", dbus_error);
            }
        } else {
            error = dbus_handle_internal_errors(dbus_error);
        }
    } else {
        lose_gerror("Unknown dbus error", dbus_error);
    }

    return error;
}


GError* dbus_handle_internal_errors(GError *error) {
    int dbusError = 0;

    if(error->code == DBUS_GERROR_SERVICE_UNKNOWN) {
        dbusError = DBUS_ERROR_SERVICE_NOT_AVAILABLE;
    } else if(error->code == DBUS_GERROR_NO_REPLY) {
        dbusError = DBUS_ERROR_NO_REPLY;
    } else {
        lose_gerror("Unknown internal dbus error", error);
    }
    //dbus_connect_to_bus(NULL);
    return g_error_new (DBUS_ERROR, dbusError, error->message);
}

void dbus_connect_to_bus(FrameworkdHandlers* frameworkdHandler ) {
    if(frameworkdHandler != NULL)
        fwdHandlers = frameworkdHandler;

    GError *error = NULL;
    g_type_init ();

    {
        GLogLevelFlags fatal_mask;

        fatal_mask = g_log_set_always_fatal (G_LOG_FATAL_MASK);
        fatal_mask |= G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL;
        g_log_set_always_fatal (fatal_mask);
    }
    g_debug("Trying to get the system bus");
    bus = dbus_g_bus_get (DBUS_BUS_SYSTEM, &error);


    if (!bus)
        lose_gerror ("Couldn't connect to system bus", error);


    dbus_g_object_register_marshaller (g_cclosure_user_marshal_VOID__INT_STRING_BOXED, G_TYPE_NONE, G_TYPE_INT, G_TYPE_STRING, dbus_get_type_g_string_variant_hashtable(), G_TYPE_INVALID);
    dbus_g_object_register_marshaller (g_cclosure_user_marshal_VOID__UINT_BOOLEAN_STRING, G_TYPE_NONE, G_TYPE_UINT, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_INVALID);
    dbus_g_object_register_marshaller (g_cclosure_marshal_VOID__INT, G_TYPE_NONE, G_TYPE_INT, G_TYPE_INVALID);

    if(frameworkdHandler != NULL) {
        g_debug("Adding signals.");
        if(frameworkdHandler->networkStatus != NULL) {
            dbus_connect_to_ogsmd_network();
            dbus_g_proxy_add_signal (networkBus, "Status", dbus_get_type_g_string_variant_hashtable(), G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (networkBus, "Status", G_CALLBACK (ogsmd_network_status_handler),
                    frameworkdHandler->networkStatus, NULL);

            g_debug("Added network Status.");
        }
        if(frameworkdHandler->networkSignalStrength != NULL) {
            dbus_connect_to_ogsmd_network();
            dbus_g_proxy_add_signal (networkBus, "SignalStrength", G_TYPE_UINT , G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (networkBus, "SignalStrength", G_CALLBACK (ogsmd_network_signal_strength_handler),
                    frameworkdHandler->networkSignalStrength, NULL);
            g_debug("Added network SignalStrength.");
        }
        if(frameworkdHandler->simAuthStatus != NULL) {
            dbus_connect_to_ogsmd_sim();
            dbus_g_proxy_add_signal (simBus, "AuthStatus", G_TYPE_STRING, G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (simBus, "AuthStatus", G_CALLBACK (ogsmd_sim_auth_status_handler),
                    frameworkdHandler->simAuthStatus, NULL);
            g_debug("Added sim AuthStatus.");
        }
        if(frameworkdHandler->simIncomingStoredMessage != NULL) {
            dbus_connect_to_ogsmd_sim();
            dbus_g_proxy_add_signal (simBus, "IncomingStoredMessage", G_TYPE_INT, G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (simBus, "IncomingStoredMessage", G_CALLBACK (ogsmd_sim_incoming_stored_message_handler),
                    frameworkdHandler->simIncomingStoredMessage, NULL);
            g_debug("Added sim IncomingStoredMessage.");
        }

        if(frameworkdHandler->callCallStatus != NULL) {
            dbus_connect_to_ogsmd_call();
            dbus_g_proxy_add_signal (callBus, "CallStatus", G_TYPE_INT, G_TYPE_STRING, dbus_get_type_g_string_variant_hashtable(), G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (callBus, "CallStatus", G_CALLBACK (ogsmd_call_status_handler),
                    frameworkdHandler->callCallStatus, NULL);
            g_debug("Added call CallStatus.");
        }

        if(frameworkdHandler->deviceIdleNotifierState != NULL) {
            dbus_connect_to_odeviced_idle_notifier();
            dbus_g_proxy_add_signal (odevicedIdleNotifierBus, "State", G_TYPE_STRING, G_TYPE_INVALID);
            dbus_g_proxy_connect_signal (odevicedIdleNotifierBus, "State", G_CALLBACK (odeviced_idle_notifier_state_handler),
                    frameworkdHandler->deviceIdleNotifierState, NULL);
            g_debug("Added device Idle Notifier State.");
        }

    }
}


DBusGProxy *dbus_connect_to_interface(char *bus_name, char *path, char *interface, char *interface_name) {
    DBusGProxy *itf = NULL;
    if(bus != NULL) {
        itf = dbus_g_proxy_new_for_name (bus, bus_name, path, interface);
        if(itf == NULL) {
            printf("Couln't connect to the %s Interface", interface_name);
        }
    }
    return itf;
}

void dbus_free_data(GType type, gpointer data) {
    GValue foo;
    g_value_init(&foo, type);
    g_value_take_boxed(&foo, data);
    g_value_unset(&foo);
}

GType dbus_get_type_g_string_variant_hashtable() {
    static GType foo = 0; 
    if (G_UNLIKELY (foo ==0)) 
        foo = dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE);
    return foo;
}
GType dbus_get_type_g_string_int_int_int_array() {
    static GType foo = 0;
    if (G_UNLIKELY (foo ==0))
        foo = dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INVALID)); 
    return foo;
}
GType dbus_get_type_int_g_string_g_string_variant_hashtable_array() {
    static GType foo = 0;
    if (G_UNLIKELY (foo ==0))
        foo = dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), G_TYPE_INVALID)); 
    return foo;
}

GType dbus_get_type_int_g_string_g_string_g_string_array() {
    static GType foo = 0;
    if (G_UNLIKELY (foo ==0))
        foo = dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INVALID));
    return foo;
}

FrameworkdHandlers *new_frameworkd_handler() {
        FrameworkdHandlers *frameworkdHandler= NULL;
        frameworkdHandler = malloc(sizeof(FrameworkdHandlers));
        if(frameworkdHandler == NULL) {
                g_debug("Couldn't alloc frameworkdHandler.");
                return NULL;
        }
        
        frameworkdHandler->networkStatus = NULL;
        frameworkdHandler->networkSignalStrength = NULL;
        frameworkdHandler->simAuthStatus = NULL;
        frameworkdHandler->simIncomingStoredMessage = NULL;
        frameworkdHandler->callCallStatus = NULL;
        frameworkdHandler->deviceIdleNotifierState = NULL;

        return frameworkdHandler;
}

