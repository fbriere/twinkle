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
     T_HDR_P_ASSERTED_IDENTITY = 302,
     T_HDR_P_PREFERRED_IDENTITY = 303,
     T_HDR_PRIORITY = 304,
     T_HDR_PRIVACY = 305,
     T_HDR_PROXY_AUTHENTICATE = 306,
     T_HDR_PROXY_AUTHORIZATION = 307,
     T_HDR_PROXY_REQUIRE = 308,
     T_HDR_RACK = 309,
     T_HDR_RECORD_ROUTE = 310,
     T_HDR_REFER_SUB = 311,
     T_HDR_REFER_TO = 312,
     T_HDR_REFERRED_BY = 313,
     T_HDR_REPLACES = 314,
     T_HDR_REPLY_TO = 315,
     T_HDR_REQUIRE = 316,
     T_HDR_RETRY_AFTER = 317,
     T_HDR_ROUTE = 318,
     T_HDR_RSEQ = 319,
     T_HDR_SERVER = 320,
     T_HDR_SUBJECT = 321,
     T_HDR_SUBSCRIPTION_STATE = 322,
     T_HDR_SUPPORTED = 323,
     T_HDR_TIMESTAMP = 324,
     T_HDR_TO = 325,
     T_HDR_UNSUPPORTED = 326,
     T_HDR_USER_AGENT = 327,
     T_HDR_VIA = 328,
     T_HDR_WARNING = 329,
     T_HDR_WWW_AUTHENTICATE = 330,
     T_HDR_UNKNOWN = 331,
     T_CRLF = 332,
     T_ERROR = 333,
     T_NULL = 334
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
#define T_HDR_P_ASSERTED_IDENTITY 302
#define T_HDR_P_PREFERRED_IDENTITY 303
#define T_HDR_PRIORITY 304
#define T_HDR_PRIVACY 305
#define T_HDR_PROXY_AUTHENTICATE 306
#define T_HDR_PROXY_AUTHORIZATION 307
#define T_HDR_PROXY_REQUIRE 308
#define T_HDR_RACK 309
#define T_HDR_RECORD_ROUTE 310
#define T_HDR_REFER_SUB 311
#define T_HDR_REFER_TO 312
#define T_HDR_REFERRED_BY 313
#define T_HDR_REPLACES 314
#define T_HDR_REPLY_TO 315
#define T_HDR_REQUIRE 316
#define T_HDR_RETRY_AFTER 317
#define T_HDR_ROUTE 318
#define T_HDR_RSEQ 319
#define T_HDR_SERVER 320
#define T_HDR_SUBJECT 321
#define T_HDR_SUBSCRIPTION_STATE 322
#define T_HDR_SUPPORTED 323
#define T_HDR_TIMESTAMP 324
#define T_HDR_TO 325
#define T_HDR_UNSUPPORTED 326
#define T_HDR_USER_AGENT 327
#define T_HDR_VIA 328
#define T_HDR_WARNING 329
#define T_HDR_WWW_AUTHENTICATE 330
#define T_HDR_UNKNOWN 331
#define T_CRLF 332
#define T_ERROR 333
#define T_NULL 334




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
	t_identity		*yyt_from_addr;
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
#line 277 "parser.cxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 289 "parser.cxx"

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
#define YYLAST   717

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  238
/* YYNRULES -- Number of rules. */
#define YYNRULES  404
/* YYNRULES -- Number of states. */
#define YYNSTATES  742

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      88,    89,     2,     2,    82,     2,    90,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    83,
      85,    84,    86,     2,    87,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79
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
     252,   256,   260,   264,   268,   272,   276,   281,   285,   289,
     293,   297,   301,   305,   309,   313,   317,   321,   325,   329,
     333,   337,   341,   345,   349,   353,   357,   361,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   401,   405,   409,
     413,   417,   421,   425,   429,   433,   437,   441,   445,   449,
     453,   457,   461,   465,   469,   473,   477,   481,   485,   489,
     493,   497,   501,   505,   508,   511,   514,   517,   520,   523,
     526,   529,   532,   535,   538,   541,   544,   547,   550,   553,
     556,   559,   562,   565,   568,   571,   574,   577,   580,   583,
     586,   589,   592,   595,   598,   601,   604,   607,   610,   613,
     616,   619,   622,   625,   628,   631,   634,   637,   640,   643,
     646,   649,   652,   655,   658,   661,   664,   667,   670,   673,
     674,   677,   682,   686,   687,   691,   693,   697,   701,   703,
     707,   709,   712,   715,   716,   719,   720,   725,   727,   728,
     732,   734,   738,   739,   740,   747,   749,   753,   754,   755,
     759,   761,   765,   767,   771,   772,   773,   780,   781,   782,
     786,   788,   790,   794,   797,   798,   799,   803,   804,   805,
     806,   814,   815,   817,   819,   822,   824,   828,   829,   832,
     833,   838,   839,   840,   844,   847,   848,   849,   854,   855,
     856,   870,   872,   876,   877,   878,   885,   886,   887,   891,
     892,   896,   897,   900,   901,   902,   909,   910,   911,   915,
     916,   917,   923,   924,   925,   929,   930,   931,   935,   937,
     938,   939,   943,   944,   947,   951,   952,   955,   959,   961,
     963,   967,   969,   973,   975,   979,   980,   981,   989,   990,
     991,   996,   997,  1001,  1003,  1007,  1008,  1009,  1015,  1016,
    1017,  1018,  1024,  1026,  1030,  1032,  1035,  1037,  1040,  1045,
    1046,  1047,  1051,  1052,  1054,  1058,  1059,  1062,  1064,  1067,
    1069,  1073,  1075,  1079,  1080,  1084,  1086,  1090,  1092,  1095,
    1097,  1101,  1105,  1111,  1113,  1114,  1115,  1121,  1123,  1127,
    1128,  1129,  1135,  1136,  1137,  1141,  1143,  1145,  1149,  1151,
    1155,  1157,  1161,  1162,  1166,  1167,  1171,  1172,  1175,  1177,
    1181,  1182,  1186,  1187,  1191,  1192,  1195,  1196,  1199,  1200,
    1203,  1204,  1205,  1209,  1210,  1211,  1217,  1220,  1222,  1226,
    1229,  1230,  1234,  1235,  1239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      92,     0,    -1,    -1,    93,    94,    -1,    95,    -1,   101,
      -1,     1,    79,    -1,    96,   106,    77,    -1,    -1,    -1,
      17,    97,     8,    98,    99,    77,    -1,    -1,    16,   100,
      80,     4,    -1,   102,   106,    77,    -1,    -1,    -1,    -1,
      99,   103,     3,   104,     7,   105,    77,    -1,    -1,   106,
     107,    -1,   108,   164,    77,    -1,   109,   168,    77,    -1,
     110,   171,    77,    -1,   111,   176,    77,    -1,   112,   180,
      77,    -1,   113,   322,    77,    -1,   114,   297,    77,    -1,
     115,   303,    77,    -1,   116,   181,    77,    -1,   117,   185,
      77,    -1,   118,   189,    77,    -1,   119,   201,    77,    -1,
     120,   202,    77,    -1,   121,   203,    77,    -1,   122,   206,
      77,    -1,   123,   209,    77,    -1,   124,   210,    77,    -1,
     125,   213,    77,    -1,   127,   321,    77,    -1,   126,   216,
      77,    -1,   128,   220,    77,    -1,   129,   223,    77,    -1,
     130,   229,    77,    -1,   131,   234,    77,    -1,   132,   237,
      77,    -1,   133,   240,    77,    -1,   134,   241,    77,    -1,
     135,   244,    77,    -1,   136,   246,    77,    -1,   137,   248,
      77,    -1,   138,   249,    77,    -1,   139,   309,    77,    -1,
     140,   311,    77,    -1,   141,   250,    77,    -1,   142,   318,
      77,    -1,   143,   251,    77,    -1,   144,   328,    77,    -1,
     145,   324,    77,    -1,   146,   326,    77,    -1,   147,   255,
      77,    -1,   148,   258,    77,    -1,   149,   260,    77,    -1,
     150,   261,    77,    -1,   151,   267,    77,    -1,   152,   315,
      77,    -1,   153,   268,    77,    -1,   154,   270,    77,    -1,
     155,   323,    77,    -1,   156,   273,    77,    -1,   157,   274,
      77,    -1,   158,   279,    77,    -1,   159,   281,    77,    -1,
     160,   282,    77,    -1,   161,   283,    77,    -1,   162,   289,
      77,    -1,   163,   313,    77,    -1,    76,    81,   293,    77,
      -1,   108,     1,    77,    -1,   109,     1,    77,    -1,   110,
       1,    77,    -1,   111,     1,    77,    -1,   112,     1,    77,
      -1,   113,     1,    77,    -1,   114,     1,    77,    -1,   115,
       1,    77,    -1,   116,     1,    77,    -1,   117,     1,    77,
      -1,   118,     1,    77,    -1,   119,     1,    77,    -1,   120,
       1,    77,    -1,   121,     1,    77,    -1,   122,     1,    77,
      -1,   123,     1,    77,    -1,   124,     1,    77,    -1,   125,
       1,    77,    -1,   126,     1,    77,    -1,   127,     1,    77,
      -1,   128,     1,    77,    -1,   129,     1,    77,    -1,   130,
       1,    77,    -1,   131,     1,    77,    -1,   132,     1,    77,
      -1,   133,     1,    77,    -1,   134,     1,    77,    -1,   135,
       1,    77,    -1,   136,     1,    77,    -1,   137,     1,    77,
      -1,   138,     1,    77,    -1,   139,     1,    77,    -1,   140,
       1,    77,    -1,   141,     1,    77,    -1,   142,     1,    77,
      -1,   143,     1,    77,    -1,   144,     1,    77,    -1,   145,
       1,    77,    -1,   146,     1,    77,    -1,   147,     1,    77,
      -1,   148,     1,    77,    -1,   149,     1,    77,    -1,   150,
       1,    77,    -1,   151,     1,    77,    -1,   152,     1,    77,
      -1,   153,     1,    77,    -1,   154,     1,    77,    -1,   155,
       1,    77,    -1,   156,     1,    77,    -1,   157,     1,    77,
      -1,   158,     1,    77,    -1,   159,     1,    77,    -1,   160,
       1,    77,    -1,   161,     1,    77,    -1,   162,     1,    77,
      -1,   163,     1,    77,    -1,    20,    81,    -1,    21,    81,
      -1,    22,    81,    -1,    23,    81,    -1,    24,    81,    -1,
      25,    81,    -1,    26,    81,    -1,    27,    81,    -1,    28,
      81,    -1,    29,    81,    -1,    30,    81,    -1,    31,    81,
      -1,    32,    81,    -1,    33,    81,    -1,    34,    81,    -1,
      35,    81,    -1,    36,    81,    -1,    37,    81,    -1,    38,
      81,    -1,    39,    81,    -1,    40,    81,    -1,    41,    81,
      -1,    42,    81,    -1,    43,    81,    -1,    44,    81,    -1,
      45,    81,    -1,    46,    81,    -1,    47,    81,    -1,    48,
      81,    -1,    49,    81,    -1,    50,    81,    -1,    51,    81,
      -1,    52,    81,    -1,    53,    81,    -1,    54,    81,    -1,
      55,    81,    -1,    56,    81,    -1,    57,    81,    -1,    58,
      81,    -1,    59,    81,    -1,    60,    81,    -1,    61,    81,
      -1,    62,    81,    -1,    63,    81,    -1,    64,    81,    -1,
      65,    81,    -1,    66,    81,    -1,    67,    81,    -1,    68,
      81,    -1,    69,    81,    -1,    70,    81,    -1,    71,    81,
      -1,    72,    81,    -1,    73,    81,    -1,    74,    81,    -1,
      75,    81,    -1,    -1,   165,   166,    -1,   164,    82,   165,
     166,    -1,     4,    80,     4,    -1,    -1,   166,    83,   167,
      -1,     4,    -1,     4,    84,     4,    -1,     4,    84,     5,
      -1,   169,    -1,   168,    82,   169,    -1,     4,    -1,     4,
     170,    -1,    83,   167,    -1,    -1,   172,   174,    -1,    -1,
     171,    82,   173,   174,    -1,    11,    -1,    -1,    11,   175,
     170,    -1,   177,    -1,   176,    82,   177,    -1,    -1,    -1,
      85,   178,     8,   179,    86,   166,    -1,     4,    -1,   180,
      82,     4,    -1,    -1,    -1,   182,   184,   183,    -1,    12,
      -1,    12,    87,    12,    -1,   186,    -1,   185,    82,   186,
      -1,    -1,    -1,    85,   187,     8,   188,    86,   166,    -1,
      -1,    -1,   190,     9,   191,    -1,   192,    -1,   193,    -1,
     192,    82,   193,    -1,   194,   166,    -1,    -1,    -1,   195,
       8,   196,    -1,    -1,    -1,    -1,   197,   200,    85,   198,
       8,   199,    86,    -1,    -1,    10,    -1,     5,    -1,     4,
     166,    -1,   169,    -1,   202,    82,   169,    -1,    -1,   204,
     174,    -1,    -1,   203,    82,   205,   174,    -1,    -1,    -1,
     207,     3,   208,    -1,   165,   166,    -1,    -1,    -1,   211,
       3,   212,     4,    -1,    -1,    -1,   214,    13,    82,     3,
      14,     3,     3,    81,     3,    81,     3,    15,   215,    -1,
     217,    -1,   216,    82,   217,    -1,    -1,    -1,    85,   218,
       8,   219,    86,   166,    -1,    -1,    -1,   221,     3,   222,
      -1,    -1,   224,   225,   166,    -1,    -1,     8,   226,    -1,
      -1,    -1,   200,    85,   227,     8,   228,    86,    -1,    -1,
      -1,   230,   184,   231,    -1,    -1,    -1,   229,    82,   232,
     184,   233,    -1,    -1,    -1,   235,     3,   236,    -1,    -1,
      -1,   238,     3,   239,    -1,     4,    -1,    -1,    -1,   242,
       7,   243,    -1,    -1,   245,   225,    -1,   244,    82,   225,
      -1,    -1,   247,   225,    -1,   246,    82,   225,    -1,     4,
      -1,     4,    -1,   249,    83,     4,    -1,     4,    -1,   250,
      82,     4,    -1,   252,    -1,   251,    82,   252,    -1,    -1,
      -1,   253,   200,    85,     8,   254,    86,   166,    -1,    -1,
      -1,   256,   184,   257,   166,    -1,    -1,   259,   225,   166,
      -1,     4,    -1,   250,    82,     4,    -1,    -1,    -1,   262,
       3,   263,   264,   166,    -1,    -1,    -1,    -1,    88,   265,
       6,   266,    89,    -1,   252,    -1,   267,    82,   252,    -1,
     269,    -1,   268,   269,    -1,   264,    -1,     4,   264,    -1,
       4,    80,     4,   264,    -1,    -1,    -1,   271,     7,   272,
      -1,    -1,     4,    -1,   273,    82,     4,    -1,    -1,   275,
     276,    -1,   277,    -1,   277,   278,    -1,     3,    -1,     3,
      90,     3,    -1,     3,    -1,     3,    90,     3,    -1,    -1,
     280,   225,   166,    -1,     4,    -1,   281,    82,     4,    -1,
     269,    -1,   282,   269,    -1,   284,    -1,   283,    82,   284,
      -1,   285,   286,   166,    -1,     4,    80,     4,    80,     4,
      -1,     4,    -1,    -1,    -1,     4,    81,   287,     3,   288,
      -1,   290,    -1,   289,    82,   290,    -1,    -1,    -1,   291,
       3,   292,   286,     5,    -1,    -1,    -1,   294,     7,   295,
      -1,   167,    -1,   296,    -1,   297,    82,   296,    -1,   167,
      -1,   298,    82,   167,    -1,   167,    -1,   299,    82,   167,
      -1,    -1,    18,   301,   298,    -1,    -1,    19,   302,   299,
      -1,    -1,   304,   300,    -1,   167,    -1,   305,    82,   167,
      -1,    -1,    18,   307,   305,    -1,    -1,    19,   308,   299,
      -1,    -1,   310,   306,    -1,    -1,   312,   300,    -1,    -1,
     314,   306,    -1,    -1,    -1,   316,     3,   317,    -1,    -1,
      -1,   319,     3,     3,   320,     4,    -1,     4,   166,    -1,
       4,    -1,   322,    82,     4,    -1,     4,   166,    -1,    -1,
     325,   225,   166,    -1,    -1,   327,   225,   166,    -1,     4,
     166,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   232,   232,   232,   235,   236,   237,   257,   266,   266,
     266,   284,   284,   288,   295,   295,   296,   295,   306,   307,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   370,   372,   374,
     376,   378,   380,   382,   384,   386,   388,   390,   392,   394,
     396,   398,   400,   402,   404,   406,   408,   410,   412,   414,
     416,   418,   420,   422,   424,   426,   428,   430,   432,   434,
     436,   438,   440,   442,   444,   446,   448,   450,   452,   454,
     456,   458,   460,   462,   464,   466,   468,   470,   472,   474,
     476,   478,   480,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   535,   537,   539,   541,   543,   545,
     547,   549,   551,   553,   555,   557,   559,   561,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   593,   595,   597,   599,   601,   603,   606,
     607,   612,   619,   625,   626,   632,   636,   641,   648,   651,
     656,   660,   667,   674,   674,   677,   677,   682,   687,   687,
     694,   697,   702,   702,   702,   717,   720,   725,   725,   725,
     730,   731,   738,   741,   746,   746,   746,   761,   761,   761,
     763,   768,   773,   779,   795,   795,   795,   806,   806,   806,
     806,   821,   822,   826,   829,   836,   839,   844,   844,   847,
     847,   852,   852,   852,   856,   863,   863,   863,   869,   872,
     869,   883,   886,   891,   891,   891,   906,   906,   906,   910,
     910,   925,   925,   936,   936,   936,   951,   951,   951,   954,
     954,   954,   959,   959,   959,   963,   963,   963,   967,   972,
     972,   972,   977,   977,   980,   985,   985,   988,   993,   998,
    1001,  1006,  1009,  1014,  1017,  1022,  1022,  1022,  1040,  1040,
    1040,  1062,  1062,  1070,  1073,  1078,  1078,  1078,  1094,  1095,
    1095,  1095,  1099,  1102,  1107,  1110,  1115,  1120,  1127,  1138,
    1138,  1138,  1143,  1145,  1148,  1153,  1153,  1156,  1158,  1163,
    1164,  1169,  1170,  1175,  1175,  1190,  1193,  1198,  1201,  1206,
    1209,  1214,  1242,  1253,  1258,  1258,  1258,  1268,  1271,  1276,
    1276,  1276,  1287,  1287,  1287,  1290,  1310,  1311,  1314,  1322,
    1329,  1334,  1339,  1339,  1345,  1345,  1354,  1354,  1359,  1367,
    1374,  1374,  1380,  1380,  1389,  1389,  1394,  1394,  1400,  1400,
    1405,  1405,  1405,  1409,  1409,  1409,  1416,  1430,  1433,  1438,
    1464,  1464,  1472,  1472,  1487
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
  "T_HDR_ORGANIZATION", "T_HDR_P_ASSERTED_IDENTITY", 
  "T_HDR_P_PREFERRED_IDENTITY", "T_HDR_PRIORITY", "T_HDR_PRIVACY", 
  "T_HDR_PROXY_AUTHENTICATE", "T_HDR_PROXY_AUTHORIZATION", 
  "T_HDR_PROXY_REQUIRE", "T_HDR_RACK", "T_HDR_RECORD_ROUTE", 
  "T_HDR_REFER_SUB", "T_HDR_REFER_TO", "T_HDR_REFERRED_BY", 
  "T_HDR_REPLACES", "T_HDR_REPLY_TO", "T_HDR_REQUIRE", 
  "T_HDR_RETRY_AFTER", "T_HDR_ROUTE", "T_HDR_RSEQ", "T_HDR_SERVER", 
  "T_HDR_SUBJECT", "T_HDR_SUBSCRIPTION_STATE", "T_HDR_SUPPORTED", 
  "T_HDR_TIMESTAMP", "T_HDR_TO", "T_HDR_UNSUPPORTED", "T_HDR_USER_AGENT", 
  "T_HDR_VIA", "T_HDR_WARNING", "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", 
  "T_CRLF", "T_ERROR", "T_NULL", "'/'", "':'", "','", "';'", "'='", "'<'", 
  "'>'", "'@'", "'('", "')'", "'.'", "$accept", "sip_message", "@1", 
  "sip_message2", "request", "request_line", "@2", "@3", "sip_version", 
  "@4", "response", "status_line", "@5", "@6", "@7", "headers", "header", 
  "hd_accept", "hd_accept_encoding", "hd_accept_language", 
  "hd_alert_info", "hd_allow", "hd_allow_events", 
  "hd_authentication_info", "hd_authorization", "hd_call_id", 
  "hd_call_info", "hd_contact", "hd_content_disp", "hd_content_encoding", 
  "hd_content_language", "hd_content_length", "hd_content_type", 
  "hd_cseq", "hd_date", "hd_error_info", "hd_event", "hd_expires", 
  "hd_from", "hd_in_reply_to", "hd_max_forwards", "hd_min_expires", 
  "hd_mime_version", "hd_organization", "hd_p_asserted_identity", 
  "hd_p_preferred_identity", "hd_priority", "hd_privacy", 
  "hd_proxy_authenticate", "hd_proxy_authorization", "hd_proxy_require", 
  "hd_rack", "hd_record_route", "hd_refer_sub", "hd_refer_to", 
  "hd_referred_by", "hd_replaces", "hd_reply_to", "hd_require", 
  "hd_retry_after", "hd_route", "hd_rseq", "hd_server", "hd_subject", 
  "hd_subscription_state", "hd_supported", "hd_timestamp", "hd_to", 
  "hd_unsupported", "hd_user_agent", "hd_via", "hd_warning", 
  "hd_www_authenticate", "hdr_accept", "media_range", "parameters", 
  "parameter", "hdr_accept_encoding", "content_coding", "q_factor", 
  "hdr_accept_language", "@8", "@9", "language", "@10", "hdr_alert_info", 
  "alert_param", "@11", "@12", "hdr_allow", "hdr_call_id", "@13", "@14", 
  "call_id", "hdr_call_info", "info_param", "@15", "@16", "hdr_contact", 
  "@17", "@18", "contacts", "contact_param", "contact_addr", "@19", "@20", 
  "@21", "@22", "@23", "display_name", "hdr_content_disp", 
  "hdr_content_encoding", "hdr_content_language", "@24", "@25", 
  "hdr_content_length", "@26", "@27", "hdr_content_type", "hdr_cseq", 
  "@28", "@29", "hdr_date", "@30", "@31", "hdr_error_info", "error_param", 
  "@32", "@33", "hdr_expires", "@34", "@35", "hdr_from", "@36", 
  "from_addr", "@37", "@38", "@39", "hdr_in_reply_to", "@40", "@41", 
  "@42", "@43", "hdr_max_forwards", "@44", "@45", "hdr_min_expires", 
  "@46", "@47", "hdr_mime_version", "hdr_organization", "@48", "@49", 
  "hdr_p_asserted_identity", "@50", "hdr_p_preferred_identity", "@51", 
  "hdr_priority", "hdr_privacy", "hdr_proxy_require", "hdr_record_route", 
  "rec_route", "@52", "@53", "hdr_replaces", "@54", "@55", "hdr_reply_to", 
  "@56", "hdr_require", "hdr_retry_after", "@57", "@58", "comment", "@59", 
  "@60", "hdr_route", "hdr_server", "server", "hdr_subject", "@61", "@62", 
  "hdr_supported", "hdr_timestamp", "@63", "hdr_timestamp1", "timestamp", 
  "delay", "hdr_to", "@64", "hdr_unsupported", "hdr_user_agent", 
  "hdr_via", "via_parm", "sent_protocol", "host", "@65", "@66", 
  "hdr_warning", "warning", "@67", "@68", "hdr_unknown", "@69", "@70", 
  "ainfo", "hdr_authentication_info", "digest_response", "auth_params", 
  "credentials", "@71", "@72", "hdr_authorization", "@73", 
  "digest_challenge", "challenge", "@74", "@75", "hdr_proxy_authenticate", 
  "@76", "hdr_proxy_authorization", "@77", "hdr_www_authenticate", "@78", 
  "hdr_rseq", "@79", "@80", "hdr_rack", "@81", "@82", "hdr_event", 
  "hdr_allow_events", "hdr_subscription_state", "hdr_refer_to", "@83", 
  "hdr_referred_by", "@84", "hdr_refer_sub", 0
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      47,    58,    44,    59,    61,    60,    62,    64,    40,    41,
      46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,    91,    93,    92,    94,    94,    94,    95,    97,    98,
      96,   100,    99,   101,   103,   104,   105,   102,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     164,   164,   165,   166,   166,   167,   167,   167,   168,   168,
     169,   169,   170,   172,   171,   173,   171,   174,   175,   174,
     176,   176,   178,   179,   177,   180,   180,   182,   183,   181,
     184,   184,   185,   185,   187,   188,   186,   190,   191,   189,
     189,   192,   192,   193,   195,   196,   194,   197,   198,   199,
     194,   200,   200,   200,   201,   202,   202,   204,   203,   205,
     203,   207,   208,   206,   209,   211,   212,   210,   214,   215,
     213,   216,   216,   218,   219,   217,   221,   222,   220,   224,
     223,   226,   225,   227,   228,   225,   230,   231,   229,   232,
     233,   229,   235,   236,   234,   238,   239,   237,   240,   242,
     243,   241,   245,   244,   244,   247,   246,   246,   248,   249,
     249,   250,   250,   251,   251,   253,   254,   252,   256,   257,
     255,   259,   258,   260,   260,   262,   263,   261,   264,   265,
     266,   264,   267,   267,   268,   268,   269,   269,   269,   271,
     272,   270,   273,   273,   273,   275,   274,   276,   276,   277,
     277,   278,   278,   280,   279,   281,   281,   282,   282,   283,
     283,   284,   285,   286,   287,   288,   286,   289,   289,   291,
     292,   290,   294,   295,   293,   296,   297,   297,   298,   298,
     299,   299,   301,   300,   302,   300,   304,   303,   305,   305,
     307,   306,   308,   306,   310,   309,   312,   311,   314,   313,
     316,   317,   315,   319,   320,   318,   321,   322,   322,   323,
     325,   324,   327,   326,   328
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
       3,     3,     3,     3,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       2,     4,     3,     0,     3,     1,     3,     3,     1,     3,
       1,     2,     2,     0,     2,     0,     4,     1,     0,     3,
       1,     3,     0,     0,     6,     1,     3,     0,     0,     3,
       1,     3,     1,     3,     0,     0,     6,     0,     0,     3,
       1,     1,     3,     2,     0,     0,     3,     0,     0,     0,
       7,     0,     1,     1,     2,     1,     3,     0,     2,     0,
       4,     0,     0,     3,     2,     0,     0,     4,     0,     0,
      13,     1,     3,     0,     0,     6,     0,     0,     3,     0,
       3,     0,     2,     0,     0,     6,     0,     0,     3,     0,
       0,     5,     0,     0,     3,     0,     0,     3,     1,     0,
       0,     3,     0,     2,     3,     0,     2,     3,     1,     1,
       3,     1,     3,     1,     3,     0,     0,     7,     0,     0,
       4,     0,     3,     1,     3,     0,     0,     5,     0,     0,
       0,     5,     1,     3,     1,     2,     1,     2,     4,     0,
       0,     3,     0,     1,     3,     0,     2,     1,     2,     1,
       3,     1,     3,     0,     3,     1,     3,     1,     2,     1,
       3,     3,     5,     1,     0,     0,     5,     1,     3,     0,
       0,     5,     0,     0,     3,     1,     1,     3,     1,     3,
       1,     3,     0,     3,     0,     3,     0,     2,     1,     3,
       0,     3,     0,     3,     0,     2,     0,     2,     0,     2,
       0,     0,     3,     0,     0,     5,     2,     1,     3,     2,
       0,     3,     0,     3,     2
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
       0,     0,     0,     0,     0,     0,     0,     0,     7,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    13,    12,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   362,     0,     0,     0,
     193,     0,   200,     0,   198,     0,     0,     0,     0,   212,
       0,   210,     0,   215,     0,     0,   397,     0,     0,   195,
     365,   366,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,   222,     0,     0,     0,   230,   231,   193,     0,
     241,     0,   193,     0,     0,   245,     0,     0,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,   261,     0,   193,     0,     0,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,   241,     0,     0,   241,     0,   298,     0,     0,
     299,     0,     0,     0,     0,     0,     0,     0,     0,   301,
       0,     0,     0,     0,     0,     0,   303,   241,     0,   193,
       0,     0,     0,   241,     0,     0,   241,     0,     0,     0,
       0,     0,   241,     0,   301,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,   318,   319,   326,
       0,   324,     0,     0,     0,     0,   193,     0,     0,   333,
       0,     0,     0,     0,     0,     0,   241,     0,   345,     0,
       0,   347,     0,     0,     0,     0,   349,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,    20,     0,   190,    78,     0,   201,    21,     0,    79,
      22,   205,   207,   204,    80,     0,    23,     0,    81,    24,
       0,    82,    25,     0,    83,     0,    26,     0,    84,    27,
     372,   374,   377,    85,    28,   220,   218,    86,     0,    29,
       0,    87,    30,   228,   237,   233,   235,   243,   242,     0,
      88,   244,    31,    89,    32,     0,    90,    33,   249,   248,
      91,    34,   252,    92,   254,    35,    93,    36,   256,    94,
      37,     0,    95,     0,    39,     0,    96,   396,    38,    97,
      40,   267,    98,    41,   271,     0,   193,    99,    42,   279,
     277,   100,    43,   283,   101,    44,   286,   102,    45,   103,
      46,   290,   104,    47,   241,   293,   105,    48,   241,   296,
     106,    49,   107,    50,     0,   108,    51,   380,   382,   385,
     109,    52,   387,   110,    53,     0,   111,    54,     0,   112,
      55,   305,     0,   113,   404,    56,   114,    57,   193,   115,
      58,   193,   116,    59,   309,   117,    60,   193,   118,     0,
      61,   119,    62,   316,   120,    63,   305,   121,    64,   391,
     122,     0,   327,     0,    65,   325,   123,    66,   330,   124,
     399,    67,   125,    68,     0,   126,    69,   339,   336,   337,
     127,    70,   193,   128,    71,     0,   129,    72,   348,   130,
       0,    73,     0,   353,   193,   131,    74,   359,   360,   132,
      75,   389,    16,    10,    76,   363,   192,   193,     0,   202,
     199,     0,     0,   213,   211,   216,   398,   196,   197,   367,
       0,     0,     0,   219,   225,   223,   229,   232,   236,   238,
     246,     0,   253,     0,     0,   264,   262,   268,   272,   273,
     270,     0,   278,   284,   287,   291,   294,   297,   300,     0,
       0,   302,   394,   304,     0,   401,   403,   193,   312,   302,
     318,   323,   392,   318,   320,   331,   334,     0,   341,   338,
     344,   346,     0,   350,   354,   351,   358,     0,     0,   364,
     191,   194,   206,   209,     0,   368,   373,   370,   375,   221,
       0,     0,   250,   257,     0,     0,     0,   280,   378,   381,
     383,     0,   306,   310,   193,   328,     0,   340,     0,     0,
       0,     0,    17,   193,     0,     0,   193,   239,     0,   193,
     274,   281,     0,   395,     0,   317,   321,   342,   352,   355,
     361,   214,   369,   371,   226,     0,     0,   265,     0,   379,
     193,   356,   240,     0,   275,   307,     0,     0,     0,     0,
     259,   260
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    15,   139,    10,    14,
      11,    12,    17,   385,   668,    16,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   199,   200,   393,   220,   203,   204,   396,
     206,   207,   601,   403,   602,   210,   211,   405,   674,   214,
     227,   228,   613,   426,   231,   232,   428,   680,   234,   235,
     616,   236,   237,   238,   239,   618,   240,   681,   725,   475,
     243,   246,   248,   249,   621,   251,   252,   622,   255,   257,
     258,   623,   260,   261,   741,   264,   265,   463,   685,   270,
     271,   627,   273,   274,   476,   628,   686,   728,   276,   277,
     632,   631,   711,   279,   280,   633,   282,   283,   634,   286,
     288,   289,   635,   291,   292,   294,   295,   298,   301,   310,
     315,   316,   317,   714,   328,   329,   647,   331,   332,   336,
     338,   339,   650,   349,   553,   696,   342,   350,   351,   353,
     354,   655,   360,   362,   363,   568,   569,   659,   365,   366,
     369,   372,   375,   376,   377,   584,   700,   731,   379,   380,
     381,   667,   387,   388,   669,   221,   222,   676,   678,   422,
     610,   611,   224,   225,   689,   509,   639,   640,   303,   304,
     306,   307,   383,   384,   344,   345,   652,   312,   313,   691,
     268,   217,   357,   322,   323,   325,   326,   320
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -390
static const short yypact[] =
{
    -390,    36,    69,  -390,    -6,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,    -5,    89,   130,   214,   473,   229,
    -390,   162,   215,   221,   227,   240,   248,   251,   252,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     267,   268,   269,   274,   275,   279,   280,   281,   285,   286,
     287,   289,   291,   292,   295,   297,   298,   299,   301,   303,
     304,   305,   307,   308,   309,   310,   312,   313,   314,   315,
     319,   320,   322,   323,   327,   329,   330,   331,  -390,  -390,
      57,   140,   108,    19,   207,   266,   270,    75,    78,    21,
      16,   271,   272,   113,   119,   276,   132,    70,    27,   277,
     302,    22,    88,   306,   311,   278,   129,    30,    38,   282,
     283,    77,   107,   284,   316,    32,   288,    44,    52,   104,
      58,   290,   317,    46,   321,    10,   131,   294,    63,   324,
      64,   296,    11,   300,   325,   109,  -390,  -390,  -390,   335,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,   328,   273,   133,
    -390,   336,   332,   136,  -390,   337,   137,   341,   339,  -390,
     143,  -390,   340,  -390,   146,   342,  -390,   147,   343,   293,
    -390,  -390,   150,   344,   345,   128,   346,   348,   351,   349,
    -390,   153,  -390,   350,   352,   338,   353,  -390,  -390,   356,
     226,   354,  -390,   355,   357,  -390,   157,   359,   160,   341,
     360,   361,   362,   363,  -390,   364,   365,   366,   368,   367,
     369,   370,   371,  -390,   163,  -390,   372,  -390,   373,   374,
     375,   378,   376,   377,    72,   380,   164,   351,   381,   382,
     384,   383,   385,   389,   386,  -390,   387,   390,   392,   391,
     393,   167,    72,   395,   170,    72,   396,  -390,   397,   398,
    -390,    65,   399,   400,   247,   401,   402,   128,   403,  -390,
     176,   404,   405,   394,   406,   177,  -390,   226,   407,  -390,
     408,   409,   410,    72,   411,   412,    72,   413,   414,   351,
     474,   475,    72,   476,   477,   379,   478,   479,   480,   415,
     481,  -390,   178,   482,   483,   425,   484,    33,  -390,  -390,
      14,  -390,   485,   486,   423,   487,  -390,   488,   489,  -390,
     179,   490,   491,   430,   492,   493,    72,   494,  -390,   180,
     495,  -390,    15,   496,   497,   186,  -390,   435,   498,   187,
    -390,   442,   499,   501,   247,   440,   502,   503,   448,  -390,
     462,  -390,   570,   500,  -390,   577,  -390,  -390,   578,  -390,
    -390,  -390,   504,  -390,  -390,   576,  -390,   505,  -390,  -390,
     581,  -390,  -390,   582,  -390,   326,  -390,   577,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,   506,  -390,  -390,   580,  -390,
     507,  -390,  -390,  -390,   583,   500,  -390,  -390,  -390,   509,
    -390,   500,  -390,  -390,  -390,   578,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   500,  -390,  -390,  -390,  -390,  -390,
    -390,   513,  -390,   588,  -390,   512,  -390,   500,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,   514,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,    72,  -390,  -390,  -390,    72,  -390,
    -390,  -390,  -390,  -390,   585,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,   594,  -390,  -390,   597,  -390,
    -390,  -390,   516,  -390,   500,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   598,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   599,  -390,   600,  -390,  -390,  -390,  -390,  -390,  -390,
     500,  -390,  -390,  -390,   601,  -390,  -390,   517,  -390,   605,
    -390,  -390,  -390,  -390,  -390,   606,  -390,  -390,  -390,  -390,
     607,  -390,   608,   523,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   577,  -390,
    -390,   341,   332,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
     577,   577,   602,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,   341,  -390,   609,   612,  -390,  -390,  -390,  -390,  -390,
     500,   351,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   577,
     577,  -390,  -390,  -390,   610,   500,   500,  -390,   500,   532,
     318,  -390,  -390,   318,  -390,  -390,  -390,   613,   527,  -390,
     500,  -390,   539,  -390,  -390,   500,  -390,   435,   543,  -390,
     500,  -390,  -390,  -390,   535,  -390,   540,  -390,   541,  -390,
     538,   617,  -390,  -390,   388,   542,   618,  -390,  -390,   545,
     541,   625,  -390,   500,  -390,  -390,   544,  -390,   627,   628,
     631,   626,  -390,  -390,   577,   577,  -390,  -390,   632,  -390,
    -390,  -390,   577,  -390,   550,   500,  -390,  -390,  -390,  -390,
    -390,   500,  -390,  -390,   500,   551,   635,   500,   553,  -390,
    -390,  -390,  -390,   559,  -390,   500,   638,   561,   640,   629,
    -390,  -390
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   230,  -390,
    -390,  -390,  -390,  -390,  -390,   633,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   -86,  -238,  -389,  -390,   -87,  -227,
    -390,  -390,  -390,  -247,  -390,  -390,     0,  -390,  -390,  -390,
    -390,  -390,  -390,  -274,  -390,   216,  -390,  -390,  -390,  -390,
    -390,  -390,   213,  -390,  -390,  -390,  -390,  -390,  -390,  -206,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,   183,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -282,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   528,
    -390,  -122,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -340,  -390,  -390,  -390,  -390,  -124,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,    68,  -390,   -16,  -390,  -390,  -390,    66,
    -390,  -390,  -390,  -390,  -390,   235,  -390,  -390,    17,   347,
    -390,  -390,  -390,  -390,  -390,   333,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -403
static const short yytable[] =
{
     435,   341,   449,   480,   441,   245,   599,   552,   371,   254,
     495,   346,   370,   499,   347,   347,   454,   233,   347,   347,
     208,  -237,   229,   272,  -234,  -227,  -237,  -269,   262,   467,
    -269,   290,  -269,   314,   439,  -292,     3,  -305,  -292,   293,
    -292,   528,  -305,  -295,   531,   321,  -295,   340,  -295,  -400,
     537,  -305,  -400,   324,  -400,   534,  -305,  -402,   197,   330,
    -402,   198,  -402,  -311,   358,   364,  -311,   359,  -311,  -343,
       4,   259,  -343,    13,  -343,    19,   223,   437,   302,   226,
     474,   524,   438,  -258,   572,     5,     6,  -318,  -318,   275,
    -217,   554,   577,  -376,  -376,  -384,  -384,    20,   348,   348,
    -276,  -237,   348,   348,   209,   327,   230,  -269,   305,   205,
     382,   522,   263,   551,   247,  -292,  -308,  -305,   560,  -203,
     250,   348,  -251,  -295,  -247,  -386,  -386,  -388,  -388,  -400,
     287,  -305,   352,   256,  -189,  -255,  -289,  -402,  -329,  -189,
    -332,   201,   503,  -311,   202,  -332,   420,   421,   504,  -343,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,   212,   671,
     391,   213,   636,   397,   400,   392,   637,   136,   398,   401,
     406,   675,   677,   409,   412,   407,   555,   416,   410,   413,
     429,   437,   417,   138,   444,   430,   438,   447,   630,   445,
     464,   478,   448,   140,   493,   465,   479,   497,   578,   494,
     688,   677,   498,   514,   520,   545,   563,   574,   515,   521,
     546,   564,   575,   581,   586,   507,   508,   215,   582,   587,
     216,   218,   241,   244,   219,   242,   202,   253,   266,   284,
     198,   267,   285,   296,   299,   308,   297,   300,   309,   318,
     645,   333,   319,   646,   334,   355,   141,   367,   356,   648,
     368,   373,   142,   269,   374,  -266,   597,   278,   143,  -282,
     694,   600,   281,   695,  -285,   722,   723,   311,   337,  -393,
    -315,   144,   343,   729,  -390,   361,   378,  -335,  -359,   145,
     607,   608,   146,   147,   660,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   665,   433,   159,   160,
     161,     5,   402,   390,   672,   162,   163,   687,   620,   670,
     164,   165,   166,   425,   436,   452,   167,   168,   169,   386,
     170,   458,   171,   172,   682,   673,   173,   415,   174,   175,
     176,   471,   177,   461,   178,   179,   180,   483,   181,   182,
     183,   184,   486,   185,   186,   187,   188,   518,   491,   643,
     189,   190,   708,   191,   192,   389,   348,   604,   193,   693,
     194,   195,   196,   394,   399,   395,   404,   408,   543,   411,
     414,   418,   419,   423,   651,   424,   427,   431,   549,   432,
     558,   440,   442,   567,   443,   434,   446,   450,   451,   583,
     453,   455,   456,   457,   459,   588,   460,   592,   462,   466,
     468,   469,   470,   472,   473,   595,   715,   477,   481,   482,
     484,   539,   485,   487,   488,   721,   596,   489,   724,   490,
     492,   727,   496,   500,   501,   502,   505,   506,   510,   511,
     513,   516,   517,   519,   523,   525,   526,   527,   529,   530,
     532,   533,   735,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
     137,   535,   536,   538,  -313,   540,   541,   542,   544,   547,
     548,   550,   556,   557,   559,   561,   562,   565,   566,   570,
     571,   573,   576,   579,   198,   585,   589,   580,   590,   593,
     594,   219,   202,   598,   603,   605,   606,  -208,   614,   638,
     209,  -234,   230,   612,   619,   624,   625,   263,   641,   629,
     642,   644,   649,   653,   664,   656,   654,   657,   658,  -314,
     661,   662,   374,   683,   679,   684,   697,   698,   692,   699,
     702,   703,   704,   705,   706,   707,   710,   712,   709,   713,
     717,   720,   718,   716,   719,   726,   730,   732,   733,   734,
     736,   737,   738,   739,   740,    18,   615,   617,   626,   335,
     663,   701,   609,   666,   512,     0,     0,   690,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591
};

static const short yycheck[] =
{
     238,   123,   249,   277,   242,    92,   395,   347,   132,    95,
     292,     1,     1,   295,     4,     4,   254,     1,     4,     4,
       1,     5,     1,     1,     8,     9,    10,     5,     1,   267,
       8,     1,    10,     1,   240,     5,     0,     5,     8,     1,
      10,   323,    10,     5,   326,     1,     8,     1,    10,     5,
     332,     5,     8,     1,    10,   329,    10,     5,     1,     1,
       8,     4,    10,     5,     1,     1,     8,     4,    10,     5,
       1,     1,     8,    79,    10,    80,     1,     5,     1,     1,
       8,   319,    10,    13,   366,    16,    17,    77,    77,     1,
      12,    77,    77,    18,    19,    18,    19,     8,    88,    88,
      12,    85,    88,    88,    85,     1,    85,    85,     1,     1,
       1,   317,    85,    80,     1,    85,    12,    85,   356,    11,
       1,    88,     3,    85,    11,    18,    19,    18,    19,    85,
       1,    85,     1,     1,    77,     3,     7,    85,     7,    82,
      77,     1,    77,    85,     4,    82,    18,    19,    83,    85,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     1,   598,
      77,     4,   494,    77,    77,    82,   498,     3,    82,    82,
      77,   610,   611,    77,    77,    82,   350,    77,    82,    82,
      77,     5,    82,     4,    77,    82,    10,    77,   476,    82,
      77,    77,    82,    81,    77,    82,    82,    77,   372,    82,
     639,   640,    82,    77,    77,    77,    77,    77,    82,    82,
      82,    82,    82,    77,    77,    18,    19,     1,    82,    82,
       4,     1,     1,     1,     4,     4,     4,     1,     1,     1,
       4,     4,     4,     1,     1,     1,     4,     4,     4,     1,
     528,     1,     4,   531,     4,     1,    81,     1,     4,   537,
       4,     1,    81,     1,     4,     3,   392,     1,    81,     3,
     650,   398,     1,   653,     3,   704,   705,     1,     1,     3,
       3,    81,     1,   712,     3,     1,     1,     3,     3,    81,
       4,     5,    81,    81,   572,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,   584,     9,    81,    81,
      81,    16,    11,    80,   601,    81,    81,   631,   445,   597,
      81,    81,    81,    12,     8,     3,    81,    81,    81,   139,
      81,     3,    81,    81,   621,   602,    81,    84,    81,    81,
      81,     3,    81,    13,    81,    81,    81,     3,    81,    81,
      81,    81,     3,    81,    81,    81,    81,     3,     7,   521,
      81,    81,    14,    81,    81,    77,    88,   407,    81,   647,
      81,    81,    81,    77,    77,    83,    77,    77,     3,    77,
      77,    77,    77,    77,   546,    77,    77,    77,     3,    77,
       7,    77,    77,     3,    77,    82,    77,    77,    77,     4,
      77,    77,    77,    77,    77,     3,    77,     7,    77,    77,
      77,    77,    77,    77,    77,     7,   694,    77,    77,    77,
      77,    82,    77,    77,    77,   703,     4,    77,   706,    77,
      77,   709,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,   730,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,     4,    77,    77,    80,    77,    77,
      77,     4,     4,    83,     8,     4,     4,    83,     8,     4,
      85,     8,    85,    87,    85,    82,     8,    85,     4,    85,
       3,    85,     4,     4,    81,     4,     6,    90,     3,    77,
       4,     4,     4,     4,    12,     3,     3,    90,     8,    80,
      77,    86,    82,    82,    86,     8,     8,    82,    86,     4,
       3,     5,     4,    89,     3,     3,    86,    86,     3,    86,
      81,     3,    81,     3,    15,    12,   430,   434,   465,   121,
     582,   667,   417,   587,   307,    -1,    -1,   640,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   384
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    92,    93,     0,     1,    16,    17,    94,    95,    96,
      99,   101,   102,    79,   100,    97,   106,   103,   106,    80,
       8,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     3,    77,     4,    98,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,     1,     4,   164,
     165,     1,     4,   168,   169,     1,   171,   172,     1,    85,
     176,   177,     1,     4,   180,     1,     4,   322,     1,     4,
     167,   296,   297,     1,   303,   304,     1,   181,   182,     1,
      85,   185,   186,     1,   189,   190,   192,   193,   194,   195,
     197,     1,     4,   201,     1,   169,   202,     1,   203,   204,
       1,   206,   207,     1,   165,   209,     1,   210,   211,     1,
     213,   214,     1,    85,   216,   217,     1,     4,   321,     1,
     220,   221,     1,   223,   224,     1,   229,   230,     1,   234,
     235,     1,   237,   238,     1,     4,   240,     1,   241,   242,
       1,   244,   245,     1,   246,   247,     1,     4,   248,     1,
       4,   249,     1,   309,   310,     1,   311,   312,     1,     4,
     250,     1,   318,   319,     1,   251,   252,   253,     1,     4,
     328,     1,   324,   325,     1,   326,   327,     1,   255,   256,
       1,   258,   259,     1,     4,   250,   260,     1,   261,   262,
       1,   252,   267,     1,   315,   316,     1,     4,    88,   264,
     268,   269,     1,   270,   271,     1,     4,   323,     1,     4,
     273,     1,   274,   275,     1,   279,   280,     1,     4,   281,
       1,   269,   282,     1,     4,   283,   284,   285,     1,   289,
     290,   291,     1,   313,   314,   104,    99,   293,   294,    77,
      80,    77,    82,   166,    77,    83,   170,    77,    82,    77,
      77,    82,    11,   174,    77,   178,    77,    82,    77,    77,
      82,    77,    77,    82,    77,    84,    77,    82,    77,    77,
      18,    19,   300,    77,    77,    12,   184,    77,   187,    77,
      82,    77,    77,     9,    82,   166,     8,     5,    10,   200,
      77,   166,    77,    77,    77,    82,    77,    77,    82,   174,
      77,    77,     3,    77,   166,    77,    77,    77,     3,    77,
      77,    13,    77,   218,    77,    82,    77,   166,    77,    77,
      77,     3,    77,    77,     8,   200,   225,    77,    77,    82,
     184,    77,    77,     3,    77,    77,     3,    77,    77,    77,
      77,     7,    77,    77,    82,   225,    77,    77,    82,   225,
      77,    77,    77,    77,    83,    77,    77,    18,    19,   306,
      77,    77,   300,    77,    77,    82,    77,    77,     3,    77,
      77,    82,   200,    77,   166,    77,    77,    77,   225,    77,
      77,   225,    77,    77,   184,    77,    77,   225,    77,    82,
      77,    77,    77,     3,    77,    77,    82,    77,    77,     3,
      77,    80,   264,   265,    77,   269,    77,    77,     7,    77,
     166,    77,    77,    77,    82,    77,    77,     3,   276,   277,
      77,    77,   225,    77,    77,    82,    77,    77,   269,    77,
      80,    77,    82,     4,   286,    77,    77,    82,     3,    77,
      77,   306,     7,    77,    77,     7,     4,   165,    83,   167,
     169,   173,   175,     8,   177,     4,     4,     4,     5,   296,
     301,   302,    87,   183,     8,   186,   191,   193,   196,    85,
     169,   205,   208,   212,    82,     8,   217,   222,   226,    85,
     166,   232,   231,   236,   239,   243,   225,   225,     4,   307,
     308,     4,     3,   252,    85,   166,   166,   257,   166,     4,
     263,   252,   317,     4,     6,   272,     4,    90,     3,   278,
     166,     4,     4,   284,    81,   166,   290,   292,   105,   295,
     166,   167,   174,   170,   179,   167,   298,   167,   299,    12,
     188,   198,   174,     4,     3,   219,   227,   184,   167,   305,
     299,   320,     8,   166,   264,   264,   266,     3,    90,    80,
     287,   286,    77,    86,    82,    82,    86,     8,    14,    86,
       8,   233,    82,     4,   254,   166,    89,     3,     4,     3,
       5,   166,   167,   167,   166,   199,     3,   166,   228,   167,
      86,   288,    86,     3,    86,   166,    81,     3,    81,     3,
      15,   215
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
#line 158 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1628 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 159 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1633 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 160 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1638 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 161 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1643 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 162 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1648 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 163 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1653 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 164 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1658 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 165 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1663 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 166 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1668 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 167 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1673 "parser.cxx"
        break;
      case 76: /* T_HDR_UNKNOWN */
#line 168 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1678 "parser.cxx"
        break;
      case 99: /* sip_version */
#line 227 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1683 "parser.cxx"
        break;
      case 165: /* media_range */
#line 221 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_media); delete yyvaluep->yyt_media; };
#line 1688 "parser.cxx"
        break;
      case 166: /* parameters */
#line 223 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1693 "parser.cxx"
        break;
      case 167: /* parameter */
#line 222 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_param); delete yyvaluep->yyt_param; };
#line 1698 "parser.cxx"
        break;
      case 169: /* content_coding */
#line 210 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_coding); delete yyvaluep->yyt_coding; };
#line 1703 "parser.cxx"
        break;
      case 174: /* language */
#line 220 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_language); delete yyvaluep->yyt_language; };
#line 1708 "parser.cxx"
        break;
      case 177: /* alert_param */
#line 202 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_alert_param); delete yyvaluep->yyt_alert_param; };
#line 1713 "parser.cxx"
        break;
      case 184: /* call_id */
#line 204 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1718 "parser.cxx"
        break;
      case 186: /* info_param */
#line 219 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_info_param); delete yyvaluep->yyt_info_param; };
#line 1723 "parser.cxx"
        break;
      case 192: /* contacts */
#line 209 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contacts); delete yyvaluep->yyt_contacts; };
#line 1728 "parser.cxx"
        break;
      case 193: /* contact_param */
#line 208 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1733 "parser.cxx"
        break;
      case 194: /* contact_addr */
#line 207 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1738 "parser.cxx"
        break;
      case 200: /* display_name */
#line 214 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1743 "parser.cxx"
        break;
      case 217: /* error_param */
#line 215 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_error_param); delete yyvaluep->yyt_error_param; };
#line 1748 "parser.cxx"
        break;
      case 225: /* from_addr */
#line 216 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_from_addr); delete yyvaluep->yyt_from_addr; };
#line 1753 "parser.cxx"
        break;
      case 252: /* rec_route */
#line 224 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_route); delete yyvaluep->yyt_route; };
#line 1758 "parser.cxx"
        break;
      case 264: /* comment */
#line 206 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1763 "parser.cxx"
        break;
      case 269: /* server */
#line 226 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_server); delete yyvaluep->yyt_server; };
#line 1768 "parser.cxx"
        break;
      case 284: /* via_parm */
#line 228 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1773 "parser.cxx"
        break;
      case 285: /* sent_protocol */
#line 225 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1778 "parser.cxx"
        break;
      case 286: /* host */
#line 218 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1783 "parser.cxx"
        break;
      case 290: /* warning */
#line 229 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_warning); delete yyvaluep->yyt_warning; };
#line 1788 "parser.cxx"
        break;
      case 293: /* hdr_unknown */
#line 217 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1793 "parser.cxx"
        break;
      case 298: /* digest_response */
#line 213 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_resp); delete yyvaluep->yyt_dig_resp; };
#line 1798 "parser.cxx"
        break;
      case 299: /* auth_params */
#line 203 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1803 "parser.cxx"
        break;
      case 300: /* credentials */
#line 211 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_credentials); delete yyvaluep->yyt_credentials; };
#line 1808 "parser.cxx"
        break;
      case 305: /* digest_challenge */
#line 212 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_chlg); delete yyvaluep->yyt_dig_chlg; };
#line 1813 "parser.cxx"
        break;
      case 306: /* challenge */
#line 205 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_challenge); delete yyvaluep->yyt_challenge; };
#line 1818 "parser.cxx"
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
#line 232 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 237 "parser.yxx"
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
#line 257 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 8:
#line 266 "parser.yxx"
    { CTXT_URI; }
    break;

  case 9:
#line 266 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 10:
#line 267 "parser.yxx"
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
#line 284 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 12:
#line 284 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 13:
#line 288 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 14:
#line 295 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 15:
#line 295 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 16:
#line 296 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 17:
#line 296 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *yyvsp[-6].yyt_str;
			((t_response *)MSG)->code = yyvsp[-4].yyt_ulong;
			((t_response *)MSG)->reason = trim(*yyvsp[-2].yyt_str);
			MEMMAN_DELETE(yyvsp[-6].yyt_str); delete yyvsp[-6].yyt_str;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 76:
#line 366 "parser.yxx"
    {
			MSG->add_unknown_header(*yyvsp[-3].yyt_str, trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 77:
#line 371 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 78:
#line 373 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 79:
#line 375 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 80:
#line 377 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 81:
#line 379 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 82:
#line 381 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 83:
#line 383 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 84:
#line 385 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 85:
#line 387 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 86:
#line 389 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 87:
#line 391 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 88:
#line 393 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 89:
#line 395 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 90:
#line 397 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 91:
#line 399 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 92:
#line 401 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 93:
#line 403 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 94:
#line 405 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 95:
#line 407 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 96:
#line 409 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 97:
#line 411 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 98:
#line 413 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 99:
#line 415 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 100:
#line 417 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 101:
#line 419 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 102:
#line 421 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 103:
#line 423 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 104:
#line 425 "parser.yxx"
    { PARSE_ERROR("P-Asserted-Identity"); }
    break;

  case 105:
#line 427 "parser.yxx"
    { PARSE_ERROR("P-Preferred-Identity"); }
    break;

  case 106:
#line 429 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 107:
#line 431 "parser.yxx"
    { PARSE_ERROR("Privacy"); }
    break;

  case 108:
#line 433 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 109:
#line 435 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 110:
#line 437 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 111:
#line 439 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 112:
#line 441 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 113:
#line 443 "parser.yxx"
    { PARSE_ERROR("Refer-Sub"); }
    break;

  case 114:
#line 445 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 115:
#line 447 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 116:
#line 449 "parser.yxx"
    { PARSE_ERROR("Replaces"); }
    break;

  case 117:
#line 451 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 118:
#line 453 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 119:
#line 455 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 120:
#line 457 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 121:
#line 459 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 122:
#line 461 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 123:
#line 463 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 124:
#line 465 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 125:
#line 467 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 126:
#line 469 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 127:
#line 471 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 128:
#line 473 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 129:
#line 475 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 130:
#line 477 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 131:
#line 479 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 132:
#line 481 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 135:
#line 497 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 140:
#line 507 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 141:
#line 509 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 143:
#line 513 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 146:
#line 519 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 147:
#line 521 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 149:
#line 525 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 150:
#line 527 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 153:
#line 533 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 154:
#line 535 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 155:
#line 537 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 156:
#line 539 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 157:
#line 541 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 159:
#line 545 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 160:
#line 547 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 161:
#line 549 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 164:
#line 555 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 165:
#line 557 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 167:
#line 561 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 168:
#line 563 "parser.yxx"
    { CTXT_URI; }
    break;

  case 170:
#line 567 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 171:
#line 569 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 172:
#line 571 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 173:
#line 573 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 175:
#line 577 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 176:
#line 579 "parser.yxx"
    { CTXT_URI; }
    break;

  case 177:
#line 581 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 179:
#line 585 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 182:
#line 591 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 183:
#line 593 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 187:
#line 601 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 188:
#line 603 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 190:
#line 607 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 191:
#line 612 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 192:
#line 619 "parser.yxx"
    { yyval.yyt_media = new t_media(tolower(*yyvsp[-2].yyt_str), tolower(*yyvsp[0].yyt_str));
					MEMMAN_NEW(yyval.yyt_media);
					MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
					MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 193:
#line 625 "parser.yxx"
    { yyval.yyt_params = new list<t_parameter>; MEMMAN_NEW(yyval.yyt_params); }
    break;

  case 194:
#line 626 "parser.yxx"
    {
			yyvsp[-2].yyt_params->push_back(*yyvsp[0].yyt_param);
			yyval.yyt_params = yyvsp[-2].yyt_params;
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 195:
#line 632 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 196:
#line 636 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 197:
#line 641 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-2].yyt_str), *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 198:
#line 648 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 199:
#line 651 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 200:
#line 656 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 201:
#line 660 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[-1].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			yyval.yyt_coding->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 202:
#line 667 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name != "q") YYERROR;
			yyval.yyt_float = atof(yyvsp[0].yyt_param->value.c_str());
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
			}
    break;

  case 203:
#line 674 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 204:
#line 674 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 205:
#line 677 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 206:
#line 677 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 207:
#line 682 "parser.yxx"
    {
			CTXT_INITIAL;
		  	yyval.yyt_language = new t_language(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 208:
#line 687 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 209:
#line 687 "parser.yxx"
    {
			yyval.yyt_language = new t_language(tolower(*yyvsp[-2].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			yyval.yyt_language->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 210:
#line 694 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 211:
#line 697 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 212:
#line 702 "parser.yxx"
    { CTXT_URI; }
    break;

  case 213:
#line 702 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 214:
#line 702 "parser.yxx"
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

  case 215:
#line 717 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 216:
#line 720 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 217:
#line 725 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 218:
#line 725 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 219:
#line 725 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 220:
#line 730 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 221:
#line 731 "parser.yxx"
    {
			yyval.yyt_str = new string(*yyvsp[-2].yyt_str + '@' + *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 222:
#line 738 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 223:
#line 741 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 224:
#line 746 "parser.yxx"
    { CTXT_URI; }
    break;

  case 225:
#line 746 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 226:
#line 746 "parser.yxx"
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

  case 227:
#line 761 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 228:
#line 761 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 229:
#line 761 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 230:
#line 763 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*yyvsp[0].yyt_contacts);
			MEMMAN_DELETE(yyvsp[0].yyt_contacts); delete yyvsp[0].yyt_contacts; }
    break;

  case 231:
#line 768 "parser.yxx"
    {
			yyval.yyt_contacts = new list<t_contact_param>;
			MEMMAN_NEW(yyval.yyt_contacts);
			yyval.yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 232:
#line 773 "parser.yxx"
    {
			yyvsp[-2].yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			yyval.yyt_contacts = yyvsp[-2].yyt_contacts;
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 233:
#line 779 "parser.yxx"
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

  case 234:
#line 795 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 235:
#line 795 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 236:
#line 795 "parser.yxx"
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

  case 237:
#line 806 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 238:
#line 806 "parser.yxx"
    { CTXT_URI; }
    break;

  case 239:
#line 806 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 240:
#line 806 "parser.yxx"
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

  case 241:
#line 821 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 242:
#line 822 "parser.yxx"
    {
			yyval.yyt_str = new string(rtrim(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 243:
#line 826 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 244:
#line 829 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*yyvsp[-1].yyt_str));
			MSG->hdr_content_disp.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 245:
#line 836 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 246:
#line 839 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 247:
#line 844 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 248:
#line 844 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 249:
#line 847 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 250:
#line 847 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 251:
#line 852 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 252:
#line 852 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 253:
#line 852 "parser.yxx"
    {
			MSG->hdr_content_length.set_length(yyvsp[-1].yyt_ulong); }
    break;

  case 254:
#line 856 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_content_type.set_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 255:
#line 863 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 256:
#line 863 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 257:
#line 863 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr(yyvsp[-2].yyt_ulong);
			MSG->hdr_cseq.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 258:
#line 869 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 259:
#line 872 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 260:
#line 872 "parser.yxx"
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

  case 261:
#line 883 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 262:
#line 886 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 263:
#line 891 "parser.yxx"
    { CTXT_URI; }
    break;

  case 264:
#line 891 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 265:
#line 891 "parser.yxx"
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

  case 266:
#line 906 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 267:
#line 906 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 268:
#line 906 "parser.yxx"
    {
			MSG->hdr_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 269:
#line 910 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 270:
#line 910 "parser.yxx"
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

  case 271:
#line 925 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 272:
#line 925 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_identity();
			MEMMAN_NEW(yyval.yyt_from_addr);
			yyval.yyt_from_addr->set_uri(*yyvsp[-1].yyt_str);

			if (!yyval.yyt_from_addr->uri.is_valid()) {
				MEMMAN_DELETE(yyval.yyt_from_addr); delete yyval.yyt_from_addr;
				YYERROR;
			}
			
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 273:
#line 936 "parser.yxx"
    { CTXT_URI; }
    break;

  case 274:
#line 936 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 275:
#line 936 "parser.yxx"
    {
			yyval.yyt_from_addr = new t_identity();
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

  case 276:
#line 951 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 277:
#line 951 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 278:
#line 951 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 279:
#line 954 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 280:
#line 954 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 281:
#line 954 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 282:
#line 959 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 283:
#line 959 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 284:
#line 959 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards(yyvsp[-1].yyt_ulong); }
    break;

  case 285:
#line 963 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 286:
#line 963 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 287:
#line 963 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 288:
#line 967 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 289:
#line 972 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 290:
#line 972 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 291:
#line 972 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 292:
#line 977 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 293:
#line 977 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 294:
#line 980 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 295:
#line 985 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 296:
#line 985 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 297:
#line 988 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 298:
#line 993 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 299:
#line 998 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 300:
#line 1001 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 301:
#line 1006 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 302:
#line 1009 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 303:
#line 1014 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 304:
#line 1017 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 305:
#line 1022 "parser.yxx"
    { CTXT_URI; }
    break;

  case 306:
#line 1022 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 307:
#line 1023 "parser.yxx"
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

  case 308:
#line 1040 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 309:
#line 1040 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 310:
#line 1040 "parser.yxx"
    {
			MSG->hdr_replaces.set_call_id(*yyvsp[-2].yyt_str);
			
			list<t_parameter>::const_iterator i;
			for (i = yyvsp[0].yyt_params->begin(); i != yyvsp[0].yyt_params->end(); i++) {
				if (i->name == "to-tag") {
					MSG->hdr_replaces.set_to_tag(i->value);
				} else if (i->name == "from-tag") {
					MSG->hdr_replaces.set_from_tag(i->value);
				} else if (i->name == "early-only") {
					MSG->hdr_replaces.set_early_only(true);
				} else {
					MSG->hdr_replaces.add_param(*i);
				}
			}
			
			if (!MSG->hdr_replaces.is_valid()) YYERROR;
			
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 311:
#line 1062 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 312:
#line 1062 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_reply_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_reply_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 313:
#line 1070 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 314:
#line 1073 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 315:
#line 1078 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 316:
#line 1078 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 317:
#line 1078 "parser.yxx"
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

  case 318:
#line 1094 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 319:
#line 1095 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 320:
#line 1095 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 321:
#line 1095 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[-2].yyt_str; }
    break;

  case 322:
#line 1099 "parser.yxx"
    {
			MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 323:
#line 1102 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 324:
#line 1107 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 325:
#line 1110 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 326:
#line 1115 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 327:
#line 1120 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 328:
#line 1127 "parser.yxx"
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

  case 329:
#line 1138 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 330:
#line 1138 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 331:
#line 1138 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 332:
#line 1143 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 333:
#line 1145 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 334:
#line 1148 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 335:
#line 1153 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 336:
#line 1153 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 337:
#line 1156 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[0].yyt_float); }
    break;

  case 338:
#line 1158 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[-1].yyt_float);
			MSG->hdr_timestamp.set_delay(yyvsp[0].yyt_float); }
    break;

  case 339:
#line 1163 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 340:
#line 1164 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 341:
#line 1169 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 342:
#line 1170 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 343:
#line 1175 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 344:
#line 1175 "parser.yxx"
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

  case 345:
#line 1190 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 346:
#line 1193 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 347:
#line 1198 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 348:
#line 1201 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 349:
#line 1206 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 350:
#line 1209 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 351:
#line 1214 "parser.yxx"
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

  case 352:
#line 1242 "parser.yxx"
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

  case 353:
#line 1253 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 354:
#line 1258 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 355:
#line 1258 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 356:
#line 1258 "parser.yxx"
    {
			if (yyvsp[-1].yyt_ulong > 65535) YYERROR;
			
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[-4].yyt_str;
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 357:
#line 1268 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 358:
#line 1271 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 359:
#line 1276 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 360:
#line 1276 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 361:
#line 1276 "parser.yxx"
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

  case 362:
#line 1287 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 363:
#line 1287 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 364:
#line 1287 "parser.yxx"
    { yyval.yyt_str = yyvsp[-1].yyt_str; }
    break;

  case 365:
#line 1290 "parser.yxx"
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

  case 368:
#line 1314 "parser.yxx"
    {
			yyval.yyt_dig_resp = new t_digest_response();
			MEMMAN_NEW(yyval.yyt_dig_resp);
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyval.yyt_dig_resp); delete yyval.yyt_dig_resp;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 369:
#line 1322 "parser.yxx"
    {
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 370:
#line 1329 "parser.yxx"
    {
			yyval.yyt_params = new list<t_parameter>;
			MEMMAN_NEW(yyval.yyt_params);
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 371:
#line 1334 "parser.yxx"
    {
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 372:
#line 1339 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 373:
#line 1339 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = AUTH_DIGEST;
			yyval.yyt_credentials->digest_response = *yyvsp[0].yyt_dig_resp;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_resp); delete yyvsp[0].yyt_dig_resp; }
    break;

  case 374:
#line 1345 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 375:
#line 1345 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_credentials->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 376:
#line 1354 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 377:
#line 1354 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*yyvsp[0].yyt_credentials);
			MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 378:
#line 1359 "parser.yxx"
    {
			yyval.yyt_dig_chlg = new t_digest_challenge();
			MEMMAN_NEW(yyval.yyt_dig_chlg);
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyval.yyt_dig_chlg); delete yyval.yyt_dig_chlg;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 379:
#line 1367 "parser.yxx"
    {
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 380:
#line 1374 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 381:
#line 1374 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = AUTH_DIGEST;
			yyval.yyt_challenge->digest_challenge = *yyvsp[0].yyt_dig_chlg;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_chlg); delete yyvsp[0].yyt_dig_chlg; }
    break;

  case 382:
#line 1380 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 383:
#line 1380 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_challenge->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 384:
#line 1389 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 385:
#line 1389 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 386:
#line 1394 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 387:
#line 1394 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*yyvsp[0].yyt_credentials);
				MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 388:
#line 1400 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 389:
#line 1400 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 390:
#line 1405 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 391:
#line 1405 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 392:
#line 1405 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr(yyvsp[-1].yyt_ulong); }
    break;

  case 393:
#line 1409 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 394:
#line 1409 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 395:
#line 1409 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr(yyvsp[-3].yyt_ulong);
			MSG->hdr_rack.set_cseq_nr(yyvsp[-2].yyt_ulong);
			MSG->hdr_rack.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 396:
#line 1416 "parser.yxx"
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

  case 397:
#line 1430 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 398:
#line 1433 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 399:
#line 1438 "parser.yxx"
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
					} else if (i->name == "retry-after") {
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

  case 400:
#line 1464 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 401:
#line 1464 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_refer_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_refer_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 402:
#line 1472 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 403:
#line 1472 "parser.yxx"
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

  case 404:
#line 1487 "parser.yxx"
    {
			string value(tolower(*yyvsp[-1].yyt_str));
			if (value != "true" && value != "false") {
				YYERROR;
			}
			MSG->hdr_refer_sub.set_create_refer_sub(value == "true");
			MSG->hdr_refer_sub.set_extensions(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;


    }

/* Line 991 of yacc.c.  */
#line 4322 "parser.cxx"

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


#line 1497 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

