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

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include "twinkle_config.h"

#define CRLF		"\r\n"

// Name and version of the softphone
#define PRODUCT_NAME	"Twinkle"
#define PRODUCT_VERSION	VERSION

typedef unsigned short	t_dialog_id;

// RFC 3261 Annex A
// SIP timers
enum t_sip_timer {
	TIMER_T1,
	TIMER_T2,
	TIMER_T4,
	TIMER_A,
	TIMER_B,
	TIMER_C,
	TIMER_D,
	TIMER_E,
	TIMER_F,
	TIMER_G,
	TIMER_H,
	TIMER_I,
	TIMER_J,
	TIMER_K
};

// All durations are in msec
#define DURATION_T1	500
#define DURATION_T2	4000
#define DURATION_T4	5000
#define DURATION_A	DURATION_T1
#define DURATION_B	(64 * DURATION_T1)
#define DURATION_C	180000
#define DURATION_D	32000
#define DURATION_E	DURATION_T1
#define DURATION_F	(64 * DURATION_T1)
#define DURATION_G	DURATION_T1
#define DURATION_H	(64 * DURATION_T1)
#define DURATION_I	DURATION_T4
#define DURATION_J	(64 * DURATION_T1)
#define DURATION_K	DURATION_T4

// UA (phone) timers
enum t_phone_timer {
	PTMR_REGISTRATION,	// Registration (failure) timeout
};

// UA (line) timers
enum t_line_timer {
	LTMR_ACK_TIMEOUT,	// Waiting for ACK
	LTMR_ACK_GUARD,		// After this timer ACK is lost for good
	LTMR_INVITE_COMP,	// After this timer INVITE transiction is
				// cosidered complete.
	LTMR_NO_ANSWER,		// This timer expires if the callee does
				// not answer. The call will be torn down.
	LTMR_RE_INVITE_GUARD,	// re-INVITE timeout
	LTMR_100REL_TIMEOUT,	// Waiting for PRACK
	LTMR_100REL_GUARD,	// After this timer PRACK is lost for good
};


// No answer timer (ms)
#define DUR_NO_ANSWER	(user_config->timer_noanswer * 1000)

// Registration timers (s)
// Registration duration (seconds)
#define DUR_REGISTRATION	(user_config->registration_time)
#define RE_REGISTER_DELTA	5   // Re-register 5 seconds before expiry
#define DUR_REG_FAILURE         30  // Re-registration interval after reg. failure

// re-INVITE guard timer (ms). This timer guards against the situation
// where a UAC has sent a re-INVITE, received a 1XX but never receives
// a final response. No timer for this is defined in RFC 3261
#define DUR_RE_INVITE_GUARD	10000

// RFC 3262
// PRACK timers
#define DUR_100REL_TIMEOUT	DURATION_T1
#define DUR_100REL_GUARD	(64 * DURATION_T1)

// RFC 3261
#ifndef RFC3261_COOKIE
#define RFC3261_COOKIE	"z9hG4bK"
#endif

// Max forwards RFC 3261 8.1.1.6
#define MAX_FORWARDS	70

// Length of tags in from and to headers
#define TAG_LEN		5

// Create a new tag
#define NEW_TAG		random_token(TAG_LEN)

// Length of call-id (before domain)
#define CALL_ID_LEN	15

// Create a new call-id
#define NEW_CALL_ID	(random_token(CALL_ID_LEN) + '@' + USER_HOST)

// Create a new sequence number fo CSeq header
#define NEW_SEQNR	rand() % 1000 + 1

// Length of cnonce
#define CNONCE_LEN	10

// Create a cnonce
#define NEW_CNONCE	random_hexstr(CNONCE_LEN)

// Set Allow header with methods that can be handled by the phone
#define SET_HDR_ALLOW(h)	{ (h).add_method(INVITE); \
				  (h).add_method(ACK); \
				  (h).add_method(BYE); \
				  (h).add_method(CANCEL); \
				  (h).add_method(OPTIONS); \
				  if (user_config->ext_100rel != EXT_DISABLED) {\
				  	(h).add_method(PRACK);\
				  }\
				}

// Set Supported header with supported extensions
#define SET_HDR_SUPPORTED(h)	{ (h).set_empty(); }

// Set Accept header with accepted body types
#define SET_HDR_ACCEPT(h)	{ (h).add_media(t_media("application",\
				  "sdp")); }

// Set Accept-Encoding header with accepted encodings
#define SET_HDR_ACCEPT_ENCODING(h)\
				{ (h).add_coding(t_coding("identity")); }

// Set Accept-Language header with accepted languages
#define SET_HDR_ACCEPT_LANGUAGE(h)\
				{ (h).add_language(t_language("en")); }

// Set User-Agent header
#define SET_HDR_USER_AGENT(h)	{ (h).add_server(t_server(PRODUCT_NAME,\
					PRODUCT_VERSION)); }

// Set Server header
#define SET_HDR_SERVER(h)	{ (h).add_server(t_server(PRODUCT_NAME,\
					PRODUCT_VERSION)); }

// Set Organization header
#define SET_HDR_ORGANIZATION(h)	{ if (user_config->organization != "") {\
					(h).set_name(user_config->organization); }}

#endif
