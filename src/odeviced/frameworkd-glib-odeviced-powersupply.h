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

#ifndef FRAMEWORKD_GLIB_ODEVICED_POWER_SUPPLY_H
#define FRAMEWORKD_GLIB_ODEVICED_POWER_SUPPLY_H

#define DBUS_DEVICE_POWER_STATE_CHARGING "Charging"
#define DBUS_DEVICE_POWER_STATE_DISCHARGING "Discharging"
#define DBUS_DEVICE_POWER_STATE_FULL "Full"
#define DBUS_DEVICE_POWER_STATE_EMPTY "Empty"
#define DBUS_DEVICE_POWER_STATE_CRITICAL "Critical"

typedef enum {
    DEVICE_POWER_STATE_CHARGING,
    DEVICE_POWER_STATE_DISCHARGING,
    DEVICE_POWER_STATE_FULL,
    DEVICE_POWER_STATE_EMPTY,
    DEVICE_POWER_STATE_CRITICAL
} DevicePowerState;

/*As for now, didn't see a use for that one*/
GError* odeviced_power_supply_handle_errors(GError *dbus_error);

void odeviced_power_supply_get_info(void (*callback)(GError *, GHashTable*, gpointer), gpointer userdata);

void odeviced_power_supply_get_capacity(void (*callback)(GError *, int, gpointer), gpointer userdata);

void odeviced_power_supply_get_power_status(void (*callback)(GError *, int, gpointer), gpointer userdata);

void odeviced_power_supply_status_handler(DBusGProxy *proxy, const char *status, gpointer user_data);

void odeviced_power_supply_capacity_handler(DBusGProxy *proxy, const char *status, gpointer user_data);

extern DBusGProxy *odevicedPowerSupplyBus ;

#endif
