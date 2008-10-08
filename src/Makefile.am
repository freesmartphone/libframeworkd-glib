SUBDIRS = ogsmd ousaged


AM_CPPFLAGS = -DDATADIR=\"$(datadir)\" -DPKGDATADIR=\"$(pkgdatadir)\"
AM_CFLAGS = -Wall @DIALER_CFLAGS@

AM_LDFLAGS = @DIALER_LIBS@

BUILT_SOURCES= dialer-marshal.c dialer-marshal.h


dialer-marshal.h: dialer-marshal.list
	( @GLIB_GENMARSHAL@ $< --header > dialer-marshal.tmp \
	&& mv dialer-marshal.tmp dialer-marshal.h ) \
	|| ( rm -f dialer-marshal.tmp && exit 1 )

dialer-marshal.c: dialer-marshal.list dialer-marshal.h
	( @GLIB_GENMARSHAL@ $< --body > dialer-marshal.tmp \
	&& mv dialer-marshal.tmp dialer-marshal.c ) \
	|| ( rm -f dialer-marshal.tmp && exit 1 )



lib_LTLIBRARIES = libframeworkd-glib.la

libframeworkd_glib_la_SOURCES = frameworkd-glib-dbus.h frameworkd-glib-dbus.c \
				frameworkd-glib-phonegui.h frameworkd-glib-phonegui.c \
				$(BUILT_SOURCES)

libframeworkd_glib_la_LDFLAGS = $(all_libraries) -version-info 0:0:0 -no-undefined
libframeworkd_glib_la_LIBADD = ogsmd/libframeworkd-glib-ogsmd.la ousaged/libframeworkd-glib-ousaged.la

libframeworkd_glib_HEADERS = frameworkd-glib-dbus.h frameworkd-glib-phonegui.h

libframeworkd_glibdir = $(includedir)/frameworkd-glib/

