/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

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
     T_HDR_SIP_ETAG = 323,
     T_HDR_SIP_IF_MATCH = 324,
     T_HDR_SUBJECT = 325,
     T_HDR_SUBSCRIPTION_STATE = 326,
     T_HDR_SUPPORTED = 327,
     T_HDR_TIMESTAMP = 328,
     T_HDR_TO = 329,
     T_HDR_UNSUPPORTED = 330,
     T_HDR_USER_AGENT = 331,
     T_HDR_VIA = 332,
     T_HDR_WARNING = 333,
     T_HDR_WWW_AUTHENTICATE = 334,
     T_HDR_UNKNOWN = 335,
     T_CRLF = 336,
     T_ERROR = 337,
     T_NULL = 338
   };
#endif
/* Tokens.  */
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
#define T_HDR_SIP_ETAG 323
#define T_HDR_SIP_IF_MATCH 324
#define T_HDR_SUBJECT 325
#define T_HDR_SUBSCRIPTION_STATE 326
#define T_HDR_SUPPORTED 327
#define T_HDR_TIMESTAMP 328
#define T_HDR_TO 329
#define T_HDR_UNSUPPORTED 330
#define T_HDR_USER_AGENT 331
#define T_HDR_VIA 332
#define T_HDR_WARNING 333
#define T_HDR_WWW_AUTHENTICATE 334
#define T_HDR_UNKNOWN 335
#define T_CRLF 336
#define T_ERROR 337
#define T_NULL 338




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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 49 "parser.yxx"
{
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
}
/* Line 193 of yacc.c.  */
#line 306 "parser.cxx"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 319 "parser.cxx"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
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
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   860

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  250
/* YYNRULES -- Number of rules.  */
#define YYNRULES  422
/* YYNRULES -- Number of states.  */
#define YYNSTATES  771

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      92,    93,     2,     2,    86,     2,    94,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    85,    87,
      89,    88,    90,     2,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    95,     2,    96,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    14,    18,    19,
      20,    27,    28,    33,    37,    38,    39,    40,    48,    49,
      52,    56,    60,    64,    68,    72,    76,    80,    84,    88,
      92,    96,   100,   104,   108,   112,   116,   120,   124,   128,
     132,   136,   140,   144,   148,   152,   156,   160,   164,   168,
     172,   176,   180,   184,   188,   192,   196,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   272,   276,   280,   284,   289,
     293,   297,   301,   305,   309,   313,   317,   321,   325,   329,
     333,   337,   341,   345,   349,   353,   357,   361,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   401,   405,   409,
     413,   417,   421,   425,   429,   433,   437,   441,   445,   449,
     453,   457,   461,   465,   469,   473,   477,   481,   485,   489,
     493,   497,   501,   505,   509,   513,   517,   521,   524,   527,
     530,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   566,   569,   572,   575,   578,   581,   584,   587,
     590,   593,   596,   599,   602,   605,   608,   611,   614,   617,
     620,   623,   626,   629,   632,   635,   638,   641,   644,   647,
     650,   653,   656,   659,   662,   665,   668,   671,   674,   677,
     680,   683,   686,   689,   692,   695,   696,   699,   704,   708,
     709,   713,   715,   716,   717,   723,   725,   727,   729,   733,
     735,   738,   741,   742,   745,   746,   751,   753,   754,   758,
     760,   764,   765,   766,   773,   775,   779,   780,   781,   785,
     787,   791,   793,   797,   798,   799,   806,   807,   808,   812,
     814,   816,   820,   823,   824,   825,   829,   830,   831,   832,
     840,   841,   843,   845,   848,   850,   854,   855,   858,   859,
     864,   865,   866,   870,   873,   874,   875,   880,   881,   882,
     896,   898,   902,   903,   904,   911,   912,   913,   917,   918,
     922,   923,   926,   927,   928,   935,   936,   937,   941,   942,
     943,   949,   950,   951,   955,   956,   957,   961,   963,   964,
     965,   969,   970,   973,   977,   978,   981,   985,   987,   989,
     993,   995,   999,  1001,  1005,  1006,  1007,  1015,  1016,  1017,
    1022,  1023,  1027,  1029,  1033,  1034,  1035,  1041,  1042,  1043,
    1044,  1050,  1052,  1056,  1058,  1061,  1063,  1066,  1071,  1072,
    1073,  1077,  1078,  1080,  1084,  1085,  1088,  1090,  1093,  1095,
    1099,  1101,  1105,  1106,  1110,  1112,  1116,  1118,  1121,  1123,
    1127,  1131,  1137,  1139,  1140,  1141,  1147,  1149,  1150,  1151,
    1157,  1158,  1159,  1165,  1167,  1171,  1172,  1173,  1179,  1180,
    1181,  1185,  1187,  1189,  1193,  1195,  1199,  1201,  1205,  1206,
    1210,  1211,  1215,  1216,  1219,  1221,  1225,  1226,  1230,  1231,
    1235,  1236,  1239,  1240,  1243,  1244,  1247,  1248,  1249,  1253,
    1254,  1255,  1261,  1264,  1266,  1270,  1273,  1274,  1278,  1279,
    1283,  1286,  1288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      98,     0,    -1,    -1,    99,   100,    -1,   101,    -1,   107,
      -1,     1,    83,    -1,   102,   112,    81,    -1,    -1,    -1,
      17,   103,     8,   104,   105,    81,    -1,    -1,    16,   106,
      84,     4,    -1,   108,   112,    81,    -1,    -1,    -1,    -1,
     105,   109,     3,   110,     7,   111,    81,    -1,    -1,   112,
     113,    -1,   114,   172,    81,    -1,   115,   179,    81,    -1,
     116,   182,    81,    -1,   117,   187,    81,    -1,   118,   191,
      81,    -1,   119,   338,    81,    -1,   120,   313,    81,    -1,
     121,   319,    81,    -1,   122,   192,    81,    -1,   123,   196,
      81,    -1,   124,   200,    81,    -1,   125,   212,    81,    -1,
     126,   213,    81,    -1,   127,   214,    81,    -1,   128,   217,
      81,    -1,   129,   220,    81,    -1,   130,   221,    81,    -1,
     131,   224,    81,    -1,   133,   337,    81,    -1,   132,   227,
      81,    -1,   134,   231,    81,    -1,   135,   234,    81,    -1,
     136,   240,    81,    -1,   137,   245,    81,    -1,   138,   248,
      81,    -1,   139,   251,    81,    -1,   140,   252,    81,    -1,
     141,   255,    81,    -1,   142,   257,    81,    -1,   143,   259,
      81,    -1,   144,   260,    81,    -1,   145,   325,    81,    -1,
     146,   327,    81,    -1,   147,   261,    81,    -1,   148,   334,
      81,    -1,   149,   262,    81,    -1,   150,   344,    81,    -1,
     151,   340,    81,    -1,   152,   342,    81,    -1,   153,   266,
      81,    -1,   154,   269,    81,    -1,   155,   271,    81,    -1,
     156,   272,    81,    -1,   157,   278,    81,    -1,   158,   331,
      81,    -1,   159,   279,    81,    -1,   160,   345,    81,    -1,
     161,   346,    81,    -1,   162,   281,    81,    -1,   163,   339,
      81,    -1,   164,   284,    81,    -1,   165,   285,    81,    -1,
     166,   290,    81,    -1,   167,   292,    81,    -1,   168,   293,
      81,    -1,   169,   294,    81,    -1,   170,   305,    81,    -1,
     171,   329,    81,    -1,    80,    85,   309,    81,    -1,   114,
       1,    81,    -1,   115,     1,    81,    -1,   116,     1,    81,
      -1,   117,     1,    81,    -1,   118,     1,    81,    -1,   119,
       1,    81,    -1,   120,     1,    81,    -1,   121,     1,    81,
      -1,   122,     1,    81,    -1,   123,     1,    81,    -1,   124,
       1,    81,    -1,   125,     1,    81,    -1,   126,     1,    81,
      -1,   127,     1,    81,    -1,   128,     1,    81,    -1,   129,
       1,    81,    -1,   130,     1,    81,    -1,   131,     1,    81,
      -1,   132,     1,    81,    -1,   133,     1,    81,    -1,   134,
       1,    81,    -1,   135,     1,    81,    -1,   136,     1,    81,
      -1,   137,     1,    81,    -1,   138,     1,    81,    -1,   139,
       1,    81,    -1,   140,     1,    81,    -1,   141,     1,    81,
      -1,   142,     1,    81,    -1,   143,     1,    81,    -1,   144,
       1,    81,    -1,   145,     1,    81,    -1,   146,     1,    81,
      -1,   147,     1,    81,    -1,   148,     1,    81,    -1,   149,
       1,    81,    -1,   150,     1,    81,    -1,   151,     1,    81,
      -1,   152,     1,    81,    -1,   153,     1,    81,    -1,   154,
       1,    81,    -1,   155,     1,    81,    -1,   156,     1,    81,
      -1,   157,     1,    81,    -1,   158,     1,    81,    -1,   159,
       1,    81,    -1,   160,     1,    81,    -1,   161,     1,    81,
      -1,   162,     1,    81,    -1,   163,     1,    81,    -1,   164,
       1,    81,    -1,   165,     1,    81,    -1,   166,     1,    81,
      -1,   167,     1,    81,    -1,   168,     1,    81,    -1,   169,
       1,    81,    -1,   170,     1,    81,    -1,   171,     1,    81,
      -1,    22,    85,    -1,    23,    85,    -1,    24,    85,    -1,
      25,    85,    -1,    26,    85,    -1,    27,    85,    -1,    28,
      85,    -1,    29,    85,    -1,    30,    85,    -1,    31,    85,
      -1,    32,    85,    -1,    33,    85,    -1,    34,    85,    -1,
      35,    85,    -1,    36,    85,    -1,    37,    85,    -1,    38,
      85,    -1,    39,    85,    -1,    40,    85,    -1,    41,    85,
      -1,    42,    85,    -1,    43,    85,    -1,    44,    85,    -1,
      45,    85,    -1,    46,    85,    -1,    47,    85,    -1,    48,
      85,    -1,    49,    85,    -1,    50,    85,    -1,    51,    85,
      -1,    52,    85,    -1,    53,    85,    -1,    54,    85,    -1,
      55,    85,    -1,    56,    85,    -1,    57,    85,    -1,    58,
      85,    -1,    59,    85,    -1,    60,    85,    -1,    61,    85,
      -1,    62,    85,    -1,    63,    85,    -1,    64,    85,    -1,
      65,    85,    -1,    66,    85,    -1,    67,    85,    -1,    68,
      85,    -1,    69,    85,    -1,    70,    85,    -1,    71,    85,
      -1,    72,    85,    -1,    73,    85,    -1,    74,    85,    -1,
      75,    85,    -1,    76,    85,    -1,    77,    85,    -1,    78,
      85,    -1,    79,    85,    -1,    -1,   173,   174,    -1,   172,
      86,   173,   174,    -1,     4,    84,     4,    -1,    -1,   174,
      87,   175,    -1,     4,    -1,    -1,    -1,     4,    88,   176,
     178,   177,    -1,    21,    -1,     5,    -1,   180,    -1,   179,
      86,   180,    -1,     4,    -1,     4,   181,    -1,    87,   175,
      -1,    -1,   183,   185,    -1,    -1,   182,    86,   184,   185,
      -1,    11,    -1,    -1,    11,   186,   181,    -1,   188,    -1,
     187,    86,   188,    -1,    -1,    -1,    89,   189,     8,   190,
      90,   174,    -1,     4,    -1,   191,    86,     4,    -1,    -1,
      -1,   193,   195,   194,    -1,    12,    -1,    12,    91,    12,
      -1,   197,    -1,   196,    86,   197,    -1,    -1,    -1,    89,
     198,     8,   199,    90,   174,    -1,    -1,    -1,   201,     9,
     202,    -1,   203,    -1,   204,    -1,   203,    86,   204,    -1,
     205,   174,    -1,    -1,    -1,   206,     8,   207,    -1,    -1,
      -1,    -1,   208,   211,    89,   209,     8,   210,    90,    -1,
      -1,    10,    -1,     5,    -1,     4,   174,    -1,   180,    -1,
     213,    86,   180,    -1,    -1,   215,   185,    -1,    -1,   214,
      86,   216,   185,    -1,    -1,    -1,   218,     3,   219,    -1,
     173,   174,    -1,    -1,    -1,   222,     3,   223,     4,    -1,
      -1,    -1,   225,    13,    86,     3,    14,     3,     3,    85,
       3,    85,     3,    15,   226,    -1,   228,    -1,   227,    86,
     228,    -1,    -1,    -1,    89,   229,     8,   230,    90,   174,
      -1,    -1,    -1,   232,     3,   233,    -1,    -1,   235,   236,
     174,    -1,    -1,     8,   237,    -1,    -1,    -1,   211,    89,
     238,     8,   239,    90,    -1,    -1,    -1,   241,   195,   242,
      -1,    -1,    -1,   240,    86,   243,   195,   244,    -1,    -1,
      -1,   246,     3,   247,    -1,    -1,    -1,   249,     3,   250,
      -1,     4,    -1,    -1,    -1,   253,     7,   254,    -1,    -1,
     256,   236,    -1,   255,    86,   236,    -1,    -1,   258,   236,
      -1,   257,    86,   236,    -1,     4,    -1,     4,    -1,   260,
      87,     4,    -1,     4,    -1,   261,    86,     4,    -1,   263,
      -1,   262,    86,   263,    -1,    -1,    -1,   264,   211,    89,
       8,   265,    90,   174,    -1,    -1,    -1,   267,   195,   268,
     174,    -1,    -1,   270,   236,   174,    -1,     4,    -1,   261,
      86,     4,    -1,    -1,    -1,   273,     3,   274,   275,   174,
      -1,    -1,    -1,    -1,    92,   276,     6,   277,    93,    -1,
     263,    -1,   278,    86,   263,    -1,   280,    -1,   279,   280,
      -1,   275,    -1,     4,   275,    -1,     4,    84,     4,   275,
      -1,    -1,    -1,   282,     7,   283,    -1,    -1,     4,    -1,
     284,    86,     4,    -1,    -1,   286,   287,    -1,   288,    -1,
     288,   289,    -1,     3,    -1,     3,    94,     3,    -1,     3,
      -1,     3,    94,     3,    -1,    -1,   291,   236,   174,    -1,
       4,    -1,   292,    86,     4,    -1,   280,    -1,   293,   280,
      -1,   295,    -1,   294,    86,   295,    -1,   296,   297,   174,
      -1,     4,    84,     4,    84,     4,    -1,     4,    -1,    -1,
      -1,     4,    85,   298,     3,   299,    -1,   302,    -1,    -1,
      -1,   302,    85,   300,     3,   301,    -1,    -1,    -1,    95,
     303,    20,   304,    96,    -1,   306,    -1,   305,    86,   306,
      -1,    -1,    -1,   307,     3,   308,   297,     5,    -1,    -1,
      -1,   310,     7,   311,    -1,   175,    -1,   312,    -1,   313,
      86,   312,    -1,   175,    -1,   314,    86,   175,    -1,   175,
      -1,   315,    86,   175,    -1,    -1,    18,   317,   314,    -1,
      -1,    19,   318,   315,    -1,    -1,   320,   316,    -1,   175,
      -1,   321,    86,   175,    -1,    -1,    18,   323,   321,    -1,
      -1,    19,   324,   315,    -1,    -1,   326,   322,    -1,    -1,
     328,   316,    -1,    -1,   330,   322,    -1,    -1,    -1,   332,
       3,   333,    -1,    -1,    -1,   335,     3,     3,   336,     4,
      -1,     4,   174,    -1,     4,    -1,   338,    86,     4,    -1,
       4,   174,    -1,    -1,   341,   236,   174,    -1,    -1,   343,
     236,   174,    -1,     4,   174,    -1,     4,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   242,   242,   242,   245,   246,   247,   267,   276,   276,
     276,   294,   294,   298,   305,   305,   306,   305,   316,   317,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   382,
     384,   386,   388,   390,   392,   394,   396,   398,   400,   402,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   466,   468,   470,   472,   474,   476,   478,   480,   482,
     484,   486,   488,   490,   492,   494,   496,   509,   511,   513,
     515,   517,   519,   521,   523,   525,   527,   529,   531,   533,
     535,   537,   539,   541,   543,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     615,   617,   619,   621,   623,   626,   627,   632,   639,   645,
     646,   652,   656,   656,   656,   663,   665,   669,   672,   677,
     681,   688,   695,   695,   698,   698,   703,   708,   708,   715,
     718,   723,   723,   723,   738,   741,   746,   746,   746,   751,
     752,   759,   762,   767,   767,   767,   782,   782,   782,   784,
     789,   794,   800,   816,   816,   816,   827,   827,   827,   827,
     842,   843,   847,   850,   857,   860,   865,   865,   868,   868,
     873,   873,   873,   877,   884,   884,   884,   890,   893,   890,
     904,   907,   912,   912,   912,   927,   927,   927,   931,   931,
     946,   946,   957,   957,   957,   972,   972,   972,   975,   975,
     975,   980,   980,   980,   984,   984,   984,   988,   993,   993,
     993,   998,   998,  1001,  1006,  1006,  1009,  1014,  1019,  1022,
    1027,  1030,  1035,  1038,  1043,  1043,  1043,  1061,  1061,  1061,
    1083,  1083,  1091,  1094,  1099,  1099,  1099,  1115,  1116,  1116,
    1116,  1120,  1123,  1128,  1131,  1136,  1141,  1148,  1159,  1159,
    1159,  1164,  1166,  1169,  1174,  1174,  1177,  1179,  1184,  1185,
    1190,  1191,  1196,  1196,  1211,  1214,  1219,  1222,  1227,  1230,
    1235,  1263,  1274,  1279,  1279,  1279,  1287,  1292,  1292,  1292,
    1300,  1300,  1300,  1307,  1310,  1315,  1315,  1315,  1326,  1326,
    1326,  1329,  1349,  1350,  1353,  1361,  1369,  1374,  1380,  1380,
    1386,  1386,  1395,  1395,  1400,  1408,  1416,  1416,  1422,  1422,
    1431,  1431,  1436,  1436,  1442,  1442,  1447,  1447,  1447,  1451,
    1451,  1451,  1458,  1472,  1475,  1480,  1506,  1506,  1514,  1514,
    1529,  1540,  1545
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
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
  "T_HDR_CONTENT_LENGTH", "T_HDR_CONTENT_TYPE", "T_HDR_CSEQ", "T_HDR_DATE",
  "T_HDR_ERROR_INFO", "T_HDR_EVENT", "T_HDR_EXPIRES", "T_HDR_FROM",
  "T_HDR_IN_REPLY_TO", "T_HDR_MAX_FORWARDS", "T_HDR_MIN_EXPIRES",
  "T_HDR_MIME_VERSION", "T_HDR_ORGANIZATION", "T_HDR_P_ASSERTED_IDENTITY",
  "T_HDR_P_PREFERRED_IDENTITY", "T_HDR_PRIORITY", "T_HDR_PRIVACY",
  "T_HDR_PROXY_AUTHENTICATE", "T_HDR_PROXY_AUTHORIZATION",
  "T_HDR_PROXY_REQUIRE", "T_HDR_RACK", "T_HDR_RECORD_ROUTE",
  "T_HDR_REFER_SUB", "T_HDR_REFER_TO", "T_HDR_REFERRED_BY",
  "T_HDR_REPLACES", "T_HDR_REPLY_TO", "T_HDR_REQUIRE", "T_HDR_RETRY_AFTER",
  "T_HDR_ROUTE", "T_HDR_RSEQ", "T_HDR_SERVER", "T_HDR_SIP_ETAG",
  "T_HDR_SIP_IF_MATCH", "T_HDR_SUBJECT", "T_HDR_SUBSCRIPTION_STATE",
  "T_HDR_SUPPORTED", "T_HDR_TIMESTAMP", "T_HDR_TO", "T_HDR_UNSUPPORTED",
  "T_HDR_USER_AGENT", "T_HDR_VIA", "T_HDR_WARNING",
  "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", "T_CRLF", "T_ERROR", "T_NULL",
  "'/'", "':'", "','", "';'", "'='", "'<'", "'>'", "'@'", "'('", "')'",
  "'.'", "'['", "']'", "$accept", "sip_message", "@1", "sip_message2",
  "request", "request_line", "@2", "@3", "sip_version", "@4", "response",
  "status_line", "@5", "@6", "@7", "headers", "header", "hd_accept",
  "hd_accept_encoding", "hd_accept_language", "hd_alert_info", "hd_allow",
  "hd_allow_events", "hd_authentication_info", "hd_authorization",
  "hd_call_id", "hd_call_info", "hd_contact", "hd_content_disp",
  "hd_content_encoding", "hd_content_language", "hd_content_length",
  "hd_content_type", "hd_cseq", "hd_date", "hd_error_info", "hd_event",
  "hd_expires", "hd_from", "hd_in_reply_to", "hd_max_forwards",
  "hd_min_expires", "hd_mime_version", "hd_organization",
  "hd_p_asserted_identity", "hd_p_preferred_identity", "hd_priority",
  "hd_privacy", "hd_proxy_authenticate", "hd_proxy_authorization",
  "hd_proxy_require", "hd_rack", "hd_record_route", "hd_refer_sub",
  "hd_refer_to", "hd_referred_by", "hd_replaces", "hd_reply_to",
  "hd_require", "hd_retry_after", "hd_route", "hd_rseq", "hd_server",
  "hd_sip_etag", "hd_sip_if_match", "hd_subject", "hd_subscription_state",
  "hd_supported", "hd_timestamp", "hd_to", "hd_unsupported",
  "hd_user_agent", "hd_via", "hd_warning", "hd_www_authenticate",
  "hdr_accept", "media_range", "parameters", "parameter", "@8", "@9",
  "parameter_val", "hdr_accept_encoding", "content_coding", "q_factor",
  "hdr_accept_language", "@10", "@11", "language", "@12", "hdr_alert_info",
  "alert_param", "@13", "@14", "hdr_allow", "hdr_call_id", "@15", "@16",
  "call_id", "hdr_call_info", "info_param", "@17", "@18", "hdr_contact",
  "@19", "@20", "contacts", "contact_param", "contact_addr", "@21", "@22",
  "@23", "@24", "@25", "display_name", "hdr_content_disp",
  "hdr_content_encoding", "hdr_content_language", "@26", "@27",
  "hdr_content_length", "@28", "@29", "hdr_content_type", "hdr_cseq",
  "@30", "@31", "hdr_date", "@32", "@33", "hdr_error_info", "error_param",
  "@34", "@35", "hdr_expires", "@36", "@37", "hdr_from", "@38",
  "from_addr", "@39", "@40", "@41", "hdr_in_reply_to", "@42", "@43", "@44",
  "@45", "hdr_max_forwards", "@46", "@47", "hdr_min_expires", "@48", "@49",
  "hdr_mime_version", "hdr_organization", "@50", "@51",
  "hdr_p_asserted_identity", "@52", "hdr_p_preferred_identity", "@53",
  "hdr_priority", "hdr_privacy", "hdr_proxy_require", "hdr_record_route",
  "rec_route", "@54", "@55", "hdr_replaces", "@56", "@57", "hdr_reply_to",
  "@58", "hdr_require", "hdr_retry_after", "@59", "@60", "comment", "@61",
  "@62", "hdr_route", "hdr_server", "server", "hdr_subject", "@63", "@64",
  "hdr_supported", "hdr_timestamp", "@65", "hdr_timestamp1", "timestamp",
  "delay", "hdr_to", "@66", "hdr_unsupported", "hdr_user_agent", "hdr_via",
  "via_parm", "sent_protocol", "host", "@67", "@68", "@69", "@70",
  "ipv6reference", "@71", "@72", "hdr_warning", "warning", "@73", "@74",
  "hdr_unknown", "@75", "@76", "ainfo", "hdr_authentication_info",
  "digest_response", "auth_params", "credentials", "@77", "@78",
  "hdr_authorization", "@79", "digest_challenge", "challenge", "@80",
  "@81", "hdr_proxy_authenticate", "@82", "hdr_proxy_authorization", "@83",
  "hdr_www_authenticate", "@84", "hdr_rseq", "@85", "@86", "hdr_rack",
  "@87", "@88", "hdr_event", "hdr_allow_events", "hdr_subscription_state",
  "hdr_refer_to", "@89", "hdr_referred_by", "@90", "hdr_refer_sub",
  "hdr_sip_etag", "hdr_sip_if_match", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,    47,    58,    44,    59,    61,    60,
      62,    64,    40,    41,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,    97,    99,    98,   100,   100,   100,   101,   103,   104,
     102,   106,   105,   107,   109,   110,   111,   108,   112,   112,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   172,   172,   173,   174,
     174,   175,   176,   177,   175,   178,   178,   179,   179,   180,
     180,   181,   183,   182,   184,   182,   185,   186,   185,   187,
     187,   189,   190,   188,   191,   191,   193,   194,   192,   195,
     195,   196,   196,   198,   199,   197,   201,   202,   200,   200,
     203,   203,   204,   206,   207,   205,   208,   209,   210,   205,
     211,   211,   211,   212,   213,   213,   215,   214,   216,   214,
     218,   219,   217,   220,   222,   223,   221,   225,   226,   224,
     227,   227,   229,   230,   228,   232,   233,   231,   235,   234,
     237,   236,   238,   239,   236,   241,   242,   240,   243,   244,
     240,   246,   247,   245,   249,   250,   248,   251,   253,   254,
     252,   256,   255,   255,   258,   257,   257,   259,   260,   260,
     261,   261,   262,   262,   264,   265,   263,   267,   268,   266,
     270,   269,   271,   271,   273,   274,   272,   275,   276,   277,
     275,   278,   278,   279,   279,   280,   280,   280,   282,   283,
     281,   284,   284,   284,   286,   285,   287,   287,   288,   288,
     289,   289,   291,   290,   292,   292,   293,   293,   294,   294,
     295,   296,   297,   298,   299,   297,   297,   300,   301,   297,
     303,   304,   302,   305,   305,   307,   308,   306,   310,   311,
     309,   312,   313,   313,   314,   314,   315,   315,   317,   316,
     318,   316,   320,   319,   321,   321,   323,   322,   324,   322,
     326,   325,   328,   327,   330,   329,   332,   333,   331,   335,
     336,   334,   337,   338,   338,   339,   341,   340,   343,   342,
     344,   345,   346
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     2,     3,     0,     0,
       6,     0,     4,     3,     0,     0,     0,     7,     0,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     0,     2,     4,     3,     0,
       3,     1,     0,     0,     5,     1,     1,     1,     3,     1,
       2,     2,     0,     2,     0,     4,     1,     0,     3,     1,
       3,     0,     0,     6,     1,     3,     0,     0,     3,     1,
       3,     1,     3,     0,     0,     6,     0,     0,     3,     1,
       1,     3,     2,     0,     0,     3,     0,     0,     0,     7,
       0,     1,     1,     2,     1,     3,     0,     2,     0,     4,
       0,     0,     3,     2,     0,     0,     4,     0,     0,    13,
       1,     3,     0,     0,     6,     0,     0,     3,     0,     3,
       0,     2,     0,     0,     6,     0,     0,     3,     0,     0,
       5,     0,     0,     3,     0,     0,     3,     1,     0,     0,
       3,     0,     2,     3,     0,     2,     3,     1,     1,     3,
       1,     3,     1,     3,     0,     0,     7,     0,     0,     4,
       0,     3,     1,     3,     0,     0,     5,     0,     0,     0,
       5,     1,     3,     1,     2,     1,     2,     4,     0,     0,
       3,     0,     1,     3,     0,     2,     1,     2,     1,     3,
       1,     3,     0,     3,     1,     3,     1,     2,     1,     3,
       3,     5,     1,     0,     0,     5,     1,     0,     0,     5,
       0,     0,     5,     1,     3,     0,     0,     5,     0,     0,
       3,     1,     1,     3,     1,     3,     1,     3,     0,     3,
       0,     3,     0,     2,     1,     3,     0,     3,     0,     3,
       0,     2,     0,     2,     0,     2,     0,     0,     3,     0,
       0,     5,     2,     1,     3,     2,     0,     3,     0,     3,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,    11,     8,     3,     4,    18,
      14,     5,    18,     6,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    13,    12,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   378,     0,     0,     0,   199,     0,   209,     0,
     207,     0,     0,     0,     0,   221,     0,   219,     0,   224,
       0,     0,   413,     0,     0,   201,   381,   382,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,   231,     0,
       0,     0,   239,   240,   199,     0,   250,     0,   199,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,   270,     0,   199,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,   250,     0,
       0,   250,     0,   307,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,   310,     0,     0,     0,     0,
       0,     0,   312,   250,     0,   199,     0,     0,     0,   250,
       0,     0,   250,     0,     0,     0,     0,     0,   250,     0,
     310,     0,     0,     0,     0,     0,     0,   331,     0,     0,
       0,     0,     0,   327,   328,   335,     0,   333,     0,   421,
       0,     0,   422,     0,     0,     0,     0,     0,   199,     0,
       0,   342,     0,     0,     0,     0,     0,     0,   250,     0,
     354,     0,     0,   356,     0,     0,     0,     0,   358,     0,
       0,     0,   373,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    20,     0,   196,    80,     0,   210,    21,
       0,    81,    22,   214,   216,   213,    82,     0,    23,     0,
      83,    24,     0,    84,    25,     0,    85,   202,    26,     0,
      86,    27,   388,   390,   393,    87,    28,   229,   227,    88,
       0,    29,     0,    89,    30,   237,   246,   242,   244,   252,
     251,     0,    90,   253,    31,    91,    32,     0,    92,    33,
     258,   257,    93,    34,   261,    94,   263,    35,    95,    36,
     265,    96,    37,     0,    97,     0,    39,     0,    98,   412,
      38,    99,    40,   276,   100,    41,   280,     0,   199,   101,
      42,   288,   286,   102,    43,   292,   103,    44,   295,   104,
      45,   105,    46,   299,   106,    47,   250,   302,   107,    48,
     250,   305,   108,    49,   109,    50,     0,   110,    51,   396,
     398,   401,   111,    52,   403,   112,    53,     0,   113,    54,
       0,   114,    55,   314,     0,   115,   420,    56,   116,    57,
     199,   117,    58,   199,   118,    59,   318,   119,    60,   199,
     120,     0,    61,   121,    62,   325,   122,    63,   314,   123,
      64,   407,   124,     0,   336,     0,    65,   334,   125,    66,
     126,    67,   127,    68,   339,   128,   415,    69,   129,    70,
       0,   130,    71,   348,   345,   346,   131,    72,   199,   132,
      73,     0,   133,    74,   357,   134,     0,    75,     0,   362,
     370,   199,   366,   135,    76,   375,   376,   136,    77,   405,
      16,    10,    78,   379,   198,   199,     0,   211,   208,     0,
       0,   222,   220,   225,   414,     0,   383,     0,     0,     0,
     228,   234,   232,   238,   241,   245,   247,   255,     0,   262,
       0,     0,   273,   271,   277,   281,   282,   279,     0,   287,
     293,   296,   300,   303,   306,   309,     0,     0,   311,   410,
     313,     0,   417,   419,   199,   321,   311,   327,   332,   408,
     327,   329,   340,   343,     0,   350,   347,   353,   355,     0,
     359,   363,     0,   360,   367,   374,     0,     0,   380,   197,
     200,   215,   218,     0,   206,   205,   203,   384,   389,   386,
     391,   230,     0,     0,   259,   266,     0,     0,     0,   289,
     394,   397,   399,     0,   315,   319,   199,   337,     0,   349,
       0,     0,     0,   371,     0,     0,    17,   199,   204,     0,
       0,   199,   248,     0,   199,   283,   290,     0,   411,     0,
     326,   330,   351,   361,   364,     0,   368,   377,   223,   385,
     387,   235,     0,     0,   274,     0,   395,   199,   365,   372,
     369,   249,     0,   284,   316,     0,     0,     0,     0,   268,
     269
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    15,   143,    10,    14,
      11,    12,    17,   397,   687,    16,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   205,   206,   405,   226,   625,
     728,   696,   209,   210,   408,   212,   213,   619,   415,   620,
     216,   217,   417,   693,   220,   233,   234,   630,   438,   237,
     238,   440,   702,   240,   241,   633,   242,   243,   244,   245,
     635,   246,   703,   752,   487,   249,   252,   254,   255,   638,
     257,   258,   639,   261,   263,   264,   640,   266,   267,   770,
     270,   271,   475,   707,   276,   277,   644,   279,   280,   488,
     645,   708,   755,   282,   283,   649,   648,   736,   285,   286,
     650,   288,   289,   651,   292,   294,   295,   652,   297,   298,
     300,   301,   304,   307,   316,   321,   322,   323,   739,   334,
     335,   664,   337,   338,   342,   344,   345,   667,   355,   565,
     718,   348,   356,   357,   365,   366,   672,   372,   374,   375,
     584,   585,   676,   377,   378,   381,   384,   387,   388,   389,
     601,   722,   758,   724,   760,   602,   682,   745,   391,   392,
     393,   686,   399,   400,   688,   227,   228,   698,   700,   434,
     627,   628,   230,   231,   711,   521,   656,   657,   309,   310,
     312,   313,   395,   396,   350,   351,   669,   318,   319,   713,
     274,   223,   369,   328,   329,   331,   332,   326,   360,   363
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -403
static const yytype_int16 yypact[] =
{
    -403,   121,   113,  -403,     6,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,    38,   126,   492,   137,   552,   148,
    -403,    77,   107,   154,   179,   183,   186,   187,   188,   189,
     190,   191,   194,   195,   196,   200,   201,   202,   206,   207,
     208,   210,   212,   213,   217,   218,   219,   221,   222,   223,
     224,   225,   228,   229,   234,   235,   238,   240,   241,   244,
     247,   252,   253,   254,   256,   257,   260,   261,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   273,   274,   275,
    -403,  -403,    47,   192,    35,    20,   193,   197,   198,    67,
      42,    31,    17,   199,   203,    73,   239,   204,   242,    39,
      34,   205,   245,    23,    81,   246,   249,   209,   112,    29,
      37,   211,   215,    76,    86,   216,   250,    70,   220,    48,
      56,    98,    62,   226,   255,    78,   258,    10,   227,   231,
     124,   232,    58,   259,    68,   233,    11,   237,   262,    97,
    -403,  -403,  -403,   272,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,   130,   139,   -21,  -403,   230,   214,    55,
    -403,   236,    61,   278,   280,  -403,    69,  -403,   281,  -403,
      72,   282,  -403,    75,   283,   243,  -403,  -403,    79,   284,
     286,   248,   289,   291,   288,   292,  -403,    82,  -403,   293,
     294,   285,   290,  -403,  -403,   276,   144,   296,  -403,   297,
     298,  -403,    83,   299,    85,   278,   300,   301,   279,   302,
    -403,   303,   305,   306,   287,   307,   308,   317,   309,  -403,
      89,  -403,   310,  -403,   311,   312,   313,   315,   314,   316,
     138,   318,    91,   288,   319,   320,   330,   321,   322,   331,
     323,  -403,   324,   325,   326,   329,   327,    92,   138,   332,
      93,   138,   333,  -403,   334,   335,  -403,    51,   336,   337,
     251,   338,   340,   248,   341,  -403,    95,   342,   343,   344,
     345,    99,  -403,   144,   346,  -403,   347,   348,   349,   138,
     350,   351,   138,   352,   354,   288,   355,   356,   138,   357,
     358,   339,   359,   360,   361,   393,   362,  -403,   101,   363,
     364,   395,   365,    43,  -403,  -403,    15,  -403,   366,  -403,
     367,   368,  -403,   369,   370,   371,   403,   372,  -403,   373,
     374,  -403,   102,   375,   376,   408,   377,   378,   138,   379,
    -403,   103,   380,  -403,    19,   381,   328,   105,  -403,    13,
     382,   109,  -403,   461,   384,   385,   251,   460,   387,   388,
     463,  -403,   467,  -403,   469,   389,  -403,   470,  -403,  -403,
     471,  -403,  -403,  -403,   390,  -403,  -403,   304,  -403,   391,
    -403,  -403,   474,  -403,  -403,   475,  -403,  -403,  -403,   470,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   394,  -403,  -403,
     473,  -403,   397,  -403,  -403,  -403,   476,   389,  -403,  -403,
    -403,   399,  -403,   389,  -403,  -403,  -403,   471,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   389,  -403,  -403,  -403,
    -403,  -403,  -403,   396,  -403,   481,  -403,   402,  -403,   389,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   404,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   138,  -403,  -403,  -403,
     138,  -403,  -403,  -403,  -403,  -403,   488,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,   490,  -403,  -403,
     493,  -403,  -403,  -403,   406,  -403,   389,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   494,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,   495,  -403,   277,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   389,  -403,  -403,  -403,
     496,  -403,  -403,   184,  -403,   498,  -403,  -403,  -403,  -403,
    -403,   499,  -403,  -403,  -403,  -403,   500,  -403,   501,   412,
    -403,  -403,   417,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   470,  -403,  -403,   278,
     214,  -403,  -403,  -403,  -403,    96,  -403,   470,   470,   497,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   278,  -403,
     502,   504,  -403,  -403,  -403,  -403,  -403,   389,   288,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   470,   470,  -403,  -403,
    -403,   503,   389,   389,  -403,   389,   427,   185,  -403,  -403,
     185,  -403,  -403,  -403,   507,   418,  -403,   389,  -403,   550,
    -403,  -403,   615,   389,  -403,  -403,    13,   555,  -403,   389,
    -403,  -403,  -403,   547,  -403,  -403,  -403,  -403,   553,  -403,
     554,  -403,   548,   633,  -403,  -403,   628,   556,   635,  -403,
    -403,   558,   554,   641,  -403,   389,  -403,  -403,   557,  -403,
     644,   645,   648,  -403,   649,   643,  -403,  -403,  -403,   470,
     470,  -403,  -403,   650,  -403,  -403,  -403,   470,  -403,   564,
     389,  -403,  -403,  -403,  -403,   559,  -403,  -403,   389,  -403,
    -403,   389,   566,   654,   389,   568,  -403,  -403,  -403,  -403,
    -403,  -403,   574,  -403,   389,   657,   576,   659,   651,  -403,
    -403
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,   173,  -403,
    -403,  -403,  -403,  -403,  -403,   652,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,   -89,  -244,  -402,  -403,
    -403,  -403,  -403,   -88,  -277,  -403,  -403,  -403,  -253,  -403,
    -403,   -79,  -403,  -403,  -403,  -403,  -403,  -403,  -280,  -403,
     295,  -403,  -403,  -403,  -403,  -403,  -403,   353,  -403,  -403,
    -403,  -403,  -403,  -403,  -226,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,   383,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -288,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,   540,  -403,  -124,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -346,  -403,
    -403,  -403,  -403,  -127,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,    71,  -403,
     -19,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,    60,
    -403,  -403,  -403,  -403,  -403,   386,  -403,  -403,    14,   392,
    -403,  -403,  -403,  -403,  -403,   398,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,
    -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403,  -403
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -419
static const yytype_int16 yytable[] =
{
     447,   347,   461,   492,   453,   617,   251,   564,   260,   383,
     507,   352,   382,   511,   353,   353,   466,   599,   239,   353,
     451,   214,  -246,   353,   278,  -243,  -236,  -246,  -278,   479,
     296,  -278,   235,  -278,  -301,   268,   211,  -301,   299,  -301,
     265,   540,  -304,   232,   543,  -304,  -212,  -304,   203,   327,
     549,   204,  -267,  -416,  -226,   546,  -416,   330,  -416,   370,
     403,  -418,   371,   336,  -418,   404,  -418,  -320,   229,   376,
    -320,   320,  -320,  -352,   253,  -314,  -352,   308,  -352,   346,
    -314,   536,   281,  -314,  -256,  -392,  -392,   311,  -314,    13,
     588,  -327,  -327,  -285,  -400,  -400,   566,   534,   394,   333,
     593,   694,   354,   354,  -402,  -402,  -246,   354,   600,   215,
    -317,   354,  -278,   293,     4,  -404,  -404,   695,  -301,  -298,
     236,     3,    19,   269,   576,   364,  -304,   563,  -195,     5,
       6,  -338,   515,  -195,    20,   354,   409,  -416,   516,  -341,
     140,   410,   412,   449,  -341,  -418,   486,   413,   450,   449,
     418,  -320,   142,   421,   450,   419,   424,  -352,   422,  -314,
     428,   425,   144,   441,   456,   429,   459,  -314,   442,   457,
     476,   460,   490,   505,   509,   477,   526,   491,   506,   510,
     532,   527,   557,   579,   590,   533,   597,   558,   580,   591,
     604,   598,   145,   207,   218,   605,   208,   219,   221,   224,
     247,   222,   225,   248,   250,   259,   272,   208,   204,   273,
     290,   401,   302,   291,   690,   303,   305,   314,   653,   306,
     315,   324,   654,   402,   325,   697,   699,   339,   358,   567,
     340,   359,   361,   367,   379,   362,   368,   380,   385,   146,
     256,   386,  -260,   262,   647,  -264,   275,   284,  -275,  -291,
     287,   317,  -294,  -409,   710,   699,   343,   594,  -324,   349,
     373,  -406,  -344,   390,   147,  -375,   432,   433,   148,   519,
     520,   149,   150,   151,   152,   153,   154,   354,   674,   155,
     156,   157,   464,   671,   448,   158,   159,   160,     5,   414,
     470,   161,   162,   163,   445,   164,   662,   165,   166,   663,
     437,   407,   167,   168,   169,   665,   170,   171,   172,   173,
     174,   406,   621,   175,   176,   615,   398,   411,   483,   177,
     178,   716,   618,   179,   717,   180,   181,   749,   750,   182,
     473,   427,   183,   495,   498,   756,   503,   184,   185,   186,
     622,   187,   188,   692,   677,   189,   190,   530,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   683,   200,   201,
     202,   416,   420,   423,   426,   430,   691,   431,   709,   637,
     435,   689,   436,   439,   443,   444,   446,   452,   454,   455,
     458,   462,   463,   465,   467,   704,   468,   469,   471,   472,
     474,   478,   480,   481,   482,   484,   555,   485,   561,   489,
     493,   494,   496,   497,   499,   500,   501,   502,   504,   660,
     574,   583,   596,   508,   512,   513,   514,   517,   518,   522,
     715,   523,   525,   528,   529,   551,   531,   535,   537,   538,
     539,   541,   542,   544,   668,   545,   547,   548,   550,  -322,
     552,   553,   554,   556,   559,   560,   562,   568,   569,   570,
     571,   572,   573,   575,   577,   578,   581,   582,   586,   587,
     589,   592,   595,   603,   606,   607,   608,   610,   611,   612,
     613,   614,   740,   204,   225,   208,   616,  -217,   623,   624,
     215,   631,   641,   748,  -243,   629,   236,   751,   636,   642,
     754,   269,   655,   646,   658,   661,   659,   681,   666,   670,
     673,   675,   684,   678,   679,   386,   705,   706,  -323,   701,
     719,   714,   720,   764,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   141,   721,   723,   726,   727,   731,   729,
     730,   732,   733,   735,   737,   738,   734,   742,   747,   743,
     741,   744,   746,   753,   757,   759,   761,   762,   763,   765,
     766,   767,   768,   341,    18,   685,   769,   725,     0,   680,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,   634,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643
};

static const yytype_int16 yycheck[] =
{
     244,   125,   255,   283,   248,   407,    94,   353,    97,   136,
     298,     1,     1,   301,     4,     4,   260,     4,     1,     4,
     246,     1,     5,     4,     1,     8,     9,    10,     5,   273,
       1,     8,     1,    10,     5,     1,     1,     8,     1,    10,
       1,   329,     5,     1,   332,     8,    11,    10,     1,     1,
     338,     4,    13,     5,    12,   335,     8,     1,    10,     1,
      81,     5,     4,     1,     8,    86,    10,     5,     1,     1,
       8,     1,    10,     5,     1,     5,     8,     1,    10,     1,
      10,   325,     1,     5,    11,    18,    19,     1,    10,    83,
     378,    81,    81,    12,    18,    19,    81,   323,     1,     1,
      81,     5,    92,    92,    18,    19,    89,    92,    95,    89,
      12,    92,    89,     1,     1,    18,    19,    21,    89,     7,
      89,     0,    84,    89,   368,     1,    89,    84,    81,    16,
      17,     7,    81,    86,     8,    92,    81,    89,    87,    81,
       3,    86,    81,     5,    86,    89,     8,    86,    10,     5,
      81,    89,     4,    81,    10,    86,    81,    89,    86,    89,
      81,    86,    85,    81,    81,    86,    81,    89,    86,    86,
      81,    86,    81,    81,    81,    86,    81,    86,    86,    86,
      81,    86,    81,    81,    81,    86,    81,    86,    86,    86,
      81,    86,    85,     1,     1,    86,     4,     4,     1,     1,
       1,     4,     4,     4,     1,     1,     1,     4,     4,     4,
       1,    81,     1,     4,   616,     4,     1,     1,   506,     4,
       4,     1,   510,    84,     4,   627,   628,     1,     1,   356,
       4,     4,     1,     1,     1,     4,     4,     4,     1,    85,
       1,     4,     3,     1,   488,     3,     1,     1,     3,     3,
       1,     1,     3,     3,   656,   657,     1,   384,     3,     1,
       1,     3,     3,     1,    85,     3,    18,    19,    85,    18,
      19,    85,    85,    85,    85,    85,    85,    92,    94,    85,
      85,    85,     3,     6,     8,    85,    85,    85,    16,    11,
       3,    85,    85,    85,     9,    85,   540,    85,    85,   543,
      12,    87,    85,    85,    85,   549,    85,    85,    85,    85,
      85,    81,     8,    85,    85,   404,   143,    81,     3,    85,
      85,   667,   410,    85,   670,    85,    85,   729,   730,    85,
      13,    88,    85,     3,     3,   737,     7,    85,    85,    85,
     419,    85,    85,   620,   588,    85,    85,     3,    85,    85,
      85,    85,    85,    85,    85,    85,    85,   601,    85,    85,
      85,    81,    81,    81,    81,    81,   619,    81,   648,   457,
      81,   615,    81,    81,    81,    81,    86,    81,    81,    81,
      81,    81,    81,    81,    81,   638,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,     3,    81,     3,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,   533,
       7,     3,    84,    81,    81,    81,    81,    81,    81,    81,
     664,    81,    81,    81,    81,    86,    81,    81,    81,    81,
      81,    81,    81,    81,   558,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,     3,    81,    81,     7,    81,    81,
       7,     4,   716,     4,     4,     4,    87,    87,     4,     4,
      89,     8,    86,   727,     8,    91,    89,   731,    89,     8,
     734,    89,     4,    89,     4,    89,     3,    85,     4,     4,
       4,     3,    85,     4,     4,     4,     4,     3,    81,    12,
       3,     8,    94,   757,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    84,    20,    81,    90,    90,    86,
      86,     8,    14,     8,    86,     4,    90,     3,     5,     4,
      93,     3,     3,     3,    90,    96,    90,     3,    90,    85,
       3,    85,     3,   123,    12,   605,    15,   686,    -1,   598,
      -1,   657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   313,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     477
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    98,    99,     0,     1,    16,    17,   100,   101,   102,
     105,   107,   108,    83,   106,   103,   112,   109,   112,    84,
       8,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
       3,    81,     4,   104,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,     1,     4,   172,   173,     1,     4,   179,
     180,     1,   182,   183,     1,    89,   187,   188,     1,     4,
     191,     1,     4,   338,     1,     4,   175,   312,   313,     1,
     319,   320,     1,   192,   193,     1,    89,   196,   197,     1,
     200,   201,   203,   204,   205,   206,   208,     1,     4,   212,
       1,   180,   213,     1,   214,   215,     1,   217,   218,     1,
     173,   220,     1,   221,   222,     1,   224,   225,     1,    89,
     227,   228,     1,     4,   337,     1,   231,   232,     1,   234,
     235,     1,   240,   241,     1,   245,   246,     1,   248,   249,
       1,     4,   251,     1,   252,   253,     1,   255,   256,     1,
     257,   258,     1,     4,   259,     1,     4,   260,     1,   325,
     326,     1,   327,   328,     1,     4,   261,     1,   334,   335,
       1,   262,   263,   264,     1,     4,   344,     1,   340,   341,
       1,   342,   343,     1,   266,   267,     1,   269,   270,     1,
       4,   261,   271,     1,   272,   273,     1,   263,   278,     1,
     331,   332,     1,     4,    92,   275,   279,   280,     1,     4,
     345,     1,     4,   346,     1,   281,   282,     1,     4,   339,
       1,     4,   284,     1,   285,   286,     1,   290,   291,     1,
       4,   292,     1,   280,   293,     1,     4,   294,   295,   296,
       1,   305,   306,   307,     1,   329,   330,   110,   105,   309,
     310,    81,    84,    81,    86,   174,    81,    87,   181,    81,
      86,    81,    81,    86,    11,   185,    81,   189,    81,    86,
      81,    81,    86,    81,    81,    86,    81,    88,    81,    86,
      81,    81,    18,    19,   316,    81,    81,    12,   195,    81,
     198,    81,    86,    81,    81,     9,    86,   174,     8,     5,
      10,   211,    81,   174,    81,    81,    81,    86,    81,    81,
      86,   185,    81,    81,     3,    81,   174,    81,    81,    81,
       3,    81,    81,    13,    81,   229,    81,    86,    81,   174,
      81,    81,    81,     3,    81,    81,     8,   211,   236,    81,
      81,    86,   195,    81,    81,     3,    81,    81,     3,    81,
      81,    81,    81,     7,    81,    81,    86,   236,    81,    81,
      86,   236,    81,    81,    81,    81,    87,    81,    81,    18,
      19,   322,    81,    81,   316,    81,    81,    86,    81,    81,
       3,    81,    81,    86,   211,    81,   174,    81,    81,    81,
     236,    81,    81,   236,    81,    81,   195,    81,    81,   236,
      81,    86,    81,    81,    81,     3,    81,    81,    86,    81,
      81,     3,    81,    84,   275,   276,    81,   280,    81,    81,
      81,    81,    81,    81,     7,    81,   174,    81,    81,    81,
      86,    81,    81,     3,   287,   288,    81,    81,   236,    81,
      81,    86,    81,    81,   280,    81,    84,    81,    86,     4,
      95,   297,   302,    81,    81,    86,     3,    81,    81,   322,
       7,    81,    81,     7,     4,   173,    87,   175,   180,   184,
     186,     8,   188,     4,     4,   176,   312,   317,   318,    91,
     194,     8,   197,   202,   204,   207,    89,   180,   216,   219,
     223,    86,     8,   228,   233,   237,    89,   174,   243,   242,
     247,   250,   254,   236,   236,     4,   323,   324,     4,     3,
     263,    89,   174,   174,   268,   174,     4,   274,   263,   333,
       4,     6,   283,     4,    94,     3,   289,   174,     4,     4,
     295,    85,   303,   174,    85,   306,   308,   111,   311,   174,
     175,   185,   181,   190,     5,    21,   178,   175,   314,   175,
     315,    12,   199,   209,   185,     4,     3,   230,   238,   195,
     175,   321,   315,   336,     8,   174,   275,   275,   277,     3,
      94,    84,   298,    20,   300,   297,    81,    90,   177,    86,
      86,    90,     8,    14,    90,     8,   244,    86,     4,   265,
     174,    93,     3,     4,     3,   304,     3,     5,   174,   175,
     175,   174,   210,     3,   174,   239,   175,    90,   299,    96,
     301,    90,     3,    90,   174,    85,     3,    85,     3,    15,
     226
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


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
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 4: /* "T_TOKEN" */
#line 162 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2028 "parser.cxx"
	break;
      case 5: /* "T_QSTRING" */
#line 163 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2033 "parser.cxx"
	break;
      case 6: /* "T_COMMENT" */
#line 164 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2038 "parser.cxx"
	break;
      case 7: /* "T_LINE" */
#line 165 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2043 "parser.cxx"
	break;
      case 8: /* "T_URI" */
#line 166 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2048 "parser.cxx"
	break;
      case 10: /* "T_DISPLAY" */
#line 167 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2053 "parser.cxx"
	break;
      case 11: /* "T_LANG" */
#line 168 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2058 "parser.cxx"
	break;
      case 12: /* "T_WORD" */
#line 169 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2063 "parser.cxx"
	break;
      case 17: /* "T_METHOD" */
#line 170 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2068 "parser.cxx"
	break;
      case 19: /* "T_AUTH_OTHER" */
#line 171 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2073 "parser.cxx"
	break;
      case 20: /* "T_IPV6ADDR" */
#line 172 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2078 "parser.cxx"
	break;
      case 21: /* "T_PARAMVAL" */
#line 173 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2083 "parser.cxx"
	break;
      case 80: /* "T_HDR_UNKNOWN" */
#line 174 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2088 "parser.cxx"
	break;
      case 105: /* "sip_version" */
#line 237 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2093 "parser.cxx"
	break;
      case 173: /* "media_range" */
#line 230 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_media)); delete (yyvaluep->yyt_media); };
#line 2098 "parser.cxx"
	break;
      case 174: /* "parameters" */
#line 233 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_params)); delete (yyvaluep->yyt_params); };
#line 2103 "parser.cxx"
	break;
      case 175: /* "parameter" */
#line 231 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_param)); delete (yyvaluep->yyt_param); };
#line 2108 "parser.cxx"
	break;
      case 178: /* "parameter_val" */
#line 232 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2113 "parser.cxx"
	break;
      case 180: /* "content_coding" */
#line 218 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_coding)); delete (yyvaluep->yyt_coding); };
#line 2118 "parser.cxx"
	break;
      case 185: /* "language" */
#line 229 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_language)); delete (yyvaluep->yyt_language); };
#line 2123 "parser.cxx"
	break;
      case 188: /* "alert_param" */
#line 210 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_alert_param)); delete (yyvaluep->yyt_alert_param); };
#line 2128 "parser.cxx"
	break;
      case 195: /* "call_id" */
#line 212 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2133 "parser.cxx"
	break;
      case 197: /* "info_param" */
#line 228 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_info_param)); delete (yyvaluep->yyt_info_param); };
#line 2138 "parser.cxx"
	break;
      case 203: /* "contacts" */
#line 217 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contacts)); delete (yyvaluep->yyt_contacts); };
#line 2143 "parser.cxx"
	break;
      case 204: /* "contact_param" */
#line 216 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contact)); delete (yyvaluep->yyt_contact); };
#line 2148 "parser.cxx"
	break;
      case 205: /* "contact_addr" */
#line 215 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contact)); delete (yyvaluep->yyt_contact); };
#line 2153 "parser.cxx"
	break;
      case 211: /* "display_name" */
#line 222 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2158 "parser.cxx"
	break;
      case 228: /* "error_param" */
#line 223 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_error_param)); delete (yyvaluep->yyt_error_param); };
#line 2163 "parser.cxx"
	break;
      case 236: /* "from_addr" */
#line 224 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_from_addr)); delete (yyvaluep->yyt_from_addr); };
#line 2168 "parser.cxx"
	break;
      case 263: /* "rec_route" */
#line 234 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_route)); delete (yyvaluep->yyt_route); };
#line 2173 "parser.cxx"
	break;
      case 275: /* "comment" */
#line 214 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2178 "parser.cxx"
	break;
      case 280: /* "server" */
#line 236 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_server)); delete (yyvaluep->yyt_server); };
#line 2183 "parser.cxx"
	break;
      case 295: /* "via_parm" */
#line 238 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2188 "parser.cxx"
	break;
      case 296: /* "sent_protocol" */
#line 235 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2193 "parser.cxx"
	break;
      case 297: /* "host" */
#line 226 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2198 "parser.cxx"
	break;
      case 302: /* "ipv6reference" */
#line 227 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2203 "parser.cxx"
	break;
      case 306: /* "warning" */
#line 239 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_warning)); delete (yyvaluep->yyt_warning); };
#line 2208 "parser.cxx"
	break;
      case 309: /* "hdr_unknown" */
#line 225 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2213 "parser.cxx"
	break;
      case 314: /* "digest_response" */
#line 221 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_dig_resp)); delete (yyvaluep->yyt_dig_resp); };
#line 2218 "parser.cxx"
	break;
      case 315: /* "auth_params" */
#line 211 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_params)); delete (yyvaluep->yyt_params); };
#line 2223 "parser.cxx"
	break;
      case 316: /* "credentials" */
#line 219 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_credentials)); delete (yyvaluep->yyt_credentials); };
#line 2228 "parser.cxx"
	break;
      case 321: /* "digest_challenge" */
#line 220 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_dig_chlg)); delete (yyvaluep->yyt_dig_chlg); };
#line 2233 "parser.cxx"
	break;
      case 322: /* "challenge" */
#line 213 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_challenge)); delete (yyvaluep->yyt_challenge); };
#line 2238 "parser.cxx"
	break;

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
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

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 242 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 247 "parser.yxx"
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
#line 267 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 8:
#line 276 "parser.yxx"
    { CTXT_URI; }
    break;

  case 9:
#line 276 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 10:
#line 277 "parser.yxx"
    {
		  	MSG = new t_request();
			MEMMAN_NEW(MSG);
			((t_request *)MSG)->set_method(*(yyvsp[(1) - (6)].yyt_str));
			((t_request *)MSG)->uri.set_url(*(yyvsp[(3) - (6)].yyt_str));
			MSG->version = *(yyvsp[(5) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (6)].yyt_str)); delete (yyvsp[(1) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (6)].yyt_str)); delete (yyvsp[(3) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (6)].yyt_str)); delete (yyvsp[(5) - (6)].yyt_str);

			if (!((t_request *)MSG)->uri.is_valid()) {
				MEMMAN_DELETE(MSG); delete MSG;
				MSG = NULL;
				YYABORT;
			} }
    break;

  case 11:
