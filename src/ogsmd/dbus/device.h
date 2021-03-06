/* Generated by dbus-binding-tool; do not edit! */

#include <glib/gtypes.h>
#include <glib/gerror.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Device
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Device

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_get_info (DBusGProxy *proxy, GHashTable** OUT_info, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetInfo", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_info, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_get_info_reply) (DBusGProxy *proxy, GHashTable *OUT_info, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_get_info_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_info;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_info, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_get_info_reply)data->cb) (proxy, OUT_info, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_get_info_async (DBusGProxy *proxy, org_freesmartphone_GSM_Device_get_info_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetInfo", org_freesmartphone_GSM_Device_get_info_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_get_antenna_power (DBusGProxy *proxy, gboolean* OUT_antenna_power, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetAntennaPower", error, G_TYPE_INVALID, G_TYPE_BOOLEAN, OUT_antenna_power, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_get_antenna_power_reply) (DBusGProxy *proxy, gboolean OUT_antenna_power, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_get_antenna_power_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gboolean OUT_antenna_power;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_BOOLEAN, &OUT_antenna_power, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_get_antenna_power_reply)data->cb) (proxy, OUT_antenna_power, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_get_antenna_power_async (DBusGProxy *proxy, org_freesmartphone_GSM_Device_get_antenna_power_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetAntennaPower", org_freesmartphone_GSM_Device_get_antenna_power_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_set_antenna_power (DBusGProxy *proxy, const gboolean IN_antenna_power, GError **error)

{
  return dbus_g_proxy_call (proxy, "SetAntennaPower", error, G_TYPE_BOOLEAN, IN_antenna_power, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_set_antenna_power_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_set_antenna_power_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_set_antenna_power_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_set_antenna_power_async (DBusGProxy *proxy, const gboolean IN_antenna_power, org_freesmartphone_GSM_Device_set_antenna_power_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "SetAntennaPower", org_freesmartphone_GSM_Device_set_antenna_power_async_callback, stuff, g_free, G_TYPE_BOOLEAN, IN_antenna_power, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_get_features (DBusGProxy *proxy, GHashTable** OUT_features, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetFeatures", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_features, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_get_features_reply) (DBusGProxy *proxy, GHashTable *OUT_features, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_get_features_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_features;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_features, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_get_features_reply)data->cb) (proxy, OUT_features, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_get_features_async (DBusGProxy *proxy, org_freesmartphone_GSM_Device_get_features_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetFeatures", org_freesmartphone_GSM_Device_get_features_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_prepare_to_suspend (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "PrepareToSuspend", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_prepare_to_suspend_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_prepare_to_suspend_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_prepare_to_suspend_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_prepare_to_suspend_async (DBusGProxy *proxy, org_freesmartphone_GSM_Device_prepare_to_suspend_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "PrepareToSuspend", org_freesmartphone_GSM_Device_prepare_to_suspend_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Device_recover_from_suspend (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "RecoverFromSuspend", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Device_recover_from_suspend_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Device_recover_from_suspend_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Device_recover_from_suspend_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Device_recover_from_suspend_async (DBusGProxy *proxy, org_freesmartphone_GSM_Device_recover_from_suspend_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "RecoverFromSuspend", org_freesmartphone_GSM_Device_recover_from_suspend_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Device */

G_END_DECLS
