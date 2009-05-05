/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Messages
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Messages

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Messages_add (DBusGProxy *proxy, const GHashTable* IN_message_data, char ** OUT_message_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "Add", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_message_data, G_TYPE_INVALID, G_TYPE_STRING, OUT_message_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Messages_add_reply) (DBusGProxy *proxy, char * OUT_message_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Messages_add_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_message_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_message_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Messages_add_reply)data->cb) (proxy, OUT_message_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Messages_add_async (DBusGProxy *proxy, const GHashTable* IN_message_data, org_freesmartphone_PIM_Messages_add_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Add", org_freesmartphone_PIM_Messages_add_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_message_data, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Messages_get_single_message_single_field (DBusGProxy *proxy, const GHashTable* IN_query, const char * IN_field, char ** OUT_value, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetSingleMessageSingleField", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_STRING, IN_field, G_TYPE_INVALID, G_TYPE_STRING, OUT_value, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Messages_get_single_message_single_field_reply) (DBusGProxy *proxy, char * OUT_value, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Messages_get_single_message_single_field_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_value;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_value, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Messages_get_single_message_single_field_reply)data->cb) (proxy, OUT_value, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Messages_get_single_message_single_field_async (DBusGProxy *proxy, const GHashTable* IN_query, const char * IN_field, org_freesmartphone_PIM_Messages_get_single_message_single_field_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetSingleMessageSingleField", org_freesmartphone_PIM_Messages_get_single_message_single_field_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_STRING, IN_field, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Messages_query (DBusGProxy *proxy, const GHashTable* IN_query, char ** OUT_query_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "Query", error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_INVALID, G_TYPE_STRING, OUT_query_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Messages_query_reply) (DBusGProxy *proxy, char * OUT_query_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Messages_query_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_query_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_query_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Messages_query_reply)data->cb) (proxy, OUT_query_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Messages_query_async (DBusGProxy *proxy, const GHashTable* IN_query, org_freesmartphone_PIM_Messages_query_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Query", org_freesmartphone_PIM_Messages_query_async_callback, stuff, g_free, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), IN_query, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Messages_get_folder_names (DBusGProxy *proxy, char *** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetFolderNames", error, G_TYPE_INVALID, G_TYPE_STRV, OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Messages_get_folder_names_reply) (DBusGProxy *proxy, char * *OUT_result, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Messages_get_folder_names_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_result, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Messages_get_folder_names_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Messages_get_folder_names_async (DBusGProxy *proxy, org_freesmartphone_PIM_Messages_get_folder_names_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetFolderNames", org_freesmartphone_PIM_Messages_get_folder_names_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Messages_get_folder_path_from_name (DBusGProxy *proxy, const char * IN_name, char ** OUT_folder_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetFolderPathFromName", error, G_TYPE_STRING, IN_name, G_TYPE_INVALID, G_TYPE_STRING, OUT_folder_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Messages_get_folder_path_from_name_reply) (DBusGProxy *proxy, char * OUT_folder_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Messages_get_folder_path_from_name_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_folder_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_folder_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Messages_get_folder_path_from_name_reply)data->cb) (proxy, OUT_folder_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Messages_get_folder_path_from_name_async (DBusGProxy *proxy, const char * IN_name, org_freesmartphone_PIM_Messages_get_folder_path_from_name_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetFolderPathFromName", org_freesmartphone_PIM_Messages_get_folder_path_from_name_async_callback, stuff, g_free, G_TYPE_STRING, IN_name, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Messages */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Message
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Message

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Message_get_content (DBusGProxy *proxy, GHashTable** OUT_content, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetContent", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_content, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Message_get_content_reply) (DBusGProxy *proxy, GHashTable *OUT_content, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Message_get_content_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_content;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_content, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Message_get_content_reply)data->cb) (proxy, OUT_content, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Message_get_content_async (DBusGProxy *proxy, org_freesmartphone_PIM_Message_get_content_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetContent", org_freesmartphone_PIM_Message_get_content_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Message_get_multiple_fields (DBusGProxy *proxy, const char * IN_fields, GHashTable** OUT_field_data, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMultipleFields", error, G_TYPE_STRING, IN_fields, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_field_data, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Message_get_multiple_fields_reply) (DBusGProxy *proxy, GHashTable *OUT_field_data, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Message_get_multiple_fields_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_field_data;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_field_data, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Message_get_multiple_fields_reply)data->cb) (proxy, OUT_field_data, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Message_get_multiple_fields_async (DBusGProxy *proxy, const char * IN_fields, org_freesmartphone_PIM_Message_get_multiple_fields_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMultipleFields", org_freesmartphone_PIM_Message_get_multiple_fields_async_callback, stuff, g_free, G_TYPE_STRING, IN_fields, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_Message_move_to_folder (DBusGProxy *proxy, const char * IN_folder, GError **error)

{
  return dbus_g_proxy_call (proxy, "MoveToFolder", error, G_TYPE_STRING, IN_folder, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_Message_move_to_folder_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_Message_move_to_folder_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_Message_move_to_folder_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_Message_move_to_folder_async (DBusGProxy *proxy, const char * IN_folder, org_freesmartphone_PIM_Message_move_to_folder_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "MoveToFolder", org_freesmartphone_PIM_Message_move_to_folder_async_callback, stuff, g_free, G_TYPE_STRING, IN_folder, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_Message */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageQuery
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageQuery

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_get_result_count (DBusGProxy *proxy, gint* OUT_count, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResultCount", error, G_TYPE_INVALID, G_TYPE_INT, OUT_count, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_get_result_count_reply) (DBusGProxy *proxy, gint OUT_count, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_get_result_count_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_count;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_count, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_get_result_count_reply)data->cb) (proxy, OUT_count, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_get_result_count_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageQuery_get_result_count_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResultCount", org_freesmartphone_PIM_MessageQuery_get_result_count_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_rewind (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Rewind", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_rewind_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_rewind_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_rewind_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_rewind_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageQuery_rewind_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Rewind", org_freesmartphone_PIM_MessageQuery_rewind_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_skip (DBusGProxy *proxy, const gint IN_count, GError **error)

{
  return dbus_g_proxy_call (proxy, "Skip", error, G_TYPE_INT, IN_count, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_skip_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_skip_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_skip_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_skip_async (DBusGProxy *proxy, const gint IN_count, org_freesmartphone_PIM_MessageQuery_skip_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Skip", org_freesmartphone_PIM_MessageQuery_skip_async_callback, stuff, g_free, G_TYPE_INT, IN_count, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_get_message_path (DBusGProxy *proxy, char ** OUT_message_path, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMessagePath", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_message_path, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_get_message_path_reply) (DBusGProxy *proxy, char * OUT_message_path, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_get_message_path_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char * OUT_message_path;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_message_path, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_get_message_path_reply)data->cb) (proxy, OUT_message_path, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_get_message_path_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageQuery_get_message_path_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMessagePath", org_freesmartphone_PIM_MessageQuery_get_message_path_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_get_result (DBusGProxy *proxy, GHashTable** OUT_result, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetResult", error, G_TYPE_INVALID, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), OUT_result, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_get_result_reply) (DBusGProxy *proxy, GHashTable *OUT_result, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_get_result_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GHashTable* OUT_result;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE), &OUT_result, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_get_result_reply)data->cb) (proxy, OUT_result, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_get_result_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageQuery_get_result_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetResult", org_freesmartphone_PIM_MessageQuery_get_result_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_get_multiple_results (DBusGProxy *proxy, const gint IN_count, GPtrArray** OUT_results, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMultipleResults", error, G_TYPE_INT, IN_count, G_TYPE_INVALID, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE)), OUT_results, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_get_multiple_results_reply) (DBusGProxy *proxy, GPtrArray *OUT_results, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_get_multiple_results_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  GPtrArray* OUT_results;
  dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_map ("GHashTable", G_TYPE_STRING, G_TYPE_VALUE)), &OUT_results, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_get_multiple_results_reply)data->cb) (proxy, OUT_results, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_get_multiple_results_async (DBusGProxy *proxy, const gint IN_count, org_freesmartphone_PIM_MessageQuery_get_multiple_results_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMultipleResults", org_freesmartphone_PIM_MessageQuery_get_multiple_results_async_callback, stuff, g_free, G_TYPE_INT, IN_count, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageQuery_dispose (DBusGProxy *proxy, GError **error)

{
  return dbus_g_proxy_call (proxy, "Dispose", error, G_TYPE_INVALID, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageQuery_dispose_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageQuery_dispose_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageQuery_dispose_reply)data->cb) (proxy, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageQuery_dispose_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageQuery_dispose_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "Dispose", org_freesmartphone_PIM_MessageQuery_dispose_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageQuery */

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageFolder
#define DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageFolder

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageFolder_get_message_count (DBusGProxy *proxy, gint* OUT_count, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMessageCount", error, G_TYPE_INVALID, G_TYPE_INT, OUT_count, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageFolder_get_message_count_reply) (DBusGProxy *proxy, gint OUT_count, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageFolder_get_message_count_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_count;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_count, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageFolder_get_message_count_reply)data->cb) (proxy, OUT_count, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageFolder_get_message_count_async (DBusGProxy *proxy, org_freesmartphone_PIM_MessageFolder_get_message_count_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMessageCount", org_freesmartphone_PIM_MessageFolder_get_message_count_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freesmartphone_PIM_MessageFolder_get_message_paths (DBusGProxy *proxy, const gint IN_first, const gint IN_count, char *** OUT_paths, GError **error)

{
  return dbus_g_proxy_call (proxy, "GetMessagePaths", error, G_TYPE_INT, IN_first, G_TYPE_INT, IN_count, G_TYPE_INVALID, G_TYPE_STRV, OUT_paths, G_TYPE_INVALID);
}

typedef void (*org_freesmartphone_PIM_MessageFolder_get_message_paths_reply) (DBusGProxy *proxy, char * *OUT_paths, GError *error, gpointer userdata);

static void
org_freesmartphone_PIM_MessageFolder_get_message_paths_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  char ** OUT_paths;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_paths, G_TYPE_INVALID);
  (*(org_freesmartphone_PIM_MessageFolder_get_message_paths_reply)data->cb) (proxy, OUT_paths, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freesmartphone_PIM_MessageFolder_get_message_paths_async (DBusGProxy *proxy, const gint IN_first, const gint IN_count, org_freesmartphone_PIM_MessageFolder_get_message_paths_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "GetMessagePaths", org_freesmartphone_PIM_MessageFolder_get_message_paths_async_callback, stuff, g_free, G_TYPE_INT, IN_first, G_TYPE_INT, IN_count, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_org_freesmartphone_PIM_MessageFolder */

G_END_DECLS
