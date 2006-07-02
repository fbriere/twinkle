TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_off release thread

LIBS	+= ../libtwinkle.a ../parser/libsipparser.a ../sdp/libsdpparser.a ../sockets/libsocket.a ../threads/libthread.a ../audio/libaudio.a ../audio/gsm/libgsm.a ../audio/ilbc/libilbc.a ../audits/libaudits.a ../stun/libstun.a -lresolv -lsndfile -lboost_regex

DEFINES	+= QT_NO_STL

INCLUDEPATH	+= ..

HEADERS	+= gui.h \
	historylistview.h \
	freedesksystray.h \
	twinklesystray.h \
	gui_util.h \
	address_finder.h

SOURCES	+= main.cpp \
	gui.cpp \
	historylistview.cpp \
	freedesksystray.cpp \
	twinklesystray.cpp \
	gui_util.cpp \
	address_finder.cpp

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
	wizardform.ui \
	getaddressform.ui \
	historyform.ui \
	selectuserform.ui \
	numberconversionform.ui

IMAGES	= images/filenew \
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
	images/dtmf-d.png \
	images/twinkle24.png \
	images/exit.png \
	images/kontact_contacts.png \
	images/ok.png \
	images/cancel.png \
	images/1rightarrow.png \
	images/1leftarrow-yellow.png \
	images/editdelete.png \
	images/kcmpci16.png \
	images/kontact_contacts-disabled.png \
	images/sys_auto_ans.png \
	images/sys_auto_ans_dis.png \
	images/sys_busy_estab.png \
	images/sys_busy_estab_dis.png \
	images/sys_busy_trans.png \
	images/sys_busy_trans_dis.png \
	images/sys_dnd.png \
	images/sys_dnd_dis.png \
	images/sys_idle.png \
	images/sys_idle_dis.png \
	images/sys_redir.png \
	images/sys_redir_dis.png \
	images/sys_services.png \
	images/sys_services_dis.png \
	images/sys_hold.png \
	images/sys_hold_dis.png \
	images/sys_mute.png \
	images/sys_mute_dis.png \
	images/network.png \
	images/knotify.png \
	images/fileopen.png \
	images/fileopen-disabled.png \
	images/edit.png \
	images/cf.png \
	images/auto_answer.png \
	images/auto_answer-disabled.png \
	images/cancel-disabled.png \
	images/cf-disabled.png \
	images/missed-disabled.png \
	images/missed.png \
	images/sys_missed.png \
	images/sys_missed_dis.png \
	images/twinkle16-disabled.png \
	images/gear.png \
	images/reg_failed-disabled.png \
	images/reg_failed.png \
	images/no-indication.png \
	images/contexthelp.png \
	images/settings.png \
	images/reg-query.png \
	images/log_small.png \
	images/qt-logo.png \
	images/1leftarrow.png \
	images/1uparrow.png \
	images/1downarrow.png \
	images/kontact_contacts32.png

unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

include( ../../qtccxxincl.pro )
