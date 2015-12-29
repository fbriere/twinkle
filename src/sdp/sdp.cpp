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

#include <assert.h>
#include <cstdlib>
#include <iostream>
#include "protocol.h"
#include "sdp_parse_ctrl.h"
#include "sdp.h"
#include "util.h"
#include "audio/audio_codecs.h"
#include "parser/hdr_warning.h"
#include "audits/memman.h"

string sdp_ntwk_type2str(t_sdp_ntwk_type n) {
	switch(n) {
	case SDP_NTWK_NULL:	return "NULL";
	case SDP_NTWK_IN:	return "IN";
	default:
		assert(false);
	}
}

t_sdp_ntwk_type str2sdp_ntwk_type(string s) {
	if (s == "IN") return SDP_NTWK_IN;

	throw (t_sdp_syntax_error("unknown network type: " + s));
}

string sdp_addr_type2str(t_sdp_addr_type a) {
	switch(a) {
	case SDP_ADDR_NULL:	return "NULL";
	case SDP_ADDR_IP4:	return "IP4";
	case SDP_ADDR_IP6:	return "IP6";
	default:
		assert(false);
	}
}

t_sdp_addr_type str2sdp_addr_type(string s) {
	if (s == "IP4") return SDP_ADDR_IP4;
	if (s == "IP6") return SDP_ADDR_IP6;

	throw (t_sdp_syntax_error("unknown address type: " + s));
}

string sdp_transport2str(t_sdp_transport t) {
	switch(t) {
	case SDP_TRANS_NULL:	return "NULL";
	case SDP_TRANS_RTP:	return "RTP/AVP";
	case SDP_TRANS_UDP:	return "udp";
	default:
		assert(false);
	}
}

t_sdp_transport str2sdp_transport(string s) {
	if (s == "RTP/AVP") return SDP_TRANS_RTP;
	if (s == "udp") return SDP_TRANS_UDP;

	throw (t_sdp_syntax_error("unknown transport: " + s));
}

t_sdp_media_type str2sdp_media_type(string s) {
	if (s == "audio") return SDP_AUDIO;
	if (s == "video") return SDP_VIDEO;
	return SDP_OTHER;
}

string sdp_media_type2str(t_sdp_media_type m) {
	switch(m) {
	case SDP_AUDIO:		return "audio";
	case SDP_VIDEO:		return "video";
	default:
		assert(false);
	}
}

string get_rtpmap(unsigned short format, unsigned short format_dtmf) {
	string rtpmap;

	switch(format) {
	case SDP_FORMAT_G711_ULAW:
		rtpmap = int2str(format);
		rtpmap += ' ';
		rtpmap += SDP_RTPMAP_G711_ULAW;
		break;
	case SDP_FORMAT_G711_ALAW:
		rtpmap = int2str(format);
		rtpmap += ' ';
		rtpmap += SDP_RTPMAP_G711_ALAW;
		break;
	case SDP_FORMAT_GSM:
		rtpmap = int2str(format);
		rtpmap += ' ';
		rtpmap += SDP_RTPMAP_GSM;
		break;
	default:
		if (format = format_dtmf) {
			rtpmap = int2str(format);
			rtpmap += ' ';
			rtpmap += SDP_RTPMAP_TELEPHONE_EV;
			break;
		}

		assert(false);
	}

	return rtpmap;
}

string sdp_media_direction2str(t_sdp_media_direction d) {
	switch(d) {
	case SDP_INACTIVE:	return "inactive";
	case SDP_SENDONLY:	return "sendonly";
	case SDP_RECVONLY:	return "recvonly";
	case SDP_SENDRECV:	return "sendrecv";
	default:
		assert(false);
	}
}

///////////////////////////////////
// class t_sdp_origin
///////////////////////////////////

t_sdp_origin::t_sdp_origin() {
	network_type = SDP_NTWK_NULL;
	address_type = SDP_ADDR_NULL;
}

t_sdp_origin::t_sdp_origin(string _username, string _session_id,
		           string _session_version, string _address) :
		username(_username),
		session_id(_session_id),
		session_version(_session_version),
		address(_address)
{
	network_type = SDP_NTWK_IN;
	address_type = SDP_ADDR_IP4;
}

