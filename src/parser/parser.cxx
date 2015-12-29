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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 19 "parser.yxx"

#include <cstdio>
#include <cstdlib>
#include <string>
#include "media_type.h"
#include "parameter.h"
#include "parse_ctrl.h"
#include "request.h"
#include "response.h"
#include "util.h"
#include "audits/memman.h"

using namespace std;

extern int yylex(void);
void yyerror(const char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
/* Line 193 of /usr/share/bison/yacc.c.  */
#line 253 "parser.cxx"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/share/bison/yacc.c.  */
#line 274 "parser.cxx"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];	\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
#define YYLAST   611

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  210
/* YYNRULES -- Number of rules. */
#define YYNRULES  350
/* YYNRULES -- Number of states. */
#define YYNSTATES  637

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      77,    78,     2,     2,    71,     2,    79,    69,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,    72,
      74,    73,    75,     2,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    15,    16,    17,
      24,    25,    30,    34,    35,    36,    37,    45,    46,    49,
      53,    57,    61,    65,    69,    73,    77,    81,    85,    89,
      93,    97,   101,   105,   109,   113,   117,   121,   125,   129,
     133,   137,   141,   145,   149,   153,   157,   161,   165,   169,
     173,   177,   181,   185,   189,   193,   197,   201,   205,   209,
     213,   217,   221,   225,   229,   233,   238,   242,   246,   250,
     254,   258,   262,   266,   270,   274,   278,   282,   286,   290,
     294,   298,   302,   306,   310,   314,   318,   322,   326,   330,
     334,   338,   342,   346,   350,   354,   358,   362,   366,   370,
     374,   378,   382,   386,   390,   394,   398,   402,   406,   410,
     414,   418,   422,   425,   428,   431,   434,   437,   440,   443,
     446,   449,   452,   455,   458,   461,   464,   467,   470,   473,
     476,   479,   482,   485,   488,   491,   494,   497,   500,   503,
     506,   509,   512,   515,   518,   521,   524,   527,   530,   533,
     536,   539,   542,   545,   548,   551,   554,   557,   560,   561,
     564,   569,   573,   574,   578,   580,   584,   588,   590,   594,
     596,   599,   602,   603,   606,   607,   612,   614,   615,   619,
     621,   625,   626,   627,   634,   636,   640,   641,   642,   646,
     648,   652,   654,   658,   659,   660,   667,   668,   669,   673,
     675,   677,   681,   684,   685,   686,   690,   691,   692,   699,
     700,   702,   704,   707,   709,   713,   714,   717,   718,   723,
     724,   725,   729,   732,   733,   734,   739,   740,   741,   755,
     757,   761,   762,   763,   770,   771,   772,   776,   777,   781,
     782,   785,   786,   792,   793,   794,   798,   799,   800,   806,
     807,   808,   812,   813,   814,   818,   820,   821,   822,   826,
     828,   830,   834,   836,   840,   841,   842,   850,   851,   855,
     857,   861,   862,   863,   869,   870,   871,   872,   878,   880,
     884,   886,   889,   892,   897,   898,   899,   903,   904,   906,
     910,   911,   914,   916,   919,   921,   925,   927,   931,   932,
     936,   938,   942,   944,   947,   949,   953,   957,   963,   965,
     966,   967,   973,   975,   979,   980,   981,   987,   988,   989,
     993,   995,   997,  1001,  1003,  1007,  1009,  1013,  1014,  1018,
    1019,  1023,  1024,  1027,  1029,  1033,  1034,  1038,  1039,  1043,
    1044,  1047,  1048,  1051,  1052,  1055,  1056,  1057,  1061,  1062,
    1063
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      81,     0,    -1,    -1,    82,    83,    -1,    84,    -1,    90,
      -1,    85,    95,    67,    -1,    -1,    -1,    17,    86,     8,
      87,    88,    67,    -1,    -1,    16,    89,    69,     4,    -1,
      91,    95,    67,    -1,    -1,    -1,    -1,    88,    92,     3,
      93,     7,    94,    67,    -1,    -1,    95,    96,    -1,    97,
     143,    67,    -1,    98,   147,    67,    -1,    99,   150,    67,
      -1,   100,   155,    67,    -1,   101,   159,    67,    -1,   102,
     266,    67,    -1,   103,   272,    67,    -1,   104,   160,    67,
      -1,   105,   164,    67,    -1,   106,   168,    67,    -1,   107,
     179,    67,    -1,   108,   180,    67,    -1,   109,   181,    67,
      -1,   110,   184,    67,    -1,   111,   187,    67,    -1,   112,
     188,    67,    -1,   113,   191,    67,    -1,   114,   194,    67,
      -1,   115,   198,    67,    -1,   116,   201,    67,    -1,   117,
     206,    67,    -1,   118,   211,    67,    -1,   119,   214,    67,
      -1,   120,   217,    67,    -1,   121,   218,    67,    -1,   122,
     221,    67,    -1,   123,   278,    67,    -1,   124,   280,    67,
      -1,   125,   222,    67,    -1,   126,   287,    67,    -1,   127,
     223,    67,    -1,   128,   227,    67,    -1,   129,   229,    67,
      -1,   130,   230,    67,    -1,   131,   236,    67,    -1,   132,
     284,    67,    -1,   133,   237,    67,    -1,   134,   239,    67,
      -1,   135,   242,    67,    -1,   136,   243,    67,    -1,   137,
     248,    67,    -1,   138,   250,    67,    -1,   139,   251,    67,
      -1,   140,   252,    67,    -1,   141,   258,    67,    -1,   142,
     282,    67,    -1,    66,    70,   262,    67,    -1,    97,     1,
      67,    -1,    98,     1,    67,    -1,    99,     1,    67,    -1,
     100,     1,    67,    -1,   101,     1,    67,    -1,   102,     1,
      67,    -1,   103,     1,    67,    -1,   104,     1,    67,    -1,
     105,     1,    67,    -1,   106,     1,    67,    -1,   107,     1,
      67,    -1,   108,     1,    67,    -1,   109,     1,    67,    -1,
     110,     1,    67,    -1,   111,     1,    67,    -1,   112,     1,
      67,    -1,   113,     1,    67,    -1,   114,     1,    67,    -1,
     115,     1,    67,    -1,   116,     1,    67,    -1,   117,     1,
      67,    -1,   118,     1,    67,    -1,   119,     1,    67,    -1,
     120,     1,    67,    -1,   121,     1,    67,    -1,   122,     1,
      67,    -1,   123,     1,    67,    -1,   124,     1,    67,    -1,
     125,     1,    67,    -1,   126,     1,    67,    -1,   127,     1,
      67,    -1,   128,     1,    67,    -1,   129,     1,    67,    -1,
     130,     1,    67,    -1,   131,     1,    67,    -1,   132,     1,
      67,    -1,   133,     1,    67,    -1,   134,     1,    67,    -1,
     135,     1,    67,    -1,   136,     1,    67,    -1,   137,     1,
      67,    -1,   138,     1,    67,    -1,   139,     1,    67,    -1,
     140,     1,    67,    -1,   141,     1,    67,    -1,   142,     1,
      67,    -1,    20,    70,    -1,    21,    70,    -1,    22,    70,
      -1,    23,    70,    -1,    24,    70,    -1,    25,    70,    -1,
      26,    70,    -1,    27,    70,    -1,    28,    70,    -1,    29,
      70,    -1,    30,    70,    -1,    31,    70,    -1,    32,    70,
      -1,    33,    70,    -1,    34,    70,    -1,    35,    70,    -1,
      36,    70,    -1,    37,    70,    -1,    38,    70,    -1,    39,
      70,    -1,    40,    70,    -1,    41,    70,    -1,    42,    70,
      -1,    43,    70,    -1,    44,    70,    -1,    45,    70,    -1,
      46,    70,    -1,    47,    70,    -1,    48,    70,    -1,    49,
      70,    -1,    50,    70,    -1,    51,    70,    -1,    52,    70,
      -1,    53,    70,    -1,    54,    70,    -1,    55,    70,    -1,
      56,    70,    -1,    57,    70,    -1,    58,    70,    -1,    59,
      70,    -1,    60,    70,    -1,    61,    70,    -1,    62,    70,
      -1,    63,    70,    -1,    64,    70,    -1,    65,    70,    -1,
      -1,   144,   145,    -1,   143,    71,   144,   145,    -1,     4,
      69,     4,    -1,    -1,   145,    72,   146,    -1,     4,    -1,
       4,    73,     4,    -1,     4,    73,     5,    -1,   148,    -1,
     147,    71,   148,    -1,     4,    -1,     4,   149,    -1,    72,
     146,    -1,    -1,   151,   153,    -1,    -1,   150,    71,   152,
     153,    -1,    11,    -1,    -1,    11,   154,   149,    -1,   156,
      -1,   155,    71,   156,    -1,    -1,    -1,    74,   157,     8,
     158,    75,   145,    -1,     4,    -1,   159,    71,     4,    -1,
      -1,    -1,   161,   163,   162,    -1,    12,    -1,    12,    76,
      12,    -1,   165,    -1,   164,    71,   165,    -1,    -1,    -1,
      74,   166,     8,   167,    75,   145,    -1,    -1,    -1,   169,
       9,   170,    -1,   171,    -1,   172,    -1,   171,    71,   172,
      -1,   173,   145,    -1,    -1,    -1,   174,     8,   175,    -1,
      -1,    -1,   176,   178,    74,     8,   177,    75,    -1,    -1,
      10,    -1,     5,    -1,     4,   145,    -1,   148,    -1,   180,
      71,   148,    -1,    -1,   182,   153,    -1,    -1,   181,    71,
     183,   153,    -1,    -1,    -1,   185,     3,   186,    -1,   144,
     145,    -1,    -1,    -1,   189,     3,   190,     4,    -1,    -1,
      -1,   192,    13,    71,     3,    14,     3,     3,    70,     3,
      70,     3,    15,   193,    -1,   195,    -1,   194,    71,   195,
      -1,    -1,    -1,    74,   196,     8,   197,    75,   145,    -1,
      -1,    -1,   199,     3,   200,    -1,    -1,   202,   203,   145,
      -1,    -1,     8,   204,    -1,    -1,   178,    74,     8,   205,
      75,    -1,    -1,    -1,   207,   163,   208,    -1,    -1,    -1,
     206,    71,   209,   163,   210,    -1,    -1,    -1,   212,     3,
     213,    -1,    -1,    -1,   215,     3,   216,    -1,     4,    -1,
      -1,    -1,   219,     7,   220,    -1,     4,    -1,     4,    -1,
     222,    71,     4,    -1,   224,    -1,   223,    71,   224,    -1,
      -1,    -1,   225,   178,    74,     8,   226,    75,   145,    -1,
      -1,   228,   203,   145,    -1,     4,    -1,   222,    71,     4,
      -1,    -1,    -1,   231,     3,   232,   233,   145,    -1,    -1,
      -1,    -1,    77,   234,     6,   235,    78,    -1,   224,    -1,
     236,    71,   224,    -1,   238,    -1,   237,   238,    -1,     4,
     233,    -1,     4,    69,     4,   233,    -1,    -1,    -1,   240,
       7,   241,    -1,    -1,     4,    -1,   242,    71,     4,    -1,
      -1,   244,   245,    -1,   246,    -1,   246,   247,    -1,     3,
      -1,     3,    79,     3,    -1,     3,    -1,     3,    79,     3,
      -1,    -1,   249,   203,   145,    -1,     4,    -1,   250,    71,
       4,    -1,   238,    -1,   251,   238,    -1,   253,    -1,   252,
      71,   253,    -1,   254,   255,   145,    -1,     4,    69,     4,
      69,     4,    -1,     4,    -1,    -1,    -1,     4,    70,   256,
       3,   257,    -1,   259,    -1,   258,    71,   259,    -1,    -1,
      -1,   260,     3,   261,   255,     5,    -1,    -1,    -1,   263,
       7,   264,    -1,   146,    -1,   265,    -1,   266,    71,   265,
      -1,   146,    -1,   267,    71,   146,    -1,   146,    -1,   268,
      71,   146,    -1,    -1,    18,   270,   267,    -1,    -1,    19,
     271,   268,    -1,    -1,   273,   269,    -1,   146,    -1,   274,
      71,   146,    -1,    -1,    18,   276,   274,    -1,    -1,    19,
     277,   268,    -1,    -1,   279,   275,    -1,    -1,   281,   269,
      -1,    -1,   283,   275,    -1,    -1,    -1,   285,     3,   286,
      -1,    -1,    -1,   288,     3,     3,   289,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   219,   219,   219,   222,   223,   226,   235,   235,   235,
     253,   253,   257,   264,   264,   265,   264,   275,   276,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   383,   385,   387,   389,   391,   393,   395,
     397,   399,   401,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   432,   434,   436,   438,   440,   442,   444,   446,
     448,   450,   452,   454,   456,   458,   460,   462,   464,   466,
     468,   470,   472,   474,   476,   478,   480,   482,   484,   486,
     488,   490,   492,   494,   496,   498,   500,   502,   504,   506,
     508,   510,   512,   514,   516,   518,   520,   522,   525,   526,
     531,   538,   544,   545,   551,   555,   560,   567,   570,   575,
     579,   586,   593,   593,   596,   596,   601,   606,   606,   613,
     616,   621,   621,   621,   635,   638,   643,   643,   643,   648,
     649,   656,   659,   664,   664,   664,   678,   678,   678,   680,
     685,   690,   696,   712,   712,   712,   722,   722,   722,   736,
     737,   741,   744,   751,   754,   759,   759,   762,   762,   767,
     767,   767,   771,   778,   778,   778,   784,   787,   784,   798,
     801,   806,   806,   806,   820,   820,   820,   824,   824,   839,
     839,   849,   849,   863,   863,   863,   866,   866,   866,   871,
     871,   871,   875,   875,   875,   879,   884,   884,   884,   889,
     894,   897,   902,   905,   910,   910,   910,   927,   927,   935,
     938,   943,   943,   943,   959,   960,   960,   960,   964,   967,
     972,   975,   980,   987,   998,   998,   998,  1003,  1005,  1008,
    1013,  1013,  1016,  1018,  1023,  1024,  1029,  1030,  1035,  1035,
    1050,  1053,  1058,  1061,  1066,  1069,  1074,  1102,  1113,  1118,
    1118,  1118,  1126,  1129,  1134,  1134,  1134,  1145,  1145,  1145,
    1148,  1169,  1170,  1173,  1181,  1189,  1194,  1199,  1199,  1205,
    1205,  1214,  1214,  1219,  1227,  1235,  1235,  1241,  1241,  1250,
    1250,  1255,  1255,  1261,  1261,  1266,  1266,  1266,  1270,  1270,
    1270
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_TOKEN", "T_QSTRING", 
  "T_COMMENT", "T_LINE", "T_URI", "T_URI_WILDCARD", "T_DISPLAY", "T_LANG", 
  "T_WORD", "T_WKDAY", "T_MONTH", "T_GMT", "T_SIP", "T_METHOD", 
  "T_AUTH_DIGEST", "T_AUTH_OTHER", "T_HDR_ACCEPT", 
  "T_HDR_ACCEPT_ENCODING", "T_HDR_ACCEPT_LANGUAGE", "T_HDR_ALERT_INFO", 
  "T_HDR_ALLOW", "T_HDR_AUTHENTICATION_INFO", "T_HDR_AUTHORIZATION", 
  "T_HDR_CALL_ID", "T_HDR_CALL_INFO", "T_HDR_CONTACT", 
  "T_HDR_CONTENT_DISP", "T_HDR_CONTENT_ENCODING", 
  "T_HDR_CONTENT_LANGUAGE", "T_HDR_CONTENT_LENGTH", "T_HDR_CONTENT_TYPE", 
  "T_HDR_CSEQ", "T_HDR_DATE", "T_HDR_ERROR_INFO", "T_HDR_EXPIRES", 
  "T_HDR_FROM", "T_HDR_IN_REPLY_TO", "T_HDR_MAX_FORWARDS", 
  "T_HDR_MIN_EXPIRES", "T_HDR_MIME_VERSION", "T_HDR_ORGANIZATION", 
  "T_HDR_PRIORITY", "T_HDR_PROXY_AUTHENTICATE", 
  "T_HDR_PROXY_AUTHORIZATION", "T_HDR_PROXY_REQUIRE", "T_HDR_RACK", 
  "T_HDR_RECORD_ROUTE", "T_HDR_REPLY_TO", "T_HDR_REQUIRE", 
  "T_HDR_RETRY_AFTER", "T_HDR_ROUTE", "T_HDR_RSEQ", "T_HDR_SERVER", 
  "T_HDR_SUBJECT", "T_HDR_SUPPORTED", "T_HDR_TIMESTAMP", "T_HDR_TO", 
  "T_HDR_UNSUPPORTED", "T_HDR_USER_AGENT", "T_HDR_VIA", "T_HDR_WARNING", 
  "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", "T_CRLF", "T_ERROR", "'/'", 
  "':'", "','", "';'", "'='", "'<'", "'>'", "'@'", "'('", "')'", "'.'", 
  "$accept", "sip_message", "@1", "sip_message2", "request", 
  "request_line", "@2", "@3", "sip_version", "@4", "response", 
  "status_line", "@5", "@6", "@7", "headers", "header", "hd_accept", 
  "hd_accept_encoding", "hd_accept_language", "hd_alert_info", "hd_allow", 
  "hd_authentication_info", "hd_authorization", "hd_call_id", 
  "hd_call_info", "hd_contact", "hd_content_disp", "hd_content_encoding", 
  "hd_content_language", "hd_content_length", "hd_content_type", 
  "hd_cseq", "hd_date", "hd_error_info", "hd_expires", "hd_from", 
  "hd_in_reply_to", "hd_max_forwards", "hd_min_expires", 
  "hd_mime_version", "hd_organization", "hd_priority", 
  "hd_proxy_authenticate", "hd_proxy_authorization", "hd_proxy_require", 
  "hd_rack", "hd_record_route", "hd_reply_to", "hd_require", 
  "hd_retry_after", "hd_route", "hd_rseq", "hd_server", "hd_subject", 
  "hd_supported", "hd_timestamp", "hd_to", "hd_unsupported", 
  "hd_user_agent", "hd_via", "hd_warning", "hd_www_authenticate", 
  "hdr_accept", "media_range", "parameters", "parameter", 
  "hdr_accept_encoding", "content_coding", "q_factor", 
  "hdr_accept_language", "@8", "@9", "language", "@10", "hdr_alert_info", 
  "alert_param", "@11", "@12", "hdr_allow", "hdr_call_id", "@13", "@14", 
  "call_id", "hdr_call_info", "info_param", "@15", "@16", "hdr_contact", 
  "@17", "@18", "contacts", "contact_param", "contact_addr", "@19", "@20", 
  "@21", "@22", "display_name", "hdr_content_disp", 
  "hdr_content_encoding", "hdr_content_language", "@23", "@24", 
  "hdr_content_length", "@25", "@26", "hdr_content_type", "hdr_cseq", 
  "@27", "@28", "hdr_date", "@29", "@30", "hdr_error_info", "error_param", 
  "@31", "@32", "hdr_expires", "@33", "@34", "hdr_from", "@35", 
  "from_addr", "@36", "@37", "hdr_in_reply_to", "@38", "@39", "@40", 
  "@41", "hdr_max_forwards", "@42", "@43", "hdr_min_expires", "@44", 
  "@45", "hdr_mime_version", "hdr_organization", "@46", "@47", 
  "hdr_priority", "hdr_proxy_require", "hdr_record_route", "rec_route", 
  "@48", "@49", "hdr_reply_to", "@50", "hdr_require", "hdr_retry_after", 
  "@51", "@52", "comment", "@53", "@54", "hdr_route", "hdr_server", 
  "server", "hdr_subject", "@55", "@56", "hdr_supported", "hdr_timestamp", 
  "@57", "hdr_timestamp1", "timestamp", "delay", "hdr_to", "@58", 
  "hdr_unsupported", "hdr_user_agent", "hdr_via", "via_parm", 
  "sent_protocol", "host", "@59", "@60", "hdr_warning", "warning", "@61", 
  "@62", "hdr_unknown", "@63", "@64", "ainfo", "hdr_authentication_info", 
  "digest_response", "auth_params", "credentials", "@65", "@66", 
  "hdr_authorization", "@67", "digest_challenge", "challenge", "@68", 
  "@69", "hdr_proxy_authenticate", "@70", "hdr_proxy_authorization", 
  "@71", "hdr_www_authenticate", "@72", "hdr_rseq", "@73", "@74", 
  "hdr_rack", "@75", "@76", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    47,
      58,    44,    59,    61,    60,    62,    64,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,    80,    82,    81,    83,    83,    84,    86,    87,    85,
      89,    88,    90,    92,    93,    94,    91,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   143,
     143,   144,   145,   145,   146,   146,   146,   147,   147,   148,
     148,   149,   151,   150,   152,   150,   153,   154,   153,   155,
     155,   157,   158,   156,   159,   159,   161,   162,   160,   163,
     163,   164,   164,   166,   167,   165,   169,   170,   168,   168,
     171,   171,   172,   174,   175,   173,   176,   177,   173,   178,
     178,   178,   179,   180,   180,   182,   181,   183,   181,   185,
     186,   184,   187,   189,   190,   188,   192,   193,   191,   194,
     194,   196,   197,   195,   199,   200,   198,   202,   201,   204,
     203,   205,   203,   207,   208,   206,   209,   210,   206,   212,
     213,   211,   215,   216,   214,   217,   219,   220,   218,   221,
     222,   222,   223,   223,   225,   226,   224,   228,   227,   229,
     229,   231,   232,   230,   233,   234,   235,   233,   236,   236,
     237,   237,   238,   238,   240,   241,   239,   242,   242,   242,
     244,   243,   245,   245,   246,   246,   247,   247,   249,   248,
     250,   250,   251,   251,   252,   252,   253,   254,   255,   256,
     257,   255,   258,   258,   260,   261,   259,   263,   264,   262,
     265,   266,   266,   267,   267,   268,   268,   270,   269,   271,
     269,   273,   272,   274,   274,   276,   275,   277,   275,   279,
     278,   281,   280,   283,   282,   285,   286,   284,   288,   289,
     287
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     0,     0,     6,
       0,     4,     3,     0,     0,     0,     7,     0,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       4,     3,     0,     3,     1,     3,     3,     1,     3,     1,
       2,     2,     0,     2,     0,     4,     1,     0,     3,     1,
       3,     0,     0,     6,     1,     3,     0,     0,     3,     1,
       3,     1,     3,     0,     0,     6,     0,     0,     3,     1,
       1,     3,     2,     0,     0,     3,     0,     0,     6,     0,
       1,     1,     2,     1,     3,     0,     2,     0,     4,     0,
       0,     3,     2,     0,     0,     4,     0,     0,    13,     1,
       3,     0,     0,     6,     0,     0,     3,     0,     3,     0,
       2,     0,     5,     0,     0,     3,     0,     0,     5,     0,
       0,     3,     0,     0,     3,     1,     0,     0,     3,     1,
       1,     3,     1,     3,     0,     0,     7,     0,     3,     1,
       3,     0,     0,     5,     0,     0,     0,     5,     1,     3,
       1,     2,     2,     4,     0,     0,     3,     0,     1,     3,
       0,     2,     1,     2,     1,     3,     1,     3,     0,     3,
       1,     3,     1,     2,     1,     3,     3,     5,     1,     0,
       0,     5,     1,     3,     0,     0,     5,     0,     0,     3,
       1,     1,     3,     1,     3,     1,     3,     0,     3,     0,
       3,     0,     2,     1,     3,     0,     3,     0,     3,     0,
       2,     0,     2,     0,     2,     0,     0,     3,     0,     0,
       5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       2,     0,     0,     1,    10,     7,     3,     4,    17,    13,
       5,    17,     0,     0,     0,     0,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    12,    11,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   317,     0,     0,     0,   162,     0,
     169,     0,   167,     0,     0,     0,     0,   181,     0,   179,
       0,   184,     0,     0,   164,   320,   321,     0,     0,     0,
       0,     0,     0,     0,     0,   193,     0,   191,     0,     0,
       0,   199,   200,   162,     0,   209,     0,   162,     0,     0,
     213,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,     0,     0,     0,     0,     0,     0,   231,     0,
     229,     0,     0,     0,     0,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,   262,
     209,     0,     0,   209,     0,   260,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,     0,     0,   274,     0,
     280,     0,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,   209,     0,   300,     0,     0,   302,     0,     0,
       0,     0,   304,     0,     0,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,    19,     0,   159,
      67,     0,   170,    20,     0,    68,    21,   174,   176,   173,
      69,     0,    22,     0,    70,    23,     0,    71,     0,    24,
       0,    72,    25,   327,   329,   332,    73,    26,   189,   187,
      74,     0,    27,     0,    75,    28,   197,   206,   202,   204,
     211,   210,     0,    76,   212,    29,    77,    30,     0,    78,
      31,   217,   216,    79,    32,   220,    80,   222,    33,    81,
      34,   224,    82,    35,     0,    83,     0,    36,     0,    84,
      37,   235,    85,    38,   239,     0,   162,    86,    39,   246,
     244,    87,    40,   250,    88,    41,   253,    89,    42,    90,
      43,   257,    91,    44,    92,    45,   335,   337,   340,    93,
      46,   342,    94,    47,     0,    95,    48,     0,    96,    49,
     264,     0,    97,    50,   162,    98,     0,    51,    99,    52,
     272,   100,    53,   264,   101,    54,   346,   102,     0,   275,
     282,    55,   281,   103,    56,   285,   104,    57,     0,   105,
      58,   294,   291,   292,   106,    59,   162,   107,    60,     0,
     108,    61,   303,   109,     0,    62,     0,   308,   162,   110,
      63,   314,   315,   111,    64,   344,    15,     9,    65,   318,
     161,   162,     0,   171,   168,     0,     0,   182,   180,   185,
     165,   166,   322,     0,     0,     0,   188,   194,   192,   198,
     201,   205,     0,   214,     0,   221,     0,     0,   232,   230,
     236,   240,     0,   238,     0,   245,   251,   254,   258,     0,
       0,   261,   349,   263,     0,   268,   261,   274,   279,   347,
     274,     0,   286,   289,     0,   296,   293,   299,   301,     0,
     305,   309,   306,   313,     0,     0,   319,   160,   163,   175,
     178,     0,   323,   328,   325,   330,   190,     0,   207,   218,
     225,     0,     0,   241,   247,   333,   336,   338,     0,   265,
     162,   283,   276,   295,     0,     0,     0,     0,    16,   162,
       0,     0,   162,     0,     0,   162,     0,   248,     0,   350,
       0,   273,     0,   297,   307,   310,   316,   183,   324,   326,
     195,   208,     0,   233,   242,   334,   162,   277,   311,     0,
     266,     0,     0,     0,     0,   227,   228
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    13,   117,     9,    12,
      10,    11,    15,   321,   565,    14,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   167,   168,   329,   185,   171,   172,   332,
     174,   175,   505,   339,   506,   178,   179,   341,   571,   182,
     192,   193,   516,   359,   196,   197,   361,   577,   199,   200,
     519,   201,   202,   203,   204,   521,   205,   603,   405,   208,
     211,   213,   214,   524,   216,   217,   525,   220,   222,   223,
     526,   225,   226,   636,   229,   230,   396,   582,   232,   233,
     530,   235,   236,   406,   531,   606,   238,   239,   535,   534,
     607,   241,   242,   536,   244,   245,   537,   248,   250,   251,
     538,   254,   263,   268,   269,   270,   610,   272,   273,   277,
     279,   280,   547,   460,   551,   612,   283,   289,   290,   292,
     293,   552,   296,   298,   299,   472,   473,   556,   301,   302,
     305,   308,   311,   312,   313,   488,   596,   628,   315,   316,
     317,   564,   323,   324,   566,   186,   187,   573,   575,   355,
     513,   514,   189,   190,   586,   428,   539,   540,   256,   257,
     259,   260,   319,   320,   285,   286,   549,   265,   266,   588
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -450
static const short yypact[] =
{
    -450,    34,    40,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,    12,    80,    95,   108,   404,   169,  -450,   141,
     178,   180,   186,   187,   189,   190,   191,   192,   193,   194,
     195,   199,   200,   201,   202,   207,   210,   211,   212,   214,
     218,   219,   220,   224,   225,   226,   229,   234,   237,   238,
     240,   241,   244,   245,   247,   248,   249,   251,   252,   253,
     254,   255,   256,   257,   258,   259,  -450,  -450,    42,    71,
      75,     8,   196,   197,    44,    52,    10,     9,   198,   203,
      76,   227,   204,   228,    48,    11,   231,    19,    59,   232,
     235,   208,    72,   209,    47,    49,   215,   236,    31,    20,
     216,   239,    32,   242,   217,    73,    43,   243,    30,   221,
     222,   223,   246,    51,  -450,  -450,  -450,    74,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   126,   205,   -13,  -450,   230,
     206,   -12,  -450,   263,    36,   268,   264,  -450,    41,  -450,
     265,  -450,    96,   266,   213,  -450,  -450,    97,   267,   269,
      81,   270,   271,   275,   273,  -450,    98,  -450,   274,   276,
     282,   277,  -450,  -450,   260,    86,   278,  -450,   279,   280,
    -450,    99,   283,   104,   268,   284,   286,   289,   287,  -450,
     288,   290,   291,   298,   292,   293,   296,   294,  -450,   105,
    -450,   295,   297,   300,   299,   301,    87,   302,   107,   275,
     303,   304,   310,   305,   306,   313,   307,  -450,   308,   309,
     311,   328,   312,  -450,   314,   315,   316,   233,   317,   318,
      81,   319,  -450,   112,   321,   322,   339,   323,   113,  -450,
      86,   324,   325,    87,   326,   327,   285,   330,   331,   333,
     341,   334,  -450,   114,   336,   337,   346,   338,   -54,    22,
    -450,   340,   342,   356,   343,  -450,   115,   344,   345,   362,
     347,   348,    87,   349,  -450,   123,   350,  -450,    35,   351,
     352,   124,  -450,   262,   353,   125,  -450,   364,   355,   405,
     233,   370,   406,   407,   373,  -450,   391,  -450,   402,   403,
    -450,   409,  -450,  -450,   415,  -450,  -450,  -450,   408,  -450,
    -450,   400,  -450,   410,  -450,  -450,   472,  -450,   250,  -450,
     409,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   401,  -450,
    -450,   470,  -450,   411,  -450,  -450,  -450,   471,   403,  -450,
    -450,  -450,   412,  -450,   403,  -450,  -450,  -450,   415,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,   403,  -450,  -450,
    -450,  -450,  -450,  -450,   416,  -450,   473,  -450,   414,  -450,
    -450,  -450,  -450,  -450,  -450,   417,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   478,  -450,  -450,   480,  -450,  -450,
    -450,   418,  -450,  -450,  -450,  -450,   485,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   486,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   489,  -450,
    -450,   188,  -450,   491,  -450,  -450,  -450,  -450,  -450,   492,
    -450,  -450,  -450,  -450,   493,  -450,   494,   425,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,   409,  -450,  -450,   268,   206,  -450,  -450,  -450,
    -450,  -450,  -450,   409,   409,   487,  -450,  -450,  -450,  -450,
    -450,  -450,   495,  -450,   268,  -450,   496,   498,  -450,  -450,
    -450,  -450,   497,   403,   275,  -450,  -450,  -450,  -450,   409,
     409,  -450,  -450,  -450,   499,   403,   435,   427,  -450,  -450,
     427,   500,  -450,  -450,   505,   430,  -450,   403,  -450,   441,
    -450,  -450,   403,  -450,   262,   444,  -450,   403,  -450,  -450,
    -450,   437,  -450,   442,  -450,   443,  -450,   440,  -450,  -450,
    -450,   502,   445,  -450,  -450,  -450,   446,   443,   514,  -450,
    -450,  -450,  -450,  -450,   516,   517,   519,   518,  -450,  -450,
     409,   409,  -450,   449,   522,  -450,   451,  -450,   409,  -450,
     452,   403,   450,  -450,  -450,  -450,  -450,   403,  -450,  -450,
     403,  -450,   526,   403,  -450,  -450,  -450,  -450,  -450,   460,
     403,   528,   462,   530,   520,  -450,  -450
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,   419,  -450,
    -450,  -450,  -450,  -450,  -450,   523,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,   -75,  -203,  -325,  -450,   -76,  -201,
    -450,  -450,  -450,  -212,  -450,  -450,   -37,  -450,  -450,  -450,
    -450,  -450,  -450,  -234,  -450,   -43,  -450,  -450,  -450,  -450,
    -450,  -450,   170,  -450,  -450,  -450,  -450,  -450,  -192,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,   140,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -251,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,   439,  -450,  -101,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -449,  -450,  -450,  -450,  -450,  -102,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,    54,  -450,   -23,  -450,  -450,  -450,    53,
    -450,  -450,  -450,  -450,  -450,   261,  -450,  -450,     2,   320,
    -450,  -450,  -450,  -450,  -450,   272,  -450,  -450,  -450,  -450,
    -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450,  -450
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -349
static const short yytable[] =
{
     368,   282,   382,   210,   374,   410,   503,   219,   307,   176,
     198,   194,   227,   372,  -206,   458,   387,  -203,  -196,  -206,
     234,   271,   444,   459,  -237,  -267,   288,  -237,  -267,  -237,
    -267,   300,   267,   281,     3,  -298,  -264,  -264,  -298,   288,
    -298,  -264,  -264,   165,   294,   188,   166,   295,   255,   224,
     258,   476,   318,   191,   327,   333,     4,     5,   328,   334,
     237,  -226,  -331,  -331,  -186,  -339,  -339,  -341,  -341,  -343,
    -343,  -243,   169,   249,   291,   170,   173,   212,   441,  -256,
    -284,    17,   177,  -206,   195,   228,  -172,  -215,    18,   461,
       4,   370,   370,  -237,  -267,   404,   371,   371,   590,   353,
     354,   591,   481,   336,  -298,  -264,  -264,   337,   342,  -158,
    -287,   114,   343,  -158,  -287,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,   345,   349,   362,   377,   346,   350,   363,
     378,   380,   397,   116,   408,   381,   398,   568,   409,   433,
     439,   452,   467,   434,   440,   453,   468,   462,   572,   574,
     478,   485,   490,   325,   479,   486,   491,   180,   183,   206,
     181,   184,   207,   533,   209,   218,   482,   170,   166,   246,
     252,   118,   247,   253,   585,   574,   261,   274,   287,   262,
     275,   288,   303,   306,   309,   304,   288,   310,   215,   221,
    -219,  -223,   231,   240,  -234,  -249,   243,   264,  -252,  -348,
     278,   545,  -271,   284,   297,  -345,  -290,   314,   119,  -314,
     120,   426,   427,   501,   510,   511,   121,   122,   504,   123,
     124,   125,   126,   127,   128,   129,   487,   554,   369,   130,
     131,   132,   133,   557,   326,   618,   619,   134,   331,   338,
     135,   136,   137,   625,   138,   562,   348,   358,   139,   140,
     141,   366,   385,   569,   142,   143,   144,   330,   567,   145,
     584,   391,   523,   401,   146,   570,   508,   147,   148,   394,
     149,   150,   579,   413,   151,   152,   416,   153,   154,   155,
     518,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     335,   340,   344,   347,   351,   421,   352,   356,   357,   543,
     360,   364,   437,   365,   450,   373,   375,   376,   367,   456,
     379,   383,   548,   384,   386,   388,   446,   389,   390,   392,
     393,   395,   399,   465,   400,   471,   402,   492,   403,   407,
     411,   412,   414,   415,   417,   418,   419,   496,   420,   422,
     499,   423,   424,   425,   429,   430,   432,   611,   435,   436,
     438,   442,   443,   445,  -269,   500,   617,   447,   448,   620,
     449,   451,   623,   454,   455,   457,   166,   463,   507,   464,
     466,   469,   470,   184,   474,   475,   477,   480,   483,   170,
     489,   484,   493,   630,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   115,   494,   497,   498,   502,   509,   515,   517,  -203,
    -177,   528,   541,   542,   177,   195,   522,   527,   228,   546,
     550,   532,   544,   553,   555,   561,   558,   559,   310,   576,
     580,   581,  -270,   578,   459,   583,   592,   589,   593,   594,
     595,   598,   599,   600,   601,   602,   604,   608,   609,   613,
     605,   614,   615,   616,   621,   622,   624,   626,   627,   629,
     631,   632,   633,   634,    16,   635,   322,   520,   529,   276,
     560,   597,   587,     0,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512
};

static const short yycheck[] =
{
     203,   102,   214,    79,   207,   239,   331,    82,   110,     1,
       1,     1,     1,   205,     5,    69,   219,     8,     9,    10,
       1,     1,   273,    77,     5,     5,     4,     8,     8,    10,
      10,     1,     1,     1,     0,     5,     5,     5,     8,     4,
      10,    10,    10,     1,     1,     1,     4,     4,     1,     1,
       1,   302,     1,     1,    67,    67,    16,    17,    71,    71,
       1,    13,    18,    19,    12,    18,    19,    18,    19,    18,
      19,    12,     1,     1,     1,     4,     1,     1,   270,     7,
       7,    69,    74,    74,    74,    74,    11,    11,     8,    67,
      16,     5,     5,    74,    74,     8,    10,    10,   547,    18,
      19,   550,    67,    67,    74,    74,    74,    71,    67,    67,
      67,     3,    71,    71,    71,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    67,    67,    67,    67,    71,    71,    71,
      71,    67,    67,     4,    67,    71,    71,   502,    71,    67,
      67,    67,    67,    71,    71,    71,    71,   289,   513,   514,
      67,    67,    67,    67,    71,    71,    71,     1,     1,     1,
       4,     4,     4,   406,     1,     1,   308,     4,     4,     1,
       1,    70,     4,     4,   539,   540,     1,     1,     1,     4,
       4,     4,     1,     1,     1,     4,     4,     4,     1,     1,
       3,     3,     1,     1,     3,     3,     1,     1,     3,     3,
       1,   444,     3,     1,     1,     3,     3,     1,    70,     3,
      70,    18,    19,   328,     4,     5,    70,    70,   334,    70,
      70,    70,    70,    70,    70,    70,     4,    79,     8,    70,
      70,    70,    70,   476,    69,   600,   601,    70,    72,    11,
      70,    70,    70,   608,    70,   488,    73,    12,    70,    70,
      70,     9,     3,   505,    70,    70,    70,    67,   501,    70,
     534,     3,   378,     3,    70,   506,   343,    70,    70,    13,
      70,    70,   524,     3,    70,    70,     3,    70,    70,    70,
     363,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      67,    67,    67,    67,    67,     7,    67,    67,    67,   440,
      67,    67,     3,    67,     3,    67,    67,    67,    71,     3,
      67,    67,   453,    67,    67,    67,    71,    67,    67,    67,
      67,    67,    67,     7,    67,     3,    67,     3,    67,    67,
      67,    67,    67,    67,    67,    67,    67,     7,    67,    67,
       7,    67,    67,    67,    67,    67,    67,   590,    67,    67,
      67,    67,    67,    67,    67,     4,   599,    67,    67,   602,
      67,    67,   605,    67,    67,    67,     4,    67,     8,    67,
      67,    67,    67,     4,    67,    67,    67,    67,    67,     4,
      67,    69,    67,   626,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    67,    67,    67,    72,     4,    76,     8,     8,
      72,     8,     4,     3,    74,    74,    74,    71,    74,     4,
       4,    74,    74,     4,     3,    70,     4,     4,     4,    12,
       4,     3,    67,     8,    77,     8,     6,     8,     3,    79,
      69,    67,    75,    71,    71,    75,    14,    71,     4,     3,
      75,     4,     3,     5,    75,     3,    75,    75,    78,     3,
      70,     3,    70,     3,    11,    15,   117,   367,   398,   100,
     486,   564,   540,    -1,   491,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   350
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    81,    82,     0,    16,    17,    83,    84,    85,    88,
      90,    91,    89,    86,    95,    92,    95,    69,     8,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,     3,    67,     4,    87,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,     1,     4,   143,   144,     1,
       4,   147,   148,     1,   150,   151,     1,    74,   155,   156,
       1,     4,   159,     1,     4,   146,   265,   266,     1,   272,
     273,     1,   160,   161,     1,    74,   164,   165,     1,   168,
     169,   171,   172,   173,   174,   176,     1,     4,   179,     1,
     148,   180,     1,   181,   182,     1,   184,   185,     1,   144,
     187,     1,   188,   189,     1,   191,   192,     1,    74,   194,
     195,     1,   198,   199,     1,   201,   202,     1,   206,   207,
       1,   211,   212,     1,   214,   215,     1,     4,   217,     1,
     218,   219,     1,     4,   221,     1,   278,   279,     1,   280,
     281,     1,     4,   222,     1,   287,   288,     1,   223,   224,
     225,     1,   227,   228,     1,     4,   222,   229,     1,   230,
     231,     1,   224,   236,     1,   284,   285,     1,     4,   237,
     238,     1,   239,   240,     1,     4,   242,     1,   243,   244,
       1,   248,   249,     1,     4,   250,     1,   238,   251,     1,
       4,   252,   253,   254,     1,   258,   259,   260,     1,   282,
     283,    93,    88,   262,   263,    67,    69,    67,    71,   145,
      67,    72,   149,    67,    71,    67,    67,    71,    11,   153,
      67,   157,    67,    71,    67,    67,    71,    67,    73,    67,
      71,    67,    67,    18,    19,   269,    67,    67,    12,   163,
      67,   166,    67,    71,    67,    67,     9,    71,   145,     8,
       5,    10,   178,    67,   145,    67,    67,    67,    71,    67,
      67,    71,   153,    67,    67,     3,    67,   145,    67,    67,
      67,     3,    67,    67,    13,    67,   196,    67,    71,    67,
      67,     3,    67,    67,     8,   178,   203,    67,    67,    71,
     163,    67,    67,     3,    67,    67,     3,    67,    67,    67,
      67,     7,    67,    67,    67,    67,    18,    19,   275,    67,
      67,   269,    67,    67,    71,    67,    67,     3,    67,    67,
      71,   178,    67,    67,   203,    67,    71,    67,    67,    67,
       3,    67,    67,    71,    67,    67,     3,    67,    69,    77,
     233,    67,   238,    67,    67,     7,    67,    67,    71,    67,
      67,     3,   245,   246,    67,    67,   203,    67,    67,    71,
      67,    67,   238,    67,    69,    67,    71,     4,   255,    67,
      67,    71,     3,    67,    67,   275,     7,    67,    67,     7,
       4,   144,    72,   146,   148,   152,   154,     8,   156,     4,
       4,     5,   265,   270,   271,    76,   162,     8,   165,   170,
     172,   175,    74,   148,   183,   186,   190,    71,     8,   195,
     200,   204,    74,   145,   209,   208,   213,   216,   220,   276,
     277,     4,     3,   224,    74,   145,     4,   232,   224,   286,
       4,   234,   241,     4,    79,     3,   247,   145,     4,     4,
     253,    70,   145,   259,   261,    94,   264,   145,   146,   153,
     149,   158,   146,   267,   146,   268,    12,   167,     8,   153,
       4,     3,   197,     8,   163,   146,   274,   268,   289,     8,
     233,   233,     6,     3,    79,    69,   256,   255,    67,    75,
      71,    71,    75,   177,    14,    75,   205,   210,    71,     4,
     226,   145,   235,     3,     4,     3,     5,   145,   146,   146,
     145,    75,     3,   145,    75,   146,    75,    78,   257,     3,
     145,    70,     3,    70,     3,    15,   193
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)
# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      case 4: /* T_TOKEN */
#line 0 "parser.yxx"
        (null);
#line 1398 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 0 "parser.yxx"
        (null);
#line 1403 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 0 "parser.yxx"
        (null);
#line 1408 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 0 "parser.yxx"
        (null);
#line 1413 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 0 "parser.yxx"
        (null);
#line 1418 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 0 "parser.yxx"
        (null);
#line 1423 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 0 "parser.yxx"
        (null);
#line 1428 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 0 "parser.yxx"
        (null);
#line 1433 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 0 "parser.yxx"
        (null);
#line 1438 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 0 "parser.yxx"
        (null);
#line 1443 "parser.cxx"
        break;
      case 66: /* T_HDR_UNKNOWN */
#line 0 "parser.yxx"
        (null);
#line 1448 "parser.cxx"
        break;
      case 88: /* sip_version */
#line 0 "parser.yxx"
        (null);
#line 1453 "parser.cxx"
        break;
      case 144: /* media_range */
#line 0 "parser.yxx"
        (null);
#line 1458 "parser.cxx"
        break;
      case 145: /* parameters */
#line 0 "parser.yxx"
        (null);
#line 1463 "parser.cxx"
        break;
      case 146: /* parameter */
#line 0 "parser.yxx"
        (null);
#line 1468 "parser.cxx"
        break;
      case 148: /* content_coding */
#line 0 "parser.yxx"
        (null);
#line 1473 "parser.cxx"
        break;
      case 153: /* language */
#line 0 "parser.yxx"
        (null);
#line 1478 "parser.cxx"
        break;
      case 156: /* alert_param */
#line 0 "parser.yxx"
        (null);
#line 1483 "parser.cxx"
        break;
      case 163: /* call_id */
#line 0 "parser.yxx"
        (null);
#line 1488 "parser.cxx"
        break;
      case 165: /* info_param */
#line 0 "parser.yxx"
        (null);
#line 1493 "parser.cxx"
        break;
      case 171: /* contacts */
#line 0 "parser.yxx"
        (null);
#line 1498 "parser.cxx"
        break;
      case 172: /* contact_param */
#line 0 "parser.yxx"
        (null);
#line 1503 "parser.cxx"
        break;
      case 173: /* contact_addr */
#line 0 "parser.yxx"
        (null);
#line 1508 "parser.cxx"
        break;
      case 178: /* display_name */
#line 0 "parser.yxx"
        (null);
#line 1513 "parser.cxx"
        break;
      case 195: /* error_param */
#line 0 "parser.yxx"
        (null);
#line 1518 "parser.cxx"
        break;
      case 203: /* from_addr */
#line 0 "parser.yxx"
        (null);
#line 1523 "parser.cxx"
        break;
      case 224: /* rec_route */
#line 0 "parser.yxx"
        (null);
#line 1528 "parser.cxx"
        break;
      case 233: /* comment */
#line 0 "parser.yxx"
        (null);
#line 1533 "parser.cxx"
        break;
      case 238: /* server */
#line 0 "parser.yxx"
        (null);
#line 1538 "parser.cxx"
        break;
      case 253: /* via_parm */
#line 0 "parser.yxx"
        (null);
#line 1543 "parser.cxx"
        break;
      case 254: /* sent_protocol */
#line 0 "parser.yxx"
        (null);
#line 1548 "parser.cxx"
        break;
      case 255: /* host */
#line 0 "parser.yxx"
        (null);
#line 1553 "parser.cxx"
        break;
      case 259: /* warning */
#line 0 "parser.yxx"
        (null);
#line 1558 "parser.cxx"
        break;
      case 262: /* hdr_unknown */
#line 0 "parser.yxx"
        (null);
#line 1563 "parser.cxx"
        break;
      case 267: /* digest_response */
#line 0 "parser.yxx"
        (null);
#line 1568 "parser.cxx"
        break;
      case 268: /* auth_params */
#line 0 "parser.yxx"
        (null);
#line 1573 "parser.cxx"
        break;
      case 269: /* credentials */
#line 0 "parser.yxx"
        (null);
#line 1578 "parser.cxx"
        break;
      case 274: /* digest_challenge */
#line 0 "parser.yxx"
        (null);
#line 1583 "parser.cxx"
        break;
      case 275: /* challenge */
#line 0 "parser.yxx"
        (null);
#line 1588 "parser.cxx"
        break;
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      case 4: /* T_TOKEN */
#line 145 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1619 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 146 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1624 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 147 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1629 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 148 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1634 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 149 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1639 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 150 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1644 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 151 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1649 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 152 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1654 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 153 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1659 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 154 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1664 "parser.cxx"
        break;
      case 66: /* T_HDR_UNKNOWN */
#line 155 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1669 "parser.cxx"
        break;
      case 88: /* sip_version */
#line 214 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1674 "parser.cxx"
        break;
      case 144: /* media_range */
#line 208 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_media); delete yyvalue.yyt_media; };
#line 1679 "parser.cxx"
        break;
      case 145: /* parameters */
#line 210 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_params); delete yyvalue.yyt_params; };
#line 1684 "parser.cxx"
        break;
      case 146: /* parameter */
#line 209 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_param); delete yyvalue.yyt_param; };
#line 1689 "parser.cxx"
        break;
      case 148: /* content_coding */
#line 197 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_coding); delete yyvalue.yyt_coding; };
#line 1694 "parser.cxx"
        break;
      case 153: /* language */
#line 207 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_language); delete yyvalue.yyt_language; };
#line 1699 "parser.cxx"
        break;
      case 156: /* alert_param */
#line 189 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_alert_param); delete yyvalue.yyt_alert_param; };
#line 1704 "parser.cxx"
        break;
      case 163: /* call_id */
#line 191 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1709 "parser.cxx"
        break;
      case 165: /* info_param */
#line 206 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_info_param); delete yyvalue.yyt_info_param; };
#line 1714 "parser.cxx"
        break;
      case 171: /* contacts */
#line 196 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_contacts); delete yyvalue.yyt_contacts; };
#line 1719 "parser.cxx"
        break;
      case 172: /* contact_param */
#line 195 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_contact); delete yyvalue.yyt_contact; };
#line 1724 "parser.cxx"
        break;
      case 173: /* contact_addr */
#line 194 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_contact); delete yyvalue.yyt_contact; };
#line 1729 "parser.cxx"
        break;
      case 178: /* display_name */
#line 201 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1734 "parser.cxx"
        break;
      case 195: /* error_param */
#line 202 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_error_param); delete yyvalue.yyt_error_param; };
#line 1739 "parser.cxx"
        break;
      case 203: /* from_addr */
#line 203 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_from_addr); delete yyvalue.yyt_from_addr; };
#line 1744 "parser.cxx"
        break;
      case 224: /* rec_route */
#line 211 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_route); delete yyvalue.yyt_route; };
#line 1749 "parser.cxx"
        break;
      case 233: /* comment */
#line 193 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1754 "parser.cxx"
        break;
      case 238: /* server */
#line 213 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_server); delete yyvalue.yyt_server; };
#line 1759 "parser.cxx"
        break;
      case 253: /* via_parm */
#line 215 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_via); delete yyvalue.yyt_via; };
#line 1764 "parser.cxx"
        break;
      case 254: /* sent_protocol */
#line 212 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_via); delete yyvalue.yyt_via; };
#line 1769 "parser.cxx"
        break;
      case 255: /* host */
#line 205 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_via); delete yyvalue.yyt_via; };
#line 1774 "parser.cxx"
        break;
      case 259: /* warning */
#line 216 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_warning); delete yyvalue.yyt_warning; };
#line 1779 "parser.cxx"
        break;
      case 262: /* hdr_unknown */
#line 204 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_str); delete yyvalue.yyt_str; };
#line 1784 "parser.cxx"
        break;
      case 267: /* digest_response */
#line 200 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_dig_resp); delete yyvalue.yyt_dig_resp; };
#line 1789 "parser.cxx"
        break;
      case 268: /* auth_params */
#line 190 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_params); delete yyvalue.yyt_params; };
#line 1794 "parser.cxx"
        break;
      case 269: /* credentials */
#line 198 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_credentials); delete yyvalue.yyt_credentials; };
#line 1799 "parser.cxx"
        break;
      case 274: /* digest_challenge */
#line 199 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_dig_chlg); delete yyvalue.yyt_dig_chlg; };
#line 1804 "parser.cxx"
        break;
      case 275: /* challenge */
#line 192 "parser.yxx"
        { MEMMAN_DELETE(yyvalue.yyt_challenge); delete yyvalue.yyt_challenge; };
#line 1809 "parser.cxx"
        break;
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 2:
#line 219 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 226 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 7:
#line 235 "parser.yxx"
    { CTXT_URI; }
    break;

  case 8:
#line 235 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 9:
#line 236 "parser.yxx"
    {
		  	MSG = new t_request();
			MEMMAN_NEW(MSG);
			((t_request *)MSG)->set_method(*yyvsp[-5].yyt_str);
			((t_request *)MSG)->uri.set_url(*yyvsp[-3].yyt_str);
			MSG->version = *yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[-5].yyt_str); delete yyvsp[-5].yyt_str;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;

			if (!((t_request *)MSG)->uri.is_valid()) {
				MEMMAN_DELETE(MSG); delete MSG;
				MSG = NULL;
				YYABORT;
			} }
    break;

  case 10:
#line 253 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 11:
#line 253 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 12:
#line 257 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 13:
#line 264 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 14:
#line 264 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 15:
#line 265 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 16:
#line 265 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *yyvsp[-6].yyt_str;
			((t_response *)MSG)->code = yyvsp[-4].yyt_ulong;
			((t_response *)MSG)->reason = trim(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-6].yyt_str); delete yyvsp[-6].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 65:
