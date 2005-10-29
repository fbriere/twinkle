INCLUDES = -I $(includedir)

AM_LDFLAGS = -L $(libdir)

AM_CPPFLAGS = -DDATADIR=\"$(pkgdatadir)\"

noinst_PROGRAMS = twinkle

noinst_LIBRARIES = libtwinkle.a

twinkle_SOURCES = main.cpp

twinkle_LDADD = libtwinkle.a\
	$(top_builddir)/src/parser/libsipparser.a\
        $(top_builddir)/src/sdp/libsdpparser.a\
        $(top_builddir)/src/sockets/libsocket.a\
        $(top_builddir)/src/threads/libthread.a\
        $(top_builddir)/src/audio/libaudio.a\
        $(top_builddir)/src/audio/gsm/libgsm.a\
        $(top_builddir)/src/audits/libaudits.a\
        $(top_builddir)/src/stun/libstun.a\
	$(CCRTP_LIBS)

libtwinkle_a_SOURCES =\
        auth.cpp\
        dialog.cpp\
        events.cpp\
        line.cpp\
        listener.cpp\
        log.cpp\
        phone.cpp\
        redirect.cpp\
        sender.cpp\
        service.cpp\
        session.cpp\
	sub_refer.cpp\
	subscription.cpp\
        sys_settings.cpp\
        timekeeper.cpp\
        transaction.cpp\
        transaction_layer.cpp\
        transaction_mgr.cpp\
        user.cpp\
        userintf.cpp\
        util.cpp\
        auth.h\
        dialog.h\
        events.h\
	exceptions.h\
        line.h\
        listener.h\
        log.h\
        phone.h\
	protocol.h\
        redirect.h\
        sender.h\
        service.h\
        session.h\
	sub_refer.h\
	subscription.h\
        sys_settings.h\
        timekeeper.h\
        transaction.h\
        transaction_layer.h\
        transaction_mgr.h\
        user.h\
        userintf.h\
        util.h

SUBDIRS = audio audits parser sdp sockets stun threads . gui
