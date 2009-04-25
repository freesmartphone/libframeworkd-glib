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

#ifndef FRAMEWORKD_GLIB_OPIMD_MESSAGES_H
#define FRAMEWORKD_GLIB_OPIMD_MESSAGES_H

/* PIM.Messages Interface */
void opimd_messages_add(const GHashTable *message_data, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_messages_get_single_message_single_field(const GHashTable *query, const char *field, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_messages_query(const GHashTable *query, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_messages_get_folder_names(void (*callback)(GError *, char **, gpointer), gpointer userdata);
void opimd_messages_get_folder_path_from_name(const char *name, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_messages_new_message_handler(DBusGProxy *proxy, char *message_path, gpointer userdata);

/* PIM.Message Interface */
void opimd_message_get_content(const char *message_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);
void opimd_message_get_multiple_fields(const char *message_path, const char *fields, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);
void opimd_message_move_to_folder(const char *message_path, const char *folder, void (*callback)(GError *, gpointer), gpointer userdata);

/* PIM.MessageQuery Interface */
void opimd_message_query_get_result_count(const char *query_path, void (*callback)(GError *, int, gpointer), gpointer userdata);
void opimd_message_query_rewind(const char *query_path, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_message_query_skip(const char *query_path, const gint count, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_message_query_get_message_path(const char *query_path, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_message_query_get_result(const char *query_path, void (*callback)(GError *, GHashTable *result, gpointer), gpointer userdata);
/* TODO: as what type to pass back the multiple results... ??? */
//void opimd_message_query_get_multiple_results(const char *query_path, int count, void (*callback)(GError *, foo results), gpointer userdata);
void opimd_message_query_dispose(const char *query_path, void (*callback)(GError *, gpointer), gpointer userdata);

/* PIM.MessageFolder Interface */
void opimd_message_folder_get_message_count(const char *folder_path, void (*callback)(GError *, int, gpointer), gpointer userdata);
void opimd_message_folder_get_message_paths(const char *folder_path, const gint first, const gint count, void (*callback)(GError *, char **, gpointer), gpointer userdata);
void opimd_message_folder_message_moved_handler(DBusGProxy *proxy, char *message_path, char *new_folder, gpointer userdata);

extern DBusGProxy *opimdMessagesBus;

#endif

