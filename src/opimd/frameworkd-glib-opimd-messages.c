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
#include "frameworkd-glib-opimd-messages.h"
#include "frameworkd-glib-opimd-dbus.h"
#include "dbus/messages.h"


DBusGProxy *opimdMessagesBus = NULL;

/* === PIM.Messages Interface ====================================================== */

/* --- Add ------------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_messages_add_data_t;

void opimd_messages_add_callback(DBusGProxy *proxy, char *message_path, GError *dbus_error, gpointer userdata) {
	 opimd_messages_add_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, message_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_messages_add(const GHashTable *message_data, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_messages();
	 opimd_messages_add_data_t *data = g_malloc (sizeof (opimd_messages_add_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Messages_add_async (opimdMessagesBus, message_data, opimd_messages_add_callback, data);
}


/* --- GetSingleMessageSingleField ------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_messages_get_single_message_single_field_data_t;

void opimd_messages_get_single_message_single_field_callback(DBusGProxy *bus, char *value, GError *dbus_error, gpointer userdata) {
	 opimd_messages_get_single_message_single_field_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);

		  data->callback (error, value, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_messages_get_single_message_single_field(const GHashTable *query, const char *field, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_messages();
	 opimd_messages_get_single_message_single_field_data_t *data = g_malloc (sizeof (opimd_messages_get_single_message_single_field_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Messages_get_single_message_single_field_async (opimdMessagesBus, query, field, opimd_messages_get_single_message_single_field_callback, data);
}


/* --- Query ----------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_messages_query_data_t;

void opimd_messages_query_callback(DBusGProxy *proxy, char *query_path, GError *dbus_error, gpointer userdata) {
	 opimd_messages_query_data_t *data = userdata;
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

void opimd_messages_query(const GHashTable *query, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_messages();
	 opimd_messages_query_data_t *data = g_malloc (sizeof (opimd_messages_query_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Messages_query_async (opimdMessagesBus, query, opimd_messages_query_callback, data);
}


/* --- GetFolderNames -------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char **, gpointer);
	 gpointer userdata;
} opimd_messages_get_folder_names_data_t;

void opimd_messages_get_folder_names_callback(DBusGProxy *proxy, char **folder_names, GError *dbus_error, gpointer userdata) {
	 opimd_messages_get_folder_names_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, folder_names, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_messages_get_folder_names(void (*callback)(GError *, char **, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_messages();
	 opimd_messages_get_folder_names_data_t *data = g_malloc (sizeof (opimd_messages_get_folder_names_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Messages_get_folder_names_async (opimdMessagesBus, opimd_messages_get_folder_names_callback, data);
}


/* --- GetFolderURIFromName -------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_messages_get_folder_path_from_name_data_t;

void opimd_messages_get_folder_path_from_name_callback(DBusGProxy *proxy, char *folder_path, GError *dbus_error, gpointer userdata) {
	 opimd_messages_get_folder_path_from_name_data_t *data = userdata;
	 GError *error = NULL;

	 if (data->callback != NULL) {
		  if (dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, folder_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_messages_get_folder_path_from_name(const char *folder_name, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 dbus_connect_to_opimd_messages();
	 opimd_messages_get_folder_path_from_name_data_t *data = g_malloc (sizeof (opimd_messages_get_folder_path_from_name_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Messages_get_folder_path_from_name_async (opimdMessagesBus, folder_name, opimd_messages_get_folder_path_from_name_callback, data);
}


/* --- (signal) NewMessage --------------------------------------------------------- */

void opimd_messages_new_handler (DBusGProxy *proxy, char *message_path, gpointer userdata) {
	 void (*callback)(char *message_path) = NULL;

	 callback = userdata;

	 if(callback != NULL)
		  (*callback)(message_path);
}


/* === PIM.Message Interface ======================================================= */

/* --- GetContent ------------------------------------------------------------------ */

typedef struct
{
	 void (*callback)(GError *, GHashTable *, gpointer);
	 gpointer userdata;
} opimd_message_get_content_data_t;

