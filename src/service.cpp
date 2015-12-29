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

#include <cassert>
#include "service.h"

void t_service::lock() {
	mtx_service.lock();
}

void t_service::unlock() {
	mtx_service.unlock();
}

t_service::t_service() {
	// Call redirection
	cf_always_active = false;
	cf_busy_active = false;
	cf_noanswer_active = false;

	// Do not disturb
	dnd_active = false;
	
	// Auto answer
	auto_answer_active = false;
}

bool t_service::multiple_services_active(void) {
	int num_services = 0;
	
	if (is_cf_active()) num_services++;
	if (is_dnd_active()) num_services++;
	if (is_auto_answer_active()) num_services++;
	
	if (num_services > 1) return true;
	
	return false;
}

void t_service::enable_cf(t_cf_type cf_type, const list<t_display_url> &cf_dest) {
	lock();

	switch (cf_type) {
	case CF_ALWAYS:
		cf_always_active = true;
		cf_always_dest = cf_dest;
		break;
	case CF_BUSY:
		cf_busy_active = true;
		cf_busy_dest = cf_dest;
		break;
	case CF_NOANSWER:
		cf_noanswer_active = true;
		cf_noanswer_dest = cf_dest;
		break;
	default:
		assert(false);
	}

	unlock();
}

void t_service::disable_cf(t_cf_type cf_type) {
	lock();

	switch (cf_type) {
	case CF_ALWAYS:
		cf_always_active = false;
		cf_always_dest.clear();
		break;
	case CF_BUSY:
		cf_busy_active = false;
		cf_busy_dest.clear();
		break;
	case CF_NOANSWER:
		cf_noanswer_active = false;
		cf_noanswer_dest.clear();
		break;
	default:
		assert(false);
	}

	unlock();
}

bool t_service::get_cf_active(t_cf_type cf_type, list<t_display_url> &dest) {
	bool active = false;

	lock();

	switch (cf_type) {
	case CF_ALWAYS:
		active = cf_always_active;
		dest = cf_always_dest;
		break;
	case CF_BUSY:
		active = cf_busy_active;
		dest = cf_busy_dest;
		break;
	case CF_NOANSWER:
		active = cf_noanswer_active;
		dest = cf_noanswer_dest;
		break;
	default:
		assert(false);
	}

	unlock();
	return active;
}

bool t_service::is_cf_active(void) {
	bool active = false;

	lock();
	active = cf_always_active || cf_busy_active || cf_noanswer_active;
	unlock();

	return active;
}

list<t_display_url> t_service::get_cf_dest(t_cf_type cf_type) {
	list<t_display_url> dest;

	lock();

	switch (cf_type) {
	case CF_ALWAYS:
		dest = cf_always_dest;
		break;
	case CF_BUSY:
		dest = cf_busy_dest;
		break;
	case CF_NOANSWER:
		dest = cf_noanswer_dest;
		break;
	default:
		assert(false);
	}

	unlock();
	return dest;
}

void t_service::enable_dnd(void) {
	lock();
	dnd_active = true;
	unlock();
}

void t_service::disable_dnd(void) {
	lock();
	dnd_active = false;
	unlock();
}

bool t_service::is_dnd_active(void) const {
	return dnd_active;
}

void t_service::enable_auto_answer(bool on) {
	lock();
	auto_answer_active = on;
	unlock();
}

bool t_service::is_auto_answer_active(void) const {
	return auto_answer_active;
}
