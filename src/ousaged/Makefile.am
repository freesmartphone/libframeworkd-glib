AM_CPPFLAGS = -DDATADIR=\"$(datadir)\" -DPKGDATADIR=\"$(pkgdatadir)\"
AM_CFLAGS = -Wall @DIALER_CFLAGS@
AM_LDFLAGS = @DIALER_LIBS@


lib_LTLIBRARIES = libframeworkd-glib-ousaged.la

libframeworkd_glib_ousaged_la_SOURCES = frameworkd-glib-ousaged-dbus.c frameworkd-glib-ousaged-dbus.h \
  frameworkd-glib-ousaged.c frameworkd-glib-ousaged.h

libframeworkd_glib_HEADERS = frameworkd-glib-ousaged-dbus.h \
                             frameworkd-glib-ousaged.h

libframeworkd_glibdir = $(includedir)/frameworkd-glib/ousaged
