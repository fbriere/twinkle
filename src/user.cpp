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
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <list>
#include "log.h"
#include "phone.h"
#include "twinkle_config.h"
#include "user.h"
#include "userintf.h"
#include "util.h"
#include "protocol.h"
#include "audits/memman.h"
#include "sdp/sdp.h"
#include "parser/parse_ctrl.h"
#include "parser/request.h"

extern t_phone		*phone;

// Field names in the config file
// USER fields
#define FLD_NAME			"user_name"
#define FLD_DOMAIN			"user_domain"
#define FLD_DISPLAY			"user_display"
#define	FLD_ORGANIZATION		"user_organization"
#define FLD_AUTH_REALM			"auth_realm"
#define FLD_AUTH_NAME			"auth_name"
#define FLD_AUTH_PASS			"auth_pass"

// SIP SERVER fields
#define FLD_OUTBOUND_PROXY		"outbound_proxy"
#define FLD_ALL_REQUESTS_TO_PROXY	"all_requests_to_proxy"
#define FLD_NON_RESOLVABLE_TO_PROXY	"non_resolvable_to_proxy"
#define FLD_REGISTRAR			"registrar"
#define FLD_REGISTRATION_TIME		"registration_time"
#define FLD_REGISTER_AT_STARTUP		"register_at_startup"

// AUDIO fields
#define FLD_CODECS			"codecs"
#define FLD_PTIME			"ptime"
#define FLD_SPEEX_NB_PAYLOAD_TYPE	"speex_nb_payload_type"
#define FLD_SPEEX_WB_PAYLOAD_TYPE	"speex_wb_payload_type"
#define FLD_SPEEX_UWB_PAYLOAD_TYPE	"speex_uwb_payload_type"
#define FLD_SPEEX_BIT_RATE_TYPE		"speex_bit_rate_type"
#define FLD_SPEEX_ABR_NB		"speex_abr_nb"
#define FLD_SPEEX_ABR_WB		"speex_abr_wb"
#define FLD_SPEEX_VAD			"speex_vad"
#define FLD_SPEEX_DTX			"speex_dtx"
#define FLD_SPEEX_PENH			"speex_penh"
#define FLD_SPEEX_COMPLEXITY		"speex_complexity"
#define FLD_ILBC_PAYLOAD_TYPE		"ilbc_payload_type"
#define FLD_ILBC_MODE			"ilbc_mode"
#define FLD_DTMF_TRANSPORT		"dtmf_transport"
#define FLD_DTMF_PAYLOAD_TYPE		"dtmf_payload_type"
#define FLD_DTMF_DURATION		"dtmf_duration"
#define FLD_DTMF_PAUSE			"dtmf_pause"
#define FLD_DTMF_VOLUME			"dtmf_volume"

// SIP PROTOCOL fields
#define FLD_HOLD_VARIANT		"hold_variant"
#define FLD_CHECK_MAX_FORWARDS		"check_max_forwards"
#define FLD_ALLOW_MISSING_CONTACT_REG	"allow_missing_contact_reg"	
#define FLD_REGISTRATION_TIME_IN_CONTACT	"registration_time_in_contact"
#define FLD_COMPACT_HEADERS		"compact_headers"
#define FLD_ENCODE_MULTI_VALUES_AS_LIST	"encode_multi_values_as_list"
#define FLD_USE_DOMAIN_IN_CONTACT	"use_domain_in_contact"
#define FLD_ALLOW_SDP_CHANGE		"allow_sdp_change"
#define FLD_ALLOW_REDIRECTION		"allow_redirection"
#define FLD_ASK_USER_TO_REDIRECT	"ask_user_to_redirect"
#define FLD_MAX_REDIRECTIONS		"max_redirections"
#define FLD_EXT_100REL			"ext_100rel"
#define FLD_REFEREE_HOLD		"referee_hold"
#define FLD_REFERRER_HOLD		"referrer_hold"
#define FLD_ALLOW_REFER			"allow_refer"
#define FLD_ASK_USER_TO_REFER		"ask_user_to_refer"
#define FLD_AUTO_REFRESH_REFER_SUB	"auto_refresh_refer_sub"

// NAT fields
#define FLD_NAT_PUBLIC_IP		"nat_public_ip"
#define FLD_STUN_SERVER			"stun_server"

// TIMER fields
#define FLD_TIMER_NOANSWER		"timer_noanswer"
#define FLD_TIMER_NAT_KEEPALIVE		"timer_nat_keepalive"

// ADDRESS FORMAT fields
#define FLD_DISPLAY_USERONLY_PHONE	"display_useronly_phone"
#define FLD_NUMERICAL_USER_IS_PHONE	"numerical_user_is_phone"
#define FLD_REMOVE_SPECIAL_PHONE_SYM	"remove_special_phone_symbols"
#define FLD_SPECIAL_PHONE_SYMBOLS	"special_phone_symbols"

// Ring tone settings
#define FLD_USER_RINGTONE_FILE		"ringtone_file"
#define FLD_USER_RINGBACK_FILE		"ringback_file"

// Incoming call script
#define FLD_SCRIPT_INCOMING_CALL	"script_incoming_call"
#define FLD_SCRIPT_IN_CALL_ANSWERED	"script_in_call_answered"
#define FLD_SCRIPT_IN_CALL_FAILED	"script_in_call_failed"
#define FLD_SCRIPT_OUTGOING_CALL	"script_outgoing_call"
#define FLD_SCRIPT_OUT_CALL_ANSWERED	"script_out_call_answered"
#define FLD_SCRIPT_OUT_CALL_FAILED	"script_out_call_failed"
#define FLD_SCRIPT_LOCAL_RELEASE	"script_local_release"
#define FLD_SCRIPT_REMOTE_RELEASE	"script_remote_release"

// Number conversion
#define FLD_NUMBER_CONVERSION		"number_conversion"

/////////////////////////
// class t_user
/////////////////////////

////////////////////
// Private
////////////////////

t_ext_support t_user::str2ext_support(const string &s) const {
	if (s == "disabled") return EXT_DISABLED;
	if (s == "supported") return EXT_SUPPORTED;
	if (s == "preferred") return EXT_PREFERRED;
	if (s == "required") return EXT_REQUIRED;
	return EXT_INVALID;
}

string t_user::ext_support2str(t_ext_support e) const {
	switch(e) {
	case EXT_INVALID:	return "invalid";
	case EXT_DISABLED:	return "disabled";
	case EXT_SUPPORTED:	return "supported";
	case EXT_PREFERRED:	return "preferred";
	case EXT_REQUIRED:	return "required";
	default:
		assert(false);
	}

	return "";
}

t_bit_rate_type t_user::str2bit_rate_type(const string &s) const {
	if (s == "cbr") return BIT_RATE_CBR;
	if (s == "vbr") return BIT_RATE_VBR;
	if (s == "abr") return BIT_RATE_ABR;
	return BIT_RATE_INVALID;
}

string t_user::bit_rate_type2str(t_bit_rate_type b) const {
	switch (b) {
	case BIT_RATE_INVALID:	return "invalid";
	case BIT_RATE_CBR:	return "cbr";
	case BIT_RATE_VBR:	return "vbr";
	case BIT_RATE_ABR:	return "abr";
	default:
		assert(false);
	}
}

t_dtmf_transport t_user::str2dtmf_transport(const string &s) const {
	if (s == "inband") return DTMF_INBAND;
	if (s == "rfc2833") return DTMF_RFC2833;
	if (s == "auto") return DTMF_AUTO;
	return DTMF_AUTO;
}

string t_user::dtmf_transport2str(t_dtmf_transport d) const {
	switch (d) {
	case DTMF_INBAND:	return "inband";
	case DTMF_RFC2833:	return "rfc2833";
	case DTMF_AUTO:		return "auto";
	default:
		assert(false);
	}
}

string t_user::expand_filename(const string &filename) {
	string f;

	if (filename[0] == '/') {
		f = filename;
	} else {
        	f = string(DIR_HOME);
        	f += "/";
        	f += USER_DIR;
        	f += "/";
        	f += filename;
	}

	return f;
}

