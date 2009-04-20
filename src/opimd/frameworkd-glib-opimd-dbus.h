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


#ifndef FRAMEWORKD_GLIB_OPIMD_DBUS_H
#define FRAMEWORKD_GLIB_OPIMD_DBUS_H

#include "../frameworkd-glib-dbus.h"

#define DEBUG

#define OPIMD_BUS                   "org.freesmartphone.opimd"

#define CONTACTS_BUS_PATH            "/org/freesmartphone/PIM/Contacts"
#define CONTACTS_INTERFACE           "org.freesmartphone.PIM.Contacts"
#define CONTACT_INTERFACE            "org.freesmartphone.PIM.Contact"
#define CONTACT_QUERY_INTERFACE      "org.freesmartphone.PIM.ContactQuery"

#define MESSAGES_BUS_PATH            "/org/freesmartphone/PIM/Messages"
#define MESSAGES_INTERFACE           "org.freesmartphone.PIM.Messages"
#define MESSAGE_INTERFACE            "org.freesmartphone.PIM.Message"
#define MESSAGE_QUERY_INTERFACE      "org.freesmartphone.PIM.MessageQuery"
#define MESSAGE_FOLDER_INTERFACE     "org.freesmartphone.PIM.MessageFolder"

#define SOURCES_BUS_PATH             "/org/freesmartphone/PIM/Sources"
#define SOURCES_INTERFACE            "org.freesmartphone.PIM.Sources"
#define SOURCE_INTERFACE             "org.freesmartphone.PIM.Source"



void dbus_connect_to_opimd_contacts(void);
DBusGProxy *dbus_connect_to_opimd_contact(const char *contact_path);
DBusGProxy *dbus_connect_to_opimd_contact_query(const char *query_path);

void dbus_connect_to_opimd_messages(void);
DBusGProxy *dbus_connect_to_opimd_message(const char *message_path);
DBusGProxy *dbus_connect_to_opimd_message_query(const char *query_path);
DBusGProxy *dbus_connect_to_opimd_message_folder(const char *folder_path);

void dbus_connect_to_opimd_sources(void);
DBusGProxy *dbus_connect_to_opimd_source(const char *source_path);


#endif

