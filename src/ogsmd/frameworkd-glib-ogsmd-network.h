/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              Marc-Olivier Barre <marco@marcochapeau.org>
 *              Julien Cassignol <ainulindale@gmail.com>
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

#ifndef FRAMEWORKD_GLIB_OGSMD_NETWORK_H
#define FRAMEWORKD_GLIB_OGSMD_NETWORK_H

G_BEGIN_DECLS

#define NETWORK_ERROR g_quark_from_static_string(NETWORK_INTERFACE)
#define DBUS_NETWORK_ERROR_NOT_PRESENT "org.freesmartphone.GSM.Network.NotPresent"
#define DBUS_NETWORK_ERROR_UNAUTHORIZED "org.freesmartphone.GSM.Network.Unauthorized"
#define DBUS_NETWORK_ERROR_NOT_SUPPORTED "org.freesmartphone.GSM.Network.NotSupported"
#define DBUS_NETWORK_ERROR_NOT_FOUND "org.freesmartphone.GSM.Network.NotFound"

#define DBUS_NETWORK_PROPERTY_REGISTRATION "registration"
#define DBUS_NETWORK_PROPERTY_PROVIDER "provider"
#define DBUS_NETWORK_PROPERTY_STRENGTH "strength"
#define DBUS_NETWORK_PROPERTY_LOCATION_AREA "lac"
#define DBUS_NETWORK_PROPERTY_CELL_ID "cid"

#define DBUS_NETWORK_PROPERTY_REGISTRATION_UNREGISTERED "unregistered"
#define DBUS_NETWORK_PROPERTY_REGISTRATION_HOME "home"
#define DBUS_NETWORK_PROPERTY_REGISTRATION_BUSY "busy"
#define DBUS_NETWORK_PROPERTY_REGISTRATION_DENIED "denied"
#define DBUS_NETWORK_PROPERTY_REGISTRATION_UNKNOWN "unknown"
#define DBUS_NETWORK_PROPERTY_REGISTRATION_ROAMING "roaming"

#define DBUS_NETWORK_PROVIDER_STATUS_UNKNOWN "unknown"
#define DBUS_NETWORK_PROVIDER_STATUS_AVAILABLE "available"
#define DBUS_NETWORK_PROVIDER_STATUS_CURRENT "current"
#define DBUS_NETWORK_PROVIDER_STATUS_FORBIDDEN "forbidden"

#define DBUS_NETWORK_FORWARD_REASON_UNCONDITIONAL "unconditional"
#define DBUS_NETWORK_FORWARD_REASON_MOBILE_BUSY "mobile busy"
#define DBUS_NETWORK_FORWARD_REASON_NO_REPLY "no reply"
#define DBUS_NETWORK_FORWARD_REASON_NOT_REACHABLE "not reachable"
#define DBUS_NETWORK_FORWARD_REASON_ALL "all"
#define DBUS_NETWORK_FORWARD_REASON_ALL_CONDITIONAL "all conditional"

#define DBUS_NETWORK_FORWARD_CLASS_VOICE "voice"
#define DBUS_NETWORK_FORWARD_CLASS_DATA "data"
#define DBUS_NETWORK_FORWARD_CLASS_VOICE_DATA "voice+data"
#define DBUS_NETWORK_FORWARD_CLASS_FAX "fax"
#define DBUS_NETWORK_FORWARD_CLASS_VOICE_DATA_FAX "voice+data+fax"
#define DBUS_NETWORK_FORWARD_CLASS_SMS "sms"
#define DBUS_NETWORK_FORWARD_CLASS_DCS "dcs"
#define DBUS_NETWORK_FORWARD_CLASS_DCA "dca"
#define DBUS_NETWORK_FORWARD_CLASS_DPA "dpa"
#define DBUS_NETWORK_FORWARD_CLASS_PAD "pad"

#define DBUS_NETWORK_IDENTIFICATION_STATUS_ON "on"
#define DBUS_NETWORK_IDENTIFICATION_STATUS_OFF "off"
#define DBUS_NETWORK_IDENTIFICATION_STATUS_NETWORK "network"

#define DBUS_NETWORK_USSD_MODE_COMPLETED "completed"
#define DBUS_NETWORK_USSD_MODE_USERACTION "useraction"
#define DBUS_NETWORK_USSD_MODE_TERMINATED "terminated"
#define DBUS_NETWORK_USSD_MODE_LOCALCLIENT "localclient"
#define DBUS_NETWORK_USSD_MODE_UNSUPPORTED "unsupported"
#define DBUS_NETWORK_USSD_MODE_TIMEOUT "timeout"


typedef enum {
    NETWORK_ERROR_NOT_PRESENT = -1,
    NETWORK_ERROR_UNAUTHORIZED = -2,
    NETWORK_ERROR_NOT_FOUND = -3,
    NETWORK_ERROR_NOT_SUPPORTED = -4,
} NetworkErrors;

