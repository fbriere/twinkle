/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, pres:erving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
/*
    Copyright (C) 2005  Michel de Boer <michelboer@xs4all.nl>

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
		((KSystemTray *)sysTray)->setPixmap(
				QPixmap::fromMimeSource("twinkle24.png"));
		((KSystemTray *)sysTray)->setCaption(PRODUCT_NAME);
		QToolTip::add(sysTray, PRODUCT_NAME);
		
		// Exit application when user selects Quit from the tray menu
		connect((KSystemTray *)sysTray, SIGNAL(quitSelected()),
			this, SLOT(fileExit()));
		
		((KSystemTray *)sysTray)->show();
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
	// Deregister if the phone is registered.
	if (phone->get_is_registered()) {
		display("");
		display("De-registering phone...");
		phone->pub_registration(REG_DEREGISTER);
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
	
	// Disable/enable controls depending on the line state
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
	if (callRedial->isEnabled() && 
	    ui->get_last_call_info(last_url, last_display, last_subject))
	{
		QString s = "Invite ";
		s.append(ui->format_sip_address(last_display, last_url).c_str());
		callRedial->setToolTip(s);
	} else {
		callRedial->setToolTip("Repeat last call invitation");
	}
}

// Update registration status
void MphoneForm::updateRegStatus()
{
	if (phone->get_is_registered()) {
		regStatusTextLabel->setText("Registered");
	} else if (phone->get_last_reg_failed()) {
		regStatusTextLabel->setText("<font color=red>Failed</font>");
	} else {
		regStatusTextLabel->setText("Not registered");
	}
}

// Update active services status
void MphoneForm::updateServicesStatus()
{	
	dndTextLabel->setEnabled(phone->service.is_dnd_active());
	redirectionTextLabel->setEnabled(phone->service.is_cf_active());
	autoAnswerTextLabel->setEnabled(phone->service.is_auto_answer_active());
}

void MphoneForm::phoneRegister()
{
	((t_gui *)ui)->action_register();
}

void MphoneForm::phoneDeregister()
{
	/*
	DeregisterForm *df = new DeregisterForm(this, "deregister", true);
	MEMMAN_NEW(df);
	
	if (df->exec()) {
		((t_gui *)ui)->action_deregister(df->deregAllCheckBox->isChecked());
	}
	
	MEMMAN_DELETE(df);
	delete df;
	*/
	
	((t_gui *)ui)->action_deregister(false);
}

void MphoneForm::phoneDeregisterAll()
{
	((t_gui *)ui)->action_deregister(true);
}

void MphoneForm::phoneShowRegistrations()
{
	((t_gui *)ui)->action_show_registrations();
}


// Show the semi-modal invite window
void MphoneForm::phoneInvite()
{
	// Seize the line, so no incoming call can take the line
	((t_gui *)ui)->action_seize();
	
	if (inviteForm) {
		MEMMAN_DELETE(inviteForm);
		delete inviteForm;
	}
	
	inviteForm = new InviteForm(this, "invite", true);
	MEMMAN_NEW(inviteForm);
	connect(inviteForm, SIGNAL(destination(const t_url &, const QString &)),
		this, SLOT(do_phoneInvite(const t_url &, const QString &)));
	
	inviteForm->show();
	updateState();
}

// Execute the invite action. This slot is connected to the destination
// signal of the invite window.
void MphoneForm::do_phoneInvite(const t_url &destination, const QString &subject)
{
	((t_gui *)ui)->action_invite(destination, "", subject.ascii());
	updateState();
}

// Redial last call
void MphoneForm::phoneRedial(void)
{
	t_url url;
	string display, subject;
	
	if (!ui->get_last_call_info(url, display, subject)) return;
	((t_gui *)ui)->action_invite(url, display, subject);
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
	if (redirectForm) {
		MEMMAN_DELETE(redirectForm);
		delete (redirectForm);
	}
	
	redirectForm = new RedirectForm(this, "redirect", true);
	MEMMAN_NEW(redirectForm);
	connect(redirectForm, SIGNAL(destinations(const list<t_url> &)),
		this, SLOT(do_phoneRedirect(const list<t_url> &)));
	
	redirectForm->show();
}

// Execute the redirect action.
void MphoneForm::do_phoneRedirect(const list<t_url> &destinations)
{
	((t_gui *)ui)->action_redirect(destinations);
	updateState();
}

