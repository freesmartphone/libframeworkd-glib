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

#ifndef FRAMEWORKD_GLIB_ODEVICED_IDLE_NOTIFIER_H
#define FRAMEWORKD_GLIB_ODEVICED_IDLE_NOTIFIER_H

G_BEGIN_DECLS

#define DBUS_DEVICE_IDLE_STATE_BUSY "busy"
#define DBUS_DEVICE_IDLE_STATE_IDLE "idle"
#define DBUS_DEVICE_IDLE_STATE_IDLE_DIM "idle_dim"
#define DBUS_DEVICE_IDLE_STATE_PRELOCK "idle_prelock"
#define DBUS_DEVICE_IDLE_STATE_LOCK "lock"
#define DBUS_DEVICE_IDLE_STATE_SUSPEND "suspend"
#define DBUS_DEVICE_IDLE_STATE_AWAKE "awake"

typedef enum {
    DEVICE_IDLE_STATE_BUSY,
    DEVICE_IDLE_STATE_IDLE,
    DEVICE_IDLE_STATE_IDLE_DIM,
    DEVICE_IDLE_STATE_PRELOCK,
    DEVICE_IDLE_STATE_LOCK,
    DEVICE_IDLE_STATE_SUSPEND,
    DEVICE_IDLE_STATE_AWAKE
} DeviceIdleState;

/*As for now, didn't see a use for that one*/
GError* odeviced_idle_notifier_handle_errors(GError *dbus_error);

void odeviced_idle_notifier_get_state(void (*callback)(GError *, int, gpointer), gpointer userdata);

void odeviced_idle_notifier_set_state(int state, void (*callback)(GError *, gpointer), gpointer userdata);

void odeviced_idle_notifier_state_handler(DBusGProxy *proxy, const char *state, gpointer user_data);

extern DBusGProxy *odevicedIdleNotifierBus ;

G_END_DECLS

#endif
