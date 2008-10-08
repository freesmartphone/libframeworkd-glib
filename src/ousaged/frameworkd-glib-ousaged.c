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
#include "frameworkd-glib-ousaged.h"
#include "frameworkd-glib-ousaged-dbus.h"
#include "dbus/ousaged.h"

DBusGProxy *ousagedBus = NULL;

GError* ousaged_handle_errors(GError *dbus_error) {
    // TODO: Add error handling when frameword code is ready
    lose_gerror ("Unknown ousaged error", dbus_error);
    // Fix warning
    return NULL;
}


typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ousaged_request_resource_data_t;

void ousaged_request_resource_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ousaged_request_resource_data_t *data = userdata;
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

void ousaged_request_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_ousaged();

    ousaged_request_resource_data_t *data = g_malloc (sizeof (ousaged_request_resource_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Usage_request_resource_async (ousagedBus, name, ousaged_request_resource_callback, data);
}


typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ousaged_release_resource_data_t;

void ousaged_release_resource_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ousaged_release_resource_data_t *data = userdata;
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

void ousaged_release_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_ousaged();

    ousaged_release_resource_data_t *data = g_malloc (sizeof (ousaged_release_resource_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Usage_release_resource_async (ousagedBus, name, ousaged_release_resource_callback, data);
}


typedef struct
{
    void (*callback)(GError *, char**, gpointer);
    gpointer userdata;
} ousaged_list_resources_data_t;

void ousaged_list_resources_callback(DBusGProxy* bus, char** resources, GError *dbus_error, gpointer userdata) {
    ousaged_list_resources_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, resources, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void ousaged_list_resources(void (*callback)(GError *, char**, gpointer), gpointer userdata) {
    dbus_connect_to_ousaged();

    ousaged_list_resources_data_t *data = g_malloc (sizeof (ousaged_list_resources_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Usage_list_resources_async (ousagedBus, ousaged_list_resources_callback, data);
}