#line 294 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 12:
#line 294 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(4) - (4)].yyt_str); }
    break;

  case 13:
#line 298 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 14:
#line 305 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 15:
#line 305 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 16:
#line 306 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 17:
#line 306 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *(yyvsp[(1) - (7)].yyt_str);
			((t_response *)MSG)->code = (yyvsp[(3) - (7)].yyt_ulong);
			((t_response *)MSG)->reason = trim(*(yyvsp[(5) - (7)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (7)].yyt_str)); delete (yyvsp[(1) - (7)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (7)].yyt_str)); delete (yyvsp[(5) - (7)].yyt_str); }
    break;

  case 78:
#line 378 "parser.yxx"
    {
			MSG->add_unknown_header(*(yyvsp[(1) - (4)].yyt_str), trim(*(yyvsp[(3) - (4)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (4)].yyt_str)); delete (yyvsp[(1) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (4)].yyt_str)); delete (yyvsp[(3) - (4)].yyt_str); }
    break;

  case 79:
#line 383 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 80:
#line 385 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 81:
#line 387 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 82:
#line 389 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 83:
#line 391 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 84:
#line 393 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 85:
#line 395 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 86:
#line 397 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 87:
#line 399 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 88:
#line 401 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 89:
#line 403 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 90:
#line 405 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 91:
#line 407 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 92:
#line 409 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 93:
#line 411 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 94:
#line 413 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 95:
#line 415 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 96:
#line 417 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 97:
#line 419 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 98:
#line 421 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 99:
#line 423 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 100:
#line 425 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 101:
#line 427 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 102:
#line 429 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 103:
#line 431 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 104:
#line 433 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 105:
#line 435 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 106:
#line 437 "parser.yxx"
    { PARSE_ERROR("P-Asserted-Identity"); }
    break;

  case 107:
