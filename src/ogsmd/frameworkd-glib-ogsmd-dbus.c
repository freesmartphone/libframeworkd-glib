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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <dbus/dbus-glib.h>
#include <dbus/dbus-glib-bindings.h>
#include "frameworkd-glib-ogsmd-dbus.h"
#include "frameworkd-glib-ogsmd-call.h"
#include "frameworkd-glib-ogsmd-sim.h"
#include "frameworkd-glib-ogsmd-network.h"
#include "frameworkd-glib-ogsmd-device.h"
#include "frameworkd-glib-ogsmd-sms.h"


void dbus_connect_to_ogsmd_call() {
    if(callBus == NULL)
        callBus = dbus_connect_to_interface (GSMD_BUS, GSMD_BUS_PATH, CALL_INTERFACE, "GSM.Call");
}

void dbus_connect_to_ogsmd_network() {
    if(networkBus == NULL)
        networkBus = dbus_connect_to_interface (GSMD_BUS, GSMD_BUS_PATH, NETWORK_INTERFACE, "GSM.Network");
}

void dbus_connect_to_ogsmd_sim() {
    if(simBus == NULL)
        simBus = dbus_connect_to_interface (GSMD_BUS, GSMD_BUS_PATH, SIM_INTERFACE, "GSM.SIM");
}

void dbus_connect_to_ogsmd_device() {
    if(deviceBus == NULL)
        deviceBus = dbus_connect_to_interface (GSMD_BUS, GSMD_BUS_PATH, DEVICE_INTERFACE, "GSM.Device");
}

void dbus_connect_to_ogsmd_sms() {
    if(smsBus == NULL)
        smsBus = dbus_connect_to_interface(GSMD_BUS, GSMD_BUS_PATH, SMS_INTERFACE, "GSM.SMS");
}

