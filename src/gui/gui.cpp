/*
    Copyright (C) 2005-2006  Michel de Boer <michelboer@xs4all.nl>
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "twinkle_config.h"

#include <iostream>
#include <cstdlib>
#include <qapplication.h>
#include "gui.h"
#include "line.h"
#include "sys_settings.h"
#include "user.h"
#include "audio/rtp_telephone_event.h"
#include "sockets/interfaces.h"
#include "threads/thread.h"
#include "audits/memman.h"
#include "authenticationform.h"
#include "mphoneform.h"
#include "selectnicform.h"
#include "selectprofileform.h"
#include "twinklesystray.h"
#include "util.h"
#include "address_finder.h"
#include "qcombobox.h"
#include "qhbox.h"
#include "qlabel.h"
#include "qlayout.h"
#include "qlistbox.h"
#include "qmessagebox.h"
#include "qpixmap.h"
#include "qsize.h"
#include "qsizepolicy.h"
#include "qstring.h"
#include "qtextedit.h"
#include "qtoolbar.h"
#include "qtooltip.h"
#include "qvbox.h"

extern string user_host;
extern pthread_t thread_id_main;

// External commands
extern QString callto_destination;
extern QString cli_command;
extern bool cmd_immediate_mode;
extern QString cmd_set_profile;

QString str2html(const QString &s)
{
	QString result(s);
	
	result.replace('&', "&amp;");
	result.replace('<', "&lt;");
	result.replace('>', "&gt;");
	
	return result;
}

void setDisabledIcon(QAction *action, const QString &icon) {
	QIconSet i = action->iconSet();
	i.setPixmap(QPixmap::fromMimeSource(icon), 
		    QIconSet::Automatic, QIconSet::Disabled);
	action->setIconSet(i);
}

void setDisabledIcon(QToolButton *toolButton, const QString &icon) {
	QIconSet i = toolButton->iconSet();
	i.setPixmap(QPixmap::fromMimeSource(icon), 
		    QIconSet::Automatic, QIconSet::Disabled);
	toolButton->setIconSet(i);
}

/////////////////////////////////////////////////
// PRIVATE
/////////////////////////////////////////////////

void t_gui::setLineFields(int line) {
	if (line == 0) {
		fromLabel = mainWindow->from1Label;
		toLabel = mainWindow->to1Label;
		subjectLabel = mainWindow->subject1Label;
		codecLabel = mainWindow->codec1TextLabel;
		photoLabel = mainWindow->photo1Label;
	} else {
		fromLabel = mainWindow->from2Label;
		toLabel = mainWindow->to2Label;
		subjectLabel = mainWindow->subject2Label;
		codecLabel = mainWindow->codec2TextLabel;
		photoLabel = mainWindow->photo2Label;
	}
}

void t_gui::clearLineFields(int line) {
	setLineFields(line);
	fromLabel->clear();
	QToolTip::remove(fromLabel);
	toLabel->clear();
	QToolTip::remove(toLabel);
	subjectLabel->clear();
	QToolTip::remove(subjectLabel);
	codecLabel->clear();
	photoLabel->clear();
	photoLabel->hide();
}

void t_gui::displayTo(const QString &s) {
	toLabel->setText(s);
	toLabel->setCursorPosition(0);
	QToolTip::add(toLabel, s);
}

void t_gui::displayFrom(const QString &s) {
	fromLabel->setText(s);
	fromLabel->setCursorPosition(0);
	QToolTip::add(fromLabel, s);
}

void t_gui::displaySubject(const QString &s) {
	subjectLabel->setText(s);
	subjectLabel->setCursorPosition(0);
	QToolTip::add(subjectLabel, s);
}

void t_gui::displayCodecInfo(int line) {
	setLineFields(line);
	codecLabel->clear();
	
	t_call_info call_info = phone->get_call_info(line);
	
	if (call_info.send_codec == CODEC_NULL && call_info.recv_codec == CODEC_NULL) {
		return;
	}
	
	if (call_info.send_codec == CODEC_NULL) {
		codecLabel->setText(format_codec(call_info.recv_codec).c_str());
		return;
	}
	
	if (call_info.recv_codec == CODEC_NULL) {
		codecLabel->setText(format_codec(call_info.send_codec).c_str());
		return;
	}
	
	if (call_info.send_codec == call_info.recv_codec) {
		codecLabel->setText(format_codec(call_info.send_codec).c_str());
		return;
	}
	
	QString s = format_codec(call_info.send_codec).c_str();
	s.append('/').append(format_codec(call_info.recv_codec).c_str());
	codecLabel->setText(s);
}

void t_gui::displayPhoto(const QImage &photo) {
	if (photo.isNull()) {
		photoLabel->hide();
	} else {
		QPixmap pm;
		pm.convertFromImage(photo.smoothScale(
			photoLabel->width(), photoLabel->height(), QImage::ScaleMin));
		photoLabel->setPixmap(pm);
		photoLabel->show();
	}
}

/////////////////////////////////////////////////
// PROTECTED
/////////////////////////////////////////////////
bool t_gui::do_invite(const string &destination, const string &display, 
			const string &subject, bool immediate)
{
	lock();
	if (mainWindow->callInvite->isEnabled()) {
		if (immediate) {
			t_user *user = phone->ref_user_profile(
				mainWindow->userComboBox->currentText().ascii());
			t_url dst_url(expand_destination(user, destination));
			if (dst_url.is_valid()) {
				mainWindow->do_phoneInvite(user, 
						display.c_str(), dst_url, subject.c_str());
			}
		} else {
			t_url dest_url(destination);
			t_display_url du(dest_url, display);
			mainWindow->phoneInvite(du.encode().c_str(), subject.c_str());
		}
	}
	unlock();
	
	return true;
}

void t_gui::do_redial(void) {
	lock();
	if (mainWindow->callRedial->isEnabled()) {
		mainWindow->phoneRedial();
	}
	unlock();
}

void t_gui::do_answer(void) {
	lock();
	if (mainWindow->callAnswer->isEnabled()) {
		mainWindow->phoneAnswer();
	}
	unlock();
}

void t_gui::do_reject(void) {
	lock();
	if (mainWindow->callReject->isEnabled()) {
		mainWindow->phoneReject();
	}
	unlock();
}

void t_gui::do_redirect(bool show_status, bool type_present, t_cf_type cf_type, 
		bool action_present, bool enable, int num_redirections,
		const list<string> &dest_strlist, bool immediate)
{
	if (show_status) {
		// Show status not supported in GUI
		return;
	}
	
	t_user *user = phone->ref_user_profile(mainWindow->
				userComboBox->currentText().ascii());
	
	list<t_display_url> dest_list;
	for (list<string>::const_iterator i = dest_strlist.begin();
	     i != dest_strlist.end(); i++)
	{
		t_display_url du;
		du.url = expand_destination(user, *i);
		du.display.clear();
		if (!du.is_valid()) return;
		dest_list.push_back(du);
	}
	
	// Enable/disable permanent redirections
	if (type_present) {
		lock();
		if (enable) {
			phone->ref_service(user)->enable_cf(cf_type, dest_list);
		} else {
			phone->ref_service(user)->disable_cf(cf_type);
		}
		mainWindow->updateServicesStatus();
		unlock();
		
		return;
	} else {
		if (action_present) {
			if (!enable) {
				lock();
				phone->ref_service(user)->disable_cf(CF_ALWAYS);
				phone->ref_service(user)->disable_cf(CF_BUSY);
				phone->ref_service(user)->disable_cf(CF_NOANSWER);
				mainWindow->updateServicesStatus();
				unlock();
			}
			
			return;
		}
	}
	
	lock();
	if (mainWindow->callRedirect->isEnabled()) {
		if (immediate) {
			mainWindow->do_phoneRedirect(dest_list);
		} else {
			mainWindow->phoneRedirect(dest_strlist);
		}
	}
	unlock();
	
	return;
}

void t_gui::do_dnd(bool show_status, bool toggle, bool enable) {
	if (show_status) {
		// Show status not supported in GUI
		return;
	}
	
	lock();
	if (phone->ref_users().size() == 1) {
		if (toggle) {
			enable = !mainWindow->serviceDnd->isOn();
		}
		mainWindow->srvDnd(enable);
		mainWindow->serviceDnd->setOn(enable);
	} else {
		t_user *user = phone->ref_user_profile(mainWindow->
				userComboBox->currentText().ascii());
		list<t_user *> l;
		l.push_back(user);
		if (toggle) {
			enable = !phone->ref_service(user)->is_dnd_active();
		}
		
		if (enable) {
			mainWindow->do_srvDnd_enable(l);
		} else {
			mainWindow->do_srvDnd_disable(l);
		}
	}
	unlock();
}

void t_gui::do_auto_answer(bool show_status, bool toggle, bool enable) {
	if (show_status) {
		// Show status not supported in GUI
		return;
	}
	
	lock();
	if (phone->ref_users().size() == 1) {
		if (toggle) {
			enable = !mainWindow->serviceAutoAnswer->isOn();
		}
		mainWindow->srvAutoAnswer(enable);
		mainWindow->serviceAutoAnswer->setOn(enable);
	} else {
		t_user *user = phone->ref_user_profile(mainWindow->
				userComboBox->currentText().ascii());
		list<t_user *> l;
		l.push_back(user);
		if (toggle) {
			enable = !phone->ref_service(user)->
				 is_auto_answer_active();
		}

		if (enable) {
			mainWindow->do_srvAutoAnswer_enable(l);
		} else {
			mainWindow->do_srvAutoAnswer_disable(l);
		}
	}
	unlock();
}

void t_gui::do_bye(void) {
	lock();
	if (mainWindow->callBye->isEnabled()) {
		mainWindow->phoneBye();
	}
	unlock();
}

void t_gui::do_hold(void) {
	lock();
	if (mainWindow->callHold->isEnabled() && !mainWindow->callHold->isOn()) {
		mainWindow->phoneHold(true);
	}
	unlock();
}

void t_gui::do_retrieve(void) {
	lock();
	if (mainWindow->callHold->isEnabled() && mainWindow->callHold->isOn()) {
		mainWindow->phoneHold(false);
	}
	unlock();
}

bool t_gui::do_refer(const string &destination, bool immediate) {
	lock();
	if (mainWindow->callTransfer->isEnabled()) {
		if (immediate) {
			t_display_url du;
			t_user *user = phone->ref_user_profile(mainWindow->
				userComboBox->currentText().ascii());
			du.url = expand_destination(user, destination);
			
			if (du.is_valid()) {
				mainWindow->do_phoneTransfer(du);
			}
		} else {
			mainWindow->phoneTransfer(destination);
		}
	}
	unlock();
	
	return true;
}

void t_gui::do_conference(void) {
	lock();
	if (mainWindow->callConference->isEnabled()) {
		mainWindow->phoneConference();
	}
	unlock();
}

void t_gui::do_mute(bool show_status, bool toggle, bool enable) {
	if (show_status) {
		// Show status not supported in GUI
		return;
	}
	
	lock();
	if (mainWindow->callMute->isEnabled()) {
		if (toggle) enable = !phone->is_line_muted(phone->get_active_line());
		mainWindow->phoneMute(enable);
	}
	unlock();
}

void t_gui::do_dtmf(const string &digits) {
	lock();
	if (mainWindow->callDTMF->isEnabled()) {
		mainWindow->sendDTMF(digits.c_str());
	}
	unlock();
}

void t_gui::do_register(bool reg_all_profiles) {
	lock();
	list<t_user *> l;
	
	if (reg_all_profiles) {
		l = phone->ref_users();
	} else {
		t_user *user = phone->ref_user_profile(mainWindow->
			userComboBox->currentText().ascii());
		l.push_back(user);
	}
	
	mainWindow->do_phoneRegister(l);
	unlock();
}

void t_gui::do_deregister(bool dereg_all_profiles, bool dereg_all_devices) {
	lock();
	list<t_user *> l;
	
	if (dereg_all_profiles) {
		l = phone->ref_users();
	} else {
		t_user *user = phone->ref_user_profile(mainWindow->
			userComboBox->currentText().ascii());
		l.push_back(user);
	}
	
	if (dereg_all_devices) {
		mainWindow->do_phoneDeregisterAll(l);
	} else {
		mainWindow->do_phoneDeregister(l);
	}
	unlock();
}

void t_gui::do_fetch_registrations(void) {
	lock();
	mainWindow->phoneShowRegistrations();
	unlock();
}

bool t_gui::do_options(bool dest_set, const string &destination, bool immediate) {
	lock();
	// In-dialog OPTIONS request
	int line = phone->get_active_line();
	if (phone->get_line_substate(line) == LSSUB_ESTABLISHED) {
		((t_gui *)ui)->action_options();
		return true;
	}
	
	if (immediate) {
		t_user *user = phone->ref_user_profile(mainWindow->
			userComboBox->currentText().ascii());
		t_url dst_url(expand_destination(user, destination));
		
		if (dst_url.is_valid()) {
			mainWindow->do_phoneTermCap(user, dst_url);
		}
	} else {
		mainWindow->phoneTermCap(destination.c_str());
	}
	unlock();
	
	return true;
}

void t_gui::do_line(int line) {
	phone->pub_activate_line(line - 1);
}

void t_gui::do_user(const string &profile_name) {
	lock();
	for (int i = 0; i < mainWindow->userComboBox->count(); i++) {
		if (mainWindow->userComboBox->text(i) == profile_name.c_str()) 
		{
			mainWindow->userComboBox->setCurrentItem(i);
		}
	}
	unlock();
}

void t_gui::do_quit(void) {
	lock();
	mainWindow->fileExit();
	unlock();
}

void t_gui::do_help(const list<t_command_arg> &al) {
	// Nothing to do in GUI mode
	return;
}


/////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////

t_gui::t_gui(t_phone *_phone) : t_userintf(_phone) {
	use_stdout = false;
	lastFileBrowsePath = DIR_HOME;
	mainWindow = new MphoneForm();
#ifdef HAVE_KDE
	sys_tray_popup = NULL;
#endif
	
	for (int i = 0; i < NUM_USER_LINES; i++) {
		QObject::connect(&autoShowTimer[i], SIGNAL(timeout()),
			mainWindow, SLOT(show()));
	}
	
	MEMMAN_NEW(mainWindow);
	qApp->setMainWidget(mainWindow);
}

t_gui::~t_gui() {
	MEMMAN_DELETE(mainWindow);
	delete mainWindow;
}

void t_gui::run(void) {
	// Start asynchronous event processor
	thr_process_events = new t_thread(process_events_main, NULL);
	MEMMAN_NEW(thr_process_events);
	
	QString s;
	list<t_user *> user_list = phone->ref_users();
	
	// Set configuration file name in titlebar
	s = PRODUCT_NAME;
	s.append(" - ").append(user_host.c_str());
	mainWindow->setCaption(s);
	
	// Set user combo box
	mainWindow->updateUserComboBox();
	
	// Display product information
	s = PRODUCT_NAME;
	s.append(' ').append(PRODUCT_VERSION).append(", ");
	s.append(PRODUCT_DATE);
	mainWindow->display(s);
	s = "Copyright (C) 2005-2006  ";
	s.append(PRODUCT_AUTHOR);
	mainWindow->display(s);
	
	// Restore user interface state from previous session
	restore_state();
	
	// Initialize phone functions
	phone->init();
	
	// Set controls in correct status
	mainWindow->updateState();
	mainWindow->updateRegStatus();
	mainWindow->updateServicesStatus();
	mainWindow->updateMissedCallStatus(0);
	mainWindow->updateMenuStatus();
	
	// Clear line field info fields
	clearLineFields(0);
	clearLineFields(1);
	
	// Set width of window to width of tool bar
	int widthToolBar = mainWindow->callToolbar->width();
	QSize sizeMainWin = mainWindow->size();
	sizeMainWin.setWidth(widthToolBar);
	mainWindow->resize(sizeMainWin);
	
	// Start QApplication/KApplication
	if (sys_config->get_start_hidden()) {
		mainWindow->hide();
	} else {
		mainWindow->show();
	}
	
	// Activate a profile is the --set-profile option was given on the command
	// line.
	if (!cmd_set_profile.isEmpty()) {
		cmd_cli(string("user ") + cmd_set_profile.ascii(), true);
	}
	
	// Execute the call command if a callto destination was specified on the
	// command line
	if (!callto_destination.isEmpty()) {
		cmd_call(callto_destination.ascii(), cmd_immediate_mode);
	}
	
	// Execute a CLI command if one was given on the command line
	if (!cli_command.isEmpty()) {
		cmd_cli(cli_command.ascii(), cmd_immediate_mode);
	}
	
	// Start Qt application
	qApp->exec();
	
	// Terminate phone functions
	phone->terminate();
	
	// Make user interface state persistent
	save_state();
}

void t_gui::save_state(void) {
	lock();
	
	sys_config->set_last_used_profile(
			mainWindow->userComboBox->currentText().ascii());

	list<string> history;
	for (int i = 0; i < mainWindow->callComboBox->count(); i++) {
		history.push_back(mainWindow->callComboBox->text(i).ascii());
	}
	sys_config->set_dial_history(history);
	
	t_userintf::save_state();
	
	unlock();
}

void t_gui::restore_state(void) {
	lock();
	
	// The last used profile is selected when the userComboBox is
	// filled by MphoneForm::updateUserComboBox
	
	mainWindow->callComboBox->clear();
	list<string> dial_history = sys_config->get_dial_history();
	for (list<string>::reverse_iterator i = dial_history.rbegin(); i != dial_history.rend(); i++)
	{
		mainWindow->addToCallComboBox(i->c_str());
	}
	
	t_userintf::restore_state();
	
	unlock();
}

void t_gui::lock(void) {
	// To synchronize actions on the Qt widget the application lock
	// is used. The main thread running the Qt event loop takes the
	// application lock itself already. So take the lock if this is not the
	// main thread.
	t_userintf::lock();
	if (!t_thread::is_self(thread_id_main)) {
		qApp->lock();
	}
}

void t_gui::unlock(void) {
	t_userintf::lock();
	if (!t_thread::is_self(thread_id_main)) {
		qApp->unlock();
	}
}

string t_gui::select_network_intf(void) {
	string ip;
	list<t_interface> *l = get_interfaces();
	// The socket routines are not under control of MEMMAN so report
	// the allocation here.
	MEMMAN_NEW(l);
	if (l->size() == 0) {
		cb_show_msg("Cannot find a network interface. Twinkle will use "
			    "127.0.0.1 as the local IP address. When you connect to "
			    "the network you have to restart Twinkle to use the correct "
			    "IP address.",
			    MSG_WARNING);
		
		MEMMAN_DELETE(l);
		delete l;
		return "127.0.0.1";
	}
	
	if (l->size() == 1) {
		// There is only 1 interface
		ip = l->front().get_ip_addr();
	} else {
		// There are multiple interfaces
		SelectNicForm *sf = new SelectNicForm(NULL, "nic", true);
		MEMMAN_NEW(sf);
		QString item;
		for (list<t_interface>::iterator i = l->begin(); i != l->end(); i++) {
			item = i->name.c_str();
			item.append(':').append(i->get_ip_addr().c_str());
			sf->nicListBox->insertItem(
					QPixmap::fromMimeSource("kcmpci16.png"), 
					item);
		}
		
		sf->nicListBox->setCurrentItem(0);
		sf->exec();
		
		int selection = sf->nicListBox->currentItem();
		int num = 0;
		for (list<t_interface>::iterator i = l->begin(); i != l->end(); i++) {
			if (num == selection) {
				ip = i->get_ip_addr();
				break;
			}
			num++;
		}
		
		MEMMAN_DELETE(sf);
		delete sf;		
	}
	
	MEMMAN_DELETE(l);
	delete l;
	return ip;
}

bool t_gui::select_user_config(list<string> &config_files) {
	SelectProfileForm f(0, "select user profile", true);
	
	if (f.execForm()) {
		config_files = f.selectedProfiles;
		return true;
	}
	
	return false;
}

// GUI call back functions

void t_gui::cb_incoming_call(t_user *user_config, int line, const t_request *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	// Incoming call for to-header
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tincoming call for ");
	s.append(format_sip_address(user_config, r->hdr_to.display, r->hdr_to.uri).c_str());
	mainWindow->display(s);
	
	// Is this a transferred call?
	if (r->hdr_referred_by.is_populated()) {
		s = "\tCall transferred by ";
		s.append(format_sip_address(user_config, 
					    r->hdr_referred_by.display, 
					    r->hdr_referred_by.uri).c_str());
		mainWindow->display(s);
	}
	
	// From
	QString fromParty = format_sip_address(user_config,
				r->hdr_from.get_display_presentation(), r->hdr_from.uri).c_str();
	s = fromParty;
	QString organization("");
	if (r->hdr_organization.is_populated()) {
		organization = r->hdr_organization.name.c_str();
		s.append(", ").append(organization);
	}
	displayFrom(s);
	
	// Display photo
	QImage fromPhoto;
	
	if (sys_config->get_ab_lookup_photo()) {
		t_address_finder *af = t_address_finder::get_instance();
		fromPhoto = af->find_photo(user_config, r->hdr_from.uri);
	}
	
	displayPhoto(fromPhoto);
	
	// To
	s = "";
	s.append(format_sip_address(user_config, r->hdr_to.display, r->hdr_to.uri).c_str());
	displayTo(s);
	
	// Subject
	QString subject("");
	if (r->hdr_subject.is_populated()) {
		subject = r->hdr_subject.subject.c_str();
	}
	displaySubject(subject);
	
	cb_notify_call(line, fromParty, organization, fromPhoto, subject);
	
	unlock();
}

void t_gui::cb_call_cancelled(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfar end cancelled call.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_far_end_hung_up(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfar end released call.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_answer_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_sdp_answer_not_supported(int line, const string &reason) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tSDP answer from far end not supported.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(reason.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_sdp_answer_missing(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tSDP answer from far end missing.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_unsupported_content_type(int line, const t_sip_message *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tUnsupported content type in answer from far end.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(r->hdr_content_type.media.type.c_str());
	s.append("/").append(r->hdr_content_type.media.type.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_ack_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tno ACK received, call will be terminated.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_100rel_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tno PRACK received, call will be terminated.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_prack_failed(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tPRACK failed.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_call_notification(line);
	
	unlock();
}

void t_gui::cb_provisional_resp_invite(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->updateState();
	
	unlock();
}

void t_gui::cb_cancel_failed(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfailed to cancel call.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_call_answered(t_user *user_config, int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfar end answered call.");
	mainWindow->display(s);
	
	// Put far-end party in line to-field
	s = "";
	s.append(format_sip_address(user_config, r->hdr_to.display, r->hdr_to.uri).c_str());
	if (r->hdr_organization.is_populated()) {
		s.append(", ").append(r->hdr_organization.name.c_str());
	}
	displayTo(s);
	
	unlock();
}

void t_gui::cb_call_failed(t_user *user_config, int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall failed.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	// Warnings
	if (r->hdr_warning.is_populated()) {
		list<string> l = format_warnings(r->hdr_warning);
		for (list<string>::iterator i = l.begin(); i != l.end(); i++) {
			s = "\t";
			s.append(i->c_str());
			mainWindow->display(s);
		}
	}
	
	// Redirect response
	if (r->get_class() == R_3XX && r->hdr_contact.is_populated()) {
		list<t_contact_param> l = r->hdr_contact.contact_list;
		l.sort();
		mainWindow->display("\tThe call can be redirected to:");
		for (list<t_contact_param>::iterator i = l.begin();
		i != l.end(); i++)
		{
			s = "\t";
			s.append(format_sip_address(user_config,
					i->display, i->uri).c_str());
			mainWindow->display(s);
		}
	}
	
	// Unsupported extensions
	if (r->code == R_420_BAD_EXTENSION) {
		s = "\t";
		s.append(r->hdr_unsupported.encode().c_str());
		mainWindow->display(s);
	}
	
	clearLineFields(line);
	unlock();
}

void t_gui::cb_stun_failed_call_ended(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall failed.");
	mainWindow->display(s);
	
	clearLineFields(line);
	unlock();
}

void t_gui::cb_call_ended(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall released.");
	mainWindow->display(s);
	
	clearLineFields(line);
	unlock();
}

void t_gui::cb_call_established(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall established.");
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_options_response(const t_response *r) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Response on terminal capability request: ";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	if (r->code == R_408_REQUEST_TIMEOUT) {
		// The request timed out, so no capabilities are known.
		unlock();
		return;
	}
	
	s = "Terminal capabilities of ";
	s.append(r->hdr_to.uri.encode().c_str());
	mainWindow->display(s);
	
	s = "Accepted body types:\t";
	if (r->hdr_accept.is_populated()) {
		s.append(r->hdr_accept.get_value().c_str());
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	s = "Accepted encodings:\t";
	if (r->hdr_accept_encoding.is_populated()) {
		s.append(r->hdr_accept_encoding.get_value().c_str());
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	s = "Accepted languages:\t";
	if (r->hdr_accept_language.is_populated()) {
		s.append(r->hdr_accept_language.get_value().c_str());
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	s = "Allowed requests:\t\t";
	if (r->hdr_allow.is_populated()) {
		s.append(r->hdr_allow.get_value().c_str());
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	s = "Supported extensions:\t";
	if (r->hdr_supported.is_populated()) {
		if (r->hdr_supported.features.empty()) {
			s.append("none");
		} else {
			s.append(r->hdr_supported.get_value().c_str());
		}
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	s = "End point type:\t\t";
	if (r->hdr_server.is_populated()) {
		s.append(r->hdr_server.get_value().c_str());
	} else if (r->hdr_user_agent.is_populated()) {
		// Some end-points put a User-Agent header in the response
		// instead of a Server header.
		s.append(r->hdr_user_agent.get_value().c_str());
	} else {
		s.append("unknown");
	}
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_reinvite_success(int line, const t_response *r) {
	// Do not bother GUI user.
	return;
}

void t_gui::cb_reinvite_failed(int line, const t_response *r) {
	// Do not bother GUI user.
	return;
}

void t_gui::cb_retrieve_failed(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall retrieve failed.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	unlock();
}


void  t_gui::cb_invalid_reg_resp(t_user *user_config, const t_response *r, const string &reason) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s= user_config->get_profile_name().c_str();
	s.append(", registration failed: ");
	s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	mainWindow->display(reason.c_str());
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_register_success(t_user *user_config, const t_response *r, unsigned long expires,
				bool first_success) 
{
	lock();
	QString s;
	
	if (first_success) {
		mainWindow->displayHeader();
		s = user_config->get_profile_name().c_str();
		s += ", registration succeeded (expires = ";
		s += QString().setNum(expires);
		s += " seconds)";
		mainWindow->display(s);
	}
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_register_failed(t_user *user_config, const t_response *r, bool first_failure) {
	lock();
	QString s;
	
	if (first_failure) {
		mainWindow->displayHeader();
		s = user_config->get_profile_name().c_str();
		s += ", registration failed: ";
		s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
		mainWindow->display(s);
	}
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_register_stun_failed(t_user *user_config, bool first_failure) {
	lock();
	QString s;
	
	if (first_failure) {
		mainWindow->displayHeader();
		s = user_config->get_profile_name().c_str();
		s += ", registration failed: STUN failure";
		mainWindow->display(s);
	}
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_deregister_success(t_user *user_config, const t_response *r) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = user_config->get_profile_name().c_str();
	s += ", de-registration succeeded: ";
	s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_deregister_failed(t_user *user_config, const t_response *r) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = user_config->get_profile_name().c_str();
	s = ", de-registration failed: ";
	s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	mainWindow->updateRegStatus();
	unlock();
}

void t_gui::cb_fetch_reg_failed(t_user *user_config, const t_response *r) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = user_config->get_profile_name().c_str();
	s = ", fetching registrations failed: ";
	s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_fetch_reg_result(t_user *user_config, const t_response *r) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	
	s = user_config->get_profile_name().c_str();
	const list<t_contact_param> &l = r->hdr_contact.contact_list;
	if (l.size() == 0) {
		s += ": you are not registered";
		mainWindow->display(s);
	} else {
		s += ": you have the following registrations";
		mainWindow->display(s);
		for (list<t_contact_param>::const_iterator i = l.begin();
		i != l.end(); i++)
		{
			mainWindow->display(i->encode().c_str());
		}
	}
	
	unlock();
}

void t_gui::cb_register_inprog(t_user *user_config, t_register_type register_type) {
	QString s;
	
	lock();
	
	switch(register_type) {
	case REG_REGISTER:
		// Do not report registration refreshments
		if (phone->get_is_registered(user_config)) break;
		mainWindow->statRegLabel->setPixmap(
				QPixmap::fromMimeSource("gear.png"));
		break;
	case REG_DEREGISTER:
	case REG_DEREGISTER_ALL:
		mainWindow->statRegLabel->setPixmap(
				QPixmap::fromMimeSource("gear.png"));
		break;
	case REG_QUERY:
		mainWindow->displayHeader();
		s = user_config->get_profile_name().c_str();
		s += ": fetching registrations...";
		mainWindow->display(s);
		break;
	}
	
	unlock();
}

void t_gui::cb_redirecting_request(t_user *user_config, int line, const t_contact_param &contact) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tredirecting request to");
	mainWindow->display(s);
	
	s = "\t";
	s.append(format_sip_address(user_config, contact.display, contact.uri).c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_redirecting_request(t_user *user_config, const t_contact_param &contact) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Redirecting request to: ";
	s.append(format_sip_address(user_config, contact.display, contact.uri).c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_notify_call(int line, const QString &from_party, const QString &organization,
			   const QImage &photo, const QString &subject)
{
	if (line >= NUM_USER_LINES) return;
	
	lock();
	
	// Play ringtone if the call is received on the active line.
	if (line == phone->get_active_line() &&
	    !phone->is_line_auto_answered(line))
	{
		cb_play_ringtone(line);
	}
	
	// Pop up sys tray balloon
#ifdef HAVE_KDE
	t_twinkle_sys_tray *tray = mainWindow->getSysTray();
	if (tray && !sys_tray_popup) {
		QString presFromParty("");
		if (!from_party.isEmpty()) {
			presFromParty = dotted_truncate(from_party.ascii(), 40).c_str();
		}
		QString presOrganization("");
		if (!organization.isEmpty()) {
			presOrganization = dotted_truncate(organization.ascii(), 40).c_str();
		}
		QString presSubject("");
		if (!subject.isEmpty()) {
			presSubject = dotted_truncate(subject.ascii(), 40).c_str();
		}
		
		// Create photo pixmap. If no photo is available, then use
		// the Twinkle icon.
		QPixmap pm;
		QFrame::Shape photoFrameShape = QFrame::NoFrame;
		if (photo.isNull()) {
			pm = QPixmap::fromMimeSource("twinkle32.png");
		} else {
			pm.convertFromImage(photo);
			photoFrameShape = QFrame::Box;
		}
		
		// Create the popup view.
		sys_tray_popup = new KPassivePopup(tray);
		MEMMAN_NEW(sys_tray_popup);
		sys_tray_popup->setAutoDelete(false);
		sys_tray_popup->setTimeout(0);
		QVBox *popup_view = new QVBox(sys_tray_popup);
		QHBox *hb = new QHBox(popup_view);
		hb->setSpacing(5);
		QLabel *lblPhoto = new QLabel(hb);
		lblPhoto->setPixmap(pm);
		lblPhoto->setFrameShape(photoFrameShape);
		QVBox *vb = new QVBox(hb);
		QLabel *lblCaption = new QLabel("<H2>Incoming Call</H2>", vb);
		lblCaption->setAlignment(Qt::AlignTop | Qt::AlignLeft);
		lblCaption->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
		QLabel *lblFrom = new QLabel(presFromParty, vb);
		lblFrom->setAlignment(Qt::AlignTop | Qt::AlignLeft);
		lblFrom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
		QLabel *lastLabel = lblFrom;
		if (!presOrganization.isEmpty()) {
			QLabel *lblOrganization = new QLabel(presOrganization, vb);
			lblOrganization->setAlignment(Qt::AlignTop | Qt::AlignLeft);
			lblOrganization->setSizePolicy(QSizePolicy::Expanding, 
						       QSizePolicy::Minimum);
			lastLabel = lblOrganization;
		}
		if (!presSubject.isEmpty()) {
			QLabel *lblSubject = new QLabel(presSubject, vb);
			lblSubject->setAlignment(Qt::AlignTop | Qt::AlignLeft);
			lblSubject->setSizePolicy(QSizePolicy::Expanding, 
						       QSizePolicy::Minimum);
			lastLabel = lblSubject;
		}
		lastLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		sys_tray_popup->setView(popup_view);
		
		// Show the popup
		line_sys_tray_popup = line;
		sys_tray_popup->show();
		QObject::connect(sys_tray_popup, SIGNAL(clicked()),
			sys_tray_popup, SLOT(hide()));
	}
#endif
	
	// Show main window after a few seconds
	if (sys_config->get_gui_auto_show_incoming()) {
		autoShowTimer[line].start(
			sys_config->get_gui_auto_show_timeout() * 1000, true);
	}
	
	unlock();
}

void t_gui::cb_stop_call_notification(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	cb_stop_tone(line);
	autoShowTimer[line].stop();
	
#ifdef HAVE_KDE
	if (sys_tray_popup && line_sys_tray_popup == line) {
		sys_tray_popup->hide();
		MEMMAN_DELETE(sys_tray_popup);
		delete sys_tray_popup;
		sys_tray_popup = NULL;
	}
#endif
	unlock();
}

void t_gui::cb_dtmf_detected(int line, char dtmf_event) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tDTMF telephone event detected: ");
	
	if (VALID_DTMF_EV(dtmf_event)) {
		s.append(dtmf_ev2char(dtmf_event));
	} else {
		s.append("invalid DTMF telephone event (");
		s.append(QString().setNum((int)dtmf_event));
	}
	
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_send_dtmf(int line, char dtmf_event) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	if (!VALID_DTMF_EV(dtmf_event)) return;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tsend DTMF ");
	s.append(dtmf_ev2char(dtmf_event));
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_dtmf_not_supported(int line) {
	if (line >= NUM_USER_LINES) return;
	
	QString s;
	
	if (throttle_dtmf_not_supported) return;
	
	lock();
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tfar end does not support DTMF telephone events.");
	mainWindow->display(s);
	
	// Throttle subsequent call backs
	throttle_dtmf_not_supported = true;
	
	unlock();
}

void t_gui::cb_dtmf_supported(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	mainWindow->updateState();
	unlock();
}

void t_gui::cb_line_state_changed(void) {
	lock();
	mainWindow->updateState();
	unlock();
}

void t_gui::cb_send_codec_changed(int line, t_audio_codec codec) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	displayCodecInfo(line);
	unlock();
}

void t_gui::cb_recv_codec_changed(int line, t_audio_codec codec) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	displayCodecInfo(line);
	unlock();
}

void t_gui::cb_notify_recvd(int line, const t_request *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\treceived notification.");
	mainWindow->display(s);
	
	s = "\tEvent: ";
	s.append(r->hdr_event.event_type.c_str());
	mainWindow->display(s);
	
	s = "\tState: ";
	s.append(r->hdr_subscription_state.substate.c_str());
	mainWindow->display(s);
	
	if (r->hdr_subscription_state.substate == SUBSTATE_TERMINATED) {
		s = "\tReason: ";
		s.append(r->hdr_subscription_state.reason.c_str());
		mainWindow->display(s);
	}
	
	t_response *sipfrag = (t_response *)((t_sip_body_sipfrag *)r->body)->sipfrag;
	s = "\tProgress: ";
	s.append(QString().setNum(sipfrag->code));
	s.append(' ').append(sipfrag->reason.c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_refer_failed(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall transfer failed.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	// The refer state has changed, so update the main window.
	mainWindow->updateState();
	
	unlock();
}

void t_gui::cb_refer_result_success(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall succesfully transferred.");
	mainWindow->display(s);
	
	// The refer state has changed, so update the main window.
	mainWindow->updateState();
	
	unlock();
}

void t_gui::cb_refer_result_failed(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall transfer failed.");
	mainWindow->display(s);
	
	// The refer state has changed, so update the main window.
	mainWindow->updateState();
	
	unlock();
}

void t_gui::cb_refer_result_inprog(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall transfer still in progress.");
	mainWindow->display(s);
	
	s = "\tNo further notifications will be received.";
	mainWindow->display(s);
	
	// The refer state has changed, so update the main window.
	mainWindow->updateState();
	
	unlock();
}

void t_gui::cb_call_referred(t_user *user_config, int line, t_request *r) {
	if (line >= NUM_USER_LINES) return;
	
	QString s;
	
	lock();
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\ttransferring call to ");
	s.append(format_sip_address(user_config,
			r->hdr_refer_to.display, r->hdr_refer_to.uri).c_str());
	mainWindow->display(s);
	
	if (r->hdr_referred_by.is_populated()) {
		s = "\tTransfer requested by ";
		s.append(format_sip_address(user_config,
					    r->hdr_referred_by.display, 
					    r->hdr_referred_by.uri).c_str());
		mainWindow->display(s);
	}
	
	setLineFields(line);
	s = format_sip_address(user_config, 
			       user_config->get_display(),  user_config->create_user_uri()).c_str();
	displayFrom(s);
	photoLabel->hide();
	
	s = format_sip_address(user_config,
			       r->hdr_refer_to.display, r->hdr_refer_to.uri).c_str();
	displayTo(s);
	
	subjectLabel->clear();
	codecLabel->clear();
	
	unlock();
}

void t_gui::cb_retrieve_referrer(t_user *user_config, int line) {
	if (line >= NUM_USER_LINES) return;
	
	QString s;
	
	lock();
	
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tCall transfer failed. Retrieving original call.");
	mainWindow->display(s);
	
	setLineFields(line);
	const t_call_info call_info = phone->get_call_info(line);
	
	s = format_sip_address(user_config, call_info.get_from_display_presentation(), 
			       call_info.from_uri).c_str();
	if (!call_info.from_organization.empty()) {
		s += ", ";
		s += call_info.from_organization.c_str();
	}
	displayFrom(s);
	
	// Display photo
	QImage fromPhoto;
	
	if (sys_config->get_ab_lookup_photo()) {
		t_address_finder *af = t_address_finder::get_instance();
		fromPhoto = af->find_photo(user_config, call_info.from_uri);
	}
	
	displayPhoto(fromPhoto);
	
	s = format_sip_address(user_config, call_info.to_display, call_info.to_uri).c_str();
	if (!call_info.to_organization.empty()) {
		s += ", ";
		s += call_info.to_organization.c_str();
	}
	displayTo(s);
	
	displaySubject(call_info.subject.c_str());
	codecLabel->clear();
	
	unlock();
}

void t_gui::cb_stun_failed(int err_code, const string &err_reason) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "STUN request failed: ";
	s.append(QString().setNum(err_code)).append(' ').append(err_reason.c_str());
	mainWindow->display(s);

	unlock();
}

void t_gui::cb_stun_failed(void) {
	lock();
	QString s;
	
	mainWindow->displayHeader();
	s = "STUN request failed.";
	mainWindow->display(s);

	unlock();
}

bool t_gui::cb_ask_user_to_redirect_invite(t_user *user_config, const t_url &destination,
					   const string &display)
{
	QString s;
	QString title;
	
	lock();
	
	title = PRODUCT_NAME;
	title.append(" - Redirecting call");
	
	s = "User profile: <b>";
	s.append(user_config->get_profile_name().c_str());
	s.append("</b><br>User: <b>");
	s.append(str2html(user_config->get_display_uri().c_str()));
	s.append("</b><br><br>");
	
	s.append("Do you allow the call to be redirected to the following destination?<br><br>");
	s.append(str2html(ui->format_sip_address(user_config, display, destination).c_str()));
	s.append("<br><br>If you don't want to be asked this anymore, then you must change "
		 "the settings in the SIP protocol section of the user profile.");
	QMessageBox *mb = new QMessageBox(title, s,
					  QMessageBox::Warning,
					  QMessageBox::Yes,
					  QMessageBox::No,
					  QMessageBox::NoButton,
					  mainWindow);
	MEMMAN_NEW(mb);
	bool permission = (mb->exec() == QMessageBox::Yes);
	MEMMAN_DELETE(mb);
	delete mb;
	
	unlock();
	
	return permission;
}

bool t_gui::cb_ask_user_to_redirect_request(t_user *user_config,
					    const t_url &destination,
					    const string &display, t_method method)
{
	QString s;
	QString title;
	
	lock();
	
	title = PRODUCT_NAME;
	title.append(" - Redirecting request");
	
	s = "User profile: <b>";
	s.append(user_config->get_profile_name().c_str());
	s.append("</b><br>User: <b>");
	s.append(str2html(user_config->get_display_uri().c_str()));
	s.append("</b><br><br>");
	
	s.append("Do you allow the ");
	s.append(method2str(method).c_str());
	s.append(" request to be redirected to the following destination?<br><br>");
	s.append(str2html(ui->format_sip_address(user_config, display, destination).c_str()));
	s.append("<br><br>If you don't want to be asked this anymore, then you must change "
		 "the settings in the SIP protocol section of the user profile.");
	QMessageBox *mb = new QMessageBox(title, s,
					  QMessageBox::Warning,
					  QMessageBox::Yes,
					  QMessageBox::No,
					  QMessageBox::NoButton,
					  mainWindow);
	MEMMAN_NEW(mb);
	bool permission = (mb->exec() == QMessageBox::Yes);
	MEMMAN_DELETE(mb);
	delete mb;
	
	unlock();
	
	return permission;
}

bool t_gui::cb_ask_credentials(t_user *user_config, const string &realm, string &username,
			       string &password)
{
	QString user(username.c_str());
	QString passwd(password.c_str());
	
	lock();
	
	AuthenticationForm *af = new AuthenticationForm(mainWindow, "authentication",
							true);
	MEMMAN_NEW(af);
	if (!af->exec(user_config, QString(realm.c_str()), user, passwd)) {
		MEMMAN_DELETE(af);
		delete af;
		unlock();
		return false;
	}
	
	username = user.ascii();
	password = passwd.ascii();
	MEMMAN_DELETE(af);
	delete af;
	
	unlock();
	return true;
}

bool t_gui::cb_ask_user_to_refer(t_user *user_config, const t_url &refer_to_uri,
				 const string &refer_to_display,
				 const t_url &referred_by_uri,
				 const string &referred_by_display)
{
	QString s;
	QString title;
	
	lock();
	
	title = PRODUCT_NAME;
	title.append(" - Transferring call");
	
	s = "User profile: <b>";
	s.append(user_config->get_profile_name().c_str());
	s.append("</b><br>User: <b>");
	s.append(str2html(user_config->get_display_uri().c_str()));
	s.append("</b><br><br>");
	
	if (referred_by_uri.is_valid()) {
		s.append("Request to transfer call received from:<br>");
		s.append(str2html(format_sip_address(user_config, referred_by_display,
					    referred_by_uri).c_str()));
		s.append("<br>");
	} else {
		s.append("Request to transfer call received.<br>");
	}
	s.append("<br>");
	
	s.append("Do you allow the call to be transferred to the following destination?<br><br>");
	s.append(str2html(ui->format_sip_address(user_config, refer_to_display, 
					refer_to_uri).c_str()));
	s.append("<br><br>If you don't want to be asked this anymore, then you must change "
		 "the settings in the SIP protocol section of the user profile.");
	QMessageBox *mb = new QMessageBox(title, s,
					  QMessageBox::Warning,
					  QMessageBox::Yes,
					  QMessageBox::No,
					  QMessageBox::NoButton,
					  mainWindow);
	MEMMAN_NEW(mb);
	bool permission = (mb->exec() == QMessageBox::Yes);
	MEMMAN_DELETE(mb);
	delete mb;
	
	unlock();
	
	return permission;
}

void t_gui::cb_show_msg(const string &msg, t_msg_priority prio) {
	cb_show_msg(NULL, msg, prio);
}

void t_gui::cb_show_msg(QWidget *parent, const string &msg, t_msg_priority prio) {
	lock();
	
	switch (prio) {
	case MSG_INFO:
		QMessageBox::information(parent, PRODUCT_NAME, msg.c_str());
		break;
	case MSG_WARNING:
		QMessageBox::warning(parent, PRODUCT_NAME, msg.c_str());
		break;
	case MSG_CRITICAL:
	default:
		QMessageBox::critical(parent, PRODUCT_NAME, msg.c_str());
		break;
	}
	
	unlock();
}

void t_gui::cb_display_msg(const string &msg, t_msg_priority prio) {
	QString s;
	
	lock();
	
	switch (prio) {
	case MSG_INFO:
		s = "Info: ";
		break;
	case MSG_WARNING:
		s = "Warning: ";
		break;
	case MSG_CRITICAL:
	default:
		s = "Critical: ";
		break;
	}	
	
	s.append(msg.c_str());
	mainWindow->displayHeader();
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_log_updated(bool log_zapped) {
	lock();
	mainWindow->updateLog(log_zapped);
	unlock();
}

void t_gui::cb_call_history_updated(void) {
	lock();
	mainWindow->updateCallHistory();
	unlock();
}

void  t_gui::cb_missed_call(int num_missed_calls) {
	lock();
	mainWindow->updateMissedCallStatus(num_missed_calls);
	unlock();
}

void t_gui::cb_nat_discovery_progress_start(int num_steps) {
	natDiscoveryProgressDialog = new QProgressDialog(
			"Firewall / NAT discovery...", "Abort", num_steps, NULL,
			"nat discovery progress", true);
	MEMMAN_NEW(natDiscoveryProgressDialog);
	natDiscoveryProgressDialog->setCaption(PRODUCT_NAME);
	natDiscoveryProgressDialog->setMinimumDuration(200);
}

void t_gui::cb_nat_discovery_progress_step(int step) {
	natDiscoveryProgressDialog->setProgress(step);
	qApp->processEvents();
}

void t_gui::cb_nat_discovery_finished(void) {
	MEMMAN_DELETE(natDiscoveryProgressDialog);
	delete natDiscoveryProgressDialog;
}

bool t_gui::cb_nat_discovery_cancelled(void) {
	return natDiscoveryProgressDialog->wasCancelled();
}

void t_gui::cmd_call(const string &destination, bool immediate) {
	string subject;
	string dst_no_headers;
	t_display_url du;
	
	t_user *user = phone->ref_user_profile(
			mainWindow->userComboBox->currentText().ascii());
	expand_destination(user, destination, du, subject, dst_no_headers);
	if (!du.is_valid()) return;
	
	lock();
	if (immediate) {
		mainWindow->do_phoneInvite(user, du.display.c_str(), du.url, 
					   subject.c_str());
	} else {
		mainWindow->phoneInvite(dst_no_headers.c_str(), subject.c_str());
	}
	unlock();
}

void t_gui::cmd_quit(void) {
	lock();
	mainWindow->fileExit();
	unlock();
}

string t_gui::get_name_from_abook(t_user *user_config, const t_url &u) {
	lock();
	t_address_finder *af = t_address_finder::get_instance();
	string name = af->find_name(user_config, u);
	unlock();
	
	return name;
}

// User invoked actions on the phone object

void t_gui::action_register(list<t_user *> user_list) {
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		phone->pub_registration(*i, REG_REGISTER, 
			DUR_REGISTRATION(*i));
	}
}

void t_gui::action_deregister(list<t_user *> user_list, bool dereg_all) {
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (dereg_all) {
			phone->pub_registration(*i, REG_DEREGISTER_ALL);
		} else {
			phone->pub_registration(*i, REG_DEREGISTER);
		}
	}
}

void t_gui::action_show_registrations(list<t_user *> user_list) {
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		phone->pub_registration(*i, REG_QUERY);
	}
}

void t_gui::action_invite(t_user *user_config, const t_url &destination,
			  const string &display, const string &subject) 
{
	QString s;
	
	// Store call info for redial
	last_called_url = destination;
	last_called_display = display;
	last_called_subject = subject;
	last_called_profile = user_config->get_profile_name();
	
	// Call can only be made if line is idle
	int line = phone->get_active_line();
	if (phone->get_line_state(line) == LS_BUSY) return;
	
	setLineFields(line);
	
	// Set party and subject line fields
	s = "";
	s.append(format_sip_address(user_config, display, destination).c_str());
	displayTo(s);
	
	s = "";
	s.append(format_sip_address(user_config, user_config->get_display(), 
				    user_config->create_user_uri()).c_str());
	displayFrom(s);
	
	displaySubject(subject.c_str());
	
	phone->pub_invite(user_config, destination, display, subject.c_str());
}

void t_gui::action_answer(void) {
	cb_stop_call_notification(phone->get_active_line());
	phone->pub_answer();
}

void t_gui::action_bye(void) {
	phone->pub_end_call();
}

void t_gui::action_reject(void) {
	QString s;
	
	cb_stop_call_notification(phone->get_active_line());
	phone->pub_reject();
	
	int line = phone->get_active_line();
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall rejected.");
	mainWindow->display(s);
	
	clearLineFields(line);
}

void t_gui::action_redirect(const list<t_display_url> &contacts) {
	QString s;
	
	cb_stop_call_notification(phone->get_active_line());
	phone->pub_redirect(contacts, 302);
	
	int line = phone->get_active_line();
	mainWindow->displayHeader();
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall redirected.");
	mainWindow->display(s);
	
	clearLineFields(line);
}

void t_gui::action_refer(const t_url &destination, const string &display) {
	phone->pub_refer(destination, display);
}

void t_gui::action_hold(void) {
	phone->pub_hold();
}

void t_gui::action_retrieve(void) {
	phone->pub_retrieve();
}

void t_gui::action_conference(void) {
	if (!phone->join_3way(0, 1)) {
		mainWindow->display("Failed to start conference.");
	}
}

void t_gui::action_mute(bool on) {
	phone->mute(on);
}

void t_gui::action_options(void) {
	phone->pub_options();
}

void t_gui::action_options(t_user *user_config, const t_url &contact) {
	phone->pub_options(user_config, contact);
}

void t_gui::action_dtmf(const string &digits) {
	const t_call_info call_info = phone->get_call_info(phone->get_active_line());
	throttle_dtmf_not_supported = false;
	
	if (!call_info.dtmf_supported) return;
	
	for (string::const_iterator i = digits.begin(); i != digits.end(); i++) {
		if (VALID_DTMF_SYM(*i)) {
			phone->pub_send_dtmf(*i, call_info.dtmf_inband);
		}
	}
}

void t_gui::action_activate_line(unsigned short line) {
	phone->pub_activate_line(line);
}

bool t_gui::action_seize(void) {
	return phone->pub_seize();
}

void t_gui::action_unseize(void) {
	phone->pub_unseize();
}

void t_gui::srv_dnd(list<t_user *> user_list, bool on) {
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (on) {
			phone->ref_service(*i)->enable_dnd();
		} else {
			phone->ref_service(*i)->disable_dnd();
		}
	}
}

void t_gui::srv_enable_cf(t_user *user_config,
		t_cf_type cf_type, const list<t_display_url> &cf_dest) 
{
	phone->ref_service(user_config)->enable_cf(cf_type, cf_dest);
}

void t_gui::srv_disable_cf(t_user *user_config, t_cf_type cf_type) {
	phone->ref_service(user_config)->disable_cf(cf_type);
}

void t_gui::srv_auto_answer(list<t_user *> user_list, bool on) {
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		phone->ref_service(*i)->enable_auto_answer(on);
	}
}

void t_gui::fill_user_combo(QComboBox *cb) {
	cb->clear();
	
	list<t_user *> user_list = phone->ref_users();
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		// OLD code: used display uri
		// cb->insertItem((*i)->get_display_uri().c_str());
		cb->insertItem((*i)->get_profile_name().c_str());
	}
	
	cb->setCurrentItem(0);
}

QString t_gui::get_last_file_browse_path(void) const {
	return lastFileBrowsePath;
}

void t_gui::set_last_file_browse_path(QString path) {
	lock();
	lastFileBrowsePath = path;
	unlock();
}
