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


G_BEGIN_DECLS


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
void opimd_message_query_get_result_count(DBusGProxy *query, void (*callback)(GError *, int, gpointer), gpointer userdata);
void opimd_message_query_rewind(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_message_query_skip(DBusGProxy *query, const gint count, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_message_query_get_message_path(DBusGProxy *query, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_message_query_get_result(DBusGProxy *query, void (*callback)(GError *, GHashTable *result, gpointer), gpointer userdata);
void opimd_message_query_get_multiple_results(DBusGProxy *query, int count, void (*callback)(GError *, GPtrArray *, gpointer), gpointer userdata);
void opimd_message_query_dispose(DBusGProxy *query, void (*callback)(GError *, gpointer), gpointer userdata);

/* PIM.MessageFolder Interface */
void opimd_message_folder_get_message_count(const char *folder_path, void (*callback)(GError *, int, gpointer), gpointer userdata);
void opimd_message_folder_get_message_paths(const char *folder_path, const gint first, const gint count, void (*callback)(GError *, char **, gpointer), gpointer userdata);
void opimd_message_folder_message_moved_handler(DBusGProxy *proxy, char *message_path, char *new_folder, gpointer userdata);

extern DBusGProxy *opimdMessagesBus;

G_END_DECLS

#endif

