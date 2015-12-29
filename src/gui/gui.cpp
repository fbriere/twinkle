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

#ifdef HAVE_KDE
#include <ksystemtray.h>
#include <kpassivepopup.h>
#endif

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
#include "qcombobox.h"
#include "qlabel.h"
#include "qlistbox.h"
#include "qmessagebox.h"
#include "qpixmap.h"
#include "qstring.h"
#include "qtextedit.h"
#include "qtooltip.h"

extern string user_host;
extern pthread_t thread_id_main;

QString str2html(const QString &s)
{
	QString result(s);
	
	result.replace('&', "&amp;");
	result.replace('<', "&lt;");
	result.replace('>', "&gt;");
	
	return result;
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
	} else {
		fromLabel = mainWindow->from2Label;
		toLabel = mainWindow->to2Label;
		subjectLabel = mainWindow->subject2Label;
		codecLabel = mainWindow->codec2TextLabel;
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

/////////////////////////////////////////////////
// PUBLIC
/////////////////////////////////////////////////

t_gui::t_gui(t_phone *_phone) : t_userintf(_phone) {
	mainWindow = new MphoneForm();
	MEMMAN_NEW(mainWindow);
	qApp->setMainWidget(mainWindow);
}

t_gui::~t_gui() {
	MEMMAN_DELETE(mainWindow);
	delete mainWindow;
}

void t_gui::run(void) {
	QString s;
	list<t_user *> user_list = phone->ref_users();
	
	// Set configuration file name in titlebar
	s = PRODUCT_NAME;
	if (user_list.size() == 1) {
		// Single user
		s.append(" - ").append(user_list.front()->get_profile_name().c_str());
	} else {
		s.append(" - Multiple users");
	}
	mainWindow->setCaption(s);
	
	// Display URI
	mainWindow->displayUser(user_list.front());
	
	// Display local IP address
	mainWindow->ipAddrTextLabel->setText(user_host.c_str());
	
	// Display product information
	s = PRODUCT_NAME;
	s.append(' ').append(PRODUCT_VERSION).append(", ");
	s.append(PRODUCT_DATE);
	mainWindow->display(s);
	s = "Copyright (C) 2005-2006  ";
	s.append(PRODUCT_AUTHOR);
	mainWindow->display(s);
	
	// Automatic registration at startup if requested
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++)
	{
		if ((*i)->register_at_startup) {
			phone->pub_registration(*i, REG_REGISTER, DUR_REGISTRATION(*i));
		}
	}
	
	// Set controls in correct status
	mainWindow->updateState();
	mainWindow->updateRegStatus();
	mainWindow->updateServicesStatus();
	mainWindow->updateMenuStatus();
	
	// Clear line field info fields
	clearLineFields(0);
	clearLineFields(1);
	
	// Start QApplication/KApplication
	if (sys_config->start_hidden) {
		mainWindow->hide();
	} else {
		mainWindow->show();
	}
	qApp->exec();
	
	// Get user list from phone again as it might have changed if the
	// user added and removed users.
	user_list = phone->ref_users();
	
	// Wait till phone is deregistered.
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++)
	{
		while (phone->get_is_registered(*i)) {
			sleep(1);
		}
	}
}

void t_gui::lock(void) {
	// To synchronize actions on the Qt widget the application lock
	// is used. The main thread running the Qt event loop takes the
	// application lock itself already. So take the lock if this is not the
	// main thread.
	if (!t_thread::is_self(thread_id_main)) {
		qApp->lock();
	}
}

void t_gui::unlock(void) {
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
	mainWindow->display("");
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
				r->hdr_from.display, r->hdr_from.uri).c_str();
	s = fromParty;
	if (r->hdr_organization.is_populated()) {
		s.append(", ").append(r->hdr_organization.name.c_str());
	}
	displayFrom(s);
	
	// To
	s = "";
	s.append(format_sip_address(user_config, r->hdr_to.display, r->hdr_to.uri).c_str());
	displayTo(s);
	
	// Subject
	s = "";
	if (r->hdr_subject.is_populated()) {
		s.append(r->hdr_subject.subject.c_str());
	}
	displaySubject(s);
	
	// Play ringtone if the call is received on the active line.
	if (line == phone->get_active_line() &&
	    !phone->ref_service(user_config)->is_auto_answer_active())
	{
		cb_play_ringtone();	
	}
	
	// Pop up sys tray balloon if main window is hidden
	if (mainWindow->isHidden()) {
#ifdef HAVE_KDE
		KSystemTray *tray = (KSystemTray *)mainWindow->getSysTray();
		if (tray) {
			QString s("Incoming call: ");
			s.append(fromParty.left(40));
			if (fromParty.length() > 40) s.append("...");
			KPassivePopup::message(s, tray);
		}
#endif
	}
	
	unlock();
}

