/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
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

#ifndef FRAMEWORKD_GLIB_OGSMD_SMS_H
#define FRAMEWORKD_GLIB_OGSMD_SMS_H

//#define SMS_ERROR g_quark_from_static_string(CALL_INTERFACE

void ogsmd_sms_message_sent_handler (DBusGProxy *proxy, const int id, const gboolean success, const char* reason, gpointer userdata);

void ogsmd_sms_send_message(const char* number, const char* content, const GHashTable *properties, void (*callback)(GError*, int transaction_index, const char *timestamp, gpointer), gpointer userdata);

extern DBusGProxy *smsBus;

#endif
