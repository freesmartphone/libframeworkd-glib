/*
 *  Copyright (C) 2009
 *      Authors (alphabetical) :
 *              mrmoku (Klaus Kurzmann, mok@fluxnetz.de)
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

#include <stdlib.h>
#include <unistd.h>

#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-bindings.h>
#include "frameworkd-glib-opimd-sources.h"
#include "frameworkd-glib-opimd-dbus.h"
#include "dbus/sources.h"



DBusGProxy *opimdSourcesBus = NULL;


/* === PIM.Sources Interface ======================================================= */

/* --- InitAllEntries -------------------------------------------------------------- */

typedef struct
{
	void (*callback)(GError *, gpointer);
	gpointer userdata;
} opimd_sources_init_all_entries_t;


void opimd_sources_init_all_entries_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata)
{
	opimd_sources_init_all_entries_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback(error, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
}




void opimd_sources_init_all_entries(void (*callback)(GError *, gpointer), gpointer userdata)
{
	g_debug("initializing all PIM sources");
	dbus_connect_to_opimd_sources();
	g_debug("connected to sources interface");
	opimd_sources_init_all_entries_t *data = g_malloc (sizeof (opimd_sources_init_all_entries_t));
	data->callback = callback;
	data->userdata = userdata;
	org_freesmartphone_PIM_Sources_init_all_entries_async (opimdSourcesBus, opimd_sources_init_all_entries_callback, data);
	g_debug("started async call to initialize all sources");
}



/* --- GetEntryCount --------------------------------------------------------------- */

typedef struct 
{
	void (*callback)(GError *, int, gpointer);
	gpointer userdata;
} opimd_sources_get_entry_count_t;


void opimd_sources_get_entry_count_callback(DBusGProxy *proxy, int entry_count, GError *dbus_error, gpointer userdata)
{
	opimd_sources_get_entry_count_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback(error, entry_count, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
}


void opimd_sources_get_entry_count(void (*callback)(GError *, int, gpointer), gpointer userdata)
{
	dbus_connect_to_opimd_sources();
	opimd_sources_get_entry_count_t *data = g_malloc (sizeof (opimd_sources_get_entry_count_t));
	data->callback = callback;
	data->userdata = userdata;
	org_freesmartphone_PIM_Sources_get_entry_count_async (opimdSourcesBus, opimd_sources_get_entry_count_callback, data);
}



/* === PIM.Source Interface ======================================================== */



/* --- GetName --------------------------------------------------------------------- */

typedef struct
{
	void (*callback)(GError *, char *, gpointer);
	gpointer userdata;
} opimd_source_get_name_t;


void opimd_source_get_name_callback(DBusGProxy *proxy, char *source_name, GError *dbus_error, gpointer userdata)
{
	opimd_source_get_name_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback(error, source_name, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
}


void opimd_source_get_name(const char *source_path, void (*callback)(GError *, char *, gpointer), gpointer userdata)
{
	DBusGProxy *source = dbus_connect_to_opimd_source (source_path);
	opimd_source_get_name_t *data = g_malloc (sizeof (opimd_source_get_name_t));
	data->callback = callback;
	data->userdata = userdata;
	org_freesmartphone_PIM_Source_get_name_async (source, opimd_source_get_name_callback, data);
}



/* --- GetStatus ------------------------------------------------------------------- */

typedef struct
{
	void (*callback)(GError *, char *, gpointer);
	gpointer userdata;
} opimd_source_get_status_t;

void opimd_source_get_status_callback(DBusGProxy *proxy, char *source_status, GError *dbus_error, gpointer userdata)
{
	opimd_source_get_status_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback(error, source_status, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
}


void opimd_source_get_status(const char *source_path, void (*callback)(GError *, char *, gpointer), gpointer userdata)
{
	DBusGProxy *source =  dbus_connect_to_opimd_source (source_path);
	opimd_source_get_status_t *data = g_malloc (sizeof (opimd_source_get_status_t));
	data->callback = callback;
	data->userdata = userdata;
	org_freesmartphone_PIM_Source_get_status_async (source, opimd_source_get_status_callback, data);
}


/* --- GetSupportedPIMDomains ------------------------------------------------------ */

typedef struct
{
	void (*callback)(GError *, GHashTable *, gpointer);
	gpointer userdata;
} opimd_source_get_supported_pim_domains_t;


void opimd_source_get_supported_pim_domains_callback(DBusGProxy *proxy, GHashTable *source_domains, GError *dbus_error, gpointer userdata)
{
	opimd_source_get_supported_pim_domains_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback(error, source_domains, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
}


void opimd_source_get_supported_pim_domains(const char *source_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata)
{
	DBusGProxy *source = dbus_connect_to_opimd_source (source_path);
	opimd_source_get_supported_pim_domains_t *data = g_malloc (sizeof (opimd_source_get_supported_pim_domains_t));
	data->callback = callback;
	data->userdata = userdata;
	org_freesmartphone_PIM_Source_get_supported_pi_mdomains_async (source, opimd_source_get_supported_pim_domains_callback, data);
}




