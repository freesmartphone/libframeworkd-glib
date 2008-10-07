
#ifndef __g_cclosure_user_marshal_MARSHAL_H__
#define __g_cclosure_user_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:INT,STRING,BOXED (dialer-marshal.list:1) */
extern void g_cclosure_user_marshal_VOID__INT_STRING_BOXED (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* VOID:UINT,BOOLEAN,STRING (dialer-marshal.list:2) */
extern void g_cclosure_user_marshal_VOID__UINT_BOOLEAN_STRING (GClosure     *closure,
                                                               GValue       *return_value,
                                                               guint         n_param_values,
                                                               const GValue *param_values,
                                                               gpointer      invocation_hint,
                                                               gpointer      marshal_data);

/* VOID:INT (dialer-marshal.list:3) */
#define g_cclosure_user_marshal_VOID__INT	g_cclosure_marshal_VOID__INT

G_END_DECLS

#endif /* __g_cclosure_user_marshal_MARSHAL_H__ */

