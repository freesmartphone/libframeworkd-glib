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
#include "frameworkd-glib-opimd-dbus.h"
#include "frameworkd-glib-opimd-contacts.h"
#include "frameworkd-glib-opimd-messages.h"
#include "frameworkd-glib-opimd-sources.h"



void dbus_connect_to_opimd_contacts(void) {
	 if(opimdContactsBus == NULL)
		  opimdContactsBus = dbus_connect_to_interface (OPIMD_BUS, CONTACTS_BUS_PATH, CONTACTS_INTERFACE, "PIM.Contacts");
}

DBusGProxy *dbus_connect_to_opimd_contact(const char *contact_path) {
	 return (dbus_connect_to_interface (OPIMD_BUS, contact_path, CONTACT_INTERFACE, "PIM.Contact"));
}

DBusGProxy *dbus_connect_to_opimd_contact_query(const char *query_path) {
	 return (dbus_connect_to_interface (OPIMD_BUS, query_path, CONTACT_QUERY_INTERFACE, "PIM.ContactQuery"));
}


void dbus_connect_to_opimd_messages(void) {
	 if(opimdMessagesBus == NULL)
		  opimdMessagesBus = dbus_connect_to_interface (OPIMD_BUS, MESSAGES_BUS_PATH, MESSAGES_INTERFACE, "PIM.Messages");
}

DBusGProxy *dbus_connect_to_opimd_message(const char *message_path) {
	 return (dbus_connect_to_interface (OPIMD_BUS, message_path, MESSAGE_INTERFACE, "PIM.Message"));
}

DBusGProxy *dbus_connect_to_opimd_message_query(const char *query_path) {
	 return (dbus_connect_to_interface (OPIMD_BUS, query_path, MESSAGE_QUERY_INTERFACE, "PIM.MessageQuery"));
}

DBusGProxy *dbus_connect_to_opimd_message_folder(const char *folder_path) {
	 return (dbus_connect_to_interface (OPIMD_BUS, folder_path, MESSAGE_FOLDER_INTERFACE, "PIM.MessageFolder"));
}

		

void dbus_connect_to_opimd_sources(void)
{
	if(opimdSourcesBus == NULL)
		opimdSourcesBus = dbus_connect_to_interface (OPIMD_BUS, SOURCES_BUS_PATH, SOURCES_INTERFACE, "PIM.Sources");
}


DBusGProxy *dbus_connect_to_opimd_source(const char *source_path)
{
	return (dbus_connect_to_interface (OPIMD_BUS, source_path, SOURCE_INTERFACE, "PIM.Source"));
}



