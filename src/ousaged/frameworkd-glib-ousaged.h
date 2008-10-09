/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
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

#ifndef FRAMEWORKD_GLIB_OUSAGED_H
#define FRAMEWORKD_GLIB_OUSAGED_H

GError* ousaged_handle_errors(GError *dbus_error);

void ousaged_list_resources(void (*callback)(GError *, char**, gpointer), gpointer userdata);

void ousaged_get_resource_policy(const char *name, void (*callback)(GError *, char*, gpointer), gpointer userdata);

void ousaged_set_resource_policy(const char *name, const char *policy, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_get_resource_state(const char *name, void (*callback)(GError *, gboolean, gpointer), gpointer userdata);

void ousaged_get_resource_users(const char *name, void (*callback)(GError *, char **, gpointer), gpointer userdata);

void ousaged_request_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_release_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_suspend(void (*callback)(GError *, gpointer), gpointer userdata);

extern DBusGProxy *ousagedBus ;

#endif