#line 439 "parser.yxx"
    { PARSE_ERROR("P-Preferred-Identity"); }
    break;

  case 108:
#line 441 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 109:
#line 443 "parser.yxx"
    { PARSE_ERROR("Privacy"); }
    break;

  case 110:
#line 445 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 111:
#line 447 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 112:
#line 449 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 113:
#line 451 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 114:
#line 453 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 115:
#line 455 "parser.yxx"
    { PARSE_ERROR("Refer-Sub"); }
    break;

  case 116:
#line 457 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 117:
#line 459 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 118:
#line 461 "parser.yxx"
    { PARSE_ERROR("Replaces"); }
    break;

  case 119:
#line 463 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 120:
#line 465 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 121:
#line 467 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 122:
#line 469 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 123:
#line 471 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 124:
#line 473 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 125:
#line 475 "parser.yxx"
    { PARSE_ERROR("SIP-ETag"); }
    break;

  case 126:
#line 477 "parser.yxx"
    { PARSE_ERROR("SIP-If-Match"); }
    break;

  case 127:
#line 479 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 128:
#line 481 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 129:
#line 483 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 130:
#line 485 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 131:
#line 487 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 132:
#line 489 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 133:
#line 491 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 134:
#line 493 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 135:
#line 495 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 136:
#line 497 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 139:
#line 513 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 144:
#line 523 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 145:
#line 525 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 147:
#line 529 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 150:
#line 535 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 151:
#line 537 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 153:
#line 541 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 154:
#line 543 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 157:
#line 549 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 158:
#line 551 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 159:
#line 553 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 160:
#line 555 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 161:
#line 557 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 163:
#line 561 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 164:
#line 563 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 165:
#line 565 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 168:
#line 571 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 169:
#line 573 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 171:
#line 577 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 172:
#line 579 "parser.yxx"
    { CTXT_URI; }
    break;

  case 174:
