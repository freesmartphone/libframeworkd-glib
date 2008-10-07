AM_CPPFLAGS = -DDATADIR=\"$(datadir)\" -DPKGDATADIR=\"$(pkgdatadir)\"
AM_CFLAGS = -Wall @DIALER_CFLAGS@

AM_LDFLAGS = @DIALER_LIBS@

lib_LTLIBRARIES = libframeworkd-glib-ogsmd.la

libframeworkd_glib_ogsmd_la_SOURCES = \
	frameworkd-glib-ogsmd-dbus.c frameworkd-glib-ogsmd-dbus.h \
  frameworkd-glib-ogsmd-sim.c frameworkd-glib-ogsmd-sim.h \
  frameworkd-glib-ogsmd-network.c frameworkd-glib-ogsmd-network.h \
  frameworkd-glib-ogsmd-call.c frameworkd-glib-ogsmd-call.h \
  frameworkd-glib-ogsmd-device.c frameworkd-glib-ogsmd-device.h \
  frameworkd-glib-ogsmd-sms.h frameworkd-glib-ogsmd-sms.c

libframeworkd_glib_HEADERS = frameworkd-glib-ogsmd-dbus.h \
  				  frameworkd-glib-ogsmd-sim.h \
  				  frameworkd-glib-ogsmd-network.h \
				  frameworkd-glib-ogsmd-call.h \
				  frameworkd-glib-ogsmd-device.h \
				  frameworkd-glib-ogsmd-sms.h

libframeworkd_glibdir = $(includedir)/frameworkd-glib/ogsmd
