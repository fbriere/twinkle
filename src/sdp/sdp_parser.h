/* A Bison parser, made from sdp_parser.yxx, by GNU bison 1.75.  */

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

#ifndef BISON_SDP_PARSER_H
# define BISON_SDP_PARSER_H

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_NUM = 258,
     T_TOKEN = 259,
     T_SAFE = 260,
     T_LINE = 261,
     T_CRLF = 262,
     T_LINE_VERSION = 263,
     T_LINE_ORIGIN = 264,
     T_LINE_SESSION_NAME = 265,
     T_LINE_CONNECTION = 266,
     T_LINE_ATTRIBUTE = 267,
     T_LINE_MEDIA = 268,
     T_LINE_UNKNOWN = 269
   };
#endif
#define T_NUM 258
#define T_TOKEN 259
#define T_SAFE 260
#define T_LINE 261
#define T_CRLF 262
#define T_LINE_VERSION 263
#define T_LINE_ORIGIN 264
#define T_LINE_SESSION_NAME 265
#define T_LINE_CONNECTION 266
#define T_LINE_ATTRIBUTE 267
#define T_LINE_MEDIA 268
#define T_LINE_UNKNOWN 269




#ifndef YYSTYPE
#line 49 "sdp_parser.yxx"
typedef union {
	int			yysdpt_int;
	string			*yysdpt_str;
	t_sdp_ntwk_type		yysdpt_ntwk_type;
	t_sdp_addr_type		yysdpt_addr_type;
	t_sdp_transport		yysdpt_transport;
	t_sdp_connection	*yysdpt_connection;
	list<t_sdp_attr>	*yysdpt_attributes;
	t_sdp_attr		*yysdpt_attribute;
	t_sdp_media		*yysdpt_media;
	list<unsigned short>	*yysdpt_num_list;
} yystype;
/* Line 1281 of /usr/share/bison/yacc.c.  */
#line 81 "y.tab.h"
# define YYSTYPE yystype
#endif

extern YYSTYPE yysdplval;


#endif /* not BISON_SDP_PARSER_H */

