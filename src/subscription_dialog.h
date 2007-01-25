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
// Generic subscription dialog state for subscribers and notifiers
// For each event type this class should be subclassed.

#ifndef _SUBSCRIPTION_DIALOG_H
#define _SUBSCRIPTION_DIALOG_H

#include "abstract_dialog.h"
#include "subscription.h"

// Forward declaration
class t_phone_user;

class t_subscription_dialog : public t_abstract_dialog {
protected:
	// The subscription belonging to this dialog. Subclasses must
	// create the proper subscription.
	t_subscription		*subscription;
	
	// The phone user owning this dialog
	t_phone_user		*phone_user;
	
	// This class must be subclassed. The subclass must provide
	// a public constructor.
	t_subscription_dialog(t_phone_user *_phone_user);

	// Send a request
	virtual void send_request(t_request *r, t_tuid tuid);
	
	// Process a received SUBSCRIBE request
	virtual void process_subscribe(t_request *r, t_tuid tuid, t_tid tid);
	
	// Process a received NOTIFY request
	virtual void process_notify(t_request *r, t_tuid tuid, t_tid tid);
	
	// Process the response to the initial SUBSCRIBE.
	// Returns true, if no further processing is needed. This happens, when a
	// 423 Interval too brief response is received. Then this method sends a
	// new SUBSCRIBE.
	virtual bool process_initial_subscribe_response(t_response *r, t_tuid tuid, t_tid tid);

public:
	virtual ~t_subscription_dialog();
	
	// Create a request using the stored state information
	virtual t_request *create_request(t_method m);
	
	virtual t_subscription_dialog *copy(void) = 0;
	
	// Resend mid-dialog request with an authorization header containing
	// credentials for the challenge in the response. The response
	// must be a 401 or 407.
	// Returns false if credentials could not be determined.
	virtual bool resend_request_auth(t_response *resp);

	// Redirect mid-dialog request to the next destination
	// Returns false if there is no next destination.
	virtual bool redirect_request(t_response *resp);
	
	// Failover request to the next destination from DNS lookup.
	// Returns false if there is no next destination.
	virtual bool failover_request(t_response *resp);

	// Handle received events
	virtual void recvd_response(t_response *r, t_tuid tuid, t_tid tid);
	virtual void recvd_request(t_request *r, t_tuid tuid, t_tid tid);
	
	// Match request with dialog and subscription
	// Returns true if the request matches
	// Returns false if the request does not match. In this case the request
	// may match partially, i.e. the from-tag matches, but the to-tag does not.
	// In case of a partial match, partial is set to true.
	virtual bool match_request(t_request *r, bool &partial);
	
	// Get the state of the subscription
	t_subscription_state get_subscription_state(void) const;
	string get_reason_termination(void) const;
	unsigned long get_resubscribe_after(void) const;
	bool get_may_resubscribe(void) const;
	
	// Process timeouts
	// The return value indicates if processing is finished.
	virtual bool timeout(t_subscribe_timer timer);
	
	// Match a timer id with a running timer
	virtual bool match_timer(t_subscribe_timer timer, t_object_id id_timer) const;
	
	virtual void subscribe(unsigned long expires, const t_url &req_uri, 
			const t_url &to_uri, const string &to_display);
	virtual void unsubscribe(void);
	virtual void refresh_subscribe(void);
};

#endif
