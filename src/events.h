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

#ifndef _EVENTS_H
#define _EVENTS_H

#include <queue>
#include "timekeeper.h"
#include "parser/sip_message.h"
#include "threads/mutex.h"
#include "threads/sema.h"

using namespace std;

// Different types of events
enum t_event_type {
	EV_NETWORK,	// Network event, eg. SIP message from/to network
	EV_USER,	// User event, eg. SIP message from/to user
	EV_TIMEOUT,	// Timer expiry
	EV_FAILURE,	// Failure, eg. transport failure
	EV_START_TIMER,	// Start timer
	EV_STOP_TIMER,	// Stop timer
	EV_ABORT_TRANS	// Abort transaction
};

///////////////////////////////////////////////////////////////
// Abstract parent class for all events
///////////////////////////////////////////////////////////////
class t_event {
public:
	virtual ~t_event() {}
	virtual t_event_type get_type(void) const = 0;
};

///////////////////////////////////////////////////////////////
// Network events
///////////////////////////////////////////////////////////////
class t_event_network : public t_event {
private:
	// Pointer to the received SIP message.
	t_sip_message	*msg;

public:
	// Address and ports are in host order
	unsigned int	src_addr;
	unsigned short	src_port;
	unsigned int	dst_addr;
	unsigned short	dst_port;

	// The event will keep a copy of the SIP message
	t_event_network(t_sip_message *m);
	~t_event_network();
	t_event_type get_type(void) const;
	t_sip_message *get_msg(void) const;
};
///////////////////////////////////////////////////////////////
// User events
///////////////////////////////////////////////////////////////
class t_event_user : public t_event {
private:
	t_sip_message	*msg;
	unsigned short	tuid;		// transaction user id
	unsigned short	tid;		// transaction id

	// Transaction id that is the target of the CANCEL message.
	// Only set if tid is a CANCEL transaction and the event
	// is sent towards the user.
	unsigned short	tid_cancel_target;

public:
	t_event_user(t_sip_message *m, unsigned short _tuid,
		unsigned short _tid);
	t_event_user(t_sip_message *m, unsigned short _tuid,
		unsigned short _tid, unsigned short _tid_cancel_target);
	~t_event_user();
	t_event_type get_type(void) const;
	t_sip_message *get_msg(void) const;
	unsigned short get_tuid(void) const;
	unsigned short get_tid(void) const;
	unsigned short get_tid_cancel_target(void) const;
};

///////////////////////////////////////////////////////////////
// Time out events
///////////////////////////////////////////////////////////////
class t_event_timeout : public t_event {
private:
	// Timer pointer will be deleted upon destruction of the object.
	t_timer		*timer;

public:
	// The event will keep a copy of the timer
	t_event_timeout(t_timer *t);
	~t_event_timeout();
	t_event_type get_type(void) const;
	t_timer *get_timer(void) const;
};

///////////////////////////////////////////////////////////////
// Failure events
///////////////////////////////////////////////////////////////
enum t_failure {
	FAIL_TIMEOUT,	// Transaction timed out
	FAIL_TRANSPORT	// Transport failure
};

class t_event_failure : public t_event {
private:
	t_failure	failure;
	unsigned short	tid;
public:
	t_event_failure(t_failure f, unsigned short _tid);
	t_event_type get_type(void) const;
	t_failure get_failure(void) const;
	unsigned short get_tid(void) const;
};

///////////////////////////////////////////////////////////////
// Start timer event
///////////////////////////////////////////////////////////////
class t_event_start_timer : public t_event {
private:
	t_timer		*timer;

public:
	t_event_start_timer(t_timer *t);
	t_event_type get_type(void) const;
	t_timer *get_timer(void) const;
};

///////////////////////////////////////////////////////////////
// Stop timer event
///////////////////////////////////////////////////////////////
class t_event_stop_timer : public t_event {
private:
	unsigned short	timer_id;

public:
	t_event_stop_timer(unsigned short id);
	t_event_type get_type(void) const;
	unsigned short get_timer_id(void) const;
};

///////////////////////////////////////////////////////////////
// Abort transaction events
///////////////////////////////////////////////////////////////
class t_event_abort_trans : public t_event {
private:
	unsigned short	tid; // transaction id
public:
	t_event_abort_trans(unsigned short _tid);
	t_event_type get_type(void) const;
	unsigned short get_tid(void) const;
};


///////////////////////////////////////////////////////////////
// Event queue
///////////////////////////////////////////////////////////////
//
// An event queue is the communication pipe between multiple
// threads. Multiple threads write events into the queue and
// one thread reads the events from the queue and processes them
// Access to the queue is protected by a mutex. A semaphore is
// used to synchronize the reader with the writers of the queue.
class t_event_queue {
private:
	queue<t_event *>	ev_queue;
	t_mutex			mutex_evq;
	t_semaphore		sema_evq;

	// Will be posted when the interrupt method is called.
	t_semaphore		sema_caught_interrupt;

public:
	t_event_queue();
	~t_event_queue();

	// Push an event into the queue
	void push(t_event *e);

	// Create a network event and push it into the queue
	void push_network(t_sip_message *m, unsigned long ipaddr,
		unsigned short port);

	// Create a user event and push it into the queue
	void push_user(t_sip_message *m, unsigned short tuid,
		unsigned short tid);

	// Create a cancel event for a user
	void push_user_cancel(t_sip_message *m, unsigned short tuid,
		unsigned short tid, unsigned short target_tid);

	// Create a timeout event and push it into the queue
	void push_timeout(t_timer *t);

	// Create failure event and push it into the queue
	void push_failure(t_failure f, unsigned short tid);

	// Create a start timer event
	void push_start_timer(t_timer *t);

	// Create a stop timer event
	void push_stop_timer(unsigned short timer_id);

	// Create an abort transaction event
	void push_abort_trans(unsigned short tid);

	// Pop an event from the queue. If the queue is empty
	// then the thread will be blocked until an event arrives.
	t_event *pop(void);

	// Same method as above, but this one can be interrupted by
	// calling the method interrupt.
	// When interrupted, pop returns NULL and the interrupted parameter
	// is set to true.
	// For a normal return of pop the interrupted parameter is false.
	t_event *pop(bool &interrupted);

	// Send an interrupt. This will cause the interruptable pop to return.
	// A non-interruptable pop will ignore the interrupt.
	// If pop is currently not suspending the thread execution then the
	// next call to pop will catch the interrupt.
	void interrupt(void);
};

#endif
