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
#include "frameworkd-glib-odeviced-audio.h"
#include "frameworkd-glib-odeviced-dbus.h"
#include "dbus/audio.h"

DBusGProxy *odevicedAudioBus = NULL;

GError* odeviced_audio_handle_errors(GError *dbus_error) {
    // TODO: Add error handling when frameword code is ready
    lose_gerror ("Unknown odeviced error", dbus_error);
    // Fix warning
    return NULL;
}

typedef struct
{
    void (*callback)(GError *, GHashTable*, gpointer);
    gpointer userdata;
} odeviced_audio_get_info_data_t;


void odeviced_audio_get_info_callback(DBusGProxy* bus, GHashTable* info, GError *dbus_error, gpointer userdata) {
    odeviced_audio_get_info_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, info, data->userdata);
        if(error != NULL) {
            g_error_free(error);
        } else {
            g_free(info);
        }
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_audio_get_info(void (*callback)(GError *, GHashTable*, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_audio();

    odeviced_audio_get_info_data_t *data = g_malloc (sizeof (odeviced_audio_get_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_Audio_get_info_async (odevicedAudioBus, odeviced_audio_get_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} odeviced_audio_push_scenario_data_t;


void odeviced_audio_push_scenario_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    odeviced_audio_push_scenario_data_t *data = userdata;
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

void odeviced_audio_push_scenario(char* scenario, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_audio();

    odeviced_audio_push_scenario_data_t *data = g_malloc (sizeof (odeviced_audio_push_scenario_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_Audio_push_scenario_async (odevicedAudioBus, scenario, odeviced_audio_push_scenario_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char *, gpointer);
    gpointer userdata;
} odeviced_audio_pull_scenario_data_t;


void odeviced_audio_pull_scenario_callback(DBusGProxy* bus, char* scenario, GError *dbus_error, gpointer userdata) {
    odeviced_audio_pull_scenario_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, scenario, data->userdata);
        if(error != NULL) g_error_free(error);
        else free(scenario);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);
    g_free(data);
}

void odeviced_audio_pull_scenario(void (*callback)(GError *, char* , gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_audio();

    odeviced_audio_pull_scenario_data_t *data = g_malloc (sizeof (odeviced_audio_pull_scenario_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_Audio_pull_scenario_async (odevicedAudioBus, odeviced_audio_pull_scenario_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} odeviced_audio_set_scenario_data_t;


void odeviced_audio_set_scenario_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    odeviced_audio_set_scenario_data_t *data = userdata;
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

void odeviced_audio_set_scenario(char* scenario, void (*callback)(GError *, gpointer), gpointer userdata) {
    dbus_connect_to_odeviced_audio();

    odeviced_audio_set_scenario_data_t *data = g_malloc (sizeof (odeviced_audio_set_scenario_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_Device_Audio_set_scenario_async (odevicedAudioBus, scenario, odeviced_audio_set_scenario_callback, data);
}

void odeviced_audio_sound_status_handler (DBusGProxy *proxy, const char *id, const  char* status, GHashTable* properties, gpointer user_data)
{
    void (*callback)(char *, char*, GHashTable*) = NULL;

    callback = user_data;

    if(callback != NULL)
        (*callback)(id, status, properties);
}
