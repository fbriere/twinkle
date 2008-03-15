/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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

void MessageForm::init()
{
	setWFlags(getWFlags() | Qt::WDestructiveClose);
	
	_getAddressForm = 0;
	_remotePartyComplete = false;
	
	// Set toolbutton icons for disabled options.
	setDisabledIcon(addressToolButton, "kontact_contacts-disabled.png");
}

void MessageForm::destroy()
{
	if (_getAddressForm) {
		MEMMAN_DELETE(_getAddressForm);
		delete _getAddressForm;
	}
}

void MessageForm::reject()
{
	MEMMAN_DELETE(this); // destructive close
	QDialog::reject();
}

void MessageForm::closeEvent(QCloseEvent *e)
{
	reject();
}


void MessageForm::show()
{
	if (toLineEdit->text().isEmpty()) {
		toLineEdit->setFocus();
	} else {
		// Once a message session has been created, the
		// source and destination cannot be changed anymore.
		fromComboBox->setEnabled(false);
		toLineEdit->setEnabled(false);
		addressToolButton->setEnabled(false);
		msgLineEdit->setFocus();
	}
	
	QDialog::show();
}

void MessageForm::selectUserConfig(t_user *user_config)
{
	for (int i = 0; i < fromComboBox->count(); i++) {
		if (fromComboBox->text(i) == 
		    user_config->get_profile_name().c_str())
		{
			fromComboBox->setCurrentItem(i);
			break;
		}
	}
}

void MessageForm::showAddressBook()
{
	if (!_getAddressForm) {
		_getAddressForm = new GetAddressForm(
				this, "select address", true);
		MEMMAN_NEW(_getAddressForm);
	}
	
	connect(_getAddressForm, 
		SIGNAL(address(const QString &)),
		this, SLOT(selectedAddress(const QString &)));
	
	_getAddressForm->show();
}

void MessageForm::selectedAddress(const QString &address)
{
	toLineEdit->setText(address);
}

bool MessageForm::updateMessageSession()
{
	string display, dest_str;
	t_user *from_user = phone->ref_user_profile(
				fromComboBox->currentText().ascii());
	if (!from_user) {
		// The user profile is not active anymore
		fromComboBox->setFocus();
		return false;
	}
	
	ui->expand_destination(from_user, toLineEdit->text().stripWhiteSpace().ascii(), 
			       display, dest_str);
	t_url dest(dest_str);
	
	if (!dest.is_valid()) {
		toLineEdit->setFocus();
		toLineEdit->selectAll();
		return false;
	}
	
	_msgSession->set_user(from_user);
	_msgSession->set_remote_party(t_display_url(dest, display));
	
	setRemotePartyCaption();

	return true;
}

void MessageForm::sendMessage() {
	if (toLineEdit->text().isEmpty() || msgLineEdit->text().isEmpty()) {
		// Nothing to send
		return;
	}
	
	if (toLineEdit->isEnabled()) {
		if (!updateMessageSession()) {
			return;
		}

		// Once a message session has been created, the
		// source and destination cannot be changed anymore.
		fromComboBox->setEnabled(false);
		toLineEdit->setEnabled(false);
		addressToolButton->setEnabled(false);	
		
	}
	
	_msgSession->send_msg(msgLineEdit->text().ascii(), im::TXT_PLAIN);
}

void MessageForm::addMessage(const QString &name, const QString &msg, bool incoming,
			    bool html)
{
	QString s = "<b>";
	if (incoming) s += "<font color=\"blue\">";
	s += QStyleSheet::escape(name);
	if (incoming) s += "</font>";
	s += ": </b>";
	
	if (html) {
		s += msg;
	} else {
		s += QStyleSheet::escape(msg);
	}
	
	conversationTextEdit->append(s);
}

void MessageForm::displayError(const QString &errorMsg)
{
	QString s = "<font color =\"red\">";
	s += "<b>";
	s += tr("Delivery failure").ascii();
	s += ": </b>";
	s += QStyleSheet::escape(errorMsg);
	s += "</font>";
	
	conversationTextEdit->append(s);
}

void MessageForm::displayDeliveryNotification(const QString &notification)
{
	QString s = "<font color =\"darkgreen\">";
	s += "<b>";
	s += tr("Delivery notification").ascii();
	s += ": </b>";
	s += QStyleSheet::escape(notification);
	s += "</font>";
	
	conversationTextEdit->append(s);
}

void MessageForm::setRemotePartyCaption(void) {
	if (!_msgSession) return;
	t_user *user = _msgSession->get_user();
	t_display_url remote_party = _msgSession->get_remote_party();
	setCaption(ui->format_sip_address(user, 
			remote_party.display, remote_party.url).c_str());
}
