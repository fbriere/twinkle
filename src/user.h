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

#ifndef _H_USER
#define _H_USER

#include <string>
#include <list>
#include "sys_settings.h"
#include "sockets/url.h"

// Default config file name
#define USER_CONFIG_FILE	"twinkle.cfg"
#define USER_FILE_EXT		".cfg"
#define USER_DIR		DIR_USER

#define USER_SCHEME		"sip"

#define PUBLIC_SIP_UDP_PORT	phone->get_public_port_sip()
#define USER_HOST		phone->get_ip_sip()
#define LOCAL_IP		user_host

using namespace std;

enum t_hold_variant {
	HOLD_RFC2543,	// set IP = 0.0.0.0 in c-line
	HOLD_RFC3264	// use direction attribute to put call on-hold
};

enum t_ext_support {
	EXT_INVALID,
	EXT_DISABLED,
	EXT_SUPPORTED,
	EXT_PREFERRED,
	EXT_REQUIRED
};

class t_user {
private:
	string			config_filename;

	// Expand file name to a fully qualified file name
	string expand_filename(const string &filename);

	t_ext_support str2ext_support(const string &s) const;
	string ext_support2str(t_ext_support e) const;

public:
	// USER

	// SIP user
	string			name;
	string			domain;
	string			display;

	// The organization will be put in an initial INVITE and in a
	// 200 OK on an INVITE.
	string			organization;

	// SIP authentication
	string			auth_realm; // an empty realm matches with all realms
	string			auth_name;
	string			auth_pass;


	// SIP SERVER

	// Send all non-REGISTER requests to the outbound proxy
	bool			use_outbound_proxy;
	t_url			outbound_proxy;

	// By default only out-of-dialog requests (including the ones the
	// establish a dialog) are sent to the outbound proxy.
	// In-dialog requests go to the address established via the contact
	// header.
	// By setting this parameter to true, in-dialog requests go to the
	// outbound proxy as well.
	bool			all_requests_to_proxy;

	// Only send the request to the proxy, if the destination cannot
	// be resolved to an IP address, adhearing to the previous setting
	// though. I.e. use_outbound_proxy must be true. And an in-dialog
	// request will only be sent to the proxy if all_requests_to_proxy
	// is true.
	bool			non_resolvable_to_proxy;

	// Send REGISTER to registrar
	bool			use_registrar;
	t_url			registrar;

	// Registration time requested by the client. If set to zero, then
	// no specific time is requested. The registrar will set a time.
	unsigned long		registration_time;

	// Automatically register at startup of the client.
	bool			register_at_startup;


	// AUDIO

	// rtp_port is the base port for RTP streams. Each phone line
	// uses has its own RPT port number.
	// line x has RTP port = rtp_port + x * 2 and
	//           RTCP port = rtp_port + x * 2 + 1
	// Where x starts at 0
	//
	// NOTE: for call transfer scenario, line 2 (3rd line) is used
	//       which is not a line that is visible to the user. The user
	//       only sees 2 lines for its use. By having a dedicated port
	//       for line 2, the  RTP stream for a referred call uses another
	//       port than the RTP stream for an original call, preventing
	//       the RTP streams for these calls to become mixed.
	//
	// NOTE: during a call transfer, line 2 will be swapped with another
	//       line, so the ports swap accordingly.
	unsigned short		rtp_port;

	list<unsigned short>	codecs; // in order of preference
	unsigned short		ptime; // ptime (ms) for G.711

	// RTP dynamic payload type for out-of-band DTMF.
	unsigned short		dtmf_payload_type;

	// DTMF duration and pause between 2 tones. During the pause the last
	// DTMF event will be repeated so the far end can detect the end of
	// the event in case of packet loss.
	unsigned short		dtmf_duration; // ms
	unsigned short		dtmf_pause; // ms
	
	// Volume of the tone in -dBm
	unsigned short		dtmf_volume;


	// SIP PROTOCOL

	// Port for sending and receiving SIP messages
	unsigned short	sip_udp_port;

	// SIP protocol options
	// hold variants: rfc2543, rfc3264
	// rfc2543 - set IP address to 0.0.0.0
	// rfc3264 - use direction attribute (sendrecv, sendonly, ...)
	t_hold_variant		hold_variant;

