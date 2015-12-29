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

#include <iostream>
#include "events.h"
#include "log.h"
#include "util.h"
#include "audits/memman.h"

string event_type2str(t_event_type t) {
	switch(t) {
	case EV_NETWORK: 	return "EV_NETWORK";
	case EV_USER: 		return "EV_USER";
	case EV_TIMEOUT: 	return "EV_TIMEOUT";
	case EV_FAILURE: 	return "EV_FAILURE";
	case EV_START_TIMER: 	return "EV_START_TIMER";
	case EV_STOP_TIMER: 	return "EV_STOP_TIMER";
	case EV_ABORT_TRANS:	return "EV_ABORT_TRANS";
	}

	return "UNKNOWN";
}

///////////////////////////////////////////////////////////
// class t_event_network
///////////////////////////////////////////////////////////

t_event_network::t_event_network(t_sip_message *m) : t_event() {
	msg = m->copy();
	src_addr = 0;
	src_port = 0;
	dst_addr = 0;
	dst_port = 0;
}

t_event_network::~t_event_network() {
	MEMMAN_DELETE(msg);
	delete msg;
}

t_event_type t_event_network::get_type(void) const {
	return EV_NETWORK;
}

t_sip_message *t_event_network::get_msg(void) const {
	return msg;
}

///////////////////////////////////////////////////////////
// class t_event_user
///////////////////////////////////////////////////////////

t_event_user::t_event_user(t_sip_message *m, unsigned short _tuid,
		unsigned short _tid) : t_event()
{
	msg = m->copy();
	tuid = _tuid;
	tid = _tid;
	tid_cancel_target = 0;
}

t_event_user::t_event_user(t_sip_message *m, unsigned short _tuid,
		unsigned short _tid, unsigned short _tid_cancel_target) :
			t_event()
{
	msg = m->copy();
	tuid = _tuid;
	tid = _tid;
	tid_cancel_target = _tid_cancel_target;
}

t_event_user::~t_event_user() {
	MEMMAN_DELETE(msg);
	delete msg;
}

t_event_type t_event_user::get_type(void) const {
	return EV_USER;
}

t_sip_message *t_event_user::get_msg(void) const {
	return msg;
}

unsigned short t_event_user::get_tuid(void) const {
	return tuid;
}

unsigned short t_event_user::get_tid(void) const {
	return tid;
}

unsigned short t_event_user::get_tid_cancel_target(void) const {
	return tid_cancel_target;
}

///////////////////////////////////////////////////////////
// class t_event_timeout
///////////////////////////////////////////////////////////

t_event_timeout::t_event_timeout(t_timer *t) : t_event() {
	timer = t->copy();
}

t_event_timeout::~t_event_timeout() {
	MEMMAN_DELETE(timer);
	delete timer;
}

t_event_type t_event_timeout::get_type(void) const {
	return EV_TIMEOUT;
}

t_timer *t_event_timeout::get_timer(void) const {
	return timer;
}

///////////////////////////////////////////////////////////
// class t_event_failure
///////////////////////////////////////////////////////////
t_event_failure::t_event_failure(t_failure f, unsigned short _tid) {
	failure = f;
	tid = _tid;
}

t_event_type t_event_failure::get_type(void) const {
	return EV_FAILURE;
}

t_failure t_event_failure::get_failure(void) const {
	return failure;
}

unsigned short t_event_failure::get_tid(void) const {
	return tid;
}

///////////////////////////////////////////////////////////
// class t_event_start_timer
///////////////////////////////////////////////////////////
t_event_start_timer::t_event_start_timer(t_timer *t) {
	timer = t->copy();
}

t_event_type t_event_start_timer::get_type(void) const {
	return EV_START_TIMER;
}

t_timer *t_event_start_timer::get_timer(void) const {
	return timer;
}

///////////////////////////////////////////////////////////
// class t_event_stop_timer
///////////////////////////////////////////////////////////
t_event_stop_timer::t_event_stop_timer(unsigned short id) {
	timer_id = id;
}

