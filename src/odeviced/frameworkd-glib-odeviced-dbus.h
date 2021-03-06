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

#ifndef FRAMEWORKD_GLIB_ODEVICED_DBUS_H
#define FRAMEWORKD_GLIB_ODEVICED_DBUS_H

#include "../frameworkd-glib-dbus.h"

G_BEGIN_DECLS

#define DEBUG
#define ODEVICED_BUS         "org.freesmartphone.odeviced"
#define DEVICE_IDLE_NOTIFIER_BUS_PATH           "/org/freesmartphone/Device/IdleNotifier/0"
#define DEVICE_IDLE_NOTIFIER_INTERFACE		"org.freesmartphone.Device.IdleNotifier"
#define DEVICE_POWER_SUPPLY_BUS_PATH            "/org/freesmartphone/Device/PowerSupply/battery"
#define DEVICE_POWER_SUPPLY_INTERFACE		"org.freesmartphone.Device.PowerSupply"
#define DEVICE_AUDIO_BUS_PATH                   "/org/freesmartphone/Device/Audio"
#define DEVICE_AUDIO_INTERFACE                  "org.freesmartphone.Device.Audio"

void dbus_connect_to_odeviced_idle_notifier();

void dbus_connect_to_odeviced_power_supply();

void dbus_connect_to_odeviced_audio();

G_END_DECLS

#endif
