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

#ifndef FRAMEWORKD_GLIB_OGSMD_DBUS_H
#define FRAMEWORKD_GLIB_OGSMD_DBUS_H

#define DEBUG
#define NETWORKD_BUS		"org.freesmartphone.onetworkd"
#define GSMD_BUS		"org.freesmartphone.ogsmd"
#define BUS_PATH		"/org/freesmartphone/GSM/Device"
#define CALL_INTERFACE		"org.freesmartphone.GSM.Call"
#define SIM_INTERFACE		"org.freesmartphone.GSM.SIM"
#define NETWORK_INTERFACE 	"org.freesmartphone.GSM.Network"
#define	DEVICE_INTERFACE	"org.freesmartphone.GSM.Device"
#define	SMS_INTERFACE		"org.freesmartphone.GSM.SMS"

#define DBUS_ERROR g_quark_from_static_string("dbus")
#define IS_DBUS_ERROR(error, code) g_error_matches(error, DBUS_ERROR, code)

typedef enum {
    DBUS_ERROR_SERVICE_NOT_AVAILABLE = -1,
    DBUS_ERROR_NO_REPLY = -2
} DbusErrors;

typedef struct {
    void (*networkStatus)(GHashTable *);
    void (*networkSignalStrength)(const int);
    void (*simAuthStatus)(const int);
    void (*simIncomingMessage)(const int);
    void (*callCallStatus)(const int, const int, GHashTable *);
} FrameworkdHandlers;

void lose (const char *str, ...);
void lose_gerror (const char *prefix, GError *error);
GError* dbus_handle_errors(GError *dbus_error); 
GError* dbus_handle_internal_errors(GError *error);
GError* device_handle_errors(GError *dbus_error);
GError* network_handle_errors(GError *dbus_error);
GError* call_handle_errors(GError *dbus_error);
GError* sim_handle_errors(GError *dbus_error);
void dbus_connect_to_bus(FrameworkdHandlers* fwHandler);
void dbus_connect_to_ogsmd_call();
void dbus_connect_to_ogsmd_network();
void dbus_connect_to_ogsmd_sim();
void dbus_connect_to_ogsmd_device();
void dbus_connect_to_ogsmd_sms();
GType dbus_get_type_g_string_variant_hashtable();
GType dbus_get_type_g_string_int_int_int_array();
GType dbus_get_type_int_g_string_g_string_variant_hashtable_array();
GType dbus_get_type_int_g_string_g_string_g_string_array();
void dbus_free_data(GType type, gpointer data);
#endif
