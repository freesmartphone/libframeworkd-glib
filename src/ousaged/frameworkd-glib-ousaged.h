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

G_BEGIN_DECLS

#define USAGE_ERROR g_quark_from_static_string(USAGE_INTERFACE)
#define DBUS_USAGE_ERROR_POLICY_UNKNOWN "org.freesmartphone.Usage.PolicyUnknown"
#define DBUS_USAGE_ERROR_POLICY_DISABLED "org.freesmartphone.Usage.PolicyDisabled"
#define DBUS_USAGE_ERROR_RESOURCE_UNKNOWN "org.freesmartphone.Usage.ResourceUnknown"
#define DBUS_USAGE_ERROR_RESOURCE_EXISTS "org.freesmartphone.Usage.ResourceExists"
#define DBUS_USAGE_ERROR_RESOURCE_IN_USE "org.freesmartphone.Usage.ResourceInUse"
#define DBUS_USAGE_ERROR_USER_EXISTS "org.freesmartphone.Usage.UserExists"
#define DBUS_USAGE_ERROR_USER_UNKNOWN "org.freesmartphone.Usage.UserUnknown"


typedef enum {
    USAGE_ERROR_POLICY_UNKNOWN = -1,
    USAGE_ERROR_POLICY_DISABLED = -2,
    USAGE_ERROR_RESOURCE_UNKNOWN = -3,
    USAGE_ERROR_RESOURCE_EXISTS = -4,
    USAGE_ERROR_RESOURCE_IN_USE = -5,
    USAGE_ERROR_USER_EXISTS = -6,
    USAGE_ERROR_USER_UNKNOWN = -7
} UsageErrors;

typedef enum {
	OUSAGED_RESOURCE_UNKNOWN = 0,
	OUSAGED_RESOURCE_GSM = 1,
	OUSAGED_RESOURCE_GPS = 2,
	OUSAGED_RESOURCE_WIFI = 3,
	OUSAGED_RESOURCE_BLUETOOTH = 4,
	OUSAGED_RESOURCE_DISPLAY = 5,
	OUSAGED_RESOURCE_CPU = 6
} OUsagedResources;

#define OUSAGED_RESOURCE_COUNT 7

GError* ousaged_handle_errors(GError *dbus_error);
int ousaged_resource_name_to_int(const char *resource);

void ousaged_list_resources(void (*callback)(GError *, char**, gpointer), gpointer userdata);

void ousaged_get_resource_policy(const char *name, void (*callback)(GError *, char*, gpointer), gpointer userdata);

void ousaged_set_resource_policy(const char *name, const char *policy, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_get_resource_state(const char *name, void (*callback)(GError *, gboolean, gpointer), gpointer userdata);

void ousaged_get_resource_users(const char *name, void (*callback)(GError *, char **, gpointer), gpointer userdata);

void ousaged_request_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_release_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_suspend(void (*callback)(GError *, gpointer), gpointer userdata);

extern DBusGProxy *ousagedBus ;

G_END_DECLS

#endif