string t_sdp_origin::encode(void) const {
	string s;

	s = "o=";
	s += username;
	s += ' ' + session_id;
	s += ' ' + session_version;
	s += ' ' + sdp_ntwk_type2str(network_type);
	s += ' ' + sdp_addr_type2str(address_type);
	s += ' ' + address;
	s += CRLF;

	return s;
}


///////////////////////////////////
// class t_sdp_connection
///////////////////////////////////

t_sdp_connection::t_sdp_connection() {
	network_type = SDP_NTWK_NULL;
}

t_sdp_connection::t_sdp_connection(string _address) :
		address(_address)
{
	network_type = SDP_NTWK_IN;
	address_type = SDP_ADDR_IP4;
}

string t_sdp_connection::encode(void) const {
	string s;

	s = "c=";
	s += sdp_ntwk_type2str(network_type);
	s += ' ' + sdp_addr_type2str(address_type);
	s += ' ' + address;
	s += CRLF;

	return s;
}


///////////////////////////////////
// class t_sdp_attr
///////////////////////////////////

t_sdp_attr::t_sdp_attr(string _name) {
	name = _name;
}

t_sdp_attr::t_sdp_attr(string _name, string _value) {
	name = _name;
	value = _value;
}

string t_sdp_attr::encode(void) const {
	string s;

	s = "a=";
	s += name;

	if (value != "") {
		s += ':' + value;
	}
	
	s += CRLF;

	return s;
}


///////////////////////////////////
// class t_sdp_media
///////////////////////////////////

t_sdp_media::t_sdp_media() {
	port = 0;
	transport = SDP_TRANS_NULL;
	format_dtmf = 0;
}

t_sdp_media::t_sdp_media(t_sdp_media_type _media_type,
			 unsigned short _port, list<unsigned short> _formats,
			 unsigned short _format_dtmf)
{
	media_type = sdp_media_type2str(_media_type);
	port = _port;
	transport = SDP_TRANS_RTP;
	format_dtmf = _format_dtmf;

	for (list<unsigned short>::const_iterator i = _formats.begin();
	     i != _formats.end(); i++)
	{
		add_format(*i);
	}

	if (format_dtmf > 0) {
		add_format(format_dtmf);
	}
}

string t_sdp_media::encode(void) const {
	string s;

	s = "m=";
	s += media_type;
	s += ' ' + int2str(port);
	s += ' ' + sdp_transport2str(transport);

	for (list<unsigned short>::const_iterator i = formats.begin();
	     i != formats.end(); i++)
	{
		s += ' ' + int2str(*i);
	}

	s += CRLF;

	if (connection.network_type != SDP_NTWK_NULL) {
		s += connection.encode();
	}

	for (list<t_sdp_attr>::const_iterator i = attributes.begin();
	     i != attributes.end(); i++)
	{
		s += i->encode();
	}

	return s;
}

void t_sdp_media::add_format(unsigned short f) {
	formats.push_back(f);

	// RFC 3264 5.1
	// All media descriptions SHOULD contain an rtpmap
	string rtpmap = get_rtpmap(f, format_dtmf);
	attributes.push_back(t_sdp_attr("rtpmap", rtpmap));

	// RFC 2833 3.9
	// Add fmtp parameter
	if (format_dtmf > 0 && f == format_dtmf) {
		string fmtp = int2str(f);
		fmtp += ' ';
		fmtp += "0-15";
		attributes.push_back(t_sdp_attr("fmtp", fmtp));
	}
}

t_sdp_attr *t_sdp_media::get_attribute(const string &name) {
	for (list<t_sdp_attr>::iterator i = attributes.begin();
	     i != attributes.end(); i++)
	{
		if (cmp_nocase(i->name, name) == 0) return &(*i);
	}

	// Attribute does not exist
	return NULL;
}

list<t_sdp_attr *> t_sdp_media::get_attributes(const string &name) {
	list<t_sdp_attr *> l;

	for (list<t_sdp_attr>::iterator i = attributes.begin();
	     i != attributes.end(); i++)
	{
		if (cmp_nocase(i->name, name) == 0) l.push_back(&(*i));
	}

	return l;
}

