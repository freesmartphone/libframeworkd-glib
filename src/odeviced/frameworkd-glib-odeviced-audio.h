/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
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

#ifndef FRAMEWORKD_GLIB_ODEVICED_AUDIO_H
#define FRAMEWORKD_GLIB_ODEVICED_AUDIO_H

G_BEGIN_DECLS

/*As for now, didn't see a use for that one*/
GError* odeviced_audio_handle_errors(GError *dbus_error);

void odeviced_audio_get_info(void (*callback)(GError *, GHashTable*, gpointer), gpointer userdata);

void odeviced_audio_push_scenario(char *scenario, void (*callback)(GError *, gpointer), gpointer userdata);

void odeviced_audio_pull_scenario(void (*callback)(GError *, char *, gpointer), gpointer userdata);

void odeviced_audio_set_scenario(char *scenario, void (*callback)(GError *, gpointer), gpointer userdata);

void odeviced_audio_sound_status_handler(DBusGProxy *proxy, const char *id, const char *status, GHashTable* properties, gpointer user_data);

extern DBusGProxy *odevicedAudioBus ;
/* TODO : Other methods */

G_END_DECLS

#endif
