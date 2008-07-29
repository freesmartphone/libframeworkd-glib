/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
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
#include "frameworkd-glib-dbus.h"
#include "frameworkd-glib-call.h"
#include "frameworkd-glib-sim.h"
#include "frameworkd-glib-network.h"
#include "frameworkd-glib-device.h"
#include "frameworkd-glib-sms.h"
#include "dialer-marshal.h"

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
        lose ("%s: %s", prefix, error->message);
}

/* Be careful with this function. Dbus error is freed ! */
GError* dbus_handle_errors(GError *dbus_error) {
        const char *error_name;
        GError *error = NULL;
        if ((dbus_error->domain==DBUS_GERROR)&&(dbus_error->code==DBUS_GERROR_REMOTE_EXCEPTION))
                error_name = dbus_g_error_get_name(dbus_error);
        else
                error_name = "";
        if(!strncmp(error_name, SIM_INTERFACE, strlen(SIM_INTERFACE))) {
                error = sim_handle_errors(dbus_error);
        } else if(!strncmp(error_name, CALL_INTERFACE, strlen(CALL_INTERFACE))) {
                error = call_handle_errors(dbus_error);
        } else if(!strncmp(error_name, NETWORK_INTERFACE, strlen(NETWORK_INTERFACE))) {
                error =  network_handle_errors(dbus_error);
        } else if(!strncmp(error_name, DEVICE_INTERFACE, strlen(DEVICE_INTERFACE))) {
                error = device_handle_errors(dbus_error);
        } else {
                lose_gerror ("Failed to handle device error", dbus_error);
        }
        g_error_free(dbus_error);
        return error;
}

void dbus_connect_to_bus() {
        DBusGConnection *bus;

        GError *error = NULL;
        g_type_init ();

        {
                GLogLevelFlags fatal_mask;

                fatal_mask = g_log_set_always_fatal (G_LOG_FATAL_MASK);
                fatal_mask |= G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL;
                g_log_set_always_fatal (fatal_mask);
        }
#ifdef DEBUG
        printf("Trying to get the system bus\n");
#endif
        bus = dbus_g_bus_get (DBUS_BUS_SYSTEM, &error);


        if (!bus)
                lose_gerror ("Couldn't connect to system bus", error);
#ifdef DEBUG
        printf("Getting the interfaces\n");
#endif

        networkBus = dbus_g_proxy_new_for_name (bus, GSMD_BUS, BUS_PATH, NETWORK_INTERFACE);
        simBus = dbus_g_proxy_new_for_name (bus, GSMD_BUS, BUS_PATH, SIM_INTERFACE);
        callBus = dbus_g_proxy_new_for_name (bus, GSMD_BUS, BUS_PATH, CALL_INTERFACE);
        deviceBus = dbus_g_proxy_new_for_name (bus, GSMD_BUS, BUS_PATH, DEVICE_INTERFACE);
        smsBus = dbus_g_proxy_new_for_name (bus, GSMD_BUS, BUS_PATH, SMS_INTERFACE);
        if(!(networkBus && simBus && callBus && deviceBus)) {
                printf("Couln't connect to the interfaces");
                exit(-1);
        }

        dbus_g_object_register_marshaller (g_cclosure_user_marshal_VOID__UINT_STRING_BOXED, G_TYPE_NONE, G_TYPE_UINT, G_TYPE_STRING, DBUS_TYPE_G_STRING_VARIANT_HASHTABLE, G_TYPE_INVALID);
        dbus_g_object_register_marshaller (g_cclosure_user_marshal_VOID__UINT_BOOLEAN_STRING, G_TYPE_NONE, G_TYPE_UINT, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_INVALID);

#ifdef DEBUG
        printf("Adding signals.\n");
#endif

        dbus_g_proxy_add_signal (networkBus, "Status", DBUS_TYPE_G_STRING_VARIANT_HASHTABLE, G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (networkBus, "Status", G_CALLBACK (network_status_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added network Status.\n");
#endif

        dbus_g_proxy_add_signal (networkBus, "SignalStrength", G_TYPE_UINT , G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (networkBus, "SignalStrength", G_CALLBACK (network_signal_strength_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added network SignalStrength.\n");
#endif

        dbus_g_proxy_add_signal (simBus, "AuthStatus", G_TYPE_STRING, G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (simBus, "AuthStatus", G_CALLBACK (sim_auth_status_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added sim AuthStatus.\n");
#endif

        dbus_g_proxy_add_signal (callBus, "CallStatus", G_TYPE_UINT, G_TYPE_STRING, DBUS_TYPE_G_STRING_VARIANT_HASHTABLE, G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (callBus, "CallStatus", G_CALLBACK (call_status_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added call CallStatus.\n");
#endif

        dbus_g_proxy_add_signal (smsBus, "MessageSent", G_TYPE_UINT, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (smsBus, "MessageSent", G_CALLBACK (sms_message_sent_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added sms MessageSent.\n");
#endif

        dbus_g_proxy_add_signal (smsBus, "IncomingMessage", G_TYPE_UINT, G_TYPE_INVALID);
        dbus_g_proxy_connect_signal (smsBus, "IncomingMessage", G_CALLBACK (sms_incoming_message_handler),
                        NULL, NULL);
#ifdef DEBUG
        printf("Added sms IncomingMessage.\n");
#endif

}