// Show the semi-modal call transfer window
void MphoneForm::phoneTransfer()
{
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
	connect(transferForm, SIGNAL(destination(const t_url &)),
		this, SLOT(do_phoneTransfer(const t_url &)));
	
	transferForm->show();
	updateState();
}

// Execute the transfer action. This slot is connected to the destination
// signal of the transfer window.
void MphoneForm::do_phoneTransfer(const t_url &destination)
{
	((t_gui *)ui)->action_refer(destination, "");
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
	
	termCapForm = new TermCapForm(this, "redirect", true);
	MEMMAN_NEW(termCapForm);
	connect(termCapForm, SIGNAL(destination(const t_url &)),
		this, SLOT(do_phoneTermCap(const t_url &)));
	
	termCapForm->show();
}

void MphoneForm::do_phoneTermCap(const t_url &destination)
{
	((t_gui *)ui)->action_options(destination);
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

void MphoneForm::srvDnd( bool on )
{
	((t_gui *)ui)->srv_dnd(on);
	updateServicesStatus();
}

void MphoneForm::srvAutoAnswer( bool on )
{
	((t_gui *)ui)->srv_auto_answer(on);
	updateServicesStatus();
}

void MphoneForm::srvRedirect()
{
	if (!srvRedirectForm) {
		srvRedirectForm = new SrvRedirectForm(this, "call redirection", true);
		MEMMAN_NEW(srvRedirectForm);
		connect(srvRedirectForm, 
			SIGNAL(destinations(const list<t_url> &,
					    const list<t_url> &,
					    const list<t_url> &)),
			this, 
			SLOT(do_srvRedirect(const list<t_url> &,
					    const list<t_url> &,
					    const list<t_url> &)));
	}
	
	srvRedirectForm->show();
}

void MphoneForm::do_srvRedirect(const list<t_url> &always, const list<t_url> &busy,
				const list<t_url> &noanswer)
{
	// Redirection always
	if (always.empty()) {
		((t_gui *)ui)->srv_disable_cf(CF_ALWAYS);
	} else {
		((t_gui *)ui)->srv_enable_cf(CF_ALWAYS, always);
	}
	
	// Redirection busy
	if (busy.empty()) {
		((t_gui *)ui)->srv_disable_cf(CF_BUSY);
	} else {
		((t_gui *)ui)->srv_enable_cf(CF_BUSY, busy);
	}
	
	// Redirection no answer
	if (noanswer.empty()) {
		((t_gui *)ui)->srv_disable_cf(CF_NOANSWER);
	} else {
		((t_gui *)ui)->srv_enable_cf(CF_NOANSWER, noanswer);
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
			SIGNAL(sipUserChanged()),
			this, 
			SLOT(displayUser()));
		
		connect(userProfileForm, 
			SIGNAL(rtpPortChanged()),
			this, 
			SLOT(updateRtpPorts()));
		
		connect(userProfileForm,
			SIGNAL(stunServerChanged()),
			this,
			SLOT(updateStunSettings()));
	}
	
	userProfileForm->show(true);
}

void MphoneForm::editSysSettings()
{
	if (!sysSettingsForm) {
		sysSettingsForm = new SysSettingsForm(this, "system settings", true);
		MEMMAN_NEW(sysSettingsForm);
	}
	
	sysSettingsForm->show();
}

void MphoneForm::displayUser()
{
	QString s;
	
	s = user_config->display.c_str();
	if (s != "") s.append(' ');
	s.append("<sip:").append(user_config->name.c_str());
	s.append('@').append(user_config->domain.c_str()).append(">");
	userTextLabel->setText(s);
	userTextLabel->setCursorPosition(0);
}

void MphoneForm::updateRtpPorts()
{
	phone->init_rtp_ports();
}

void MphoneForm::updateStunSettings()
{
	if (user_config->use_stun) {
		string s;
		if (!stun_discover_nat(s)) {
			// Warn user that the STUN settings will not work.
			((t_gui *)ui)->cb_show_msg(this, s, MSG_WARNING);
		}
	} else {
		// Disable STUN
		phone->use_stun = false;
	}
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

QLabel *MphoneForm::getSysTray()
{
	return sysTray;
}

