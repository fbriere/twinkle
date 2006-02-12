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

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#include "twinkle_config.h"

#define CRLF		"\r\n"

// Name and version of the softphone
#define PRODUCT_NAME	"Twinkle"
#define PRODUCT_VERSION	VERSION

typedef unsigned short	t_dialog_id;

// State of a call transfer at the referrer.
enum t_refer_state {
	REFST_NULL,		// No REFER in progress
	REFST_W4RESP,		// REFER sent, waiting for response
	REFST_W4NOTIFY,		// Response received, waiting for 1st NOTIFY
	REFST_PENDING,		// REFER received, but not granted yet
	REFST_ACTIVE,		// Referee granted refer
};

// Types of registration requests
enum t_register_type {
	REG_REGISTER,
	REG_QUERY,
	REG_DEREGISTER,
	REG_DEREGISTER_ALL
};

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
	PTMR_NAT_KEEPALIVE,	// NAT binding refresh timeout for STUN
};

// UA (line) timers
enum t_line_timer {
	LTMR_ACK_TIMEOUT,	// Waiting for ACK
	LTMR_ACK_GUARD,		// After this timer ACK is lost for good
	LTMR_INVITE_COMP,	// After this timer INVITE transiction is
				// considered complete.
	LTMR_NO_ANSWER,		// This timer expires if the callee does
				// not answer. The call will be torn down.
	LTMR_RE_INVITE_GUARD,	// re-INVITE timeout
	LTMR_100REL_TIMEOUT,	// Waiting for PRACK
	LTMR_100REL_GUARD,	// After this timer PRACK is lost for good
	LTMR_GLARE_RETRY,	// Waiting before retry re-INVITE after glare
	LTMR_CANCEL_GUARD,	// Guard for situation where CANCEL has been 
				// responded to, but 487 on INVITE is never
				// received.
};

// Subscription timers
enum t_subscribe_timer {
	STMR_SUBSCRIPTION,	// Subscription timeout
};

// STUN timers
enum t_stun_timer {
	STUN_TMR_REQ_TIMEOUT,	// Waiting for response
};


// No answer timer (ms)
#define DUR_NO_ANSWER(u)	((u)->timer_noanswer * 1000)

// Registration timers (s)
// Registration duration (seconds)
#define DUR_REGISTRATION(u)	((u)->registration_time)
#define RE_REGISTER_DELTA	5   // Re-register 5 seconds before expiry
#define DUR_REG_FAILURE         30  // Re-registration interval after reg. failure

// NAT keepalive timer (s) default value
#define DUR_NAT_KEEPALIVE	30

// re-INVITE guard timer (ms). This timer guards against the situation
// where a UAC has sent a re-INVITE, received a 1XX but never receives
// a final response. No timer for this is defined in RFC 3261
#define DUR_RE_INVITE_GUARD	10000

// Guard for situation where CANCEL has been 
// responded to, but 487 on INVITE is never eceived.
// This situation is not defined by RFC 3261
#define DUR_CANCEL_GUARD	(64 * DURATION_T1)

// RFC 3261 14.1
// Maximum values (10th of sec) for timers for retrying a re-INVITE after
// a glare (491 response).
#define MAX_GLARE_RETRY_NOT_OWN	20
#define MAX_GLARE_RETRY_OWN	40

// Calculate the glare retry duration (ms)
#define DUR_GLARE_RETRY_NOT_OWN	((rand() % (MAX_GLARE_RETRY_NOT_OWN + 1)) * 100)
#define DUR_GLARE_RETRY_OWN	((rand() % (MAX_GLARE_RETRY_OWN - \
				MAX_GLARE_RETRY_NOT_OWN) + 1 + MAX_GLARE_RETRY_NOT_OWN)\
				* 100)

// RFC 3262
// PRACK timers
#define DUR_100REL_TIMEOUT	DURATION_T1
#define DUR_100REL_GUARD	(64 * DURATION_T1)

// refer subscription timer (s)
// RFC 3515 does not define the length of the timer.
// It should be long enough to notify the result of an INVITE.
#define DUR_REFER_SUBSCRIPTION	60 // Used when refer is always permitted
#define DUR_REFER_SUB_INTERACT	90 // Used when user has to grant permission

// Minimum duration of a subscription
#define MIN_DUR_SUBSCRIPTION	60

// After an unsubscribe has been sent, a NOTIFY will should come in.
// In case the NOTIFY does not come, this guard timer (ms) will assure
// that the subscription will be cleaned up.
#define DUR_UNSUBSCRIBE_GUARD	4000

// RFC 3489
// STUN retransmission timer intervals (ms)
// The RFC states that the interval should start at 100ms. But that
// seems to short. We start at 200 and do 8 instead of 9 transmissions.
#define DUR_STUN_START_INTVAL	200
#define DUR_STUN_MAX_INTVAL	1600

// Maximum number of transmissions
#define STUN_MAX_TRANSMISSIONS	8

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
#define NEW_CALL_ID(u)	(random_token(CALL_ID_LEN) + '@' + USER_HOST(u))

// Create a new sequence number fo CSeq header
#define NEW_SEQNR	rand() % 1000 + 1

// Length of cnonce
#define CNONCE_LEN	10

// Create a cnonce
#define NEW_CNONCE	random_hexstr(CNONCE_LEN)

// Set Allow header with methods that can be handled by the phone
#define SET_HDR_ALLOW(h, u)	{ (h).add_method(INVITE); \
				  (h).add_method(ACK); \
				  (h).add_method(BYE); \
				  (h).add_method(CANCEL); \
				  (h).add_method(OPTIONS); \
				  if ((u)->ext_100rel != EXT_DISABLED) {\
				  	(h).add_method(PRACK);\
				  }\
				  (h).add_method(REFER); \
				  (h).add_method(NOTIFY); \
				  (h).add_method(SUBSCRIBE); \
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
#define SET_HDR_ORGANIZATION(h, u)	{ if ((u)->organization != "") {\
					(h).set_name((u)->organization); }}

#endif
