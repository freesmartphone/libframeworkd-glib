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
#include "frameworkd-glib-odeviced-powersupply.h"
#include "frameworkd-glib-odeviced-dbus.h"
#include "dbus/powersupply.h"

DBusGProxy *odevicedPowerSupplyBus = NULL;

GError* odeviced_power_supply_handle_errors(GError *dbus_error) {
    // TODO: Add error handling when frameword code is ready
    lose_gerror ("Unknown odeviced error", dbus_error);
    // Fix warning
    return NULL;
}

int odeviced_power_supply_get_status_from_dbus(const char *status) {
    if(!strcmp(status, DBUS_DEVICE_POWER_STATE_CHARGING)) {
        return DEVICE_POWER_STATE_CHARGING;
    } else if(!strcmp(status, DBUS_DEVICE_POWER_STATE_DISCHARGING)) {
        return DEVICE_POWER_STATE_DISCHARGING;
    } else if(!strcmp(status, DBUS_DEVICE_POWER_STATE_FULL)) {
        return DEVICE_POWER_STATE_FULL;
    } else if(!strcmp(status, DBUS_DEVICE_POWER_STATE_EMPTY)) {
        return DEVICE_POWER_STATE_EMPTY;
    } 
    
    return DEVICE_POWER_STATE_CRITICAL;
}

char * odeviced_power_supply_get_status_for_dbus(int status) {
    switch(status) {
        case DEVICE_POWER_STATE_CHARGING:
            return DBUS_DEVICE_POWER_STATE_CHARGING;
        case DEVICE_POWER_STATE_DISCHARGING:
            return DBUS_DEVICE_POWER_STATE_DISCHARGING;
        case DEVICE_POWER_STATE_FULL:
            return DBUS_DEVICE_POWER_STATE_FULL;
        case DEVICE_POWER_STATE_EMPTY:
            return DBUS_DEVICE_POWER_STATE_EMPTY;
        case DEVICE_POWER_STATE_CRITICAL:
            return DBUS_DEVICE_POWER_STATE_CRITICAL;
    }
}


typedef struct
{
    void (*callback)(GError *, GHashTable*, gpointer);
    gpointer userdata;
} odeviced_power_supply_get_info_data_t;


void odeviced_power_supply_get_info_callback(DBusGProxy* bus, GHashTable* properties, GError *dbus_error, gpointer userdata) {
    odeviced_power_supply_get_info_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, properties, data->userdata);
        if(error != NULL) {
            g_error_free(error);
        } else {
            g_free(properties);
        }
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_power_supply_get_info(void (*callback)(GError *, GHashTable*, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_power_supply();

    odeviced_power_supply_get_info_data_t *data = g_malloc (sizeof (odeviced_power_supply_get_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_PowerSupply_get_info_async (odevicedPowerSupplyBus, odeviced_power_supply_get_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, int, gpointer);
    gpointer userdata;
} odeviced_power_supply_get_capacity_data_t;


void odeviced_power_supply_get_capacity_callback(DBusGProxy* bus, int capacity, GError *dbus_error, gpointer userdata) {
    odeviced_power_supply_get_capacity_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, capacity, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_power_supply_get_capacity(void (*callback)(GError *, int, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_power_supply();

    odeviced_power_supply_get_capacity_data_t *data = g_malloc (sizeof (odeviced_power_supply_get_capacity_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_PowerSupply_get_capacity_async (odevicedPowerSupplyBus, odeviced_power_supply_get_capacity_callback, data);
}

typedef struct
{
    void (*callback)(GError *, int, gpointer);
    gpointer userdata;
} odeviced_power_supply_get_power_status_data_t;


void odeviced_power_supply_get_power_status_callback(DBusGProxy* bus, char* status, GError *dbus_error, gpointer userdata) {
    odeviced_power_supply_get_power_status_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, odeviced_power_supply_get_status_from_dbus(status), data->userdata);
        if(error != NULL) g_error_free(error);
        else free(status);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_power_supply_get_power_status(void (*callback)(GError *, int, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_power_supply();

    odeviced_power_supply_get_power_status_data_t *data = g_malloc (sizeof (odeviced_power_supply_get_power_status_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_PowerSupply_get_power_status_async (odevicedPowerSupplyBus, odeviced_power_supply_get_power_status_callback, data);
}


void odeviced_power_supply_power_status_handler (DBusGProxy *proxy, const char * status, gpointer user_data)
{
    void (*callback)(int) = NULL;

    callback = user_data;

    if(callback != NULL)
        (*callback)(odeviced_power_supply_get_status_from_dbus(status));
}
