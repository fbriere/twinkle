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

// Session description

// TODO: multicast IP addresses

#ifndef _H_SDP
#define _H_SDP

#include <list>
#include <string>
#include "parser/sip_body.h"

// Audio codec formats
#define SDP_FORMAT_G711_ULAW	0
#define SDP_FORMAT_GSM		3
#define SDP_FORMAT_G711_ALAW	8

// rtpmap values
#define SDP_RTPMAP_G711_ULAW	"PCMU/8000"
#define SDP_RTPMAP_GSM		"GSM/8000"
#define SDP_RTPMAP_G711_ALAW	"PCMA/8000"
#define SDP_RTPMAP_TELEPHONE_EV	"telephone-event/8000"

using namespace std;

enum t_sdp_ntwk_type {
	SDP_NTWK_NULL,
	SDP_NTWK_IN
};

string sdp_ntwk_type2str(t_sdp_ntwk_type n);
t_sdp_ntwk_type str2sdp_ntwk_type(string s);


enum t_sdp_addr_type {
	SDP_ADDR_NULL,
	SDP_ADDR_IP4,
	SDP_ADDR_IP6
};

string sdp_addr_type2str(t_sdp_addr_type a);
t_sdp_addr_type str2sdp_addr_type(string s);


enum t_sdp_transport {
	SDP_TRANS_NULL,
	SDP_TRANS_RTP,
	SDP_TRANS_UDP
};

string sdp_transport2str(t_sdp_transport t);
t_sdp_transport str2sdp_transport(string s);


enum t_sdp_media_direction {
	SDP_INACTIVE,
	SDP_SENDONLY,
	SDP_RECVONLY,
	SDP_SENDRECV
};

string sdp_media_direction2str(t_sdp_media_direction d);


enum t_sdp_media_type {
	SDP_AUDIO,
	SDP_VIDEO,
	SDP_OTHER
};

t_sdp_media_type str2sdp_media_type(string s);
string sdp_media_type2str(t_sdp_media_type m);


class t_sdp_origin {
public:
	string			username;
	string			session_id;
	string			session_version;
	t_sdp_ntwk_type		network_type;
	t_sdp_addr_type		address_type;
	string			address;

	t_sdp_origin();
	t_sdp_origin(string _username, string _session_id,
		     string _session_version, string _address);

	string encode(void) const;
};

class t_sdp_connection {
public:
	t_sdp_ntwk_type		network_type;
	t_sdp_addr_type		address_type;
	string			address;

	t_sdp_connection();
	t_sdp_connection(string _address);
	string encode(void) const;
};

class t_sdp_attr {
public:
	string			name;
	string			value;

	t_sdp_attr(string _name);
	t_sdp_attr(string _name, string _value);
	string encode(void) const;
};

class t_sdp_media {
private:
	unsigned short		format_dtmf; // dynamic payload type for DTMF

public:
	string			media_type;
	unsigned short		port;
	t_sdp_transport		transport;
	list<unsigned short>	formats;
	t_sdp_connection	connection;
	list <t_sdp_attr>	attributes;

	t_sdp_media();
	t_sdp_media(t_sdp_media_type _media_type,
		    unsigned short _port, list<unsigned short> _formats,
	            unsigned short _format_dtmf);

	string encode(void) const;
	void add_format(unsigned short f);
	t_sdp_attr *get_attribute(const string &name);
	list<t_sdp_attr *>get_attributes(const string &name);
	t_sdp_media_direction get_direction(void) const;
	t_sdp_media_type get_media_type(void) const;
};

class t_sdp : public t_sip_body {
public:
	unsigned short		version;
	t_sdp_origin		origin;
	string			session_name;
	t_sdp_connection	connection;
	list<t_sdp_attr>	attributes;
	list<t_sdp_media>	media;

	t_sdp();

	// Create SDP with a single audio media stream
	t_sdp(string user, string sess_id, string sess_version,
	      string media_host, unsigned short media_port,
	      list<unsigned short> formats, unsigned short format_dtmf);

	// Create SDP without media streams
	t_sdp(string user, string sess_id, string sess_version, string media_host);

	// Add media stream
	void add_media(const t_sdp_media &m);

	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;

	// Return true if the current SDP is supported:
	// version is 0
	// 1 audio stream RTP
	// IN IP4 addressing
	// connection at session level only
	// If false is returned, then a warning code and text is returned.
	bool is_supported(int &warn_code, string &warn_text) const;

	// Get/set codec/rtp info for first media stream having a non-zero
	// value for the port of the given media type
	string get_rtp_host(t_sdp_media_type media_type) const;
	unsigned short get_rtp_port(t_sdp_media_type media_type) const;
	list<unsigned short> get_codecs(t_sdp_media_type media_type) const;

	// Get codec description from rtpmap
	string get_codec_description(t_sdp_media_type media_type,
			unsigned short codec) const;
	t_sdp_media_direction get_direction(t_sdp_media_type media_type) const;

	// Get ptime. Returns 0 if ptime is not present
	unsigned short get_ptime(t_sdp_media_type media_type) const;

	void set_ptime(t_sdp_media_type media_type, unsigned short ptime);
	void set_direction(t_sdp_media_type media_type, t_sdp_media_direction direction);

	// Returns a pointer to the first media stream in the list of media
	// streams having a non-zero port value for the give media type.
	// Returns NULL if no such media stream can be found.
	const t_sdp_media *get_first_media(t_sdp_media_type media_type) const;
};

#endif
