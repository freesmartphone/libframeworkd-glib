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
#include "frameworkd-glib-ogsmd-device.h"
#include "frameworkd-glib-ogsmd-dbus.h"
#include "dbus/device.h"

DBusGProxy *deviceBus = NULL;

GError* ogsmd_device_handle_errors(GError *dbus_error) {
    const char *error_name = dbus_g_error_get_name(dbus_error);
    int deviceError = 0;

    if(!strcmp(error_name, DBUS_DEVICE_ERROR_TIMEOUT)) {
        deviceError = DEVICE_ERROR_TIMEOUT;
    } else if(!strcmp(error_name, DBUS_DEVICE_ERROR_NOT_PRESENT)) {
        deviceError = DEVICE_ERROR_NOT_PRESENT;
    } else if(!strcmp(error_name, DBUS_DEVICE_ERROR_FAILED)) {
        deviceError = DEVICE_ERROR_FAILED;
    } else {
        lose_gerror ("Unknown device error", dbus_error);
    }
    return g_error_new (DEVICE_ERROR, deviceError, "TODO");
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_device_set_antenna_power_data_t;

void ogsmd_device_set_antenna_power_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_device_set_antenna_power_data_t *data = userdata;
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

void ogsmd_device_set_antenna_power(gboolean power, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_set_antenna_power_data_t *data = g_malloc (sizeof (ogsmd_device_set_antenna_power_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_set_antenna_power_async (deviceBus, power, ogsmd_device_set_antenna_power_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gboolean power, gpointer);
    gpointer userdata;
} ogsmd_device_get_antenna_power_data_t;

void ogsmd_device_get_antenna_power_callback(DBusGProxy* bus, gboolean power, GError *dbus_error, gpointer userdata) {
    ogsmd_device_get_antenna_power_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, power, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void ogsmd_device_get_antenna_power(void (*callback)(GError *, gboolean power, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_get_antenna_power_data_t *data = g_malloc (sizeof (ogsmd_device_get_antenna_power_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_get_antenna_power_async(deviceBus, ogsmd_device_get_antenna_power_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GHashTable* info, gpointer);
    gpointer userdata;
} ogsmd_device_get_info_data_t;

void ogsmd_device_get_info_callback(DBusGProxy* bus, GHashTable *info, GError *dbus_error, gpointer userdata) {
    ogsmd_device_get_info_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, info, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL)
        g_error_free(dbus_error);
    else
        g_hash_table_destroy(info);
    g_free(data);
}

void ogsmd_device_get_info(void (*callback)(GError *, GHashTable *info, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_get_info_data_t *data = g_malloc (sizeof (ogsmd_device_get_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_get_info_async(deviceBus, ogsmd_device_get_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GHashTable* features, gpointer);
    gpointer userdata;
} ogsmd_device_get_features_data_t;

void ogsmd_device_get_features_callback(DBusGProxy* bus, GHashTable *features, GError *dbus_error, gpointer userdata) {
    ogsmd_device_get_features_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, features, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
    g_hash_table_destroy(features);
}

void ogsmd_device_get_features(void (*callback)(GError *, GHashTable *features, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_get_features_data_t *data = g_malloc (sizeof (ogsmd_device_get_features_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_get_features_async(deviceBus, ogsmd_device_get_features_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_device_prepare_to_suspend_data_t;

void ogsmd_device_prepare_to_suspend_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_device_prepare_to_suspend_data_t *data = userdata;
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

void ogsmd_device_prepare_to_suspend(void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_prepare_to_suspend_data_t *data = g_malloc (sizeof (ogsmd_device_prepare_to_suspend_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_prepare_to_suspend_async(deviceBus, ogsmd_device_prepare_to_suspend_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_device_recover_from_suspend_data_t;

void ogsmd_device_recover_from_suspend_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_device_recover_from_suspend_data_t *data = userdata;
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

void ogsmd_device_recover_from_suspend(void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_ogsmd_device();

    ogsmd_device_recover_from_suspend_data_t *data = g_malloc (sizeof (ogsmd_device_recover_from_suspend_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_Device_recover_from_suspend_async(deviceBus, ogsmd_device_recover_from_suspend_callback, data);
}


