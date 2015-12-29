INCLUDES = -I $(top_builddir)/src -I $(includedir)

noinst_LIBRARIES = libaudio.a

libaudio_a_SOURCES =\
        audio_codecs.cpp\
        audio_rx.cpp\
        audio_session.cpp\
        audio_tx.cpp\
        g711.cpp\
        g721.cpp\
        g723_24.cpp\
        g723_40.cpp\
        g72x.cpp\
        media_buffer.cpp\
        rtp_telephone_event.cpp\
        tone_gen.cpp\
        audio_codecs.h\
        audio_rx.h\
        audio_session.h\
        audio_tx.h\
        g711.h\
        g72x.h\
        media_buffer.h\
        rtp_telephone_event.h\
        tone_gen.h

SUBDIRS = gsm

EXTRA_DIST = README_G711