#line 583 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 175:
#line 585 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 176:
#line 587 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 177:
#line 589 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 179:
#line 593 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 180:
#line 595 "parser.yxx"
    { CTXT_URI; }
    break;

  case 181:
#line 597 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 185:
#line 605 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 188:
#line 611 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 189:
#line 613 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 193:
#line 621 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 194:
#line 623 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 196:
#line 627 "parser.yxx"
    {
			(yyvsp[(1) - (2)].yyt_media)->add_params(*(yyvsp[(2) - (2)].yyt_params));
			MSG->hdr_accept.add_media(*(yyvsp[(1) - (2)].yyt_media));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_media)); delete (yyvsp[(1) - (2)].yyt_media);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 197:
#line 632 "parser.yxx"
    {
			(yyvsp[(3) - (4)].yyt_media)->add_params(*(yyvsp[(4) - (4)].yyt_params));
			MSG->hdr_accept.add_media(*(yyvsp[(3) - (4)].yyt_media));
			MEMMAN_DELETE((yyvsp[(3) - (4)].yyt_media)); delete (yyvsp[(3) - (4)].yyt_media);
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_params)); delete (yyvsp[(4) - (4)].yyt_params); }
    break;

  case 198:
#line 639 "parser.yxx"
    { (yyval.yyt_media) = new t_media(tolower(*(yyvsp[(1) - (3)].yyt_str)), tolower(*(yyvsp[(3) - (3)].yyt_str)));
					MEMMAN_NEW((yyval.yyt_media));
					MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
					MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 199:
#line 645 "parser.yxx"
    { (yyval.yyt_params) = new list<t_parameter>; MEMMAN_NEW((yyval.yyt_params)); }
    break;

  case 200:
#line 646 "parser.yxx"
    {
			(yyvsp[(1) - (3)].yyt_params)->push_back(*(yyvsp[(3) - (3)].yyt_param));
			(yyval.yyt_params) = (yyvsp[(1) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 201:
#line 652 "parser.yxx"
    {
			(yyval.yyt_param) = new t_parameter(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 202:
#line 656 "parser.yxx"
    { CTXT_PARAMVAL; }
    break;

  case 203:
#line 656 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 204:
#line 656 "parser.yxx"
    {
			(yyval.yyt_param) = new t_parameter(tolower(*(yyvsp[(1) - (5)].yyt_str)), *(yyvsp[(4) - (5)].yyt_str));
			MEMMAN_NEW((yyval.yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_str)); delete (yyvsp[(4) - (5)].yyt_str); }
    break;

  case 205:
#line 663 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 206:
#line 665 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 207:
#line 669 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*(yyvsp[(1) - (1)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_coding)); delete (yyvsp[(1) - (1)].yyt_coding); }
    break;

  case 208:
#line 672 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*(yyvsp[(3) - (3)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_coding)); delete (yyvsp[(3) - (3)].yyt_coding); }
    break;

  case 209:
#line 677 "parser.yxx"
    {
			(yyval.yyt_coding) = new t_coding(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 210:
#line 681 "parser.yxx"
    {
			(yyval.yyt_coding) = new t_coding(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_coding));
			(yyval.yyt_coding)->q = (yyvsp[(2) - (2)].yyt_float);
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str); }
    break;

  case 211:
#line 688 "parser.yxx"
    {
			if ((yyvsp[(2) - (2)].yyt_param)->name != "q") YYERROR;
			(yyval.yyt_float) = atof((yyvsp[(2) - (2)].yyt_param)->value.c_str());
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_param)); delete (yyvsp[(2) - (2)].yyt_param);
			}
    break;

  case 212:
#line 695 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 213:
#line 695 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*(yyvsp[(2) - (2)].yyt_language));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_language)); delete (yyvsp[(2) - (2)].yyt_language); }
    break;

  case 214:
#line 698 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 215:
#line 698 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*(yyvsp[(4) - (4)].yyt_language));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_language)); delete (yyvsp[(4) - (4)].yyt_language); }
    break;

  case 216:
#line 703 "parser.yxx"
    {
			CTXT_INITIAL;
		  	(yyval.yyt_language) = new t_language(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_language));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 217:
#line 708 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 218:
#line 708 "parser.yxx"
    {
			(yyval.yyt_language) = new t_language(tolower(*(yyvsp[(1) - (3)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_language));
			(yyval.yyt_language)->q = (yyvsp[(3) - (3)].yyt_float);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str); }
    break;

  case 219:
#line 715 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*(yyvsp[(1) - (1)].yyt_alert_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_alert_param)); delete (yyvsp[(1) - (1)].yyt_alert_param); }
    break;

  case 220:
#line 718 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*(yyvsp[(3) - (3)].yyt_alert_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_alert_param)); delete (yyvsp[(3) - (3)].yyt_alert_param); }
    break;

  case 221:
#line 723 "parser.yxx"
    { CTXT_URI; }
    break;

  case 222:
#line 723 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 223:
#line 723 "parser.yxx"
    {
		  	(yyval.yyt_alert_param) = new t_alert_param();
			MEMMAN_NEW((yyval.yyt_alert_param));
			(yyval.yyt_alert_param)->uri.set_url(*(yyvsp[(3) - (6)].yyt_str));
			(yyval.yyt_alert_param)->parameter_list = *(yyvsp[(6) - (6)].yyt_params);

			if (!(yyval.yyt_alert_param)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_alert_param)); delete (yyval.yyt_alert_param);
				YYERROR;
			}
			 
			MEMMAN_DELETE((yyvsp[(3) - (6)].yyt_str)); delete (yyvsp[(3) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(6) - (6)].yyt_params)); delete (yyvsp[(6) - (6)].yyt_params); }
    break;

  case 224:
#line 738 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 225:
#line 741 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*(yyvsp[(3) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 226:
#line 746 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 227:
#line 746 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 228:
#line 746 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*(yyvsp[(2) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 229:
#line 751 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 230:
#line 752 "parser.yxx"
    {
			(yyval.yyt_str) = new string(*(yyvsp[(1) - (3)].yyt_str) + '@' + *(yyvsp[(3) - (3)].yyt_str));
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 231:
#line 759 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*(yyvsp[(1) - (1)].yyt_info_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_info_param)); delete (yyvsp[(1) - (1)].yyt_info_param); }
    break;

  case 232:
#line 762 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*(yyvsp[(3) - (3)].yyt_info_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_info_param)); delete (yyvsp[(3) - (3)].yyt_info_param); }
    break;

  case 233:
#line 767 "parser.yxx"
    { CTXT_URI; }
    break;

  case 234:
#line 767 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 235:
#line 767 "parser.yxx"
    {
		  	(yyval.yyt_info_param) = new t_info_param();
			MEMMAN_NEW((yyval.yyt_info_param));
			(yyval.yyt_info_param)->uri.set_url(*(yyvsp[(3) - (6)].yyt_str));
			(yyval.yyt_info_param)->parameter_list = *(yyvsp[(6) - (6)].yyt_params);

			if (!(yyval.yyt_info_param)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_info_param)); delete (yyval.yyt_info_param);
				YYERROR;
			}
			
			MEMMAN_DELETE((yyvsp[(3) - (6)].yyt_str)); delete (yyvsp[(3) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(6) - (6)].yyt_params)); delete (yyvsp[(6) - (6)].yyt_params); }
    break;

  case 236:
