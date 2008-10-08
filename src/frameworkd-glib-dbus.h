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

#ifndef FRAMEWORKD_GLIB_DBUS_H
#define FRAMEWORKD_GLIB_DBUS_H

#include <dbus/dbus-glib.h>

#define DEBUG

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
    void (*simIncomingStoredMessage)(const int);
    void (*callCallStatus)(const int, const int, GHashTable *);
} FrameworkdHandlers;

void lose (const char *str, ...);
void lose_gerror (const char *prefix, GError *error);
void dbus_connect_to_bus(FrameworkdHandlers* fwHandler);
DBusGProxy *dbus_connect_to_interface(char *bus_name, char *path, char *interface, char *interface_name);
GType dbus_get_type_g_string_variant_hashtable();
GType dbus_get_type_g_string_int_int_int_array();
GType dbus_get_type_int_g_string_g_string_variant_hashtable_array();
GType dbus_get_type_int_g_string_g_string_g_string_array();
void dbus_free_data(GType type, gpointer data);
GError* dbus_handle_errors(GError *dbus_error);
GError* dbus_handle_internal_errors(GError *error);

#endif