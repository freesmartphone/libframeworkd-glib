/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Call
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Call

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_emergency (DBusGProxy *proxy, const char * IN_number, GError **error)

{
  return dbus_g_proxy_call (proxy, "Emergency", error, G_TYPE_STRING, IN_number, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_emergency_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_emergency_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_emergency_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_emergency_async (DBusGProxy *proxy, const char * IN_number, org_freesmartphone_GSM_Call_emergency_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Emergency", org_freesmartphone_GSM_Call_emergency_async_callback, stuff, g_free, G_TYPE_STRING, IN_number, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_activate (DBusGProxy *proxy, const gint IN_id, GError **error)

{
  return dbus_g_proxy_call (proxy, "Activate", error, G_TYPE_INT, IN_id, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_activate_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_activate_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_activate_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_activate_async (DBusGProxy *proxy, const gint IN_id, org_freesmartphone_GSM_Call_activate_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Activate", org_freesmartphone_GSM_Call_activate_async_callback, stuff, g_free, G_TYPE_INT, IN_id, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_activate_conference (DBusGProxy *proxy, const gint IN_id, GError **error)

{
  return dbus_g_proxy_call (proxy, "ActivateConference", error, G_TYPE_INT, IN_id, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_activate_conference_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_activate_conference_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_activate_conference_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_activate_conference_async (DBusGProxy *proxy, const gint IN_id, org_freesmartphone_GSM_Call_activate_conference_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ActivateConference", org_freesmartphone_GSM_Call_activate_conference_async_callback, stuff, g_free, G_TYPE_INT, IN_id, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_release (DBusGProxy *proxy, const gint IN_id, GError **error)

{
  return dbus_g_proxy_call (proxy, "Release", error, G_TYPE_INT, IN_id, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_release_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_release_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_release_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_release_async (DBusGProxy *proxy, const gint IN_id, org_freesmartphone_GSM_Call_release_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Release", org_freesmartphone_GSM_Call_release_async_callback, stuff, g_free, G_TYPE_INT, IN_id, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_hold_active (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "HoldActive", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_hold_active_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_hold_active_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_hold_active_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_hold_active_async (DBusGProxy *proxy, org_freesmartphone_GSM_Call_hold_active_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "HoldActive", org_freesmartphone_GSM_Call_hold_active_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_join (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Join", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_join_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_join_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_join_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_join_async (DBusGProxy *proxy, org_freesmartphone_GSM_Call_join_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Join", org_freesmartphone_GSM_Call_join_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_transfer (DBusGProxy *proxy, const char * IN_number, GError **error)

{
  return dbus_g_proxy_call (proxy, "Transfer", error, G_TYPE_STRING, IN_number, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_transfer_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_transfer_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_transfer_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_transfer_async (DBusGProxy *proxy, const char * IN_number, org_freesmartphone_GSM_Call_transfer_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Transfer", org_freesmartphone_GSM_Call_transfer_async_callback, stuff, g_free, G_TYPE_STRING, IN_number, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_release_held (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "ReleaseHeld", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_release_held_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_release_held_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_release_held_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_release_held_async (DBusGProxy *proxy, org_freesmartphone_GSM_Call_release_held_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ReleaseHeld", org_freesmartphone_GSM_Call_release_held_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_release_all (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "ReleaseAll", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_release_all_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_release_all_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_release_all_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_release_all_async (DBusGProxy *proxy, org_freesmartphone_GSM_Call_release_all_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ReleaseAll", org_freesmartphone_GSM_Call_release_all_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_initiate (DBusGProxy *proxy, const char * IN_number, const char * IN_type, gint* OUT_id, GError **error)

{
  return dbus_g_proxy_call (proxy, "Initiate", error, G_TYPE_STRING, IN_number, G_TYPE_STRING, IN_type, G_TYPE_INVALID, G_TYPE_INT, OUT_id, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_initiate_reply) (DBusGProxy *proxy, gint OUT_id, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_initiate_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_id;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_id, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_initiate_reply)data->cb) (proxy, OUT_id, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_initiate_async (DBusGProxy *proxy, const char * IN_number, const char * IN_type, org_freesmartphone_GSM_Call_initiate_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Initiate", org_freesmartphone_GSM_Call_initiate_async_callback, stuff, g_free, G_TYPE_STRING, IN_number, G_TYPE_STRING, IN_type, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_list_calls (DBusGProxy *proxy, GPtrArray** OUT_call_status, GError **error)

{
  return dbus_g_proxy_call (proxy, "ListCalls", error, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), G_TYPE_INVALID)), OUT_call_status, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_list_calls_reply) (DBusGProxy *proxy, GPtrArray *OUT_call_status, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_list_calls_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_call_status;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_INT, G_TYPE_STRING, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), G_TYPE_INVALID)), &OUT_call_status, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_list_calls_reply)data->cb) (proxy, OUT_call_status, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_list_calls_async (DBusGProxy *proxy, org_freesmartphone_GSM_Call_list_calls_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ListCalls", org_freesmartphone_GSM_Call_list_calls_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_GSM_Call_send_dtmf (DBusGProxy *proxy, const char * IN_tones, GError **error)

{
  return dbus_g_proxy_call (proxy, "SendDtmf", error, G_TYPE_STRING, IN_tones, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_GSM_Call_send_dtmf_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_GSM_Call_send_dtmf_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_GSM_Call_send_dtmf_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_GSM_Call_send_dtmf_async (DBusGProxy *proxy, const char * IN_tones, org_freesmartphone_GSM_Call_send_dtmf_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "SendDtmf", org_freesmartphone_GSM_Call_send_dtmf_async_callback, stuff, g_free, G_TYPE_STRING, IN_tones, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_GSM_Call */

G_END_DECLS
