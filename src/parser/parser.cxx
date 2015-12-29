/* A Bison parser, made by GNU Bison 1.875.  */

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
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

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
     T_HDR_ALLOW_EVENTS = 280,
     T_HDR_AUTHENTICATION_INFO = 281,
     T_HDR_AUTHORIZATION = 282,
     T_HDR_CALL_ID = 283,
     T_HDR_CALL_INFO = 284,
     T_HDR_CONTACT = 285,
     T_HDR_CONTENT_DISP = 286,
     T_HDR_CONTENT_ENCODING = 287,
     T_HDR_CONTENT_LANGUAGE = 288,
     T_HDR_CONTENT_LENGTH = 289,
     T_HDR_CONTENT_TYPE = 290,
     T_HDR_CSEQ = 291,
     T_HDR_DATE = 292,
     T_HDR_ERROR_INFO = 293,
     T_HDR_EVENT = 294,
     T_HDR_EXPIRES = 295,
     T_HDR_FROM = 296,
     T_HDR_IN_REPLY_TO = 297,
     T_HDR_MAX_FORWARDS = 298,
     T_HDR_MIN_EXPIRES = 299,
     T_HDR_MIME_VERSION = 300,
     T_HDR_ORGANIZATION = 301,
     T_HDR_PRIORITY = 302,
     T_HDR_PROXY_AUTHENTICATE = 303,
     T_HDR_PROXY_AUTHORIZATION = 304,
     T_HDR_PROXY_REQUIRE = 305,
     T_HDR_RACK = 306,
     T_HDR_RECORD_ROUTE = 307,
     T_HDR_REFER_TO = 308,
     T_HDR_REFERRED_BY = 309,
     T_HDR_REPLY_TO = 310,
     T_HDR_REQUIRE = 311,
     T_HDR_RETRY_AFTER = 312,
     T_HDR_ROUTE = 313,
     T_HDR_RSEQ = 314,
     T_HDR_SERVER = 315,
     T_HDR_SUBJECT = 316,
     T_HDR_SUBSCRIPTION_STATE = 317,
     T_HDR_SUPPORTED = 318,
     T_HDR_TIMESTAMP = 319,
     T_HDR_TO = 320,
     T_HDR_UNSUPPORTED = 321,
     T_HDR_USER_AGENT = 322,
     T_HDR_VIA = 323,
     T_HDR_WARNING = 324,
     T_HDR_WWW_AUTHENTICATE = 325,
     T_HDR_UNKNOWN = 326,
     T_CRLF = 327,
     T_ERROR = 328,
     T_NULL = 329
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
#define T_HDR_ALLOW_EVENTS 280
#define T_HDR_AUTHENTICATION_INFO 281
#define T_HDR_AUTHORIZATION 282
#define T_HDR_CALL_ID 283
#define T_HDR_CALL_INFO 284
#define T_HDR_CONTACT 285
#define T_HDR_CONTENT_DISP 286
#define T_HDR_CONTENT_ENCODING 287
#define T_HDR_CONTENT_LANGUAGE 288
#define T_HDR_CONTENT_LENGTH 289
#define T_HDR_CONTENT_TYPE 290
#define T_HDR_CSEQ 291
#define T_HDR_DATE 292
#define T_HDR_ERROR_INFO 293
#define T_HDR_EVENT 294
#define T_HDR_EXPIRES 295
#define T_HDR_FROM 296
#define T_HDR_IN_REPLY_TO 297
#define T_HDR_MAX_FORWARDS 298
#define T_HDR_MIN_EXPIRES 299
#define T_HDR_MIME_VERSION 300
#define T_HDR_ORGANIZATION 301
#define T_HDR_PRIORITY 302
#define T_HDR_PROXY_AUTHENTICATE 303
#define T_HDR_PROXY_AUTHORIZATION 304
#define T_HDR_PROXY_REQUIRE 305
#define T_HDR_RACK 306
#define T_HDR_RECORD_ROUTE 307
#define T_HDR_REFER_TO 308
#define T_HDR_REFERRED_BY 309
#define T_HDR_REPLY_TO 310
#define T_HDR_REQUIRE 311
#define T_HDR_RETRY_AFTER 312
#define T_HDR_ROUTE 313
#define T_HDR_RSEQ 314
#define T_HDR_SERVER 315
#define T_HDR_SUBJECT 316
#define T_HDR_SUBSCRIPTION_STATE 317
#define T_HDR_SUPPORTED 318
#define T_HDR_TIMESTAMP 319
#define T_HDR_TO 320
#define T_HDR_UNSUPPORTED 321
#define T_HDR_USER_AGENT 322
#define T_HDR_VIA 323
#define T_HDR_WARNING 324
#define T_HDR_WWW_AUTHENTICATE 325
#define T_HDR_UNKNOWN 326
#define T_CRLF 327
#define T_ERROR 328
#define T_NULL 329




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 49 "parser.yxx"
typedef union YYSTYPE {
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
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 267 "parser.cxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 279 "parser.cxx"

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
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

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
	    (To)[yyi] = (From)[yyi];		\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
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
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  224
/* YYNRULES -- Number of rules. */
#define YYNRULES  377
/* YYNRULES -- Number of states. */
#define YYNSTATES  690

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      83,    84,     2,     2,    77,     2,    85,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    78,
      80,    79,    81,     2,    82,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    18,    19,
      20,    27,    28,    33,    37,    38,    39,    40,    48,    49,
      52,    56,    60,    64,    68,    72,    76,    80,    84,    88,
      92,    96,   100,   104,   108,   112,   116,   120,   124,   128,
     132,   136,   140,   144,   148,   152,   156,   160,   164,   168,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   261,   265,   269,   273,   277,   281,   285,   289,
     293,   297,   301,   305,   309,   313,   317,   321,   325,   329,
     333,   337,   341,   345,   349,   353,   357,   361,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   401,   405,   409,
     413,   417,   421,   425,   429,   433,   437,   441,   445,   449,
     453,   457,   461,   465,   468,   471,   474,   477,   480,   483,
     486,   489,   492,   495,   498,   501,   504,   507,   510,   513,
     516,   519,   522,   525,   528,   531,   534,   537,   540,   543,
     546,   549,   552,   555,   558,   561,   564,   567,   570,   573,
     576,   579,   582,   585,   588,   591,   594,   597,   600,   603,
     606,   609,   612,   615,   618,   619,   622,   627,   631,   632,
     636,   638,   642,   646,   648,   652,   654,   657,   660,   661,
     664,   665,   670,   672,   673,   677,   679,   683,   684,   685,
     692,   694,   698,   699,   700,   704,   706,   710,   712,   716,
     717,   718,   725,   726,   727,   731,   733,   735,   739,   742,
     743,   744,   748,   749,   750,   751,   759,   760,   762,   764,
     767,   769,   773,   774,   777,   778,   783,   784,   785,   789,
     792,   793,   794,   799,   800,   801,   815,   817,   821,   822,
     823,   830,   831,   832,   836,   837,   841,   842,   845,   846,
     847,   854,   855,   856,   860,   861,   862,   868,   869,   870,
     874,   875,   876,   880,   882,   883,   884,   888,   890,   892,
     896,   898,   902,   903,   904,   912,   913,   917,   919,   923,
     924,   925,   931,   932,   933,   934,   940,   942,   946,   948,
     951,   953,   956,   961,   962,   963,   967,   968,   970,   974,
     975,   978,   980,   983,   985,   989,   991,   995,   996,  1000,
    1002,  1006,  1008,  1011,  1013,  1017,  1021,  1027,  1029,  1030,
    1031,  1037,  1039,  1043,  1044,  1045,  1051,  1052,  1053,  1057,
    1059,  1061,  1065,  1067,  1071,  1073,  1077,  1078,  1082,  1083,
    1087,  1088,  1091,  1093,  1097,  1098,  1102,  1103,  1107,  1108,
    1111,  1112,  1115,  1116,  1119,  1120,  1121,  1125,  1126,  1127,
    1133,  1136,  1138,  1142,  1145,  1146,  1150,  1151
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      87,     0,    -1,    -1,    88,    89,    -1,    90,    -1,    96,
      -1,     1,    74,    -1,    91,   101,    72,    -1,    -1,    -1,
      17,    92,     8,    93,    94,    72,    -1,    -1,    16,    95,
      75,     4,    -1,    97,   101,    72,    -1,    -1,    -1,    -1,
      94,    98,     3,    99,     7,   100,    72,    -1,    -1,   101,
     102,    -1,   103,   154,    72,    -1,   104,   158,    72,    -1,
     105,   161,    72,    -1,   106,   166,    72,    -1,   107,   170,
      72,    -1,   108,   304,    72,    -1,   109,   279,    72,    -1,
     110,   285,    72,    -1,   111,   171,    72,    -1,   112,   175,
      72,    -1,   113,   179,    72,    -1,   114,   191,    72,    -1,
     115,   192,    72,    -1,   116,   193,    72,    -1,   117,   196,
      72,    -1,   118,   199,    72,    -1,   119,   200,    72,    -1,
     120,   203,    72,    -1,   122,   303,    72,    -1,   121,   206,
      72,    -1,   123,   210,    72,    -1,   124,   213,    72,    -1,
     125,   219,    72,    -1,   126,   224,    72,    -1,   127,   227,
      72,    -1,   128,   230,    72,    -1,   129,   231,    72,    -1,
     130,   234,    72,    -1,   131,   291,    72,    -1,   132,   293,
      72,    -1,   133,   235,    72,    -1,   134,   300,    72,    -1,
     135,   236,    72,    -1,   136,   306,    72,    -1,   137,   308,
      72,    -1,   138,   240,    72,    -1,   139,   242,    72,    -1,
     140,   243,    72,    -1,   141,   249,    72,    -1,   142,   297,
      72,    -1,   143,   250,    72,    -1,   144,   252,    72,    -1,
     145,   305,    72,    -1,   146,   255,    72,    -1,   147,   256,
      72,    -1,   148,   261,    72,    -1,   149,   263,    72,    -1,
     150,   264,    72,    -1,   151,   265,    72,    -1,   152,   271,
      72,    -1,   153,   295,    72,    -1,    71,    76,   275,    72,
      -1,   103,     1,    72,    -1,   104,     1,    72,    -1,   105,
       1,    72,    -1,   106,     1,    72,    -1,   107,     1,    72,
      -1,   108,     1,    72,    -1,   109,     1,    72,    -1,   110,
       1,    72,    -1,   111,     1,    72,    -1,   112,     1,    72,
      -1,   113,     1,    72,    -1,   114,     1,    72,    -1,   115,
       1,    72,    -1,   116,     1,    72,    -1,   117,     1,    72,
      -1,   118,     1,    72,    -1,   119,     1,    72,    -1,   120,
       1,    72,    -1,   121,     1,    72,    -1,   122,     1,    72,
      -1,   123,     1,    72,    -1,   124,     1,    72,    -1,   125,
       1,    72,    -1,   126,     1,    72,    -1,   127,     1,    72,
      -1,   128,     1,    72,    -1,   129,     1,    72,    -1,   130,
       1,    72,    -1,   131,     1,    72,    -1,   132,     1,    72,
      -1,   133,     1,    72,    -1,   134,     1,    72,    -1,   135,
       1,    72,    -1,   136,     1,    72,    -1,   137,     1,    72,
      -1,   138,     1,    72,    -1,   139,     1,    72,    -1,   140,
       1,    72,    -1,   141,     1,    72,    -1,   142,     1,    72,
      -1,   143,     1,    72,    -1,   144,     1,    72,    -1,   145,
       1,    72,    -1,   146,     1,    72,    -1,   147,     1,    72,
      -1,   148,     1,    72,    -1,   149,     1,    72,    -1,   150,
       1,    72,    -1,   151,     1,    72,    -1,   152,     1,    72,
      -1,   153,     1,    72,    -1,    20,    76,    -1,    21,    76,
      -1,    22,    76,    -1,    23,    76,    -1,    24,    76,    -1,
      25,    76,    -1,    26,    76,    -1,    27,    76,    -1,    28,
      76,    -1,    29,    76,    -1,    30,    76,    -1,    31,    76,
      -1,    32,    76,    -1,    33,    76,    -1,    34,    76,    -1,
      35,    76,    -1,    36,    76,    -1,    37,    76,    -1,    38,
      76,    -1,    39,    76,    -1,    40,    76,    -1,    41,    76,
      -1,    42,    76,    -1,    43,    76,    -1,    44,    76,    -1,
      45,    76,    -1,    46,    76,    -1,    47,    76,    -1,    48,
      76,    -1,    49,    76,    -1,    50,    76,    -1,    51,    76,
      -1,    52,    76,    -1,    53,    76,    -1,    54,    76,    -1,
      55,    76,    -1,    56,    76,    -1,    57,    76,    -1,    58,
      76,    -1,    59,    76,    -1,    60,    76,    -1,    61,    76,
      -1,    62,    76,    -1,    63,    76,    -1,    64,    76,    -1,
      65,    76,    -1,    66,    76,    -1,    67,    76,    -1,    68,
      76,    -1,    69,    76,    -1,    70,    76,    -1,    -1,   155,
     156,    -1,   154,    77,   155,   156,    -1,     4,    75,     4,
      -1,    -1,   156,    78,   157,    -1,     4,    -1,     4,    79,
       4,    -1,     4,    79,     5,    -1,   159,    -1,   158,    77,
     159,    -1,     4,    -1,     4,   160,    -1,    78,   157,    -1,
      -1,   162,   164,    -1,    -1,   161,    77,   163,   164,    -1,
      11,    -1,    -1,    11,   165,   160,    -1,   167,    -1,   166,
      77,   167,    -1,    -1,    -1,    80,   168,     8,   169,    81,
     156,    -1,     4,    -1,   170,    77,     4,    -1,    -1,    -1,
     172,   174,   173,    -1,    12,    -1,    12,    82,    12,    -1,
     176,    -1,   175,    77,   176,    -1,    -1,    -1,    80,   177,
       8,   178,    81,   156,    -1,    -1,    -1,   180,     9,   181,
      -1,   182,    -1,   183,    -1,   182,    77,   183,    -1,   184,
     156,    -1,    -1,    -1,   185,     8,   186,    -1,    -1,    -1,
      -1,   187,   190,    80,   188,     8,   189,    81,    -1,    -1,
      10,    -1,     5,    -1,     4,   156,    -1,   159,    -1,   192,
      77,   159,    -1,    -1,   194,   164,    -1,    -1,   193,    77,
     195,   164,    -1,    -1,    -1,   197,     3,   198,    -1,   155,
     156,    -1,    -1,    -1,   201,     3,   202,     4,    -1,    -1,
      -1,   204,    13,    77,     3,    14,     3,     3,    76,     3,
      76,     3,    15,   205,    -1,   207,    -1,   206,    77,   207,
      -1,    -1,    -1,    80,   208,     8,   209,    81,   156,    -1,
      -1,    -1,   211,     3,   212,    -1,    -1,   214,   215,   156,
      -1,    -1,     8,   216,    -1,    -1,    -1,   190,    80,   217,
       8,   218,    81,    -1,    -1,    -1,   220,   174,   221,    -1,
      -1,    -1,   219,    77,   222,   174,   223,    -1,    -1,    -1,
     225,     3,   226,    -1,    -1,    -1,   228,     3,   229,    -1,
       4,    -1,    -1,    -1,   232,     7,   233,    -1,     4,    -1,
       4,    -1,   235,    77,     4,    -1,   237,    -1,   236,    77,
     237,    -1,    -1,    -1,   238,   190,    80,     8,   239,    81,
     156,    -1,    -1,   241,   215,   156,    -1,     4,    -1,   235,
      77,     4,    -1,    -1,    -1,   244,     3,   245,   246,   156,
      -1,    -1,    -1,    -1,    83,   247,     6,   248,    84,    -1,
     237,    -1,   249,    77,   237,    -1,   251,    -1,   250,   251,
      -1,   246,    -1,     4,   246,    -1,     4,    75,     4,   246,
      -1,    -1,    -1,   253,     7,   254,    -1,    -1,     4,    -1,
     255,    77,     4,    -1,    -1,   257,   258,    -1,   259,    -1,
     259,   260,    -1,     3,    -1,     3,    85,     3,    -1,     3,
      -1,     3,    85,     3,    -1,    -1,   262,   215,   156,    -1,
       4,    -1,   263,    77,     4,    -1,   251,    -1,   264,   251,
      -1,   266,    -1,   265,    77,   266,    -1,   267,   268,   156,
      -1,     4,    75,     4,    75,     4,    -1,     4,    -1,    -1,
      -1,     4,    76,   269,     3,   270,    -1,   272,    -1,   271,
      77,   272,    -1,    -1,    -1,   273,     3,   274,   268,     5,
      -1,    -1,    -1,   276,     7,   277,    -1,   157,    -1,   278,
      -1,   279,    77,   278,    -1,   157,    -1,   280,    77,   157,
      -1,   157,    -1,   281,    77,   157,    -1,    -1,    18,   283,
     280,    -1,    -1,    19,   284,   281,    -1,    -1,   286,   282,
      -1,   157,    -1,   287,    77,   157,    -1,    -1,    18,   289,
     287,    -1,    -1,    19,   290,   281,    -1,    -1,   292,   288,
      -1,    -1,   294,   282,    -1,    -1,   296,   288,    -1,    -1,
      -1,   298,     3,   299,    -1,    -1,    -1,   301,     3,     3,
     302,     4,    -1,     4,   156,    -1,     4,    -1,   304,    77,
       4,    -1,     4,   156,    -1,    -1,   307,   215,   156,    -1,
      -1,   309,   215,   156,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   227,   227,   227,   230,   231,   232,   252,   261,   261,
     261,   279,   279,   283,   290,   290,   291,   290,   301,   302,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   360,   362,   364,   366,   368,   370,   372,   374,
     376,   378,   380,   382,   384,   386,   388,   390,   392,   394,
     396,   398,   400,   402,   404,   406,   408,   410,   412,   414,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     436,   438,   440,   442,   444,   446,   448,   450,   452,   454,
     456,   458,   460,   473,   475,   477,   479,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   535,   537,   539,   541,   543,   545,
     547,   549,   551,   553,   555,   557,   559,   561,   563,   565,
     567,   569,   571,   573,   576,   577,   582,   589,   595,   596,
     602,   606,   611,   618,   621,   626,   630,   637,   644,   644,
     647,   647,   652,   657,   657,   664,   667,   672,   672,   672,
     687,   690,   695,   695,   695,   700,   701,   708,   711,   716,
     716,   716,   731,   731,   731,   733,   738,   743,   749,   765,
     765,   765,   776,   776,   776,   776,   791,   792,   796,   799,
     806,   809,   814,   814,   817,   817,   822,   822,   822,   826,
     833,   833,   833,   839,   842,   839,   853,   856,   861,   861,
     861,   876,   876,   876,   880,   880,   895,   895,   906,   906,
     906,   921,   921,   921,   924,   924,   924,   929,   929,   929,
     933,   933,   933,   937,   942,   942,   942,   947,   952,   955,
     960,   963,   968,   968,   968,   986,   986,   994,   997,  1002,
    1002,  1002,  1018,  1019,  1019,  1019,  1023,  1026,  1031,  1034,
    1039,  1044,  1051,  1062,  1062,  1062,  1067,  1069,  1072,  1077,
    1077,  1080,  1082,  1087,  1088,  1093,  1094,  1099,  1099,  1114,
    1117,  1122,  1125,  1130,  1133,  1138,  1166,  1177,  1182,  1182,
    1182,  1192,  1195,  1200,  1200,  1200,  1211,  1211,  1211,  1214,
    1234,  1235,  1238,  1245,  1252,  1257,  1262,  1262,  1268,  1268,
    1277,  1277,  1282,  1289,  1296,  1296,  1302,  1302,  1311,  1311,
    1316,  1316,  1322,  1322,  1327,  1327,  1327,  1331,  1331,  1331,
    1338,  1352,  1355,  1360,  1386,  1386,  1394,  1394
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
  "T_HDR_ALLOW", "T_HDR_ALLOW_EVENTS", "T_HDR_AUTHENTICATION_INFO", 
  "T_HDR_AUTHORIZATION", "T_HDR_CALL_ID", "T_HDR_CALL_INFO", 
  "T_HDR_CONTACT", "T_HDR_CONTENT_DISP", "T_HDR_CONTENT_ENCODING", 
  "T_HDR_CONTENT_LANGUAGE", "T_HDR_CONTENT_LENGTH", "T_HDR_CONTENT_TYPE", 
  "T_HDR_CSEQ", "T_HDR_DATE", "T_HDR_ERROR_INFO", "T_HDR_EVENT", 
  "T_HDR_EXPIRES", "T_HDR_FROM", "T_HDR_IN_REPLY_TO", 
  "T_HDR_MAX_FORWARDS", "T_HDR_MIN_EXPIRES", "T_HDR_MIME_VERSION", 
  "T_HDR_ORGANIZATION", "T_HDR_PRIORITY", "T_HDR_PROXY_AUTHENTICATE", 
  "T_HDR_PROXY_AUTHORIZATION", "T_HDR_PROXY_REQUIRE", "T_HDR_RACK", 
  "T_HDR_RECORD_ROUTE", "T_HDR_REFER_TO", "T_HDR_REFERRED_BY", 
  "T_HDR_REPLY_TO", "T_HDR_REQUIRE", "T_HDR_RETRY_AFTER", "T_HDR_ROUTE", 
  "T_HDR_RSEQ", "T_HDR_SERVER", "T_HDR_SUBJECT", 
  "T_HDR_SUBSCRIPTION_STATE", "T_HDR_SUPPORTED", "T_HDR_TIMESTAMP", 
  "T_HDR_TO", "T_HDR_UNSUPPORTED", "T_HDR_USER_AGENT", "T_HDR_VIA", 
  "T_HDR_WARNING", "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", "T_CRLF", 
  "T_ERROR", "T_NULL", "'/'", "':'", "','", "';'", "'='", "'<'", "'>'", 
  "'@'", "'('", "')'", "'.'", "$accept", "sip_message", "@1", 
  "sip_message2", "request", "request_line", "@2", "@3", "sip_version", 
  "@4", "response", "status_line", "@5", "@6", "@7", "headers", "header", 
  "hd_accept", "hd_accept_encoding", "hd_accept_language", 
  "hd_alert_info", "hd_allow", "hd_allow_events", 
  "hd_authentication_info", "hd_authorization", "hd_call_id", 
  "hd_call_info", "hd_contact", "hd_content_disp", "hd_content_encoding", 
  "hd_content_language", "hd_content_length", "hd_content_type", 
  "hd_cseq", "hd_date", "hd_error_info", "hd_event", "hd_expires", 
  "hd_from", "hd_in_reply_to", "hd_max_forwards", "hd_min_expires", 
  "hd_mime_version", "hd_organization", "hd_priority", 
  "hd_proxy_authenticate", "hd_proxy_authorization", "hd_proxy_require", 
  "hd_rack", "hd_record_route", "hd_refer_to", "hd_referred_by", 
  "hd_reply_to", "hd_require", "hd_retry_after", "hd_route", "hd_rseq", 
  "hd_server", "hd_subject", "hd_subscription_state", "hd_supported", 
  "hd_timestamp", "hd_to", "hd_unsupported", "hd_user_agent", "hd_via", 
  "hd_warning", "hd_www_authenticate", "hdr_accept", "media_range", 
  "parameters", "parameter", "hdr_accept_encoding", "content_coding", 
  "q_factor", "hdr_accept_language", "@8", "@9", "language", "@10", 
  "hdr_alert_info", "alert_param", "@11", "@12", "hdr_allow", 
  "hdr_call_id", "@13", "@14", "call_id", "hdr_call_info", "info_param", 
  "@15", "@16", "hdr_contact", "@17", "@18", "contacts", "contact_param", 
  "contact_addr", "@19", "@20", "@21", "@22", "@23", "display_name", 
  "hdr_content_disp", "hdr_content_encoding", "hdr_content_language", 
  "@24", "@25", "hdr_content_length", "@26", "@27", "hdr_content_type", 
  "hdr_cseq", "@28", "@29", "hdr_date", "@30", "@31", "hdr_error_info", 
  "error_param", "@32", "@33", "hdr_expires", "@34", "@35", "hdr_from", 
  "@36", "from_addr", "@37", "@38", "@39", "hdr_in_reply_to", "@40", 
  "@41", "@42", "@43", "hdr_max_forwards", "@44", "@45", 
  "hdr_min_expires", "@46", "@47", "hdr_mime_version", "hdr_organization", 
  "@48", "@49", "hdr_priority", "hdr_proxy_require", "hdr_record_route", 
  "rec_route", "@50", "@51", "hdr_reply_to", "@52", "hdr_require", 
  "hdr_retry_after", "@53", "@54", "comment", "@55", "@56", "hdr_route", 
  "hdr_server", "server", "hdr_subject", "@57", "@58", "hdr_supported", 
  "hdr_timestamp", "@59", "hdr_timestamp1", "timestamp", "delay", 
  "hdr_to", "@60", "hdr_unsupported", "hdr_user_agent", "hdr_via", 
  "via_parm", "sent_protocol", "host", "@61", "@62", "hdr_warning", 
  "warning", "@63", "@64", "hdr_unknown", "@65", "@66", "ainfo", 
  "hdr_authentication_info", "digest_response", "auth_params", 
  "credentials", "@67", "@68", "hdr_authorization", "@69", 
  "digest_challenge", "challenge", "@70", "@71", "hdr_proxy_authenticate", 
  "@72", "hdr_proxy_authorization", "@73", "hdr_www_authenticate", "@74", 
  "hdr_rseq", "@75", "@76", "hdr_rack", "@77", "@78", "hdr_event", 
  "hdr_allow_events", "hdr_subscription_state", "hdr_refer_to", "@79", 
  "hdr_referred_by", "@80", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    47,    58,    44,    59,    61,
      60,    62,    64,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,    86,    88,    87,    89,    89,    89,    90,    92,    93,
      91,    95,    94,    96,    98,    99,   100,    97,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   154,   154,   155,   156,   156,
     157,   157,   157,   158,   158,   159,   159,   160,   162,   161,
     163,   161,   164,   165,   164,   166,   166,   168,   169,   167,
     170,   170,   172,   173,   171,   174,   174,   175,   175,   177,
     178,   176,   180,   181,   179,   179,   182,   182,   183,   185,
     186,   184,   187,   188,   189,   184,   190,   190,   190,   191,
     192,   192,   194,   193,   195,   193,   197,   198,   196,   199,
     201,   202,   200,   204,   205,   203,   206,   206,   208,   209,
     207,   211,   212,   210,   214,   213,   216,   215,   217,   218,
     215,   220,   221,   219,   222,   223,   219,   225,   226,   224,
     228,   229,   227,   230,   232,   233,   231,   234,   235,   235,
     236,   236,   238,   239,   237,   241,   240,   242,   242,   244,
     245,   243,   246,   247,   248,   246,   249,   249,   250,   250,
     251,   251,   251,   253,   254,   252,   255,   255,   255,   257,
     256,   258,   258,   259,   259,   260,   260,   262,   261,   263,
     263,   264,   264,   265,   265,   266,   267,   268,   269,   270,
     268,   271,   271,   273,   274,   272,   276,   277,   275,   278,
     279,   279,   280,   280,   281,   281,   283,   282,   284,   282,
     286,   285,   287,   287,   289,   288,   290,   288,   292,   291,
     294,   293,   296,   295,   298,   299,   297,   301,   302,   300,
     303,   304,   304,   305,   307,   306,   309,   308
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     3,     0,     0,
       6,     0,     4,     3,     0,     0,     0,     7,     0,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     2,     4,     3,     0,     3,
       1,     3,     3,     1,     3,     1,     2,     2,     0,     2,
       0,     4,     1,     0,     3,     1,     3,     0,     0,     6,
       1,     3,     0,     0,     3,     1,     3,     1,     3,     0,
       0,     6,     0,     0,     3,     1,     1,     3,     2,     0,
       0,     3,     0,     0,     0,     7,     0,     1,     1,     2,
       1,     3,     0,     2,     0,     4,     0,     0,     3,     2,
       0,     0,     4,     0,     0,    13,     1,     3,     0,     0,
       6,     0,     0,     3,     0,     3,     0,     2,     0,     0,
       6,     0,     0,     3,     0,     0,     5,     0,     0,     3,
       0,     0,     3,     1,     0,     0,     3,     1,     1,     3,
       1,     3,     0,     0,     7,     0,     3,     1,     3,     0,
       0,     5,     0,     0,     0,     5,     1,     3,     1,     2,
       1,     2,     4,     0,     0,     3,     0,     1,     3,     0,
       2,     1,     2,     1,     3,     1,     3,     0,     3,     1,
       3,     1,     2,     1,     3,     3,     5,     1,     0,     0,
       5,     1,     3,     0,     0,     5,     0,     0,     3,     1,
       1,     3,     1,     3,     1,     3,     0,     3,     0,     3,
       0,     2,     1,     3,     0,     3,     0,     3,     0,     2,
       0,     2,     0,     2,     0,     0,     3,     0,     0,     5,
       2,     1,     3,     2,     0,     3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       2,     0,     0,     1,     0,    11,     8,     3,     4,    18,
      14,     5,    18,     6,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    13,    12,     0,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   336,     0,     0,     0,   178,     0,   185,     0,   183,
       0,     0,     0,     0,   197,     0,   195,     0,   200,     0,
       0,   371,     0,     0,   180,   339,   340,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,   207,     0,     0,
       0,   215,   216,   178,     0,   226,     0,   178,     0,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,   248,     0,
     246,     0,   178,     0,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,     0,   277,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,     0,     0,     0,
       0,     0,   280,   226,     0,     0,   226,     0,     0,   226,
       0,     0,   226,     0,   278,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,   292,   293,   300,
       0,   298,     0,     0,     0,     0,   178,     0,     0,   307,
       0,     0,     0,     0,     0,     0,   226,     0,   319,     0,
       0,   321,     0,     0,     0,     0,   323,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,    20,     0,   175,    73,     0,   186,    21,     0,    74,
      22,   190,   192,   189,    75,     0,    23,     0,    76,    24,
       0,    77,    25,     0,    78,     0,    26,     0,    79,    27,
     346,   348,   351,    80,    28,   205,   203,    81,     0,    29,
       0,    82,    30,   213,   222,   218,   220,   228,   227,     0,
      83,   229,    31,    84,    32,     0,    85,    33,   234,   233,
      86,    34,   237,    87,   239,    35,    88,    36,   241,    89,
      37,     0,    90,     0,    39,     0,    91,   370,    38,    92,
      40,   252,    93,    41,   256,     0,   178,    94,    42,   264,
     262,    95,    43,   268,    96,    44,   271,    97,    45,    98,
      46,   275,    99,    47,   100,    48,   354,   356,   359,   101,
      49,   361,   102,    50,     0,   103,    51,     0,   104,    52,
     282,     0,   105,    53,   178,   106,    54,   178,   107,    55,
     178,   108,     0,    56,   109,    57,   290,   110,    58,   282,
     111,    59,   365,   112,     0,   301,     0,    60,   299,   113,
      61,   304,   114,   373,    62,   115,    63,     0,   116,    64,
     313,   310,   311,   117,    65,   178,   118,    66,     0,   119,
      67,   322,   120,     0,    68,     0,   327,   178,   121,    69,
     333,   334,   122,    70,   363,    16,    10,    71,   337,   177,
     178,     0,   187,   184,     0,     0,   198,   196,   201,   372,
     181,   182,   341,     0,     0,     0,   204,   210,   208,   214,
     217,   221,   223,   231,     0,   238,     0,     0,   249,   247,
     253,   257,   258,   255,     0,   263,   269,   272,   276,     0,
       0,   279,   368,   281,     0,   375,   377,   286,   279,   292,
     297,   366,   292,   294,   305,   308,     0,   315,   312,   318,
     320,     0,   324,   328,   325,   332,     0,     0,   338,   176,
     179,   191,   194,     0,   342,   347,   344,   349,   206,     0,
       0,   235,   242,     0,     0,     0,   265,   352,   355,   357,
       0,   283,   178,   302,     0,   314,     0,     0,     0,     0,
      17,   178,     0,     0,   178,   224,     0,   178,   259,   266,
       0,   369,     0,   291,   295,   316,   326,   329,   335,   199,
     343,   345,   211,     0,     0,   250,     0,   353,   178,   330,
     225,     0,   260,   284,     0,     0,     0,     0,   244,   245
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    15,   129,    10,    14,
      11,    12,    17,   355,   617,    16,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   184,   185,
     363,   205,   188,   189,   366,   191,   192,   554,   373,   555,
     195,   196,   375,   623,   199,   212,   213,   566,   396,   216,
     217,   398,   629,   219,   220,   569,   221,   222,   223,   224,
     571,   225,   630,   673,   445,   228,   231,   233,   234,   574,
     236,   237,   575,   240,   242,   243,   576,   245,   246,   689,
     249,   250,   433,   634,   255,   256,   580,   258,   259,   446,
     581,   635,   676,   261,   262,   585,   584,   659,   264,   265,
     586,   267,   268,   587,   271,   273,   274,   588,   277,   286,
     291,   292,   293,   662,   301,   302,   306,   308,   309,   599,
     319,   506,   644,   312,   320,   321,   323,   324,   604,   330,
     332,   333,   521,   522,   608,   335,   336,   339,   342,   345,
     346,   347,   537,   648,   679,   349,   350,   351,   616,   357,
     358,   618,   206,   207,   625,   627,   392,   563,   564,   209,
     210,   638,   468,   589,   590,   279,   280,   282,   283,   353,
     354,   314,   315,   601,   288,   289,   640,   253,   202,   327,
     295,   296,   298,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -361
static const short yypact[] =
{
    -361,    35,    62,  -361,    -9,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,    -3,    87,   115,   101,   436,   109,
    -361,    55,   142,   186,   201,   206,   221,   222,   223,   225,
     227,   228,   229,   233,   234,   235,   239,   240,   241,   245,
     247,   253,   257,   258,   259,   260,   261,   263,   264,   267,
     270,   274,   275,   276,   278,   279,   281,   282,   283,   286,
     287,   288,   289,   290,   293,   294,   295,   296,   297,   298,
     299,   300,   301,  -361,  -361,    37,   230,    49,    17,   231,
     232,   236,    58,    63,    19,    14,   237,   238,    97,   262,
     242,   265,    31,    25,   243,   268,    20,    89,   269,   272,
     244,    67,   248,    65,    68,   249,   273,    46,    26,    32,
      38,   250,   277,    52,   280,     9,   110,   254,    57,   284,
      44,   255,    10,   256,   285,    70,  -361,  -361,  -361,   292,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,   246,   251,    43,  -361,   252,   266,    50,  -361,
     306,    53,   302,   307,  -361,    56,  -361,   308,  -361,   116,
     309,  -361,   117,   310,   304,  -361,  -361,   118,   312,   313,
     180,   314,   316,   318,   317,  -361,   120,  -361,   319,   320,
     303,   321,  -361,  -361,   311,   191,   322,  -361,   323,   324,
    -361,   128,   325,   130,   302,   327,   328,   329,   330,  -361,
     331,   332,   333,   335,   334,   336,   340,   337,  -361,   136,
    -361,   338,  -361,   339,   341,   342,   344,   343,   345,   111,
     346,   137,   318,   348,   349,   353,   350,   351,   357,   352,
    -361,   354,   355,   358,   360,   361,  -361,   363,   364,   365,
     271,   366,   367,   180,   368,  -361,   138,   369,   370,   387,
     371,   139,  -361,   191,   372,   373,   111,   374,   375,   111,
     376,   377,   111,   378,   379,   432,   380,   381,   382,   390,
     438,  -361,   140,   439,   440,   398,   441,    27,  -361,  -361,
       8,  -361,   442,   443,   400,   444,  -361,   445,   446,  -361,
     147,   447,   448,   409,   449,   450,   111,   451,  -361,   148,
     452,  -361,    13,   453,   454,   149,  -361,   412,   455,   150,
    -361,   422,   456,   458,   271,   425,   459,   460,   519,  -361,
     529,  -361,   530,   457,  -361,   532,  -361,  -361,   533,  -361,
    -361,  -361,   461,  -361,  -361,   421,  -361,   226,  -361,  -361,
     534,  -361,  -361,   536,  -361,   291,  -361,   532,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,   462,  -361,  -361,   535,  -361,
     465,  -361,  -361,  -361,   538,   457,  -361,  -361,  -361,   467,
    -361,   457,  -361,  -361,  -361,   533,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,   457,  -361,  -361,  -361,  -361,  -361,
    -361,   464,  -361,   540,  -361,   469,  -361,   457,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,   470,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,   547,  -361,  -361,   539,  -361,  -361,
    -361,   472,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,   549,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,   550,  -361,   551,  -361,  -361,  -361,
    -361,  -361,  -361,   457,  -361,  -361,  -361,   552,  -361,  -361,
     473,  -361,   556,  -361,  -361,  -361,  -361,  -361,   557,  -361,
    -361,  -361,  -361,   558,  -361,   559,   479,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,   532,  -361,  -361,   302,   266,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,   532,   532,   548,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,   302,  -361,   560,   562,  -361,  -361,
    -361,  -361,  -361,   457,   318,  -361,  -361,  -361,  -361,   532,
     532,  -361,  -361,  -361,   561,   457,   457,   457,   494,   224,
    -361,  -361,   224,  -361,  -361,  -361,   564,   483,  -361,   457,
    -361,   495,  -361,  -361,   457,  -361,   412,   499,  -361,   457,
    -361,  -361,  -361,   491,  -361,   496,  -361,   497,  -361,   498,
     567,  -361,  -361,   347,   500,   568,  -361,  -361,   501,   497,
     573,  -361,  -361,  -361,   502,  -361,   577,   578,   580,   315,
    -361,  -361,   532,   532,  -361,  -361,   581,  -361,  -361,  -361,
     532,  -361,   504,   457,  -361,  -361,  -361,  -361,  -361,   457,
    -361,  -361,   457,   506,   585,   457,   508,  -361,  -361,  -361,
    -361,   514,  -361,   457,   588,   516,   590,   326,  -361,  -361
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,   196,  -361,
    -361,  -361,  -361,  -361,  -361,   582,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,   -83,
    -223,  -360,  -361,   -84,  -210,  -361,  -361,  -361,  -232,  -361,
    -361,   -29,  -361,  -361,  -361,  -361,  -361,  -361,  -256,  -361,
     -51,  -361,  -361,  -361,  -361,  -361,  -361,   192,  -361,  -361,
    -361,  -361,  -361,  -361,  -170,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,   160,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -229,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,   486,
    -361,  -112,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -308,  -361,  -361,  -361,  -361,  -114,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
      64,  -361,   -18,  -361,  -361,  -361,    60,  -361,  -361,  -361,
    -361,  -361,   214,  -361,  -361,    12,   356,  -361,  -361,  -361,
    -361,  -361,   305,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,  -361,
    -361,  -361,  -361,  -361
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -377
static const short yytable[] =
{
     405,   311,   419,   230,   411,   552,   450,   239,   341,   505,
     316,   340,   317,   317,   317,   218,   424,   317,   193,  -222,
     214,   257,  -219,  -212,  -222,  -254,   247,   294,  -254,   437,
    -254,  -374,   244,   297,  -374,     3,  -374,  -376,   182,   300,
    -376,   183,  -376,  -285,  -243,   334,  -285,   290,  -285,  -317,
     190,  -282,  -317,   310,  -317,   409,  -282,  -282,   328,   208,
    -188,   329,  -282,     4,   211,    13,   278,   484,   272,   281,
     487,   352,    19,   490,  -274,  -202,  -350,  -350,     5,     6,
     507,  -292,  -292,  -358,  -358,   530,  -360,  -360,  -362,  -362,
     260,   318,   318,   318,  -222,    20,   318,   194,   232,   215,
    -254,  -261,   504,   513,   126,   248,  -374,   525,  -232,  -174,
     318,   322,  -376,   128,  -174,   361,   407,  -303,  -285,   444,
     362,   408,   367,   481,  -317,   370,  -282,   368,   376,  -306,
     371,   130,  -282,   377,  -306,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   379,   382,
     386,   620,   399,   380,   383,   387,   407,   400,   390,   391,
     414,   408,   417,   624,   626,   415,   508,   418,   434,   448,
     473,   479,   498,   435,   449,   474,   480,   499,   131,   516,
     527,   534,   539,   583,   517,   528,   535,   540,   531,   637,
     626,   186,   197,   200,   187,   198,   201,   203,   226,   229,
     204,   227,   187,   238,   251,   269,   183,   252,   270,   275,
     284,   303,   276,   285,   304,   325,   337,   343,   326,   338,
     344,   595,   132,   235,   596,  -236,   241,   597,  -240,   254,
     263,  -251,  -267,   266,   287,  -270,  -367,   133,   307,   550,
    -289,   313,   134,  -364,   553,   331,   348,  -309,  -333,   466,
     467,   642,   670,   671,   643,   560,   561,   135,   136,   137,
     677,   138,   609,   139,   140,   141,   194,   318,     5,   142,
     143,   144,   403,   372,   614,   145,   146,   147,   359,   406,
     668,   148,   621,   149,   364,   356,   360,   619,   636,   150,
     395,   573,   422,   151,   152,   153,   154,   155,   428,   156,
     157,   688,   631,   158,   365,   622,   159,   441,   557,   568,
     160,   161,   162,   431,   163,   164,   453,   165,   166,   167,
     456,   656,   168,   169,   170,   171,   172,   461,   593,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   369,   374,
     378,   381,   384,   385,   388,   389,   393,   600,   394,   397,
     477,   401,   402,   496,   410,   412,   413,   416,   404,   420,
     421,   502,   423,   425,   426,   427,   429,   511,   430,   432,
     436,   438,   520,   439,   440,   442,   536,   443,   447,   663,
     451,   452,   454,   455,   457,   541,   458,   459,   669,   556,
     460,   672,   545,   462,   675,   463,   464,   465,   469,   470,
     472,   475,   476,   478,   482,   483,   485,   486,   488,   489,
     491,  -287,   493,   494,   495,   683,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,   127,   492,
     497,   500,   501,   503,   509,   510,   512,   514,   515,   518,
     519,   523,   524,   526,   529,   532,   548,   538,   542,   533,
     543,   546,   547,   549,   183,   551,   204,   187,   558,  -193,
     559,   577,   592,   567,   565,   215,  -219,   572,   578,   248,
     582,   591,   594,   598,   602,   613,   605,   603,   606,   607,
     628,   610,   611,   344,   632,   633,  -288,   645,   646,   641,
     647,   650,   651,   652,   653,   655,   658,   661,   660,   654,
     665,   657,   666,   667,   674,   678,   664,   680,   681,   682,
     684,   685,   686,   687,    18,   579,   570,   305,   649,   612,
     615,   562,   639,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   544
};

static const short yycheck[] =
{
     223,   113,   234,    87,   227,   365,   262,    90,   122,   317,
       1,     1,     4,     4,     4,     1,   239,     4,     1,     5,
       1,     1,     8,     9,    10,     5,     1,     1,     8,   252,
      10,     5,     1,     1,     8,     0,    10,     5,     1,     1,
       8,     4,    10,     5,    13,     1,     8,     1,    10,     5,
       1,     5,     8,     1,    10,   225,    10,     5,     1,     1,
      11,     4,    10,     1,     1,    74,     1,   296,     1,     1,
     299,     1,    75,   302,     7,    12,    18,    19,    16,    17,
      72,    72,    72,    18,    19,    72,    18,    19,    18,    19,
       1,    83,    83,    83,    80,     8,    83,    80,     1,    80,
      80,    12,    75,   326,     3,    80,    80,   336,    11,    72,
      83,     1,    80,     4,    77,    72,     5,     7,    80,     8,
      77,    10,    72,   293,    80,    72,    80,    77,    72,    72,
      77,    76,    80,    77,    77,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    72,    72,
      72,   551,    72,    77,    77,    77,     5,    77,    18,    19,
      72,    10,    72,   563,   564,    77,   320,    77,    72,    72,
      72,    72,    72,    77,    77,    77,    77,    77,    76,    72,
      72,    72,    72,   446,    77,    77,    77,    77,   342,   589,
     590,     1,     1,     1,     4,     4,     4,     1,     1,     1,
       4,     4,     4,     1,     1,     1,     4,     4,     4,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     4,     4,
       4,   484,    76,     1,   487,     3,     1,   490,     3,     1,
       1,     3,     3,     1,     1,     3,     3,    76,     1,   362,
       3,     1,    76,     3,   368,     1,     1,     3,     3,    18,
      19,   599,   652,   653,   602,     4,     5,    76,    76,    76,
     660,    76,   525,    76,    76,    76,    80,    83,    16,    76,
      76,    76,     9,    11,   537,    76,    76,    76,    72,     8,
       5,    76,   554,    76,    72,   129,    75,   550,   584,    76,
      12,   415,     3,    76,    76,    76,    76,    76,     3,    76,
      76,    15,   574,    76,    78,   555,    76,     3,   377,   400,
      76,    76,    76,    13,    76,    76,     3,    76,    76,    76,
       3,    14,    76,    76,    76,    76,    76,     7,   480,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    72,    72,
      72,    72,    72,    79,    72,    72,    72,   499,    72,    72,
       3,    72,    72,     3,    72,    72,    72,    72,    77,    72,
      72,     3,    72,    72,    72,    72,    72,     7,    72,    72,
      72,    72,     3,    72,    72,    72,     4,    72,    72,   642,
      72,    72,    72,    72,    72,     3,    72,    72,   651,     8,
      72,   654,     7,    72,   657,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,   678,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    77,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,     7,    72,    72,    75,
      72,    72,    72,     4,     4,    78,     4,     4,     4,    78,
       4,    77,     3,     8,    82,    80,     8,    80,     8,    80,
      80,     4,    80,     4,     4,    76,     4,     6,    85,     3,
      12,     4,     4,     4,     4,     3,    72,     3,    85,     8,
      75,    72,    81,    77,    77,     8,     8,     4,    77,    81,
       3,    81,     4,     3,     3,    81,    84,    81,     3,    81,
      76,     3,    76,     3,    12,   435,   404,   111,   616,   535,
     540,   387,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    87,    88,     0,     1,    16,    17,    89,    90,    91,
      94,    96,    97,    74,    95,    92,   101,    98,   101,    75,
       8,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     3,    72,     4,    93,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,     1,     4,   154,   155,     1,     4,   158,   159,
       1,   161,   162,     1,    80,   166,   167,     1,     4,   170,
       1,     4,   304,     1,     4,   157,   278,   279,     1,   285,
     286,     1,   171,   172,     1,    80,   175,   176,     1,   179,
     180,   182,   183,   184,   185,   187,     1,     4,   191,     1,
     159,   192,     1,   193,   194,     1,   196,   197,     1,   155,
     199,     1,   200,   201,     1,   203,   204,     1,    80,   206,
     207,     1,     4,   303,     1,   210,   211,     1,   213,   214,
       1,   219,   220,     1,   224,   225,     1,   227,   228,     1,
       4,   230,     1,   231,   232,     1,     4,   234,     1,   291,
     292,     1,   293,   294,     1,     4,   235,     1,   300,   301,
       1,   236,   237,   238,     1,   306,   307,     1,   308,   309,
       1,   240,   241,     1,     4,   235,   242,     1,   243,   244,
       1,   237,   249,     1,   297,   298,     1,     4,    83,   246,
     250,   251,     1,   252,   253,     1,     4,   305,     1,     4,
     255,     1,   256,   257,     1,   261,   262,     1,     4,   263,
       1,   251,   264,     1,     4,   265,   266,   267,     1,   271,
     272,   273,     1,   295,   296,    99,    94,   275,   276,    72,
      75,    72,    77,   156,    72,    78,   160,    72,    77,    72,
      72,    77,    11,   164,    72,   168,    72,    77,    72,    72,
      77,    72,    72,    77,    72,    79,    72,    77,    72,    72,
      18,    19,   282,    72,    72,    12,   174,    72,   177,    72,
      77,    72,    72,     9,    77,   156,     8,     5,    10,   190,
      72,   156,    72,    72,    72,    77,    72,    72,    77,   164,
      72,    72,     3,    72,   156,    72,    72,    72,     3,    72,
      72,    13,    72,   208,    72,    77,    72,   156,    72,    72,
      72,     3,    72,    72,     8,   190,   215,    72,    72,    77,
     174,    72,    72,     3,    72,    72,     3,    72,    72,    72,
      72,     7,    72,    72,    72,    72,    18,    19,   288,    72,
      72,   282,    72,    72,    77,    72,    72,     3,    72,    72,
      77,   190,    72,    72,   215,    72,    72,   215,    72,    72,
     215,    72,    77,    72,    72,    72,     3,    72,    72,    77,
      72,    72,     3,    72,    75,   246,   247,    72,   251,    72,
      72,     7,    72,   156,    72,    72,    72,    77,    72,    72,
       3,   258,   259,    72,    72,   215,    72,    72,    77,    72,
      72,   251,    72,    75,    72,    77,     4,   268,    72,    72,
      77,     3,    72,    72,   288,     7,    72,    72,     7,     4,
     155,    78,   157,   159,   163,   165,     8,   167,     4,     4,
       4,     5,   278,   283,   284,    82,   173,     8,   176,   181,
     183,   186,    80,   159,   195,   198,   202,    77,     8,   207,
     212,   216,    80,   156,   222,   221,   226,   229,   233,   289,
     290,     4,     3,   237,    80,   156,   156,   156,     4,   245,
     237,   299,     4,     6,   254,     4,    85,     3,   260,   156,
       4,     4,   266,    76,   156,   272,   274,   100,   277,   156,
     157,   164,   160,   169,   157,   280,   157,   281,    12,   178,
     188,   164,     4,     3,   209,   217,   174,   157,   287,   281,
     302,     8,   246,   246,   248,     3,    85,    75,   269,   268,
      72,    81,    77,    77,    81,     8,    14,    81,     8,   223,
      77,     4,   239,   156,    84,     3,     4,     3,     5,   156,
     157,   157,   156,   189,     3,   156,   218,   157,    81,   270,
      81,     3,    81,   156,    76,     3,    76,     3,    15,   205
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
#define YYEMPTY		(-2)
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
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

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

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
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
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {
      case 4: /* T_TOKEN */
#line 153 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1558 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 154 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1563 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 155 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1568 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 156 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1573 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 157 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1578 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 158 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1583 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 159 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1588 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 160 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1593 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 161 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1598 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 162 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1603 "parser.cxx"
        break;
      case 71: /* T_HDR_UNKNOWN */
#line 163 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1608 "parser.cxx"
        break;
      case 94: /* sip_version */
#line 222 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1613 "parser.cxx"
        break;
      case 155: /* media_range */
#line 216 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_media); delete yyvaluep->yyt_media; };
#line 1618 "parser.cxx"
        break;
      case 156: /* parameters */
#line 218 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1623 "parser.cxx"
        break;
      case 157: /* parameter */
#line 217 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_param); delete yyvaluep->yyt_param; };
#line 1628 "parser.cxx"
        break;
      case 159: /* content_coding */
#line 205 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_coding); delete yyvaluep->yyt_coding; };
#line 1633 "parser.cxx"
        break;
      case 164: /* language */
#line 215 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_language); delete yyvaluep->yyt_language; };
#line 1638 "parser.cxx"
        break;
      case 167: /* alert_param */
#line 197 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_alert_param); delete yyvaluep->yyt_alert_param; };
#line 1643 "parser.cxx"
        break;
      case 174: /* call_id */
#line 199 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1648 "parser.cxx"
        break;
      case 176: /* info_param */
#line 214 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_info_param); delete yyvaluep->yyt_info_param; };
#line 1653 "parser.cxx"
        break;
      case 182: /* contacts */
#line 204 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contacts); delete yyvaluep->yyt_contacts; };
#line 1658 "parser.cxx"
        break;
      case 183: /* contact_param */
#line 203 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1663 "parser.cxx"
        break;
      case 184: /* contact_addr */
#line 202 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1668 "parser.cxx"
        break;
      case 190: /* display_name */
#line 209 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1673 "parser.cxx"
        break;
      case 207: /* error_param */
#line 210 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_error_param); delete yyvaluep->yyt_error_param; };
#line 1678 "parser.cxx"
        break;
      case 215: /* from_addr */
#line 211 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_from_addr); delete yyvaluep->yyt_from_addr; };
#line 1683 "parser.cxx"
        break;
      case 237: /* rec_route */
#line 219 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_route); delete yyvaluep->yyt_route; };
#line 1688 "parser.cxx"
        break;
      case 246: /* comment */
#line 201 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1693 "parser.cxx"
        break;
      case 251: /* server */
#line 221 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_server); delete yyvaluep->yyt_server; };
#line 1698 "parser.cxx"
        break;
      case 266: /* via_parm */
#line 223 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1703 "parser.cxx"
        break;
      case 267: /* sent_protocol */
#line 220 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1708 "parser.cxx"
        break;
      case 268: /* host */
#line 213 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1713 "parser.cxx"
        break;
      case 272: /* warning */
#line 224 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_warning); delete yyvaluep->yyt_warning; };
#line 1718 "parser.cxx"
        break;
      case 275: /* hdr_unknown */
#line 212 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1723 "parser.cxx"
        break;
      case 280: /* digest_response */
#line 208 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_resp); delete yyvaluep->yyt_dig_resp; };
#line 1728 "parser.cxx"
        break;
      case 281: /* auth_params */
#line 198 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1733 "parser.cxx"
        break;
      case 282: /* credentials */
#line 206 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_credentials); delete yyvaluep->yyt_credentials; };
#line 1738 "parser.cxx"
        break;
      case 287: /* digest_challenge */
#line 207 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_chlg); delete yyvaluep->yyt_dig_chlg; };
#line 1743 "parser.cxx"
        break;
      case 288: /* challenge */
#line 200 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_challenge); delete yyvaluep->yyt_challenge; };
#line 1748 "parser.cxx"
        break;

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

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

  if (yyss + yystacksize - 1 <= yyssp)
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
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
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

      if (yyss + yystacksize - 1 <= yyssp)
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
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
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 227 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 232 "parser.yxx"
    {
			/* KLUDGE to work around a memory leak in bison.
			 * T_NULL does never match, so the parser never
			 * gets here. The error keyword causes bison
			 * to eat all input and destroy all tokens returned
			 * by the parser.
			 * Without this workaround the following input causes
			 * the parser to leak:
			 *
			 *   INVITE INVITE ....
			 *
			 * In request_line a T_METHOD is returned as look ahead
			 * token when bison tries to match sip_version.
			 * This does not match, but the look ahead token is
			 * never destructed by Bison.
			 */
			YYABORT;
		}
    break;

  case 7:
#line 252 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 8:
#line 261 "parser.yxx"
    { CTXT_URI; }
    break;

  case 9:
#line 261 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 10:
#line 262 "parser.yxx"
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

  case 11:
#line 279 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 12:
#line 279 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 13:
#line 283 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 14:
#line 290 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 15:
#line 290 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 16:
#line 291 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 17:
#line 291 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *yyvsp[-6].yyt_str;
			((t_response *)MSG)->code = yyvsp[-4].yyt_ulong;
			((t_response *)MSG)->reason = trim(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-6].yyt_str); delete yyvsp[-6].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 71:
#line 356 "parser.yxx"
    {
			MSG->add_unknown_header(*yyvsp[-3].yyt_str, trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 72:
#line 361 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 73:
#line 363 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 74:
#line 365 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 75:
#line 367 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 76:
#line 369 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 77:
#line 371 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 78:
#line 373 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 79:
#line 375 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 80:
#line 377 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 81:
#line 379 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 82:
#line 381 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 83:
#line 383 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 84:
#line 385 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 85:
#line 387 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 86:
#line 389 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 87:
#line 391 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 88:
#line 393 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 89:
#line 395 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 90:
#line 397 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 91:
#line 399 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 92:
#line 401 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 93:
#line 403 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 94:
#line 405 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 95:
#line 407 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 96:
#line 409 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 97:
#line 411 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 98:
#line 413 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 99:
#line 415 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 100:
#line 417 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 101:
#line 419 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 102:
#line 421 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 103:
#line 423 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 104:
#line 425 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 105:
#line 427 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 106:
#line 429 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 107:
#line 431 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 108:
#line 433 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 109:
#line 435 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 110:
#line 437 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 111:
#line 439 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 112:
#line 441 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 113:
#line 443 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 114:
#line 445 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 115:
#line 447 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 116:
#line 449 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 117:
#line 451 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 118:
#line 453 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 119:
#line 455 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 120:
#line 457 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 121:
#line 459 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 122:
#line 461 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 125:
#line 477 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 130:
#line 487 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 131:
#line 489 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 133:
#line 493 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 136:
#line 499 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 137:
#line 501 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 139:
#line 505 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 140:
#line 507 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 143:
#line 513 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 144:
#line 515 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 145:
#line 517 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 146:
#line 519 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 147:
#line 521 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 149:
#line 525 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 151:
#line 529 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 152:
#line 531 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 154:
#line 535 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 155:
#line 537 "parser.yxx"
    { CTXT_URI; }
    break;

  case 156:
#line 539 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 157:
#line 541 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 158:
#line 543 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 160:
#line 547 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 161:
#line 549 "parser.yxx"
    { CTXT_URI; }
    break;

  case 162:
#line 551 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 164:
#line 555 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 167:
#line 561 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 168:
#line 563 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 172:
#line 571 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 173:
#line 573 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 175:
#line 577 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 176:
#line 582 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 177:
#line 589 "parser.yxx"
    { yyval.yyt_media = new t_media(tolower(*yyvsp[-2].yyt_str), tolower(*yyvsp[0].yyt_str));
					MEMMAN_NEW(yyval.yyt_media);
					MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
					MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 178:
#line 595 "parser.yxx"
    { yyval.yyt_params = new list<t_parameter>; MEMMAN_NEW(yyval.yyt_params); }
    break;

  case 179:
#line 596 "parser.yxx"
    {
			yyvsp[-2].yyt_params->push_back(*yyvsp[0].yyt_param);
			yyval.yyt_params = yyvsp[-2].yyt_params;
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 180:
#line 602 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 181:
#line 606 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 182:
#line 611 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 183:
#line 618 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 184:
#line 621 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 185:
#line 626 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 186:
#line 630 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[-1].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			yyval.yyt_coding->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 187:
#line 637 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name != "q") YYERROR;
			yyval.yyt_float = atof(yyvsp[0].yyt_param->value.c_str());
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
			}
    break;

  case 188:
#line 644 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 189:
#line 644 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 190:
#line 647 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 191:
#line 647 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 192:
#line 652 "parser.yxx"
    {
			CTXT_INITIAL;
		  	yyval.yyt_language = new t_language(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 193:
#line 657 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 194:
#line 657 "parser.yxx"
    {
			yyval.yyt_language = new t_language(tolower(*yyvsp[-2].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			yyval.yyt_language->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 195:
#line 664 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 196:
#line 667 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 197:
#line 672 "parser.yxx"
    { CTXT_URI; }
    break;

  case 198:
#line 672 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 199:
#line 672 "parser.yxx"
    {
		  	yyval.yyt_alert_param = new t_alert_param();
			MEMMAN_NEW(yyval.yyt_alert_param);
			yyval.yyt_alert_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_alert_param->parameter_list = *yyvsp[0].yyt_params;

			if (!yyval.yyt_alert_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_alert_param); delete yyval.yyt_alert_param;
				YYERROR;
			}
			 
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 200:
#line 687 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 201:
#line 690 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 202:
#line 695 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 203:
#line 695 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 204:
#line 695 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 205:
#line 700 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 206:
#line 701 "parser.yxx"
    {
			yyval.yyt_str = new string(*yyvsp[-2].yyt_str + '@' + *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 207:
#line 708 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 208:
#line 711 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 209:
#line 716 "parser.yxx"
    { CTXT_URI; }
    break;

  case 210:
#line 716 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 211:
#line 716 "parser.yxx"
    {
		  	yyval.yyt_info_param = new t_info_param();
			MEMMAN_NEW(yyval.yyt_info_param);
			yyval.yyt_info_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_info_param->parameter_list = *yyvsp[0].yyt_params;

			if (!yyval.yyt_info_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_info_param); delete yyval.yyt_info_param;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 212:
#line 731 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 213:
#line 731 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 214:
#line 731 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 215:
#line 733 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*yyvsp[0].yyt_contacts);
			MEMMAN_DELETE(yyvsp[0].yyt_contacts); delete yyvsp[0].yyt_contacts; }
    break;

  case 216:
#line 738 "parser.yxx"
    {
			yyval.yyt_contacts = new list<t_contact_param>;
			MEMMAN_NEW(yyval.yyt_contacts);
			yyval.yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 217:
#line 743 "parser.yxx"
    {
			yyvsp[-2].yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			yyval.yyt_contacts = yyvsp[-2].yyt_contacts;
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 218:
#line 749 "parser.yxx"
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

  case 219:
#line 765 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 220:
#line 765 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 221:
#line 765 "parser.yxx"
    {
			yyval.yyt_contact = new t_contact_param();
			MEMMAN_NEW(yyval.yyt_contact);
			yyval.yyt_contact->uri.set_url(*yyvsp[-1].yyt_str);

			if (!yyval.yyt_contact->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_contact); delete yyval.yyt_contact;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 222:
#line 776 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 223:
#line 776 "parser.yxx"
    { CTXT_URI; }
    break;

  case 224:
#line 776 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 225:
#line 776 "parser.yxx"
    {
			yyval.yyt_contact = new t_contact_param();
			MEMMAN_NEW(yyval.yyt_contact);
			yyval.yyt_contact->display = *yyvsp[-5].yyt_str;
			yyval.yyt_contact->uri.set_url(*yyvsp[-2].yyt_str);

			if (!yyval.yyt_contact->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_contact); delete yyval.yyt_contact;
				YYERROR;
			}
			 
			MEMMAN_DELETE(yyvsp[-5].yyt_str); delete yyvsp[-5].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 226:
#line 791 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 227:
#line 792 "parser.yxx"
    {
			yyval.yyt_str = new string(rtrim(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 228:
#line 796 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 229:
#line 799 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*yyvsp[-1].yyt_str));
			MSG->hdr_content_disp.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 230:
#line 806 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 231:
#line 809 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 232:
#line 814 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 233:
#line 814 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 234:
#line 817 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 235:
#line 817 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 236:
#line 822 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 237:
#line 822 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 238:
#line 822 "parser.yxx"
    {
			MSG->hdr_content_length.set_length(yyvsp[-1].yyt_ulong); }
    break;

  case 239:
#line 826 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_content_type.set_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 240:
#line 833 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 241:
#line 833 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 242:
#line 833 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr(yyvsp[-2].yyt_ulong);
			MSG->hdr_cseq.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 243:
#line 839 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 244:
#line 842 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 245:
#line 842 "parser.yxx"
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

  case 246:
#line 853 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 247:
#line 856 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 248:
#line 861 "parser.yxx"
    { CTXT_URI; }
    break;

  case 249:
#line 861 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 250:
#line 861 "parser.yxx"
    {
		  	yyval.yyt_error_param = new t_error_param();
			MEMMAN_NEW(yyval.yyt_error_param);
			yyval.yyt_error_param->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_error_param->parameter_list = *yyvsp[0].yyt_params;

			if (!yyval.yyt_error_param->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_error_param); delete yyval.yyt_error_param;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 251:
#line 876 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 252:
#line 876 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 253:
#line 876 "parser.yxx"
    {
			MSG->hdr_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 254:
#line 880 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 255:
#line 880 "parser.yxx"
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

  case 256:
#line 895 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 257:
#line 895 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_hdr_from();
			MEMMAN_NEW(yyval.yyt_from_addr);
			yyval.yyt_from_addr->set_uri(*yyvsp[-1].yyt_str);

			if (!yyval.yyt_from_addr->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_from_addr); delete yyval.yyt_from_addr;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 258:
#line 906 "parser.yxx"
    { CTXT_URI; }
    break;

  case 259:
#line 906 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 260:
#line 906 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_hdr_from();
			MEMMAN_NEW(yyval.yyt_from_addr);
			yyval.yyt_from_addr->set_display(*yyvsp[-5].yyt_str);
			yyval.yyt_from_addr->set_uri(*yyvsp[-2].yyt_str);

			if (!yyval.yyt_from_addr->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_from_addr); delete yyval.yyt_from_addr;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-5].yyt_str); delete yyvsp[-5].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 261:
#line 921 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 262:
#line 921 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 263:
#line 921 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 264:
#line 924 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 265:
#line 924 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 266:
#line 924 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 267:
#line 929 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 268:
#line 929 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 269:
#line 929 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards(yyvsp[-1].yyt_ulong); }
    break;

  case 270:
#line 933 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 271:
#line 933 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 272:
#line 933 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 273:
#line 937 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 274:
#line 942 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 275:
#line 942 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 276:
#line 942 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 277:
#line 947 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 278:
#line 952 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 279:
#line 955 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 280:
#line 960 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 281:
#line 963 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 282:
#line 968 "parser.yxx"
    { CTXT_URI; }
    break;

  case 283:
#line 968 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 284:
#line 969 "parser.yxx"
    {
			yyval.yyt_route = new t_route;
			MEMMAN_NEW(yyval.yyt_route);
			yyval.yyt_route->display = *yyvsp[-5].yyt_str;
			yyval.yyt_route->uri.set_url(*yyvsp[-3].yyt_str);
			yyval.yyt_route->set_params(*yyvsp[0].yyt_params);

			if (!yyval.yyt_route->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_route); delete yyval.yyt_route;
				YYERROR;
			}
			 
			MEMMAN_DELETE(yyvsp[-5].yyt_str); delete yyvsp[-5].yyt_str;
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 285:
#line 986 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 286:
#line 986 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_reply_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_reply_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 287:
#line 994 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 288:
#line 997 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 289:
#line 1002 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 290:
#line 1002 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 291:
#line 1002 "parser.yxx"
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

  case 292:
#line 1018 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 293:
#line 1019 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 294:
#line 1019 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 295:
#line 1019 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[-2].yyt_str; }
    break;

  case 296:
#line 1023 "parser.yxx"
    {
			MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 297:
#line 1026 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 298:
#line 1031 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 299:
#line 1034 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 300:
#line 1039 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 301:
#line 1044 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 302:
#line 1051 "parser.yxx"
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

  case 303:
#line 1062 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 304:
#line 1062 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 305:
#line 1062 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 306:
#line 1067 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 307:
#line 1069 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 308:
#line 1072 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 309:
#line 1077 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 310:
#line 1077 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 311:
#line 1080 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[0].yyt_float); }
    break;

  case 312:
#line 1082 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[-1].yyt_float);
			MSG->hdr_timestamp.set_delay(yyvsp[0].yyt_float); }
    break;

  case 313:
#line 1087 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 314:
#line 1088 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 315:
#line 1093 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 316:
#line 1094 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 317:
#line 1099 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 318:
#line 1099 "parser.yxx"
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

  case 319:
#line 1114 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 320:
#line 1117 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 321:
#line 1122 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 322:
#line 1125 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 323:
#line 1130 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 324:
#line 1133 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 325:
#line 1138 "parser.yxx"
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

  case 326:
#line 1166 "parser.yxx"
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

  case 327:
#line 1177 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 328:
#line 1182 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 329:
#line 1182 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 330:
#line 1182 "parser.yxx"
    {
			if (yyvsp[-1].yyt_ulong > 65535) YYERROR;
			
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[-4].yyt_str;
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 331:
#line 1192 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 332:
#line 1195 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 333:
#line 1200 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 334:
#line 1200 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 335:
#line 1200 "parser.yxx"
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

  case 336:
#line 1211 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 337:
#line 1211 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 338:
#line 1211 "parser.yxx"
    { yyval.yyt_str = yyvsp[-1].yyt_str; }
    break;

  case 339:
#line 1214 "parser.yxx"
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
				YYERROR;
			}

			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 342:
#line 1238 "parser.yxx"
    {
			yyval.yyt_dig_resp = new t_digest_response();
			MEMMAN_NEW(yyval.yyt_dig_resp);
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 343:
#line 1245 "parser.yxx"
    {
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 344:
#line 1252 "parser.yxx"
    {
			yyval.yyt_params = new list<t_parameter>;
			MEMMAN_NEW(yyval.yyt_params);
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 345:
#line 1257 "parser.yxx"
    {
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 346:
#line 1262 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 347:
#line 1262 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = AUTH_DIGEST;
			yyval.yyt_credentials->digest_response = *yyvsp[0].yyt_dig_resp;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_resp); delete yyvsp[0].yyt_dig_resp; }
    break;

  case 348:
#line 1268 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 349:
#line 1268 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_credentials->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 350:
#line 1277 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 351:
#line 1277 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*yyvsp[0].yyt_credentials);
			MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 352:
#line 1282 "parser.yxx"
    {
			yyval.yyt_dig_chlg = new t_digest_challenge();
			MEMMAN_NEW(yyval.yyt_dig_chlg);
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 353:
#line 1289 "parser.yxx"
    {
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 354:
#line 1296 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 355:
#line 1296 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = AUTH_DIGEST;
			yyval.yyt_challenge->digest_challenge = *yyvsp[0].yyt_dig_chlg;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_chlg); delete yyvsp[0].yyt_dig_chlg; }
    break;

  case 356:
#line 1302 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 357:
#line 1302 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_challenge->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 358:
#line 1311 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 359:
#line 1311 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 360:
#line 1316 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 361:
#line 1316 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*yyvsp[0].yyt_credentials);
				MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 362:
#line 1322 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 363:
#line 1322 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 364:
#line 1327 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 365:
#line 1327 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 366:
#line 1327 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr(yyvsp[-1].yyt_ulong); }
    break;

  case 367:
#line 1331 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 368:
#line 1331 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 369:
#line 1331 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr(yyvsp[-3].yyt_ulong);
			MSG->hdr_rack.set_cseq_nr(yyvsp[-2].yyt_ulong);
			MSG->hdr_rack.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 370:
#line 1338 "parser.yxx"
    {
			MSG->hdr_event.set_event_type(tolower(*yyvsp[-1].yyt_str));
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "id") {
					MSG->hdr_event.set_id(i->value);
				} else {
					MSG->hdr_event.add_event_param(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 371:
#line 1352 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 372:
#line 1355 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 373:
#line 1360 "parser.yxx"
    {
				MSG->hdr_subscription_state.set_substate(tolower(*yyvsp[-1].yyt_str));
				list<t_parameter>::const_iterator i;
				for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
					if (i->name == "reason") {
						MSG->hdr_subscription_state.
							set_reason(tolower(i->value));
					} else if (i->name == "expires") {
						MSG->hdr_subscription_state.
							set_expires(strtoul(
							  i->value.c_str(),
							  NULL, 10));
					} else if (i->name == "retry_after") {
						MSG->hdr_subscription_state.
							set_retry_after(strtoul(
							  i->value.c_str(),
							  NULL, 10));
					} else {
						MSG->hdr_subscription_state.
							add_extension(*i);
					}
				}
				MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
				MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 374:
#line 1386 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 375:
#line 1386 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_refer_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_refer_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 376:
#line 1394 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 377:
#line 1394 "parser.yxx"
    {
			MSG->hdr_referred_by.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_referred_by.set_uri(yyvsp[-1].yyt_from_addr->uri);
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "cid") {
					MSG->hdr_referred_by.set_cid(i->value);
				} else {
					MSG->hdr_referred_by.add_param(*i);
				}
			}
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;


    }

/* Line 991 of yacc.c.  */
#line 4111 "parser.cxx"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

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
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
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
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



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
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__) \
    && !defined __cplusplus
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
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


#line 1409 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

