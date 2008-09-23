/*
 *  Copyright (C) 2008 
 *	Authors (alphabetical) : 
 *		Marc-Olivier Barre <marco@marcochapeau.org>
 *		Julien Cassignol <ainulindale@gmail.com>
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

#include "frameworkd-glib-ogsmd-dbus.h"
#include "dbus/sim.h"
#include "frameworkd-glib-ogsmd-sim.h"

DBusGProxy *simBus = NULL;

void ogsmd_sim_auth_status_handler (DBusGProxy *proxy, const char *status, gpointer user_data)
{ 
    int st;
    void (*callback)(const int) = NULL;

    st = ogsmd_sim_handle_authentication_state(status);
    callback = user_data;

    if(callback != NULL)
        (*callback)(st);

}


int ogsmd_sim_handle_authentication_state(const char*status) {
    if(!strcmp(status,DBUS_SIM_READY)) {
        return SIM_READY;
    }
    else if(!strcmp(status,DBUS_SIM_PIN_REQUIRED)) {
        return SIM_PIN_REQUIRED;
    }
    else if(!strcmp(status,DBUS_SIM_PUK_REQUIRED)) {
        return SIM_PUK_REQUIRED;
    }
    else if(!strcmp(status,DBUS_SIM_PIN2_REQUIRED)) {
        return SIM_PIN2_REQUIRED;
    }
    else {
        return SIM_PUK2_REQUIRED;
    }

}

typedef struct
{
    void (*callback)(GError *, int status, gpointer);
    gpointer userdata;
} ogsmd_sim_get_auth_status_data_t;

void ogsmd_sim_get_auth_status_callback(DBusGProxy *bus, char* status, GError* dbus_error, gpointer userdata) {
    ogsmd_sim_get_auth_status_data_t *data = userdata;
    GError *error = NULL;
    int st = 0;


    if(data->callback != NULL) {
        if(dbus_error == NULL) {
            st = ogsmd_sim_handle_authentication_state(status);
            free(status);
        } else {
            error = dbus_handle_errors(dbus_error);
        }

        data->callback (error, st, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    g_free(data);
    if(dbus_error != NULL) g_error_free(dbus_error);
}

void ogsmd_sim_get_auth_status(void (*callback)(GError*, int status, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_auth_status_data_t *data = g_malloc (sizeof (ogsmd_sim_get_auth_status_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_auth_status_async(simBus, ogsmd_sim_get_auth_status_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_send_auth_code_data_t;

void ogsmd_sim_send_auth_code_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_send_auth_code_data_t *data = userdata;
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

void ogsmd_sim_send_auth_code(const char* pin, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_send_auth_code_data_t *data = g_malloc (sizeof (ogsmd_sim_send_auth_code_data_t));
    data->callback = callback;
    data->userdata = userdata;

    if(pin != NULL)
        org_freesmartphone_GSM_SIM_send_auth_code_async(simBus, pin, ogsmd_sim_send_auth_code_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_unlock_data_t;

void ogsmd_sim_unlock_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_unlock_data_t *data = userdata;
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

void ogsmd_sim_unlock(const char* puk, const char* pin, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_unlock_data_t *data = g_malloc (sizeof (ogsmd_sim_unlock_data_t));
    data->callback = callback;
    data->userdata = userdata;


    if(puk != NULL && pin != NULL)
        org_freesmartphone_GSM_SIM_unlock_async(simBus, puk, pin, ogsmd_sim_unlock_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_change_auth_code_data_t;

void ogsmd_sim_change_auth_code_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_change_auth_code_data_t *data = userdata;
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

void ogsmd_sim_change_auth_code(const char* old, const char* new, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_change_auth_code_data_t *data = g_malloc (sizeof (ogsmd_sim_change_auth_code_data_t));
    data->callback = callback;
    data->userdata = userdata;

    if(old != NULL && new != NULL)
        org_freesmartphone_GSM_SIM_change_auth_code_async(simBus, old, new, ogsmd_sim_change_auth_code_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char* name, char* number, gpointer);
    gpointer userdata;
} ogsmd_sim_retrieve_entry_data_t;

void ogsmd_sim_retrieve_entry_callback(DBusGProxy* bus, char*name, char* number, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_retrieve_entry_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, name, number, data->userdata);
        if(error != NULL) g_error_free(error);
    }

    if(dbus_error != NULL) {
        g_error_free(dbus_error);
    } else {
        free(name);
        free(number);
    }
    
    g_free(data);
}

void ogsmd_sim_retrieve_entry(const int index, void (*callback)(GError*, char* name, char*number, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_retrieve_entry_data_t *data = g_malloc (sizeof (ogsmd_sim_retrieve_entry_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_retrieve_entry_async(simBus, index, ogsmd_sim_retrieve_entry_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char*number, char*content, gpointer);
    gpointer userdata;
} ogsmd_sim_retrieve_message_data_t;

void ogsmd_sim_retrieve_message_callback(DBusGProxy* bus, char*number, char* content, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_retrieve_message_data_t *data = userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, number, content, data->userdata);
        if(error != NULL) g_error_free(error);
    }

    if(dbus_error != NULL) {
        g_error_free(dbus_error);
    } else {
        free(number);
        free(content);
    }
    
    g_free(data);
}

void ogsmd_sim_retrieve_message(const int index, void (*callback)(GError*, char*number, char*content, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_retrieve_message_data_t *data = g_malloc (sizeof (ogsmd_sim_retrieve_message_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_retrieve_message_async(simBus, index, ogsmd_sim_retrieve_message_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_set_auth_code_required_data_t;

void ogsmd_sim_set_auth_code_required_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_set_auth_code_required_data_t *data = userdata;
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

void ogsmd_sim_set_auth_code_required(gboolean check, const char* pin, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_set_auth_code_required_data_t *data = g_malloc (sizeof (ogsmd_sim_set_auth_code_required_data_t));
    data->callback = callback;
    data->userdata = userdata;

    if(pin != NULL)
        org_freesmartphone_GSM_SIM_set_auth_code_required_async(simBus, check, pin, ogsmd_sim_set_auth_code_required_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gboolean check, gpointer);
    gpointer userdata;
} ogsmd_sim_get_auth_code_required_data_t;

void ogsmd_sim_get_auth_code_required_callback(DBusGProxy* bus, gboolean check, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_auth_code_required_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, check, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
}

void ogsmd_sim_get_auth_code_required(void (*callback)(GError*, gboolean check, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_auth_code_required_data_t *data = g_malloc (sizeof (ogsmd_sim_get_auth_code_required_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_auth_code_required_async(simBus, ogsmd_sim_get_auth_code_required_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GHashTable*sim_info, gpointer);
    gpointer userdata;
} ogsmd_sim_get_sim_info_data_t;

void ogsmd_sim_get_sim_info_callback(DBusGProxy* bus, GHashTable* ogsmd_sim_info, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_sim_info_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, ogsmd_sim_info, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    g_hash_table_destroy(ogsmd_sim_info);
}

void ogsmd_sim_get_sim_info(void (*callback)(GError*, GHashTable*sim_info, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_sim_info_data_t *data = g_malloc (sizeof (ogsmd_sim_get_sim_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_sim_info_async(simBus, ogsmd_sim_get_sim_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char* result, gpointer);
    gpointer userdata;
} ogsmd_sim_send_generic_sim_command_data_t;

void ogsmd_sim_send_generic_sim_command_callback(DBusGProxy* bus, char* result, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_send_generic_sim_command_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, result, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    free(result);
}

void ogsmd_sim_send_generic_sim_command(char * command, void (*callback)(GError*, char*result, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_send_generic_sim_command_data_t *data = g_malloc (sizeof (ogsmd_sim_send_generic_sim_command_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_send_generic_sim_command_async(simBus, command, ogsmd_sim_send_generic_sim_command_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char* result, gpointer);
    gpointer userdata;
} ogsmd_sim_send_restricted_sim_command_data_t;

void ogsmd_sim_send_restricted_sim_command_callback(DBusGProxy* bus, char* result, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_send_restricted_sim_command_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, result, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    free(result);
}

void ogsmd_sim_send_restricted_sim_command(const int command, const int fileid, const int p1, const int p2, const int p3, char * ogsmd_sim_data, void (*callback)(GError*, char* result, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_send_restricted_sim_command_data_t *data = g_malloc (sizeof (ogsmd_sim_send_restricted_sim_command_data_t));
    data->callback = callback;
    data->userdata = userdata;

    // TODO sim command enum
    org_freesmartphone_GSM_SIM_send_restricted_sim_command_async(simBus, command, fileid, p1, p2, p3, ogsmd_sim_data, ogsmd_sim_send_restricted_sim_command_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GPtrArray*home_zones, gpointer);
    gpointer userdata;
} ogsmd_sim_get_home_zones_data_t;

void ogsmd_sim_get_home_zones_callback(DBusGProxy* bus, GPtrArray* home_zones, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_home_zones_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, home_zones, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    dbus_free_data(dbus_get_type_g_string_int_int_int_array(), home_zones);
}

void ogsmd_sim_get_home_zones(void (*callback)(GError*, GPtrArray*home_zones, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_home_zones_data_t *data = g_malloc (sizeof (ogsmd_sim_get_home_zones_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_home_zones_async(simBus, ogsmd_sim_get_home_zones_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GHashTable*phonebook_info, gpointer);
    gpointer userdata;
} ogsmd_sim_get_phonebook_info_data_t;

void ogsmd_sim_get_phonebook_info_callback(DBusGProxy* bus, GHashTable* phonebook_info, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_phonebook_info_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, phonebook_info, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    g_hash_table_destroy(phonebook_info);
}

void ogsmd_sim_get_phonebook_info(void (*callback)(GError*, GHashTable*phonebook_info, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_phonebook_info_data_t *data = g_malloc (sizeof (ogsmd_sim_get_phonebook_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_phonebook_info_async(simBus, ogsmd_sim_get_phonebook_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_delete_entry_data_t;

void ogsmd_sim_delete_entry_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_delete_entry_data_t *data = userdata;
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

void ogsmd_sim_delete_entry(const int index, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_delete_entry_data_t *data = g_malloc (sizeof (ogsmd_sim_delete_entry_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_delete_entry_async(simBus, index, ogsmd_sim_delete_entry_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_store_entry_data_t;

void ogsmd_sim_store_entry_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_store_entry_data_t *data = userdata;
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

void ogsmd_sim_store_entry(const int index, char *name, char * number, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_store_entry_data_t *data = g_malloc (sizeof (ogsmd_sim_store_entry_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_store_entry_async(simBus, index, name, number, ogsmd_sim_store_entry_callback, data);
}

typedef struct
{
    void (*callback)(GError *, GHashTable*messagebook_info, gpointer);
    gpointer userdata;
} ogsmd_sim_get_messagebook_info_data_t;

void ogsmd_sim_get_messagebook_info_callback(DBusGProxy* bus, GHashTable* messagebook_info, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_messagebook_info_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, messagebook_info, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    g_hash_table_destroy(messagebook_info);
}

void ogsmd_sim_get_messagebook_info(void (*callback)(GError*, GHashTable*messagebook_info, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_messagebook_info_data_t *data = g_malloc (sizeof (ogsmd_sim_get_messagebook_info_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_messagebook_info_async(simBus, ogsmd_sim_get_messagebook_info_callback, data);
}

typedef struct
{
    void (*callback)(GError *, char*number, gpointer);
    gpointer userdata;
} ogsmd_sim_get_service_center_number_data_t;

void ogsmd_sim_get_service_center_number_callback(DBusGProxy* bus, char* number, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_get_service_center_number_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, number, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
    free(number);
}

void ogsmd_sim_get_service_center_number(void (*callback)(GError*, char*number, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_get_service_center_number_data_t *data = g_malloc (sizeof (ogsmd_sim_get_service_center_number_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_get_service_center_number_async(simBus, ogsmd_sim_get_service_center_number_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_set_service_center_number_data_t;

void ogsmd_sim_set_service_center_number_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_set_service_center_number_data_t *data = userdata;
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

void ogsmd_sim_set_service_center_number(char * number, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_set_service_center_number_data_t *data = g_malloc (sizeof (ogsmd_sim_set_service_center_number_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_set_service_center_number_async(simBus, number, ogsmd_sim_set_service_center_number_callback, data);
}

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} ogsmd_sim_delete_message_data_t;

void ogsmd_sim_delete_message_callback(DBusGProxy* bus, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_delete_message_data_t *data = userdata;
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

void ogsmd_sim_delete_message(int index, void (*callback)(GError*, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_delete_message_data_t *data = g_malloc (sizeof (ogsmd_sim_delete_message_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_delete_message_async(simBus, index, ogsmd_sim_delete_message_callback, data);
}

typedef struct
{
    void (*callback)(GError *, int index, gpointer);
    gpointer userdata;
} ogsmd_sim_store_message_data_t;

void ogsmd_sim_store_message_callback(DBusGProxy* bus, int index, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_store_message_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, index, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
}

void ogsmd_sim_store_message(char * number, char* content, void (*callback)(GError*, int index, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_store_message_data_t *data = g_malloc (sizeof (ogsmd_sim_store_message_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_store_message_async(simBus, number, content, ogsmd_sim_store_message_callback, data);
}

typedef struct
{
    void (*callback)(GError *, int transaction_index, gpointer);
    gpointer userdata;
} ogsmd_sim_send_stored_message_data_t;

void ogsmd_sim_send_stored_message_callback(DBusGProxy* bus, int transaction_index, GError *dbus_error, gpointer userdata) {
    ogsmd_sim_send_stored_message_data_t *data = userdata;
    GError *error = NULL;


    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors(dbus_error);

        data->callback (error, transaction_index, data->userdata);
        if(error != NULL) g_error_free(error);
    } 

    if(dbus_error != NULL) g_error_free(dbus_error);        
    g_free(data);
}

void ogsmd_sim_send_stored_message(const int index, void (*callback)(GError*, int transaction_index, gpointer), gpointer userdata) {
    dbus_connect_to_gsm_sim();

    ogsmd_sim_send_stored_message_data_t *data = g_malloc (sizeof (ogsmd_sim_send_stored_message_data_t));
    data->callback = callback;
    data->userdata = userdata;

    org_freesmartphone_GSM_SIM_send_stored_message_async(simBus, index, ogsmd_sim_send_stored_message_callback, data);
}

GError* ogsmd_sim_handle_errors(GError *error) {
    const char *error_name = dbus_g_error_get_name(error);
    int simError = 0;

    if(!strcmp(error_name, DBUS_SIM_ERROR_NOT_PRESENT)) {
        simError = SIM_ERROR_NOT_PRESENT;
    } else if(!strcmp(error_name, DBUS_SIM_ERROR_AUTH_FAILED)) {
        simError = SIM_ERROR_AUTH_FAILED;
    } else if(!strcmp(error_name, DBUS_SIM_ERROR_BLOCKED)) {
        simError = SIM_ERROR_BLOCKED;
    } else if(!strcmp(error_name, DBUS_SIM_ERROR_NOT_FOUND)) {
        simError = SIM_ERROR_NOT_FOUND;
    } else if(!strcmp(error_name, DBUS_SIM_ERROR_MEMORY_FULL)) {
        simError = SIM_ERROR_MEMORY_FULL;
    } else if(!strcmp(error_name, DBUS_SIM_ERROR_INVALID_INDEX)) {
        simError = SIM_ERROR_INVALID_INDEX;
    } else {
        lose_gerror ("Unknown SIM error", error);
    }
    return g_error_new (SIM_ERROR, simError, "TODO");
}