#line 782 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 237:
#line 782 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 238:
#line 782 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 239:
#line 784 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*(yyvsp[(1) - (1)].yyt_contacts));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_contacts)); delete (yyvsp[(1) - (1)].yyt_contacts); }
    break;

  case 240:
#line 789 "parser.yxx"
    {
			(yyval.yyt_contacts) = new list<t_contact_param>;
			MEMMAN_NEW((yyval.yyt_contacts));
			(yyval.yyt_contacts)->push_back(*(yyvsp[(1) - (1)].yyt_contact));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_contact)); delete (yyvsp[(1) - (1)].yyt_contact); }
    break;

  case 241:
#line 794 "parser.yxx"
    {
			(yyvsp[(1) - (3)].yyt_contacts)->push_back(*(yyvsp[(3) - (3)].yyt_contact));
			(yyval.yyt_contacts) = (yyvsp[(1) - (3)].yyt_contacts);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_contact)); delete (yyvsp[(3) - (3)].yyt_contact); }
    break;

  case 242:
#line 800 "parser.yxx"
    {
			(yyval.yyt_contact) = (yyvsp[(1) - (2)].yyt_contact);
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(2) - (2)].yyt_params)->begin(); i != (yyvsp[(2) - (2)].yyt_params)->end(); i++) {
				if (i->name == "q") {
					(yyval.yyt_contact)->set_qvalue(atof(i->value.c_str()));
				} else if (i->name == "expires") {
					(yyval.yyt_contact)->set_expires(strtoul(
						i->value.c_str(), NULL, 10));
				} else {
					(yyval.yyt_contact)->add_extension(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 243:
#line 816 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 244:
#line 816 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 245:
#line 816 "parser.yxx"
    {
			(yyval.yyt_contact) = new t_contact_param();
			MEMMAN_NEW((yyval.yyt_contact));
			(yyval.yyt_contact)->uri.set_url(*(yyvsp[(2) - (3)].yyt_str));

			if (!(yyval.yyt_contact)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_contact)); delete (yyval.yyt_contact);
				YYERROR;
			}
			
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 246:
#line 827 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 247:
#line 827 "parser.yxx"
    { CTXT_URI; }
    break;

  case 248:
#line 827 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 249:
#line 827 "parser.yxx"
    {
			(yyval.yyt_contact) = new t_contact_param();
			MEMMAN_NEW((yyval.yyt_contact));
			(yyval.yyt_contact)->display = *(yyvsp[(2) - (7)].yyt_str);
			(yyval.yyt_contact)->uri.set_url(*(yyvsp[(5) - (7)].yyt_str));

			if (!(yyval.yyt_contact)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_contact)); delete (yyval.yyt_contact);
				YYERROR;
			}
			 
			MEMMAN_DELETE((yyvsp[(2) - (7)].yyt_str)); delete (yyvsp[(2) - (7)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (7)].yyt_str)); delete (yyvsp[(5) - (7)].yyt_str); }
    break;

  case 250:
#line 842 "parser.yxx"
    { (yyval.yyt_str) = new string(); MEMMAN_NEW((yyval.yyt_str)); }
    break;

  case 251:
#line 843 "parser.yxx"
    {
			(yyval.yyt_str) = new string(rtrim(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 252:
#line 847 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 253:
#line 850 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			MSG->hdr_content_disp.set_params(*(yyvsp[(2) - (2)].yyt_params));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 254:
#line 857 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*(yyvsp[(1) - (1)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_coding)); delete (yyvsp[(1) - (1)].yyt_coding); }
    break;

  case 255:
#line 860 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*(yyvsp[(3) - (3)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_coding)); delete (yyvsp[(3) - (3)].yyt_coding); }
    break;

  case 256:
#line 865 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 257:
#line 865 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*(yyvsp[(2) - (2)].yyt_language));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_language)); delete (yyvsp[(2) - (2)].yyt_language); }
    break;

  case 258:
#line 868 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 259:
#line 868 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*(yyvsp[(4) - (4)].yyt_language));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_language)); delete (yyvsp[(4) - (4)].yyt_language); }
    break;

  case 260:
#line 873 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 261:
#line 873 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 262:
#line 873 "parser.yxx"
    {
			MSG->hdr_content_length.set_length((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 263:
#line 877 "parser.yxx"
    {
			(yyvsp[(1) - (2)].yyt_media)->add_params(*(yyvsp[(2) - (2)].yyt_params));
			MSG->hdr_content_type.set_media(*(yyvsp[(1) - (2)].yyt_media));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_media)); delete (yyvsp[(1) - (2)].yyt_media);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 264:
#line 884 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 265:
#line 884 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 266:
#line 884 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr((yyvsp[(2) - (4)].yyt_ulong));
			MSG->hdr_cseq.set_method(*(yyvsp[(4) - (4)].yyt_str));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_str)); delete (yyvsp[(4) - (4)].yyt_str); }
    break;

  case 267:
#line 890 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 268:
#line 893 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 269:
#line 893 "parser.yxx"
    {
			struct tm t;
			t.tm_mday = (yyvsp[(4) - (13)].yyt_ulong);
			t.tm_mon = (yyvsp[(5) - (13)].yyt_int);
			t.tm_year = (yyvsp[(6) - (13)].yyt_ulong) - 1900;
			t.tm_hour = (yyvsp[(7) - (13)].yyt_ulong);
			t.tm_min = (yyvsp[(9) - (13)].yyt_ulong);
			t.tm_sec = (yyvsp[(11) - (13)].yyt_ulong);
			MSG->hdr_date.set_date_gm(&t); }
    break;

  case 270:
#line 904 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*(yyvsp[(1) - (1)].yyt_error_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_error_param)); delete (yyvsp[(1) - (1)].yyt_error_param); }
    break;

  case 271:
#line 907 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*(yyvsp[(3) - (3)].yyt_error_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_error_param)); delete (yyvsp[(3) - (3)].yyt_error_param); }
    break;

  case 272:
#line 912 "parser.yxx"
    { CTXT_URI; }
    break;

  case 273:
#line 912 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 274:
#line 912 "parser.yxx"
    {
		  	(yyval.yyt_error_param) = new t_error_param();
			MEMMAN_NEW((yyval.yyt_error_param));
			(yyval.yyt_error_param)->uri.set_url(*(yyvsp[(3) - (6)].yyt_str));
			(yyval.yyt_error_param)->parameter_list = *(yyvsp[(6) - (6)].yyt_params);

			if (!(yyval.yyt_error_param)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_error_param)); delete (yyval.yyt_error_param);
				YYERROR;
			}
			
			MEMMAN_DELETE((yyvsp[(3) - (6)].yyt_str)); delete (yyvsp[(3) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(6) - (6)].yyt_params)); delete (yyvsp[(6) - (6)].yyt_params); }
    break;

  case 275:
#line 927 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 276:
#line 927 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 277:
#line 927 "parser.yxx"
    {
			MSG->hdr_expires.set_time((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 278:
#line 931 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 279:
#line 931 "parser.yxx"
    {
			MSG->hdr_from.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_from.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(3) - (3)].yyt_params)->begin(); i != (yyvsp[(3) - (3)].yyt_params)->end(); i++) {
				if (i->name == "tag") {
					MSG->hdr_from.set_tag(i->value);
				} else {
					MSG->hdr_from.add_param(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 280:
#line 946 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 281:
#line 946 "parser.yxx"
    {
			(yyval.yyt_from_addr) = new t_identity();
			MEMMAN_NEW((yyval.yyt_from_addr));
			(yyval.yyt_from_addr)->set_uri(*(yyvsp[(1) - (2)].yyt_str));

			if (!(yyval.yyt_from_addr)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_from_addr)); delete (yyval.yyt_from_addr);
				YYERROR;
			}
			
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str); }
    break;

  case 282:
#line 957 "parser.yxx"
    { CTXT_URI; }
    break;

  case 283:
#line 957 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 284:
#line 957 "parser.yxx"
    {
			(yyval.yyt_from_addr) = new t_identity();
			MEMMAN_NEW((yyval.yyt_from_addr));
			(yyval.yyt_from_addr)->set_display(*(yyvsp[(1) - (6)].yyt_str));
			(yyval.yyt_from_addr)->set_uri(*(yyvsp[(4) - (6)].yyt_str));

			if (!(yyval.yyt_from_addr)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_from_addr)); delete (yyval.yyt_from_addr);
				YYERROR;
			}
			
			MEMMAN_DELETE((yyvsp[(1) - (6)].yyt_str)); delete (yyvsp[(1) - (6)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (6)].yyt_str)); delete (yyvsp[(4) - (6)].yyt_str); }
    break;

  case 285:
#line 972 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 286:
#line 972 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 287:
#line 972 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*(yyvsp[(2) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 288:
#line 975 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 289:
#line 975 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 290:
#line 975 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*(yyvsp[(4) - (5)].yyt_str));
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_str)); delete (yyvsp[(4) - (5)].yyt_str); }
    break;

  case 291:
#line 980 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 292:
#line 980 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 293:
#line 980 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 294:
#line 984 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 295:
#line 984 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 296:
#line 984 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 297:
#line 988 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 298:
#line 993 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 299:
#line 993 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 300:
#line 993 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*(yyvsp[(2) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 301:
#line 998 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 302:
#line 998 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*(yyvsp[(2) - (2)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_from_addr)); delete (yyvsp[(2) - (2)].yyt_from_addr); }
    break;

  case 303:
#line 1001 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*(yyvsp[(3) - (3)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_from_addr)); delete (yyvsp[(3) - (3)].yyt_from_addr); }
    break;

  case 304:
#line 1006 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 305:
#line 1006 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*(yyvsp[(2) - (2)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_from_addr)); delete (yyvsp[(2) - (2)].yyt_from_addr); }
    break;

  case 306:
#line 1009 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*(yyvsp[(3) - (3)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_from_addr)); delete (yyvsp[(3) - (3)].yyt_from_addr); }
    break;

  case 307:
#line 1014 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 308:
#line 1019 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 309:
#line 1022 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 310:
#line 1027 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 311:
#line 1030 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 312:
#line 1035 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*(yyvsp[(1) - (1)].yyt_route));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_route)); delete (yyvsp[(1) - (1)].yyt_route); }
    break;

  case 313:
#line 1038 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*(yyvsp[(3) - (3)].yyt_route));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_route)); delete (yyvsp[(3) - (3)].yyt_route); }
    break;

  case 314:
#line 1043 "parser.yxx"
    { CTXT_URI; }
    break;

  case 315:
#line 1043 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 316:
#line 1044 "parser.yxx"
    {
			(yyval.yyt_route) = new t_route;
			MEMMAN_NEW((yyval.yyt_route));
			(yyval.yyt_route)->display = *(yyvsp[(2) - (7)].yyt_str);
			(yyval.yyt_route)->uri.set_url(*(yyvsp[(4) - (7)].yyt_str));
			(yyval.yyt_route)->set_params(*(yyvsp[(7) - (7)].yyt_params));

			if (!(yyval.yyt_route)->uri.is_valid()) {
				MEMMAN_DELETE((yyval.yyt_route)); delete (yyval.yyt_route);
				YYERROR;
			}
			 
			MEMMAN_DELETE((yyvsp[(2) - (7)].yyt_str)); delete (yyvsp[(2) - (7)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (7)].yyt_str)); delete (yyvsp[(4) - (7)].yyt_str);
			MEMMAN_DELETE((yyvsp[(7) - (7)].yyt_params)); delete (yyvsp[(7) - (7)].yyt_params); }
    break;

  case 317:
#line 1061 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 318:
#line 1061 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 319:
#line 1061 "parser.yxx"
    {
			MSG->hdr_replaces.set_call_id(*(yyvsp[(2) - (4)].yyt_str));
			
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(4) - (4)].yyt_params)->begin(); i != (yyvsp[(4) - (4)].yyt_params)->end(); i++) {
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
			
			MEMMAN_DELETE((yyvsp[(2) - (4)].yyt_str)); delete (yyvsp[(2) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_params)); delete (yyvsp[(4) - (4)].yyt_params); }
    break;

  case 320:
#line 1083 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 321:
#line 1083 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_reply_to.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			MSG->hdr_reply_to.set_params(*(yyvsp[(3) - (3)].yyt_params));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 322:
#line 1091 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 323:
#line 1094 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 324:
#line 1099 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 325:
#line 1099 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 326:
#line 1099 "parser.yxx"
    {
			MSG->hdr_retry_after.set_time((yyvsp[(2) - (5)].yyt_ulong));
			MSG->hdr_retry_after.set_comment(*(yyvsp[(4) - (5)].yyt_str));
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(5) - (5)].yyt_params)->begin(); i != (yyvsp[(5) - (5)].yyt_params)->end(); i++) {
				if (i->name == "duration") {
					int d = strtoul(i->value.c_str(), NULL, 10);
					MSG->hdr_retry_after.set_duration(d);
				} else {
					MSG->hdr_retry_after.add_param(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_str)); delete (yyvsp[(4) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (5)].yyt_params)); delete (yyvsp[(5) - (5)].yyt_params); }
    break;

  case 327:
#line 1115 "parser.yxx"
    { (yyval.yyt_str) = new string(); MEMMAN_NEW((yyval.yyt_str)); }
    break;

  case 328:
#line 1116 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 329:
#line 1116 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 330:
#line 1116 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(3) - (5)].yyt_str); }
    break;

  case 331:
#line 1120 "parser.yxx"
    {
			MSG->hdr_route.add_route(*(yyvsp[(1) - (1)].yyt_route));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_route)); delete (yyvsp[(1) - (1)].yyt_route); }
    break;

  case 332:
#line 1123 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*(yyvsp[(3) - (3)].yyt_route));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_route)); delete (yyvsp[(3) - (3)].yyt_route); }
    break;

  case 333:
#line 1128 "parser.yxx"
    {
			MSG->hdr_server.add_server(*(yyvsp[(1) - (1)].yyt_server));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_server)); delete (yyvsp[(1) - (1)].yyt_server); }
    break;

  case 334:
#line 1131 "parser.yxx"
    {
			MSG->hdr_server.add_server(*(yyvsp[(2) - (2)].yyt_server));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_server)); delete (yyvsp[(2) - (2)].yyt_server); }
    break;

  case 335:
#line 1136 "parser.yxx"
    {
			(yyval.yyt_server) = new t_server();
			MEMMAN_NEW((yyval.yyt_server));
			(yyval.yyt_server)->comment = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 336:
#line 1141 "parser.yxx"
    {
			(yyval.yyt_server) = new t_server();
			MEMMAN_NEW((yyval.yyt_server));
			(yyval.yyt_server)->product = *(yyvsp[(1) - (2)].yyt_str);
			(yyval.yyt_server)->comment = *(yyvsp[(2) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_str)); delete (yyvsp[(2) - (2)].yyt_str); }
    break;

  case 337:
#line 1148 "parser.yxx"
    {
			(yyval.yyt_server) = new t_server();
			MEMMAN_NEW((yyval.yyt_server));
			(yyval.yyt_server)->product = *(yyvsp[(1) - (4)].yyt_str);
			(yyval.yyt_server)->version = *(yyvsp[(3) - (4)].yyt_str);
			(yyval.yyt_server)->comment = *(yyvsp[(4) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (4)].yyt_str)); delete (yyvsp[(1) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (4)].yyt_str)); delete (yyvsp[(3) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_str)); delete (yyvsp[(4) - (4)].yyt_str); }
    break;

  case 338:
#line 1159 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 339:
#line 1159 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 340:
#line 1159 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*(yyvsp[(2) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 341:
#line 1164 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 342:
#line 1166 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 343:
#line 1169 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 344:
#line 1174 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 345:
#line 1174 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 346:
#line 1177 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp((yyvsp[(1) - (1)].yyt_float)); }
    break;

  case 347:
#line 1179 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp((yyvsp[(1) - (2)].yyt_float));
			MSG->hdr_timestamp.set_delay((yyvsp[(2) - (2)].yyt_float)); }
    break;

  case 348:
#line 1184 "parser.yxx"
    { (yyval.yyt_float) = (yyvsp[(1) - (1)].yyt_ulong); }
    break;

  case 349:
#line 1185 "parser.yxx"
    {
			string s = int2str((yyvsp[(1) - (3)].yyt_ulong)) + '.' + int2str((yyvsp[(3) - (3)].yyt_ulong));
			(yyval.yyt_float) = atof(s.c_str()); }
    break;

  case 350:
#line 1190 "parser.yxx"
    { (yyval.yyt_float) = (yyvsp[(1) - (1)].yyt_ulong); }
    break;

  case 351:
#line 1191 "parser.yxx"
    {
			string s = int2str((yyvsp[(1) - (3)].yyt_ulong)) + '.' + int2str((yyvsp[(3) - (3)].yyt_ulong));
			(yyval.yyt_float) = atof(s.c_str()); }
    break;

  case 352:
#line 1196 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 353:
#line 1196 "parser.yxx"
    {
			MSG->hdr_to.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_to.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(3) - (3)].yyt_params)->begin(); i != (yyvsp[(3) - (3)].yyt_params)->end(); i++) {
				if (i->name == "tag") {
					MSG->hdr_to.set_tag(i->value);
				} else {
					MSG->hdr_to.add_param(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 354:
#line 1211 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 355:
#line 1214 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 356:
#line 1219 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*(yyvsp[(1) - (1)].yyt_server));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_server)); delete (yyvsp[(1) - (1)].yyt_server); }
    break;

  case 357:
#line 1222 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*(yyvsp[(2) - (2)].yyt_server));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_server)); delete (yyvsp[(2) - (2)].yyt_server); }
    break;

  case 358:
#line 1227 "parser.yxx"
    {
			MSG->hdr_via.add_via(*(yyvsp[(1) - (1)].yyt_via));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_via)); delete (yyvsp[(1) - (1)].yyt_via); }
    break;

  case 359:
#line 1230 "parser.yxx"
    {
			MSG->hdr_via.add_via(*(yyvsp[(3) - (3)].yyt_via));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_via)); delete (yyvsp[(3) - (3)].yyt_via); }
    break;

  case 360:
#line 1235 "parser.yxx"
    {
			(yyval.yyt_via) = (yyvsp[(1) - (3)].yyt_via);
			(yyval.yyt_via)->host = (yyvsp[(2) - (3)].yyt_via)->host;
			(yyval.yyt_via)->port = (yyvsp[(2) - (3)].yyt_via)->port;
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(3) - (3)].yyt_params)->begin(); i != (yyvsp[(3) - (3)].yyt_params)->end(); i++) {
				if (i->name == "ttl") {
					(yyval.yyt_via)->ttl = atoi(i->value.c_str());
				} else if (i->name == "maddr") {
					(yyval.yyt_via)->maddr = i->value;
				} else if (i->name == "received") {
					(yyval.yyt_via)->received = i->value;
				} else if (i->name == "branch") {
					(yyval.yyt_via)->branch = i->value;
				} else if (i->name == "rport") {
					(yyval.yyt_via)->rport_present = true;
					if (i->type == t_parameter::VALUE) {
						(yyval.yyt_via)->rport =
							atoi(i->value.c_str());
					}
				} else {
					(yyval.yyt_via)->add_extension(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_via)); delete (yyvsp[(2) - (3)].yyt_via);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 361:
#line 1263 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->protocol_name = toupper(*(yyvsp[(1) - (5)].yyt_str));
			(yyval.yyt_via)->protocol_version = *(yyvsp[(3) - (5)].yyt_str);
			(yyval.yyt_via)->transport = toupper(*(yyvsp[(5) - (5)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (5)].yyt_str)); delete (yyvsp[(3) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (5)].yyt_str)); delete (yyvsp[(5) - (5)].yyt_str); }
    break;

  case 362:
#line 1274 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 363:
#line 1279 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 364:
#line 1279 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 365:
#line 1279 "parser.yxx"
    {
			if ((yyvsp[(4) - (5)].yyt_ulong) > 65535) YYERROR;
			
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (5)].yyt_str);
			(yyval.yyt_via)->port = (yyvsp[(4) - (5)].yyt_ulong);
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str); }
    break;

  case 366:
#line 1287 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 367:
#line 1292 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 368:
#line 1292 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 369:
#line 1292 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (5)].yyt_str);
			(yyval.yyt_via)->port = (yyvsp[(4) - (5)].yyt_ulong);
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str); }
    break;

  case 370:
#line 1300 "parser.yxx"
    { CTXT_IPV6ADDR; }
    break;

  case 371:
#line 1300 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 372:
#line 1300 "parser.yxx"
    {
			// TODO: check correct format of IPv6 address
			(yyval.yyt_str) = new string('[' + *(yyvsp[(3) - (5)].yyt_str) + ']');
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(3) - (5)].yyt_str)); }
    break;

  case 373:
#line 1307 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*(yyvsp[(1) - (1)].yyt_warning));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_warning)); delete (yyvsp[(1) - (1)].yyt_warning); }
    break;

  case 374:
#line 1310 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*(yyvsp[(3) - (3)].yyt_warning));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_warning)); delete (yyvsp[(3) - (3)].yyt_warning); }
    break;

  case 375:
#line 1315 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 376:
#line 1315 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 377:
#line 1315 "parser.yxx"
    {
			(yyval.yyt_warning) = new t_warning();
			MEMMAN_NEW((yyval.yyt_warning));
			(yyval.yyt_warning)->code = (yyvsp[(2) - (5)].yyt_ulong);
			(yyval.yyt_warning)->host = (yyvsp[(4) - (5)].yyt_via)->host;
			(yyval.yyt_warning)->port = (yyvsp[(4) - (5)].yyt_via)->port;
			(yyval.yyt_warning)->text = *(yyvsp[(5) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_via)); delete (yyvsp[(4) - (5)].yyt_via);
			MEMMAN_DELETE((yyvsp[(5) - (5)].yyt_str)); delete (yyvsp[(5) - (5)].yyt_str); }
    break;

  case 378:
#line 1326 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 379:
#line 1326 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 380:
#line 1326 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 381:
#line 1329 "parser.yxx"
    {
			if ((yyvsp[(1) - (1)].yyt_param)->name == "nextnonce")
				MSG->hdr_auth_info.set_next_nonce((yyvsp[(1) - (1)].yyt_param)->value);
		 	else if ((yyvsp[(1) - (1)].yyt_param)->name == "qop")
				MSG->hdr_auth_info.set_message_qop((yyvsp[(1) - (1)].yyt_param)->value);
			else if ((yyvsp[(1) - (1)].yyt_param)->name == "rspauth")
				MSG->hdr_auth_info.set_response_auth((yyvsp[(1) - (1)].yyt_param)->value);
			else if ((yyvsp[(1) - (1)].yyt_param)->name == "cnonce")
				MSG->hdr_auth_info.set_cnonce((yyvsp[(1) - (1)].yyt_param)->value);
			else if ((yyvsp[(1) - (1)].yyt_param)->name == "nc") {
				MSG->hdr_auth_info.set_nonce_count(
							hex2int((yyvsp[(1) - (1)].yyt_param)->value));
			}
			else {
				YYERROR;
			}

			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 384:
#line 1353 "parser.yxx"
    {
			(yyval.yyt_dig_resp) = new t_digest_response();
			MEMMAN_NEW((yyval.yyt_dig_resp));
			if (!(yyval.yyt_dig_resp)->set_attr(*(yyvsp[(1) - (1)].yyt_param))) {
				MEMMAN_DELETE((yyval.yyt_dig_resp)); delete (yyval.yyt_dig_resp);
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 385:
#line 1361 "parser.yxx"
    {
			(yyval.yyt_dig_resp) = (yyvsp[(1) - (3)].yyt_dig_resp);
			if (!(yyval.yyt_dig_resp)->set_attr(*(yyvsp[(3) - (3)].yyt_param))) {
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 386:
#line 1369 "parser.yxx"
    {
			(yyval.yyt_params) = new list<t_parameter>;
			MEMMAN_NEW((yyval.yyt_params));
			(yyval.yyt_params)->push_back(*(yyvsp[(1) - (1)].yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 387:
#line 1374 "parser.yxx"
    {
			(yyval.yyt_params) = (yyvsp[(1) - (3)].yyt_params);
			(yyval.yyt_params)->push_back(*(yyvsp[(3) - (3)].yyt_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 388:
#line 1380 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 389:
#line 1380 "parser.yxx"
    {
			(yyval.yyt_credentials) = new t_credentials;
			MEMMAN_NEW((yyval.yyt_credentials));
			(yyval.yyt_credentials)->auth_scheme = AUTH_DIGEST;
			(yyval.yyt_credentials)->digest_response = *(yyvsp[(3) - (3)].yyt_dig_resp);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_dig_resp)); delete (yyvsp[(3) - (3)].yyt_dig_resp); }
    break;

  case 390:
#line 1386 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 391:
#line 1386 "parser.yxx"
    {
			(yyval.yyt_credentials) = new t_credentials;
			MEMMAN_NEW((yyval.yyt_credentials));
			(yyval.yyt_credentials)->auth_scheme = *(yyvsp[(1) - (3)].yyt_str);
			(yyval.yyt_credentials)->auth_params = *(yyvsp[(3) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 392:
#line 1395 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 393:
#line 1395 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*(yyvsp[(2) - (2)].yyt_credentials));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_credentials)); delete (yyvsp[(2) - (2)].yyt_credentials); }
    break;

  case 394:
#line 1400 "parser.yxx"
    {
			(yyval.yyt_dig_chlg) = new t_digest_challenge();
			MEMMAN_NEW((yyval.yyt_dig_chlg));
			if (!(yyval.yyt_dig_chlg)->set_attr(*(yyvsp[(1) - (1)].yyt_param))) {
				MEMMAN_DELETE((yyval.yyt_dig_chlg)); delete (yyval.yyt_dig_chlg);
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 395:
#line 1408 "parser.yxx"
    {
			(yyval.yyt_dig_chlg) = (yyvsp[(1) - (3)].yyt_dig_chlg);
			if (!(yyval.yyt_dig_chlg)->set_attr(*(yyvsp[(3) - (3)].yyt_param))) {
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 396:
#line 1416 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 397:
#line 1416 "parser.yxx"
    {
			(yyval.yyt_challenge) = new t_challenge;
			MEMMAN_NEW((yyval.yyt_challenge));
			(yyval.yyt_challenge)->auth_scheme = AUTH_DIGEST;
			(yyval.yyt_challenge)->digest_challenge = *(yyvsp[(3) - (3)].yyt_dig_chlg);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_dig_chlg)); delete (yyvsp[(3) - (3)].yyt_dig_chlg); }
    break;

  case 398:
#line 1422 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 399:
#line 1422 "parser.yxx"
    {
			(yyval.yyt_challenge) = new t_challenge;
			MEMMAN_NEW((yyval.yyt_challenge));
			(yyval.yyt_challenge)->auth_scheme = *(yyvsp[(1) - (3)].yyt_str);
			(yyval.yyt_challenge)->auth_params = *(yyvsp[(3) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 400:
#line 1431 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 401:
#line 1431 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*(yyvsp[(2) - (2)].yyt_challenge));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_challenge)); delete (yyvsp[(2) - (2)].yyt_challenge); }
    break;

  case 402:
#line 1436 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 403:
#line 1436 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*(yyvsp[(2) - (2)].yyt_credentials));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_credentials)); delete (yyvsp[(2) - (2)].yyt_credentials); }
    break;

  case 404:
#line 1442 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 405:
#line 1442 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*(yyvsp[(2) - (2)].yyt_challenge));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_challenge)); delete (yyvsp[(2) - (2)].yyt_challenge); }
    break;

  case 406:
#line 1447 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 407:
#line 1447 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 408:
#line 1447 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 409:
#line 1451 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 410:
#line 1451 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 411:
#line 1451 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr((yyvsp[(2) - (5)].yyt_ulong));
			MSG->hdr_rack.set_cseq_nr((yyvsp[(3) - (5)].yyt_ulong));
			MSG->hdr_rack.set_method(*(yyvsp[(5) - (5)].yyt_str));
			MEMMAN_DELETE((yyvsp[(5) - (5)].yyt_str)); delete (yyvsp[(5) - (5)].yyt_str); }
    break;

  case 412:
#line 1458 "parser.yxx"
    {
			MSG->hdr_event.set_event_type(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(2) - (2)].yyt_params)->begin(); i != (yyvsp[(2) - (2)].yyt_params)->end(); i++) {
				if (i->name == "id") {
					MSG->hdr_event.set_id(i->value);
				} else {
					MSG->hdr_event.add_event_param(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 413:
#line 1472 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*(yyvsp[(1) - (1)].yyt_str)));
				MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 414:
#line 1475 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*(yyvsp[(3) - (3)].yyt_str)));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 415:
#line 1480 "parser.yxx"
    {
				MSG->hdr_subscription_state.set_substate(tolower(*(yyvsp[(1) - (2)].yyt_str)));
				list<t_parameter>::const_iterator i;
				for (i = (yyvsp[(2) - (2)].yyt_params)->begin(); i != (yyvsp[(2) - (2)].yyt_params)->end(); i++) {
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
				MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 416:
#line 1506 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 417:
#line 1506 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_refer_to.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			MSG->hdr_refer_to.set_params(*(yyvsp[(3) - (3)].yyt_params));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 418:
#line 1514 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 419:
#line 1514 "parser.yxx"
    {
			MSG->hdr_referred_by.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_referred_by.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(3) - (3)].yyt_params)->begin(); i != (yyvsp[(3) - (3)].yyt_params)->end(); i++) {
				if (i->name == "cid") {
					MSG->hdr_referred_by.set_cid(i->value);
				} else {
					MSG->hdr_referred_by.add_param(*i);
				}
			}
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 420:
#line 1529 "parser.yxx"
    {
			string value(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			if (value != "true" && value != "false") {
				YYERROR;
			}
			MSG->hdr_refer_sub.set_create_refer_sub(value == "true");
			MSG->hdr_refer_sub.set_extensions(*(yyvsp[(2) - (2)].yyt_params));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 421:
#line 1540 "parser.yxx"
    {
			MSG->hdr_sip_etag.set_etag(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 422:
#line 1545 "parser.yxx"
    {
			MSG->hdr_sip_if_match.set_etag(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;


/* Line 1267 of yacc.c.  */
#line 4834 "parser.cxx"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
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
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1550 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