#line 325 "parser.yxx"
    {
			MSG->add_unknown_header(*yyvsp[-3].yyt_str, trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 66:
#line 330 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 67:
#line 332 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 68:
#line 334 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 69:
#line 336 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 70:
#line 338 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 71:
#line 340 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 72:
#line 342 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 73:
#line 344 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 74:
#line 346 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 75:
#line 348 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 76:
#line 350 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 77:
#line 352 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 78:
#line 354 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 79:
#line 356 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 80:
#line 358 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 81:
#line 360 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 82:
#line 362 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 83:
#line 364 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 84:
#line 366 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 85:
#line 368 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 86:
#line 370 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 87:
#line 372 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 88:
#line 374 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 89:
#line 376 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 90:
#line 378 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 91:
#line 380 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 92:
#line 382 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 93:
#line 384 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 94:
#line 386 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 95:
#line 388 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 96:
#line 390 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 97:
#line 392 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 98:
#line 394 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 99:
#line 396 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 100:
#line 398 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 101:
#line 400 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 102:
#line 402 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 103:
#line 404 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 104:
#line 406 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 105:
#line 408 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 106:
#line 410 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 107:
#line 412 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 108:
#line 414 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 109:
#line 416 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 110:
#line 418 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 111:
#line 420 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 114:
#line 436 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 118:
#line 444 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 119:
#line 446 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 121:
#line 450 "parser.yxx"
    { CTXT_URI; }
    break;

  case 124:
#line 456 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 125:
#line 458 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 127:
#line 462 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 128:
#line 464 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 130:
#line 468 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 131:
#line 470 "parser.yxx"
    { CTXT_URI; }
    break;

  case 132:
#line 472 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 133:
#line 474 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 134:
#line 476 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 136:
#line 480 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 138:
#line 484 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 139:
#line 486 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 141:
#line 490 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 142:
#line 492 "parser.yxx"
    { CTXT_URI; }
    break;

  case 145:
#line 498 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 146:
#line 500 "parser.yxx"
    { CTXT_URI; }
    break;

  case 147:
#line 502 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 149:
#line 506 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 151:
#line 510 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 152:
#line 512 "parser.yxx"
    { CTXT_URI; }
    break;

  case 156:
#line 520 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 157:
#line 522 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 159:
#line 526 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 160:
#line 531 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 161:
#line 538 "parser.yxx"
    { yyval.yyt_media = new t_media(tolower(*yyvsp[-2].yyt_str), tolower(*yyvsp[0].yyt_str));
					MEMMAN_NEW(yyval.yyt_media);
					MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
					MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 162:
#line 544 "parser.yxx"
    { yyval.yyt_params = new list<t_parameter>; MEMMAN_NEW(yyval.yyt_params); }
    break;

  case 163:
#line 545 "parser.yxx"
    {
			yyvsp[-2].yyt_params->push_back(*yyvsp[0].yyt_param);
			yyval.yyt_params = yyvsp[-2].yyt_params;
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 164:
#line 551 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 165:
#line 555 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 166:
#line 560 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 167:
#line 567 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 168:
#line 570 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 169:
#line 575 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 170:
#line 579 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[-1].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			yyval.yyt_coding->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 171:
#line 586 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name != "q") YYERROR;
			yyval.yyt_float = atof(yyvsp[0].yyt_param->value.c_str());
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
			}
    break;

  case 172:
#line 593 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 173:
#line 593 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 174:
#line 596 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 175:
#line 596 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 176:
#line 601 "parser.yxx"
    {
			CTXT_INITIAL;
		  	yyval.yyt_language = new t_language(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 177:
#line 606 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 178:
#line 606 "parser.yxx"
    {
			yyval.yyt_language = new t_language(tolower(*yyvsp[-2].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			yyval.yyt_language->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 179:
#line 613 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 180:
#line 616 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 181:
#line 621 "parser.yxx"
    { CTXT_URI; }
    break;

  case 182:
#line 621 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 183:
#line 621 "parser.yxx"
    {
		  	yyval.yyt_alert_param = new t_alert_param();
			MEMMAN_NEW(yyval.yyt_alert_param);
			yyval.yyt_alert_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_alert_param->parameter_list = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params;

			if (!yyval.yyt_alert_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_alert_param); delete yyval.yyt_alert_param;
				YYERROR;
			} }
    break;

  case 184:
#line 635 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 185:
#line 638 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 186:
#line 643 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 187:
#line 643 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 188:
#line 643 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 189:
#line 648 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 190:
#line 649 "parser.yxx"
    {
			yyval.yyt_str = new string(*yyvsp[-2].yyt_str + '@' + *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 191:
#line 656 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 192:
#line 659 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 193:
#line 664 "parser.yxx"
    { CTXT_URI; }
    break;

  case 194:
#line 664 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 195:
#line 664 "parser.yxx"
    {
		  	yyval.yyt_info_param = new t_info_param();
			MEMMAN_NEW(yyval.yyt_info_param);
			yyval.yyt_info_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_info_param->parameter_list = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params;

			if (!yyval.yyt_info_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_info_param); delete yyval.yyt_info_param;
				YYERROR;
			} }
    break;

  case 196:
#line 678 "parser.yxx"
    { CTXT_URI; }
    break;

  case 197:
#line 678 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 198:
#line 678 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 199:
#line 680 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*yyvsp[0].yyt_contacts);
			MEMMAN_DELETE(yyvsp[0].yyt_contacts); delete yyvsp[0].yyt_contacts; }
    break;

  case 200:
#line 685 "parser.yxx"
    {
			yyval.yyt_contacts = new list<t_contact_param>;
			MEMMAN_NEW(yyval.yyt_contacts);
			yyval.yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 201:
#line 690 "parser.yxx"
    {
			yyvsp[-2].yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			yyval.yyt_contacts = yyvsp[-2].yyt_contacts;
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 202:
#line 696 "parser.yxx"
    {
			yyval.yyt_contact = yyvsp[-1].yyt_contact;
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "q") {
					yyval.yyt_contact->q = atof(i->value.c_str());
				} else if (i->name == "expires") {
					yyval.yyt_contact->set_expires(strtoul(
						i->value.c_str(), NULL, 10));
				} else {
					yyval.yyt_contact->add_extension(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 203:
#line 712 "parser.yxx"
    { CTXT_URI; }
    break;

  case 204:
#line 712 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 205:
#line 712 "parser.yxx"
    {
			yyval.yyt_contact = new t_contact_param();
			MEMMAN_NEW(yyval.yyt_contact);
			yyval.yyt_contact->uri.set_url(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;

			if (!yyval.yyt_contact->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_contact); delete yyval.yyt_contact;
				YYERROR;
			} }
    break;

  case 206:
#line 722 "parser.yxx"
    { CTXT_URI; }
    break;

  case 207:
#line 722 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 208:
#line 722 "parser.yxx"
    {
			yyval.yyt_contact = new t_contact_param();
			MEMMAN_NEW(yyval.yyt_contact);
			yyval.yyt_contact->display = *yyvsp[-4].yyt_str;
			yyval.yyt_contact->uri.set_url(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;

			if (!yyval.yyt_contact->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_contact); delete yyval.yyt_contact;
				YYERROR;
			} }
    break;

  case 209:
#line 736 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 210:
#line 737 "parser.yxx"
    {
			yyval.yyt_str = new string(rtrim(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 211:
#line 741 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 212:
#line 744 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*yyvsp[-1].yyt_str));
			MSG->hdr_content_disp.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 213:
#line 751 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 214:
#line 754 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 215:
#line 759 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 216:
#line 759 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 217:
#line 762 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 218:
#line 762 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 219:
#line 767 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 220:
#line 767 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 221:
#line 767 "parser.yxx"
    {
			MSG->hdr_content_length.set_length(yyvsp[-1].yyt_ulong); }
    break;

  case 222:
#line 771 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_content_type.set_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 223:
#line 778 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 224:
#line 778 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 225:
#line 778 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr(yyvsp[-2].yyt_ulong);
			MSG->hdr_cseq.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 226:
#line 784 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 227:
#line 787 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 228:
#line 787 "parser.yxx"
    {
			struct tm t;
			t.tm_mday = yyvsp[-9].yyt_ulong;
			t.tm_mon = yyvsp[-8].yyt_int;
			t.tm_year = yyvsp[-7].yyt_ulong - 1900;
			t.tm_hour = yyvsp[-6].yyt_ulong;
			t.tm_min = yyvsp[-4].yyt_ulong;
			t.tm_sec = yyvsp[-2].yyt_ulong;
			MSG->hdr_date.set_date_gm(&t); }
    break;

  case 229:
#line 798 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 230:
#line 801 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 231:
#line 806 "parser.yxx"
    { CTXT_URI; }
    break;

  case 232:
#line 806 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 233:
#line 806 "parser.yxx"
    {
		  	yyval.yyt_error_param = new t_error_param();
			MEMMAN_NEW(yyval.yyt_error_param);
			yyval.yyt_error_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_error_param->parameter_list = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params;

			if (!yyval.yyt_error_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_error_param); delete yyval.yyt_error_param;
				YYERROR;
			} }
    break;

  case 234:
#line 820 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 235:
#line 820 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 236:
#line 820 "parser.yxx"
    {
			MSG->hdr_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 237:
#line 824 "parser.yxx"
    { CTXT_URI; }
    break;

  case 238:
#line 824 "parser.yxx"
    {
			MSG->hdr_from.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_from.set_uri(yyvsp[-1].yyt_from_addr->uri);
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "tag") {
					MSG->hdr_from.set_tag(i->value);
				} else {
					MSG->hdr_from.add_param(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 239:
#line 839 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 240:
#line 839 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_hdr_from();
			MEMMAN_NEW(yyval.yyt_from_addr);
			yyval.yyt_from_addr->set_uri(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;

			if (!yyval.yyt_from_addr->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_from_addr); delete yyval.yyt_from_addr;
				YYERROR;
			} }
    break;

  case 241:
#line 849 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 242:
#line 849 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_hdr_from();
			MEMMAN_NEW(yyval.yyt_from_addr);
			yyval.yyt_from_addr->set_display(*yyvsp[-4].yyt_str);
			yyval.yyt_from_addr->set_uri(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;

			if (!yyval.yyt_from_addr->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_from_addr); delete yyval.yyt_from_addr;
				YYERROR;
			} }
    break;

  case 243:
#line 863 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 244:
#line 863 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 245:
#line 863 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 246:
#line 866 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 247:
#line 866 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 248:
#line 866 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 249:
#line 871 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 250:
#line 871 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 251:
#line 871 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards(yyvsp[-1].yyt_ulong); }
    break;

  case 252:
#line 875 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 253:
#line 875 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 254:
#line 875 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 255:
#line 879 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 256:
#line 884 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 257:
#line 884 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 258:
#line 884 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 259:
#line 889 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 260:
#line 894 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 261:
#line 897 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 262:
#line 902 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 263:
#line 905 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 264:
#line 910 "parser.yxx"
    { CTXT_URI; }
    break;

  case 265:
#line 910 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 266:
#line 911 "parser.yxx"
    {
			yyval.yyt_route = new t_route;
			MEMMAN_NEW(yyval.yyt_route);
			yyval.yyt_route->display = *yyvsp[-5].yyt_str;
			yyval.yyt_route->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_route->set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-5].yyt_str); delete yyvsp[-5].yyt_str;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params;

			if (!yyval.yyt_route->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_route); delete yyval.yyt_route;
				YYERROR;
			} }
    break;

  case 267:
#line 927 "parser.yxx"
    { CTXT_URI; }
    break;

  case 268:
#line 927 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_reply_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_reply_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 269:
#line 935 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 270:
#line 938 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 271:
#line 943 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 272:
#line 943 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 273:
#line 943 "parser.yxx"
    {
			MSG->hdr_retry_after.set_time(yyvsp[-3].yyt_ulong);
			MSG->hdr_retry_after.set_comment(*yyvsp[-1].yyt_str);
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "duration") {
					int d = strtoul(i->value.c_str(), NULL, 10);
					MSG->hdr_retry_after.set_duration(d);
				} else {
					MSG->hdr_retry_after.add_param(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 274:
#line 959 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 275:
#line 960 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 276:
#line 960 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 277:
#line 960 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[-2].yyt_str; }
    break;

  case 278:
#line 964 "parser.yxx"
    {
			MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 279:
#line 967 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 280:
#line 972 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 281:
#line 975 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 282:
#line 980 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 283:
#line 987 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-3].yyt_str;
			yyval.yyt_server->version = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 284:
#line 998 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 285:
#line 998 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 286:
#line 998 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 287:
#line 1003 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 288:
#line 1005 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 289:
#line 1008 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 290:
#line 1013 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 291:
#line 1013 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 292:
#line 1016 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[0].yyt_float); }
    break;

  case 293:
#line 1018 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[-1].yyt_float);
			MSG->hdr_timestamp.set_delay(yyvsp[0].yyt_float); }
    break;

  case 294:
#line 1023 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 295:
#line 1024 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 296:
#line 1029 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 297:
#line 1030 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 298:
#line 1035 "parser.yxx"
    { CTXT_URI; }
    break;

  case 299:
#line 1035 "parser.yxx"
    {
			MSG->hdr_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "tag") {
					MSG->hdr_to.set_tag(i->value);
				} else {
					MSG->hdr_to.add_param(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 300:
#line 1050 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 301:
#line 1053 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 302:
#line 1058 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 303:
#line 1061 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 304:
#line 1066 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 305:
#line 1069 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 306:
#line 1074 "parser.yxx"
    {
			yyval.yyt_via = yyvsp[-2].yyt_via;
			yyval.yyt_via->host = yyvsp[-1].yyt_via->host;
			yyval.yyt_via->port = yyvsp[-1].yyt_via->port;
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "ttl") {
					yyval.yyt_via->ttl = atoi(i->value.c_str());
				} else if (i->name == "maddr") {
					yyval.yyt_via->maddr = i->value;
				} else if (i->name == "received") {
					yyval.yyt_via->received = i->value;
				} else if (i->name == "branch") {
					yyval.yyt_via->branch = i->value;
				} else if (i->name == "rport") {
					yyval.yyt_via->rport_present = true;
					if (i->type == t_parameter::VALUE) {
						yyval.yyt_via->rport =
							atoi(i->value.c_str());
					}
				} else {
					yyval.yyt_via->add_extension(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_via); delete yyvsp[-1].yyt_via;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 307:
#line 1102 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->protocol_name = toupper(*yyvsp[-4].yyt_str);
			yyval.yyt_via->protocol_version = *yyvsp[-2].yyt_str;
			yyval.yyt_via->transport = toupper(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 308:
#line 1113 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = tolower(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 309:
#line 1118 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 310:
#line 1118 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 311:
#line 1118 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = tolower(*yyvsp[-4].yyt_str);
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 312:
#line 1126 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 313:
#line 1129 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 314:
#line 1134 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 315:
#line 1134 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 316:
#line 1134 "parser.yxx"
    {
			yyval.yyt_warning = new t_warning();
			MEMMAN_NEW(yyval.yyt_warning);
			yyval.yyt_warning->code = yyvsp[-3].yyt_ulong;
			yyval.yyt_warning->host = yyvsp[-1].yyt_via->host;
			yyval.yyt_warning->port = yyvsp[-1].yyt_via->port;
			yyval.yyt_warning->text = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_via); delete yyvsp[-1].yyt_via;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 317:
#line 1145 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 318:
#line 1145 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 319:
#line 1145 "parser.yxx"
    { yyval.yyt_str = yyvsp[-1].yyt_str; }
    break;

  case 320:
#line 1148 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name == "nextnonce")
				MSG->hdr_auth_info.set_next_nonce(yyvsp[0].yyt_param->value);
		 	else if (yyvsp[0].yyt_param->name == "qop")
				MSG->hdr_auth_info.set_message_qop(yyvsp[0].yyt_param->value);
			else if (yyvsp[0].yyt_param->name == "rspauth")
				MSG->hdr_auth_info.set_response_auth(yyvsp[0].yyt_param->value);
			else if (yyvsp[0].yyt_param->name == "cnonce")
				MSG->hdr_auth_info.set_cnonce(yyvsp[0].yyt_param->value);
			else if (yyvsp[0].yyt_param->name == "nc") {
				MSG->hdr_auth_info.set_nonce_count(
							hex2int(yyvsp[0].yyt_param->value));
			}
			else {
				MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
				YYERROR;
			}

			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 323:
#line 1173 "parser.yxx"
    {
			yyval.yyt_dig_resp = new t_digest_response();
			MEMMAN_NEW(yyval.yyt_dig_resp);
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 324:
#line 1181 "parser.yxx"
    {
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 325:
#line 1189 "parser.yxx"
    {
			yyval.yyt_params = new list<t_parameter>;
			MEMMAN_NEW(yyval.yyt_params);
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 326:
#line 1194 "parser.yxx"
    {
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 327:
#line 1199 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 328:
#line 1199 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = AUTH_DIGEST;
			yyval.yyt_credentials->digest_response = *yyvsp[0].yyt_dig_resp;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_resp); delete yyvsp[0].yyt_dig_resp; }
    break;

  case 329:
#line 1205 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 330:
#line 1205 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_credentials->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 331:
#line 1214 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 332:
#line 1214 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*yyvsp[0].yyt_credentials);
			MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 333:
#line 1219 "parser.yxx"
    {
			yyval.yyt_dig_chlg = new t_digest_challenge();
			MEMMAN_NEW(yyval.yyt_dig_chlg);
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 334:
#line 1227 "parser.yxx"
    {
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 335:
#line 1235 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 336:
#line 1235 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = AUTH_DIGEST;
			yyval.yyt_challenge->digest_challenge = *yyvsp[0].yyt_dig_chlg;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_chlg); delete yyvsp[0].yyt_dig_chlg; }
    break;

  case 337:
#line 1241 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 338:
#line 1241 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_challenge->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 339:
#line 1250 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 340:
#line 1250 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 341:
#line 1255 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 342:
#line 1255 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*yyvsp[0].yyt_credentials);
				MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 343:
#line 1261 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 344:
#line 1261 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 345:
#line 1266 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 346:
#line 1266 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 347:
#line 1266 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr(yyvsp[-1].yyt_ulong); }
    break;

  case 348:
#line 1270 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 349:
#line 1270 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 350:
#line 1270 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr(yyvsp[-3].yyt_ulong);
			MSG->hdr_rack.set_cseq_nr(yyvsp[-2].yyt_ulong);
			MSG->hdr_rack.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;


    }

/* Line 1016 of /usr/share/bison/yacc.c.  */
#line 4011 "parser.cxx"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1277 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