void t_gui::cb_call_cancelled(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfar end cancelled call.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_far_end_hung_up(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tfar end released call.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_answer_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_sdp_answer_not_supported(int line, const string &reason) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tSDP answer from far end not supported.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(reason.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_sdp_answer_missing(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tSDP answer from far end missing.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_unsupported_content_type(int line, const t_sip_message *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tUnsupported content type in answer from far end.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(r->hdr_content_type.media.type.c_str());
	s.append("/").append(r->hdr_content_type.media.type.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_ack_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tno ACK received, call will be terminated.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_100rel_timeout(int line) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tno PRACK received, call will be terminated.");
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
	unlock();
}

void t_gui::cb_prack_failed(int line, const t_response *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	setLineFields(line);
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tPRACK failed.");
	mainWindow->display(s);
	
	s = "\t";
	s.append(QString().setNum(r->code));
	s.append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	clearLineFields(line);
	cb_stop_tone(line);
	
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall established.");
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_options_response(const t_response *r) {
	lock();
	QString s;
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
		mainWindow->display("");
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
		mainWindow->display("");
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
		mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
	s = user_config->get_profile_name().c_str();
	s = ", fetching registrations failed: ";
	s.append(QString().setNum(r->code)).append(' ').append(r->reason.c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_fetch_reg_result(t_user *user_config, const t_response *r) {
	lock();
	QString s;
	
	mainWindow->display("");
	
	s = user_config->get_profile_name().c_str();
	const list<t_contact_param> &l = r->hdr_contact.contact_list;
	if (l.size() == 0) {
		s += ": you are nor registered";
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
		mainWindow->regStatusTextLabel->setText("Registering...");
		break;
	case REG_DEREGISTER:
	case REG_DEREGISTER_ALL:
		mainWindow->regStatusTextLabel->setText("Deregistering...");
		break;
	case REG_QUERY:
		mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
	s = "Redirecting request to: ";
	s.append(format_sip_address(user_config, contact.display, contact.uri).c_str());
	mainWindow->display(s);
	
	unlock();
}

void t_gui::cb_dtmf_detected(int line, char dtmf_event) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->display("");
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

void t_gui::cb_dtmf_not_supported(int line) {
	if (line >= NUM_USER_LINES) return;
	
	QString s;
	
	if (throttle_dtmf_not_supported) return;
	
	lock();
	
	mainWindow->display("");
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
	
	displayCodecInfo(line);
}

void t_gui::cb_recv_codec_changed(int line, t_audio_codec codec) {
	if (line >= NUM_USER_LINES) return;
	
	displayCodecInfo(line);
}

void t_gui::cb_notify_recvd(int line, const t_request *r) {
	if (line >= NUM_USER_LINES) return;
	
	lock();
	QString s;
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
	
	mainWindow->display("");
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
			       user_config->display,  user_config->create_user_uri()).c_str();
	displayFrom(s);
	
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
	
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1));
	s.append(":\tCall transfer failed. Retrieving original call.");
	mainWindow->display(s);
	
	setLineFields(line);
	const t_call_info call_info = phone->get_call_info(line);
	
	s = format_sip_address(user_config, call_info.from_display, call_info.from_uri).c_str();
	if (!call_info.from_organization.empty()) {
		s += ", ";
		s += call_info.from_organization.c_str();
	}
	displayFrom(s);
	
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
	
	mainWindow->display("");
	s = "STUN request failed: ";
	s.append(QString().setNum(err_code)).append(' ').append(err_reason.c_str());
	mainWindow->display(s);

	unlock();
}

void t_gui::cb_stun_failed(void) {
	lock();
	QString s;
	
	mainWindow->display("");
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
	QString user, passwd;
	
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

void t_gui::cb_nat_discovery_progress_start(int num_steps) {
	natDiscoveryProgressDialog = new QProgressDialog(
			"Firewall / NAT discovery...", "Abort", num_steps, NULL,
			"nat discovery progress", true, Qt::WDestructiveClose);
	natDiscoveryProgressDialog->setCaption(PRODUCT_NAME);
	natDiscoveryProgressDialog->setMinimumDuration(200);
}

void t_gui::cb_nat_discovery_progress_step(int step) {
	natDiscoveryProgressDialog->setProgress(step);
	qApp->processEvents();
}

bool t_gui::cb_nat_discovery_cancelled(void) {
	return natDiscoveryProgressDialog->wasCancelled();
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
	s.append(format_sip_address(user_config, user_config->display, 
				    user_config->create_user_uri()).c_str());
	displayFrom(s);
	
	displaySubject(subject.c_str());
	
	phone->pub_invite(user_config, destination, display, subject.c_str());
}

void t_gui::action_answer(void) {
	cb_stop_tone(phone->get_active_line());
	phone->pub_answer();
}

void t_gui::action_bye(void) {
	phone->pub_end_call();
}

void t_gui::action_reject(void) {
	QString s;
	
	cb_stop_tone(phone->get_active_line());
	phone->pub_reject();
	
	int line = phone->get_active_line();
	mainWindow->display("");
	s = "Line ";
	s.append(QString().setNum(line + 1)).append(":\tcall rejected.");
	mainWindow->display(s);
	
	clearLineFields(line);
}

void t_gui::action_redirect(const list<t_display_url> &contacts) {
	QString s;
	
	cb_stop_tone(phone->get_active_line());
	phone->pub_redirect(contacts, 302);
	
	int line = phone->get_active_line();
	mainWindow->display("");
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
	throttle_dtmf_not_supported = false;
	
	for (string::const_iterator i = digits.begin(); i != digits.end(); i++) {
		if (VALID_DTMF_SYM(*i)) {
			phone->pub_send_dtmf(*i);
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
		cb->insertItem((*i)->get_display_uri().c_str());
	}
	cb->setCurrentItem(0);
}
