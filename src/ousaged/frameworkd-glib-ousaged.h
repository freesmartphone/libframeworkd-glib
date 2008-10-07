/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
 *              quickdev
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

#ifndef FRAMEWORKD_GLIB_OUSAGED_H
#define FRAMEWORKD_GLIB_OUSAGED_H

GError* ousaged_handle_errors(GError *dbus_error);

void ousaged_request_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_release_resource(const char *name, void (*callback)(GError *, gpointer), gpointer userdata);

void ousaged_list_resources(void (*callback)(GError *, char**, gpointer), gpointer userdata);

extern DBusGProxy *ousagedBus ;

#endif
