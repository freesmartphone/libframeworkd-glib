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
#include "frameworkd-glib-odeviced-idlenotifier.h"
#include "frameworkd-glib-odeviced-dbus.h"
#include "dbus/idlenotifier.h"

DBusGProxy *odevicedIdleNotifierBus = NULL;

GError* odeviced_idle_notifier_handle_errors(GError *dbus_error) {
    // TODO: Add error handling when frameword code is ready
    lose_gerror ("Unknown odeviced error", dbus_error);
    // Fix warning
    return NULL;
}

int odeviced_idle_notifier_get_state_from_dbus(const char *state) {
    if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_BUSY)) {
        return DEVICE_IDLE_STATE_BUSY;
    } else if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_IDLE)) {
        return DEVICE_IDLE_STATE_IDLE;
    } else if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_IDLE_DIM)) {
        return DEVICE_IDLE_STATE_IDLE_DIM;
    } else if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_PRELOCK)) {
        return DEVICE_IDLE_STATE_PRELOCK;
    } else if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_LOCK)) {
        return DEVICE_IDLE_STATE_LOCK;
    } else if(!strcmp(state, DBUS_DEVICE_IDLE_STATE_SUSPEND)) {
        return DEVICE_IDLE_STATE_SUSPEND;
    } 
    
    return DEVICE_IDLE_STATE_AWAKE;
}

char * odeviced_idle_notifier_get_state_for_dbus(int state) {
    switch(state) {
        case DEVICE_IDLE_STATE_BUSY:
            return DBUS_DEVICE_IDLE_STATE_BUSY;
        case DEVICE_IDLE_STATE_IDLE:
            return DBUS_DEVICE_IDLE_STATE_IDLE;
        case DEVICE_IDLE_STATE_IDLE_DIM:
            return DBUS_DEVICE_IDLE_STATE_IDLE_DIM;
        case DEVICE_IDLE_STATE_PRELOCK:
            return DBUS_DEVICE_IDLE_STATE_PRELOCK;
        case DEVICE_IDLE_STATE_LOCK:
            return DBUS_DEVICE_IDLE_STATE_LOCK;
        case DEVICE_IDLE_STATE_SUSPEND:
            return DBUS_DEVICE_IDLE_STATE_SUSPEND;
        case DEVICE_IDLE_STATE_AWAKE:
            return DBUS_DEVICE_IDLE_STATE_AWAKE;
    }
}


typedef struct
{
    void (*callback)(GError *, int, gpointer);
    gpointer userdata;
} odeviced_idle_notifier_get_state_data_t;


void odeviced_idle_notifier_get_state_callback(DBusGProxy* bus, char* state, GError *dbus_error, gpointer userdata) {
    odeviced_idle_notifier_get_state_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, odeviced_idle_notifier_get_state_from_dbus(state), data->userdata);
        if(error != NULL) {
            g_error_free(error);
        } else {
            free(state);
        }
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_idle_notifier_get_state(void (*callback)(GError *, int, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_idle_notifier();

    odeviced_idle_notifier_get_state_data_t *data = g_malloc (sizeof (odeviced_idle_notifier_get_state_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_IdleNotifier_get_state_async (odevicedIdleNotifierBus, odeviced_idle_notifier_get_state_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} odeviced_idle_notifier_set_state_data_t;


void odeviced_idle_notifier_set_state_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    odeviced_idle_notifier_set_state_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_idle_notifier_set_state(int state, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_idle_notifier();

    odeviced_idle_notifier_set_state_data_t *data = g_malloc (sizeof (odeviced_idle_notifier_set_state_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_IdleNotifier_set_state_async (odevicedIdleNotifierBus, odeviced_idle_notifier_get_state_for_dbus(state), odeviced_idle_notifier_set_state_callback, data);
}

void odeviced_idle_notifier_state_handler (DBusGProxy *proxy, const char * state, gpointer user_data)
{
    void (*callback)(int) = NULL;

    callback = user_data;

    if(callback != NULL)
        (*callback)(odeviced_idle_notifier_get_state_from_dbus(state));
}
