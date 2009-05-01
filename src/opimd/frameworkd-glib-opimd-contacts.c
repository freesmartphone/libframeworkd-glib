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
#include "frameworkd-glib-opimd-contacts.h"
#include "frameworkd-glib-opimd-dbus.h"
#include "dbus/contacts.h"



DBusGProxy *opimdContactsBus = NULL;


/* === PIM.Contacts Interface ====================================================== */

/* --- Add ------------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_contacts_add_data_t;

void opimd_contacts_add_callback(DBusGProxy *proxy, char *contact_path, GError *dbus_error, gpointer userdata) {
	 opimd_contacts_add_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, contact_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contacts_add(const GHashTable *contact_data, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_contacts();
	 opimd_contacts_add_data_t *data = g_malloc (sizeof (opimd_contacts_add_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Contacts_add_async (opimdContactsBus, contact_data, opimd_contacts_add_callback, data);
}


/* --- GetSingleContactSingleField ------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_contacts_get_single_contact_single_field_data_t;

void opimd_contacts_get_single_contact_single_field_callback(DBusGProxy *proxy, char *value, GError *dbus_error, gpointer userdata) {
	 opimd_contacts_get_single_contact_single_field_data_t *data = (opimd_contacts_get_single_contact_single_field_data_t *)userdata;
	 GError *error = NULL;

	 g_debug("launched async query for a single contact (callback) ...");
	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, value, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contacts_get_single_contact_single_field(const GHashTable *query, const char *field, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_contacts();
	 opimd_contacts_get_single_contact_single_field_data_t *data = g_malloc (sizeof (opimd_contacts_get_single_contact_single_field_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Contacts_get_single_contact_single_field_async (opimdContactsBus, query, field, opimd_contacts_get_single_contact_single_field_callback, data);
}


/* --- Query ----------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_contacts_query_data_t;

void opimd_contacts_query_callback(DBusGProxy *proxy, char *query_path, GError *dbus_error, gpointer userdata) {
	 opimd_contacts_query_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);

		  data->callback (error, query_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contacts_query(const GHashTable *query, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_contacts();
	 opimd_contacts_query_data_t *data = g_malloc (sizeof (opimd_contacts_query_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Contacts_query_async (opimdContactsBus, query, opimd_contacts_query_callback, data);
}


/* === PIM.Contact Interface ======================================================= */

/* --- GetContent ------------------------------------------------------------------ */

typedef struct
{
	 void (*callback)(GError *, GHashTable *, gpointer);
	 gpointer userdata;
} opimd_contact_get_content_data_t;

void opimd_contact_get_content_callback(DBusGProxy *proxy, GHashTable *contact_data, GError *dbus_error, gpointer userdata) {
	 opimd_contact_get_content_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, contact_data, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);
	 g_free (data);
}

void opimd_contact_get_content(const char *contact_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata) {
	 DBusGProxy *contact = dbus_connect_to_opimd_contact (contact_path);
	 opimd_contact_get_content_data_t *data = g_malloc (sizeof (opimd_contact_get_content_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Contact_get_content_async (contact, opimd_contact_get_content_callback, data);
}


/* --- GetMultipleFields ----------------------------------------------------------- */

typedef struct
{
	void (*callback)(GError *, GHashTable *, gpointer);
	gpointer userdata;
} opimd_contact_get_multiple_fields_data_t;

void opimd_contact_get_multiple_fields_callback(DBusGProxy *proxy, GHashTable *field_data, GError *dbus_error, gpointer userdata) {
	opimd_contact_get_multiple_fields_data_t *data = userdata;
	GError *error = NULL;

	if(data->callback != NULL) {
		if(dbus_error != NULL)
			error = dbus_handle_errors (dbus_error);
		data->callback (error, field_data, data->userdata);
		if(error != NULL) g_error_free (error);
	}
	if(dbus_error != NULL) g_error_free (dbus_error);

	g_free (data);
	g_free (proxy);
}

void opimd_contact_get_multiple_fields(const char *contact_path, const char *field_list, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata) {
    DBusGProxy *proxy = dbus_connect_to_opimd_contact (contact_path);
    opimd_contact_get_multiple_fields_data_t *data = g_malloc (sizeof (opimd_contact_get_multiple_fields_data_t));
    data->callback = callback;
    data->userdata = userdata;
    org_freesmartphone_PIM_Contact_get_multiple_fields_async (proxy, field_list, opimd_contact_get_multiple_fields_callback, data);
}


/* --- Delete ---------------------------------------------------------------------- */

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} opimd_contact_delete_data_t;

void opimd_contact_delete_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
    opimd_contact_delete_data_t *data = (opimd_contact_delete_data_t *)userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors (dbus_error);
        data->callback (error, data->userdata);
        if(error != NULL) g_error_free (error);
    }
    if(dbus_error != NULL) g_error_free (dbus_error);
    g_free (data);
    g_free (proxy);
}

