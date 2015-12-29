TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_off release thread

LIBS	+= ../libtwinkle.a ../parser/libsipparser.a ../sdp/libsdpparser.a ../sockets/libsocket.a ../threads/libthread.a ../audio/libaudio.a ../audio/gsm/libgsm.a ../audits/libaudits.a ../stun/libstun.a

INCLUDEPATH	+= ..

HEADERS	+= gui.h

SOURCES	+= main.cpp \
	gui.cpp

FORMS	= mphoneform.ui \
	inviteform.ui \
	deregisterform.ui \
	redirectform.ui \
	termcapform.ui \
	dtmfform.ui \
	selectnicform.ui \
	srvredirectform.ui \
	authenticationform.ui \
	userprofileform.ui \
	selectprofileform.ui \
	getprofilenameform.ui \
	transferform.ui \
	syssettingsform.ui \
	logviewform.ui \
	wizardform.ui

IMAGES	= images/filenew \
	images/fileopen \
	images/filesave \
	images/print \
	images/undo \
	images/redo \
	images/editcut \
	images/editcopy \
	images/editpaste \
	images/searchfind \
	images/invite.png \
	images/answer.png \
	images/bye.png \
	images/reject.png \
	images/redirect.png \
	images/hold.png \
	images/dtmf.png \
	images/bye-disabled.png \
	images/redial.png \
	images/redial-disabled.png \
	images/invite-disabled.png \
	images/answer-disabled.png \
	images/reject-disabled.png \
	images/redirect-disabled.png \
	images/hold-disabled.png \
	images/dtmf-disabled.png \
	images/penguin.png \
	images/package_network.png \
	images/kmix.png \
	images/package_system.png \
	images/yast_babelfish.png \
	images/clock.png \
	images/yast_PhoneTTOffhook.png \
	images/penguin_big.png \
	images/password.png \
	images/kcmpci.png \
	images/penguin-small.png \
	images/conf.png \
	images/conf-disabled.png \
	images/mute.png \
	images/mute-disabled.png \
	images/twinkle16.png \
	images/twinkle48.png \
	images/twinkle32.png \
	images/transfer-disabled.png \
	images/transfer.png \
	images/log.png \
	images/dtmf-2.png \
	images/dtmf-3.png \
	images/dtmf-5.png \
	images/dtmf-6.png \
	images/dtmf-7.png \
	images/dtmf-8.png \
	images/dtmf-9.png \
	images/dtmf-4.png \
	images/dtmf-1.png \
	images/dtmf-0.png \
	images/dtmf-star.png \
	images/dtmf-pound.png \
	images/dtmf-a.png \
	images/dtmf-b.png \
	images/dtmf-c.png \
	images/dtmf-d.png

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

include( ../../qtccxxincl.pro )