	// Indicate if the mandatory Max-Forwards header should be present.
	// If true and the header is missing, then the request will fail.
	bool			check_max_forwards;
	
	// RFC 3261 10.3 states that a registrar must include a contact
	// header in a 200 OK on a REGISTER. This contact should match the
	// contact that a UA puts in the REGISTER. Unfortunately many
	// registrars do not include the contact header or put a wrong
	// IP address in the host-part due to NAT.
	// This settings allows for a missing/non-matching contact header.
	// In that case Twinkle assumes that it is registered for the
	// requested interval.
	bool			allow_missing_contact_reg;

	// Indicate the place of the requested registration time in a REGISTER.
	// true - expires parameter in contact header
	// false - Expires header
	bool			registration_time_in_contact;

	// Indicate if compact header names should be used in outgoing messages.
	bool			compact_headers;

	// Redirections
	// Allow redirection of a request when a 3XX is received.
	bool			allow_redirection;

	// Ask user for permission to redirect a request when a 3XX is received.
	bool			ask_user_to_redirect;

	// Maximum number of locations to be tried when a request is redirected.
	unsigned short		max_redirections;

	// SIP extensions
	// 100rel extension (PRACK)
	// Possible values:
	// - disabled	100rel extension is disabled
	// - supported	100rel is supported (it is added in the supported header of
	//               an outgoing INVITE). A far-end can now require a PRACK on a
	//               1xx response.
	// - required	100rel is required (it is put in the require header of an
	//               outgoing INVITE).
	//		If an incoming INVITE indicates that it supports 100rel, then
	//		Twinkle will require a PRACK when sending a 1xx response.
	// - preferred	Similar to required, but if a call fails because the far-end
	//		indicates it does not support 100rel (420 response) then the
	//		call will be re-attempted without the 100rel requirement.
	t_ext_support		ext_100rel;

	// REFER options
	// Hold the current call when an incoming REFER is accepted.
	bool			referee_hold;

	// Hold the current call before sending a REFER.
	bool			referrer_hold;

	// Allow an incoming refer
	bool			allow_refer;

	// Ask user for permission when a REFER is received.
	bool			ask_user_to_refer;

	// Referrer automatically refreshes subscription before expiry.
	bool			auto_refresh_refer_sub;

	// NAT

	// NAT traversal
	// You can set nat_public_ip to your public IP or FQDN if you are behind
	// a NAT. This will then be used inside the SIP messages instead of your
	// private IP. On your NAT you have to create static bindings for port 5060
	// and ports 8000 - 8003 to the same ports on your private IP address.
	bool			use_nat_public_ip;
	string			nat_public_ip;
	
	// NAT traversal via STUN
	bool			use_stun;
	t_url			stun_server;


	// TIMERS

	// Noanswer timer is started when an initial INVITE is received. If
	// the user does not respond within the timer, then the call will be
	// released with a 480 Temporarily Unavailable response.
	unsigned short		timer_noanswer; // seconds
	
	// Duration of NAT keepalive timer (s)
	unsigned long		timer_nat_keepalive; 

	// ADDRESS FORMAT

	// Telephone numbers
	// Display only the user-part of a URI if it is a telephone number
	// I.e. the user=phone parameter is present, or the user indicated
	// that the format of the user-part is a telephone number.
	bool			display_useronly_phone;

	// Consider user-parts that consist of 0-9,+,-,*,# as a telephone
	// number. I.e. in outgoing messages the user=phone parameter will
	// be added to the URI. For incoming messages the URI will be considered
	// to be a telephone number regardless of the presence of the
	// user=phone parameter.
	bool			numerical_user_is_phone;


	t_user();

	// Read and parse a config file into the user object.
	// Returns false if it fails. error_msg is an error message that can
	// be give to the user.
	bool read_config(const string &filename, string &error_msg);

	// Write the settings into a config file
	bool write_config(const string &filename, string &error_msg);
	string get_filename(void) const;

	// Set a config file name
	void set_config(string _filename);

	// Get the name of the profile (filename without extension)
	string get_profile_name(void) const;
};

extern t_user *user_config;

#endif
