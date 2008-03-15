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

#include "msg_session.h"

#include <sys/time.h>

#include "phone.h"

extern t_phone *phone;

using namespace im;

t_msg::t_msg() {}

t_msg::t_msg(const string &msg, t_direction dir, t_text_format fmt) :
	message(msg),
	direction(dir),
	format(fmt)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	timestamp = t.tv_sec;
}

t_msg_session::t_msg_session(t_user *u) :
	user_config(u),
	new_message_added(false),
	error_recvd(false),
	delivery_notification_recvd(false),
	msg_in_flight(false)
{
}

t_msg_session::t_msg_session(t_user *u, t_display_url _remote_party) :
	user_config(u),
	new_message_added(false),
	remote_party(_remote_party),
	error_recvd(false),
	delivery_notification_recvd(false),
	msg_in_flight(false)
{
}

t_user *t_msg_session::get_user(void) const {
	return user_config;
}

t_display_url t_msg_session::get_remote_party(void) const {
	return remote_party;
}

void t_msg_session::set_user(t_user *u) {
	user_config = u;
}

void t_msg_session::set_remote_party(const t_display_url &du) {
	remote_party = du;
}

t_msg t_msg_session::get_last_message(void) {
	new_message_added = false;
	if (messages.empty()) {
		throw empty_list_exception();
	}
	return messages.back();
}

bool t_msg_session::is_new_message_added(void) const {
	return new_message_added;
}

void t_msg_session::set_display_if_empty(const string &display) {
	if (remote_party.display.empty()) {
		remote_party.display = display;
	}
}

const list<t_msg> &t_msg_session::get_messages(void) const {
	return messages;
}

void t_msg_session::recv_msg(const string &message, t_text_format format) {
	messages.push_back(t_msg(message, im::MSG_DIR_IN, format));
	new_message_added = true;
	notify();
}

void t_msg_session::send_msg(const string &message, t_text_format format) {
	messages.push_back(t_msg(message, im::MSG_DIR_OUT, format));
	new_message_added = true;
	phone->pub_send_message(user_config, remote_party.url, remote_party.display, message);
	msg_in_flight = true;
	notify();
}

void t_msg_session::set_error(const string &message) {
	error_msg = message;
	error_recvd = true;
	notify();
}

bool t_msg_session::error_received(void) const {
	return error_recvd;
}

string t_msg_session::take_error(void) {
	if (!error_recvd) return "";
	error_recvd = false;
	return error_msg;
}

void t_msg_session::set_delivery_notification(const string &notification) {
	delivery_notification = notification;
	delivery_notification_recvd = true;
	notify();
}

bool t_msg_session::delivery_notification_received(void) const {
	return delivery_notification_recvd;
}

string t_msg_session::take_delivery_notification(void) {
	if (!delivery_notification_recvd) return "";
	delivery_notification_recvd = false;
	return delivery_notification;
}

bool t_msg_session::match(t_user *user, t_url _remote_party) {
	return user == user_config && _remote_party == remote_party.url;
}

void t_msg_session::set_msg_in_flight(bool in_flight) {
	msg_in_flight = in_flight;
	notify();
}

bool t_msg_session::is_msg_in_flight(void) const {
	return msg_in_flight;
}
