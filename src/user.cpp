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
}

t_user *t_user::copy(void) const {
	t_user *u = new t_user(*this);
	MEMMAN_NEW(u);
	return u;
}

bool t_user::read_config(const string &filename, string &error_msg) {
	string f;
	
	if (filename.size() == 0) {
		error_msg = "Cannot read user profile: missing file name.";
		log_file->write_report(error_msg, "t_user::read_config",
			LOG_NORMAL, LOG_CRITICAL);
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
				} else {
					error_msg = "Syntax error in file ";
					error_msg += f;
					error_msg += "\n";
					error_msg += "Invalid codec: ";
					error_msg += value;
					log_file->write_report(error_msg,
						"t_user::read_config",
						LOG_NORMAL, LOG_CRITICAL);
					return false;
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
				return false;
			}
		} else if (parameter == FLD_COMPACT_HEADERS) {
			compact_headers = yesno2bool(value);
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
				return false;	
			}
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

	return true;
}

bool t_user::write_config(const string &filename, string &error_msg) {
	struct stat stat_buf;
	string f;

	if (filename.size() == 0) {
		error_msg = "Cannot write user profile: missing file name.";
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
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
			return false;
		}
	}

	ofstream config(f.c_str());
	if (!config) {
		error_msg = "Cannot open file for writing: ";
		error_msg += f;
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
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

	// Check if writing succeeded
	if (!config.good()) {
		// Restore backup
		config.close();
		rename(f_backup.c_str(), f.c_str());

		error_msg = "File system error while writing file ";
		error_msg += f;
		log_file->write_report(error_msg, "t_user::write_config",
			LOG_NORMAL, LOG_CRITICAL);
		return false;
	}

	// Set parser options
	t_parser::check_max_forwards = check_max_forwards;
	t_parser::compact_headers = compact_headers;

	return true;
}

string t_user::get_filename(void) const {
	return config_filename;
}

void t_user::set_config(string filename) {
	config_filename = filename;
}

string t_user::get_profile_name(void) const {
	int pos_ext = config_filename.find(USER_FILE_EXT);

	if (pos_ext == string::npos) return config_filename;

	return config_filename.substr(0, pos_ext);
}

string t_user::get_contact_name(void) const {
	// Some broken proxies expect the contact name to be the same
	// as the SIP user name.
	if (!use_domain_in_contact) return name;
	
	// Create a unique contact name from the user name and domain:
	// 
	//   username_domain, where all dots in domain are replace
	//
	// This way it is possible to activate 2 profiles that have the
	// same username, but different domains, e.g.
	//
	//   michel@domainA
	//   michel@domainB

	string s = name;
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

	return s;
}

string t_user::get_display_uri(void) const {
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
	
	return s;
}

bool t_user::check_required_ext(t_request *r, list<string> &unsupported) const {
	bool all_supported = true;

	unsupported.clear();
	if (!r->hdr_require.is_populated()) return true;

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

	return all_supported;
}

string t_user::create_user_contact(void) {
	string s;

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

	return s;
}

string t_user::create_user_uri(void) {
	string s;

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

	return s;
}
