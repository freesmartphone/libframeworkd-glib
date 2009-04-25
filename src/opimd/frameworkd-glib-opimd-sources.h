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

#ifndef FRAMWORKD_GLIB_OPIMD_SOURCES_H
#define FRAMWORKD_GLIB_OPIMD_SOURCES_H


G_BEGIN_DECLS


/* PIM.Sources interfaces */
void opimd_sources_init_all_entries(void (*callback)(GError *, gpointer), gpointer userdata);
void opimd_sources_get_entry_count(void (*callback)(GError *, int, gpointer), gpointer userdata);

/* PIM.Source interface */
void opimd_source_get_name(const char *source_path, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_source_get_status(const char *source_path, void (*callback)(GError *, char *, gpointer), gpointer userdata);
void opimd_source_get_supported_pim_domains(const char *source_path, void (*callback)(GError *, GHashTable *, gpointer), gpointer userdata);


extern DBusGProxy *opimdSourcesBus;

G_END_DECLS


#endif


