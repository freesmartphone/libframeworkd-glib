AM_CPPFLAGS = -DDATADIR=\"$(datadir)\" -DPKGDATADIR=\"$(pkgdatadir)\"
AM_CFLAGS = -Wall @DIALER_CFLAGS@

AM_LDFLAGS = @DIALER_LIBS@

BUILT_SOURCES= dialer-marshal.c dialer-marshal.h

lib_LTLIBRARIES = libframeworkd-glib.la

libframeworkd_glib_la_LDFLAGS = $(all_libraries) -version-info 0:0:0 -no-undefined

dialer-marshal.h: dialer-marshal.list
	( @GLIB_GENMARSHAL@ $< --header > dialer-marshal.tmp \
	&& mv dialer-marshal.tmp dialer-marshal.h ) \
	|| ( rm -f dialer-marshal.tmp && exit 1 )

dialer-marshal.c: dialer-marshal.list dialer-marshal.h
	( @GLIB_GENMARSHAL@ $< --body > dialer-marshal.tmp \
	&& mv dialer-marshal.tmp dialer-marshal.c ) \
	|| ( rm -f dialer-marshal.tmp && exit 1 )

libframeworkd_glib_la_SOURCES = \
	frameworkd-glib-dbus.h frameworkd-glib-dbus.c \
	frameworkd-glib-phonegui.h frameworkd-glib-phonegui.c \
	ogsmd/frameworkd-glib-ogsmd-dbus.c ogsmd/frameworkd-glib-ogsmd-dbus.h \
	ogsmd/frameworkd-glib-ogsmd-sim.c ogsmd/frameworkd-glib-ogsmd-sim.h \
	ogsmd/frameworkd-glib-ogsmd-network.c ogsmd/frameworkd-glib-ogsmd-network.h \
	ogsmd/frameworkd-glib-ogsmd-call.c ogsmd/frameworkd-glib-ogsmd-call.h \
	ogsmd/frameworkd-glib-ogsmd-device.c ogsmd/frameworkd-glib-ogsmd-device.h \
	ogsmd/frameworkd-glib-ogsmd-sms.h ogsmd/frameworkd-glib-ogsmd-sms.c \
	ousaged/frameworkd-glib-ousaged-dbus.c ousaged/frameworkd-glib-ousaged-dbus.h \
	ousaged/frameworkd-glib-ousaged.c ousaged/frameworkd-glib-ousaged.h \
	$(BUILT_SOURCES)

libframeworkd_glib_HEADERS = \
	frameworkd-glib-dbus.h frameworkd-glib-phonegui.h \
	ogsmd/frameworkd-glib-ogsmd-dbus.h ogsmd/frameworkd-glib-ogsmd-sim.h \
	ogsmd/frameworkd-glib-ogsmd-network.h ogsmd/frameworkd-glib-ogsmd-call.h \
	ogsmd/frameworkd-glib-ogsmd-device.h ogsmd/frameworkd-glib-ogsmd-sms.h \
	ousaged/frameworkd-glib-ousaged-dbus.h ousaged/frameworkd-glib-ousaged.h

libframeworkd_glibdir = $(includedir)/frameworkd-glib/

