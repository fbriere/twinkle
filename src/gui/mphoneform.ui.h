/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, pres:erving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
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
#include <kpopupmenu.h>

#define KSYSTRAY ((KSystemTray *)sysTray)

#endif

void MphoneForm::init()
{
	dtmfForm = 0;
	inviteForm = 0;
	redirectForm = 0;
	transferForm = 0;
	termCapForm = 0;
	srvRedirectForm = 0;
	userProfileForm = 0;
	sysSettingsForm = 0;
	logViewForm = 0;
	historyForm = 0;
	selectUserForm = 0;
	selectProfileForm = 0;
	sysTray = 0;
	
	// Set toolbar icons for disabled options.
	QIconSet i;
	i = callInvite->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("invite-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callInvite->setIconSet(i);
	
	i = callAnswer->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("answer-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callAnswer->setIconSet(i);
	
	i = callBye->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("bye-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callBye->setIconSet(i);
	
	i = callReject->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("reject-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callReject->setIconSet(i);
	
	i = callRedirect->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("redirect-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callRedirect->setIconSet(i);
	
	i = callTransfer->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("transfer-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callTransfer->setIconSet(i);
	
	i = callHold->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("hold-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callHold->setIconSet(i);
	
	i = callConference->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("conf-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callConference->setIconSet(i);
	
	i = callMute->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("mute-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callMute->setIconSet(i);
	
	i = callDTMF->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("dtmf-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callDTMF->setIconSet(i);
	
	i = callRedial->iconSet();
	i.setPixmap(QPixmap::fromMimeSource("redial-disabled.png"), 
		    QIconSet::Automatic, QIconSet::Disabled);
	callRedial->setIconSet(i);
	
	// Some text labels on the main window are implemented as QLineEdit
	// objects as these do not automatically resize when a text set with setText
	// does not fit. The background of a QLineEdit is static however, it does not
	// automatically take a background color passed by the -bg parameter.
	// Set the background color of these QLineEdit objects here.
	userTextLabel->setPaletteBackgroundColor(paletteBackgroundColor());
	from1Label->setPaletteBackgroundColor(paletteBackgroundColor());
	to1Label->setPaletteBackgroundColor(paletteBackgroundColor());
	subject1Label->setPaletteBackgroundColor(paletteBackgroundColor());
	from2Label->setPaletteBackgroundColor(paletteBackgroundColor());
	to2Label->setPaletteBackgroundColor(paletteBackgroundColor());
	subject2Label->setPaletteBackgroundColor(paletteBackgroundColor());
	
	if (sys_config->gui_use_systray) {
#ifdef HAVE_KDE
		// Create system tray icon
		sysTray = new KSystemTray(this, "twinkle_sys_tray");
		MEMMAN_NEW(sysTray);
		KSYSTRAY->setPixmap(
				QPixmap::fromMimeSource("sys_idle_dis.png"));
		KSYSTRAY->setCaption(PRODUCT_NAME);
		QToolTip::add(sysTray, PRODUCT_NAME);
		
		// Add items to the system tray menu
		KPopupMenu *menu = KSYSTRAY->contextMenu();
		
		// Call menu
		callInvite->addTo(menu);
		callAnswer->addTo(menu);
		callBye->addTo(menu);
		callReject->addTo(menu);
		callRedirect->addTo(menu);
		callTransfer->addTo(menu);
		callHold->addTo(menu);
		callMute->addTo(menu);
		callDTMF->addTo(menu);
		callRedial->addTo(menu);
		
		menu->insertSeparator();
		
		// Service menu
		serviceDnd->addTo(menu);
		serviceRedirection->addTo(menu);
		serviceAutoAnswer->addTo(menu);
		
		menu->insertSeparator();
		
		// View menu
		viewCall_HistoryAction->addTo(menu);
		
		// Exit application when user selects Quit from the tray menu
		connect(KSYSTRAY, SIGNAL(quitSelected()),
			this, SLOT(fileExit()));
		
		KSYSTRAY->show();
#endif
	}
}

void MphoneForm::destroy()
{
	if (dtmfForm) {
		MEMMAN_DELETE(dtmfForm);
		delete dtmfForm;
	}
	if (inviteForm) {
		MEMMAN_DELETE(inviteForm);
		delete inviteForm;
	}
	if (redirectForm) {
		MEMMAN_DELETE(redirectForm);
		delete redirectForm;
	}
	if (termCapForm) {
		MEMMAN_DELETE(termCapForm);
		delete termCapForm;
	}
	if (srvRedirectForm) {
		MEMMAN_DELETE(srvRedirectForm);
		delete srvRedirectForm;
	}
	if (userProfileForm) {
		MEMMAN_DELETE(userProfileForm);
		delete userProfileForm;
	}
	if (transferForm) {
		MEMMAN_DELETE(transferForm);
		delete transferForm;
	}
	if (sysSettingsForm) {
		MEMMAN_DELETE(sysSettingsForm);
		delete sysSettingsForm;
	}
	if (logViewForm) {
		if (logViewForm->isShown()) logViewForm->close();
		MEMMAN_DELETE(logViewForm);
		delete logViewForm;
	}
	if (historyForm) {
		if (historyForm->isShown()) historyForm->close();
		MEMMAN_DELETE(historyForm);
		delete historyForm;
	}
	if (selectUserForm) {
		MEMMAN_DELETE(selectUserForm);
		delete selectUserForm;
	}
	if (selectProfileForm) {
		MEMMAN_DELETE(selectProfileForm);
		delete selectProfileForm;
	}
	if (sysTray) {
		MEMMAN_DELETE(sysTray);
		delete sysTray;
	}
}

QString MphoneForm::lineSubstate2str( int line) {
	QString reason;
	
	t_call_info call_info = phone->get_call_info(line);
	
	switch(phone->get_line_substate(line)) {
	case LSSUB_IDLE:	
		return "idle";
	case LSSUB_SEIZED:
		return "dialing";
	case LSSUB_OUTGOING_PROGRESS:
		reason = call_info.last_provisional_reason.c_str();
		if (reason == "") {
			return "attempting call, please wait";
		}
		return reason;
	case LSSUB_INCOMING_PROGRESS:
		return "<font color=red>incoming call</font>";
	case LSSUB_ANSWERING:
		return "establishing call, please wait";
	case LSSUB_ESTABLISHED:
		return "established";
	case LSSUB_RELEASING:
		return "releasing call, please wait";
	default:
		return "unknown state";
	}
}

void MphoneForm::closeEvent( QCloseEvent *e )
{
	if (sysTray && sys_config->gui_hide_on_close) {
		hide();
	} else {
		fileExit();
	}
}

void MphoneForm::fileExit()
{
	list<t_user *> user_list = phone->ref_users();
	
	// De-register all registered users.
	display("");
	display("Deregestering phone ...");
	for (list<t_user *>::iterator i = user_list.begin();
	     i != user_list.end(); i++)
	{
		if (phone->get_is_registered(*i)) {
			phone->pub_registration(*i, REG_DEREGISTER);
		}
	}
	
	QApplication::exit(0);
}

// Append a string to the display window
void MphoneForm::display( const QString &s )
{
	displayContents.push_back(s);
	if (displayContents.size() > 100) {
		displayContents.pop_front();
	}
	
	displayTextEdit->setText(displayContents.join("\n"));
	
	// Set cursor position at the end of text
	displayTextEdit->setCursorPosition(displayTextEdit->paragraphs() - 1, 0);
}

// Update line state and enable/disable buttons depending on state
void MphoneForm::updateState()
{
	QString state;
	int line, other_line;
	bool on_hold; // indicates if a line is put on-hold
	bool in_conference; // indicates if a line is in a conference
	bool is_muted; // indicates is a line is muted
	t_refer_state refer_state; // indicates if a call transfer is in progress
	
	// Update status of line 1
	state = lineSubstate2str(0);
	on_hold = phone->is_line_on_hold(0);
	if (on_hold) state.append(", on hold");
	in_conference = phone->part_of_3way(0);
	if (in_conference) state.append(", conference");
	is_muted = phone->is_line_muted(0);
	if (is_muted) state.append(", mute");
	refer_state = phone->get_line_refer_state(0);
	if (refer_state != REFST_NULL) state.append(", transferring");
	status1TextLabel->setText(state);
	
	// Update status of line 2
	state = lineSubstate2str(1);
	on_hold = phone->is_line_on_hold(1);
	if (on_hold) state.append(", on hold");
	in_conference = phone->part_of_3way(1);
	if (in_conference) state.append(", conference");
	is_muted = phone->is_line_muted(1);
	if (is_muted) state.append(", mute");
	refer_state = phone->get_line_refer_state(1);
	if (refer_state != REFST_NULL) state.append(", transferring");
	status2TextLabel->setText(state);
	
	// Disable/enable controls depending on the active line state
	t_line_substate line_substate;
	line = phone->get_active_line();
	line_substate = phone->get_line_substate(line);
	on_hold = phone->is_line_on_hold(line);
	in_conference = phone->part_of_3way(line);
	is_muted = phone->is_line_muted(line);
	refer_state = phone->get_line_refer_state(line);
	other_line = (line == 0 ? 1 : 0);
	t_call_info call_info = phone->get_call_info(line);
	
	// The active line may change when one of the parties in a conference
	// releases the call. If this happens, then update the state of the
	// line radio buttons.
	if (line == 0 && line2RadioButton->isOn()) 
	{
		line1RadioButton->setChecked(true);
	} else if (line == 1 && line1RadioButton->isOn())
	{
		line2RadioButton->setChecked(true);
	}
	
	switch(line_substate) {
	case LSSUB_IDLE:	
		callInvite->setEnabled(true);
		callAnswer->setEnabled(false);
		callBye->setEnabled(false);
		callReject->setEnabled(false);
		callRedirect->setEnabled(false);
		callTransfer->setEnabled(false);
		callHold->setEnabled(false);
		callConference->setEnabled(false);
		callMute->setEnabled(false);
		callDTMF->setEnabled(false);
		callRedial->setEnabled(ui->can_redial());
		break;
	case LSSUB_OUTGOING_PROGRESS:
		callInvite->setEnabled(false);
		callAnswer->setEnabled(false);
		callBye->setEnabled(true);
		callReject->setEnabled(false);
		callRedirect->setEnabled(false);
		callTransfer->setEnabled(false);
		callHold->setEnabled(false);
		callConference->setEnabled(false);
		callMute->setEnabled(false);
		callDTMF->setEnabled(call_info.dtmf_supported);
		callRedial->setEnabled(false);
		break;
	case LSSUB_INCOMING_PROGRESS:
		callInvite->setEnabled(false);
		callAnswer->setEnabled(true);
		callBye->setEnabled(false);
		callReject->setEnabled(true);
		callRedirect->setEnabled(true);
		callTransfer->setEnabled(false);
		callHold->setEnabled(false);
		callConference->setEnabled(false);
		callMute->setEnabled(false);
		callDTMF->setEnabled(call_info.dtmf_supported);
		callRedial->setEnabled(false);
		break;
	case LSSUB_ESTABLISHED:
		callInvite->setEnabled(false);
		callAnswer->setEnabled(false);
		callBye->setEnabled(true);
		callReject->setEnabled(false);
		callRedirect->setEnabled(false);
		
		if (in_conference) {
			callTransfer->setEnabled(false);
			callHold->setEnabled(false);
			callConference->setEnabled(false);
			callDTMF->setEnabled(false);
		} else {
			callTransfer->setEnabled(call_info.refer_supported &&
						 refer_state == REFST_NULL);
			callHold->setEnabled(true);
			callDTMF->setEnabled(call_info.dtmf_supported);
			
			if (phone->get_line_substate(other_line) == 
			    LSSUB_ESTABLISHED)
			{
				// If one of the lines is transferring a call, then a
				// conference cannot be setup.
				if (refer_state != REFST_NULL ||
				    phone->get_line_refer_state(other_line) != REFST_NULL)
				{
					callConference->setEnabled(false);
				} else {
					callConference->setEnabled(true);
				}
			} else {
				callConference->setEnabled(false);
			}
		}
		
		callMute->setEnabled(true);
		callRedial->setEnabled(false);
		break;
	case LSSUB_SEIZED:
	case LSSUB_ANSWERING:
	case LSSUB_RELEASING:
		// During dialing, answering and call release no other actions are 
		// possible
		callInvite->setEnabled(false);
		callAnswer->setEnabled(false);
		callBye->setEnabled(false);
		callReject->setEnabled(false);
		callRedirect->setEnabled(false);
		callTransfer->setEnabled(false);
		callHold->setEnabled(false);
		callConference->setEnabled(false);
		callMute->setEnabled(false);
		callDTMF->setEnabled(false);
		callRedial->setEnabled(false);
		break;
	default:
		callInvite->setEnabled(true);
		callAnswer->setEnabled(true);
		callBye->setEnabled(true);
		callReject->setEnabled(true);
		callRedirect->setEnabled(true);
		callTransfer->setEnabled(true);
		callHold->setEnabled(true);
		callConference->setEnabled(false);
		callMute->setEnabled(true);
		callDTMF->setEnabled(true);
		callRedial->setEnabled(ui->can_redial());
	}
	
	// Set hold action in correct state
	callHold->setOn(on_hold);
	
	// Set mute action in correct state
	callMute->setOn(is_muted);
	
	// Hide redirect form if it is still visible, but not applicable anymore
	if (!callRedirect->isEnabled() && redirectForm && 
	    redirectForm->isVisible()) 
	{
		redirectForm->hide();
	}
	
	// Hide transfer form if it is still visible, but not applicable anymore
	if (!callTransfer->isEnabled() && transferForm && 
	    transferForm->isVisible()) 
	{
		transferForm->hide();
	}
	
	// Hide DTMF form if it is still visible, but not applicable anymore
	if (!callDTMF->isEnabled() && dtmfForm && 
	    dtmfForm->isVisible()) 
	{
		dtmfForm->hide();
	}
	
	// Set last called address in the redial tool tip
	t_url last_url;
	string last_display;
	string last_subject;
	t_user *last_user;
	if (callRedial->isEnabled() && 
	    ui->get_last_call_info(last_url, last_display, last_subject, &last_user))
	{
		QString s = "Call ";
		s.append(ui->format_sip_address(last_user,
					last_display, last_url).c_str());
		callRedial->setToolTip(s);
	} else {
		callRedial->setToolTip("Repeat last call invitation");
	}
	
	updateSysTrayStatus();
}

// Update registration status
void MphoneForm::updateRegStatus()
{
	int num_registered = 0;
	int num_failed = 0;
	QString toolTip;
	
	// Count number of succesful and failed registrations.
	// Determine tool tip showing registration details for all users.
	list<t_user *>user_list = phone->ref_users();
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (phone->get_is_registered(*i)) {
			num_registered++;
			toolTip.append((*i)->get_display_uri().c_str());
			toolTip.append(" - Registered\n");
		} else if (phone->get_last_reg_failed(*i)) {
			num_failed++;
			toolTip.append((*i)->get_display_uri().c_str());
			toolTip.append(" - Failed\n");
		} else {
			toolTip.append((*i)->get_display_uri().c_str());
			toolTip.append(" - Not registered\n");
		}
	}
	
	// Set registration status
	if (num_registered == user_list.size()) {
		regStatusTextLabel->setText("Registered");
	} else if (num_failed == user_list.size()) {
		regStatusTextLabel->setText("<font color=red>Failed</font>");
	} else if (num_registered > 0) {
		regStatusTextLabel->setText("<i>Registered</i>");
	} else if (num_failed > 0) {
		regStatusTextLabel->setText("<i>Failed</i>");	
	} else {
		regStatusTextLabel->setText("Not registered");
	}
	
	// Set tool tip with detailed info for multiple users.
	QToolTip::remove(regStatusTextLabel);
	if (user_list.size() > 1) {
		QToolTip::add(regStatusTextLabel, toolTip);
	}
	
	updateSysTrayStatus();
}

// Update active services status
void MphoneForm::updateServicesStatus()
{	
	int num_dnd = 0;
	int num_cf = 0;
	int num_auto_answer = 0;
	QString tipDnd = "Do not disturb active for:\n";
	QString tipCf = "Redirection active for:\n";
	QString tipAa = "Auto answer active for:\n";
	
	// Calculate number of services active.
	// Determine tool tips with detailed service status for all users.
	list<t_user *>user_list = phone->ref_users();
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (phone->ref_service(*i)->is_dnd_active()) {
			num_dnd++;
			tipDnd.append((*i)->get_display_uri().c_str());
			tipDnd.append("\n");
		}
		if (phone->ref_service(*i)->is_cf_active()) {
			num_cf++;
			tipCf.append((*i)->get_display_uri().c_str());
			tipCf.append("\n");
		}
		if (phone->ref_service(*i)->is_auto_answer_active()) {
			num_auto_answer++;
			tipAa.append((*i)->get_display_uri().c_str());
			tipAa.append("\n");
		}
	}
	
	// Set service status
	dndTextLabel->setEnabled(num_dnd > 0);
	redirectionTextLabel->setEnabled(num_cf > 0);
	autoAnswerTextLabel->setEnabled(num_auto_answer > 0);
	
	// Set font to italic if not all users have a service active.
	// NOTE: all services have the same type of font.
	QFont fontNormal = dndTextLabel->font();
	fontNormal.setItalic(false);
	QFont fontItalic = dndTextLabel->font();
	fontItalic.setItalic(true);
	
	if (num_dnd == user_list.size() || num_dnd == 0) {
		dndTextLabel->setFont(fontNormal);
	} else {
		dndTextLabel->setFont(fontItalic);
	}
	if (num_cf == user_list.size() || num_cf == 0) {
		redirectionTextLabel->setFont(fontNormal);
	} else {
		redirectionTextLabel->setFont(fontItalic);
	}
	if (num_auto_answer == user_list.size() || num_auto_answer == 0) {
		autoAnswerTextLabel->setFont(fontNormal);
	} else {
		autoAnswerTextLabel->setFont(fontItalic);
	}
	
	// Set tool tip with detailed info for multiple users.
	QToolTip::remove(dndTextLabel);
	QToolTip::remove(redirectionTextLabel);
	QToolTip::remove(autoAnswerTextLabel);
	if (user_list.size() > 1) {
		if (num_dnd > 0) QToolTip::add(dndTextLabel, tipDnd);
		if (num_cf > 0) QToolTip::add(redirectionTextLabel, tipCf);
		if (num_auto_answer > 0) QToolTip::add(autoAnswerTextLabel, tipAa);
	}
	
	updateSysTrayStatus();
}

// Update system tray status
void MphoneForm::updateSysTrayStatus()
{
#ifdef HAVE_KDE
	QString icon_name;
	bool cf_active = false;
	bool dnd_active = false;
	bool auto_answer_active = false;
	bool multi_services = false;
	int num_services;
	
	if (!sysTray) return;
	
	// Get status of active line
	int line = phone->get_active_line();
	t_line_substate line_substate = phone->get_line_substate(line);
	
	list<t_user *> user_list = phone->ref_users();
	
	switch(line_substate) {
	case LSSUB_IDLE:
	case LSSUB_SEIZED:
		// If a service is active, then show the service icon
		user_list = phone->ref_users();
		for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
			if (phone->ref_service(*i)->multiple_services_active()) {
				multi_services = true;
				break;
			} else {
				if (phone->ref_service(*i)->is_dnd_active())  {
					dnd_active = true;
				}
				if (phone->ref_service(*i)->is_cf_active()) {
					cf_active = true;
				}
				if (phone->ref_service(*i)->is_auto_answer_active()) {
					auto_answer_active = true;
				}
			}
		}
		
		num_services = (dnd_active ? 1 : 0) + (cf_active ? 1 : 0) + 
			       (auto_answer_active ? 1 : 0);
		
		if (multi_services || num_services > 1) {
			icon_name = "sys_services";
		} else if (dnd_active) {
			icon_name = "sys_dnd";
		} else if (cf_active) {
			icon_name = "sys_redir";
		} else if (auto_answer_active) {
			icon_name = "sys_auto_ans";
		} else {
			// No service is active, show the idle icon
			if (icon_name.isEmpty()) icon_name = "sys_idle";
		}

		break;
	case LSSUB_ESTABLISHED:
		if (phone->is_line_on_hold(line)) {
			icon_name = "sys_hold";
		} else if (phone->is_line_muted(line)) {
			icon_name = "sys_mute";
		} else {
			icon_name = "sys_busy_estab";
		}
		break;
	default:
		// Line is in a busy transient state
		icon_name = "sys_busy_trans";
	}
	
	// Based on the registration status use the active or disabled version
	// of the icon.
	bool registered = false;
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (phone->get_is_registered(*i)) {
			registered = true;
			break;
		}
	}
	
	if (registered) {
		icon_name += ".png";
	} else {
		icon_name += "_dis.png";
	}
	
	KSYSTRAY->setPixmap(QPixmap::fromMimeSource(icon_name));
#endif
}

// Update menu status based on the number of active users
void MphoneForm::updateMenuStatus()
{
	// Some menu options should be toggle actions when there is only
	// 1 user active, but they should be normal actions when there are
	// multiple users.
	disconnect(serviceDnd, 0, 0, 0);
	disconnect(serviceAutoAnswer, 0, 0, 0);
	if (phone->ref_users().size() == 1) {
		t_service *srv = phone->ref_service(phone->ref_users().front());
		
		serviceDnd->setToggleAction(true);
		serviceDnd->setOn(srv->is_dnd_active());
		connect(serviceDnd, SIGNAL(toggled(bool)),
			this, SLOT(srvDnd(bool)));
		
		serviceAutoAnswer->setToggleAction(true);
		serviceAutoAnswer->setOn(srv->is_auto_answer_active());
		connect(serviceAutoAnswer, SIGNAL(toggled(bool)),
			this, SLOT(srvAutoAnswer(bool)));
	} else {
		serviceDnd->setOn(false);
		serviceDnd->setToggleAction(false);
		connect(serviceDnd, SIGNAL(activated()),
			this, SLOT(srvDnd()));
		
		serviceAutoAnswer->setOn(false);
		serviceAutoAnswer->setToggleAction(false);
		connect(serviceAutoAnswer, SIGNAL(activated()),
			this, SLOT(srvAutoAnswer()));
	}
}

void MphoneForm::phoneRegister()
{
	t_gui *gui = (t_gui *)ui;
	list<t_user *> user_list = phone->ref_users();
	
	if (user_list.size() > 1) {
		if (selectUserForm) {
			MEMMAN_DELETE(selectUserForm);
			delete (selectUserForm);
		}
		
		selectUserForm = new SelectUserForm(this, "register", true);
		MEMMAN_NEW(selectUserForm);
		
		connect(selectUserForm, SIGNAL(selection(list<t_user *>)), this, 
			SLOT(do_phoneRegister(list<t_user *>)));
		selectUserForm->show(SELECT_REGISTER);
	} else {
		gui->action_register(user_list);
	}
}

void MphoneForm::do_phoneRegister(list<t_user *> user_list)
{
	((t_gui *)ui)->action_register(user_list);
}

void MphoneForm::phoneDeregister()
{
	t_gui *gui = (t_gui *)ui;
	list<t_user *> user_list = phone->ref_users();
	
	if (user_list.size() > 1) {
		if (selectUserForm) {
			MEMMAN_DELETE(selectUserForm);
			delete (selectUserForm);
		}
		
		selectUserForm = new SelectUserForm(this, "deregister", true);
		MEMMAN_NEW(selectUserForm);
		
		connect(selectUserForm, SIGNAL(selection(list<t_user *>)), this, 
			SLOT(do_phoneDeregister(list<t_user *>)));
		selectUserForm->show(SELECT_DEREGISTER);
	} else {
		gui->action_deregister(user_list, false);
	}
}

void MphoneForm::do_phoneDeregister(list<t_user *> user_list)
{
	((t_gui *)ui)->action_deregister(user_list, false);
}

void MphoneForm::phoneDeregisterAll()
{
	t_gui *gui = (t_gui *)ui;
	list<t_user *> user_list = phone->ref_users();
	
	if (user_list.size() > 1) {
		if (selectUserForm) {
			MEMMAN_DELETE(selectUserForm);
			delete (selectUserForm);
		}
		
		selectUserForm = new SelectUserForm(this, "deregister all", true);
		MEMMAN_NEW(selectUserForm);
	
		connect(selectUserForm, SIGNAL(selection(list<t_user *>)), this, 
			SLOT(do_phoneDeregisterAll(list<t_user *>)));
		selectUserForm->show(SELECT_DEREGISTER_ALL);
	} else {
		gui->action_deregister(user_list, true);
	}
}

void MphoneForm::do_phoneDeregisterAll(list<t_user *> user_list)
{
	((t_gui *)ui)->action_deregister(user_list, true);
}

void MphoneForm::phoneShowRegistrations()
{
	list<t_user *> user_list = phone->ref_users();
	((t_gui *)ui)->action_show_registrations(user_list);
}


// Show the semi-modal invite window
void MphoneForm::phoneInvite(t_user * user_config, 
		const QString &dest, const QString &subject)
{
	// Seize the line, so no incoming call can take the line
	if (!((t_gui *)ui)->action_seize()) return;
	
	if (inviteForm) {
		inviteForm->clear();
	} else {
		inviteForm = new InviteForm(this, "invite", true);
		MEMMAN_NEW(inviteForm);
	}
	
	connect(inviteForm, 
		SIGNAL(destination(t_user *, const QString &, const t_url &, 
				   const QString &)),
		this, 
		SLOT(do_phoneInvite(t_user *, const QString &, 
				    const t_url &, const QString &)));
	
	inviteForm->show(user_config, dest, subject);
	updateState();
}

void MphoneForm::phoneInvite(const QString &dest, const QString &subject)
{
	phoneInvite(NULL, "", "");
}

void MphoneForm::phoneInvite()
{
	phoneInvite("", "");
}

// Execute the invite action. This slot is connected to the destination
// signal of the invite window.
void MphoneForm::do_phoneInvite(t_user *user_config, const QString &display, 
			const t_url &destination, const QString &subject)
{
	((t_gui *)ui)->action_invite(user_config, destination, display.ascii(), subject.ascii());
	updateState();
}

// Redial last call
void MphoneForm::phoneRedial(void)
{
	t_url url;
	string display, subject;
	t_user *user_config;
	
	if (!ui->get_last_call_info(url, display, subject, &user_config)) return;
	((t_gui *)ui)->action_invite(user_config, url, display, subject);
	updateState();
}


void MphoneForm::phoneAnswer()
{
	((t_gui *)ui)->action_answer();
	updateState();
}

void MphoneForm::phoneBye()
{
	((t_gui *)ui)->action_bye();
	updateState();
}


void MphoneForm::phoneReject()
{
	((t_gui *)ui)->action_reject();
	updateState();
}


// Show the semi-modal redirect form
void MphoneForm::phoneRedirect()
{
	int active_line = phone->get_active_line();
	t_user *user_config = phone->get_line_user(active_line);
	
	if (redirectForm) {
		MEMMAN_DELETE(redirectForm);
		delete (redirectForm);
	}
	
	redirectForm = new RedirectForm(this, "redirect", true);
	MEMMAN_NEW(redirectForm);
	connect(redirectForm, SIGNAL(destinations(const list<t_display_url> &)),
		this, SLOT(do_phoneRedirect(const list<t_display_url> &)));
	
	redirectForm->show(user_config);
}

// Execute the redirect action.
void MphoneForm::do_phoneRedirect(const list<t_display_url> &destinations)
{
	((t_gui *)ui)->action_redirect(destinations);
	updateState();
}

// Show the semi-modal call transfer window
void MphoneForm::phoneTransfer()
{
	int active_line = phone->get_active_line();
	t_user *user_config = phone->get_line_user(active_line);
	
	// Hold the call if setting in user profile indicates call hold
	if (user_config->referrer_hold) {
		phoneHold(true);
	}
	
	if (transferForm) {
		MEMMAN_DELETE(transferForm);
		delete transferForm;
	}
	
	transferForm = new TransferForm(this, "transfer", true);
	MEMMAN_NEW(transferForm);
	connect(transferForm, SIGNAL(destination(const t_display_url &)),
		this, SLOT(do_phoneTransfer(const t_display_url &)));
	
	transferForm->show(user_config);
	updateState();
}

// Execute the transfer action. This slot is connected to the destination
// signal of the transfer window.
void MphoneForm::do_phoneTransfer(const t_display_url &destination)
{
	((t_gui *)ui)->action_refer(destination.url, destination.display);
	updateState();
}

void MphoneForm::phoneHold(bool on)
{
	if (on) {
		((t_gui *)ui)->action_hold();
	} else {
		((t_gui *)ui)->action_retrieve();
	}
	
	updateState();
}

void MphoneForm::phoneConference()
{
	((t_gui *)ui)->action_conference();
	updateState();
}

void MphoneForm::phoneMute(bool on)
{
	((t_gui *)ui)->action_mute(on);
	updateState();
}

void MphoneForm::phoneTermCap()
{
	// In-dialog OPTIONS request
	int line = phone->get_active_line();
	if (phone->get_line_substate(line) == LSSUB_ESTABLISHED) {
		((t_gui *)ui)->action_options();
		return;
	}
	
	// Out-of-dialog OPTIONS request
	if (termCapForm) {
		MEMMAN_DELETE(termCapForm);
		delete (termCapForm);
	}
	
	termCapForm = new TermCapForm(this, "termcap", true);
	MEMMAN_NEW(termCapForm);
	connect(termCapForm, SIGNAL(destination(t_user *, const t_url &)),
		this, SLOT(do_phoneTermCap(t_user *, const t_url &)));
	
	termCapForm->show();
}

void MphoneForm::do_phoneTermCap(t_user *user_config, const t_url &destination)
{
	((t_gui *)ui)->action_options(user_config, destination);
}

void MphoneForm::phoneDTMF()
{
	if (!dtmfForm) {
		dtmfForm = new DtmfForm(this);
		MEMMAN_NEW(dtmfForm);
		connect(dtmfForm, SIGNAL(digits(const QString &)),
			this, SLOT(sendDTMF(const QString &)));
	}
	
	dtmfForm->show();
}

void MphoneForm::sendDTMF(const QString &digits)
{
	((t_gui *)ui)->action_dtmf(digits.ascii());	
}

// Radio button for line 1 changed state
void MphoneForm::line1rbChangedState( bool on )
{
	// If the radio button is switched off, then return, the toggle
	// on the other line will handle the action
	if (!on) return;
	
	((t_gui *)ui)->action_activate_line(0);
}

void MphoneForm::line2rbChangedState( bool on )
{
	// If the radio button is switched off, then return, the toggle
	// on the other line will handle the action
	if (!on) return;
	
	((t_gui *)ui)->action_activate_line(1);
}

// Enable/disable dnd when there is 1 user active
void MphoneForm::srvDnd( bool on ) 
{
	((t_gui *)ui)->srv_dnd(phone->ref_users(), on);
	updateServicesStatus();
}

// Enable/disable dnd when there are multiple users active
void MphoneForm::srvDnd()
{
	if (selectUserForm) {
		MEMMAN_DELETE(selectUserForm);
		delete (selectUserForm);
	}
		
	selectUserForm = new SelectUserForm(this, "dnd", true);
	MEMMAN_NEW(selectUserForm);
		
	connect(selectUserForm, SIGNAL(selection(list<t_user *>)), this, 
			SLOT(do_srvDnd_enable(list<t_user *>)));
	connect(selectUserForm, SIGNAL(not_selected(list<t_user *>)), this, 
			SLOT(do_srvDnd_disable(list<t_user *>)));
			
	selectUserForm->show(SELECT_DND);
}

void MphoneForm::do_srvDnd_enable(list<t_user *> user_list) {
	((t_gui *)ui)->srv_dnd(user_list, true);
	updateServicesStatus();
}

void MphoneForm::do_srvDnd_disable(list<t_user *> user_list) {
	((t_gui *)ui)->srv_dnd(user_list, false);
	updateServicesStatus();
}

// Enable/disable auto answer when there is 1 user active
void MphoneForm::srvAutoAnswer( bool on ) 
{
	((t_gui *)ui)->srv_auto_answer(phone->ref_users(), on);
	updateServicesStatus();
}

// Enable/disable auto answer when there are multiple users active
void MphoneForm::srvAutoAnswer()
{
	if (selectUserForm) {
		MEMMAN_DELETE(selectUserForm);
		delete (selectUserForm);
	}
		
	selectUserForm = new SelectUserForm(this, "auto answer", true);
	MEMMAN_NEW(selectUserForm);
		
	connect(selectUserForm, SIGNAL(selection(list<t_user *>)), this, 
			SLOT(do_srvAutoAnswer_enable(list<t_user *>)));
	connect(selectUserForm, SIGNAL(not_selected(list<t_user *>)), this, 
			SLOT(do_srvAutoAnswer_disable(list<t_user *>)));
			
	selectUserForm->show(SELECT_AUTO_ANSWER);
}

void MphoneForm::do_srvAutoAnswer_enable(list<t_user *> user_list) {
	((t_gui *)ui)->srv_auto_answer(user_list, true);
	updateServicesStatus();
}

void MphoneForm::do_srvAutoAnswer_disable(list<t_user *> user_list) {
	((t_gui *)ui)->srv_auto_answer(user_list, false);
	updateServicesStatus();
}

void MphoneForm::srvRedirect()
{
	if (!srvRedirectForm) {
		srvRedirectForm = new SrvRedirectForm(this, "call redirection", true);
		MEMMAN_NEW(srvRedirectForm);
		connect(srvRedirectForm, 
			SIGNAL(destinations(t_user *,
					    const list<t_display_url> &,
					    const list<t_display_url> &,
					    const list<t_display_url> &)),
			this, 
			SLOT(do_srvRedirect(t_user *,
					    const list<t_display_url> &,
					    const list<t_display_url> &,
					    const list<t_display_url> &)));
	}
	
	srvRedirectForm->show();
}

void MphoneForm::do_srvRedirect(t_user *user_config,
				const list<t_display_url> &always, 
				const list<t_display_url> &busy,
				const list<t_display_url> &noanswer)
{
	// Redirection always
	if (always.empty()) {
		((t_gui *)ui)->srv_disable_cf(user_config, CF_ALWAYS);
	} else {
		((t_gui *)ui)->srv_enable_cf(user_config, CF_ALWAYS, always);
	}
	
	// Redirection busy
	if (busy.empty()) {
		((t_gui *)ui)->srv_disable_cf(user_config, CF_BUSY);
	} else {
		((t_gui *)ui)->srv_enable_cf(user_config, CF_BUSY, busy);
	}
	
	// Redirection no answer
	if (noanswer.empty()) {
		((t_gui *)ui)->srv_disable_cf(user_config, CF_NOANSWER);
	} else {
		((t_gui *)ui)->srv_enable_cf(user_config, CF_NOANSWER, noanswer);
	}
	
	updateServicesStatus();
}


void MphoneForm::about()
{
	QString s = sys_config->about(true).c_str();
	
	QMessageBox mbAbout(PRODUCT_NAME, s.replace(' ', "&nbsp;"), 
		    QMessageBox::Information, 
		    QMessageBox::Ok | QMessageBox::Default,
		    QMessageBox::NoButton, QMessageBox::NoButton);
	mbAbout.setIconPixmap(QPixmap::fromMimeSource("twinkle48.png"));
	mbAbout.exec();
}

void MphoneForm::aboutQt()
{
	QMessageBox::aboutQt(this, PRODUCT_NAME);
}

void MphoneForm::editUserProfile()
{
	if (!userProfileForm) {
		userProfileForm = new UserProfileForm(this, "user profile", true);
		MEMMAN_NEW(userProfileForm);
	
		connect(userProfileForm, 
			SIGNAL(sipUserChanged(t_user *)),
			this, 
			SLOT(displayUser(t_user *)));
		
		connect(userProfileForm,
			SIGNAL(authCredentialsChanged(t_user *, const string&)),
			this,
			SLOT(updateAuthCache(t_user *, const string&)));
		
		connect(userProfileForm,
			SIGNAL(stunServerChanged(t_user *)),
			this,
			SLOT(updateStunSettings(t_user *)));
	}
	
	userProfileForm->show(phone->ref_users());
}

void MphoneForm::editSysSettings()
{
	if (!sysSettingsForm) {
		sysSettingsForm = new SysSettingsForm(this, "system settings", true);
		MEMMAN_NEW(sysSettingsForm);
		connect(sysSettingsForm, SIGNAL(sipUdpPortChanged()),
			this, SLOT(updateSipUdpPort()));
		connect(sysSettingsForm, SIGNAL(rtpPortChanged()),
			this, SLOT(updateRtpPorts()));
	}
	
	sysSettingsForm->show();
}

void MphoneForm::selectProfile()
{
	if (!selectProfileForm) {
		selectProfileForm = new SelectProfileForm(this, "select profile", true);
		MEMMAN_NEW(selectProfileForm);
		connect(selectProfileForm, SIGNAL(selection(const list<string> &)),
			this, SLOT(newUsers(const list<string> &)));
	}
	
	selectProfileForm->showForm(this);
}

// A new set of users has been selected.
// Remove users from the current user set that are not in the selection.
// Add users from the selection that are not in the current set of users.
void MphoneForm::newUsers(const list<string> &profiles)
{
	string error_msg;
	
	// NOTE: First users must be removed. It could be that a
	// user profile of an active was renamed. In this case, the user 
	// with the old profile name is first removed and then added again.
	
	list<t_user *> user_list = phone->ref_users();
	
	// Remove current users that are not selected anymore.
	for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
		if (std::find(profiles.begin(), profiles.end(), 
			      (*i)->get_filename().c_str()) == profiles.end())
		{
			// User is not selected anymore.
			// Deregister user
			if (phone->get_is_registered(*i)) {
				phone->pub_registration(*i, REG_DEREGISTER);
			}
			
			log_file->write_header("MphoneForm::newUsers");
			log_file->write_raw("Stop user profile: ");
			log_file->write_raw((*i)->get_profile_name());
			log_file->write_endl();
			log_file->write_footer();
			phone->remove_phone_user(*(*i));
		}
	}
	
	// Determine which users to add
	list<string> add_profile_list;
	for (list<string>::const_iterator i = profiles.begin(); i != profiles.end(); i++) {
		QString profile = (*i).c_str();
		// Strip off the .cfg extension
		profile.truncate(profile.length() - 4);
		
		if (!phone->ref_user_profile(profile.ascii())) {
			add_profile_list.push_back(*i);
		}
	}
	
	// Add new phone users
	QProgressDialog progress("Starting user profiles...", "Abort", add_profile_list.size(), this,
				 "starting user profiles", true);
	progress.setCaption(PRODUCT_NAME);
	progress.setMinimumDuration(200);
	int progressStep = 0;
	for (list<string>::iterator i = add_profile_list.begin(); i != add_profile_list.end(); i++) {
		progress.setProgress(progressStep);
		qApp->processEvents();
		
		if (progress.wasCancelled()) {
			log_file->write_report("User aborted startup of new users.", 
					       "MphoneForm::newUsers");
			break;
		}
		
		t_user user_config;
		
		// Read user configuration
		if (user_config.read_config(*i, error_msg)) {
			t_user *dup_user;
			
			log_file->write_header("MphoneForm::newUsers");
			log_file->write_raw("Run user profile: ");
			log_file->write_raw(user_config.get_profile_name());
			log_file->write_endl();
			log_file->write_footer();
			
			if (phone->add_phone_user(user_config, &dup_user))
			{
				// NAT discovery
				if (user_config.use_stun &&
				    !phone->stun_discover_nat(&user_config, error_msg)) 
				{
					// Warn user that the STUN settings will not work.
					((t_gui *)ui)->cb_show_msg(this, error_msg, 
							MSG_WARNING);
				}
				
				// Register at startup
				if (user_config.register_at_startup) {
					phone->pub_registration(&user_config,
						REG_REGISTER,
						DUR_REGISTRATION(&user_config));
				}
			} else {
				error_msg = "The following profiles are both for user ";
				error_msg += user_config.name;
				error_msg += '@';
				error_msg += user_config.domain;
				error_msg += ":\n\n";
				error_msg += user_config.get_profile_name();
				error_msg += "\n";
				error_msg += dup_user->get_profile_name();
				error_msg += "\n\n";
				error_msg += "You can only run multiple profiles ";
				error_msg += "for different users.";
				
				log_file->write_report(error_msg,
					"MphoneForm::newUsers", 
					LOG_NORMAL, LOG_WARNING);
				ui->cb_display_msg(error_msg, MSG_WARNING);
			}
		} else {
			log_file->write_report(error_msg,
					"MphoneForm::newUsers", 
					LOG_NORMAL, LOG_CRITICAL);
			ui->cb_display_msg(error_msg, MSG_CRITICAL);
		}
		
		progressStep++;
	}
	progress.setProgress(add_profile_list.size());
	
	displayUser(phone->ref_users().front());
	updateRegStatus();
	updateServicesStatus();
	updateSysTrayStatus();
	updateMenuStatus();
	updateState();
}

void MphoneForm::displayUser(t_user *user_config)
{
	QString s;
	QString toolTip;
	
	list<t_user *> user_list = phone->ref_users();
	if (user_list.size() == 1) {
		s = user_config->get_display_uri().c_str();
		toolTip = s;
	} else {
		s = "Multiple users";
		
		// Tool tip shows all users
		for (list<t_user *>::iterator i = user_list.begin(); i != user_list.end(); i++) {
			toolTip += (*i)->get_display_uri().c_str();
			toolTip += "\n";
		}
	}
	
	userTextLabel->setText(s);
	userTextLabel->setCursorPosition(0);
	QToolTip::add(userTextLabel, toolTip);
}

void MphoneForm::updateSipUdpPort()
{
	((t_gui *)ui)->cb_show_msg(sysSettingsForm,
			"You have changed the SIP UDP port. This setting will only become "\
			"active when you restart Twinkle.",
			MSG_INFO);
}

void MphoneForm::updateRtpPorts()
{
	phone->init_rtp_ports();
}

void MphoneForm::updateStunSettings(t_user *user_config)
{
	if (user_config->use_stun) {
		string s;
		if (!phone->stun_discover_nat(user_config, s)) {
			// Warn user that the STUN settings will not work.
			((t_gui *)ui)->cb_show_msg(this, s, MSG_WARNING);
		}
	} else {
		// Disable STUN
		phone->disable_stun(user_config);
	}
}

void MphoneForm::updateAuthCache(t_user *user_config, const string &realm)
{
	phone->remove_cached_credentials(user_config, realm);
}

void MphoneForm::viewLog()
{
	if (!logViewForm) {
		logViewForm = new LogViewForm(NULL);
		MEMMAN_NEW(logViewForm);
	}
	
	logViewForm->show();
}

void MphoneForm::updateLog(bool log_zapped)
{
	if (logViewForm) logViewForm->update(log_zapped);
}

void MphoneForm::viewHistory()
{
	if (!historyForm) {
		historyForm = new HistoryForm(NULL);
		MEMMAN_NEW(historyForm);
	}
	
	connect(historyForm, 
		SIGNAL(call(t_user *, const QString &, const QString &)), this,  
		SLOT(phoneInvite(t_user *, const QString &, const QString &)));
	
	historyForm->show();
}

void MphoneForm::updateCallHistory()
{
	if (historyForm) historyForm->update();
}

QLabel *MphoneForm::getSysTray()
{
	return sysTray;
}

