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

// RFC 3265
// Generic subscription state for subscribers and notifiers
// For each event type this class should be subclassed.

#ifndef _SUBSCRIPTION_H
#define _SUBSCRIPTION_H

#include <queue>
#include <string>
#include "dialog.h"

enum t_subscription_role {
	SR_SUBSCRIBER,
	SR_NOTIFIER
};

enum t_subscription_state {
	SS_NULL,		// Initial state
	SS_ESTABLISHED,		// Subscription is in place
	SS_UNSUBSCRIBED,	// An outoging unsubscribe was succesful.
				// Waiting for the final NOTIFY.
	SS_TERMINATED,		// Subscription ended
};

class t_subscription {
protected:
	t_subscription_role	role;
	t_subscription_state	state;
	t_dialog		*dialog; // dialog owning the subscription
	string			event_type;
	string			event_id;
	
	// User profile of user using the line
	// This is a pointer to the user_config owned by a phone user.
	// So this pointer should never be deleted.
	t_user			*user_config;

	bool			pending; // indicates if not active yet

	// Timers
	// For a subscriber the subscription_timeout timer indicates when
	// the subscription must be refreshed.
	// For a notifier it indicates when the subscription expires.
	unsigned short		id_subscription_timeout;

	// Indicates if a subscriber automatically refreshes the subscritption
	// when the subscription timer expires. If not, then the subscription
	// terminates at expiry.
	bool			auto_refresh;

	// Protect constructor from being used
	t_subscription() {};

	// Remove a pending request. Pass one of the client request pointers.
	void remove_client_request(t_client_request **cr);

	// Create requests based on the event type
	// Creating a subscribe is for subscription refreshment/unsubscribe.
	virtual t_request *create_subscribe(unsigned long expires) const;
	virtual t_request *create_notify(const string &sub_state,
		const string &reason = "") const;

	void send_request(t_user *user_config, t_request *r, t_tuid tuid) const;
	void send_response(t_user *user_config, t_response *r, t_tuid tuid, t_tid tid) const;

	void start_timer(t_subscribe_timer timer, long duration);
	void stop_timer(t_subscribe_timer timer);

public:
	// Pending request
	t_client_request	*req_out;

	// Queue of pending outgoing NOTIFY requests. A next NOTIFY
	// will only be sent after the previous NOTIFY has been
	// answered.
	queue<t_request *>	queue_notify;

	t_subscription(t_dialog *_dialog, t_subscription_role _role);
	t_subscription(t_dialog *_dialog, t_subscription_role _role,
			const string &_event_id);
	virtual ~t_subscription();

	t_subscription_role get_role(void) const;
	t_subscription_state get_state(void) const;
	string get_event_type(void) const;
	string get_event_id(void) const;

	// Receive requests
	// The return value indicates if processing is finished.
	// This way a subclass can first call the parent class method.
	// If the parent indicates that process is finished, then the child
	// does not need to further process.
	virtual bool recv_subscribe(t_request *r, t_tuid tuid, t_tid tid);
	virtual bool recv_notify(t_request *r, t_tuid tuid, t_tid tid);

	// Receive responses
	// The return value indicates if processing is finished.
	virtual bool recv_response(t_response *r, t_tuid tuid, t_tid tid);
	virtual bool recv_notify_response(t_response *r, t_tuid tuid, t_tid tid);
	virtual bool recv_subscribe_response(t_response *r, t_tuid tuid, t_tid tid);

	// Process timeouts
	// The return value indicates if processing is finished.
	virtual bool timeout(t_subscribe_timer timer);

	// Does incoming request match with event type and id?
	virtual bool match(t_request *r) const;

	bool is_pending(void) const;

	virtual void unsubscribe(void);
	virtual void refresh_subscribe(unsigned long expires);
};

#endif