bool t_user::parse_num_conversion(const string &value, t_number_conversion &c) {
	list<string> l = split_escaped(value, ',');
	
	if (l.size() != 2) {
		// Invalid conversion rule
		return false;
	}
	
	try {
		c.re.assign(l.front());
		c.fmt = l.back();
	} catch (boost::bad_expression) {
		// Invalid regular expression
		log_file->write_header("t_user::parse_num_conversion", 
				LOG_NORMAL, LOG_WARNING);
		log_file->write_raw("Bad number conversion:\n");
		log_file->write_raw(l.front());
		log_file->write_raw(" --> ");
		log_file->write_raw(l.back());
		log_file->write_endl();
		log_file->write_footer();
		
		return false;
	}
	
	return true;
}


////////////////////
// Public
////////////////////

t_user::t_user() {
	// Set defaults
	use_outbound_proxy = false;
	all_requests_to_proxy = false;
	non_resolvable_to_proxy = false;
	use_registrar = false;
	registration_time = 3600;
#ifdef HAVE_SPEEX
	codecs.push_back(CODEC_SPEEX_WB);
	codecs.push_back(CODEC_SPEEX_NB);
#endif
#ifdef HAVE_ILBC
	codecs.push_back(CODEC_ILBC);
#endif
	codecs.push_back(CODEC_G711_ALAW);
	codecs.push_back(CODEC_G711_ULAW);
	codecs.push_back(CODEC_GSM);
	ptime = 20;
	hold_variant = HOLD_RFC3264;
	use_nat_public_ip = false;
	use_stun = false;
	register_at_startup = true;
	check_max_forwards = false;
	allow_missing_contact_reg = true;
	compact_headers = false;
	encode_multi_values_as_list = true;
	registration_time_in_contact = true;
	use_domain_in_contact = false;
	allow_sdp_change = false;
	allow_redirection = true;
	ask_user_to_redirect = true;
	max_redirections = 5;
	timer_noanswer = 30;
	timer_nat_keepalive = DUR_NAT_KEEPALIVE;
	ext_100rel = EXT_SUPPORTED;
	speex_nb_payload_type = 97;
	speex_wb_payload_type = 98;
	speex_uwb_payload_type = 99;
	speex_bit_rate_type = BIT_RATE_CBR;
	speex_abr_nb = 0;
	speex_abr_wb = 0;
	speex_vad = true;
	speex_dtx = false;
	speex_penh = true;
	speex_complexity = 2;
	ilbc_payload_type = 96;
	ilbc_mode = 30;
	dtmf_transport = DTMF_AUTO;
	dtmf_duration = 100;
	dtmf_pause = 40;
	dtmf_payload_type = 101;
	dtmf_volume = 10;
	display_useronly_phone = true;
	numerical_user_is_phone = false;
	remove_special_phone_symbols = true;
	special_phone_symbols = SPECIAL_PHONE_SYMBOLS;
	referee_hold = false;
	referrer_hold = true;
	allow_refer = true;
	ask_user_to_refer = true;
	auto_refresh_refer_sub = false;
	ringtone_file.clear();
	ringback_file.clear();
	script_incoming_call.clear();
	script_in_call_answered.clear();
	script_in_call_failed.clear();
	script_outgoing_call.clear();
	script_out_call_answered.clear();
	script_out_call_failed.clear();
	script_local_release.clear();
	script_remote_release.clear();
	number_conversions.clear();
}

t_user::t_user(const t_user &u) {
	u.mtx_user.lock();

	config_filename = u.config_filename;
	name = u.name;
	domain = u.domain;
	display = u.display;	
	organization = u.organization;
	auth_realm = u.auth_realm;
	auth_name = u.auth_name;
	auth_pass = u.auth_pass;
	use_outbound_proxy = u.use_outbound_proxy;
	outbound_proxy = u.outbound_proxy;
	all_requests_to_proxy = u.all_requests_to_proxy;
	non_resolvable_to_proxy = u.non_resolvable_to_proxy;
	use_registrar = u.use_registrar;
	registrar = u.registrar;
	registration_time = u.registration_time;
	register_at_startup = u.register_at_startup;
	codecs = u.codecs;
	ptime = u.ptime;
	speex_nb_payload_type = u.speex_nb_payload_type;
	speex_wb_payload_type = u.speex_wb_payload_type;
	speex_uwb_payload_type = u.speex_uwb_payload_type;
	speex_bit_rate_type = u.speex_bit_rate_type;
	speex_abr_nb = u.speex_abr_nb;
	speex_abr_wb = u.speex_abr_wb;
	speex_vad = u.speex_vad;
	speex_dtx = u.speex_dtx;
	speex_penh = u.speex_penh;
	speex_complexity = u.speex_complexity;
	ilbc_payload_type = u.ilbc_payload_type;
	ilbc_mode = u.ilbc_mode;
	dtmf_transport = u.dtmf_transport;
	dtmf_payload_type = u.dtmf_payload_type;
	dtmf_duration = u.dtmf_duration;
	dtmf_pause = u.dtmf_pause;
	dtmf_volume = u.dtmf_volume;
	hold_variant = u.hold_variant;
	check_max_forwards = u.check_max_forwards;
	allow_missing_contact_reg = u.allow_missing_contact_reg;
	registration_time_in_contact = u.registration_time_in_contact;
	compact_headers = u.compact_headers;
	encode_multi_values_as_list = u.encode_multi_values_as_list;
	use_domain_in_contact = u.use_domain_in_contact;
	allow_sdp_change = u.allow_sdp_change;
	allow_redirection = u.allow_redirection;
	ask_user_to_redirect = u.ask_user_to_redirect;
	max_redirections = u.max_redirections;
	ext_100rel = u.ext_100rel;
	referee_hold = u.referee_hold;
	referrer_hold = u.referrer_hold;
	allow_refer = u.allow_refer;
	ask_user_to_refer = u.ask_user_to_refer;
	auto_refresh_refer_sub = u.auto_refresh_refer_sub;
	use_nat_public_ip = u.use_nat_public_ip;
	nat_public_ip = u.nat_public_ip;
	use_stun = u.use_stun;
	stun_server = u.stun_server;
	timer_noanswer = u.timer_noanswer;
	timer_nat_keepalive = u.timer_nat_keepalive; 
	display_useronly_phone = u.display_useronly_phone;
	numerical_user_is_phone = u.numerical_user_is_phone;
	remove_special_phone_symbols = u.remove_special_phone_symbols;
	special_phone_symbols = u.special_phone_symbols;
	ringtone_file = u.ringtone_file;
	ringback_file = u.ringback_file;
	script_incoming_call = u.script_incoming_call;
	script_in_call_answered = u.script_in_call_answered;
	script_in_call_failed = u.script_in_call_failed;
	script_outgoing_call = u.script_outgoing_call;
	script_out_call_answered = u.script_out_call_answered;
	script_out_call_failed = u.script_out_call_failed;
	script_local_release = u.script_local_release;
	script_remote_release = u.script_remote_release;
	number_conversions = u.number_conversions;
	
	u.mtx_user.unlock();
}

t_user *t_user::copy(void) const {
	t_user *u = new t_user(*this);
	MEMMAN_NEW(u);
	return u;
}

string t_user::get_name(void) const {
	string result;
	mtx_user.lock();
	result = name;
	mtx_user.unlock();
	return result;
}

string t_user::get_domain(void) const {
	string result;
	mtx_user.lock();
	result = domain;
	mtx_user.unlock();
	return result;
}

string t_user::get_display(void) const {
	string result;
	mtx_user.lock();
	result = display;
	mtx_user.unlock();
	return result;
}
	
string t_user::get_organization(void) const {
	string result;
	mtx_user.lock();
	result = organization;
	mtx_user.unlock();
	return result;
}

string t_user::get_auth_realm(void) const {
	string result;
	mtx_user.lock();
	result = auth_realm;
	mtx_user.unlock();
	return result;
}

string t_user::get_auth_name(void) const {
	string result;
	mtx_user.lock();
	result = auth_name;
	mtx_user.unlock();
	return result;
}

string t_user::get_auth_pass(void) const {
	string result;
	mtx_user.lock();
	result = auth_pass;
	mtx_user.unlock();
	return result;
}

bool t_user::get_use_outbound_proxy(void) const {
	bool result;
	mtx_user.lock();
	result = use_outbound_proxy;
	mtx_user.unlock();
	return result;
}

t_url t_user::get_outbound_proxy(void) const {
	t_url result;
	mtx_user.lock();
	result = outbound_proxy;
	mtx_user.unlock();
	return result;
}

bool t_user::get_all_requests_to_proxy(void) const {
	bool result;
	mtx_user.lock();
	result = all_requests_to_proxy;
	mtx_user.unlock();
	return result;
}

