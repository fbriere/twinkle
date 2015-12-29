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

/**
 * @file
 * Instant message session.
 * SIP does not have a concept of message sessions. It's up to the
 * user interface to create the illusion of a session by grouping
 * messages between 2 users.
 */

#ifndef _MSG_SESSION_H
#define _MSG_SESSION_H

#include <string>
#include <time.h>

#include "id_object.h"
#include "exceptions.h"
#include "user.h"
#include "sockets/url.h"
#include "patterns/observer.h"

using namespace std;

namespace im {

/** Message direction. */
enum t_direction {
	MSG_DIR_IN,	/**< Incoming. */
	MSG_DIR_OUT	/**< Outgoing. */
};

/** Text format. */
enum t_text_format {
	TXT_PLAIN,	/**< Plain */
	TXT_HTML,	/**< HTML */
};

/** Single message with meta information. */
class t_msg : public t_id_object {
public:
	string		message;	/**< The message. */
	t_direction	direction;	/**< Direction of the message. */
	time_t		timestamp;	/**< Timestamp of the message. */
	t_text_format	format;		/**< Text format. */
	
	/** Constructor. */
	t_msg();
	
	/**
	 * Constructor.
	 * Sets the timestamp to the current time.
	 * @param msg [in] The message.
	 * @param dir [in] Direction of the message.
	 * @param fmt [in] Text format of the message.
	 */
	t_msg(const string &msg, t_direction dir, t_text_format fmt);
};

/** 
 * Message session. 
 * It's up to the user interface to create a message session and store
 * all messages in it. The session is just a container to store a
 * collection of page-mode messages.
 */
class t_msg_session : public patterns::t_subject {
private:
	t_user		*user_config;	/**< User profile of the local user. */
	t_display_url	remote_party;	/**< Remote party. */
	list<t_msg>	messages;	/**< Messages sent/received. */
	
	/** Indicates if a new message has been added to the list of message. */
	bool		new_message_added;
	
	bool		error_recvd;	/**< Indicates that an error has been received. */
	string		error_msg;	/**< Received error message. */
	
	/** Indicates that a delivery notification has been received. */
	bool		delivery_notification_recvd;
	
	/** Received delivery notification. */
	string		delivery_notification;
	
	bool		msg_in_flight;	/**< Indicates if an outgoing message is in flight. */
	
public:
	/**
	 * Constructor.
	 * @param u [in] User profile of the local user.
	 */
	t_msg_session(t_user *u);

	/**
	 * Constructor.
	 * @param u [in] User profile of the local user.
	 * @param _remote_party [in] URL of remote party.
	 */
	t_msg_session(t_user *u, t_display_url _remote_party);
	
	/** @name getters */
	//@{
	t_user *get_user(void) const;
	t_display_url get_remote_party(void) const;
	const list<t_msg> &get_messages(void) const;
	//@}
	
	/** @name setters */
	//@{
	void set_user(t_user *u);
	void set_remote_party(const t_display_url &du);
	//@}
	
	/**
	 * Get the last message of the session.
	 * @return The last message.
	 * @throws empty_list_exception  There are no messages.
	 */
	t_msg get_last_message(void);
	
	/** Check if a new message has been added. */
	bool is_new_message_added(void) const;
	
	/**
	 * Set the display name of the remote party if it is not yet set.
	 * @param display [in] The display name to set.
	 */
	void set_display_if_empty(const string &display);
	
	/**
	 * Add a received message to the session.
	 * @param message [in] The message.
	 * @param format [in] Text format of the message.
	 */
	void recv_msg(const string &message, t_text_format format);
	
	/**
	 * Send a message to the remote party.
	 * The message will be added to the list of messages.
	 * @param message [in] Message to be sent.
	 * @param format [in] Text format of the message.
	 */
	void send_msg(const string &message, t_text_format format);
	
	/**
	 * Set the error message of the session.
	 * @param message [in] Error message.
	 * @post @ref error_msg == message
	 * @post @ref error_recvd == true
	 */
	void set_error(const string &message);
	
	/**
	 * Check if an error has been received.
	 * @return true, if an error has been received.
	 * @return false, otherwise
	 */
	bool error_received(void) const;
	
	/**
	 * Take the error message from the session.
	 * @return Error message.
	 * @pre @ref error_received() == true
	 * @post @ref error_received() == false
	 */
	string take_error(void);
	
	/**
	 * Set the delivery notification of the session.
	 * @param notification [in] Delivery notification.
	 * @post @ref delivery_notification == notification
	 * @post @ref delivery_notification_recvd == true
	 */
	void set_delivery_notification(const string &notification);
	
	/**
	 * Check if a delivery notification has been received.
	 * @return true, if an error has been received.
	 * @return false, otherwise
	 */
	bool delivery_notification_received(void) const;
	
	/**
	 * Take the delivery notification from the session.
	 * @return Delivery notification.
	 * @pre @ref delivery_notification_received() == true
	 * @post @ref delivery_notification_received() == false
	 */
	string take_delivery_notification(void);
	
	/**
	 * Check if the session matches with a particular user and
	 * remote party.
	 * @param user [in] The user
	 * @param remote_party [in] URL of the remote party
	 * @return true, if there is a match
	 * @return false, otherwise
	 */
	bool match(t_user *user, t_url _remote_party);
	
	/**
	 * Set the message in flight indicator.
	 * @param in_flight [in] Indicator value to set.
	 */
	void set_msg_in_flight(bool in_flight);
	
	/**
	 * Check if a message is in flight.
	 * @return true, message is in flight.
	 * @return false, no message is in flight.
	 */
	bool is_msg_in_flight(void) const;
};

}; // end namespace

#endif