t_sdp_media_direction t_sdp_media::get_direction(void) const {
	t_sdp_attr *a;

	t_sdp_media *self = const_cast<t_sdp_media *>(this);

	a = self->get_attribute("inactive");
	if (a) return SDP_INACTIVE;

	a = self->get_attribute("sendonly");
	if (a) return SDP_SENDONLY;

	a = self->get_attribute("recvonly");
	if (a) return SDP_RECVONLY;

	return SDP_SENDRECV;
}

t_sdp_media_type t_sdp_media::get_media_type(void) const {
	return str2sdp_media_type(media_type);
}

///////////////////////////////////
// class t_sdp
///////////////////////////////////

t_sdp::t_sdp() : t_sip_body() {
	version = 0;
}

t_sdp::t_sdp(string user, string sess_id, string sess_version,
	     string media_host, unsigned short media_port,
	     list<unsigned short> formats, unsigned short format_dtmf) :
		origin(user, sess_id, sess_version, media_host),
		connection(media_host)
{
	version = 0;
	media.push_back(t_sdp_media(SDP_AUDIO, media_port, formats, format_dtmf));
}

t_sdp::t_sdp(string user, string sess_id, string sess_version, string media_host) :
		origin(user, sess_id, sess_version, media_host),
		connection(media_host)
{
	version = 0;
}

void t_sdp::add_media(const t_sdp_media &m) {
	media.push_back(m);
}

string t_sdp::encode(void) const {
	string s;

	s = "v=" + int2str(version) + CRLF;
	s += origin.encode();

	if (session_name == "") {
		// RFC 3264 5
		// Session name may no be empty. Recommende is '-'
		s += "s=-";
		s += CRLF;
	} else {
		s += "s=" + session_name + CRLF;
	}

	if (connection.network_type != SDP_NTWK_NULL) {
		s += connection.encode();
	}

	// RFC 3264 5
	// Time parameter should be 0 0
	s += "t=0 0";
	s += CRLF;

	for (list<t_sdp_attr>::const_iterator i = attributes.begin();
	     i != attributes.end(); i++)
	{
		s += i->encode();
	}

	for (list<t_sdp_media>::const_iterator i = media.begin();
	     i != media.end(); i++)
	{
		s += i->encode();
	}

	return s;
}

t_sip_body *t_sdp::copy(void) const {
	t_sdp *s = new t_sdp(*this);
	MEMMAN_NEW(s);
	return s;
}

t_body_type t_sdp::get_type(void) const {
	return BODY_SDP;
}

bool t_sdp::is_supported(int &warn_code, string &warn_text) const {
	warn_text = "";

	if (version != 0) {
		warn_code = W_399_MISCELLANEOUS;
		warn_text = "SDP version ";
		warn_text += int2str(version);
		warn_text += " not supported";
		return false;
	}

	// There must be at least 1 audio stream with a non-zero port value
	const t_sdp_media *m = get_first_media(SDP_AUDIO);

	if (m == NULL) {
		warn_code = W_304_MEDIA_TYPE_NOT_AVAILABLE;
		warn_text = "Valid media stream for audio is missing";
		return false;
	}

	// Connection information must be present at the session level
	// and/or the media level
	if (connection.network_type == SDP_NTWK_NULL) {
		if (m->connection.network_type == SDP_NTWK_NULL) {
			warn_code = W_399_MISCELLANEOUS;
			warn_text = "c-line missing";
			return false;
		}
	} else {
		// Only Internet is supported
		if (connection.network_type != SDP_NTWK_IN) {
			warn_code = W_300_INCOMPATIBLE_NWK_PROT;
			return false;
		}

		// Only IPv4 is supported
		if (connection.address_type != SDP_ADDR_IP4) {
			warn_code = W_301_INCOMPATIBLE_ADDR_FORMAT;
			return false;
		}
	}

	// Check connection informatio on media level
	if (m->connection.network_type != SDP_NTWK_NULL &&
	    m->connection.address_type != SDP_ADDR_IP4) {
		warn_code = W_301_INCOMPATIBLE_ADDR_FORMAT;
		return false;
	}

	if (m->transport != SDP_TRANS_RTP) {
		warn_code = W_302_INCOMPATIBLE_TRANS_PROT;
		return false;
	}

	t_sdp_media *m2 = const_cast<t_sdp_media *>(m);
	const t_sdp_attr *a = m2->get_attribute("ptime");
	if (a) {
		unsigned short p = atoi(a->value.c_str());
		if (p < MIN_PTIME) {
			warn_code = W_306_ATTRIBUTE_NOT_UNDERSTOOD;
			warn_text = "Attribute 'ptime' too small. must be >= ";
			warn_text += int2str(MIN_PTIME);
			return false;
		}

		if (p > MAX_PTIME) {
			warn_code = W_306_ATTRIBUTE_NOT_UNDERSTOOD;
			warn_text = "Attribute 'ptime' too big. must be <= ";
			warn_text += int2str(MAX_PTIME);
			return false;
		}

	}

	return true;
}

