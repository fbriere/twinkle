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

#include <cassert>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <list>
#include "log.h"
#include "user.h"
#include "util.h"
#include "protocol.h"
#include "sdp/sdp.h"
#include "parser/parse_ctrl.h"

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
#define FLD_RTP_PORT			"rtp_port"
#define FLD_CODECS			"codecs"
#define FLD_PTIME			"ptime"
#define FLD_DTMF_PAYLOAD_TYPE		"dtmf_payload_type"
#define FLD_DTMF_DURATION		"dtmf_duration"
#define FLD_DTMF_PAUSE			"dtmf_pause"
#define FLD_DTMF_VOLUME			"dtmf_volume"

// SIP PROTOCOL fields
#define FLD_SIP_UDP_PORT		"sip_udp_port"
#define FLD_HOLD_VARIANT		"hold_variant"
#define FLD_CHECK_MAX_FORWARDS		"check_max_forwards"
#define FLD_ALLOW_MISSING_CONTACT_REG	"allow_missing_contact_reg"	
#define FLD_REGISTRATION_TIME_IN_CONTACT	"registration_time_in_contact"
#define FLD_COMPACT_HEADERS		"compact_headers"
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
	sip_udp_port = 5060;
	use_outbound_proxy = false;
	all_requests_to_proxy = false;
	non_resolvable_to_proxy = false;
	use_registrar = false;
	registration_time = 3600;
	rtp_port = 8000;
	codecs.push_back(SDP_FORMAT_G711_ALAW);
	codecs.push_back(SDP_FORMAT_G711_ULAW);
	codecs.push_back(SDP_FORMAT_GSM);
	ptime = 20;
	hold_variant = HOLD_RFC2543;
	use_nat_public_ip = false;
	use_stun = false;
	register_at_startup = true;
	check_max_forwards = false;
	allow_missing_contact_reg = true;
	allow_redirection = true;
	ask_user_to_redirect = true;
	max_redirections = 5;
	timer_noanswer = 30;
	timer_nat_keepalive = DUR_NAT_KEEPALIVE;
	ext_100rel = EXT_SUPPORTED;
	compact_headers = false;
	registration_time_in_contact = true;
	dtmf_duration = 100;
	dtmf_pause = 40;
	dtmf_payload_type = 101;
	dtmf_volume = 10;
	display_useronly_phone = true;
	numerical_user_is_phone = false;
	referee_hold = false;
	referrer_hold = true;
	allow_refer = true;
	ask_user_to_refer = true;
	auto_refresh_refer_sub = false;
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

		list<string> l = split(line, '=');
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
		
		if (parameter == FLD_SIP_UDP_PORT) {
			sip_udp_port = atoi(value.c_str());
		} else if (parameter == FLD_NAME) {
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
		} else if (parameter == FLD_RTP_PORT) {
			rtp_port = atoi(value.c_str());
		} else if (parameter == FLD_CODECS) {
			list<string> l = split(value, ',');
			if (l.size() > 0) codecs.clear();
			for (list<string>::iterator i = l.begin();
			     i != l.end(); i++)
			{
				string codec = trim(*i);
				if (codec == "g711a") {
					codecs.push_back(SDP_FORMAT_G711_ALAW);
				} else if (codec == "g711u") {
					codecs.push_back(SDP_FORMAT_G711_ULAW);
				} else if (codec == "gsm") {
					codecs.push_back(SDP_FORMAT_GSM);
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
		} else {
			// Ignore unknown parameters. Only report in log file.
			log_file->write_header("t_user::read_config",
				LOG_NORMAL, LOG_WARNING);
			log_file->write_raw("Unknown paramter in user profile: ");
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
	config << FLD_RTP_PORT << '=' << rtp_port << endl;
	config << FLD_CODECS << '=';
	for (list<unsigned short>::iterator i = codecs.begin();
	     i != codecs.end(); i++)
	{
		if (i != codecs.begin()) config << ',';
		switch(*i) {
		case SDP_FORMAT_G711_ALAW:
			config << "g711a";
			break;
		case SDP_FORMAT_G711_ULAW:
			config << "g711u";
			break;
		case SDP_FORMAT_GSM:
			config << "gsm";
			break;
		default:
			assert(false);
		}
	}
	config << endl;
	config << FLD_PTIME << '=' << ptime << endl;
	config << FLD_DTMF_PAYLOAD_TYPE << '=' << dtmf_payload_type << endl;
	config << FLD_DTMF_DURATION << '=' << dtmf_duration << endl;
	config << FLD_DTMF_PAUSE << '=' << dtmf_pause << endl;
	config << FLD_DTMF_VOLUME << '=' << dtmf_volume << endl;
	config << endl;

	// Write SIP PROTOCOL settings
	config << "# SIP PROTOCOL\n";
	config << FLD_SIP_UDP_PORT << '=' << sip_udp_port << endl;
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
	config << endl;

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
