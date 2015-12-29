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
     T_ERROR = 328
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
#line 265 "parser.cxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 277 "parser.cxx"

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
#define YYLAST   651

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  224
/* YYNRULES -- Number of rules. */
#define YYNRULES  376
/* YYNRULES -- Number of states. */
#define YYNSTATES  688

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      82,    83,     2,     2,    76,     2,    84,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    75,    77,
      79,    78,    80,     2,    81,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
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
     213,   217,   221,   225,   229,   233,   237,   241,   245,   249,
     253,   258,   262,   266,   270,   274,   278,   282,   286,   290,
     294,   298,   302,   306,   310,   314,   318,   322,   326,   330,
     334,   338,   342,   346,   350,   354,   358,   362,   366,   370,
     374,   378,   382,   386,   390,   394,   398,   402,   406,   410,
     414,   418,   422,   426,   430,   434,   438,   442,   446,   450,
     454,   458,   462,   465,   468,   471,   474,   477,   480,   483,
     486,   489,   492,   495,   498,   501,   504,   507,   510,   513,
     516,   519,   522,   525,   528,   531,   534,   537,   540,   543,
     546,   549,   552,   555,   558,   561,   564,   567,   570,   573,
     576,   579,   582,   585,   588,   591,   594,   597,   600,   603,
     606,   609,   612,   615,   616,   619,   624,   628,   629,   633,
     635,   639,   643,   645,   649,   651,   654,   657,   658,   661,
     662,   667,   669,   670,   674,   676,   680,   681,   682,   689,
     691,   695,   696,   697,   701,   703,   707,   709,   713,   714,
     715,   722,   723,   724,   728,   730,   732,   736,   739,   740,
     741,   745,   746,   747,   748,   756,   757,   759,   761,   764,
     766,   770,   771,   774,   775,   780,   781,   782,   786,   789,
     790,   791,   796,   797,   798,   812,   814,   818,   819,   820,
     827,   828,   829,   833,   834,   838,   839,   842,   843,   844,
     851,   852,   853,   857,   858,   859,   865,   866,   867,   871,
     872,   873,   877,   879,   880,   881,   885,   887,   889,   893,
     895,   899,   900,   901,   909,   910,   914,   916,   920,   921,
     922,   928,   929,   930,   931,   937,   939,   943,   945,   948,
     950,   953,   958,   959,   960,   964,   965,   967,   971,   972,
     975,   977,   980,   982,   986,   988,   992,   993,   997,   999,
    1003,  1005,  1008,  1010,  1014,  1018,  1024,  1026,  1027,  1028,
    1034,  1036,  1040,  1041,  1042,  1048,  1049,  1050,  1054,  1056,
    1058,  1062,  1064,  1068,  1070,  1074,  1075,  1079,  1080,  1084,
    1085,  1088,  1090,  1094,  1095,  1099,  1100,  1104,  1105,  1108,
    1109,  1112,  1113,  1116,  1117,  1118,  1122,  1123,  1124,  1130,
    1133,  1135,  1139,  1142,  1143,  1147,  1148
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      86,     0,    -1,    -1,    87,    88,    -1,    89,    -1,    95,
      -1,    90,   100,    72,    -1,    -1,    -1,    17,    91,     8,
      92,    93,    72,    -1,    -1,    16,    94,    74,     4,    -1,
      96,   100,    72,    -1,    -1,    -1,    -1,    93,    97,     3,
      98,     7,    99,    72,    -1,    -1,   100,   101,    -1,   102,
     153,    72,    -1,   103,   157,    72,    -1,   104,   160,    72,
      -1,   105,   165,    72,    -1,   106,   169,    72,    -1,   107,
     303,    72,    -1,   108,   278,    72,    -1,   109,   284,    72,
      -1,   110,   170,    72,    -1,   111,   174,    72,    -1,   112,
     178,    72,    -1,   113,   190,    72,    -1,   114,   191,    72,
      -1,   115,   192,    72,    -1,   116,   195,    72,    -1,   117,
     198,    72,    -1,   118,   199,    72,    -1,   119,   202,    72,
      -1,   121,   302,    72,    -1,   120,   205,    72,    -1,   122,
     209,    72,    -1,   123,   212,    72,    -1,   124,   218,    72,
      -1,   125,   223,    72,    -1,   126,   226,    72,    -1,   127,
     229,    72,    -1,   128,   230,    72,    -1,   129,   233,    72,
      -1,   130,   290,    72,    -1,   131,   292,    72,    -1,   132,
     234,    72,    -1,   133,   299,    72,    -1,   134,   235,    72,
      -1,   135,   305,    72,    -1,   136,   307,    72,    -1,   137,
     239,    72,    -1,   138,   241,    72,    -1,   139,   242,    72,
      -1,   140,   248,    72,    -1,   141,   296,    72,    -1,   142,
     249,    72,    -1,   143,   251,    72,    -1,   144,   304,    72,
      -1,   145,   254,    72,    -1,   146,   255,    72,    -1,   147,
     260,    72,    -1,   148,   262,    72,    -1,   149,   263,    72,
      -1,   150,   264,    72,    -1,   151,   270,    72,    -1,   152,
     294,    72,    -1,    71,    75,   274,    72,    -1,   102,     1,
      72,    -1,   103,     1,    72,    -1,   104,     1,    72,    -1,
     105,     1,    72,    -1,   106,     1,    72,    -1,   107,     1,
      72,    -1,   108,     1,    72,    -1,   109,     1,    72,    -1,
     110,     1,    72,    -1,   111,     1,    72,    -1,   112,     1,
      72,    -1,   113,     1,    72,    -1,   114,     1,    72,    -1,
     115,     1,    72,    -1,   116,     1,    72,    -1,   117,     1,
      72,    -1,   118,     1,    72,    -1,   119,     1,    72,    -1,
     120,     1,    72,    -1,   121,     1,    72,    -1,   122,     1,
      72,    -1,   123,     1,    72,    -1,   124,     1,    72,    -1,
     125,     1,    72,    -1,   126,     1,    72,    -1,   127,     1,
      72,    -1,   128,     1,    72,    -1,   129,     1,    72,    -1,
     130,     1,    72,    -1,   131,     1,    72,    -1,   132,     1,
      72,    -1,   133,     1,    72,    -1,   134,     1,    72,    -1,
     135,     1,    72,    -1,   136,     1,    72,    -1,   137,     1,
      72,    -1,   138,     1,    72,    -1,   139,     1,    72,    -1,
     140,     1,    72,    -1,   141,     1,    72,    -1,   142,     1,
      72,    -1,   143,     1,    72,    -1,   144,     1,    72,    -1,
     145,     1,    72,    -1,   146,     1,    72,    -1,   147,     1,
      72,    -1,   148,     1,    72,    -1,   149,     1,    72,    -1,
     150,     1,    72,    -1,   151,     1,    72,    -1,   152,     1,
      72,    -1,    20,    75,    -1,    21,    75,    -1,    22,    75,
      -1,    23,    75,    -1,    24,    75,    -1,    25,    75,    -1,
      26,    75,    -1,    27,    75,    -1,    28,    75,    -1,    29,
      75,    -1,    30,    75,    -1,    31,    75,    -1,    32,    75,
      -1,    33,    75,    -1,    34,    75,    -1,    35,    75,    -1,
      36,    75,    -1,    37,    75,    -1,    38,    75,    -1,    39,
      75,    -1,    40,    75,    -1,    41,    75,    -1,    42,    75,
      -1,    43,    75,    -1,    44,    75,    -1,    45,    75,    -1,
      46,    75,    -1,    47,    75,    -1,    48,    75,    -1,    49,
      75,    -1,    50,    75,    -1,    51,    75,    -1,    52,    75,
      -1,    53,    75,    -1,    54,    75,    -1,    55,    75,    -1,
      56,    75,    -1,    57,    75,    -1,    58,    75,    -1,    59,
      75,    -1,    60,    75,    -1,    61,    75,    -1,    62,    75,
      -1,    63,    75,    -1,    64,    75,    -1,    65,    75,    -1,
      66,    75,    -1,    67,    75,    -1,    68,    75,    -1,    69,
      75,    -1,    70,    75,    -1,    -1,   154,   155,    -1,   153,
      76,   154,   155,    -1,     4,    74,     4,    -1,    -1,   155,
      77,   156,    -1,     4,    -1,     4,    78,     4,    -1,     4,
      78,     5,    -1,   158,    -1,   157,    76,   158,    -1,     4,
      -1,     4,   159,    -1,    77,   156,    -1,    -1,   161,   163,
      -1,    -1,   160,    76,   162,   163,    -1,    11,    -1,    -1,
      11,   164,   159,    -1,   166,    -1,   165,    76,   166,    -1,
      -1,    -1,    79,   167,     8,   168,    80,   155,    -1,     4,
      -1,   169,    76,     4,    -1,    -1,    -1,   171,   173,   172,
      -1,    12,    -1,    12,    81,    12,    -1,   175,    -1,   174,
      76,   175,    -1,    -1,    -1,    79,   176,     8,   177,    80,
     155,    -1,    -1,    -1,   179,     9,   180,    -1,   181,    -1,
     182,    -1,   181,    76,   182,    -1,   183,   155,    -1,    -1,
      -1,   184,     8,   185,    -1,    -1,    -1,    -1,   186,   189,
      79,   187,     8,   188,    80,    -1,    -1,    10,    -1,     5,
      -1,     4,   155,    -1,   158,    -1,   191,    76,   158,    -1,
      -1,   193,   163,    -1,    -1,   192,    76,   194,   163,    -1,
      -1,    -1,   196,     3,   197,    -1,   154,   155,    -1,    -1,
      -1,   200,     3,   201,     4,    -1,    -1,    -1,   203,    13,
      76,     3,    14,     3,     3,    75,     3,    75,     3,    15,
     204,    -1,   206,    -1,   205,    76,   206,    -1,    -1,    -1,
      79,   207,     8,   208,    80,   155,    -1,    -1,    -1,   210,
       3,   211,    -1,    -1,   213,   214,   155,    -1,    -1,     8,
     215,    -1,    -1,    -1,   189,    79,   216,     8,   217,    80,
      -1,    -1,    -1,   219,   173,   220,    -1,    -1,    -1,   218,
      76,   221,   173,   222,    -1,    -1,    -1,   224,     3,   225,
      -1,    -1,    -1,   227,     3,   228,    -1,     4,    -1,    -1,
      -1,   231,     7,   232,    -1,     4,    -1,     4,    -1,   234,
      76,     4,    -1,   236,    -1,   235,    76,   236,    -1,    -1,
      -1,   237,   189,    79,     8,   238,    80,   155,    -1,    -1,
     240,   214,   155,    -1,     4,    -1,   234,    76,     4,    -1,
      -1,    -1,   243,     3,   244,   245,   155,    -1,    -1,    -1,
      -1,    82,   246,     6,   247,    83,    -1,   236,    -1,   248,
      76,   236,    -1,   250,    -1,   249,   250,    -1,   245,    -1,
       4,   245,    -1,     4,    74,     4,   245,    -1,    -1,    -1,
     252,     7,   253,    -1,    -1,     4,    -1,   254,    76,     4,
      -1,    -1,   256,   257,    -1,   258,    -1,   258,   259,    -1,
       3,    -1,     3,    84,     3,    -1,     3,    -1,     3,    84,
       3,    -1,    -1,   261,   214,   155,    -1,     4,    -1,   262,
      76,     4,    -1,   250,    -1,   263,   250,    -1,   265,    -1,
     264,    76,   265,    -1,   266,   267,   155,    -1,     4,    74,
       4,    74,     4,    -1,     4,    -1,    -1,    -1,     4,    75,
     268,     3,   269,    -1,   271,    -1,   270,    76,   271,    -1,
      -1,    -1,   272,     3,   273,   267,     5,    -1,    -1,    -1,
     275,     7,   276,    -1,   156,    -1,   277,    -1,   278,    76,
     277,    -1,   156,    -1,   279,    76,   156,    -1,   156,    -1,
     280,    76,   156,    -1,    -1,    18,   282,   279,    -1,    -1,
      19,   283,   280,    -1,    -1,   285,   281,    -1,   156,    -1,
     286,    76,   156,    -1,    -1,    18,   288,   286,    -1,    -1,
      19,   289,   280,    -1,    -1,   291,   287,    -1,    -1,   293,
     281,    -1,    -1,   295,   287,    -1,    -1,    -1,   297,     3,
     298,    -1,    -1,    -1,   300,     3,     3,   301,     4,    -1,
       4,   155,    -1,     4,    -1,   303,    76,     4,    -1,     4,
     155,    -1,    -1,   306,   214,   155,    -1,    -1,   308,   214,
     155,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   224,   224,   224,   227,   228,   231,   240,   240,   240,
     258,   258,   262,   269,   269,   270,   269,   280,   281,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   363,   365,   367,   369,   371,   373,   375,
     377,   379,   381,   383,   385,   387,   389,   391,   393,   395,
     397,   399,   401,   403,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   427,   429,   431,   433,   435,
     437,   439,   452,   454,   456,   458,   460,   462,   464,   466,
     468,   470,   472,   474,   476,   478,   480,   482,   484,   486,
     488,   490,   492,   494,   496,   498,   500,   502,   504,   506,
     508,   510,   512,   514,   516,   518,   520,   522,   524,   526,
     528,   530,   532,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   555,   556,   561,   568,   574,   575,   581,
     585,   590,   597,   600,   605,   609,   616,   623,   623,   626,
     626,   631,   636,   636,   643,   646,   651,   651,   651,   666,
     669,   674,   674,   674,   679,   680,   687,   690,   695,   695,
     695,   710,   710,   710,   712,   717,   722,   728,   744,   744,
     744,   755,   755,   755,   755,   770,   771,   775,   778,   785,
     788,   793,   793,   796,   796,   801,   801,   801,   805,   812,
     812,   812,   818,   821,   818,   832,   835,   840,   840,   840,
     855,   855,   855,   859,   859,   874,   874,   885,   885,   885,
     900,   900,   900,   903,   903,   903,   908,   908,   908,   912,
     912,   912,   916,   921,   921,   921,   926,   931,   934,   939,
     942,   947,   947,   947,   965,   965,   973,   976,   981,   981,
     981,   997,   998,   998,   998,  1002,  1005,  1010,  1013,  1018,
    1023,  1030,  1041,  1041,  1041,  1046,  1048,  1051,  1056,  1056,
    1059,  1061,  1066,  1067,  1072,  1073,  1078,  1078,  1093,  1096,
    1101,  1104,  1109,  1112,  1117,  1145,  1156,  1161,  1161,  1161,
    1171,  1174,  1179,  1179,  1179,  1190,  1190,  1190,  1193,  1213,
    1214,  1217,  1224,  1231,  1236,  1241,  1241,  1247,  1247,  1256,
    1256,  1261,  1268,  1275,  1275,  1281,  1281,  1290,  1290,  1295,
    1295,  1301,  1301,  1306,  1306,  1306,  1310,  1310,  1310,  1317,
    1331,  1334,  1339,  1365,  1365,  1373,  1373
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
  "T_ERROR", "'/'", "':'", "','", "';'", "'='", "'<'", "'>'", "'@'", 
  "'('", "')'", "'.'", "$accept", "sip_message", "@1", "sip_message2", 
  "request", "request_line", "@2", "@3", "sip_version", "@4", "response", 
  "status_line", "@5", "@6", "@7", "headers", "header", "hd_accept", 
  "hd_accept_encoding", "hd_accept_language", "hd_alert_info", "hd_allow", 
  "hd_allow_events", "hd_authentication_info", "hd_authorization", 
  "hd_call_id", "hd_call_info", "hd_contact", "hd_content_disp", 
  "hd_content_encoding", "hd_content_language", "hd_content_length", 
  "hd_content_type", "hd_cseq", "hd_date", "hd_error_info", "hd_event", 
  "hd_expires", "hd_from", "hd_in_reply_to", "hd_max_forwards", 
  "hd_min_expires", "hd_mime_version", "hd_organization", "hd_priority", 
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
     325,   326,   327,   328,    47,    58,    44,    59,    61,    60,
      62,    64,    40,    41,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,    85,    87,    86,    88,    88,    89,    91,    92,    90,
      94,    93,    95,    97,    98,    99,    96,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   153,   153,   154,   155,   155,   156,
     156,   156,   157,   157,   158,   158,   159,   161,   160,   162,
     160,   163,   164,   163,   165,   165,   167,   168,   166,   169,
     169,   171,   172,   170,   173,   173,   174,   174,   176,   177,
     175,   179,   180,   178,   178,   181,   181,   182,   184,   185,
     183,   186,   187,   188,   183,   189,   189,   189,   190,   191,
     191,   193,   192,   194,   192,   196,   197,   195,   198,   200,
     201,   199,   203,   204,   202,   205,   205,   207,   208,   206,
     210,   211,   209,   213,   212,   215,   214,   216,   217,   214,
     219,   220,   218,   221,   222,   218,   224,   225,   223,   227,
     228,   226,   229,   231,   232,   230,   233,   234,   234,   235,
     235,   237,   238,   236,   240,   239,   241,   241,   243,   244,
     242,   245,   246,   247,   245,   248,   248,   249,   249,   250,
     250,   250,   252,   253,   251,   254,   254,   254,   256,   255,
     257,   257,   258,   258,   259,   259,   261,   260,   262,   262,
     263,   263,   264,   264,   265,   266,   267,   268,   269,   267,
     270,   270,   272,   273,   271,   275,   276,   274,   277,   278,
     278,   279,   279,   280,   280,   282,   281,   283,   281,   285,
     284,   286,   286,   288,   287,   289,   287,   291,   290,   293,
     292,   295,   294,   297,   298,   296,   300,   301,   299,   302,
     303,   303,   304,   306,   305,   308,   307
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     2,     4,     3,     0,     3,     1,
       3,     3,     1,     3,     1,     2,     2,     0,     2,     0,
       4,     1,     0,     3,     1,     3,     0,     0,     6,     1,
       3,     0,     0,     3,     1,     3,     1,     3,     0,     0,
       6,     0,     0,     3,     1,     1,     3,     2,     0,     0,
       3,     0,     0,     0,     7,     0,     1,     1,     2,     1,
       3,     0,     2,     0,     4,     0,     0,     3,     2,     0,
       0,     4,     0,     0,    13,     1,     3,     0,     0,     6,
       0,     0,     3,     0,     3,     0,     2,     0,     0,     6,
       0,     0,     3,     0,     0,     5,     0,     0,     3,     0,
       0,     3,     1,     0,     0,     3,     1,     1,     3,     1,
       3,     0,     0,     7,     0,     3,     1,     3,     0,     0,
       5,     0,     0,     0,     5,     1,     3,     1,     2,     1,
       2,     4,     0,     0,     3,     0,     1,     3,     0,     2,
       1,     2,     1,     3,     1,     3,     0,     3,     1,     3,
       1,     2,     1,     3,     3,     5,     1,     0,     0,     5,
       1,     3,     0,     0,     5,     0,     0,     3,     1,     1,
       3,     1,     3,     1,     3,     0,     3,     0,     3,     0,
       2,     1,     3,     0,     3,     0,     3,     0,     2,     0,
       2,     0,     2,     0,     0,     3,     0,     0,     5,     2,
       1,     3,     2,     0,     3,     0,     3
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    12,    11,     0,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   335,
       0,     0,     0,   177,     0,   184,     0,   182,     0,     0,
       0,     0,   196,     0,   194,     0,   199,     0,     0,   370,
       0,     0,   179,   338,   339,     0,     0,     0,     0,     0,
       0,     0,     0,   208,     0,   206,     0,     0,     0,   214,
     215,   177,     0,   225,     0,   177,     0,     0,   229,     0,
       0,     0,     0,     0,     0,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,   245,     0,
     177,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,     0,     0,
     279,   225,     0,     0,   225,     0,     0,   225,     0,     0,
     225,     0,   277,     0,     0,     0,     0,     0,     0,   295,
       0,     0,     0,     0,     0,   291,   292,   299,     0,   297,
       0,     0,     0,     0,   177,     0,     0,   306,     0,     0,
       0,     0,     0,     0,   225,     0,   318,     0,     0,   320,
       0,     0,     0,     0,   322,     0,     0,     0,   330,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,    19,
       0,   174,    72,     0,   185,    20,     0,    73,    21,   189,
     191,   188,    74,     0,    22,     0,    75,    23,     0,    76,
      24,     0,    77,     0,    25,     0,    78,    26,   345,   347,
     350,    79,    27,   204,   202,    80,     0,    28,     0,    81,
      29,   212,   221,   217,   219,   227,   226,     0,    82,   228,
      30,    83,    31,     0,    84,    32,   233,   232,    85,    33,
     236,    86,   238,    34,    87,    35,   240,    88,    36,     0,
      89,     0,    38,     0,    90,   369,    37,    91,    39,   251,
      92,    40,   255,     0,   177,    93,    41,   263,   261,    94,
      42,   267,    95,    43,   270,    96,    44,    97,    45,   274,
      98,    46,    99,    47,   353,   355,   358,   100,    48,   360,
     101,    49,     0,   102,    50,     0,   103,    51,   281,     0,
     104,    52,   177,   105,    53,   177,   106,    54,   177,   107,
       0,    55,   108,    56,   289,   109,    57,   281,   110,    58,
     364,   111,     0,   300,     0,    59,   298,   112,    60,   303,
     113,   372,    61,   114,    62,     0,   115,    63,   312,   309,
     310,   116,    64,   177,   117,    65,     0,   118,    66,   321,
     119,     0,    67,     0,   326,   177,   120,    68,   332,   333,
     121,    69,   362,    15,     9,    70,   336,   176,   177,     0,
     186,   183,     0,     0,   197,   195,   200,   371,   180,   181,
     340,     0,     0,     0,   203,   209,   207,   213,   216,   220,
     222,   230,     0,   237,     0,     0,   248,   246,   252,   256,
     257,   254,     0,   262,   268,   271,   275,     0,     0,   278,
     367,   280,     0,   374,   376,   285,   278,   291,   296,   365,
     291,   293,   304,   307,     0,   314,   311,   317,   319,     0,
     323,   327,   324,   331,     0,     0,   337,   175,   178,   190,
     193,     0,   341,   346,   343,   348,   205,     0,     0,   234,
     241,     0,     0,     0,   264,   351,   354,   356,     0,   282,
     177,   301,     0,   313,     0,     0,     0,     0,    16,   177,
       0,     0,   177,   223,     0,   177,   258,   265,     0,   368,
       0,   290,   294,   315,   325,   328,   334,   198,   342,   344,
     210,     0,     0,   249,     0,   352,   177,   329,   224,     0,
     259,   283,     0,     0,     0,     0,   243,   244
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    13,   127,     9,    12,
      10,    11,    15,   353,   615,    14,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   182,   183,
     361,   203,   186,   187,   364,   189,   190,   552,   371,   553,
     193,   194,   373,   621,   197,   210,   211,   564,   394,   214,
     215,   396,   627,   217,   218,   567,   219,   220,   221,   222,
     569,   223,   628,   671,   443,   226,   229,   231,   232,   572,
     234,   235,   573,   238,   240,   241,   574,   243,   244,   687,
     247,   248,   431,   632,   253,   254,   578,   256,   257,   444,
     579,   633,   674,   259,   260,   583,   582,   657,   262,   263,
     584,   265,   266,   585,   269,   271,   272,   586,   275,   284,
     289,   290,   291,   660,   299,   300,   304,   306,   307,   597,
     317,   504,   642,   310,   318,   319,   321,   322,   602,   328,
     330,   331,   519,   520,   606,   333,   334,   337,   340,   343,
     344,   345,   535,   646,   677,   347,   348,   349,   614,   355,
     356,   616,   204,   205,   623,   625,   390,   561,   562,   207,
     208,   636,   466,   587,   588,   277,   278,   280,   281,   351,
     352,   312,   313,   599,   286,   287,   638,   251,   200,   325,
     293,   294,   296,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -359
