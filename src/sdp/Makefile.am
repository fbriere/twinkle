INCLUDES = -I $(top_builddir)/src -I $(includedir)

AM_YFLAGS = -p yysdp -d
AM_LFLAGS = -Pyysdp -olex.yy.c -is

noinst_LIBRARIES = libsdpparser.a

libsdpparser_a_SOURCES =\
        sdp.cpp\
        sdp_parse_ctrl.cpp\
	sdp_parser.yxx\
	sdp_scanner.lxx\
        sdp.h\
        sdp_parse_ctrl.h
