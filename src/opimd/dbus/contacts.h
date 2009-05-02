/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contacts
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contacts

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contacts_add (DBusGProxy *proxy, const GHashTable* IN_contact_data, char ** OUT_contact_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "Add", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_contact_data, G_TYPE_INVALID, G_TYPE_STRING, OUT_contact_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contacts_add_reply) (DBusGProxy *proxy, char * OUT_contact_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contacts_add_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_contact_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_contact_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contacts_add_reply)data->cb) (proxy, OUT_contact_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contacts_add_async (DBusGProxy *proxy, const GHashTable* IN_contact_data, org_freesmartphone_PIM_Contacts_add_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Add", org_freesmartphone_PIM_Contacts_add_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_contact_data, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contacts_get_single_contact_single_field (DBusGProxy *proxy, const GHashTable* IN_query, const char * IN_field, char ** OUT_value, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetSingleContactSingleField", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_STRING, IN_field, G_TYPE_INVALID, G_TYPE_STRING, OUT_value, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contacts_get_single_contact_single_field_reply) (DBusGProxy *proxy, char * OUT_value, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contacts_get_single_contact_single_field_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_value;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_value, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contacts_get_single_contact_single_field_reply)data->cb) (proxy, OUT_value, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contacts_get_single_contact_single_field_async (DBusGProxy *proxy, const GHashTable* IN_query, const char * IN_field, org_freesmartphone_PIM_Contacts_get_single_contact_single_field_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetSingleContactSingleField", org_freesmartphone_PIM_Contacts_get_single_contact_single_field_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_STRING, IN_field, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contacts_query (DBusGProxy *proxy, const GHashTable* IN_query, char ** OUT_query_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "Query", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_INVALID, G_TYPE_STRING, OUT_query_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contacts_query_reply) (DBusGProxy *proxy, char * OUT_query_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contacts_query_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_query_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_query_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contacts_query_reply)data->cb) (proxy, OUT_query_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contacts_query_async (DBusGProxy *proxy, const GHashTable* IN_query, org_freesmartphone_PIM_Contacts_query_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Query", org_freesmartphone_PIM_Contacts_query_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contacts */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contact
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contact

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contact_get_content (DBusGProxy *proxy, GHashTable** OUT_contact_data, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetContent", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_contact_data, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contact_get_content_reply) (DBusGProxy *proxy, GHashTable *OUT_contact_data, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contact_get_content_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_contact_data;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_contact_data, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contact_get_content_reply)data->cb) (proxy, OUT_contact_data, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contact_get_content_async (DBusGProxy *proxy, org_freesmartphone_PIM_Contact_get_content_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetContent", org_freesmartphone_PIM_Contact_get_content_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contact_get_multiple_fields (DBusGProxy *proxy, const char * IN_field_list, GHashTable** OUT_field_data, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMultipleFields", error, G_TYPE_STRING, IN_field_list, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_field_data, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contact_get_multiple_fields_reply) (DBusGProxy *proxy, GHashTable *OUT_field_data, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contact_get_multiple_fields_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_field_data;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_field_data, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contact_get_multiple_fields_reply)data->cb) (proxy, OUT_field_data, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contact_get_multiple_fields_async (DBusGProxy *proxy, const char * IN_field_list, org_freesmartphone_PIM_Contact_get_multiple_fields_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMultipleFields", org_freesmartphone_PIM_Contact_get_multiple_fields_async_callback, stuff, g_free, G_TYPE_STRING, IN_field_list, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contact_delete (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Delete", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contact_delete_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contact_delete_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contact_delete_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contact_delete_async (DBusGProxy *proxy, org_freesmartphone_PIM_Contact_delete_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Delete", org_freesmartphone_PIM_Contact_delete_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Contact_update (DBusGProxy *proxy, const GHashTable* IN_contact_data, GError **error)

{
  return dbus_g_proxy_call (proxy, "Update", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_contact_data, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Contact_update_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Contact_update_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Contact_update_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Contact_update_async (DBusGProxy *proxy, const GHashTable* IN_contact_data, org_freesmartphone_PIM_Contact_update_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Update", org_freesmartphone_PIM_Contact_update_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_contact_data, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Contact */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_ContactQuery
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_ContactQuery

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_get_result_count (DBusGProxy *proxy, gint* OUT_count, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResultCount", error, G_TYPE_INVALID, G_TYPE_INT, OUT_count, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_get_result_count_reply) (DBusGProxy *proxy, gint OUT_count, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_get_result_count_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_count;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_count, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_get_result_count_reply)data->cb) (proxy, OUT_count, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_get_result_count_async (DBusGProxy *proxy, org_freesmartphone_PIM_ContactQuery_get_result_count_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResultCount", org_freesmartphone_PIM_ContactQuery_get_result_count_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_rewind (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Rewind", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_rewind_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_rewind_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_rewind_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_rewind_async (DBusGProxy *proxy, org_freesmartphone_PIM_ContactQuery_rewind_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Rewind", org_freesmartphone_PIM_ContactQuery_rewind_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_skip (DBusGProxy *proxy, const gint IN_count, GError **error)

{
  return dbus_g_proxy_call (proxy, "Skip", error, G_TYPE_INT, IN_count, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_skip_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_skip_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_skip_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_skip_async (DBusGProxy *proxy, const gint IN_count, org_freesmartphone_PIM_ContactQuery_skip_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Skip", org_freesmartphone_PIM_ContactQuery_skip_async_callback, stuff, g_free, G_TYPE_INT, IN_count, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_get_contact_path (DBusGProxy *proxy, char ** OUT_contact_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetContactPath", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_contact_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_get_contact_path_reply) (DBusGProxy *proxy, char * OUT_contact_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_get_contact_path_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_contact_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_contact_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_get_contact_path_reply)data->cb) (proxy, OUT_contact_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_get_contact_path_async (DBusGProxy *proxy, org_freesmartphone_PIM_ContactQuery_get_contact_path_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetContactPath", org_freesmartphone_PIM_ContactQuery_get_contact_path_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_get_result (DBusGProxy *proxy, GHashTable** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResult", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_get_result_reply) (DBusGProxy *proxy, GHashTable *OUT_result, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_get_result_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_result, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_get_result_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_get_result_async (DBusGProxy *proxy, org_freesmartphone_PIM_ContactQuery_get_result_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResult", org_freesmartphone_PIM_ContactQuery_get_result_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_get_multiple_results (DBusGProxy *proxy, const gint IN_count, GPtrArray** OUT_resultset, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMultipleResults", error, G_TYPE_INT, IN_count, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE)), OUT_resultset, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_get_multiple_results_reply) (DBusGProxy *proxy, GPtrArray *OUT_resultset, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_get_multiple_results_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_resultset;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE)), &OUT_resultset, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_get_multiple_results_reply)data->cb) (proxy, OUT_resultset, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_get_multiple_results_async (DBusGProxy *proxy, const gint IN_count, org_freesmartphone_PIM_ContactQuery_get_multiple_results_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMultipleResults", org_freesmartphone_PIM_ContactQuery_get_multiple_results_async_callback, stuff, g_free, G_TYPE_INT, IN_count, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_ContactQuery_dispose (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Dispose", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_ContactQuery_dispose_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_ContactQuery_dispose_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_ContactQuery_dispose_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_ContactQuery_dispose_async (DBusGProxy *proxy, org_freesmartphone_PIM_ContactQuery_dispose_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Dispose", org_freesmartphone_PIM_ContactQuery_dispose_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_ContactQuery */

G_END_DECLS
