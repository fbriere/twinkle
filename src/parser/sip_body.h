/*
    Copyright (C) 2005-2008  Michel de Boer <michel@twinklephone.com>

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

// SIP bodies
#ifndef _H_SIP_BODY
#define _H_SIP_BODY

#include <cc++/config.h>
#include <string>

#include "media_type.h"

class t_sip_message;

using namespace std;

/** Body type. */
enum t_body_type {
	BODY_OPAQUE,		/**< Opaque body. */
	BODY_SDP,		/**< SDP */
	BODY_SIPFRAG,		/**< message/sipfrag RFC 3420 */
	BODY_DTMF_RELAY,	/**< DTMF relay as defined by Cisco */
	BODY_SIMPLE_MSG_SUM,	/**< Simple message summary RFC 3842 */
	BODY_PLAIN_TEXT,	/**< Plain text for messaging */
	BODY_HTML_TEXT,		/**< HTML text for messaging */
	BODY_PIDF_XML		/**< pidx+xml RFC 3863 */
};

/** Abstract base class for SIP bodies. */
class t_sip_body {
public:
	/**
	 * Indicates if the body content is invalid.
	 * This will be set by the body parser.
	 */
	bool 	invalid;

	/** Constructor. */
	t_sip_body();
	
	virtual ~t_sip_body() {}

	/**
	 * Encode the body.
	 * @return Text encoded body.
	 */
	virtual string encode(void) const = 0;

	/**
	 * Create a copy of the body.
	 * @return Copy of the body.
	 */
	virtual t_sip_body *copy(void) const = 0;

	/** 
	 * Get type of body.
	 * @return body type.
	 */
	virtual t_body_type get_type(void) const = 0;
	
	/**
	 * Get content type for this type of body.
	 * @return Content type.
	 */
	virtual t_media get_media(void) const = 0;
	
	/**
	 * Check if all local IP address are correctly filled in. This
	 * check is an integrity check to help debugging the auto IP
	 * discover feature.
	 */
	virtual bool local_ip_check(void) const;
};


// Opaque bodies
class t_sip_body_opaque : public t_sip_body {
public:
	string	opaque;

	t_sip_body_opaque(string s);
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
	t_media get_media(void) const;
};

// RFC 3420
// sipfrag body
class t_sip_body_sipfrag : public t_sip_body {
public:
	t_sip_message	*sipfrag;

	t_sip_body_sipfrag(t_sip_message *m);
	~t_sip_body_sipfrag();
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
	t_media get_media(void) const;
};

// application/dtmf-relay body
class t_sip_body_dtmf_relay : public t_sip_body {
public:
	char	signal;
	uint16	duration; // ms
	
	t_sip_body_dtmf_relay();
	t_sip_body_dtmf_relay(char _signal, uint16 _duration);
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
	t_media get_media(void) const;
	bool parse(const string &s);
};

/** Plain text body. */
class t_sip_body_plain_text : public t_sip_body {
public:
	string	text;	/**< The text */
	
	/**
	 * Constructor.
	 * @param _text [in] The body text.
	 */
	t_sip_body_plain_text(const string &_text);
	
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
	t_media get_media(void) const;
};

/** Html text body. */
class t_sip_body_html_text : public t_sip_body {
public:
	string	text;	/**< The text */
	
	/**
	 * Constructor.
	 * @param _text [in] The body text.
	 */
	t_sip_body_html_text(const string &_text);
	
	string encode(void) const;
	t_sip_body *copy(void) const;
	t_body_type get_type(void) const;
	t_media get_media(void) const;
};

#endif
