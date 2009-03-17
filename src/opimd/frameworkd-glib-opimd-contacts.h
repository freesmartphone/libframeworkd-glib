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

#ifndef FRAMWORKD_GLIB_OPIMD_CONTACTS_H
#define FRAMWORKD_GLIB_OPIMD_CONTACTS_H

/* PIM.Contacts interface */
void opimd_contacts_add(const GHashTable *contact_data, void (*callback)(GError*, char *, gpointer), gpointer userdata);
void opimd_contacts_get_single_contact_single_field(const GHashTable *query, const char *field, void (*callback)(GError*, char *, gpointer), gpointer userdata);
void opimd_contacts_query(const GHashTable *query, void (*callback)(GError*, char *, gpointer), gpointer userdata);

/* PIM.Contact interface */
void opimd_contact_get_content(const char *contact_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);
void opimd_contact_get_multiple_fields(const char *contact_path, const char *field_list, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);

/* PIM.ContactQuery interface */
void opimd_contact_query_get_result_count(const char *query_path, void (*callback)(GError *, int, gpointer), gpointer userdata);
void opimd_contact_query_rewind(const char *query_path, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_contact_query_skip(const char *query_path, const gint count, void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_contact_query_get_contact_path(const char *query_path, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_contact_query_get_result(const char *query_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);
void opimd_contact_query_dispose(const char *query_path, void (*callback)(GError *, gpointer), gpointer userdata);

extern DBusGProxy *opimdContactsBus;

#endif


