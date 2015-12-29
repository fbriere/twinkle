INCLUDES = -I $(top_builddir)/src -I $(includedir)

noinst_LIBRARIES = libsocket.a

#noinst_PROGRAMS = srvinfo
#srvinfo_SOURCES = srvinfo.cpp
#srvinfo_LDADD = $(top_builddir)/src/util.o\
#	$(top_builddir)/src/sockets/libsocket.a\
#	-lresolv

libsocket_a_SOURCES =\
	dnssrv.cpp\
        interfaces.cpp\
        socket.cpp\
        url.cpp\
        dnssrv.h\
        interfaces.h\
        socket.h\
        url.h