string t_sdp::get_rtp_host(t_sdp_media_type media_type) const {
	const t_sdp_media *m = get_first_media(media_type);
	assert(m != NULL);

	// If the media line has its own connection information, then
	// take the host information from there.
	if (m->connection.network_type == SDP_NTWK_IN) {
		return m->connection.address;
	}

	// The host information must be in the session connection info
	assert(connection.network_type == SDP_NTWK_IN);
	return connection.address;
}

unsigned short t_sdp::get_rtp_port(t_sdp_media_type media_type) const {
	const t_sdp_media *m = get_first_media(media_type);
	assert(m != NULL);

	return m->port;
}

list<unsigned short> t_sdp::get_codecs(t_sdp_media_type media_type) const {
	const t_sdp_media *m = get_first_media(media_type);
	assert(m != NULL);

	return m->formats;
}

string t_sdp::get_codec_description(t_sdp_media_type media_type,
		unsigned short codec) const
{
	t_sdp_media *m = const_cast<t_sdp_media *>(get_first_media(media_type));
	assert(m != NULL);

	const list<t_sdp_attr *> attrs = m->get_attributes("rtpmap");
	if (attrs.empty()) return "";

	for (list<t_sdp_attr *>::const_iterator i = attrs.begin();
	     i != attrs.end(); i++)
	{
		list<string> l = split_ws((*i)->value);
		if (atoi(l.front().c_str()) == codec) {
			return l.back();
		}
	}

	return "";
}

t_sdp_media_direction t_sdp::get_direction(t_sdp_media_type media_type) const {
	const t_sdp_media *m = get_first_media(media_type);
	assert(m != NULL);

	return m->get_direction();
}

unsigned short t_sdp::get_ptime(t_sdp_media_type media_type) const {
	t_sdp_media *m = const_cast<t_sdp_media *>(get_first_media(media_type));
	assert(m != NULL);

	const t_sdp_attr *a = m->get_attribute("ptime");
	if (!a) return 0;
	return atoi(a->value.c_str());
}

void t_sdp::set_ptime(t_sdp_media_type media_type, unsigned short ptime) {
	t_sdp_media *m = const_cast<t_sdp_media *>(get_first_media(media_type));
	assert(m != NULL);

	t_sdp_attr a("ptime", int2str(ptime));
	m->attributes.push_back(a);
}

void t_sdp::set_direction(t_sdp_media_type media_type, t_sdp_media_direction direction) {
	t_sdp_media *m = const_cast<t_sdp_media *>(get_first_media(media_type));
	assert(m != NULL);

	t_sdp_attr a(sdp_media_direction2str(direction));
	m->attributes.push_back(a);
}

const t_sdp_media *t_sdp::get_first_media(t_sdp_media_type media_type) const {
	for (list<t_sdp_media>::const_iterator i = media.begin();
	     i != media.end(); i++)
	{
		if (i->get_media_type() == media_type && i->port != 0) {
			return &(*i);
		}
	}

	return NULL;
}