bool t_user::get_non_resolvable_to_proxy(void) const {
	bool result;
	mtx_user.lock();
	result = non_resolvable_to_proxy;
	mtx_user.unlock();
	return result;
}

bool t_user::get_use_registrar(void) const {
	bool result;
	mtx_user.lock();
	result = use_registrar;
	mtx_user.unlock();
	return result;
}

t_url t_user::get_registrar(void) const {
	t_url result;
	mtx_user.lock();
	result = registrar;
	mtx_user.unlock();
	return result;
}

unsigned long t_user::get_registration_time(void) const {
	unsigned long result;
	mtx_user.lock();
	result = registration_time;
	mtx_user.unlock();
	return result;
}

bool t_user::get_register_at_startup(void) const {
	bool result;
	mtx_user.lock();
	result = register_at_startup;
	mtx_user.unlock();
	return result;
}

list<t_audio_codec> t_user::get_codecs(void) const {
	list<t_audio_codec> result;
	mtx_user.lock();
	result = codecs;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_ptime(void) const {
	unsigned short result;
	mtx_user.lock();
	result = ptime;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_speex_nb_payload_type(void) const {
	unsigned short result;
	mtx_user.lock();
	result = speex_nb_payload_type;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_speex_wb_payload_type(void) const {
	unsigned short result;
	mtx_user.lock();
	result = speex_wb_payload_type;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_speex_uwb_payload_type(void) const {
	unsigned short result;
	mtx_user.lock();
	result = speex_uwb_payload_type;
	mtx_user.unlock();
	return result;
}

t_bit_rate_type t_user::get_speex_bit_rate_type(void) const {
	t_bit_rate_type result;
	mtx_user.lock();
	result = speex_bit_rate_type;
	mtx_user.unlock();
	return result;
}

int t_user::get_speex_abr_nb(void) const {
	int result;
	mtx_user.lock();
	result = speex_abr_nb;
	mtx_user.unlock();
	return result;
}

int t_user::get_speex_abr_wb(void) const {
	int result;
	mtx_user.lock();
	result = speex_abr_wb;
	mtx_user.unlock();
	return result;
}

bool t_user::get_speex_vad(void) const {
	bool result;
	mtx_user.lock();
	result = speex_vad;
	mtx_user.unlock();
	return result;
}

bool t_user::get_speex_dtx(void) const {
	bool result;
	mtx_user.lock();
	result = speex_dtx;
	mtx_user.unlock();
	return result;
}

bool t_user::get_speex_penh(void) const {
	bool result;
	mtx_user.lock();
	result = speex_penh;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_speex_complexity(void) const {
	unsigned short result;
	mtx_user.lock();
	result = speex_complexity;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_ilbc_payload_type(void) const {
	unsigned short result;
	mtx_user.lock();
	result = ilbc_payload_type;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_ilbc_mode(void) const {
	unsigned short result;
	mtx_user.lock();
	result = ilbc_mode;
	mtx_user.unlock();
	return result;
}

t_dtmf_transport t_user::get_dtmf_transport(void) const {
	t_dtmf_transport result;
	mtx_user.lock();
	result = dtmf_transport;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_dtmf_payload_type(void) const {
	unsigned short result;
	mtx_user.lock();
	result = dtmf_payload_type;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_dtmf_duration(void) const {
	unsigned short result;
	mtx_user.lock();
	result = dtmf_duration;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_dtmf_pause(void) const {
	unsigned short result;
	mtx_user.lock();
	result = dtmf_pause;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_dtmf_volume(void) const {
	unsigned short result;
	mtx_user.lock();
	result = dtmf_volume;
	mtx_user.unlock();
	return result;
}

t_hold_variant t_user::get_hold_variant(void) const {
	t_hold_variant result;
	mtx_user.lock();
	result = hold_variant;
	mtx_user.unlock();
	return result;
}

bool t_user::get_check_max_forwards(void) const {
	bool result;
	mtx_user.lock();
	result = check_max_forwards;
	mtx_user.unlock();
	return result;
}

bool t_user::get_allow_missing_contact_reg(void) const {
	bool result;
	mtx_user.lock();
	result = allow_missing_contact_reg;
	mtx_user.unlock();
	return result;
}

bool t_user::get_registration_time_in_contact(void) const {
	bool result;
	mtx_user.lock();
	result = registration_time_in_contact;
	mtx_user.unlock();
	return result;
}

bool t_user::get_compact_headers(void) const {
	bool result;
	mtx_user.lock();
	result = compact_headers;
	mtx_user.unlock();
	return result;
}

bool t_user::get_encode_multi_values_as_list(void) const {
	bool result;
	mtx_user.lock();
	result = encode_multi_values_as_list;
	mtx_user.unlock();
	return result;
}

bool t_user::get_use_domain_in_contact(void) const {
	bool result;
	mtx_user.lock();
	result = use_domain_in_contact;
	mtx_user.unlock();
	return result;
}

bool t_user::get_allow_sdp_change(void) const {
	bool result;
	mtx_user.lock();
	result = allow_sdp_change;
	mtx_user.unlock();
	return result;
}

bool t_user::get_allow_redirection(void) const {
	bool result;
	mtx_user.lock();
	result = allow_redirection;
	mtx_user.unlock();
	return result;
}

bool t_user::get_ask_user_to_redirect(void) const {
	bool result;
	mtx_user.lock();
	result = ask_user_to_redirect;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_max_redirections(void) const {
	bool result;
	mtx_user.lock();
	result = max_redirections;
	mtx_user.unlock();
	return result;
}

t_ext_support t_user::get_ext_100rel(void) const {
	t_ext_support result;
	mtx_user.lock();
	result = ext_100rel;
	mtx_user.unlock();
	return result;
}

bool t_user::get_referee_hold(void) const {
	bool result;
	mtx_user.lock();
	result = referee_hold;
	mtx_user.unlock();
	return result;
}

bool t_user::get_referrer_hold(void) const {
	bool result;
	mtx_user.lock();
	result = referrer_hold;
	mtx_user.unlock();
	return result;
}

bool t_user::get_allow_refer(void) const {
	bool result;
	mtx_user.lock();
	result = allow_refer;
	mtx_user.unlock();
	return result;
}

bool t_user::get_ask_user_to_refer(void) const {
	bool result;
	mtx_user.lock();
	result = ask_user_to_refer;
	mtx_user.unlock();
	return result;
}

bool t_user::get_auto_refresh_refer_sub(void) const {
	bool result;
	mtx_user.lock();
	result = auto_refresh_refer_sub;
	mtx_user.unlock();
	return result;
}

bool t_user::get_use_nat_public_ip(void) const {
	bool result;
	mtx_user.lock();
	result = use_nat_public_ip;
	mtx_user.unlock();
	return result;
}

string t_user::get_nat_public_ip(void) const {
	string result;
	mtx_user.lock();
	result = nat_public_ip;
	mtx_user.unlock();
	return result;
}

bool t_user::get_use_stun(void) const {
	bool result;
	mtx_user.lock();
	result = use_stun;
	mtx_user.unlock();
	return result;
}

t_url t_user::get_stun_server(void) const {
	t_url result;
	mtx_user.lock();
	result = stun_server;
	mtx_user.unlock();
	return result;
}

unsigned short t_user::get_timer_noanswer(void) const {
	unsigned short result;
	mtx_user.lock();
	result = timer_noanswer;
	mtx_user.unlock();
	return result;
}

unsigned long t_user::get_timer_nat_keepalive(void) const {
	unsigned short result;
	mtx_user.lock();
	result = timer_nat_keepalive;
	mtx_user.unlock();
	return result;
}
 
bool t_user::get_display_useronly_phone(void) const {
	bool result;
	mtx_user.lock();
	result = display_useronly_phone;
	mtx_user.unlock();
	return result;
}

bool t_user::get_numerical_user_is_phone(void) const {
	bool result;
	mtx_user.lock();
	result = numerical_user_is_phone;
	mtx_user.unlock();
	return result;
}

bool t_user::get_remove_special_phone_symbols(void) const {
	bool result;
	mtx_user.lock();
	result = remove_special_phone_symbols;
	mtx_user.unlock();
	return result;
}

string t_user::get_special_phone_symbols(void) const {
	string result;
	mtx_user.lock();
	result = special_phone_symbols;
	mtx_user.unlock();
	return result;
}

string t_user::get_ringtone_file(void) const {
	string result;
	mtx_user.lock();
	result = ringtone_file;
	mtx_user.unlock();
	return result;
}

string t_user::get_ringback_file(void) const {
	string result;
	mtx_user.lock();
	result = ringback_file;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_incoming_call(void) const {
	string result;
	mtx_user.lock();
	result = script_incoming_call;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_in_call_answered(void) const {
	string result;
	mtx_user.lock();
	result = script_in_call_answered;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_in_call_failed(void) const {
	string result;
	mtx_user.lock();
	result = script_in_call_failed;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_outgoing_call(void) const {
	string result;
	mtx_user.lock();
	result = script_outgoing_call;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_out_call_answered(void) const {
	string result;
	mtx_user.lock();
	result = script_out_call_answered;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_out_call_failed(void) const {
	string result;
	mtx_user.lock();
	result = script_out_call_failed;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_local_release(void) const {
	string result;
	mtx_user.lock();
	result = script_local_release;
	mtx_user.unlock();
	return result;
}

string t_user::get_script_remote_release(void) const {
	string result;
	mtx_user.lock();
	result = script_remote_release;
	mtx_user.unlock();
	return result;
}

list<t_number_conversion> t_user::get_number_conversions(void) const {
	list<t_number_conversion> result;
	mtx_user.lock();
	result = number_conversions;
	mtx_user.unlock();
	return result;	
}


	
void t_user::set_name(const string &_name) {
	mtx_user.lock();
	name = _name;
	mtx_user.unlock();
}

void t_user::set_domain(const string &_domain) {
	mtx_user.lock();
	domain = _domain;
	mtx_user.unlock();
}

void t_user::set_display(const string &_display) {	
	mtx_user.lock();
	display = _display;
	mtx_user.unlock();
}

void t_user::set_organization(const string &_organization) {
	mtx_user.lock();
	organization = _organization;
	mtx_user.unlock();
}

void t_user::set_auth_realm(const string &realm) {
	mtx_user.lock();
	auth_realm = realm;
	mtx_user.unlock();
}

void t_user::set_auth_name(const string &name) {
	mtx_user.lock();
	auth_name = name;
	mtx_user.unlock();
}

void t_user::set_auth_pass(const string &pass) {
	mtx_user.lock();
	auth_pass = pass;
	mtx_user.unlock();
}

void t_user::set_use_outbound_proxy(bool b) {
	mtx_user.lock();
	use_outbound_proxy = b;
	mtx_user.unlock();
}

void t_user::set_outbound_proxy(const t_url &url) {
	mtx_user.lock();
	outbound_proxy = url;
	mtx_user.unlock();
}

void t_user::set_all_requests_to_proxy(bool b) {
	mtx_user.lock();
	all_requests_to_proxy = b;
	mtx_user.unlock();
}

void t_user::set_non_resolvable_to_proxy(bool b) {
	mtx_user.lock();
	non_resolvable_to_proxy = b;
	mtx_user.unlock();
}

void t_user::set_use_registrar(bool b) {
	mtx_user.lock();
	use_registrar = b;
	mtx_user.unlock();
}

void t_user::set_registrar(const t_url &url) {
	mtx_user.lock();
	registrar = url;
	mtx_user.unlock();
}

void t_user::set_registration_time(const unsigned long time) {
	mtx_user.lock();
	registration_time = time;
	mtx_user.unlock();
}

void t_user::set_register_at_startup(bool b) {
	mtx_user.lock();
	register_at_startup = b;
	mtx_user.unlock();
}

void t_user::set_codecs(const list<t_audio_codec> &_codecs) {
	mtx_user.lock();
	codecs = _codecs;
	mtx_user.unlock();
}

void t_user::set_ptime(unsigned short _ptime) {
	mtx_user.lock();
	ptime = _ptime;
	mtx_user.unlock();
}

void t_user::set_speex_nb_payload_type(unsigned short payload_type) {
	mtx_user.lock();
	speex_nb_payload_type = payload_type;
	mtx_user.unlock();
}

void t_user::set_speex_wb_payload_type(unsigned short payload_type) {
	mtx_user.lock();
	speex_wb_payload_type = payload_type;
	mtx_user.unlock();
}

void t_user::set_speex_uwb_payload_type(unsigned short payload_type) {
	mtx_user.lock();
	speex_uwb_payload_type = payload_type;
	mtx_user.unlock();
}

void t_user::set_speex_bit_rate_type(t_bit_rate_type bit_rate_type) {
	mtx_user.lock();
	speex_bit_rate_type = bit_rate_type;
	mtx_user.unlock();
}

void t_user::set_speex_abr_nb(int abr) {
	mtx_user.lock();
	speex_abr_nb = abr;
	mtx_user.unlock();
}

void t_user::set_speex_abr_wb(int abr) {
	mtx_user.lock();
	speex_abr_wb = abr;
	mtx_user.unlock();
}

void t_user::set_speex_vad(bool b) {
	mtx_user.lock();
	speex_vad = b;
	mtx_user.unlock();
}

void t_user::set_speex_dtx(bool b) {
	mtx_user.lock();
	speex_dtx = b;
	mtx_user.unlock();
}

void t_user::set_speex_penh(bool b) {
	mtx_user.lock();
	speex_penh = b;
	mtx_user.unlock();
}

void t_user::set_speex_complexity(unsigned short complexity) {
	mtx_user.lock();
	speex_complexity = complexity;
	mtx_user.unlock();
}

void t_user::set_ilbc_payload_type(unsigned short payload_type) {
	mtx_user.lock();
	ilbc_payload_type = payload_type;
	mtx_user.unlock();
}

void t_user::set_ilbc_mode(unsigned short mode) {
	mtx_user.lock();
	ilbc_mode = mode;
	mtx_user.unlock();
}

void t_user::set_dtmf_transport(t_dtmf_transport _dtmf_transport) {
	mtx_user.lock();
	dtmf_transport = _dtmf_transport;
	mtx_user.unlock();
}

void t_user::set_dtmf_payload_type(unsigned short payload_type) {
	mtx_user.lock();
	dtmf_payload_type = payload_type;
	mtx_user.unlock();
}

void t_user::set_dtmf_duration(unsigned short duration) {
	mtx_user.lock();
	dtmf_duration = duration;
	mtx_user.unlock();
}

void t_user::set_dtmf_pause(unsigned short pause) {
	mtx_user.lock();
	dtmf_pause = pause;
	mtx_user.unlock();
}

void t_user::set_dtmf_volume(unsigned short volume) {
	mtx_user.lock();
	dtmf_volume = volume;
	mtx_user.unlock();
}

void t_user::set_hold_variant(t_hold_variant _hold_variant) {
	mtx_user.lock();
	hold_variant = _hold_variant;
	mtx_user.unlock();
}

void t_user::set_check_max_forwards(bool b) {
	mtx_user.lock();
	check_max_forwards = b;
	mtx_user.unlock();
}

void t_user::set_allow_missing_contact_reg(bool b) {
	mtx_user.lock();
	allow_missing_contact_reg = b;
	mtx_user.unlock();
}

void t_user::set_registration_time_in_contact(bool b) {
	mtx_user.lock();
	registration_time_in_contact = b;
	mtx_user.unlock();
}

void t_user::set_compact_headers(bool b) {
	mtx_user.lock();
	compact_headers = b;
	mtx_user.unlock();
}

void t_user::set_encode_multi_values_as_list(bool b) {
	mtx_user.lock();
	encode_multi_values_as_list = b;
	mtx_user.unlock();
}

void t_user::set_use_domain_in_contact(bool b) {
	mtx_user.lock();
	use_domain_in_contact = b;
	mtx_user.unlock();
}

void t_user::set_allow_sdp_change(bool b) {
	mtx_user.lock();
	allow_sdp_change = b;
	mtx_user.unlock();
}

void t_user::set_allow_redirection(bool b) {
	mtx_user.lock();
	allow_redirection = b;
	mtx_user.unlock();
}

void t_user::set_ask_user_to_redirect(bool b) {
	mtx_user.lock();
	ask_user_to_redirect = b;
	mtx_user.unlock();
}

void t_user::set_max_redirections(unsigned short _max_redirections) {
	mtx_user.lock();
	max_redirections = _max_redirections;
	mtx_user.unlock();
}

void t_user::set_ext_100rel(t_ext_support ext_support) {
	mtx_user.lock();
	ext_100rel = ext_support;
	mtx_user.unlock();
}

void t_user::set_referee_hold(bool b) {
	mtx_user.lock();
	referee_hold = b;
	mtx_user.unlock();
}

void t_user::set_referrer_hold(bool b) {
	mtx_user.lock();
	referrer_hold = b;
	mtx_user.unlock();
}

void t_user::set_allow_refer(bool b) {
	mtx_user.lock();
	allow_refer = b;
	mtx_user.unlock();
}

void t_user::set_ask_user_to_refer(bool b) {
	mtx_user.lock();
	ask_user_to_refer = b;
	mtx_user.unlock();
}

void t_user::set_auto_refresh_refer_sub(bool b) {
	mtx_user.lock();
	auto_refresh_refer_sub = b;
	mtx_user.unlock();
}

void t_user::set_use_nat_public_ip(bool b) {
	mtx_user.lock();
	use_nat_public_ip = b;
	mtx_user.unlock();
}

void t_user::set_nat_public_ip(const string &public_ip) {
	mtx_user.lock();
	nat_public_ip = public_ip;
	mtx_user.unlock();
}

void t_user::set_use_stun(bool b) {
	mtx_user.lock();
	use_stun = b;
	mtx_user.unlock();
}

void t_user::set_stun_server(const t_url &url) {
	mtx_user.lock();
	stun_server = url;
	mtx_user.unlock();
}

void t_user::set_timer_noanswer(unsigned short timer) {
	mtx_user.lock();
	timer_noanswer = timer;
	mtx_user.unlock();
}

void t_user::set_timer_nat_keepalive(unsigned short timer) { 
	mtx_user.lock();
	timer_nat_keepalive = timer;
	mtx_user.unlock();
}

void t_user::set_display_useronly_phone(bool b) {
	mtx_user.lock();
	display_useronly_phone = b;
	mtx_user.unlock();
}

void t_user::set_numerical_user_is_phone(bool b) {
	mtx_user.lock();
	numerical_user_is_phone = b;
	mtx_user.unlock();
}

void t_user::set_remove_special_phone_symbols(bool b) {
	mtx_user.lock();
	remove_special_phone_symbols = b;
	mtx_user.unlock();
}

void t_user::set_special_phone_symbols(const string &symbols) {
	mtx_user.lock();
	special_phone_symbols = symbols;
	mtx_user.unlock();
}

void t_user::set_ringtone_file(const string &file) {
	mtx_user.lock();
	ringtone_file = file;
	mtx_user.unlock();
}

void t_user::set_ringback_file(const string &file) {
	mtx_user.lock();
	ringback_file = file;
	mtx_user.unlock();
}

void t_user::set_script_incoming_call(const string &script) {
	mtx_user.lock();
	script_incoming_call = script;
	mtx_user.unlock();
}

void t_user::set_script_in_call_answered(const string &script) {
	mtx_user.lock();
	script_in_call_answered = script;
	mtx_user.unlock();
}

void t_user::set_script_in_call_failed(const string &script) {
	mtx_user.lock();
	script_in_call_failed = script;
	mtx_user.unlock();
}

void t_user::set_script_outgoing_call(const string &script) {
	mtx_user.lock();
	script_outgoing_call = script;
	mtx_user.unlock();
}

void t_user::set_script_out_call_answered(const string &script) {
	mtx_user.lock();
	script_out_call_answered = script;
	mtx_user.unlock();
}

void t_user::set_script_out_call_failed(const string &script) {
	mtx_user.lock();
	script_out_call_failed = script;
	mtx_user.unlock();
}

void t_user::set_script_local_release(const string &script) {
	mtx_user.lock();
	script_local_release = script;
	mtx_user.unlock();
}

void t_user::set_script_remote_release(const string &script) {
	mtx_user.lock();
	script_remote_release = script;
	mtx_user.unlock();
}

void t_user::set_number_conversions(const list<t_number_conversion> &l) {
	mtx_user.lock();
	number_conversions = l;
	mtx_user.unlock();
}

bool t_user::read_config(const string &filename, string &error_msg) {
	string f;
	string msg;
	
	mtx_user.lock();
	
	if (filename.size() == 0) {
		error_msg = "Cannot read user profile: missing file name.";
		log_file->write_report(error_msg, "t_user::read_config",
			LOG_NORMAL, LOG_CRITICAL);
		mtx_user.unlock();
		return false;
	}

	config_filename = filename;
	f = expand_filename(filename);

	ifstream config(f.c_str());
	if (!config) {
		error_msg = "Cannot open file for reading: ";
		error_msg += f;
		log_file->write_report(error_msg, "t_user::read_config",
			LOG_NORMAL, LOG_CRITICAL);
		mtx_user.unlock();
		return false;
	}

	log_file->write_header("t_user::read_config");
	log_file->write_raw("Reading config: ");
	log_file->write_raw(filename);
	log_file->write_endl();
	log_file->write_footer();

	while (!config.eof()) {
		string line;
		getline(config, line);

		// Check if read operation succeeded
		if (!config.good() && !config.eof()) {
			error_msg = "File system error while reading file ";
			error_msg += f;
			log_file->write_report(error_msg, "t_user::read_config",
				LOG_NORMAL, LOG_CRITICAL);
			mtx_user.unlock();
			return false;
		}

		line = trim(line);

		// Skip empty lines
		if (line.size() == 0) continue;

		// Skip comment lines
		if (line[0] == '#') continue;

		list<string> l = split_on_first(line, '=');
		if (l.size() != 2) {
			error_msg = "Syntax error in file ";
			error_msg += f;
			error_msg += "\n";
			error_msg += line;
			log_file->write_report(error_msg, "t_user::read_config",
				LOG_NORMAL, LOG_CRITICAL);
			mtx_user.unlock();
			return false;
		}

		string parameter = trim(l.front());
		string value = trim(l.back());
		
		if (parameter == FLD_NAME) {
			name = value;
		} else if (parameter == FLD_DOMAIN) {
			domain = value;
		} else if (parameter == FLD_DISPLAY) {
			display = value;
		} else if (parameter == FLD_ORGANIZATION) {
			organization = value;
		} else if (parameter == FLD_REGISTRATION_TIME) {
			registration_time = atol(value.c_str());
		} else if (parameter == FLD_REGISTRATION_TIME_IN_CONTACT) {
			registration_time_in_contact = yesno2bool(value);
		} else if (parameter == FLD_REGISTRAR) {
			if (value.size() == 0) continue;
			string s = string(USER_SCHEME) + ":" + value;
			registrar.set_url(s);

			// RFC 3261 10.2
			// Registrar URI should not contain user info
			if (!registrar.is_valid() ||
			    registrar.get_user() != "")
			{
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for registrar: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;
			}
			use_registrar = true;
		} else if (parameter == FLD_REGISTER_AT_STARTUP) {
			register_at_startup = yesno2bool(value);
		} else if (parameter == FLD_OUTBOUND_PROXY) {
			if (value.size() == 0) continue;
			string s = string(USER_SCHEME) + ":" + value;
			outbound_proxy.set_url(s);
			if (!outbound_proxy.is_valid() ||
			    outbound_proxy.get_user() != "")
			{
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for outbound proxy: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;
			}
			use_outbound_proxy = true;
		} else if (parameter == FLD_ALL_REQUESTS_TO_PROXY) {
			all_requests_to_proxy = yesno2bool(value);
		} else if (parameter == FLD_NON_RESOLVABLE_TO_PROXY) {
			non_resolvable_to_proxy = yesno2bool(value);
		} else if (parameter == FLD_AUTH_REALM) {
			auth_realm = value;
		} else if (parameter == FLD_AUTH_NAME) {
			auth_name = value;
		} else if (parameter == FLD_AUTH_PASS) {
			auth_pass = value;
		} else if (parameter == FLD_CODECS) {
			list<string> l = split(value, ',');
			if (l.size() > 0) codecs.clear();
			for (list<string>::iterator i = l.begin();
			     i != l.end(); i++)
			{
				string codec = trim(*i);
				if (codec == "g711a") {
					codecs.push_back(CODEC_G711_ALAW);
				} else if (codec == "g711u") {
					codecs.push_back(CODEC_G711_ULAW);
				} else if (codec == "gsm") {
					codecs.push_back(CODEC_GSM);
#ifdef HAVE_SPEEX
				} else if (codec == "speex-nb") {
					codecs.push_back(CODEC_SPEEX_NB);
				} else if (codec == "speex-wb") {
					codecs.push_back(CODEC_SPEEX_WB);
				} else if (codec == "speex-uwb") {
					codecs.push_back(CODEC_SPEEX_UWB);
#endif
#ifdef HAVE_ILBC
				} else if (codec == "ilbc") {
					codecs.push_back(CODEC_ILBC);
#endif
				} else {
					msg = "Syntax error in file ";
					msg += f;
					msg += "\n";
					msg += "Invalid codec: ";
					msg += value;
					log_file->write_report(msg,
						"t_user::read_config",
						LOG_NORMAL, LOG_WARNING);
				}
			}
		} else if (parameter == FLD_PTIME) {
			ptime = atoi(value.c_str());
		} else if (parameter == FLD_HOLD_VARIANT) {
			if (value == "rfc2543") {
				hold_variant = HOLD_RFC2543;
			} else if (value == "rfc3264") {
				hold_variant = HOLD_RFC3264;
			} else {
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid hold variant: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;
			}
		} else if (parameter == FLD_CHECK_MAX_FORWARDS) {
			check_max_forwards = yesno2bool(value);
		} else if (parameter == FLD_ALLOW_MISSING_CONTACT_REG) {
			allow_missing_contact_reg = yesno2bool(value);
		} else if (parameter == FLD_USE_DOMAIN_IN_CONTACT) {
			use_domain_in_contact = yesno2bool(value);
		} else if (parameter == FLD_ALLOW_SDP_CHANGE) {
			allow_sdp_change = yesno2bool(value);
		} else if (parameter == FLD_ALLOW_REDIRECTION) {
			allow_redirection = yesno2bool(value);
		} else if (parameter == FLD_ASK_USER_TO_REDIRECT) {
			ask_user_to_redirect = yesno2bool(value);
		} else if (parameter == FLD_MAX_REDIRECTIONS) {
			max_redirections = atoi(value.c_str());
		} else if (parameter == FLD_REFEREE_HOLD) {
			referee_hold = yesno2bool(value);
		} else if (parameter == FLD_REFERRER_HOLD) {
			referrer_hold = yesno2bool(value);
		} else if (parameter == FLD_ALLOW_REFER) {
			allow_refer = yesno2bool(value);
		} else if (parameter == FLD_ASK_USER_TO_REFER) {
			ask_user_to_refer = yesno2bool(value);
		} else if (parameter == FLD_AUTO_REFRESH_REFER_SUB) {
			auto_refresh_refer_sub = yesno2bool(value);
		} else if (parameter == FLD_NAT_PUBLIC_IP) {
			if (value.size() == 0) continue;
			use_nat_public_ip = true;
			nat_public_ip = value;
		} else if (parameter == FLD_STUN_SERVER) {
			if (value.size() == 0) continue;
			string s = "stun:" + value;
			stun_server.set_url(s);
			if (!stun_server.is_valid() ||
			    stun_server.get_user() != "")
			{
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for STUN server: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;
			}
			use_stun = true;
		} else if (parameter == FLD_TIMER_NOANSWER) {
			timer_noanswer = atoi(value.c_str());
		} else if (parameter == FLD_TIMER_NAT_KEEPALIVE) {
			timer_nat_keepalive = atoi(value.c_str());
		} else if (parameter == FLD_EXT_100REL) {
			ext_100rel = str2ext_support(value);
			if (ext_100rel == EXT_INVALID) {
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for ext_100rel: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;
			}
		} else if (parameter == FLD_COMPACT_HEADERS) {
			compact_headers = yesno2bool(value);
		} else if (parameter == FLD_ENCODE_MULTI_VALUES_AS_LIST) {
			encode_multi_values_as_list = yesno2bool(value);
		} else if (parameter == FLD_SPEEX_NB_PAYLOAD_TYPE) {
			speex_nb_payload_type = atoi(value.c_str());
		} else if (parameter == FLD_SPEEX_WB_PAYLOAD_TYPE) {
			speex_wb_payload_type = atoi(value.c_str());
		} else if (parameter == FLD_SPEEX_UWB_PAYLOAD_TYPE) {
			speex_uwb_payload_type = atoi(value.c_str());
		} else if (parameter == FLD_SPEEX_BIT_RATE_TYPE) {
			speex_bit_rate_type = str2bit_rate_type(value);
			if (speex_bit_rate_type == BIT_RATE_INVALID) {
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for speex bit rate type: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;		
			}
		} else if (parameter == FLD_SPEEX_ABR_NB) {
			speex_abr_nb = atoi(value.c_str());
		} else if (parameter == FLD_SPEEX_ABR_WB) {
			speex_abr_wb = atoi(value.c_str());
		} else if (parameter == FLD_SPEEX_VAD) {
			speex_vad = yesno2bool(value);
		} else if (parameter == FLD_SPEEX_DTX) {
			speex_dtx = yesno2bool(value);
		} else if (parameter == FLD_SPEEX_PENH) {
			speex_penh = yesno2bool(value);
		} else if (parameter == FLD_SPEEX_COMPLEXITY) {
			speex_complexity = atoi(value.c_str());
			if (speex_complexity < 1 || speex_complexity > 10) {
				error_msg = "Syntax error in file ";
				error_msg += f;
				error_msg += "\n";
				error_msg += "Invalid value for speex complexity: ";
				error_msg += value;
				log_file->write_report(error_msg, "t_user::read_config",
					LOG_NORMAL, LOG_CRITICAL);
				mtx_user.unlock();
				return false;	
			}
		} else if (parameter == FLD_ILBC_PAYLOAD_TYPE) {
			ilbc_payload_type = atoi(value.c_str());
		} else if (parameter == FLD_ILBC_MODE) {
			ilbc_mode = atoi(value.c_str());
		} else if (parameter == FLD_DTMF_TRANSPORT) {
			dtmf_transport = str2dtmf_transport(value);	
		} else if (parameter == FLD_DTMF_PAYLOAD_TYPE) {
			dtmf_payload_type = atoi(value.c_str());
		} else if (parameter == FLD_DTMF_DURATION) {
			dtmf_duration = atoi(value.c_str());
		} else if (parameter == FLD_DTMF_PAUSE) {
			dtmf_pause = atoi(value.c_str());
		} else if (parameter == FLD_DTMF_VOLUME) {
			dtmf_volume = atoi(value.c_str());
		} else if (parameter == FLD_DISPLAY_USERONLY_PHONE) {
			display_useronly_phone = yesno2bool(value);
		} else if (parameter == FLD_NUMERICAL_USER_IS_PHONE) {
			numerical_user_is_phone = yesno2bool(value);
		} else if (parameter == FLD_REMOVE_SPECIAL_PHONE_SYM) {
			remove_special_phone_symbols = yesno2bool(value);
		} else if (parameter == FLD_SPECIAL_PHONE_SYMBOLS) {
			special_phone_symbols = value;
		} else if (parameter == FLD_USER_RINGTONE_FILE) {
			ringtone_file = value;
		} else if (parameter == FLD_USER_RINGBACK_FILE) {
			ringback_file = value;
		} else if (parameter == FLD_SCRIPT_INCOMING_CALL) {
			script_incoming_call = value;
		} else if (parameter == FLD_SCRIPT_IN_CALL_ANSWERED) {
			script_in_call_answered = value;
		} else if (parameter == FLD_SCRIPT_IN_CALL_FAILED) {
			script_in_call_failed = value;
		} else if (parameter == FLD_SCRIPT_OUTGOING_CALL) {
			script_outgoing_call = value;
		} else if (parameter == FLD_SCRIPT_OUT_CALL_ANSWERED) {
			script_out_call_answered = value;
		} else if (parameter == FLD_SCRIPT_OUT_CALL_FAILED) {
			script_out_call_failed = value;
		} else if (parameter == FLD_SCRIPT_LOCAL_RELEASE) {
			script_local_release = value;
		} else if (parameter == FLD_SCRIPT_REMOTE_RELEASE) {
			script_remote_release = value;
		} else if (parameter == FLD_NUMBER_CONVERSION) {
			t_number_conversion c;
			if (parse_num_conversion(value, c)) {
				number_conversions.push_back(c);
			}
		} else {
			// Ignore unknown parameters. Only report in log file.
			log_file->write_header("t_user::read_config",
				LOG_NORMAL, LOG_WARNING);
			log_file->write_raw("Unknown parameter in user profile: ");
			log_file->write_raw(parameter);
			log_file->write_endl();
			log_file->write_footer();
		}
	}

	// Set parser options
	t_parser::check_max_forwards = check_max_forwards;
	t_parser::compact_headers = compact_headers;
	t_parser::multi_values_as_list = encode_multi_values_as_list;

	mtx_user.unlock();
	return true;
}

bool t_user::write_config(const string &filename, string &error_msg) {
	struct stat stat_buf;
	string f;
	
	mtx_user.lock();

	if (filename.size() == 0) {
		error_msg = "Cannot write user profile: missing file name.";
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
		mtx_user.unlock();
		return false;
	}

	config_filename = filename;
	f = expand_filename(filename);

	// Make a backup of the file if we are editing an existing file, so
	// that can be restored when writing fails.
	string f_backup = f + '~';
	if (stat(f.c_str(), &stat_buf) == 0) {
		if (rename(f.c_str(), f_backup.c_str()) != 0) {
			char *err = strerror(errno);
			error_msg = "Failed to backup ";
			error_msg += f;
			error_msg += " to ";
			error_msg += f_backup;
			error_msg += "\n";
			error_msg += err;
			log_file->write_report(error_msg, "t_user::write_config",
				LOG_NORMAL, LOG_CRITICAL);
			mtx_user.unlock();
			return false;
		}
	}

	ofstream config(f.c_str());
	if (!config) {
		error_msg = "Cannot open file for writing: ";
		error_msg += f;
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
		mtx_user.unlock();
		return false;
	}

	log_file->write_header("t_user::write_config");
	log_file->write_raw("Writing config: ");
	log_file->write_raw(filename);
	log_file->write_endl();
	log_file->write_footer();

	// Write USER settings
	config << "# USER\n";
	config << FLD_NAME << '=' << name << endl;
	config << FLD_DOMAIN << '=' << domain << endl;
	config << FLD_DISPLAY << '=' << display << endl;
	config << FLD_ORGANIZATION << '=' << organization << endl;
	config << FLD_AUTH_REALM << '=' << auth_realm << endl;
	config << FLD_AUTH_NAME << '=' << auth_name << endl;
	config << FLD_AUTH_PASS << '=' << auth_pass << endl;
	config << endl;

	// Write SIP SERVER settings
	config << "# SIP SERVER\n";
	if (use_outbound_proxy) {
		config << FLD_OUTBOUND_PROXY << '=';
		config << outbound_proxy.encode_noscheme() << endl;
		config << FLD_ALL_REQUESTS_TO_PROXY << '=';
		config << bool2yesno(all_requests_to_proxy) << endl;
		config << FLD_NON_RESOLVABLE_TO_PROXY << '=';
		config << bool2yesno(non_resolvable_to_proxy) << endl;
	} else {
		config << FLD_OUTBOUND_PROXY << '=' << endl;
		config << FLD_ALL_REQUESTS_TO_PROXY << "=no" << endl;
	}
	if (use_registrar) {
		config << FLD_REGISTRAR << '=' << registrar.encode_noscheme();
		config << endl;
	} else {
		config << FLD_REGISTRAR << '=' << endl;
	}
	config << FLD_REGISTER_AT_STARTUP << '=';
	config << bool2yesno(register_at_startup) << endl;
	config << FLD_REGISTRATION_TIME << '=' << registration_time << endl;
	config << endl;

	// Write AUDIO settings
	config << "# RTP AUDIO\n";
	config << FLD_CODECS << '=';
	for (list<t_audio_codec>::iterator i = codecs.begin();
	     i != codecs.end(); i++)
	{
		if (i != codecs.begin()) config << ',';
		switch(*i) {
		case CODEC_G711_ALAW:
			config << "g711a";
			break;
		case CODEC_G711_ULAW:
			config << "g711u";
			break;
		case CODEC_GSM:
			config << "gsm";
			break;
		case CODEC_SPEEX_NB:
			config << "speex-nb";
			break;
		case CODEC_SPEEX_WB:
			config << "speex-wb";
			break;
		case CODEC_SPEEX_UWB:
			config << "speex-uwb";
			break;
		case CODEC_ILBC:
			config << "ilbc";
			break;
		default:
			assert(false);
		}
	}
	config << endl;
	config << FLD_PTIME << '=' << ptime << endl;
	config << FLD_SPEEX_NB_PAYLOAD_TYPE << '=' << speex_nb_payload_type << endl;
	config << FLD_SPEEX_WB_PAYLOAD_TYPE << '=' << speex_wb_payload_type << endl;
	config << FLD_SPEEX_UWB_PAYLOAD_TYPE << '=' << speex_uwb_payload_type << endl;
	config << FLD_SPEEX_BIT_RATE_TYPE << '=';
	// config << FLD_SPEEX_ABR_NB << '=' << speex_abr_nb << endl;
	// config << FLD_SPEEX_ABR_WB << '=' << speex_abr_wb << endl;
	config << bit_rate_type2str(speex_bit_rate_type) << endl;
	config << FLD_SPEEX_VAD << '=' << bool2yesno(speex_vad) << endl;
	config << FLD_SPEEX_DTX << '=' << bool2yesno(speex_dtx) << endl;
	config << FLD_SPEEX_PENH << '=' << bool2yesno(speex_penh) << endl;
	config << FLD_SPEEX_COMPLEXITY << '=' << speex_complexity << endl;
	config << FLD_ILBC_PAYLOAD_TYPE << '=' << ilbc_payload_type << endl;
	config << FLD_ILBC_MODE << '=' << ilbc_mode << endl;
	config << FLD_DTMF_TRANSPORT << '=' << dtmf_transport2str(dtmf_transport) << endl;
	config << FLD_DTMF_PAYLOAD_TYPE << '=' << dtmf_payload_type << endl;
	config << FLD_DTMF_DURATION << '=' << dtmf_duration << endl;
	config << FLD_DTMF_PAUSE << '=' << dtmf_pause << endl;
	config << FLD_DTMF_VOLUME << '=' << dtmf_volume << endl;
	config << endl;

	// Write SIP PROTOCOL settings
	config << "# SIP PROTOCOL\n";
	config << FLD_HOLD_VARIANT << '=';
	switch(hold_variant) {
	case HOLD_RFC2543:
		config << "rfc2543";
		break;
	case HOLD_RFC3264:
		config << "rfc3264";
		break;
	default:
		assert(false);
	}
	config << endl;
	config << FLD_CHECK_MAX_FORWARDS << '=';
	config << bool2yesno(check_max_forwards) << endl;
	config << FLD_ALLOW_MISSING_CONTACT_REG << '=';
	config << bool2yesno(allow_missing_contact_reg) << endl;
	config << FLD_REGISTRATION_TIME_IN_CONTACT << '=';
	config << bool2yesno(registration_time_in_contact) << endl;
	config << FLD_COMPACT_HEADERS << '=' << bool2yesno(compact_headers) << endl;
	config << FLD_ENCODE_MULTI_VALUES_AS_LIST << '=';
	config << bool2yesno(encode_multi_values_as_list) << endl;
	config << FLD_USE_DOMAIN_IN_CONTACT << '=';
	config << bool2yesno(use_domain_in_contact) << endl;
	config << FLD_ALLOW_SDP_CHANGE << '=' << bool2yesno(allow_sdp_change) << endl;
	config << FLD_ALLOW_REDIRECTION << '=' << bool2yesno(allow_redirection);
	config << endl;
	config << FLD_ASK_USER_TO_REDIRECT << '=';
	config << bool2yesno(ask_user_to_redirect) << endl;
	config << FLD_MAX_REDIRECTIONS << '=' << max_redirections << endl;
	config << FLD_EXT_100REL << '=' << ext_support2str(ext_100rel) << endl;
	config << FLD_REFEREE_HOLD << '=' << bool2yesno(referee_hold) << endl;
	config << FLD_REFERRER_HOLD << '=' << bool2yesno(referrer_hold) << endl;
	config << FLD_ALLOW_REFER << '=' << bool2yesno(allow_refer) << endl;
	config << FLD_ASK_USER_TO_REFER << '=';
	config << bool2yesno(ask_user_to_refer) << endl;
	config << FLD_AUTO_REFRESH_REFER_SUB << '=';
	config << bool2yesno(auto_refresh_refer_sub) << endl;
	config << endl;

	// Write NAT settings
	config << "# NAT\n";
	if (use_nat_public_ip) {
		config << FLD_NAT_PUBLIC_IP << '=' << nat_public_ip << endl;
	} else {
		config << FLD_NAT_PUBLIC_IP << '=' << endl;
	}
	if (use_stun) {
		config << FLD_STUN_SERVER << '=' << 
			stun_server.encode_noscheme() << endl;
	} else {
		config << FLD_STUN_SERVER << '=' << endl;
	}
	config << endl;

	// Write TIMER settings
	config << "# TIMERS\n";
	config << FLD_TIMER_NOANSWER << '=' << timer_noanswer << endl;
	config << FLD_TIMER_NAT_KEEPALIVE << '=' << timer_nat_keepalive << endl;
	config << endl;

	// Write ADDRESS FORMAT settings
	config << "# ADDRESS FORMAT\n";
	config << FLD_DISPLAY_USERONLY_PHONE << '=';
	config << bool2yesno(display_useronly_phone) << endl;
	config << FLD_NUMERICAL_USER_IS_PHONE << '=';
	config << bool2yesno(numerical_user_is_phone) << endl;
	config << FLD_REMOVE_SPECIAL_PHONE_SYM << '=';
	config << bool2yesno(remove_special_phone_symbols) << endl;
	config << FLD_SPECIAL_PHONE_SYMBOLS << '=' << special_phone_symbols << endl;
	config << endl;
	
	// Write RING TONE settings
	config << "# RING TONES\n";
	config << FLD_USER_RINGTONE_FILE << '=' << ringtone_file << endl;
	config << FLD_USER_RINGBACK_FILE << '=' << ringback_file << endl;
	config << endl;
	
	// Write script settings
	config << "# SCRIPTS\n";
	config << FLD_SCRIPT_INCOMING_CALL << '=' << script_incoming_call << endl;
	config << FLD_SCRIPT_IN_CALL_ANSWERED << '=' << script_in_call_answered << endl;
	config << FLD_SCRIPT_IN_CALL_FAILED << '=' << script_in_call_failed << endl;
	config << FLD_SCRIPT_OUTGOING_CALL << '=' << script_outgoing_call << endl;
	config << FLD_SCRIPT_OUT_CALL_ANSWERED << '=' << script_out_call_answered << endl;
	config << FLD_SCRIPT_OUT_CALL_FAILED << '=' << script_out_call_failed << endl;
	config << FLD_SCRIPT_LOCAL_RELEASE << '=' << script_local_release << endl;
	config << FLD_SCRIPT_REMOTE_RELEASE << '=' << script_remote_release << endl;
	config << endl;
	
	// Write number conversion rules
	config << "# Number conversion\n";

	for (list<t_number_conversion>::iterator i = number_conversions.begin();
	     i != number_conversions.end(); i++)
	{
		config << FLD_NUMBER_CONVERSION << '=';
		config << escape(i->re.str(), ',');
		config << ',';
		config << escape(i->fmt, ',');
		config << endl;
	}

	// Check if writing succeeded
	if (!config.good()) {
		// Restore backup
		config.close();
		rename(f_backup.c_str(), f.c_str());

		error_msg = "File system error while writing file ";
		error_msg += f;
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
		mtx_user.unlock();
		return false;
	}

	// Set parser options
	t_parser::check_max_forwards = check_max_forwards;
	t_parser::compact_headers = compact_headers;
	t_parser::multi_values_as_list = encode_multi_values_as_list;

	mtx_user.unlock();
	return true;
}

string t_user::get_filename(void) const {
	string result;
	
	mtx_user.lock();
	result = config_filename;
	mtx_user.unlock();
	
	return result;
}

void t_user::set_config(string filename) {
	mtx_user.lock();
	config_filename = filename;
	mtx_user.unlock();
}

string t_user::get_profile_name(void) const {
	string result;
	
	mtx_user.lock();
	
	string::size_type pos_ext = config_filename.find(USER_FILE_EXT);

	if (pos_ext == string::npos) {
		result = config_filename;
	} else {
		result = config_filename.substr(0, pos_ext);
	}
	
	mtx_user.unlock();
	
	return result;
}

string t_user::get_contact_name(void) const {
	mtx_user.lock();
	
	string s = name;
	
	// Some broken proxies expect the contact name to be the same
	// as the SIP user name.
	if (!use_domain_in_contact) {
		mtx_user.unlock();
		return s;
	}
	
	// Create a unique contact name from the user name and domain:
	// 
	//   username_domain, where all dots in domain are replace
	//
	// This way it is possible to activate 2 profiles that have the
	// same username, but different domains, e.g.
	//
	//   michel@domainA
	//   michel@domainB

	s += '_';
	
	// Cut of port and/or uri-parameters if present in domain
	int i = domain.find_first_of(":;");
	if (i != string::npos) {
		// Some broken SIP proxies think that their own address appears
		// in the contact header when they see the domain in the user part.
		// By replacing the dots with underscores Twinkle interoperates
		// with those proxies (yuck).
		s += replace_char(domain.substr(0, i), '.', '_');
	} else {
		s += replace_char(domain, '.', '_');
	}

	mtx_user.unlock();
	return s;
}

string t_user::get_display_uri(void) const {
	mtx_user.lock();
	string s;
	
	s = display;
	if (!s.empty()) s += ' ';
	s += '<';
	s += USER_SCHEME;
	s += ':';
	s += name;
	s += '@';
	s += domain;
	s += '>';
	
	mtx_user.unlock();
	return s;
}

bool t_user::check_required_ext(t_request *r, list<string> &unsupported) const {
	bool all_supported = true;
	
	mtx_user.lock();

	unsupported.clear();
	if (!r->hdr_require.is_populated()) {
		mtx_user.unlock();
		return true;
	}
	
	for (list<string>::iterator i = r->hdr_require.features.begin();
	     i != r->hdr_require.features.end(); i++)
	{
		if (*i == EXT_100REL) {
			if (ext_100rel != EXT_DISABLED) continue;
		}

		// Extension is not supported
		unsupported.push_back(*i);
		all_supported = false;
	}

	mtx_user.unlock();
	return all_supported;
}

string t_user::create_user_contact(void) {
	string s;
	
	mtx_user.lock();

	s = USER_SCHEME;
	s += ':';
	s += get_contact_name();
	s += '@';
	s += USER_HOST(this);

	if (PUBLIC_SIP_UDP_PORT(this) != get_default_port(USER_SCHEME)) {
		s += ':';
		s += int2str(PUBLIC_SIP_UDP_PORT(this));
	}

	if (numerical_user_is_phone && looks_like_phone(name, special_phone_symbols))
	{
		// RFC 3261 19.1.1
		// If the URI contains a telephone number it SHOULD contain
		// the user=phone parameter.
		s += ";user=phone";
	}

	mtx_user.unlock();
	return s;
}

string t_user::create_user_uri(void) {
	string s;
	
	mtx_user.lock();

	s = USER_SCHEME;
	s += ':';
	s += name;
	s += '@';
	s += domain;

	if (numerical_user_is_phone && looks_like_phone(name, special_phone_symbols))
	{
		// RFC 3261 19.1.1
		// If the URI contains a telephone number it SHOULD contain
		// the user=phone parameter.
		s += ";user=phone";
	}

	mtx_user.unlock();
	return s;
}

string t_user::convert_number(const string &number, const list<t_number_conversion> &l) const {
	for (list<t_number_conversion>::const_iterator i = l.begin();
	     i != l.end(); i++)
	{
		boost::smatch m;
		
		try {
			if (boost::regex_match(number, m, i->re)) {
				string result = m.format(i->fmt);
			
				log_file->write_header("t_user::convert_number", 
					LOG_NORMAL, LOG_DEBUG);
				log_file->write_raw("Apply conversion: ");
				log_file->write_raw(i->str());
				log_file->write_endl();
				log_file->write_raw(number);
				log_file->write_raw(" converted to ");
				log_file->write_raw(result);
				log_file->write_endl();
				log_file->write_footer();
					
				return result;
			}
		} catch (std::runtime_error) {
			log_file->write_header("t_user::convert_number", 
					LOG_NORMAL, LOG_WARNING);
			log_file->write_raw("Number conversion rule too complex:\n");
			log_file->write_raw("Number: ");
			log_file->write_raw(number);
			log_file->write_endl();
			log_file->write_raw(i->str());
			log_file->write_endl();
			log_file->write_footer();
			
			return number;
		}
	}
	
	// No match found
	return number;
}

string t_user::convert_number(const string &number) const {
	return convert_number(number, number_conversions);
}
