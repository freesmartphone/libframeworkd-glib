/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_Usage
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_Usage

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_list_resources (DBusGProxy *proxy, char *** OUT_resources, GError **error)

{
  return dbus_g_proxy_call (proxy, "ListResources", error, G_TYPE_INVALID, G_TYPE_STRV, OUT_resources, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_list_resources_reply) (DBusGProxy *proxy, char * *OUT_resources, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_list_resources_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_resources;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_resources, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_list_resources_reply)data->cb) (proxy, OUT_resources, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_list_resources_async (DBusGProxy *proxy, org_freesmartphone_Usage_list_resources_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ListResources", org_freesmartphone_Usage_list_resources_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_get_resource_policy (DBusGProxy *proxy, const char * IN_name, char ** OUT_policy, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResourcePolicy", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_STRING, OUT_policy, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_get_resource_policy_reply) (DBusGProxy *proxy, char * OUT_policy, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_get_resource_policy_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_policy;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_policy, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_get_resource_policy_reply)data->cb) (proxy, OUT_policy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_get_resource_policy_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_Usage_get_resource_policy_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResourcePolicy", org_freesmartphone_Usage_get_resource_policy_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_set_resource_policy (DBusGProxy *proxy, const char * IN_name, const char * IN_policy, GError **error)

{
  return dbus_g_proxy_call (proxy, "SetResourcePolicy", error, G_TYPE_STRING, IN_name, G_TYPE_STRING, IN_policy, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_set_resource_policy_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_set_resource_policy_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_set_resource_policy_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_set_resource_policy_async (DBusGProxy *proxy, const char * IN_name, const char * IN_policy, org_freesmartphone_Usage_set_resource_policy_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "SetResourcePolicy", org_freesmartphone_Usage_set_resource_policy_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_STRING, IN_policy, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_get_resource_state (DBusGProxy *proxy, const char * IN_name, gboolean* OUT_state, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResourceState", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_BOOLEAN, OUT_state, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_get_resource_state_reply) (DBusGProxy *proxy, gboolean OUT_state, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_get_resource_state_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gboolean OUT_state;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_BOOLEAN, &OUT_state, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_get_resource_state_reply)data->cb) (proxy, OUT_state, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_get_resource_state_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_Usage_get_resource_state_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResourceState", org_freesmartphone_Usage_get_resource_state_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_get_resource_users (DBusGProxy *proxy, const char * IN_name, char *** OUT_users, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResourceUsers", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_STRV, OUT_users, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_get_resource_users_reply) (DBusGProxy *proxy, char * *OUT_users, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_get_resource_users_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_users;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_users, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_get_resource_users_reply)data->cb) (proxy, OUT_users, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_get_resource_users_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_Usage_get_resource_users_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResourceUsers", org_freesmartphone_Usage_get_resource_users_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_request_resource (DBusGProxy *proxy, const char * IN_name, GError **error)

{
  return dbus_g_proxy_call (proxy, "RequestResource", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_request_resource_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_request_resource_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_request_resource_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_request_resource_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_Usage_request_resource_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "RequestResource", org_freesmartphone_Usage_request_resource_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_release_resource (DBusGProxy *proxy, const char * IN_name, GError **error)

{
  return dbus_g_proxy_call (proxy, "ReleaseResource", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_release_resource_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_release_resource_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_release_resource_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_release_resource_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_Usage_release_resource_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "ReleaseResource", org_freesmartphone_Usage_release_resource_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_Usage_suspend (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Suspend", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_Usage_suspend_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_Usage_suspend_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_Usage_suspend_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_Usage_suspend_async (DBusGProxy *proxy, org_freesmartphone_Usage_suspend_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Suspend", org_freesmartphone_Usage_suspend_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_Usage */

G_END_DECLS