typedef enum {
    NETWORK_PROPERTY_REGISTRATION_UNREGISTERED,
    NETWORK_PROPERTY_REGISTRATION_HOME,
    NETWORK_PROPERTY_REGISTRATION_BUSY,
    NETWORK_PROPERTY_REGISTRATION_DENIED,
    NETWORK_PROPERTY_REGISTRATION_UNKNOWN,
    NETWORK_PROPERTY_REGISTRATION_ROAMING    
} NetworkRegistrationProperties;

typedef enum {
    NETWORK_PROVIDER_STATUS_UNKNOWN,
    NETWORK_PROVIDER_STATUS_AVAILABLE,
    NETWORK_PROVIDER_STATUS_CURRENT,
    NETWORK_PROVIDER_STATUS_FORBIDDEN
} NetworkProviderStatus;

typedef enum {
    NETWORK_FORWARD_REASON_UNCONDITIONAL,
    NETWORK_FORWARD_REASON_MOBILE_BUSY,
    NETWORK_FORWARD_REASON_NO_REPLY,
    NETWORK_FORWARD_REASON_NOT_REACHABLE,
    NETWORK_FORWARD_REASON_ALL,
    NETWORK_FORWARD_REASON_ALL_CONDITIONAL
} NetworkForwardReasons;

typedef enum {
    NETWORK_FORWARD_CLASS_VOICE,
    NETWORK_FORWARD_CLASS_DATA,
    NETWORK_FORWARD_CLASS_VOICE_DATA,
    NETWORK_FORWARD_CLASS_FAX,
    NETWORK_FORWARD_CLASS_VOICE_DATA_FAX,
    NETWORK_FORWARD_CLASS_SMS,
    NETWORK_FORWARD_CLASS_DCS,
    NETWORK_FORWARD_CLASS_DCA,
    NETWORK_FORWARD_CLASS_DPA,
    NETWORK_FORWARD_CLASS_PAD
} NetworkForwardClasses;

typedef enum {
    NETWORK_IDENTIFICATION_STATUS_ON,
    NETWORK_IDENTIFICATION_STATUS_OFF,
    NETWORK_IDENTIFICATION_STATUS_NETWORK
} NetworkIdentificationStatus;

typedef enum {
    NETWORK_USSD_MODE_COMPLETED,
    NETWORK_USSD_MODE_USERACTION,
    NETWORK_USSD_MODE_TERMINATED,
    NETWORK_USSD_MODE_LOCALCLIENT,
    NETWORK_USSD_MODE_UNSUPPORTED,
    NETWORK_USSD_MODE_TIMEOUT
} NetworkUssdModes;

extern DBusGProxy *networkBus;

void ogsmd_network_status_handler (DBusGProxy *proxy, const  GHashTable * status, gpointer user_data);
void ogsmd_network_signal_strength_handler (DBusGProxy *proxy, const int signal_strength, gpointer user_data);
void ogsmd_network_incoming_ussd_handler (DBusGProxy *proxy, const char *mode, const char *message, gpointer user_data);

void ogsmd_network_register(void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_register_with_provider(int provider_id, void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_unregister(void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_get_status(void (*callback)(GError *, GHashTable* status, gpointer), gpointer userdata);

void ogsmd_network_get_signal_strength(void (*callback)(GError *, int strength, gpointer), gpointer userdata);

void ogsmd_network_list_providers(void (*callback)(GError *, GPtrArray* providers, gpointer), gpointer userdata);

void ogsmd_network_get_network_country_code(void (*callback)(GError *, char* dial_code, char* country_name, gpointer), gpointer userdata);

void ogsmd_network_get_call_forwarding(int reason, void (*callback)(GError *, GHashTable* forwards, gpointer), gpointer userdata);

void ogsmd_network_enable_call_forwarding(int reason, int forward_class, char *number, int timeout, void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_disable_call_forwarding(int reason, int forward_class, void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_set_calling_identification(int visible, void (*callback)(GError *, gpointer), gpointer userdata);

void ogsmd_network_get_calling_identification(void (*callback)(GError *, int visible, gpointer), gpointer userdata);

int ogsmd_network_get_registration_status_from_dbus(GHashTable *properties);
const char* ogsmd_network_get_location_area_from_dbus(GHashTable *properties);
const char* ogsmd_network_get_provider_from_dbus(GHashTable *properties);
const char* ogsmd_network_get_cell_id_from_dbus(GHashTable *properties);
int ogsmd_network_get_signal_strength_from_dbus(GHashTable *properties);

char* ogsmd_network_get_reason_for_dbus(int reason);
int ogsmd_network_get_reason_from_dbus(char *reason);
char * ogsmd_network_get_forward_class_for_dbus(int forward_class);
int ogsmd_network_get_forward_class_from_dbus(char *forward_class);
char * ogsmd_network_get_visible_for_dbus(int visible);
int ogsmd_network_get_visible_from_dbus(char *);

void ogsmd_network_send_ussd_request(char *request, void (*callback)(GError *, gpointer), gpointer userdata);

GError* ogsmd_network_handle_errors(GError *dbus_error);

G_END_DECLS

#endif
