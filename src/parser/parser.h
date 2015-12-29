/* A Bison parser, made from parser.yxx, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef BISON_PARSER_H
# define BISON_PARSER_H

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_NUM = 258,
     T_TOKEN = 259,
     T_QSTRING = 260,
     T_COMMENT = 261,
     T_LINE = 262,
     T_URI = 263,
     T_URI_WILDCARD = 264,
     T_DISPLAY = 265,
     T_LANG = 266,
     T_WORD = 267,
     T_WKDAY = 268,
     T_MONTH = 269,
     T_GMT = 270,
     T_SIP = 271,
     T_METHOD = 272,
     T_AUTH_DIGEST = 273,
     T_AUTH_OTHER = 274,
     T_HDR_ACCEPT = 275,
     T_HDR_ACCEPT_ENCODING = 276,
     T_HDR_ACCEPT_LANGUAGE = 277,
     T_HDR_ALERT_INFO = 278,
     T_HDR_ALLOW = 279,
     T_HDR_AUTHENTICATION_INFO = 280,
     T_HDR_AUTHORIZATION = 281,
     T_HDR_CALL_ID = 282,
     T_HDR_CALL_INFO = 283,
     T_HDR_CONTACT = 284,
     T_HDR_CONTENT_DISP = 285,
     T_HDR_CONTENT_ENCODING = 286,
     T_HDR_CONTENT_LANGUAGE = 287,
     T_HDR_CONTENT_LENGTH = 288,
     T_HDR_CONTENT_TYPE = 289,
     T_HDR_CSEQ = 290,
     T_HDR_DATE = 291,
     T_HDR_ERROR_INFO = 292,
     T_HDR_EXPIRES = 293,
     T_HDR_FROM = 294,
     T_HDR_IN_REPLY_TO = 295,
     T_HDR_MAX_FORWARDS = 296,
     T_HDR_MIN_EXPIRES = 297,
     T_HDR_MIME_VERSION = 298,
     T_HDR_ORGANIZATION = 299,
     T_HDR_PRIORITY = 300,
     T_HDR_PROXY_AUTHENTICATE = 301,
     T_HDR_PROXY_AUTHORIZATION = 302,
     T_HDR_PROXY_REQUIRE = 303,
     T_HDR_RACK = 304,
     T_HDR_RECORD_ROUTE = 305,
     T_HDR_REPLY_TO = 306,
     T_HDR_REQUIRE = 307,
     T_HDR_RETRY_AFTER = 308,
     T_HDR_ROUTE = 309,
     T_HDR_RSEQ = 310,
     T_HDR_SERVER = 311,
     T_HDR_SUBJECT = 312,
     T_HDR_SUPPORTED = 313,
     T_HDR_TIMESTAMP = 314,
     T_HDR_TO = 315,
     T_HDR_UNSUPPORTED = 316,
     T_HDR_USER_AGENT = 317,
     T_HDR_VIA = 318,
     T_HDR_WARNING = 319,
     T_HDR_WWW_AUTHENTICATE = 320,
     T_HDR_UNKNOWN = 321,
     T_CRLF = 322,
     T_ERROR = 323
   };
#endif
#define T_NUM 258
#define T_TOKEN 259
#define T_QSTRING 260
#define T_COMMENT 261
#define T_LINE 262
#define T_URI 263
#define T_URI_WILDCARD 264
#define T_DISPLAY 265
#define T_LANG 266
#define T_WORD 267
#define T_WKDAY 268
#define T_MONTH 269
#define T_GMT 270
#define T_SIP 271
#define T_METHOD 272
#define T_AUTH_DIGEST 273
#define T_AUTH_OTHER 274
#define T_HDR_ACCEPT 275
#define T_HDR_ACCEPT_ENCODING 276
#define T_HDR_ACCEPT_LANGUAGE 277
#define T_HDR_ALERT_INFO 278
#define T_HDR_ALLOW 279
#define T_HDR_AUTHENTICATION_INFO 280
#define T_HDR_AUTHORIZATION 281
#define T_HDR_CALL_ID 282
#define T_HDR_CALL_INFO 283
#define T_HDR_CONTACT 284
#define T_HDR_CONTENT_DISP 285
#define T_HDR_CONTENT_ENCODING 286
#define T_HDR_CONTENT_LANGUAGE 287
#define T_HDR_CONTENT_LENGTH 288
#define T_HDR_CONTENT_TYPE 289
#define T_HDR_CSEQ 290
#define T_HDR_DATE 291
#define T_HDR_ERROR_INFO 292
#define T_HDR_EXPIRES 293
#define T_HDR_FROM 294
#define T_HDR_IN_REPLY_TO 295
#define T_HDR_MAX_FORWARDS 296
#define T_HDR_MIN_EXPIRES 297
#define T_HDR_MIME_VERSION 298
#define T_HDR_ORGANIZATION 299
#define T_HDR_PRIORITY 300
#define T_HDR_PROXY_AUTHENTICATE 301
#define T_HDR_PROXY_AUTHORIZATION 302
#define T_HDR_PROXY_REQUIRE 303
#define T_HDR_RACK 304
#define T_HDR_RECORD_ROUTE 305
#define T_HDR_REPLY_TO 306
#define T_HDR_REQUIRE 307
#define T_HDR_RETRY_AFTER 308
#define T_HDR_ROUTE 309
#define T_HDR_RSEQ 310
#define T_HDR_SERVER 311
#define T_HDR_SUBJECT 312
#define T_HDR_SUPPORTED 313
#define T_HDR_TIMESTAMP 314
#define T_HDR_TO 315
#define T_HDR_UNSUPPORTED 316
#define T_HDR_USER_AGENT 317
#define T_HDR_VIA 318
#define T_HDR_WARNING 319
#define T_HDR_WWW_AUTHENTICATE 320
#define T_HDR_UNKNOWN 321
#define T_CRLF 322
#define T_ERROR 323




#ifndef YYSTYPE
#line 49 "parser.yxx"
typedef union {
	int			yyt_int;
	ulong			yyt_ulong;
	float			yyt_float;
	string			*yyt_str;
	t_parameter		*yyt_param;
	list<t_parameter>	*yyt_params;
	t_media			*yyt_media;
	t_coding		*yyt_coding;
	t_language		*yyt_language;
	t_alert_param		*yyt_alert_param;
	t_info_param		*yyt_info_param;
	list<t_contact_param>	*yyt_contacts;
	t_contact_param		*yyt_contact;
	t_error_param		*yyt_error_param;
	t_hdr_from		*yyt_from_addr;
	t_route			*yyt_route;
	t_server		*yyt_server;
	t_via			*yyt_via;
	t_warning		*yyt_warning;
	t_digest_response	*yyt_dig_resp;
	t_credentials		*yyt_credentials;
	t_digest_challenge	*yyt_dig_chlg;
	t_challenge		*yyt_challenge;
} yystype;
/* Line 1281 of /usr/share/bison/yacc.c.  */
#line 202 "y.tab.h"
# define YYSTYPE yystype
#endif

extern YYSTYPE yylval;


#endif /* not BISON_PARSER_H */

