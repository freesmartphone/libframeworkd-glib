/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
 *              Klaus 'mrmoku' Kurzmann <mok@fluxnetz.de>
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

#ifndef FRAMEWORKD_GLIB_OGSMD_SIM_H
#define FRAMEWORKD_GLIB_OGSMD_SIM_H

#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#define DBUS_SIM_AUTH_STATUS_READY "READY"
#define DBUS_SIM_AUTH_STATUS_PIN_REQUIRED "SIM PIN"
#define DBUS_SIM_AUTH_STATUS_PUK_REQUIRED "SIM PUK"
#define DBUS_SIM_AUTH_STATUS_PIN2_REQUIRED "SIM PIN2"
#define DBUS_SIM_AUTH_STATUS_PUK2_REQUIRED "SIM PUK2"

#define DBUS_SIM_ERROR_NOT_PRESENT "org.freesmartphone.GSM.SIM.NotPresent"
#define DBUS_SIM_ERROR_AUTH_FAILED "org.freesmartphone.GSM.SIM.AuthFailed"
#define DBUS_SIM_ERROR_BLOCKED "org.freesmartphone.GSM.SIM.Blocked"
#define DBUS_SIM_ERROR_NOT_FOUND "org.freesmartphone.GSM.SIM.NotFound"
#define DBUS_SIM_ERROR_MEMORY_FULL "org.freesmartphone.GSM.SIM.MemoryFull"
#define DBUS_SIM_ERROR_INVALID_INDEX "org.freesmartphone.GSM.SIM.InvalidIndex"

#define SIM_ERROR g_quark_from_static_string(SIM_INTERFACE)
#define IS_SIM_ERROR(error, code) g_error_matches(error, SIM_ERROR, code)
typedef enum {
    SIM_READY,
    SIM_PIN_REQUIRED,
    SIM_PUK_REQUIRED,
    SIM_PIN2_REQUIRED,
    SIM_PUK2_REQUIRED
} SimStatus;

typedef enum {
    SIM_ERROR_NOT_PRESENT = -1,
    SIM_ERROR_AUTH_FAILED = -2,
    SIM_ERROR_BLOCKED = -3,
    SIM_ERROR_NOT_FOUND = -4,
    SIM_ERROR_MEMORY_FULL = -5,
    SIM_ERROR_INVALID_INDEX = -6
} SimErrors;

void ogsmd_sim_incoming_stored_message_handler (DBusGProxy *proxy, const int id, gpointer userdata);

void ogsmd_sim_auth_status_handler (DBusGProxy *proxy, char *status, gpointer user_data);

int ogsmd_sim_handle_authentication_state(char *status);

void ogsmd_sim_ready_status_handler (DBusGProxy *proxy, gboolean status, gpointer user_data);

void ogsmd_sim_get_auth_status(void (*callback)(GError*, int status, gpointer), gpointer userdata);

void ogsmd_sim_send_auth_code(const char* pin, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_get_ready_status(void (*callback)(GError *, gboolean status, gpointer), gpointer userdata);

void ogsmd_sim_unlock(const char* puk, const char* pin, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_change_auth_code(const char* old_code, const char* new_code, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_retrieve_message(const int index, void (*callback)(GError*, char* status, char* number, char* content, GHashTable*properties, gpointer), gpointer userdata);

void ogsmd_sim_retrieve_entry(const char* category, const int index, void (*callback)(GError*, char* name, char* number, gpointer), gpointer userdata);

void ogsmd_sim_set_auth_code_required(const gboolean check, const char* pin, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_get_auth_code_required(void (*callback)(GError*, gboolean check, gpointer), gpointer userdata);

void ogsmd_sim_get_sim_info(void (*callback)(GError *,GHashTable* ogsmd_sim_info, gpointer), gpointer userdata);

void ogsmd_sim_send_generic_sim_command(char *command, void (*callback)(GError*, char* result, gpointer), gpointer userdata);

void ogsmd_sim_send_restricted_sim_command(const int command, const int fileid, const int p1, const int p2, const int p3, char *data, void (*callback)(GError*, char* result, gpointer), gpointer userdata);

void ogsmd_sim_get_home_zones(void (*callback)(GError*, GPtrArray*home_zones, gpointer), gpointer userdata);

void ogsmd_sim_get_phonebook_info(const char *category, void (*callback)(GError*, GHashTable*phonebook_info, gpointer), gpointer userdata);

void ogsmd_sim_delete_entry(const char *category, const int index, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_store_entry(const char *category, const int index, char *name, char*number, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_get_messagebook_info( void (*callback)(GError*, GHashTable*messagebook_info, gpointer), gpointer userdata);

void ogsmd_sim_retrieve_messagebook( const char* category, void (*callback)(GError*, GPtrArray*messages, gpointer), gpointer userdata);

void ogsmd_sim_get_service_center_number(void (*callback)(GError*, char*number, gpointer), gpointer userdata);

void ogsmd_sim_set_service_center_number(char *number,  void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_delete_message(const int index, void (*callback)(GError*, gpointer), gpointer userdata);

void ogsmd_sim_store_message(char *number, char* content, GHashTable* properties, void (*callback)(GError*, int index, gpointer), gpointer userdata);

void ogsmd_sim_send_stored_message(const int index, void (*callback)(GError*, int transaction_index, gpointer), gpointer userdata);

GError* ogsmd_sim_handle_errors(GError *dbus_error);

extern DBusGProxy *simBus;

G_END_DECLS

#endif
