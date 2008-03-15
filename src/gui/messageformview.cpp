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

#include "messageformview.h"

#include "gui.h"

#include "audits/memman.h"

MessageFormView::MessageFormView(QWidget *parent, im::t_msg_session *s) :
		MessageForm(parent),
		t_observer()
{
	_msgSession = s;
	_msgSession->attach(this);
	_destructing = false;
}

MessageFormView::~MessageFormView()
{
	_destructing = true;
	if (_msgSession) {
		((t_gui *)ui)->removeMessageSession(_msgSession);
		MEMMAN_DELETE(_msgSession);
		delete _msgSession;
	}
}

void MessageFormView::updatePartyInfo(void)
{
	t_user *user_config = _msgSession->get_user();
	selectUserConfig(user_config);
	t_display_url to_url = _msgSession->get_remote_party();
	
	if (to_url.is_valid()) {
		toLineEdit->setText(ui->format_sip_address(user_config, to_url.display, to_url.url).c_str());
	} else {
		toLineEdit->clear();
	}
}

void MessageFormView::update(void) {
	// Called directly from core, so lock GUI
	ui->lock();
	
	updatePartyInfo();
	setRemotePartyCaption();
	
	t_user *user_config = _msgSession->get_user();
	t_display_url to_url = _msgSession->get_remote_party();
	
	if (!_msgSession->is_msg_in_flight() && !msgLineEdit->isEnabled()) {
		msgLineEdit->clear();
		msgLineEdit->setEnabled(true);
		msgLineEdit->setFocus();
	} else if (_msgSession->is_msg_in_flight() && msgLineEdit->isEnabled()) {
		msgLineEdit->setText(tr("sending message"));
		msgLineEdit->setEnabled(false);
	}
	
	msgLineEdit->setEnabled(!_msgSession->is_msg_in_flight());
	
	if (_msgSession->error_received()) {
		string error_msg = _msgSession->take_error();
		displayError(error_msg.c_str());
	}
	
	if (_msgSession->delivery_notification_received()) {
		string notification = _msgSession->take_delivery_notification();
		displayDeliveryNotification(notification.c_str());
	}
	
	if (_msgSession->is_new_message_added()) {
		im::t_msg m;
		try {
			m = _msgSession->get_last_message();
		} catch (empty_list_exception) {
			ui->unlock();
			return;
		}
		
		QString name;
		if (m.direction == im::MSG_DIR_IN) {
			name = to_url.display.c_str();
			if (name.isEmpty()) {
				name = to_url.url.get_user().c_str();
			}
		} else {
			name = user_config->get_display(false).c_str();
			if (name.isEmpty()) {
				name = user_config->get_name().c_str();
			}
		}
		
		addMessage(name, m.message.c_str(), m.direction == im::MSG_DIR_IN,
			   m.format == im::TXT_HTML);
	}
	
	ui->unlock();
}

void MessageFormView::subject_destroyed()
{
	_msgSession = NULL;
	
	if (!_destructing) close();
}

void MessageFormView::show()
{
	((t_gui *)ui)->fill_user_combo(fromComboBox);
	updatePartyInfo();
	MessageForm::show();
}
