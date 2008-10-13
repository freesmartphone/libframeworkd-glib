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
#include "frameworkd-glib-odeviced-dbus.h"
#include "frameworkd-glib-odeviced-idlenotifier.h"
#include "frameworkd-glib-odeviced-powersupply.h"

void dbus_connect_to_odeviced_idle_notifier() {
    if(odevicedIdleNotifierBus == NULL)
        odevicedIdleNotifierBus = dbus_connect_to_interface (ODEVICED_BUS, DEVICE_IDLE_NOTIFIER_BUS_PATH, DEVICE_IDLE_NOTIFIER_INTERFACE, "Device Idle Notifier");
}
void dbus_connect_to_odeviced_power_supply() {
    if(odevicedPowerSupplyBus == NULL) 
        odevicedPowerSupplyBus = dbus_connect_to_interface (ODEVICED_BUS, DEVICE_POWER_SUPPLY_BUS_PATH, DEVICE_POWER_SUPPLY_INTERFACE, "Device Power Supply");
}