static const short yypact[] =
{
    -359,    50,    72,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,    -5,    94,   112,   111,   436,   221,  -359,   159,
     183,   202,   207,   214,   215,   222,   224,   226,   228,   229,
     230,   231,   232,   233,   235,   236,   237,   241,   242,   243,
     248,   249,   254,   255,   257,   259,   260,   261,   263,   265,
     266,   270,   271,   274,   275,   276,   278,   279,   281,   282,
     283,   286,   287,   288,   289,   290,   292,   294,   295,   296,
     297,  -359,  -359,    34,   125,    86,    17,   234,   238,   239,
      54,    62,    19,    14,   240,   244,   107,   127,   245,   223,
      58,    25,   246,   268,    20,    67,   269,   272,   250,   106,
     251,    57,    59,   252,   273,    46,    26,    32,    38,   256,
     277,    52,   280,     9,   108,   258,    40,   284,    44,   262,
      10,   264,   285,    65,  -359,  -359,  -359,   293,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
      55,   247,   113,  -359,   253,   267,   116,  -359,   301,   118,
     302,   303,  -359,   121,  -359,   304,  -359,   123,   305,  -359,
     124,   306,   220,  -359,  -359,   126,   307,   308,   102,   309,
     310,   314,   311,  -359,   129,  -359,   312,   313,   324,   298,
    -359,  -359,   329,    60,   316,  -359,   317,   318,  -359,   135,
     319,   136,   302,   320,   321,   336,   322,  -359,   323,   325,
     326,   340,   327,   328,   334,   330,  -359,   137,  -359,   331,
    -359,   332,   333,   335,   345,   337,   338,   114,   339,   138,
     314,   341,   342,   349,   343,   344,   352,   346,  -359,   348,
     350,   351,   353,   354,  -359,   355,   357,   358,   168,   360,
     361,   102,   363,  -359,   143,   364,   365,   356,   366,   144,
    -359,    60,   367,   368,   114,   369,   370,   114,   371,   372,
     114,   373,   374,   375,   376,   377,   378,   383,   380,  -359,
     145,   381,   382,   393,   437,    12,  -359,  -359,     8,  -359,
     438,   439,   359,   440,  -359,   441,   442,  -359,   146,   443,
     444,   398,   445,   446,   114,   447,  -359,   155,   448,  -359,
      13,   449,   347,   160,  -359,   315,   450,   161,  -359,   403,
     451,   452,   168,   401,   453,   454,   405,  -359,   413,  -359,
     420,   455,  -359,   421,  -359,  -359,   523,  -359,  -359,  -359,
     456,  -359,  -359,   520,  -359,   457,  -359,  -359,   525,  -359,
    -359,   526,  -359,   291,  -359,   421,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,   458,  -359,  -359,   527,  -359,   459,  -359,
    -359,  -359,   529,   455,  -359,  -359,  -359,   461,  -359,   455,
    -359,  -359,  -359,   523,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,   455,  -359,  -359,  -359,  -359,  -359,  -359,   465,
    -359,   534,  -359,   464,  -359,   455,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,   466,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,   530,  -359,  -359,   528,  -359,  -359,  -359,   467,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
     540,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,   543,  -359,   542,  -359,  -359,  -359,  -359,  -359,
    -359,   455,  -359,  -359,  -359,   545,  -359,  -359,   468,  -359,
     547,  -359,  -359,  -359,  -359,  -359,   549,  -359,  -359,  -359,
    -359,   550,  -359,   551,   476,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,   421,
    -359,  -359,   302,   267,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   421,   421,   435,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,   302,  -359,   552,   554,  -359,  -359,  -359,  -359,
    -359,   455,   314,  -359,  -359,  -359,  -359,   421,   421,  -359,
    -359,  -359,   553,   455,   455,   455,   486,   477,  -359,  -359,
     477,  -359,  -359,  -359,   557,   478,  -359,   455,  -359,   489,
    -359,  -359,   455,  -359,   315,   492,  -359,   455,  -359,  -359,
    -359,   485,  -359,   490,  -359,   491,  -359,   488,   561,  -359,
    -359,   556,   493,   563,  -359,  -359,   496,   491,   570,  -359,
    -359,  -359,   494,  -359,   572,   574,   573,   575,  -359,  -359,
     421,   421,  -359,  -359,   576,  -359,  -359,  -359,   421,  -359,
     501,   455,  -359,  -359,  -359,  -359,  -359,   455,  -359,  -359,
     455,   502,   580,   455,   504,  -359,  -359,  -359,  -359,   510,
    -359,   455,   583,   512,   585,   300,  -359,  -359
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,   193,  -359,
    -359,  -359,  -359,  -359,  -359,   578,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,   -81,
    -221,  -358,  -359,   -82,    37,  -359,  -359,  -359,  -230,  -359,
    -359,   216,  -359,  -359,  -359,  -359,  -359,  -359,  -254,  -359,
     194,  -359,  -359,  -359,  -359,  -359,  -359,   191,  -359,  -359,
    -359,  -359,  -359,  -359,  -191,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,   162,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -233,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,   487,
    -359,  -110,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -306,  -359,  -359,  -359,  -359,  -112,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
      61,  -359,   -17,  -359,  -359,  -359,    63,  -359,  -359,  -359,
    -359,  -359,   213,  -359,  -359,    11,   362,  -359,  -359,  -359,
    -359,  -359,   299,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,  -359,
    -359,  -359,  -359,  -359
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -376
static const short yytable[] =
{
     403,   309,   417,   228,   409,   550,   448,   237,   339,   503,
     314,   338,   315,   315,   315,   216,   422,   315,   191,  -221,
     212,   255,  -218,  -211,  -221,  -253,   245,   292,  -253,   435,
    -253,  -373,   407,   295,  -373,   180,  -373,  -375,   181,   298,
    -375,   326,  -375,  -284,   327,   332,  -284,   288,  -284,  -316,
       3,  -281,  -316,   308,  -316,   206,  -281,  -281,   276,   242,
     279,   482,  -281,   209,   485,   405,   350,   488,   258,    17,
     406,  -242,  -349,  -349,  -201,  -357,  -357,  -359,  -359,  -260,
     505,  -291,  -291,  -361,  -361,   528,   502,   188,     4,     5,
     316,   316,   316,  -221,   316,   316,   192,  -187,   213,  -253,
     479,   523,    18,   511,   246,  -373,  -173,   270,   230,   320,
    -173,  -375,  -305,  -273,   124,  -302,  -305,  -284,  -231,   405,
     388,   389,   442,  -316,   406,  -281,   184,   357,   233,   185,
    -235,  -281,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,   359,   464,   465,   365,   360,
     368,   618,   366,   374,   369,   377,   380,   375,   384,   378,
     381,   397,   385,   622,   624,   398,   506,   412,   415,   432,
     446,   413,   416,   433,   447,   471,   477,   496,   514,   472,
     478,   497,   515,   581,   239,   126,  -239,   525,   529,   635,
     624,   526,   532,   537,   128,   195,   533,   538,   196,   198,
     201,   224,   199,   202,   225,   227,   236,   249,   185,   181,
     250,   267,   273,   282,   268,   274,   283,   301,   129,   323,
     302,   593,   324,   335,   594,   341,   336,   595,   342,   252,
     261,  -250,  -266,   264,   285,  -269,  -366,   130,   305,   548,
    -288,   311,   131,  -363,   551,   329,   346,  -308,  -332,   132,
     133,   640,   668,   669,   641,   558,   559,   134,   383,   135,
     675,   136,   607,   137,   138,   139,   140,   141,   142,     4,
     143,   144,   145,   370,   612,   686,   146,   147,   148,   534,
     354,   358,   619,   149,   150,   362,   393,   617,   634,   151,
     152,   571,   153,   401,   154,   155,   156,   404,   157,   420,
     158,   159,   629,   426,   363,   160,   161,   429,   439,   162,
     163,   164,   451,   165,   166,   454,   167,   168,   169,   475,
     459,   170,   171,   172,   173,   174,   509,   175,   591,   176,
     177,   178,   179,   367,   402,   372,   376,   379,   382,   386,
     387,   391,   392,   395,   399,   400,   494,   598,   408,   410,
     411,   414,   418,   419,   421,   423,   500,   424,   425,   427,
     428,   518,   430,   434,   436,   437,   539,   438,   543,   440,
     441,   445,   546,   449,   450,   452,   453,   547,   455,   661,
     456,   531,   457,   458,   181,   202,   460,   461,   667,   462,
     463,   670,   467,   468,   673,   470,   473,   474,   476,   480,
     481,   483,   484,   486,   487,   489,  -286,   626,   491,   492,
     493,   490,   495,   498,   499,   681,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,   125,   501,
     507,   508,   510,   512,   513,   516,   517,   521,   522,   524,
     527,   530,   536,   540,   541,   544,   545,   185,   554,   556,
     557,   590,   549,  -192,   589,   565,   192,  -218,   213,   563,
     570,   575,   576,   246,   596,   580,   592,   600,   601,   603,
     605,   611,   604,   608,   609,   342,   630,   631,  -287,   316,
     643,   639,   644,   645,   648,   649,   650,   651,   652,   653,
     654,   656,   658,   655,   659,   663,   665,   662,   664,   672,
     666,   676,   678,   679,   680,   682,   683,   684,   685,    16,
     620,   555,   566,   568,   610,   577,   303,   647,   560,   637,
       0,   613,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,     0,     0,     0,
       0,   542
};

static const short yycheck[] =
{
     221,   111,   232,    85,   225,   363,   260,    88,   120,   315,
       1,     1,     4,     4,     4,     1,   237,     4,     1,     5,
       1,     1,     8,     9,    10,     5,     1,     1,     8,   250,
      10,     5,   223,     1,     8,     1,    10,     5,     4,     1,
       8,     1,    10,     5,     4,     1,     8,     1,    10,     5,
       0,     5,     8,     1,    10,     1,    10,     5,     1,     1,
       1,   294,    10,     1,   297,     5,     1,   300,     1,    74,
      10,    13,    18,    19,    12,    18,    19,    18,    19,    12,
      72,    72,    72,    18,    19,    72,    74,     1,    16,    17,
      82,    82,    82,    79,    82,    82,    79,    11,    79,    79,
     291,   334,     8,   324,    79,    79,    72,     1,     1,     1,
      76,    79,    72,     7,     3,     7,    76,    79,    11,     5,
      18,    19,     8,    79,    10,    79,     1,    72,     1,     4,
       3,    79,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    72,    18,    19,    72,    76,
      72,   549,    76,    72,    76,    72,    72,    76,    72,    76,
      76,    72,    76,   561,   562,    76,   318,    72,    72,    72,
      72,    76,    76,    76,    76,    72,    72,    72,    72,    76,
      76,    76,    76,   444,     1,     4,     3,    72,   340,   587,
     588,    76,    72,    72,    75,     1,    76,    76,     4,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     4,     4,
       4,     1,     1,     1,     4,     4,     4,     1,    75,     1,
       4,   482,     4,     1,   485,     1,     4,   488,     4,     1,
       1,     3,     3,     1,     1,     3,     3,    75,     1,   360,
       3,     1,    75,     3,   366,     1,     1,     3,     3,    75,
      75,   597,   650,   651,   600,     4,     5,    75,    78,    75,
     658,    75,   523,    75,    75,    75,    75,    75,    75,    16,
      75,    75,    75,    11,   535,    15,    75,    75,    75,     4,
     127,    74,   552,    75,    75,    72,    12,   548,   582,    75,
      75,   413,    75,     9,    75,    75,    75,     8,    75,     3,
      75,    75,   572,     3,    77,    75,    75,    13,     3,    75,
      75,    75,     3,    75,    75,     3,    75,    75,    75,     3,
       7,    75,    75,    75,    75,    75,     7,    75,   478,    75,
      75,    75,    75,    72,    76,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,     3,   497,    72,    72,
      72,    72,    72,    72,    72,    72,     3,    72,    72,    72,
      72,     3,    72,    72,    72,    72,     3,    72,     7,    72,
      72,    72,     7,    72,    72,    72,    72,     4,    72,   640,
      72,    74,    72,    72,     4,     4,    72,    72,   649,    72,
      72,   652,    72,    72,   655,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    12,    72,    72,
      72,    76,    72,    72,    72,   676,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,     4,     8,     4,
       4,     3,    77,    77,     4,     8,    79,     8,    79,    81,
      79,    76,     8,    79,     4,    79,    79,     4,     6,     4,
       3,    75,    84,     4,     4,     4,     4,     3,    72,    82,
       3,     8,    84,    74,    72,    80,    76,    76,    80,     8,
      14,     8,    76,    80,     4,     3,     3,    83,     4,     3,
       5,    80,    80,     3,    80,    75,     3,    75,     3,    11,
     553,   375,   398,   402,   533,   433,   109,   614,   385,   588,
      -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   281,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   352
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    86,    87,     0,    16,    17,    88,    89,    90,    93,
      95,    96,    94,    91,   100,    97,   100,    74,     8,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     3,    72,     4,    92,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
       1,     4,   153,   154,     1,     4,   157,   158,     1,   160,
     161,     1,    79,   165,   166,     1,     4,   169,     1,     4,
     303,     1,     4,   156,   277,   278,     1,   284,   285,     1,
     170,   171,     1,    79,   174,   175,     1,   178,   179,   181,
     182,   183,   184,   186,     1,     4,   190,     1,   158,   191,
       1,   192,   193,     1,   195,   196,     1,   154,   198,     1,
     199,   200,     1,   202,   203,     1,    79,   205,   206,     1,
       4,   302,     1,   209,   210,     1,   212,   213,     1,   218,
     219,     1,   223,   224,     1,   226,   227,     1,     4,   229,
       1,   230,   231,     1,     4,   233,     1,   290,   291,     1,
     292,   293,     1,     4,   234,     1,   299,   300,     1,   235,
     236,   237,     1,   305,   306,     1,   307,   308,     1,   239,
     240,     1,     4,   234,   241,     1,   242,   243,     1,   236,
     248,     1,   296,   297,     1,     4,    82,   245,   249,   250,
       1,   251,   252,     1,     4,   304,     1,     4,   254,     1,
     255,   256,     1,   260,   261,     1,     4,   262,     1,   250,
     263,     1,     4,   264,   265,   266,     1,   270,   271,   272,
       1,   294,   295,    98,    93,   274,   275,    72,    74,    72,
      76,   155,    72,    77,   159,    72,    76,    72,    72,    76,
      11,   163,    72,   167,    72,    76,    72,    72,    76,    72,
      72,    76,    72,    78,    72,    76,    72,    72,    18,    19,
     281,    72,    72,    12,   173,    72,   176,    72,    76,    72,
      72,     9,    76,   155,     8,     5,    10,   189,    72,   155,
      72,    72,    72,    76,    72,    72,    76,   163,    72,    72,
       3,    72,   155,    72,    72,    72,     3,    72,    72,    13,
      72,   207,    72,    76,    72,   155,    72,    72,    72,     3,
      72,    72,     8,   189,   214,    72,    72,    76,   173,    72,
      72,     3,    72,    72,     3,    72,    72,    72,    72,     7,
      72,    72,    72,    72,    18,    19,   287,    72,    72,   281,
      72,    72,    76,    72,    72,     3,    72,    72,    76,   189,
      72,    72,   214,    72,    72,   214,    72,    72,   214,    72,
      76,    72,    72,    72,     3,    72,    72,    76,    72,    72,
       3,    72,    74,   245,   246,    72,   250,    72,    72,     7,
      72,   155,    72,    72,    72,    76,    72,    72,     3,   257,
     258,    72,    72,   214,    72,    72,    76,    72,    72,   250,
      72,    74,    72,    76,     4,   267,    72,    72,    76,     3,
      72,    72,   287,     7,    72,    72,     7,     4,   154,    77,
     156,   158,   162,   164,     8,   166,     4,     4,     4,     5,
     277,   282,   283,    81,   172,     8,   175,   180,   182,   185,
      79,   158,   194,   197,   201,    76,     8,   206,   211,   215,
      79,   155,   221,   220,   225,   228,   232,   288,   289,     4,
       3,   236,    79,   155,   155,   155,     4,   244,   236,   298,
       4,     6,   253,     4,    84,     3,   259,   155,     4,     4,
     265,    75,   155,   271,   273,    99,   276,   155,   156,   163,
     159,   168,   156,   279,   156,   280,    12,   177,   187,   163,
       4,     3,   208,   216,   173,   156,   286,   280,   301,     8,
     245,   245,   247,     3,    84,    74,   268,   267,    72,    80,
      76,    76,    80,     8,    14,    80,     8,   222,    76,     4,
     238,   155,    83,     3,     4,     3,     5,   155,   156,   156,
     155,   188,     3,   155,   217,   156,    80,   269,    80,     3,
      80,   155,    75,     3,    75,     3,    15,   204
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
#line 150 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1555 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 151 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1560 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 152 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1565 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 153 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1570 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 154 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1575 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 155 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1580 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 156 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1585 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 157 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1590 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 158 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1595 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 159 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1600 "parser.cxx"
        break;
      case 71: /* T_HDR_UNKNOWN */
#line 160 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1605 "parser.cxx"
        break;
      case 93: /* sip_version */
#line 219 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1610 "parser.cxx"
        break;
      case 154: /* media_range */
#line 213 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_media); delete yyvaluep->yyt_media; };
#line 1615 "parser.cxx"
        break;
      case 155: /* parameters */
#line 215 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1620 "parser.cxx"
        break;
      case 156: /* parameter */
#line 214 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_param); delete yyvaluep->yyt_param; };
#line 1625 "parser.cxx"
        break;
      case 158: /* content_coding */
#line 202 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_coding); delete yyvaluep->yyt_coding; };
#line 1630 "parser.cxx"
        break;
      case 163: /* language */
#line 212 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_language); delete yyvaluep->yyt_language; };
#line 1635 "parser.cxx"
        break;
      case 166: /* alert_param */
#line 194 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_alert_param); delete yyvaluep->yyt_alert_param; };
#line 1640 "parser.cxx"
        break;
      case 173: /* call_id */
#line 196 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1645 "parser.cxx"
        break;
      case 175: /* info_param */
#line 211 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_info_param); delete yyvaluep->yyt_info_param; };
#line 1650 "parser.cxx"
        break;
      case 181: /* contacts */
#line 201 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contacts); delete yyvaluep->yyt_contacts; };
#line 1655 "parser.cxx"
        break;
      case 182: /* contact_param */
#line 200 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1660 "parser.cxx"
        break;
      case 183: /* contact_addr */
#line 199 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1665 "parser.cxx"
        break;
      case 189: /* display_name */
#line 206 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1670 "parser.cxx"
        break;
      case 206: /* error_param */
#line 207 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_error_param); delete yyvaluep->yyt_error_param; };
#line 1675 "parser.cxx"
        break;
      case 214: /* from_addr */
#line 208 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_from_addr); delete yyvaluep->yyt_from_addr; };
#line 1680 "parser.cxx"
        break;
      case 236: /* rec_route */
#line 216 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_route); delete yyvaluep->yyt_route; };
#line 1685 "parser.cxx"
        break;
      case 245: /* comment */
#line 198 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1690 "parser.cxx"
        break;
      case 250: /* server */
#line 218 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_server); delete yyvaluep->yyt_server; };
#line 1695 "parser.cxx"
        break;
      case 265: /* via_parm */
#line 220 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1700 "parser.cxx"
        break;
      case 266: /* sent_protocol */
#line 217 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1705 "parser.cxx"
        break;
      case 267: /* host */
#line 210 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1710 "parser.cxx"
        break;
      case 271: /* warning */
#line 221 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_warning); delete yyvaluep->yyt_warning; };
#line 1715 "parser.cxx"
        break;
      case 274: /* hdr_unknown */
#line 209 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1720 "parser.cxx"
        break;
      case 279: /* digest_response */
#line 205 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_resp); delete yyvaluep->yyt_dig_resp; };
#line 1725 "parser.cxx"
        break;
      case 280: /* auth_params */
#line 195 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1730 "parser.cxx"
        break;
      case 281: /* credentials */
#line 203 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_credentials); delete yyvaluep->yyt_credentials; };
#line 1735 "parser.cxx"
        break;
      case 286: /* digest_challenge */
#line 204 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_chlg); delete yyvaluep->yyt_dig_chlg; };
#line 1740 "parser.cxx"
        break;
      case 287: /* challenge */
#line 197 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_challenge); delete yyvaluep->yyt_challenge; };
#line 1745 "parser.cxx"
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
#line 224 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 231 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 7:
#line 240 "parser.yxx"
    { CTXT_URI; }
    break;

  case 8:
#line 240 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 9:
#line 241 "parser.yxx"
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
#line 258 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 11:
#line 258 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 12:
#line 262 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 13:
#line 269 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 14:
#line 269 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 15:
#line 270 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 16:
#line 270 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *yyvsp[-6].yyt_str;
			((t_response *)MSG)->code = yyvsp[-4].yyt_ulong;
			((t_response *)MSG)->reason = trim(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-6].yyt_str); delete yyvsp[-6].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 70:
#line 335 "parser.yxx"
    {
			MSG->add_unknown_header(*yyvsp[-3].yyt_str, trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 71:
#line 340 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 72:
#line 342 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 73:
#line 344 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 74:
#line 346 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 75:
#line 348 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 76:
#line 350 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 77:
#line 352 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 78:
#line 354 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 79:
#line 356 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 80:
#line 358 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 81:
#line 360 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 82:
#line 362 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 83:
#line 364 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 84:
#line 366 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 85:
#line 368 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 86:
#line 370 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 87:
#line 372 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 88:
#line 374 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 89:
#line 376 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 90:
#line 378 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 91:
#line 380 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 92:
#line 382 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 93:
#line 384 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 94:
#line 386 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 95:
#line 388 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 96:
#line 390 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 97:
#line 392 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 98:
#line 394 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 99:
#line 396 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 100:
#line 398 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 101:
#line 400 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 102:
#line 402 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 103:
#line 404 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 104:
#line 406 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 105:
#line 408 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 106:
#line 410 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 107:
#line 412 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 108:
#line 414 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 109:
#line 416 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 110:
#line 418 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 111:
#line 420 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 112:
#line 422 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 113:
#line 424 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 114:
#line 426 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 115:
#line 428 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 116:
#line 430 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 117:
#line 432 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 118:
#line 434 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 119:
#line 436 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 120:
#line 438 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 121:
#line 440 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 124:
#line 456 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 129:
#line 466 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 130:
#line 468 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 132:
#line 472 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 135:
#line 478 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 136:
#line 480 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 138:
#line 484 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 139:
#line 486 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 142:
#line 492 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 143:
#line 494 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 144:
#line 496 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 145:
#line 498 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 146:
#line 500 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 148:
#line 504 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 150:
#line 508 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 151:
#line 510 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 153:
#line 514 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 154:
#line 516 "parser.yxx"
    { CTXT_URI; }
    break;

  case 155:
#line 518 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 156:
#line 520 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 157:
#line 522 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 159:
#line 526 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 160:
#line 528 "parser.yxx"
    { CTXT_URI; }
    break;

  case 161:
#line 530 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 163:
#line 534 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 166:
#line 540 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 167:
#line 542 "parser.yxx"
    { CTXT_URI; }
    break;

  case 171:
#line 550 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 172:
#line 552 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 174:
#line 556 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 175:
#line 561 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 176:
#line 568 "parser.yxx"
    { yyval.yyt_media = new t_media(tolower(*yyvsp[-2].yyt_str), tolower(*yyvsp[0].yyt_str));
					MEMMAN_NEW(yyval.yyt_media);
					MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
					MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 177:
#line 574 "parser.yxx"
    { yyval.yyt_params = new list<t_parameter>; MEMMAN_NEW(yyval.yyt_params); }
    break;

  case 178:
#line 575 "parser.yxx"
    {
			yyvsp[-2].yyt_params->push_back(*yyvsp[0].yyt_param);
			yyval.yyt_params = yyvsp[-2].yyt_params;
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 179:
#line 581 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 180:
#line 585 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 181:
#line 590 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 182:
#line 597 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 183:
#line 600 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 184:
#line 605 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 185:
#line 609 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[-1].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			yyval.yyt_coding->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 186:
#line 616 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name != "q") YYERROR;
			yyval.yyt_float = atof(yyvsp[0].yyt_param->value.c_str());
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
			}
    break;

  case 187:
#line 623 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 188:
#line 623 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 189:
#line 626 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 190:
#line 626 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 191:
#line 631 "parser.yxx"
    {
			CTXT_INITIAL;
		  	yyval.yyt_language = new t_language(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 192:
#line 636 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 193:
#line 636 "parser.yxx"
    {
			yyval.yyt_language = new t_language(tolower(*yyvsp[-2].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			yyval.yyt_language->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 194:
#line 643 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 195:
#line 646 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 196:
#line 651 "parser.yxx"
    { CTXT_URI; }
    break;

  case 197:
#line 651 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 198:
#line 651 "parser.yxx"
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

  case 199:
#line 666 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 200:
#line 669 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 201:
#line 674 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 202:
#line 674 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 203:
#line 674 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 204:
#line 679 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 205:
#line 680 "parser.yxx"
    {
			yyval.yyt_str = new string(*yyvsp[-2].yyt_str + '@' + *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 206:
#line 687 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 207:
#line 690 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 208:
#line 695 "parser.yxx"
    { CTXT_URI; }
    break;

  case 209:
#line 695 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 210:
#line 695 "parser.yxx"
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

  case 211:
#line 710 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 212:
#line 710 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 213:
#line 710 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 214:
#line 712 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*yyvsp[0].yyt_contacts);
			MEMMAN_DELETE(yyvsp[0].yyt_contacts); delete yyvsp[0].yyt_contacts; }
    break;

  case 215:
#line 717 "parser.yxx"
    {
			yyval.yyt_contacts = new list<t_contact_param>;
			MEMMAN_NEW(yyval.yyt_contacts);
			yyval.yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 216:
#line 722 "parser.yxx"
    {
			yyvsp[-2].yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			yyval.yyt_contacts = yyvsp[-2].yyt_contacts;
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 217:
#line 728 "parser.yxx"
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

  case 218:
#line 744 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 219:
#line 744 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 220:
#line 744 "parser.yxx"
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

  case 221:
#line 755 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 222:
#line 755 "parser.yxx"
    { CTXT_URI; }
    break;

  case 223:
#line 755 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 224:
#line 755 "parser.yxx"
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

  case 225:
#line 770 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 226:
#line 771 "parser.yxx"
    {
			yyval.yyt_str = new string(rtrim(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 227:
#line 775 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 228:
#line 778 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*yyvsp[-1].yyt_str));
			MSG->hdr_content_disp.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 229:
#line 785 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 230:
#line 788 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 231:
#line 793 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 232:
#line 793 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 233:
#line 796 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 234:
#line 796 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 235:
#line 801 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 236:
#line 801 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 237:
#line 801 "parser.yxx"
    {
			MSG->hdr_content_length.set_length(yyvsp[-1].yyt_ulong); }
    break;

  case 238:
#line 805 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_content_type.set_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 239:
#line 812 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 240:
#line 812 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 241:
#line 812 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr(yyvsp[-2].yyt_ulong);
			MSG->hdr_cseq.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 242:
#line 818 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 243:
#line 821 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 244:
#line 821 "parser.yxx"
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

  case 245:
#line 832 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 246:
#line 835 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 247:
#line 840 "parser.yxx"
    { CTXT_URI; }
    break;

  case 248:
#line 840 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 249:
#line 840 "parser.yxx"
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

  case 250:
#line 855 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 251:
#line 855 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 252:
#line 855 "parser.yxx"
    {
			MSG->hdr_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 253:
#line 859 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 254:
#line 859 "parser.yxx"
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

  case 255:
#line 874 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 256:
#line 874 "parser.yxx"
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

  case 257:
#line 885 "parser.yxx"
    { CTXT_URI; }
    break;

  case 258:
#line 885 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 259:
#line 885 "parser.yxx"
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

  case 260:
#line 900 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 261:
#line 900 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 262:
#line 900 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 263:
#line 903 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 264:
#line 903 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 265:
#line 903 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 266:
#line 908 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 267:
#line 908 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 268:
#line 908 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards(yyvsp[-1].yyt_ulong); }
    break;

  case 269:
#line 912 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 270:
#line 912 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 271:
#line 912 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 272:
#line 916 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 273:
#line 921 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 274:
#line 921 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 275:
#line 921 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 276:
#line 926 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 277:
#line 931 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 278:
#line 934 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 279:
#line 939 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 280:
#line 942 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 281:
#line 947 "parser.yxx"
    { CTXT_URI; }
    break;

  case 282:
#line 947 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 283:
#line 948 "parser.yxx"
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

  case 284:
#line 965 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 285:
#line 965 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_reply_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_reply_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 286:
#line 973 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 287:
#line 976 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 288:
#line 981 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 289:
#line 981 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 290:
#line 981 "parser.yxx"
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

  case 291:
#line 997 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 292:
#line 998 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 293:
#line 998 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 294:
#line 998 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[-2].yyt_str; }
    break;

  case 295:
#line 1002 "parser.yxx"
    {
			MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 296:
#line 1005 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 297:
#line 1010 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 298:
#line 1013 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 299:
#line 1018 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 300:
#line 1023 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 301:
#line 1030 "parser.yxx"
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

  case 302:
#line 1041 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 303:
#line 1041 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 304:
#line 1041 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 305:
#line 1046 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 306:
#line 1048 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 307:
#line 1051 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 308:
#line 1056 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 309:
#line 1056 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 310:
#line 1059 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[0].yyt_float); }
    break;

  case 311:
#line 1061 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[-1].yyt_float);
			MSG->hdr_timestamp.set_delay(yyvsp[0].yyt_float); }
    break;

  case 312:
#line 1066 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 313:
#line 1067 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 314:
#line 1072 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 315:
#line 1073 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 316:
#line 1078 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 317:
#line 1078 "parser.yxx"
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

  case 318:
#line 1093 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 319:
#line 1096 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 320:
#line 1101 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 321:
#line 1104 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 322:
#line 1109 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 323:
#line 1112 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 324:
#line 1117 "parser.yxx"
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

  case 325:
#line 1145 "parser.yxx"
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

  case 326:
#line 1156 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 327:
#line 1161 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 328:
#line 1161 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 329:
#line 1161 "parser.yxx"
    {
			if (yyvsp[-1].yyt_ulong > 65535) YYERROR;
			
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[-4].yyt_str;
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 330:
#line 1171 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 331:
#line 1174 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 332:
#line 1179 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 333:
#line 1179 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 334:
#line 1179 "parser.yxx"
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

  case 335:
#line 1190 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 336:
#line 1190 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 337:
#line 1190 "parser.yxx"
    { yyval.yyt_str = yyvsp[-1].yyt_str; }
    break;

  case 338:
#line 1193 "parser.yxx"
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

  case 341:
#line 1217 "parser.yxx"
    {
			yyval.yyt_dig_resp = new t_digest_response();
			MEMMAN_NEW(yyval.yyt_dig_resp);
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 342:
#line 1224 "parser.yxx"
    {
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 343:
#line 1231 "parser.yxx"
    {
			yyval.yyt_params = new list<t_parameter>;
			MEMMAN_NEW(yyval.yyt_params);
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 344:
#line 1236 "parser.yxx"
    {
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 345:
#line 1241 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 346:
#line 1241 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = AUTH_DIGEST;
			yyval.yyt_credentials->digest_response = *yyvsp[0].yyt_dig_resp;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_resp); delete yyvsp[0].yyt_dig_resp; }
    break;

  case 347:
#line 1247 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 348:
#line 1247 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_credentials->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 349:
#line 1256 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 350:
#line 1256 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*yyvsp[0].yyt_credentials);
			MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 351:
#line 1261 "parser.yxx"
    {
			yyval.yyt_dig_chlg = new t_digest_challenge();
			MEMMAN_NEW(yyval.yyt_dig_chlg);
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 352:
#line 1268 "parser.yxx"
    {
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 353:
#line 1275 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 354:
#line 1275 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = AUTH_DIGEST;
			yyval.yyt_challenge->digest_challenge = *yyvsp[0].yyt_dig_chlg;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_chlg); delete yyvsp[0].yyt_dig_chlg; }
    break;

  case 355:
#line 1281 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 356:
#line 1281 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_challenge->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 357:
#line 1290 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 358:
#line 1290 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 359:
#line 1295 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 360:
#line 1295 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*yyvsp[0].yyt_credentials);
				MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 361:
#line 1301 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 362:
#line 1301 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 363:
#line 1306 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 364:
#line 1306 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 365:
#line 1306 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr(yyvsp[-1].yyt_ulong); }
    break;

  case 366:
#line 1310 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 367:
#line 1310 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 368:
#line 1310 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr(yyvsp[-3].yyt_ulong);
			MSG->hdr_rack.set_cseq_nr(yyvsp[-2].yyt_ulong);
			MSG->hdr_rack.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 369:
#line 1317 "parser.yxx"
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

  case 370:
#line 1331 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 371:
#line 1334 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 372:
#line 1339 "parser.yxx"
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

  case 373:
#line 1365 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 374:
#line 1365 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_refer_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_refer_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 375:
#line 1373 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 376:
#line 1373 "parser.yxx"
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
#line 4086 "parser.cxx"

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


#line 1388 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

