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

#ifndef FRAMEWORKD_GLIB_OGSMD_DBUS_H
#define FRAMEWORKD_GLIB_OGSMD_DBUS_H

#include "../frameworkd-glib-dbus.h"

G_BEGIN_DECLS

#define DEBUG
#define NETWORKD_BUS        "org.freesmartphone.onetworkd"
#define GSMD_BUS            "org.freesmartphone.ogsmd"
#define GSMD_BUS_PATH       "/org/freesmartphone/GSM/Device"
#define CALL_INTERFACE		"org.freesmartphone.GSM.Call"
#define SIM_INTERFACE		"org.freesmartphone.GSM.SIM"
#define NETWORK_INTERFACE 	"org.freesmartphone.GSM.Network"
#define	DEVICE_INTERFACE	"org.freesmartphone.GSM.Device"
#define	SMS_INTERFACE		"org.freesmartphone.GSM.SMS"

void dbus_connect_to_ogsmd_call();
void dbus_connect_to_ogsmd_network();
void dbus_connect_to_ogsmd_sim();
void dbus_connect_to_ogsmd_device();
void dbus_connect_to_ogsmd_sms();

G_END_DECLS

#endif