void opimd_contact_delete(const char *contact_path, void (*callback)(GError *, gpointer), gpointer userdata){
    DBusGProxy *proxy = dbus_connect_to_opimd_contact (contact_path);
    opimd_contact_delete_data_t *data = g_malloc (sizeof (opimd_contact_delete_data_t));
    data->callback = callback;
    data->userdata = userdata;
    org_freesmartphone_PIM_Contact_delete_async (proxy, opimd_contact_delete_callback, data);
}


/* --- Update ---------------------------------------------------------------------- */

typedef struct
{
    void (*callback)(GError *, gpointer);
    gpointer userdata;
} opimd_contact_update_data_t;

void opimd_contact_update_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
    opimd_contact_update_data_t *data = (opimd_contact_update_data_t *)userdata;
    GError *error = NULL;

    if(data->callback != NULL) {
        if(dbus_error != NULL)
            error = dbus_handle_errors (dbus_error);
        data->callback (error, data->userdata);
        if(error != NULL) g_error_free (error);
    }
    if(dbus_error != NULL) g_error_free (dbus_error);
    g_free (data);
    g_free (proxy);
}

void opimd_contact_update(const char *contact_path, GHashTable *contact_data, void (*callback)(GError *, gpointer), gpointer userdata) {
    DBusGProxy *proxy = dbus_connect_to_opimd_contact (contact_path);
    opimd_contact_update_data_t *data = g_malloc (sizeof (opimd_contact_update_data_t));
    data->callback = callback;
    data->userdata = userdata;
    org_freesmartphone_PIM_Contact_update_async (proxy, contact_data, opimd_contact_update_callback, data);
}
	

/* === PIM.ContactQuery Interface ================================================== */

/* --- GetResultCount -------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, int, gpointer);
	 gpointer userdata;
} opimd_contact_query_get_result_count_data_t;

void opimd_contact_query_get_result_count_callback(DBusGProxy *proxy, int count, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_get_result_count_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);

		  data->callback (error, count, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_get_result_count(DBusGProxy *query, void (*callback)(GError *, int count, gpointer), gpointer userdata) {
	 opimd_contact_query_get_result_count_data_t *data = g_malloc (sizeof (opimd_contact_query_get_result_count_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_get_result_count_async (query, opimd_contact_query_get_result_count_callback, data);
}


/* --- Rewind ---------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_contact_query_rewind_data_t;

void opimd_contact_query_rewind_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_rewind_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_rewind(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_contact_query_rewind_data_t *data = g_malloc (sizeof (opimd_contact_query_rewind_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_rewind_async (query, opimd_contact_query_rewind_callback, data);
}


/* --- Skip ------------------------------------------------------------------------ */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_contact_query_skip_data_t;

void opimd_contact_query_skip_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_skip_data_t *data = userdata;
	 GError *error = NULL;

	 if (data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_skip(DBusGProxy *query, const gint count, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_contact_query_skip_data_t *data = g_malloc (sizeof (opimd_contact_query_skip_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_skip_async (query, count, opimd_contact_query_skip_callback, data);
}


/* --- GetContactPath -------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_contact_query_get_contact_path_data_t;

void opimd_contact_query_get_contact_path_callback(DBusGProxy *proxy, char *contact_path, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_get_contact_path_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, contact_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_get_contact_path(DBusGProxy *query, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 opimd_contact_query_get_contact_path_data_t *data = g_malloc (sizeof (opimd_contact_query_get_contact_path_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_get_contact_path_async (query, opimd_contact_query_get_contact_path_callback, data);
}


/* --- GetResult ------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, GHashTable *, gpointer);
	 gpointer userdata;
} opimd_contact_query_get_result_data_t;

void opimd_contact_query_get_result_callback (DBusGProxy *proxy, GHashTable *result, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_get_result_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, result, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_get_result(DBusGProxy *query, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata) {
	 opimd_contact_query_get_result_data_t *data = g_malloc (sizeof (opimd_contact_query_get_result_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_get_result_async (query, opimd_contact_query_get_result_callback, data);
}


/* --- GetMultipleResults ---------------------------------------------------------- */

typedef struct {
	void (*callback)(GError *, GPtrArray *, gpointer);
	gpointer userdata;
} opimd_contact_query_get_multiple_results_t;


void opimd_contact_query_get_multiple_results_callback(DBusGProxy *proxy, GPtrArray *resultset, GError *dbus_error, gpointer userdata)
{
	 opimd_contact_query_get_multiple_results_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, resultset, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_contact_query_get_multiple_results(DBusGProxy *query, int count, void (*callback)(GError *, GPtrArray *, gpointer), gpointer userdata) {
	 opimd_contact_query_get_multiple_results_t *data = g_malloc (sizeof (opimd_contact_query_get_multiple_results_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_get_multiple_results_async (query, count, opimd_contact_query_get_result_callback, data);
}



/* --- Dispose --------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_contact_query_dispose_data_t;

void opimd_contact_query_dispose_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_contact_query_dispose_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if (dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
	 g_free (proxy);
}


void opimd_contact_query_dispose(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_contact_query_dispose_data_t *data = g_malloc (sizeof (opimd_contact_query_dispose_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_ContactQuery_dispose_async (query, opimd_contact_query_dispose_callback, data);
}


