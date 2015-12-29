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
     T_IPV6ADDR = 275,
     T_PARAMVAL = 276,
     T_HDR_ACCEPT = 277,
     T_HDR_ACCEPT_ENCODING = 278,
     T_HDR_ACCEPT_LANGUAGE = 279,
     T_HDR_ALERT_INFO = 280,
     T_HDR_ALLOW = 281,
     T_HDR_ALLOW_EVENTS = 282,
     T_HDR_AUTHENTICATION_INFO = 283,
     T_HDR_AUTHORIZATION = 284,
     T_HDR_CALL_ID = 285,
     T_HDR_CALL_INFO = 286,
     T_HDR_CONTACT = 287,
     T_HDR_CONTENT_DISP = 288,
     T_HDR_CONTENT_ENCODING = 289,
     T_HDR_CONTENT_LANGUAGE = 290,
     T_HDR_CONTENT_LENGTH = 291,
     T_HDR_CONTENT_TYPE = 292,
     T_HDR_CSEQ = 293,
     T_HDR_DATE = 294,
     T_HDR_ERROR_INFO = 295,
     T_HDR_EVENT = 296,
     T_HDR_EXPIRES = 297,
     T_HDR_FROM = 298,
     T_HDR_IN_REPLY_TO = 299,
     T_HDR_MAX_FORWARDS = 300,
     T_HDR_MIN_EXPIRES = 301,
     T_HDR_MIME_VERSION = 302,
     T_HDR_ORGANIZATION = 303,
     T_HDR_P_ASSERTED_IDENTITY = 304,
     T_HDR_P_PREFERRED_IDENTITY = 305,
     T_HDR_PRIORITY = 306,
     T_HDR_PRIVACY = 307,
     T_HDR_PROXY_AUTHENTICATE = 308,
     T_HDR_PROXY_AUTHORIZATION = 309,
     T_HDR_PROXY_REQUIRE = 310,
     T_HDR_RACK = 311,
     T_HDR_RECORD_ROUTE = 312,
     T_HDR_REFER_SUB = 313,
     T_HDR_REFER_TO = 314,
     T_HDR_REFERRED_BY = 315,
     T_HDR_REPLACES = 316,
     T_HDR_REPLY_TO = 317,
     T_HDR_REQUIRE = 318,
     T_HDR_RETRY_AFTER = 319,
     T_HDR_ROUTE = 320,
     T_HDR_RSEQ = 321,
     T_HDR_SERVER = 322,
     T_HDR_SUBJECT = 323,
     T_HDR_SUBSCRIPTION_STATE = 324,
     T_HDR_SUPPORTED = 325,
     T_HDR_TIMESTAMP = 326,
     T_HDR_TO = 327,
     T_HDR_UNSUPPORTED = 328,
     T_HDR_USER_AGENT = 329,
     T_HDR_VIA = 330,
     T_HDR_WARNING = 331,
     T_HDR_WWW_AUTHENTICATE = 332,
     T_HDR_UNKNOWN = 333,
     T_CRLF = 334,
     T_ERROR = 335,
     T_NULL = 336
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
#define T_IPV6ADDR 275
#define T_PARAMVAL 276
#define T_HDR_ACCEPT 277
#define T_HDR_ACCEPT_ENCODING 278
#define T_HDR_ACCEPT_LANGUAGE 279
#define T_HDR_ALERT_INFO 280
#define T_HDR_ALLOW 281
#define T_HDR_ALLOW_EVENTS 282
#define T_HDR_AUTHENTICATION_INFO 283
#define T_HDR_AUTHORIZATION 284
#define T_HDR_CALL_ID 285
#define T_HDR_CALL_INFO 286
#define T_HDR_CONTACT 287
#define T_HDR_CONTENT_DISP 288
#define T_HDR_CONTENT_ENCODING 289
#define T_HDR_CONTENT_LANGUAGE 290
#define T_HDR_CONTENT_LENGTH 291
#define T_HDR_CONTENT_TYPE 292
#define T_HDR_CSEQ 293
#define T_HDR_DATE 294
#define T_HDR_ERROR_INFO 295
#define T_HDR_EVENT 296
#define T_HDR_EXPIRES 297
#define T_HDR_FROM 298
#define T_HDR_IN_REPLY_TO 299
#define T_HDR_MAX_FORWARDS 300
#define T_HDR_MIN_EXPIRES 301
#define T_HDR_MIME_VERSION 302
#define T_HDR_ORGANIZATION 303
#define T_HDR_P_ASSERTED_IDENTITY 304
#define T_HDR_P_PREFERRED_IDENTITY 305
#define T_HDR_PRIORITY 306
#define T_HDR_PRIVACY 307
#define T_HDR_PROXY_AUTHENTICATE 308
#define T_HDR_PROXY_AUTHORIZATION 309
#define T_HDR_PROXY_REQUIRE 310
#define T_HDR_RACK 311
#define T_HDR_RECORD_ROUTE 312
#define T_HDR_REFER_SUB 313
#define T_HDR_REFER_TO 314
#define T_HDR_REFERRED_BY 315
#define T_HDR_REPLACES 316
#define T_HDR_REPLY_TO 317
#define T_HDR_REQUIRE 318
#define T_HDR_RETRY_AFTER 319
#define T_HDR_ROUTE 320
#define T_HDR_RSEQ 321
#define T_HDR_SERVER 322
#define T_HDR_SUBJECT 323
#define T_HDR_SUBSCRIPTION_STATE 324
#define T_HDR_SUPPORTED 325
#define T_HDR_TIMESTAMP 326
#define T_HDR_TO 327
#define T_HDR_UNSUPPORTED 328
#define T_HDR_USER_AGENT 329
#define T_HDR_VIA 330
#define T_HDR_WARNING 331
#define T_HDR_WWW_AUTHENTICATE 332
#define T_HDR_UNKNOWN 333
#define T_CRLF 334
#define T_ERROR 335
#define T_NULL 336




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
#line 281 "parser.cxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 293 "parser.cxx"

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
#define YYLAST   694

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  246
/* YYNRULES -- Number of rules. */
#define YYNRULES  414
/* YYNRULES -- Number of states. */
#define YYNSTATES  755

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   336

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      90,    91,     2,     2,    84,     2,    92,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    85,
      87,    86,    88,     2,    89,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    93,     2,    94,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81
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
     674,   677,   682,   686,   687,   691,   693,   694,   695,   701,
     703,   705,   707,   711,   713,   716,   719,   720,   723,   724,
     729,   731,   732,   736,   738,   742,   743,   744,   751,   753,
     757,   758,   759,   763,   765,   769,   771,   775,   776,   777,
     784,   785,   786,   790,   792,   794,   798,   801,   802,   803,
     807,   808,   809,   810,   818,   819,   821,   823,   826,   828,
     832,   833,   836,   837,   842,   843,   844,   848,   851,   852,
     853,   858,   859,   860,   874,   876,   880,   881,   882,   889,
     890,   891,   895,   896,   900,   901,   904,   905,   906,   913,
     914,   915,   919,   920,   921,   927,   928,   929,   933,   934,
     935,   939,   941,   942,   943,   947,   948,   951,   955,   956,
     959,   963,   965,   967,   971,   973,   977,   979,   983,   984,
     985,   993,   994,   995,  1000,  1001,  1005,  1007,  1011,  1012,
    1013,  1019,  1020,  1021,  1022,  1028,  1030,  1034,  1036,  1039,
    1041,  1044,  1049,  1050,  1051,  1055,  1056,  1058,  1062,  1063,
    1066,  1068,  1071,  1073,  1077,  1079,  1083,  1084,  1088,  1090,
    1094,  1096,  1099,  1101,  1105,  1109,  1115,  1117,  1118,  1119,
    1125,  1127,  1128,  1129,  1135,  1136,  1137,  1143,  1145,  1149,
    1150,  1151,  1157,  1158,  1159,  1163,  1165,  1167,  1171,  1173,
    1177,  1179,  1183,  1184,  1188,  1189,  1193,  1194,  1197,  1199,
    1203,  1204,  1208,  1209,  1213,  1214,  1217,  1218,  1221,  1222,
    1225,  1226,  1227,  1231,  1232,  1233,  1239,  1242,  1244,  1248,
    1251,  1252,  1256,  1257,  1261
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
      96,     0,    -1,    -1,    97,    98,    -1,    99,    -1,   105,
      -1,     1,    81,    -1,   100,   110,    79,    -1,    -1,    -1,
      17,   101,     8,   102,   103,    79,    -1,    -1,    16,   104,
      82,     4,    -1,   106,   110,    79,    -1,    -1,    -1,    -1,
     103,   107,     3,   108,     7,   109,    79,    -1,    -1,   110,
     111,    -1,   112,   168,    79,    -1,   113,   175,    79,    -1,
     114,   178,    79,    -1,   115,   183,    79,    -1,   116,   187,
      79,    -1,   117,   334,    79,    -1,   118,   309,    79,    -1,
     119,   315,    79,    -1,   120,   188,    79,    -1,   121,   192,
      79,    -1,   122,   196,    79,    -1,   123,   208,    79,    -1,
     124,   209,    79,    -1,   125,   210,    79,    -1,   126,   213,
      79,    -1,   127,   216,    79,    -1,   128,   217,    79,    -1,
     129,   220,    79,    -1,   131,   333,    79,    -1,   130,   223,
      79,    -1,   132,   227,    79,    -1,   133,   230,    79,    -1,
     134,   236,    79,    -1,   135,   241,    79,    -1,   136,   244,
      79,    -1,   137,   247,    79,    -1,   138,   248,    79,    -1,
     139,   251,    79,    -1,   140,   253,    79,    -1,   141,   255,
      79,    -1,   142,   256,    79,    -1,   143,   321,    79,    -1,
     144,   323,    79,    -1,   145,   257,    79,    -1,   146,   330,
      79,    -1,   147,   258,    79,    -1,   148,   340,    79,    -1,
     149,   336,    79,    -1,   150,   338,    79,    -1,   151,   262,
      79,    -1,   152,   265,    79,    -1,   153,   267,    79,    -1,
     154,   268,    79,    -1,   155,   274,    79,    -1,   156,   327,
      79,    -1,   157,   275,    79,    -1,   158,   277,    79,    -1,
     159,   335,    79,    -1,   160,   280,    79,    -1,   161,   281,
      79,    -1,   162,   286,    79,    -1,   163,   288,    79,    -1,
     164,   289,    79,    -1,   165,   290,    79,    -1,   166,   301,
      79,    -1,   167,   325,    79,    -1,    78,    83,   305,    79,
      -1,   112,     1,    79,    -1,   113,     1,    79,    -1,   114,
       1,    79,    -1,   115,     1,    79,    -1,   116,     1,    79,
      -1,   117,     1,    79,    -1,   118,     1,    79,    -1,   119,
       1,    79,    -1,   120,     1,    79,    -1,   121,     1,    79,
      -1,   122,     1,    79,    -1,   123,     1,    79,    -1,   124,
       1,    79,    -1,   125,     1,    79,    -1,   126,     1,    79,
      -1,   127,     1,    79,    -1,   128,     1,    79,    -1,   129,
       1,    79,    -1,   130,     1,    79,    -1,   131,     1,    79,
      -1,   132,     1,    79,    -1,   133,     1,    79,    -1,   134,
       1,    79,    -1,   135,     1,    79,    -1,   136,     1,    79,
      -1,   137,     1,    79,    -1,   138,     1,    79,    -1,   139,
       1,    79,    -1,   140,     1,    79,    -1,   141,     1,    79,
      -1,   142,     1,    79,    -1,   143,     1,    79,    -1,   144,
       1,    79,    -1,   145,     1,    79,    -1,   146,     1,    79,
      -1,   147,     1,    79,    -1,   148,     1,    79,    -1,   149,
       1,    79,    -1,   150,     1,    79,    -1,   151,     1,    79,
      -1,   152,     1,    79,    -1,   153,     1,    79,    -1,   154,
       1,    79,    -1,   155,     1,    79,    -1,   156,     1,    79,
      -1,   157,     1,    79,    -1,   158,     1,    79,    -1,   159,
       1,    79,    -1,   160,     1,    79,    -1,   161,     1,    79,
      -1,   162,     1,    79,    -1,   163,     1,    79,    -1,   164,
       1,    79,    -1,   165,     1,    79,    -1,   166,     1,    79,
      -1,   167,     1,    79,    -1,    22,    83,    -1,    23,    83,
      -1,    24,    83,    -1,    25,    83,    -1,    26,    83,    -1,
      27,    83,    -1,    28,    83,    -1,    29,    83,    -1,    30,
      83,    -1,    31,    83,    -1,    32,    83,    -1,    33,    83,
      -1,    34,    83,    -1,    35,    83,    -1,    36,    83,    -1,
      37,    83,    -1,    38,    83,    -1,    39,    83,    -1,    40,
      83,    -1,    41,    83,    -1,    42,    83,    -1,    43,    83,
      -1,    44,    83,    -1,    45,    83,    -1,    46,    83,    -1,
      47,    83,    -1,    48,    83,    -1,    49,    83,    -1,    50,
      83,    -1,    51,    83,    -1,    52,    83,    -1,    53,    83,
      -1,    54,    83,    -1,    55,    83,    -1,    56,    83,    -1,
      57,    83,    -1,    58,    83,    -1,    59,    83,    -1,    60,
      83,    -1,    61,    83,    -1,    62,    83,    -1,    63,    83,
      -1,    64,    83,    -1,    65,    83,    -1,    66,    83,    -1,
      67,    83,    -1,    68,    83,    -1,    69,    83,    -1,    70,
      83,    -1,    71,    83,    -1,    72,    83,    -1,    73,    83,
      -1,    74,    83,    -1,    75,    83,    -1,    76,    83,    -1,
      77,    83,    -1,    -1,   169,   170,    -1,   168,    84,   169,
     170,    -1,     4,    82,     4,    -1,    -1,   170,    85,   171,
      -1,     4,    -1,    -1,    -1,     4,    86,   172,   174,   173,
      -1,    21,    -1,     5,    -1,   176,    -1,   175,    84,   176,
      -1,     4,    -1,     4,   177,    -1,    85,   171,    -1,    -1,
     179,   181,    -1,    -1,   178,    84,   180,   181,    -1,    11,
      -1,    -1,    11,   182,   177,    -1,   184,    -1,   183,    84,
     184,    -1,    -1,    -1,    87,   185,     8,   186,    88,   170,
      -1,     4,    -1,   187,    84,     4,    -1,    -1,    -1,   189,
     191,   190,    -1,    12,    -1,    12,    89,    12,    -1,   193,
      -1,   192,    84,   193,    -1,    -1,    -1,    87,   194,     8,
     195,    88,   170,    -1,    -1,    -1,   197,     9,   198,    -1,
     199,    -1,   200,    -1,   199,    84,   200,    -1,   201,   170,
      -1,    -1,    -1,   202,     8,   203,    -1,    -1,    -1,    -1,
     204,   207,    87,   205,     8,   206,    88,    -1,    -1,    10,
      -1,     5,    -1,     4,   170,    -1,   176,    -1,   209,    84,
     176,    -1,    -1,   211,   181,    -1,    -1,   210,    84,   212,
     181,    -1,    -1,    -1,   214,     3,   215,    -1,   169,   170,
      -1,    -1,    -1,   218,     3,   219,     4,    -1,    -1,    -1,
     221,    13,    84,     3,    14,     3,     3,    83,     3,    83,
       3,    15,   222,    -1,   224,    -1,   223,    84,   224,    -1,
      -1,    -1,    87,   225,     8,   226,    88,   170,    -1,    -1,
      -1,   228,     3,   229,    -1,    -1,   231,   232,   170,    -1,
      -1,     8,   233,    -1,    -1,    -1,   207,    87,   234,     8,
     235,    88,    -1,    -1,    -1,   237,   191,   238,    -1,    -1,
      -1,   236,    84,   239,   191,   240,    -1,    -1,    -1,   242,
       3,   243,    -1,    -1,    -1,   245,     3,   246,    -1,     4,
      -1,    -1,    -1,   249,     7,   250,    -1,    -1,   252,   232,
      -1,   251,    84,   232,    -1,    -1,   254,   232,    -1,   253,
      84,   232,    -1,     4,    -1,     4,    -1,   256,    85,     4,
      -1,     4,    -1,   257,    84,     4,    -1,   259,    -1,   258,
      84,   259,    -1,    -1,    -1,   260,   207,    87,     8,   261,
      88,   170,    -1,    -1,    -1,   263,   191,   264,   170,    -1,
      -1,   266,   232,   170,    -1,     4,    -1,   257,    84,     4,
      -1,    -1,    -1,   269,     3,   270,   271,   170,    -1,    -1,
      -1,    -1,    90,   272,     6,   273,    91,    -1,   259,    -1,
     274,    84,   259,    -1,   276,    -1,   275,   276,    -1,   271,
      -1,     4,   271,    -1,     4,    82,     4,   271,    -1,    -1,
      -1,   278,     7,   279,    -1,    -1,     4,    -1,   280,    84,
       4,    -1,    -1,   282,   283,    -1,   284,    -1,   284,   285,
      -1,     3,    -1,     3,    92,     3,    -1,     3,    -1,     3,
      92,     3,    -1,    -1,   287,   232,   170,    -1,     4,    -1,
     288,    84,     4,    -1,   276,    -1,   289,   276,    -1,   291,
      -1,   290,    84,   291,    -1,   292,   293,   170,    -1,     4,
      82,     4,    82,     4,    -1,     4,    -1,    -1,    -1,     4,
      83,   294,     3,   295,    -1,   298,    -1,    -1,    -1,   298,
      83,   296,     3,   297,    -1,    -1,    -1,    93,   299,    20,
     300,    94,    -1,   302,    -1,   301,    84,   302,    -1,    -1,
      -1,   303,     3,   304,   293,     5,    -1,    -1,    -1,   306,
       7,   307,    -1,   171,    -1,   308,    -1,   309,    84,   308,
      -1,   171,    -1,   310,    84,   171,    -1,   171,    -1,   311,
      84,   171,    -1,    -1,    18,   313,   310,    -1,    -1,    19,
     314,   311,    -1,    -1,   316,   312,    -1,   171,    -1,   317,
      84,   171,    -1,    -1,    18,   319,   317,    -1,    -1,    19,
     320,   311,    -1,    -1,   322,   318,    -1,    -1,   324,   312,
      -1,    -1,   326,   318,    -1,    -1,    -1,   328,     3,   329,
      -1,    -1,    -1,   331,     3,     3,   332,     4,    -1,     4,
     170,    -1,     4,    -1,   334,    84,     4,    -1,     4,   170,
      -1,    -1,   337,   232,   170,    -1,    -1,   339,   232,   170,
      -1,     4,   170,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   240,   240,   240,   243,   244,   245,   265,   274,   274,
     274,   292,   292,   296,   303,   303,   304,   303,   314,   315,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   378,   380,   382,
     384,   386,   388,   390,   392,   394,   396,   398,   400,   402,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   466,   468,   470,   472,   474,   476,   478,   480,   482,
     484,   486,   488,   501,   503,   505,   507,   509,   511,   513,
     515,   517,   519,   521,   523,   525,   527,   529,   531,   533,
     535,   537,   539,   541,   543,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   614,
     615,   620,   627,   633,   634,   640,   644,   644,   644,   651,
     653,   657,   660,   665,   669,   676,   683,   683,   686,   686,
     691,   696,   696,   703,   706,   711,   711,   711,   726,   729,
     734,   734,   734,   739,   740,   747,   750,   755,   755,   755,
     770,   770,   770,   772,   777,   782,   788,   804,   804,   804,
     815,   815,   815,   815,   830,   831,   835,   838,   845,   848,
     853,   853,   856,   856,   861,   861,   861,   865,   872,   872,
     872,   878,   881,   878,   892,   895,   900,   900,   900,   915,
     915,   915,   919,   919,   934,   934,   945,   945,   945,   960,
     960,   960,   963,   963,   963,   968,   968,   968,   972,   972,
     972,   976,   981,   981,   981,   986,   986,   989,   994,   994,
     997,  1002,  1007,  1010,  1015,  1018,  1023,  1026,  1031,  1031,
    1031,  1049,  1049,  1049,  1071,  1071,  1079,  1082,  1087,  1087,
    1087,  1103,  1104,  1104,  1104,  1108,  1111,  1116,  1119,  1124,
    1129,  1136,  1147,  1147,  1147,  1152,  1154,  1157,  1162,  1162,
    1165,  1167,  1172,  1173,  1178,  1179,  1184,  1184,  1199,  1202,
    1207,  1210,  1215,  1218,  1223,  1251,  1262,  1267,  1267,  1267,
    1275,  1280,  1280,  1280,  1288,  1288,  1288,  1295,  1298,  1303,
    1303,  1303,  1314,  1314,  1314,  1317,  1337,  1338,  1341,  1349,
    1356,  1361,  1366,  1366,  1372,  1372,  1381,  1381,  1386,  1394,
    1401,  1401,  1407,  1407,  1416,  1416,  1421,  1421,  1427,  1427,
    1432,  1432,  1432,  1436,  1436,  1436,  1443,  1457,  1460,  1465,
    1491,  1491,  1499,  1499,  1514
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
  "T_AUTH_DIGEST", "T_AUTH_OTHER", "T_IPV6ADDR", "T_PARAMVAL", 
  "T_HDR_ACCEPT", "T_HDR_ACCEPT_ENCODING", "T_HDR_ACCEPT_LANGUAGE", 
  "T_HDR_ALERT_INFO", "T_HDR_ALLOW", "T_HDR_ALLOW_EVENTS", 
  "T_HDR_AUTHENTICATION_INFO", "T_HDR_AUTHORIZATION", "T_HDR_CALL_ID", 
  "T_HDR_CALL_INFO", "T_HDR_CONTACT", "T_HDR_CONTENT_DISP", 
  "T_HDR_CONTENT_ENCODING", "T_HDR_CONTENT_LANGUAGE", 
  "T_HDR_CONTENT_LENGTH", "T_HDR_CONTENT_TYPE", "T_HDR_CSEQ", 
  "T_HDR_DATE", "T_HDR_ERROR_INFO", "T_HDR_EVENT", "T_HDR_EXPIRES", 
  "T_HDR_FROM", "T_HDR_IN_REPLY_TO", "T_HDR_MAX_FORWARDS", 
  "T_HDR_MIN_EXPIRES", "T_HDR_MIME_VERSION", "T_HDR_ORGANIZATION", 
  "T_HDR_P_ASSERTED_IDENTITY", "T_HDR_P_PREFERRED_IDENTITY", 
  "T_HDR_PRIORITY", "T_HDR_PRIVACY", "T_HDR_PROXY_AUTHENTICATE", 
  "T_HDR_PROXY_AUTHORIZATION", "T_HDR_PROXY_REQUIRE", "T_HDR_RACK", 
  "T_HDR_RECORD_ROUTE", "T_HDR_REFER_SUB", "T_HDR_REFER_TO", 
  "T_HDR_REFERRED_BY", "T_HDR_REPLACES", "T_HDR_REPLY_TO", 
  "T_HDR_REQUIRE", "T_HDR_RETRY_AFTER", "T_HDR_ROUTE", "T_HDR_RSEQ", 
  "T_HDR_SERVER", "T_HDR_SUBJECT", "T_HDR_SUBSCRIPTION_STATE", 
  "T_HDR_SUPPORTED", "T_HDR_TIMESTAMP", "T_HDR_TO", "T_HDR_UNSUPPORTED", 
  "T_HDR_USER_AGENT", "T_HDR_VIA", "T_HDR_WARNING", 
  "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", "T_CRLF", "T_ERROR", 
  "T_NULL", "'/'", "':'", "','", "';'", "'='", "'<'", "'>'", "'@'", "'('", 
  "')'", "'.'", "'['", "']'", "$accept", "sip_message", "@1", 
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
  "parameter", "@8", "@9", "parameter_val", "hdr_accept_encoding", 
  "content_coding", "q_factor", "hdr_accept_language", "@10", "@11", 
  "language", "@12", "hdr_alert_info", "alert_param", "@13", "@14", 
  "hdr_allow", "hdr_call_id", "@15", "@16", "call_id", "hdr_call_info", 
  "info_param", "@17", "@18", "hdr_contact", "@19", "@20", "contacts", 
  "contact_param", "contact_addr", "@21", "@22", "@23", "@24", "@25", 
  "display_name", "hdr_content_disp", "hdr_content_encoding", 
  "hdr_content_language", "@26", "@27", "hdr_content_length", "@28", 
  "@29", "hdr_content_type", "hdr_cseq", "@30", "@31", "hdr_date", "@32", 
  "@33", "hdr_error_info", "error_param", "@34", "@35", "hdr_expires", 
  "@36", "@37", "hdr_from", "@38", "from_addr", "@39", "@40", "@41", 
  "hdr_in_reply_to", "@42", "@43", "@44", "@45", "hdr_max_forwards", 
  "@46", "@47", "hdr_min_expires", "@48", "@49", "hdr_mime_version", 
  "hdr_organization", "@50", "@51", "hdr_p_asserted_identity", "@52", 
  "hdr_p_preferred_identity", "@53", "hdr_priority", "hdr_privacy", 
  "hdr_proxy_require", "hdr_record_route", "rec_route", "@54", "@55", 
  "hdr_replaces", "@56", "@57", "hdr_reply_to", "@58", "hdr_require", 
  "hdr_retry_after", "@59", "@60", "comment", "@61", "@62", "hdr_route", 
  "hdr_server", "server", "hdr_subject", "@63", "@64", "hdr_supported", 
  "hdr_timestamp", "@65", "hdr_timestamp1", "timestamp", "delay", 
  "hdr_to", "@66", "hdr_unsupported", "hdr_user_agent", "hdr_via", 
  "via_parm", "sent_protocol", "host", "@67", "@68", "@69", "@70", 
  "ipv6reference", "@71", "@72", "hdr_warning", "warning", "@73", "@74", 
  "hdr_unknown", "@75", "@76", "ainfo", "hdr_authentication_info", 
  "digest_response", "auth_params", "credentials", "@77", "@78", 
  "hdr_authorization", "@79", "digest_challenge", "challenge", "@80", 
  "@81", "hdr_proxy_authenticate", "@82", "hdr_proxy_authorization", 
  "@83", "hdr_www_authenticate", "@84", "hdr_rseq", "@85", "@86", 
  "hdr_rack", "@87", "@88", "hdr_event", "hdr_allow_events", 
  "hdr_subscription_state", "hdr_refer_to", "@89", "hdr_referred_by", 
  "@90", "hdr_refer_sub", 0
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
     335,   336,    47,    58,    44,    59,    61,    60,    62,    64,
      40,    41,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,    95,    97,    96,    98,    98,    98,    99,   101,   102,
     100,   104,   103,   105,   107,   108,   109,   106,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     168,   168,   169,   170,   170,   171,   172,   173,   171,   174,
     174,   175,   175,   176,   176,   177,   179,   178,   180,   178,
     181,   182,   181,   183,   183,   185,   186,   184,   187,   187,
     189,   190,   188,   191,   191,   192,   192,   194,   195,   193,
     197,   198,   196,   196,   199,   199,   200,   202,   203,   201,
     204,   205,   206,   201,   207,   207,   207,   208,   209,   209,
     211,   210,   212,   210,   214,   215,   213,   216,   218,   219,
     217,   221,   222,   220,   223,   223,   225,   226,   224,   228,
     229,   227,   231,   230,   233,   232,   234,   235,   232,   237,
     238,   236,   239,   240,   236,   242,   243,   241,   245,   246,
     244,   247,   249,   250,   248,   252,   251,   251,   254,   253,
     253,   255,   256,   256,   257,   257,   258,   258,   260,   261,
     259,   263,   264,   262,   266,   265,   267,   267,   269,   270,
     268,   271,   272,   273,   271,   274,   274,   275,   275,   276,
     276,   276,   278,   279,   277,   280,   280,   280,   282,   281,
     283,   283,   284,   284,   285,   285,   287,   286,   288,   288,
     289,   289,   290,   290,   291,   292,   293,   294,   295,   293,
     293,   296,   297,   293,   299,   300,   298,   301,   301,   303,
     304,   302,   306,   307,   305,   308,   309,   309,   310,   310,
     311,   311,   313,   312,   314,   312,   316,   315,   317,   317,
     319,   318,   320,   318,   322,   321,   324,   323,   326,   325,
     328,   329,   327,   331,   332,   330,   333,   334,   334,   335,
     337,   336,   339,   338,   340
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
       2,     4,     3,     0,     3,     1,     0,     0,     5,     1,
       1,     1,     3,     1,     2,     2,     0,     2,     0,     4,
       1,     0,     3,     1,     3,     0,     0,     6,     1,     3,
       0,     0,     3,     1,     3,     1,     3,     0,     0,     6,
       0,     0,     3,     1,     1,     3,     2,     0,     0,     3,
       0,     0,     0,     7,     0,     1,     1,     2,     1,     3,
       0,     2,     0,     4,     0,     0,     3,     2,     0,     0,
       4,     0,     0,    13,     1,     3,     0,     0,     6,     0,
       0,     3,     0,     3,     0,     2,     0,     0,     6,     0,
       0,     3,     0,     0,     5,     0,     0,     3,     0,     0,
       3,     1,     0,     0,     3,     0,     2,     3,     0,     2,
       3,     1,     1,     3,     1,     3,     1,     3,     0,     0,
       7,     0,     0,     4,     0,     3,     1,     3,     0,     0,
       5,     0,     0,     0,     5,     1,     3,     1,     2,     1,
       2,     4,     0,     0,     3,     0,     1,     3,     0,     2,
       1,     2,     1,     3,     1,     3,     0,     3,     1,     3,
       1,     2,     1,     3,     3,     5,     1,     0,     0,     5,
       1,     0,     0,     5,     0,     0,     5,     1,     3,     0,
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
     183,   184,   185,   186,   187,   188,   372,     0,     0,     0,
     193,     0,   203,     0,   201,     0,     0,     0,     0,   215,
       0,   213,     0,   218,     0,     0,   407,     0,     0,   195,
     375,   376,     0,     0,     0,     0,     0,     0,     0,     0,
     227,     0,   225,     0,     0,     0,   233,   234,   193,     0,
     244,     0,   193,     0,     0,   248,     0,     0,     0,     0,
       0,     0,     0,     0,   193,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,   264,     0,   193,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,   244,     0,     0,   244,     0,   301,     0,     0,
     302,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,   306,   244,     0,   193,
       0,     0,     0,   244,     0,     0,   244,     0,     0,     0,
       0,     0,   244,     0,   304,     0,     0,     0,     0,     0,
       0,   325,     0,     0,     0,     0,     0,   321,   322,   329,
       0,   327,     0,     0,     0,     0,   193,     0,     0,   336,
       0,     0,     0,     0,     0,     0,   244,     0,   348,     0,
       0,   350,     0,     0,     0,     0,   352,     0,     0,     0,
     367,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,    20,     0,   190,    78,     0,   204,    21,     0,    79,
      22,   208,   210,   207,    80,     0,    23,     0,    81,    24,
       0,    82,    25,     0,    83,   196,    26,     0,    84,    27,
     382,   384,   387,    85,    28,   223,   221,    86,     0,    29,
       0,    87,    30,   231,   240,   236,   238,   246,   245,     0,
      88,   247,    31,    89,    32,     0,    90,    33,   252,   251,
      91,    34,   255,    92,   257,    35,    93,    36,   259,    94,
      37,     0,    95,     0,    39,     0,    96,   406,    38,    97,
      40,   270,    98,    41,   274,     0,   193,    99,    42,   282,
     280,   100,    43,   286,   101,    44,   289,   102,    45,   103,
      46,   293,   104,    47,   244,   296,   105,    48,   244,   299,
     106,    49,   107,    50,     0,   108,    51,   390,   392,   395,
     109,    52,   397,   110,    53,     0,   111,    54,     0,   112,
      55,   308,     0,   113,   414,    56,   114,    57,   193,   115,
      58,   193,   116,    59,   312,   117,    60,   193,   118,     0,
      61,   119,    62,   319,   120,    63,   308,   121,    64,   401,
     122,     0,   330,     0,    65,   328,   123,    66,   333,   124,
     409,    67,   125,    68,     0,   126,    69,   342,   339,   340,
     127,    70,   193,   128,    71,     0,   129,    72,   351,   130,
       0,    73,     0,   356,   364,   193,   360,   131,    74,   369,
     370,   132,    75,   399,    16,    10,    76,   373,   192,   193,
       0,   205,   202,     0,     0,   216,   214,   219,   408,     0,
     377,     0,     0,     0,   222,   228,   226,   232,   235,   239,
     241,   249,     0,   256,     0,     0,   267,   265,   271,   275,
     276,   273,     0,   281,   287,   290,   294,   297,   300,   303,
       0,     0,   305,   404,   307,     0,   411,   413,   193,   315,
     305,   321,   326,   402,   321,   323,   334,   337,     0,   344,
     341,   347,   349,     0,   353,   357,     0,   354,   361,   368,
       0,     0,   374,   191,   194,   209,   212,     0,   200,   199,
     197,   378,   383,   380,   385,   224,     0,     0,   253,   260,
       0,     0,     0,   283,   388,   391,   393,     0,   309,   313,
     193,   331,     0,   343,     0,     0,     0,   365,     0,     0,
      17,   193,   198,     0,     0,   193,   242,     0,   193,   277,
     284,     0,   405,     0,   320,   324,   345,   355,   358,     0,
     362,   371,   217,   379,   381,   229,     0,     0,   268,     0,
     389,   193,   359,   366,   363,   243,     0,   278,   310,     0,
       0,     0,     0,   262,   263
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    15,   139,    10,    14,
      11,    12,    17,   385,   671,    16,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   199,   200,   393,   220,   609,   712,   680,
     203,   204,   396,   206,   207,   603,   403,   604,   210,   211,
     405,   677,   214,   227,   228,   614,   426,   231,   232,   428,
     686,   234,   235,   617,   236,   237,   238,   239,   619,   240,
     687,   736,   475,   243,   246,   248,   249,   622,   251,   252,
     623,   255,   257,   258,   624,   260,   261,   754,   264,   265,
     463,   691,   270,   271,   628,   273,   274,   476,   629,   692,
     739,   276,   277,   633,   632,   720,   279,   280,   634,   282,
     283,   635,   286,   288,   289,   636,   291,   292,   294,   295,
     298,   301,   310,   315,   316,   317,   723,   328,   329,   648,
     331,   332,   336,   338,   339,   651,   349,   553,   702,   342,
     350,   351,   353,   354,   656,   360,   362,   363,   568,   569,
     660,   365,   366,   369,   372,   375,   376,   377,   585,   706,
     742,   708,   744,   586,   666,   729,   379,   380,   381,   670,
     387,   388,   672,   221,   222,   682,   684,   422,   611,   612,
     224,   225,   695,   509,   640,   641,   303,   304,   306,   307,
     383,   384,   344,   345,   653,   312,   313,   697,   268,   217,
     357,   322,   323,   325,   326,   320
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -391
static const short yypact[] =
{
    -391,    54,    31,  -391,   -23,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,    38,   103,   482,    96,   540,   141,
    -391,     9,    72,   124,   130,   152,   159,   164,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   197,   199,   201,
     202,   203,   206,   208,   209,   211,   212,   213,   215,   217,
     218,   219,   220,   221,   223,   225,   226,   227,   232,   233,
     234,   237,   238,   239,   243,   244,   246,   247,   249,   253,
     254,   257,   258,   261,   262,   265,   266,   267,  -391,  -391,
      74,   132,    85,    20,   196,   198,   200,    84,    76,    34,
      17,   204,   205,   116,   242,   210,   245,    70,    37,   214,
     251,    23,    79,   252,   255,   216,    86,    29,    35,   222,
     224,    94,   107,   228,   256,    63,   229,    41,    51,   118,
      52,   230,   259,    64,   260,    10,   128,   235,    75,   263,
      62,   236,    11,   240,   264,   113,  -391,  -391,  -391,   170,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,   140,   142,    58,
    -391,   272,   248,    68,  -391,   273,    77,   268,   274,  -391,
      78,  -391,   275,  -391,    81,   276,  -391,    87,   278,   277,
    -391,  -391,    88,   281,   283,   145,   285,   286,   269,   287,
    -391,    89,  -391,   288,   289,   279,   241,  -391,  -391,   299,
     138,   290,  -391,   291,   292,  -391,    90,   293,    91,   268,
     294,   295,   280,   297,  -391,   298,   300,   301,   284,   302,
     303,   305,   304,  -391,    97,  -391,   306,  -391,   307,   308,
     309,   310,   311,   312,   136,   313,    98,   269,   314,   315,
     316,   317,   318,   325,   319,  -391,   321,   322,   323,   328,
     324,    99,   136,   326,   100,   136,   327,  -391,   329,   330,
    -391,    55,   332,   333,   250,   334,   335,   145,   336,  -391,
     101,   337,   338,   339,   340,   108,  -391,   138,   341,  -391,
     342,   343,   344,   136,   346,   347,   136,   348,   349,   269,
     350,   351,   136,   352,   353,   320,   354,   355,   356,   375,
     357,  -391,   109,   358,   359,   381,   360,    33,  -391,  -391,
      15,  -391,   361,   362,   331,   363,  -391,   364,   365,  -391,
     110,   366,   367,   386,   368,   369,   136,   370,  -391,   111,
     371,  -391,    19,   372,   373,   112,  -391,    13,   374,   119,
    -391,   392,   377,   378,   250,   400,   379,   380,   411,  -391,
     448,  -391,   450,   376,  -391,   456,  -391,  -391,   459,  -391,
    -391,  -391,   382,  -391,  -391,   457,  -391,   383,  -391,  -391,
     460,  -391,  -391,   462,  -391,  -391,  -391,   456,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,   385,  -391,  -391,   461,  -391,
     384,  -391,  -391,  -391,   464,   376,  -391,  -391,  -391,   388,
    -391,   376,  -391,  -391,  -391,   459,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,   376,  -391,  -391,  -391,  -391,  -391,
    -391,   394,  -391,   468,  -391,   395,  -391,   376,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,   396,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,   136,  -391,  -391,  -391,   136,  -391,
    -391,  -391,  -391,  -391,   475,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,   477,  -391,  -391,   465,  -391,
    -391,  -391,   397,  -391,   376,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   481,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,   483,  -391,   480,  -391,  -391,  -391,  -391,  -391,  -391,
     376,  -391,  -391,  -391,   484,  -391,  -391,   398,  -391,   486,
    -391,  -391,  -391,  -391,  -391,   487,  -391,  -391,  -391,  -391,
     488,  -391,   489,   412,  -391,  -391,   413,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
     456,  -391,  -391,   268,   248,  -391,  -391,  -391,  -391,    61,
    -391,   456,   456,   485,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,   268,  -391,   490,   495,  -391,  -391,  -391,  -391,
    -391,   376,   269,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
     456,   456,  -391,  -391,  -391,   491,   376,   376,  -391,   376,
     421,   207,  -391,  -391,   207,  -391,  -391,  -391,   498,   410,
    -391,   376,  -391,   538,  -391,  -391,   601,   376,  -391,  -391,
      13,   543,  -391,   376,  -391,  -391,  -391,   535,  -391,  -391,
    -391,  -391,   541,  -391,   542,  -391,   536,   619,  -391,  -391,
     614,   544,   621,  -391,  -391,   546,   542,   627,  -391,   376,
    -391,  -391,   545,  -391,   630,   631,   634,  -391,   635,   629,
    -391,  -391,  -391,   456,   456,  -391,  -391,   636,  -391,  -391,
    -391,   456,  -391,   552,   376,  -391,  -391,  -391,  -391,   547,
    -391,  -391,   376,  -391,  -391,   376,   554,   640,   376,   556,
    -391,  -391,  -391,  -391,  -391,  -391,   562,  -391,   376,   643,
     564,   645,   637,  -391,  -391
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   510,  -391,
    -391,  -391,  -391,  -391,  -391,   638,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,   -87,  -238,  -390,  -391,  -391,  -391,
    -391,   -86,  -265,  -391,  -391,  -391,  -247,  -391,  -391,   -64,
    -391,  -391,  -391,  -391,  -391,  -391,  -274,  -391,   -84,  -391,
    -391,  -391,  -391,  -391,  -391,   231,  -391,  -391,  -391,  -391,
    -391,  -391,  -220,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   186,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -282,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,   532,  -391,  -122,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -340,  -391,  -391,  -391,
    -391,  -123,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,    73,  -391,   -16,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,    67,  -391,  -391,
    -391,  -391,  -391,   270,  -391,  -391,    16,   387,  -391,  -391,
    -391,  -391,  -391,   282,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -413
static const short yytable[] =
{
     435,   341,   449,   480,   441,   601,   245,   552,   254,   371,
     495,   346,   370,   499,   347,   347,   454,   583,   233,   347,
     439,   208,  -240,   347,   272,  -237,  -230,  -240,  -272,   467,
     290,  -272,     4,  -272,  -295,   229,   293,  -295,   262,  -295,
    -298,   528,   321,  -298,   531,  -298,  -410,     5,     6,  -410,
     537,  -410,   324,   330,     3,   534,  -412,  -314,    13,  -412,
    -314,  -412,  -314,   364,   314,   340,   678,  -346,  -308,  -308,
    -346,   259,  -346,  -308,  -308,   197,   358,   226,   198,   359,
     275,   524,   679,  -261,   572,   223,   205,   287,  -220,  -321,
    -321,  -279,   140,  -292,   554,   302,  -206,   522,   577,   136,
     348,   348,  -386,  -386,  -240,   348,   584,   209,   305,   348,
    -272,    20,  -394,  -394,   382,   551,  -295,   247,   560,   327,
      19,   230,  -298,   348,   263,  -396,  -396,  -250,  -410,   352,
    -311,  -398,  -398,   201,   503,  -332,   202,   391,  -412,  -314,
     504,   437,   392,   437,   474,   138,   438,   397,   438,  -346,
    -308,  -308,   398,  -189,  -335,   141,   400,   406,  -189,  -335,
     409,   401,   407,   420,   421,   410,   412,   416,   429,   444,
     447,   413,   417,   430,   445,   448,   464,   478,   493,   497,
     514,   465,   479,   494,   498,   515,     5,   520,   545,   563,
     574,   581,   521,   546,   564,   575,   582,   212,   588,   215,
     213,   218,   216,   589,   219,   241,   244,   142,   242,   202,
     674,   253,   637,   143,   198,   266,   638,   284,   267,   389,
     285,   681,   683,   296,   390,   299,   297,   555,   300,   308,
     318,   333,   309,   319,   334,   144,   355,   367,   631,   356,
     368,   373,   145,   250,   374,  -254,   256,   146,  -258,   578,
     694,   683,   269,   278,  -269,  -285,   281,   311,  -288,  -403,
     337,   343,  -318,  -400,   361,   378,  -338,  -369,   507,   508,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   402,
     156,   425,   157,   452,   158,   159,   160,   458,   433,   161,
     646,   162,   163,   647,   164,   165,   166,   348,   167,   649,
     168,   169,   170,   171,   172,   599,   173,   436,   174,   175,
     176,   700,   602,   471,   701,   177,   178,   179,   461,   483,
     180,   181,   182,   733,   734,   434,   183,   184,   486,   185,
     186,   740,   187,   395,   661,   491,   188,   189,   558,   676,
     190,   191,   518,   606,   192,   193,   616,   667,   194,   195,
     196,   394,   399,   404,   408,   411,   675,   414,   693,   621,
     418,   673,   419,   415,   423,   424,   427,   431,   432,   440,
     442,   443,   446,   450,   451,   688,   453,   455,   543,   456,
     457,   459,   460,   462,   549,   466,   468,   469,   470,   567,
     472,   473,   477,   481,   482,   590,   484,   485,   487,   644,
     488,   489,   490,   492,   539,   496,   500,   594,   501,   502,
     699,   505,   506,   510,   511,   513,   516,   517,   597,   519,
     523,   525,   526,   527,   652,   529,   530,   532,   533,   535,
     536,   538,  -316,   540,   541,   542,   544,   547,   548,   550,
     556,   557,   559,   561,   562,   565,   566,   570,   571,   573,
     576,   579,   598,   587,   198,   580,   591,   592,   595,   596,
     219,   600,   724,   202,   607,   605,   608,  -211,   643,   615,
     209,   230,  -237,   732,   613,   620,   626,   735,   625,   639,
     738,   642,   263,   630,   645,   650,   655,   654,   657,   659,
     658,   662,   663,   374,   689,   665,   668,   685,   690,   698,
    -317,   703,   704,   748,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   137,
     705,   707,   710,   711,   715,   713,   714,   716,   717,   719,
     721,   722,   718,   726,   731,   727,   725,   728,   730,   737,
     741,   743,   745,   746,   747,   749,   750,   751,   752,   386,
      18,   627,   753,   335,   709,   664,   669,   696,     0,     0,
       0,     0,     0,     0,     0,   618,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   610,     0,     0,
       0,     0,     0,     0,   512
};

static const short yycheck[] =
{
     238,   123,   249,   277,   242,   395,    92,   347,    95,   132,
     292,     1,     1,   295,     4,     4,   254,     4,     1,     4,
     240,     1,     5,     4,     1,     8,     9,    10,     5,   267,
       1,     8,     1,    10,     5,     1,     1,     8,     1,    10,
       5,   323,     1,     8,   326,    10,     5,    16,    17,     8,
     332,    10,     1,     1,     0,   329,     5,     5,    81,     8,
       8,    10,    10,     1,     1,     1,     5,     5,     5,     5,
       8,     1,    10,    10,    10,     1,     1,     1,     4,     4,
       1,   319,    21,    13,   366,     1,     1,     1,    12,    79,
      79,    12,    83,     7,    79,     1,    11,   317,    79,     3,
      90,    90,    18,    19,    87,    90,    93,    87,     1,    90,
      87,     8,    18,    19,     1,    82,    87,     1,   356,     1,
      82,    87,    87,    90,    87,    18,    19,    11,    87,     1,
      12,    18,    19,     1,    79,     7,     4,    79,    87,    87,
      85,     5,    84,     5,     8,     4,    10,    79,    10,    87,
      87,    87,    84,    79,    79,    83,    79,    79,    84,    84,
      79,    84,    84,    18,    19,    84,    79,    79,    79,    79,
      79,    84,    84,    84,    84,    84,    79,    79,    79,    79,
      79,    84,    84,    84,    84,    84,    16,    79,    79,    79,
      79,    79,    84,    84,    84,    84,    84,     1,    79,     1,
       4,     1,     4,    84,     4,     1,     1,    83,     4,     4,
     600,     1,   494,    83,     4,     1,   498,     1,     4,    79,
       4,   611,   612,     1,    82,     1,     4,   350,     4,     1,
       1,     1,     4,     4,     4,    83,     1,     1,   476,     4,
       4,     1,    83,     1,     4,     3,     1,    83,     3,   372,
     640,   641,     1,     1,     3,     3,     1,     1,     3,     3,
       1,     1,     3,     3,     1,     1,     3,     3,    18,    19,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    11,
      83,    12,    83,     3,    83,    83,    83,     3,     9,    83,
     528,    83,    83,   531,    83,    83,    83,    90,    83,   537,
      83,    83,    83,    83,    83,   392,    83,     8,    83,    83,
      83,   651,   398,     3,   654,    83,    83,    83,    13,     3,
      83,    83,    83,   713,   714,    84,    83,    83,     3,    83,
      83,   721,    83,    85,   572,     7,    83,    83,     7,   604,
      83,    83,     3,   407,    83,    83,   430,   585,    83,    83,
      83,    79,    79,    79,    79,    79,   603,    79,   632,   445,
      79,   599,    79,    86,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,   622,    79,    79,     3,    79,
      79,    79,    79,    79,     3,    79,    79,    79,    79,     3,
      79,    79,    79,    79,    79,     3,    79,    79,    79,   521,
      79,    79,    79,    79,    84,    79,    79,     7,    79,    79,
     648,    79,    79,    79,    79,    79,    79,    79,     7,    79,
      79,    79,    79,    79,   546,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,     4,    79,     4,    82,    79,    79,    79,    79,
       4,    85,   700,     4,     4,     8,     4,    85,     3,     8,
      87,    87,     8,   711,    89,    87,     8,   715,    84,     4,
     718,     4,    87,    87,    87,     4,     6,     4,     4,     3,
      92,     4,     4,     4,     4,    83,    83,    12,     3,     8,
      79,     3,    92,   741,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      82,    20,    79,    88,    88,    84,    84,     8,    14,     8,
      84,     4,    88,     3,     5,     4,    91,     3,     3,     3,
      88,    94,    88,     3,    88,    83,     3,    83,     3,   139,
      12,   465,    15,   121,   670,   582,   589,   641,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,
      -1,    -1,    -1,    -1,   307
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    96,    97,     0,     1,    16,    17,    98,    99,   100,
     103,   105,   106,    81,   104,   101,   110,   107,   110,    82,
       8,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,     3,    79,     4,   102,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,     1,     4,   168,
     169,     1,     4,   175,   176,     1,   178,   179,     1,    87,
     183,   184,     1,     4,   187,     1,     4,   334,     1,     4,
     171,   308,   309,     1,   315,   316,     1,   188,   189,     1,
      87,   192,   193,     1,   196,   197,   199,   200,   201,   202,
     204,     1,     4,   208,     1,   176,   209,     1,   210,   211,
       1,   213,   214,     1,   169,   216,     1,   217,   218,     1,
     220,   221,     1,    87,   223,   224,     1,     4,   333,     1,
     227,   228,     1,   230,   231,     1,   236,   237,     1,   241,
     242,     1,   244,   245,     1,     4,   247,     1,   248,   249,
       1,   251,   252,     1,   253,   254,     1,     4,   255,     1,
       4,   256,     1,   321,   322,     1,   323,   324,     1,     4,
     257,     1,   330,   331,     1,   258,   259,   260,     1,     4,
     340,     1,   336,   337,     1,   338,   339,     1,   262,   263,
       1,   265,   266,     1,     4,   257,   267,     1,   268,   269,
       1,   259,   274,     1,   327,   328,     1,     4,    90,   271,
     275,   276,     1,   277,   278,     1,     4,   335,     1,     4,
     280,     1,   281,   282,     1,   286,   287,     1,     4,   288,
       1,   276,   289,     1,     4,   290,   291,   292,     1,   301,
     302,   303,     1,   325,   326,   108,   103,   305,   306,    79,
      82,    79,    84,   170,    79,    85,   177,    79,    84,    79,
      79,    84,    11,   181,    79,   185,    79,    84,    79,    79,
      84,    79,    79,    84,    79,    86,    79,    84,    79,    79,
      18,    19,   312,    79,    79,    12,   191,    79,   194,    79,
      84,    79,    79,     9,    84,   170,     8,     5,    10,   207,
      79,   170,    79,    79,    79,    84,    79,    79,    84,   181,
      79,    79,     3,    79,   170,    79,    79,    79,     3,    79,
      79,    13,    79,   225,    79,    84,    79,   170,    79,    79,
      79,     3,    79,    79,     8,   207,   232,    79,    79,    84,
     191,    79,    79,     3,    79,    79,     3,    79,    79,    79,
      79,     7,    79,    79,    84,   232,    79,    79,    84,   232,
      79,    79,    79,    79,    85,    79,    79,    18,    19,   318,
      79,    79,   312,    79,    79,    84,    79,    79,     3,    79,
      79,    84,   207,    79,   170,    79,    79,    79,   232,    79,
      79,   232,    79,    79,   191,    79,    79,   232,    79,    84,
      79,    79,    79,     3,    79,    79,    84,    79,    79,     3,
      79,    82,   271,   272,    79,   276,    79,    79,     7,    79,
     170,    79,    79,    79,    84,    79,    79,     3,   283,   284,
      79,    79,   232,    79,    79,    84,    79,    79,   276,    79,
      82,    79,    84,     4,    93,   293,   298,    79,    79,    84,
       3,    79,    79,   318,     7,    79,    79,     7,     4,   169,
      85,   171,   176,   180,   182,     8,   184,     4,     4,   172,
     308,   313,   314,    89,   190,     8,   193,   198,   200,   203,
      87,   176,   212,   215,   219,    84,     8,   224,   229,   233,
      87,   170,   239,   238,   243,   246,   250,   232,   232,     4,
     319,   320,     4,     3,   259,    87,   170,   170,   264,   170,
       4,   270,   259,   329,     4,     6,   279,     4,    92,     3,
     285,   170,     4,     4,   291,    83,   299,   170,    83,   302,
     304,   109,   307,   170,   171,   181,   177,   186,     5,    21,
     174,   171,   310,   171,   311,    12,   195,   205,   181,     4,
       3,   226,   234,   191,   171,   317,   311,   332,     8,   170,
     271,   271,   273,     3,    92,    82,   294,    20,   296,   293,
      79,    88,   173,    84,    84,    88,     8,    14,    88,     8,
     240,    84,     4,   261,   170,    91,     3,     4,     3,   300,
       3,     5,   170,   171,   171,   170,   206,     3,   170,   235,
     171,    88,   295,    94,   297,    88,     3,    88,   170,    83,
       3,    83,     3,    15,   222
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
#line 160 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1642 "parser.cxx"
        break;
      case 5: /* T_QSTRING */
#line 161 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1647 "parser.cxx"
        break;
      case 6: /* T_COMMENT */
#line 162 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1652 "parser.cxx"
        break;
      case 7: /* T_LINE */
#line 163 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1657 "parser.cxx"
        break;
      case 8: /* T_URI */
#line 164 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1662 "parser.cxx"
        break;
      case 10: /* T_DISPLAY */
#line 165 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1667 "parser.cxx"
        break;
      case 11: /* T_LANG */
#line 166 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1672 "parser.cxx"
        break;
      case 12: /* T_WORD */
#line 167 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1677 "parser.cxx"
        break;
      case 17: /* T_METHOD */
#line 168 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1682 "parser.cxx"
        break;
      case 19: /* T_AUTH_OTHER */
#line 169 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1687 "parser.cxx"
        break;
      case 20: /* T_IPV6ADDR */
#line 170 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1692 "parser.cxx"
        break;
      case 21: /* T_PARAMVAL */
#line 171 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1697 "parser.cxx"
        break;
      case 78: /* T_HDR_UNKNOWN */
#line 172 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1702 "parser.cxx"
        break;
      case 103: /* sip_version */
#line 235 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1707 "parser.cxx"
        break;
      case 169: /* media_range */
#line 228 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_media); delete yyvaluep->yyt_media; };
#line 1712 "parser.cxx"
        break;
      case 170: /* parameters */
#line 231 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1717 "parser.cxx"
        break;
      case 171: /* parameter */
#line 229 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_param); delete yyvaluep->yyt_param; };
#line 1722 "parser.cxx"
        break;
      case 174: /* parameter_val */
#line 230 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1727 "parser.cxx"
        break;
      case 176: /* content_coding */
#line 216 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_coding); delete yyvaluep->yyt_coding; };
#line 1732 "parser.cxx"
        break;
      case 181: /* language */
#line 227 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_language); delete yyvaluep->yyt_language; };
#line 1737 "parser.cxx"
        break;
      case 184: /* alert_param */
#line 208 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_alert_param); delete yyvaluep->yyt_alert_param; };
#line 1742 "parser.cxx"
        break;
      case 191: /* call_id */
#line 210 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1747 "parser.cxx"
        break;
      case 193: /* info_param */
#line 226 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_info_param); delete yyvaluep->yyt_info_param; };
#line 1752 "parser.cxx"
        break;
      case 199: /* contacts */
#line 215 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contacts); delete yyvaluep->yyt_contacts; };
#line 1757 "parser.cxx"
        break;
      case 200: /* contact_param */
#line 214 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1762 "parser.cxx"
        break;
      case 201: /* contact_addr */
#line 213 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_contact); delete yyvaluep->yyt_contact; };
#line 1767 "parser.cxx"
        break;
      case 207: /* display_name */
#line 220 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1772 "parser.cxx"
        break;
      case 224: /* error_param */
#line 221 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_error_param); delete yyvaluep->yyt_error_param; };
#line 1777 "parser.cxx"
        break;
      case 232: /* from_addr */
#line 222 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_from_addr); delete yyvaluep->yyt_from_addr; };
#line 1782 "parser.cxx"
        break;
      case 259: /* rec_route */
#line 232 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_route); delete yyvaluep->yyt_route; };
#line 1787 "parser.cxx"
        break;
      case 271: /* comment */
#line 212 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1792 "parser.cxx"
        break;
      case 276: /* server */
#line 234 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_server); delete yyvaluep->yyt_server; };
#line 1797 "parser.cxx"
        break;
      case 291: /* via_parm */
#line 236 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1802 "parser.cxx"
        break;
      case 292: /* sent_protocol */
#line 233 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1807 "parser.cxx"
        break;
      case 293: /* host */
#line 224 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_via); delete yyvaluep->yyt_via; };
#line 1812 "parser.cxx"
        break;
      case 298: /* ipv6reference */
#line 225 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1817 "parser.cxx"
        break;
      case 302: /* warning */
#line 237 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_warning); delete yyvaluep->yyt_warning; };
#line 1822 "parser.cxx"
        break;
      case 305: /* hdr_unknown */
#line 223 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_str); delete yyvaluep->yyt_str; };
#line 1827 "parser.cxx"
        break;
      case 310: /* digest_response */
#line 219 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_resp); delete yyvaluep->yyt_dig_resp; };
#line 1832 "parser.cxx"
        break;
      case 311: /* auth_params */
#line 209 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_params); delete yyvaluep->yyt_params; };
#line 1837 "parser.cxx"
        break;
      case 312: /* credentials */
#line 217 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_credentials); delete yyvaluep->yyt_credentials; };
#line 1842 "parser.cxx"
        break;
      case 317: /* digest_challenge */
#line 218 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_dig_chlg); delete yyvaluep->yyt_dig_chlg; };
#line 1847 "parser.cxx"
        break;
      case 318: /* challenge */
#line 211 "parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yyt_challenge); delete yyvaluep->yyt_challenge; };
#line 1852 "parser.cxx"
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
#line 240 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 245 "parser.yxx"
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
#line 265 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 8:
#line 274 "parser.yxx"
    { CTXT_URI; }
    break;

  case 9:
#line 274 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 10:
#line 275 "parser.yxx"
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
#line 292 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 12:
#line 292 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 13:
#line 296 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 14:
#line 303 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 15:
#line 303 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 16:
#line 304 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 17:
#line 304 "parser.yxx"
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
#line 374 "parser.yxx"
    {
			MSG->add_unknown_header(*yyvsp[-3].yyt_str, trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-3].yyt_str); delete yyvsp[-3].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 77:
#line 379 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 78:
#line 381 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 79:
#line 383 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 80:
#line 385 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 81:
#line 387 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 82:
#line 389 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 83:
#line 391 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 84:
#line 393 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 85:
#line 395 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 86:
#line 397 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 87:
#line 399 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 88:
#line 401 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 89:
#line 403 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 90:
#line 405 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 91:
#line 407 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 92:
#line 409 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 93:
#line 411 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 94:
#line 413 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 95:
#line 415 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 96:
#line 417 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 97:
#line 419 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 98:
#line 421 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 99:
#line 423 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 100:
#line 425 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 101:
#line 427 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 102:
#line 429 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 103:
#line 431 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 104:
#line 433 "parser.yxx"
    { PARSE_ERROR("P-Asserted-Identity"); }
    break;

  case 105:
#line 435 "parser.yxx"
    { PARSE_ERROR("P-Preferred-Identity"); }
    break;

  case 106:
#line 437 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 107:
#line 439 "parser.yxx"
    { PARSE_ERROR("Privacy"); }
    break;

  case 108:
#line 441 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 109:
#line 443 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 110:
#line 445 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 111:
#line 447 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 112:
#line 449 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 113:
#line 451 "parser.yxx"
    { PARSE_ERROR("Refer-Sub"); }
    break;

  case 114:
#line 453 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 115:
#line 455 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 116:
#line 457 "parser.yxx"
    { PARSE_ERROR("Replaces"); }
    break;

  case 117:
#line 459 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 118:
#line 461 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 119:
#line 463 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 120:
#line 465 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 121:
#line 467 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 122:
#line 469 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 123:
#line 471 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 124:
#line 473 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 125:
#line 475 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 126:
#line 477 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 127:
#line 479 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 128:
#line 481 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 129:
#line 483 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 130:
#line 485 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 131:
#line 487 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 132:
#line 489 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 135:
#line 505 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 140:
#line 515 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 141:
#line 517 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 143:
#line 521 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 146:
#line 527 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 147:
#line 529 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 149:
#line 533 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 150:
#line 535 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 153:
#line 541 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 154:
#line 543 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 155:
#line 545 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 156:
#line 547 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 157:
#line 549 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 159:
#line 553 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 160:
#line 555 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 161:
#line 557 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 164:
#line 563 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 165:
#line 565 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 167:
#line 569 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 168:
#line 571 "parser.yxx"
    { CTXT_URI; }
    break;

  case 170:
#line 575 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 171:
#line 577 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 172:
#line 579 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 173:
#line 581 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 175:
#line 585 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 176:
#line 587 "parser.yxx"
    { CTXT_URI; }
    break;

  case 177:
#line 589 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 179:
#line 593 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 182:
#line 599 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 183:
#line 601 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 187:
#line 609 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 188:
#line 611 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 190:
#line 615 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 191:
#line 620 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_accept.add_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 192:
#line 627 "parser.yxx"
    { yyval.yyt_media = new t_media(tolower(*yyvsp[-2].yyt_str), tolower(*yyvsp[0].yyt_str));
					MEMMAN_NEW(yyval.yyt_media);
					MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
					MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 193:
#line 633 "parser.yxx"
    { yyval.yyt_params = new list<t_parameter>; MEMMAN_NEW(yyval.yyt_params); }
    break;

  case 194:
#line 634 "parser.yxx"
    {
			yyvsp[-2].yyt_params->push_back(*yyvsp[0].yyt_param);
			yyval.yyt_params = yyvsp[-2].yyt_params;
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 195:
#line 640 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 196:
#line 644 "parser.yxx"
    { CTXT_PARAMVAL; }
    break;

  case 197:
#line 644 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 198:
#line 644 "parser.yxx"
    {
			yyval.yyt_param = new t_parameter(tolower(*yyvsp[-4].yyt_str), *yyvsp[-1].yyt_str);
			MEMMAN_NEW(yyval.yyt_param);
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 199:
#line 651 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 200:
#line 653 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 201:
#line 657 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 202:
#line 660 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 203:
#line 665 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 204:
#line 669 "parser.yxx"
    {
			yyval.yyt_coding = new t_coding(tolower(*yyvsp[-1].yyt_str));
			MEMMAN_NEW(yyval.yyt_coding);
			yyval.yyt_coding->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 205:
#line 676 "parser.yxx"
    {
			if (yyvsp[0].yyt_param->name != "q") YYERROR;
			yyval.yyt_float = atof(yyvsp[0].yyt_param->value.c_str());
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param;
			}
    break;

  case 206:
#line 683 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 207:
#line 683 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 208:
#line 686 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 209:
#line 686 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 210:
#line 691 "parser.yxx"
    {
			CTXT_INITIAL;
		  	yyval.yyt_language = new t_language(tolower(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 211:
#line 696 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 212:
#line 696 "parser.yxx"
    {
			yyval.yyt_language = new t_language(tolower(*yyvsp[-2].yyt_str));
			MEMMAN_NEW(yyval.yyt_language);
			yyval.yyt_language->q = yyvsp[0].yyt_float;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str; }
    break;

  case 213:
#line 703 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 214:
#line 706 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*yyvsp[0].yyt_alert_param);
			MEMMAN_DELETE(yyvsp[0].yyt_alert_param); delete yyvsp[0].yyt_alert_param; }
    break;

  case 215:
#line 711 "parser.yxx"
    { CTXT_URI; }
    break;

  case 216:
#line 711 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 217:
#line 711 "parser.yxx"
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

  case 218:
#line 726 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 219:
#line 729 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 220:
#line 734 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 221:
#line 734 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 222:
#line 734 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 223:
#line 739 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 224:
#line 740 "parser.yxx"
    {
			yyval.yyt_str = new string(*yyvsp[-2].yyt_str + '@' + *yyvsp[0].yyt_str);
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 225:
#line 747 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 226:
#line 750 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*yyvsp[0].yyt_info_param);
			MEMMAN_DELETE(yyvsp[0].yyt_info_param); delete yyvsp[0].yyt_info_param; }
    break;

  case 227:
#line 755 "parser.yxx"
    { CTXT_URI; }
    break;

  case 228:
#line 755 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 229:
#line 755 "parser.yxx"
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

  case 230:
#line 770 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 231:
#line 770 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 232:
#line 770 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 233:
#line 772 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*yyvsp[0].yyt_contacts);
			MEMMAN_DELETE(yyvsp[0].yyt_contacts); delete yyvsp[0].yyt_contacts; }
    break;

  case 234:
#line 777 "parser.yxx"
    {
			yyval.yyt_contacts = new list<t_contact_param>;
			MEMMAN_NEW(yyval.yyt_contacts);
			yyval.yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 235:
#line 782 "parser.yxx"
    {
			yyvsp[-2].yyt_contacts->push_back(*yyvsp[0].yyt_contact);
			yyval.yyt_contacts = yyvsp[-2].yyt_contacts;
			MEMMAN_DELETE(yyvsp[0].yyt_contact); delete yyvsp[0].yyt_contact; }
    break;

  case 236:
#line 788 "parser.yxx"
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

  case 237:
#line 804 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 238:
#line 804 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 239:
#line 804 "parser.yxx"
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

  case 240:
#line 815 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 241:
#line 815 "parser.yxx"
    { CTXT_URI; }
    break;

  case 242:
#line 815 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 243:
#line 815 "parser.yxx"
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

  case 244:
#line 830 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 245:
#line 831 "parser.yxx"
    {
			yyval.yyt_str = new string(rtrim(*yyvsp[0].yyt_str));
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 246:
#line 835 "parser.yxx"
    { yyval.yyt_str = yyvsp[0].yyt_str; }
    break;

  case 247:
#line 838 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*yyvsp[-1].yyt_str));
			MSG->hdr_content_disp.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 248:
#line 845 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 249:
#line 848 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*yyvsp[0].yyt_coding);
			MEMMAN_DELETE(yyvsp[0].yyt_coding); delete yyvsp[0].yyt_coding; }
    break;

  case 250:
#line 853 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 251:
#line 853 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 252:
#line 856 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 253:
#line 856 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*yyvsp[0].yyt_language);
			MEMMAN_DELETE(yyvsp[0].yyt_language); delete yyvsp[0].yyt_language; }
    break;

  case 254:
#line 861 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 255:
#line 861 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 256:
#line 861 "parser.yxx"
    {
			MSG->hdr_content_length.set_length(yyvsp[-1].yyt_ulong); }
    break;

  case 257:
#line 865 "parser.yxx"
    {
			yyvsp[-1].yyt_media->add_params(*yyvsp[0].yyt_params);
			MSG->hdr_content_type.set_media(*yyvsp[-1].yyt_media);
			MEMMAN_DELETE(yyvsp[-1].yyt_media); delete yyvsp[-1].yyt_media;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 258:
#line 872 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 259:
#line 872 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 260:
#line 872 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr(yyvsp[-2].yyt_ulong);
			MSG->hdr_cseq.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 261:
#line 878 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 262:
#line 881 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 263:
#line 881 "parser.yxx"
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

  case 264:
#line 892 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 265:
#line 895 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*yyvsp[0].yyt_error_param);
			MEMMAN_DELETE(yyvsp[0].yyt_error_param); delete yyvsp[0].yyt_error_param; }
    break;

  case 266:
#line 900 "parser.yxx"
    { CTXT_URI; }
    break;

  case 267:
#line 900 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 268:
#line 900 "parser.yxx"
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

  case 269:
#line 915 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 270:
#line 915 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 271:
#line 915 "parser.yxx"
    {
			MSG->hdr_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 272:
#line 919 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 273:
#line 919 "parser.yxx"
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

  case 274:
#line 934 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 275:
#line 934 "parser.yxx"
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

  case 276:
#line 945 "parser.yxx"
    { CTXT_URI; }
    break;

  case 277:
#line 945 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 278:
#line 945 "parser.yxx"
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

  case 279:
#line 960 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 280:
#line 960 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 281:
#line 960 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 282:
#line 963 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 283:
#line 963 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 284:
#line 963 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*yyvsp[-1].yyt_str);
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 285:
#line 968 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 286:
#line 968 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 287:
#line 968 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards(yyvsp[-1].yyt_ulong); }
    break;

  case 288:
#line 972 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 289:
#line 972 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 290:
#line 972 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time(yyvsp[-1].yyt_ulong); }
    break;

  case 291:
#line 976 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 292:
#line 981 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 293:
#line 981 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 294:
#line 981 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 295:
#line 986 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 296:
#line 986 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 297:
#line 989 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 298:
#line 994 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 299:
#line 994 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 300:
#line 997 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*yyvsp[0].yyt_from_addr);
				MEMMAN_DELETE(yyvsp[0].yyt_from_addr); delete yyvsp[0].yyt_from_addr; }
    break;

  case 301:
#line 1002 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 302:
#line 1007 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 303:
#line 1010 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 304:
#line 1015 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 305:
#line 1018 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 306:
#line 1023 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 307:
#line 1026 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 308:
#line 1031 "parser.yxx"
    { CTXT_URI; }
    break;

  case 309:
#line 1031 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 310:
#line 1032 "parser.yxx"
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

  case 311:
#line 1049 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 312:
#line 1049 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 313:
#line 1049 "parser.yxx"
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

  case 314:
#line 1071 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 315:
#line 1071 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_reply_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_reply_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 316:
#line 1079 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 317:
#line 1082 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 318:
#line 1087 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 319:
#line 1087 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 320:
#line 1087 "parser.yxx"
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

  case 321:
#line 1103 "parser.yxx"
    { yyval.yyt_str = new string(); MEMMAN_NEW(yyval.yyt_str); }
    break;

  case 322:
#line 1104 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 323:
#line 1104 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 324:
#line 1104 "parser.yxx"
    {
			yyval.yyt_str = yyvsp[-2].yyt_str; }
    break;

  case 325:
#line 1108 "parser.yxx"
    {
			MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 326:
#line 1111 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*yyvsp[0].yyt_route);
			MEMMAN_DELETE(yyvsp[0].yyt_route); delete yyvsp[0].yyt_route; }
    break;

  case 327:
#line 1116 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 328:
#line 1119 "parser.yxx"
    {
			MSG->hdr_server.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 329:
#line 1124 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 330:
#line 1129 "parser.yxx"
    {
			yyval.yyt_server = new t_server();
			MEMMAN_NEW(yyval.yyt_server);
			yyval.yyt_server->product = *yyvsp[-1].yyt_str;
			yyval.yyt_server->comment = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 331:
#line 1136 "parser.yxx"
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

  case 332:
#line 1147 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 333:
#line 1147 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 334:
#line 1147 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*yyvsp[-1].yyt_str));
			MEMMAN_DELETE(yyvsp[-1].yyt_str); delete yyvsp[-1].yyt_str; }
    break;

  case 335:
#line 1152 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 336:
#line 1154 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 337:
#line 1157 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 338:
#line 1162 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 339:
#line 1162 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 340:
#line 1165 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[0].yyt_float); }
    break;

  case 341:
#line 1167 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp(yyvsp[-1].yyt_float);
			MSG->hdr_timestamp.set_delay(yyvsp[0].yyt_float); }
    break;

  case 342:
#line 1172 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 343:
#line 1173 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 344:
#line 1178 "parser.yxx"
    { yyval.yyt_float = yyvsp[0].yyt_ulong; }
    break;

  case 345:
#line 1179 "parser.yxx"
    {
			string s = int2str(yyvsp[-2].yyt_ulong) + '.' + int2str(yyvsp[0].yyt_ulong);
			yyval.yyt_float = atof(s.c_str()); }
    break;

  case 346:
#line 1184 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 347:
#line 1184 "parser.yxx"
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

  case 348:
#line 1199 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 349:
#line 1202 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*yyvsp[0].yyt_str));
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 350:
#line 1207 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 351:
#line 1210 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*yyvsp[0].yyt_server);
			MEMMAN_DELETE(yyvsp[0].yyt_server); delete yyvsp[0].yyt_server; }
    break;

  case 352:
#line 1215 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 353:
#line 1218 "parser.yxx"
    {
			MSG->hdr_via.add_via(*yyvsp[0].yyt_via);
			MEMMAN_DELETE(yyvsp[0].yyt_via); delete yyvsp[0].yyt_via; }
    break;

  case 354:
#line 1223 "parser.yxx"
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

  case 355:
#line 1251 "parser.yxx"
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

  case 356:
#line 1262 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 357:
#line 1267 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 358:
#line 1267 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 359:
#line 1267 "parser.yxx"
    {
			if (yyvsp[-1].yyt_ulong > 65535) YYERROR;
			
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[-4].yyt_str;
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 360:
#line 1275 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[0].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 361:
#line 1280 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 362:
#line 1280 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 363:
#line 1280 "parser.yxx"
    {
			yyval.yyt_via = new t_via();
			MEMMAN_NEW(yyval.yyt_via);
			yyval.yyt_via->host = *yyvsp[-4].yyt_str;
			yyval.yyt_via->port = yyvsp[-1].yyt_ulong;
			MEMMAN_DELETE(yyvsp[-4].yyt_str); delete yyvsp[-4].yyt_str; }
    break;

  case 364:
#line 1288 "parser.yxx"
    { CTXT_IPV6ADDR; }
    break;

  case 365:
#line 1288 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 366:
#line 1288 "parser.yxx"
    {
			// TODO: check correct format of IPv6 address
			yyval.yyt_str = new string('[' + *yyvsp[-2].yyt_str + ']');
			MEMMAN_NEW(yyval.yyt_str);
			MEMMAN_DELETE(yyvsp[-2].yyt_str); }
    break;

  case 367:
#line 1295 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 368:
#line 1298 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*yyvsp[0].yyt_warning);
			MEMMAN_DELETE(yyvsp[0].yyt_warning); delete yyvsp[0].yyt_warning; }
    break;

  case 369:
#line 1303 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 370:
#line 1303 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 371:
#line 1303 "parser.yxx"
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

  case 372:
#line 1314 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 373:
#line 1314 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 374:
#line 1314 "parser.yxx"
    { yyval.yyt_str = yyvsp[-1].yyt_str; }
    break;

  case 375:
#line 1317 "parser.yxx"
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

  case 378:
#line 1341 "parser.yxx"
    {
			yyval.yyt_dig_resp = new t_digest_response();
			MEMMAN_NEW(yyval.yyt_dig_resp);
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyval.yyt_dig_resp); delete yyval.yyt_dig_resp;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 379:
#line 1349 "parser.yxx"
    {
			if (!yyval.yyt_dig_resp->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 380:
#line 1356 "parser.yxx"
    {
			yyval.yyt_params = new list<t_parameter>;
			MEMMAN_NEW(yyval.yyt_params);
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 381:
#line 1361 "parser.yxx"
    {
			yyval.yyt_params->push_back(*yyvsp[0].yyt_param);
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 382:
#line 1366 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 383:
#line 1366 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = AUTH_DIGEST;
			yyval.yyt_credentials->digest_response = *yyvsp[0].yyt_dig_resp;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_resp); delete yyvsp[0].yyt_dig_resp; }
    break;

  case 384:
#line 1372 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 385:
#line 1372 "parser.yxx"
    {
			yyval.yyt_credentials = new t_credentials;
			MEMMAN_NEW(yyval.yyt_credentials);
			yyval.yyt_credentials->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_credentials->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 386:
#line 1381 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 387:
#line 1381 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*yyvsp[0].yyt_credentials);
			MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 388:
#line 1386 "parser.yxx"
    {
			yyval.yyt_dig_chlg = new t_digest_challenge();
			MEMMAN_NEW(yyval.yyt_dig_chlg);
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				MEMMAN_DELETE(yyval.yyt_dig_chlg); delete yyval.yyt_dig_chlg;
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 389:
#line 1394 "parser.yxx"
    {
			if (!yyval.yyt_dig_chlg->set_attr(*yyvsp[0].yyt_param)) {
				YYERROR;
			}
			MEMMAN_DELETE(yyvsp[0].yyt_param); delete yyvsp[0].yyt_param; }
    break;

  case 390:
#line 1401 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 391:
#line 1401 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = AUTH_DIGEST;
			yyval.yyt_challenge->digest_challenge = *yyvsp[0].yyt_dig_chlg;
			MEMMAN_DELETE(yyvsp[0].yyt_dig_chlg); delete yyvsp[0].yyt_dig_chlg; }
    break;

  case 392:
#line 1407 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 393:
#line 1407 "parser.yxx"
    {
			yyval.yyt_challenge = new t_challenge;
			MEMMAN_NEW(yyval.yyt_challenge);
			yyval.yyt_challenge->auth_scheme = *yyvsp[-2].yyt_str;
			yyval.yyt_challenge->auth_params = *yyvsp[0].yyt_params;
			MEMMAN_DELETE(yyvsp[-2].yyt_str); delete yyvsp[-2].yyt_str;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 394:
#line 1416 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 395:
#line 1416 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 396:
#line 1421 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 397:
#line 1421 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*yyvsp[0].yyt_credentials);
				MEMMAN_DELETE(yyvsp[0].yyt_credentials); delete yyvsp[0].yyt_credentials; }
    break;

  case 398:
#line 1427 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 399:
#line 1427 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*yyvsp[0].yyt_challenge);
				MEMMAN_DELETE(yyvsp[0].yyt_challenge); delete yyvsp[0].yyt_challenge; }
    break;

  case 400:
#line 1432 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 401:
#line 1432 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 402:
#line 1432 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr(yyvsp[-1].yyt_ulong); }
    break;

  case 403:
#line 1436 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 404:
#line 1436 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 405:
#line 1436 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr(yyvsp[-3].yyt_ulong);
			MSG->hdr_rack.set_cseq_nr(yyvsp[-2].yyt_ulong);
			MSG->hdr_rack.set_method(*yyvsp[0].yyt_str);
			MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 406:
#line 1443 "parser.yxx"
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

  case 407:
#line 1457 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 408:
#line 1460 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*yyvsp[0].yyt_str));
				MEMMAN_DELETE(yyvsp[0].yyt_str); delete yyvsp[0].yyt_str; }
    break;

  case 409:
#line 1465 "parser.yxx"
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

  case 410:
#line 1491 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 411:
#line 1491 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display(yyvsp[-1].yyt_from_addr->display);
			MSG->hdr_refer_to.set_uri(yyvsp[-1].yyt_from_addr->uri);
			MSG->hdr_refer_to.set_params(*yyvsp[0].yyt_params);
			MEMMAN_DELETE(yyvsp[-1].yyt_from_addr); delete yyvsp[-1].yyt_from_addr;
			MEMMAN_DELETE(yyvsp[0].yyt_params); delete yyvsp[0].yyt_params; }
    break;

  case 412:
#line 1499 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 413:
#line 1499 "parser.yxx"
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

  case 414:
#line 1514 "parser.yxx"
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
#line 4417 "parser.cxx"

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


#line 1524 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

