/*
    Copyright (C) 2005-2007  Michel de Boer <michel@twinklephone.com>

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
#include "abstract_dialog.h"

enum t_subscription_role {
	SR_SUBSCRIBER,
	SR_NOTIFIER
};

enum t_subscription_state {
	SS_NULL,		// Initial state
	SS_ESTABLISHED,		// Subscription is in place
	SS_UNSUBSCRIBING,	// A request to unsubscribe has been sent
	SS_UNSUBSCRIBED,	// An outoging unsubscribe was succesful.
				// Waiting for the final NOTIFY.
	SS_TERMINATED,		// Subscription ended
};

string t_subscription_state2str(t_subscription_state state);

class t_subscription {
protected:
	t_subscription_role	role;
	t_subscription_state	state;
	
	// When a subscriber subscription is terminated, this reason indicates
	// the reason conveyed in the NOTIFY, if any.
	string			reason_termination;
	
	// If the NOTIFY indicated that the subscriber may retry subscription at
	// a later time, then resubscribe_after indicates the number of seconds to wait.
	unsigned long		resubscribe_after;
	
	// Indicates if a re-subscribe may be done after a failure.
	bool			may_resubscribe;
	
	t_abstract_dialog	*dialog; // dialog owning the subscription
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
	
	// Subcription expiry for a SUBSCRIBE request
	unsigned long		subscription_expiry;
	
	// Default duration for a subscription
	unsigned long		default_duration;

	// Protect constructor from being used
	t_subscription() {};
	
	// Write event type and id to log file
	void log_event() const;

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

	t_subscription(t_abstract_dialog *_dialog, t_subscription_role _role,
			const string &_event_type);
	t_subscription(t_abstract_dialog *_dialog, t_subscription_role _role,
			const string &_event_type, const string &_event_id);
	virtual ~t_subscription();

	t_subscription_role get_role(void) const;
	t_subscription_state get_state(void) const;
	string get_reason_termination(void) const;
	unsigned long get_resubscribe_after(void) const;
	bool get_may_resubscribe(void) const;
	string get_event_type(void) const;
	string get_event_id(void) const;
	unsigned long get_expiry(void) const;

	// Receive requests
	// The return value indicates if processing is finished.
	// This way a subclass can first call the parent class method.
	// If the parent indicates that process is finished, then the child
	// does not need to further process.
	// Note that recv_subscribe return false if the SUBSCRIBE is valid. The
	// subscription timer will be started, but no response is sent. The subclass
	// MUST further handle the SUBSCRIBE, i.e. send a response and a NOTIFY.
	virtual bool recv_subscribe(t_request *r, t_tuid tuid, t_tid tid);
	
	// When the NOTIFY is valid, false is returned. The subclass MUST further
	// handle the NOTIFY, i.e. send a response.
	virtual bool recv_notify(t_request *r, t_tuid tuid, t_tid tid);

	// Receive responses
	// The return value indicates if processing is finished.
	virtual bool recv_response(t_response *r, t_tuid tuid, t_tid tid);
	virtual bool recv_notify_response(t_response *r, t_tuid tuid, t_tid tid);
	virtual bool recv_subscribe_response(t_response *r, t_tuid tuid, t_tid tid);

	// Process timeouts
	// The return value indicates if processing is finished.
	virtual bool timeout(t_subscribe_timer timer);
	
	// Match timer id with a running timer
	virtual bool match_timer(t_subscribe_timer timer, t_object_id id_timer) const;
	
	// Does incoming request match with event type and id?
	virtual bool match(t_request *r) const;

	bool is_pending(void) const;

	// Subscribe. If expires == 0, then the default duration is used.
	virtual void subscribe(unsigned long expires);
	
	// Unsubscribe
	virtual void unsubscribe(void);
	
	// Refresh subscription
	virtual void refresh_subscribe(void);
};

#endif