void opimd_message_get_content_callback(DBusGProxy *proxy, GHashTable *content, GError *dbus_error, gpointer userdata) {
	 opimd_message_get_content_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback(error, content, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
	 g_free (proxy);
}

void opimd_message_get_content(const char *message_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata) {
	 DBusGProxy *proxy = dbus_connect_to_opimd_message (message_path);
	 opimd_message_get_content_data_t *data = g_malloc (sizeof (opimd_message_get_content_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Message_get_content_async (proxy, opimd_message_get_content_callback, data);
}


/* --- GetMultipleFields ----------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, GHashTable *, gpointer);
	 gpointer userdata;
} opimd_message_get_multiple_fields_data_t;

void opimd_message_get_multiple_fields_callback(DBusGProxy *proxy, GHashTable *field_data, GError *dbus_error, gpointer userdata) {
	 opimd_message_get_multiple_fields_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, field_data, userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
	 g_free (proxy);
}

void opimd_message_get_multiple_fields(const char *message_path, const char *fields, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata) {
	 DBusGProxy *proxy = dbus_connect_to_opimd_message (message_path);
	 opimd_message_get_multiple_fields_data_t *data = g_malloc (sizeof (opimd_message_get_multiple_fields_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Message_get_multiple_fields_async (proxy, fields, opimd_message_get_multiple_fields_callback, data);
}


/* --- MoveToFolder ---------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_message_move_to_folder_data_t;

void opimd_message_move_to_folder_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_message_move_to_folder_data_t *data = userdata;
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

void opimd_message_move_to_folder(const char *message_path, const char *folder, void (*callback)(GError *, gpointer), gpointer userdata) {
	 DBusGProxy *proxy = dbus_connect_to_opimd_message (message_path);
	 opimd_message_move_to_folder_data_t *data = g_malloc (sizeof (opimd_message_move_to_folder_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_Message_move_to_folder_async (proxy, folder, opimd_message_move_to_folder_callback, data);
}


/* === PIM.MessageQuery Interface ================================================== */

/* --- GetResultCount -------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gint, gpointer);
	 gpointer userdata;
} opimd_message_query_get_result_count_data_t;

void opimd_message_query_get_result_count_callback(DBusGProxy *proxy, int count, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_get_result_count_data_t *data = userdata;
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

void opimd_message_query_get_result_count(DBusGProxy *query, void (*callback)(GError *, gint, gpointer), gpointer userdata) {
	 opimd_message_query_get_result_count_data_t *data = g_malloc (sizeof (opimd_message_query_get_result_count_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_get_result_count_async (query, opimd_message_query_get_result_count_callback, data);
}


/* --- Rewind ---------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_message_query_rewind_data_t;

void opimd_message_query_rewind_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_rewind_data_t *data = userdata;
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

void opimd_message_query_rewind(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_message_query_rewind_data_t *data = g_malloc (sizeof (opimd_message_query_rewind_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_rewind_async (query, opimd_message_query_rewind_callback, data);
}


/* --- Skip ------------------------------------------------------------------------ */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_message_query_skip_data_t;

void opimd_message_query_skip_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_skip_data_t *data = userdata;
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

void opimd_message_query_skip(DBusGProxy *query, const gint count, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_message_query_skip_data_t *data = g_malloc (sizeof (opimd_message_query_skip_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_skip_async (query, count, opimd_message_query_skip_callback, data);
}


/* --- GetMessagePath -------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char *, gpointer);
	 gpointer userdata;
} opimd_message_query_get_message_path_data_t;

void opimd_message_query_get_message_path_callback(DBusGProxy *proxy, char *message_path, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_get_message_path_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, message_path, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
}

void opimd_message_query_get_message_path(DBusGProxy *query, void (*callback)(GError *, char *, gpointer), gpointer userdata) {
	 opimd_message_query_get_message_path_data_t *data = g_malloc (sizeof (opimd_message_query_get_message_path_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_get_message_path_async (query, opimd_message_query_get_message_path_callback, data);
}


/* --- GetResult ------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, GHashTable *, gpointer);
	 gpointer userdata;
} opimd_message_query_get_result_data_t;

void opimd_message_query_get_result_callback(DBusGProxy *proxy, GHashTable *result, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_get_result_data_t *data = userdata;
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

void opimd_message_query_get_result(DBusGProxy *query, void (*callback)(GError *, GHashTable *result, gpointer), gpointer userdata) {
	 opimd_message_query_get_result_data_t *data = g_malloc (sizeof (opimd_message_query_get_result_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_get_result_async (query, opimd_message_query_get_result_callback, data);
}


/* --- GetMultipleResults ---------------------------------------------------------- */

typedef struct {
    void (*callback)(GError *, GPtrArray *, gpointer);
    gpointer userdata;
} opimd_message_query_get_multiple_results_data_t;

void opimd_message_query_get_multiple_results_callback(DBusGProxy *proxy, GPtrArray *resultset, GError *dbus_error, gpointer userdata)
{
	 opimd_message_query_get_multiple_results_data_t *data = userdata;
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
	
void opimd_message_query_get_multiple_results(DBusGProxy *query, int count, void (*callback)(GError *, GPtrArray *, gpointer), gpointer userdata)
{
    opimd_message_query_get_multiple_results_data_t *data = g_malloc (sizeof (opimd_message_query_get_multiple_results_data_t));
    data->callback = callback;
    data->userdata = userdata;
    org_freesmartphone_PIM_MessageQuery_get_multiple_results_async (query, count, opimd_message_query_get_multiple_results_callback, data);
}



/* --- Dispose --------------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gpointer);
	 gpointer userdata;
} opimd_message_query_dispose_data_t;

void opimd_message_query_dispose_callback(DBusGProxy *proxy, GError *dbus_error, gpointer userdata) {
	 opimd_message_query_dispose_data_t * data = userdata;
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

void opimd_message_query_dispose(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata) {
	 opimd_message_query_dispose_data_t *data = g_malloc (sizeof (opimd_message_query_dispose_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageQuery_dispose_async (query, opimd_message_query_dispose_callback, data);
}


/* === PIM.MessageFolder Interface ================================================= */

/* --- GetMessageCount ------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, gint, gpointer);
	 gpointer userdata;
} opimd_message_folder_get_message_count_data_t;

void opimd_message_folder_get_message_count_callback(DBusGProxy *proxy, gint count, GError *dbus_error, gpointer userdata) {
	 opimd_message_folder_get_message_count_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, count, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
	 g_free (proxy);
}

void opimd_message_folder_get_message_count(const char *folder_path, void (*callback)(GError *, gint, gpointer), gpointer userdata) {
	 DBusGProxy *proxy = dbus_connect_to_opimd_message_folder (folder_path);
	 opimd_message_folder_get_message_count_data_t *data = g_malloc (sizeof (opimd_message_folder_get_message_count_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageFolder_get_message_count_async (proxy, opimd_message_folder_get_message_count_callback, data);
}


/* --- GetMessagePaths ------------------------------------------------------------- */

typedef struct
{
	 void (*callback)(GError *, char **, gpointer);
	 gpointer userdata;
} opimd_message_folder_get_message_paths_data_t;

void opimd_message_folder_get_message_paths_callback(DBusGProxy *proxy, char **message_paths, GError *dbus_error, gpointer userdata) {
	 opimd_message_folder_get_message_paths_data_t *data = userdata;
	 GError *error = NULL;

	 if(data->callback != NULL) {
		  if(dbus_error != NULL)
				error = dbus_handle_errors (dbus_error);
		  data->callback (error, message_paths, data->userdata);
		  if(error != NULL) g_error_free (error);
	 }
	 if(dbus_error != NULL) g_error_free (dbus_error);

	 g_free (data);
	 g_free (proxy);
}

void opimd_message_folder_get_message_paths(const char *folder_path, const gint first, const gint count, void (*callback)(GError *, char **, gpointer), gpointer userdata) {
	 DBusGProxy *proxy = dbus_connect_to_opimd_message_folder (folder_path);
	 opimd_message_folder_get_message_paths_data_t *data = g_malloc (sizeof (opimd_message_folder_get_message_paths_data_t));
	 data->callback = callback;
	 data->userdata = userdata;
	 org_freesmartphone_PIM_MessageFolder_get_message_paths_async (proxy, first, count, opimd_message_folder_get_message_paths_callback, data);
}


/* --- (signal) MessageMoved ------------------------------------------------------- */

void opimd_message_folder_message_moved_handler(DBusGProxy *proxy, char *message_path, char *new_folder, gpointer userdata) {
	 void (*callback)(char *message_path, char *new_folder) = NULL;

	 callback = userdata;

	 if(callback != NULL)
		  (*callback)(message_path, new_folder);
}