t_event_type t_event_stop_timer::get_type(void) const {
	return EV_STOP_TIMER;
}

unsigned short t_event_stop_timer::get_timer_id(void) const {
	return timer_id;
}

///////////////////////////////////////////////////////////
// class t_event_abort_trans
///////////////////////////////////////////////////////////
t_event_abort_trans::t_event_abort_trans(unsigned short _tid) {
	tid = _tid;
}

t_event_type t_event_abort_trans::get_type(void) const {
	return EV_ABORT_TRANS;
}

unsigned short t_event_abort_trans::get_tid(void) const {
	return tid;
}

///////////////////////////////////////////////////////////
// class t_event_queue
///////////////////////////////////////////////////////////

t_event_queue::t_event_queue() : sema_evq(0), sema_caught_interrupt(0) {}

t_event_queue::~t_event_queue() {
	log_file->write_header("t_event_queue::~t_event_queue", LOG_DEBUG, LOG_INFO);
	log_file->write_raw("Clean up event queue.\n");

	while (!ev_queue.empty())
	{
		t_event *e = ev_queue.front();
		ev_queue.pop();
		log_file->write_raw("\nDeleting unproccessed event: \n");
		log_file->write_raw("Type: ");
		log_file->write_raw(event_type2str(e->get_type()));
		log_file->write_raw(", Pointer: ");
		log_file->write_raw(int2str(int(e), "0x%x"));
		log_file->write_endl();
		MEMMAN_DELETE(e);
		delete e;
	}

	log_file->write_footer();
}

void t_event_queue::push(t_event *e) {
	mutex_evq.lock();
	ev_queue.push(e);
	mutex_evq.unlock();
	sema_evq.up();
}

void t_event_queue::push_network(t_sip_message *m, unsigned long ipaddr,
		unsigned short port)
{
	t_event_network	*event = new t_event_network(m);
	MEMMAN_NEW(event);
	event->dst_addr = ipaddr;
	event->dst_port = port;
	push(event);
}

void t_event_queue::push_user(t_sip_message *m, unsigned short tuid,
		unsigned short tid)
{
	t_event_user *event = new t_event_user(m, tuid, tid);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_user_cancel(t_sip_message *m, unsigned short tuid,
		unsigned short tid, unsigned short target_tid)
{
	t_event_user *event = new t_event_user(m, tuid, tid, target_tid);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_timeout(t_timer *t) {
	t_event_timeout *event = new t_event_timeout(t);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_failure(t_failure f, unsigned short tid) {
	t_event_failure *event = new t_event_failure(f, tid);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_start_timer(t_timer *t) {
	t_event_start_timer *event = new t_event_start_timer(t);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_stop_timer(unsigned short timer_id) {
	t_event_stop_timer *event = new t_event_stop_timer(timer_id);
	MEMMAN_NEW(event);
	push(event);
}

void t_event_queue::push_abort_trans(unsigned short tid) {
	t_event_abort_trans *event = new t_event_abort_trans(tid);
	MEMMAN_NEW(event);
	push(event);
}

t_event *t_event_queue::pop(void) {
	t_event *e;
	bool interrupt;

	do {
		interrupt = false;
		sema_evq.down();
		mutex_evq.lock();

		if (sema_caught_interrupt.try_down()) {
			// This pop is non-interruptable, so ignore the interrupt
			interrupt = true;
		} else {
			e = ev_queue.front();
			ev_queue.pop();
		}

		mutex_evq.unlock();
	} while (interrupt);

	return e;
}

t_event *t_event_queue::pop(bool &interrupted) {
	t_event *e;

	sema_evq.down();
	mutex_evq.lock();

	if (sema_caught_interrupt.try_down()) {
		interrupted = true;
		e = NULL;
	} else {
		interrupted = false;
		e = ev_queue.front();
		ev_queue.pop();
	}

	mutex_evq.unlock();

	return e;
}

void t_event_queue::interrupt(void) {
	sema_caught_interrupt.up();
	sema_evq.up();
}
