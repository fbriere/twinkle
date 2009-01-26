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
     T_HDR_SERVICE_ROUTE = 313,
     T_HDR_REFER_SUB = 314,
     T_HDR_REFER_TO = 315,
     T_HDR_REFERRED_BY = 316,
     T_HDR_REPLACES = 317,
     T_HDR_REPLY_TO = 318,
     T_HDR_REQUIRE = 319,
     T_HDR_RETRY_AFTER = 320,
     T_HDR_ROUTE = 321,
     T_HDR_RSEQ = 322,
     T_HDR_SERVER = 323,
     T_HDR_SIP_ETAG = 324,
     T_HDR_SIP_IF_MATCH = 325,
     T_HDR_SUBJECT = 326,
     T_HDR_SUBSCRIPTION_STATE = 327,
     T_HDR_SUPPORTED = 328,
     T_HDR_TIMESTAMP = 329,
     T_HDR_TO = 330,
     T_HDR_UNSUPPORTED = 331,
     T_HDR_USER_AGENT = 332,
     T_HDR_VIA = 333,
     T_HDR_WARNING = 334,
     T_HDR_WWW_AUTHENTICATE = 335,
     T_HDR_UNKNOWN = 336,
     T_CRLF = 337,
     T_ERROR = 338,
     T_NULL = 339
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
#define T_HDR_SERVICE_ROUTE 313
#define T_HDR_REFER_SUB 314
#define T_HDR_REFER_TO 315
#define T_HDR_REFERRED_BY 316
#define T_HDR_REPLACES 317
#define T_HDR_REPLY_TO 318
#define T_HDR_REQUIRE 319
#define T_HDR_RETRY_AFTER 320
#define T_HDR_ROUTE 321
#define T_HDR_RSEQ 322
#define T_HDR_SERVER 323
#define T_HDR_SIP_ETAG 324
#define T_HDR_SIP_IF_MATCH 325
#define T_HDR_SUBJECT 326
#define T_HDR_SUBSCRIPTION_STATE 327
#define T_HDR_SUPPORTED 328
#define T_HDR_TIMESTAMP 329
#define T_HDR_TO 330
#define T_HDR_UNSUPPORTED 331
#define T_HDR_USER_AGENT 332
#define T_HDR_VIA 333
#define T_HDR_WARNING 334
#define T_HDR_WWW_AUTHENTICATE 335
#define T_HDR_UNKNOWN 336
#define T_CRLF 337
#define T_ERROR 338
#define T_NULL 339




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
#line 308 "parser.cxx"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 321 "parser.cxx"

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
#define YYLAST   730

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  252
/* YYNRULES -- Number of rules.  */
#define YYNRULES  427
/* YYNRULES -- Number of states.  */
#define YYNSTATES  781

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      93,    94,     2,     2,    87,     2,    95,    85,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    86,    88,
      90,    89,    91,     2,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    96,     2,    97,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
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
     252,   256,   260,   264,   268,   272,   276,   280,   284,   288,
     293,   297,   301,   305,   309,   313,   317,   321,   325,   329,
     333,   337,   341,   345,   349,   353,   357,   361,   365,   369,
     373,   377,   381,   385,   389,   393,   397,   401,   405,   409,
     413,   417,   421,   425,   429,   433,   437,   441,   445,   449,
     453,   457,   461,   465,   469,   473,   477,   481,   485,   489,
     493,   497,   501,   505,   509,   513,   517,   521,   525,   529,
     532,   535,   538,   541,   544,   547,   550,   553,   556,   559,
     562,   565,   568,   571,   574,   577,   580,   583,   586,   589,
     592,   595,   598,   601,   604,   607,   610,   613,   616,   619,
     622,   625,   628,   631,   634,   637,   640,   643,   646,   649,
     652,   655,   658,   661,   664,   667,   670,   673,   676,   679,
     682,   685,   688,   691,   694,   697,   700,   703,   706,   707,
     710,   715,   719,   720,   724,   726,   727,   728,   734,   736,
     738,   740,   744,   746,   749,   752,   753,   756,   757,   762,
     764,   765,   769,   771,   775,   776,   777,   784,   786,   790,
     791,   792,   796,   798,   802,   804,   808,   809,   810,   817,
     818,   819,   823,   825,   827,   831,   834,   835,   836,   840,
     841,   842,   843,   851,   852,   854,   856,   859,   861,   865,
     866,   869,   870,   875,   876,   877,   881,   884,   885,   886,
     891,   892,   893,   907,   909,   913,   914,   915,   922,   923,
     924,   928,   929,   933,   934,   937,   938,   939,   946,   947,
     948,   952,   953,   954,   960,   961,   962,   966,   967,   968,
     972,   974,   975,   976,   980,   981,   984,   988,   989,   992,
     996,   998,  1000,  1004,  1006,  1010,  1012,  1016,  1017,  1018,
    1026,  1028,  1032,  1033,  1034,  1039,  1040,  1044,  1046,  1050,
    1051,  1052,  1058,  1059,  1060,  1061,  1067,  1069,  1073,  1075,
    1078,  1080,  1083,  1088,  1089,  1090,  1094,  1095,  1097,  1101,
    1102,  1105,  1107,  1110,  1112,  1116,  1118,  1122,  1123,  1127,
    1129,  1133,  1135,  1138,  1140,  1144,  1148,  1154,  1156,  1157,
    1158,  1164,  1166,  1167,  1168,  1174,  1175,  1176,  1182,  1184,
    1188,  1189,  1190,  1196,  1197,  1198,  1202,  1204,  1206,  1210,
    1212,  1216,  1218,  1222,  1223,  1227,  1228,  1232,  1233,  1236,
    1238,  1242,  1243,  1247,  1248,  1252,  1253,  1256,  1257,  1260,
    1261,  1264,  1265,  1266,  1270,  1271,  1272,  1278,  1281,  1283,
    1287,  1290,  1291,  1295,  1296,  1300,  1303,  1305
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      99,     0,    -1,    -1,   100,   101,    -1,   102,    -1,   108,
      -1,     1,    84,    -1,   103,   113,    82,    -1,    -1,    -1,
      17,   104,     8,   105,   106,    82,    -1,    -1,    16,   107,
      85,     4,    -1,   109,   113,    82,    -1,    -1,    -1,    -1,
     106,   110,     3,   111,     7,   112,    82,    -1,    -1,   113,
     114,    -1,   115,   174,    82,    -1,   116,   181,    82,    -1,
     117,   184,    82,    -1,   118,   189,    82,    -1,   119,   193,
      82,    -1,   120,   341,    82,    -1,   121,   316,    82,    -1,
     122,   322,    82,    -1,   123,   194,    82,    -1,   124,   198,
      82,    -1,   125,   202,    82,    -1,   126,   214,    82,    -1,
     127,   215,    82,    -1,   128,   216,    82,    -1,   129,   219,
      82,    -1,   130,   222,    82,    -1,   131,   223,    82,    -1,
     132,   226,    82,    -1,   134,   340,    82,    -1,   133,   229,
      82,    -1,   135,   233,    82,    -1,   136,   236,    82,    -1,
     137,   242,    82,    -1,   138,   247,    82,    -1,   139,   250,
      82,    -1,   140,   253,    82,    -1,   141,   254,    82,    -1,
     142,   257,    82,    -1,   143,   259,    82,    -1,   144,   261,
      82,    -1,   145,   262,    82,    -1,   146,   328,    82,    -1,
     147,   330,    82,    -1,   148,   263,    82,    -1,   149,   337,
      82,    -1,   150,   264,    82,    -1,   151,   268,    82,    -1,
     152,   347,    82,    -1,   153,   343,    82,    -1,   154,   345,
      82,    -1,   155,   269,    82,    -1,   156,   272,    82,    -1,
     157,   274,    82,    -1,   158,   275,    82,    -1,   159,   281,
      82,    -1,   160,   334,    82,    -1,   161,   282,    82,    -1,
     162,   348,    82,    -1,   163,   349,    82,    -1,   164,   284,
      82,    -1,   165,   342,    82,    -1,   166,   287,    82,    -1,
     167,   288,    82,    -1,   168,   293,    82,    -1,   169,   295,
      82,    -1,   170,   296,    82,    -1,   171,   297,    82,    -1,
     172,   308,    82,    -1,   173,   332,    82,    -1,    81,    86,
     312,    82,    -1,   115,     1,    82,    -1,   116,     1,    82,
      -1,   117,     1,    82,    -1,   118,     1,    82,    -1,   119,
       1,    82,    -1,   120,     1,    82,    -1,   121,     1,    82,
      -1,   122,     1,    82,    -1,   123,     1,    82,    -1,   124,
       1,    82,    -1,   125,     1,    82,    -1,   126,     1,    82,
      -1,   127,     1,    82,    -1,   128,     1,    82,    -1,   129,
       1,    82,    -1,   130,     1,    82,    -1,   131,     1,    82,
      -1,   132,     1,    82,    -1,   133,     1,    82,    -1,   134,
       1,    82,    -1,   135,     1,    82,    -1,   136,     1,    82,
      -1,   137,     1,    82,    -1,   138,     1,    82,    -1,   139,
       1,    82,    -1,   140,     1,    82,    -1,   141,     1,    82,
      -1,   142,     1,    82,    -1,   143,     1,    82,    -1,   144,
       1,    82,    -1,   145,     1,    82,    -1,   146,     1,    82,
      -1,   147,     1,    82,    -1,   148,     1,    82,    -1,   149,
       1,    82,    -1,   150,     1,    82,    -1,   151,     1,    82,
      -1,   152,     1,    82,    -1,   153,     1,    82,    -1,   154,
       1,    82,    -1,   155,     1,    82,    -1,   156,     1,    82,
      -1,   157,     1,    82,    -1,   158,     1,    82,    -1,   159,
       1,    82,    -1,   160,     1,    82,    -1,   161,     1,    82,
      -1,   162,     1,    82,    -1,   163,     1,    82,    -1,   164,
       1,    82,    -1,   165,     1,    82,    -1,   166,     1,    82,
      -1,   167,     1,    82,    -1,   168,     1,    82,    -1,   169,
       1,    82,    -1,   170,     1,    82,    -1,   171,     1,    82,
      -1,   172,     1,    82,    -1,   173,     1,    82,    -1,    22,
      86,    -1,    23,    86,    -1,    24,    86,    -1,    25,    86,
      -1,    26,    86,    -1,    27,    86,    -1,    28,    86,    -1,
      29,    86,    -1,    30,    86,    -1,    31,    86,    -1,    32,
      86,    -1,    33,    86,    -1,    34,    86,    -1,    35,    86,
      -1,    36,    86,    -1,    37,    86,    -1,    38,    86,    -1,
      39,    86,    -1,    40,    86,    -1,    41,    86,    -1,    42,
      86,    -1,    43,    86,    -1,    44,    86,    -1,    45,    86,
      -1,    46,    86,    -1,    47,    86,    -1,    48,    86,    -1,
      49,    86,    -1,    50,    86,    -1,    51,    86,    -1,    52,
      86,    -1,    53,    86,    -1,    54,    86,    -1,    55,    86,
      -1,    56,    86,    -1,    57,    86,    -1,    58,    86,    -1,
      59,    86,    -1,    60,    86,    -1,    61,    86,    -1,    62,
      86,    -1,    63,    86,    -1,    64,    86,    -1,    65,    86,
      -1,    66,    86,    -1,    67,    86,    -1,    68,    86,    -1,
      69,    86,    -1,    70,    86,    -1,    71,    86,    -1,    72,
      86,    -1,    73,    86,    -1,    74,    86,    -1,    75,    86,
      -1,    76,    86,    -1,    77,    86,    -1,    78,    86,    -1,
      79,    86,    -1,    80,    86,    -1,    -1,   175,   176,    -1,
     174,    87,   175,   176,    -1,     4,    85,     4,    -1,    -1,
     176,    88,   177,    -1,     4,    -1,    -1,    -1,     4,    89,
     178,   180,   179,    -1,    21,    -1,     5,    -1,   182,    -1,
     181,    87,   182,    -1,     4,    -1,     4,   183,    -1,    88,
     177,    -1,    -1,   185,   187,    -1,    -1,   184,    87,   186,
     187,    -1,    11,    -1,    -1,    11,   188,   183,    -1,   190,
      -1,   189,    87,   190,    -1,    -1,    -1,    90,   191,     8,
     192,    91,   176,    -1,     4,    -1,   193,    87,     4,    -1,
      -1,    -1,   195,   197,   196,    -1,    12,    -1,    12,    92,
      12,    -1,   199,    -1,   198,    87,   199,    -1,    -1,    -1,
      90,   200,     8,   201,    91,   176,    -1,    -1,    -1,   203,
       9,   204,    -1,   205,    -1,   206,    -1,   205,    87,   206,
      -1,   207,   176,    -1,    -1,    -1,   208,     8,   209,    -1,
      -1,    -1,    -1,   210,   213,    90,   211,     8,   212,    91,
      -1,    -1,    10,    -1,     5,    -1,     4,   176,    -1,   182,
      -1,   215,    87,   182,    -1,    -1,   217,   187,    -1,    -1,
     216,    87,   218,   187,    -1,    -1,    -1,   220,     3,   221,
      -1,   175,   176,    -1,    -1,    -1,   224,     3,   225,     4,
      -1,    -1,    -1,   227,    13,    87,     3,    14,     3,     3,
      86,     3,    86,     3,    15,   228,    -1,   230,    -1,   229,
      87,   230,    -1,    -1,    -1,    90,   231,     8,   232,    91,
     176,    -1,    -1,    -1,   234,     3,   235,    -1,    -1,   237,
     238,   176,    -1,    -1,     8,   239,    -1,    -1,    -1,   213,
      90,   240,     8,   241,    91,    -1,    -1,    -1,   243,   197,
     244,    -1,    -1,    -1,   242,    87,   245,   197,   246,    -1,
      -1,    -1,   248,     3,   249,    -1,    -1,    -1,   251,     3,
     252,    -1,     4,    -1,    -1,    -1,   255,     7,   256,    -1,
      -1,   258,   238,    -1,   257,    87,   238,    -1,    -1,   260,
     238,    -1,   259,    87,   238,    -1,     4,    -1,     4,    -1,
     262,    88,     4,    -1,     4,    -1,   263,    87,     4,    -1,
     265,    -1,   264,    87,   265,    -1,    -1,    -1,   266,   213,
      90,     8,   267,    91,   176,    -1,   265,    -1,   268,    87,
     265,    -1,    -1,    -1,   270,   197,   271,   176,    -1,    -1,
     273,   238,   176,    -1,     4,    -1,   263,    87,     4,    -1,
      -1,    -1,   276,     3,   277,   278,   176,    -1,    -1,    -1,
      -1,    93,   279,     6,   280,    94,    -1,   265,    -1,   281,
      87,   265,    -1,   283,    -1,   282,   283,    -1,   278,    -1,
       4,   278,    -1,     4,    85,     4,   278,    -1,    -1,    -1,
     285,     7,   286,    -1,    -1,     4,    -1,   287,    87,     4,
      -1,    -1,   289,   290,    -1,   291,    -1,   291,   292,    -1,
       3,    -1,     3,    95,     3,    -1,     3,    -1,     3,    95,
       3,    -1,    -1,   294,   238,   176,    -1,     4,    -1,   295,
      87,     4,    -1,   283,    -1,   296,   283,    -1,   298,    -1,
     297,    87,   298,    -1,   299,   300,   176,    -1,     4,    85,
       4,    85,     4,    -1,     4,    -1,    -1,    -1,     4,    86,
     301,     3,   302,    -1,   305,    -1,    -1,    -1,   305,    86,
     303,     3,   304,    -1,    -1,    -1,    96,   306,    20,   307,
      97,    -1,   309,    -1,   308,    87,   309,    -1,    -1,    -1,
     310,     3,   311,   300,     5,    -1,    -1,    -1,   313,     7,
     314,    -1,   177,    -1,   315,    -1,   316,    87,   315,    -1,
     177,    -1,   317,    87,   177,    -1,   177,    -1,   318,    87,
     177,    -1,    -1,    18,   320,   317,    -1,    -1,    19,   321,
     318,    -1,    -1,   323,   319,    -1,   177,    -1,   324,    87,
     177,    -1,    -1,    18,   326,   324,    -1,    -1,    19,   327,
     318,    -1,    -1,   329,   325,    -1,    -1,   331,   319,    -1,
      -1,   333,   325,    -1,    -1,    -1,   335,     3,   336,    -1,
      -1,    -1,   338,     3,     3,   339,     4,    -1,     4,   176,
      -1,     4,    -1,   341,    87,     4,    -1,     4,   176,    -1,
      -1,   344,   238,   176,    -1,    -1,   346,   238,   176,    -1,
       4,   176,    -1,     4,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   243,   243,   243,   246,   247,   248,   268,   277,   277,
     277,   295,   295,   299,   306,   306,   307,   306,   317,   318,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     384,   386,   388,   390,   392,   394,   396,   398,   400,   402,
     404,   406,   408,   410,   412,   414,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   466,   468,   470,   472,   474,   476,   478,   480,   482,
     484,   486,   488,   490,   492,   494,   496,   498,   500,   513,
     515,   517,   519,   521,   523,   525,   527,   529,   531,   533,
     535,   537,   539,   541,   543,   545,   547,   549,   551,   553,
     555,   557,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607,   609,   611,   613,
     615,   617,   619,   621,   623,   625,   627,   629,   632,   633,
     638,   645,   651,   652,   658,   662,   662,   662,   669,   671,
     675,   678,   683,   687,   694,   701,   701,   704,   704,   709,
     714,   714,   721,   724,   729,   729,   729,   744,   747,   752,
     752,   752,   757,   758,   765,   768,   773,   773,   773,   788,
     788,   788,   790,   795,   800,   806,   822,   822,   822,   833,
     833,   833,   833,   848,   849,   853,   856,   872,   875,   880,
     880,   883,   883,   888,   888,   888,   892,   899,   899,   899,
     905,   908,   905,   919,   922,   927,   927,   927,   942,   942,
     942,   946,   946,   961,   961,   972,   972,   972,   987,   987,
     987,   990,   990,   990,   995,   995,   995,   999,   999,   999,
    1003,  1008,  1008,  1008,  1013,  1013,  1016,  1021,  1021,  1024,
    1029,  1034,  1037,  1042,  1045,  1050,  1053,  1058,  1058,  1058,
    1076,  1079,  1084,  1084,  1084,  1106,  1106,  1114,  1117,  1122,
    1122,  1122,  1138,  1139,  1139,  1139,  1143,  1146,  1151,  1154,
    1159,  1164,  1171,  1182,  1182,  1182,  1187,  1189,  1192,  1197,
    1197,  1200,  1202,  1207,  1208,  1213,  1214,  1219,  1219,  1234,
    1237,  1242,  1245,  1250,  1253,  1258,  1286,  1297,  1302,  1302,
    1302,  1310,  1315,  1315,  1315,  1323,  1323,  1323,  1330,  1333,
    1338,  1338,  1338,  1349,  1349,  1349,  1352,  1372,  1373,  1376,
    1384,  1392,  1397,  1403,  1403,  1409,  1409,  1418,  1418,  1423,
    1431,  1439,  1439,  1445,  1445,  1454,  1454,  1459,  1459,  1465,
    1465,  1470,  1470,  1470,  1474,  1474,  1474,  1481,  1495,  1498,
    1503,  1529,  1529,  1537,  1537,  1552,  1563,  1568
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
  "T_HDR_SERVICE_ROUTE", "T_HDR_REFER_SUB", "T_HDR_REFER_TO",
  "T_HDR_REFERRED_BY", "T_HDR_REPLACES", "T_HDR_REPLY_TO", "T_HDR_REQUIRE",
  "T_HDR_RETRY_AFTER", "T_HDR_ROUTE", "T_HDR_RSEQ", "T_HDR_SERVER",
  "T_HDR_SIP_ETAG", "T_HDR_SIP_IF_MATCH", "T_HDR_SUBJECT",
  "T_HDR_SUBSCRIPTION_STATE", "T_HDR_SUPPORTED", "T_HDR_TIMESTAMP",
  "T_HDR_TO", "T_HDR_UNSUPPORTED", "T_HDR_USER_AGENT", "T_HDR_VIA",
  "T_HDR_WARNING", "T_HDR_WWW_AUTHENTICATE", "T_HDR_UNKNOWN", "T_CRLF",
  "T_ERROR", "T_NULL", "'/'", "':'", "','", "';'", "'='", "'<'", "'>'",
  "'@'", "'('", "')'", "'.'", "'['", "']'", "$accept", "sip_message", "@1",
  "sip_message2", "request", "request_line", "@2", "@3", "sip_version",
  "@4", "response", "status_line", "@5", "@6", "@7", "headers", "header",
  "hd_accept", "hd_accept_encoding", "hd_accept_language", "hd_alert_info",
  "hd_allow", "hd_allow_events", "hd_authentication_info",
  "hd_authorization", "hd_call_id", "hd_call_info", "hd_contact",
  "hd_content_disp", "hd_content_encoding", "hd_content_language",
  "hd_content_length", "hd_content_type", "hd_cseq", "hd_date",
  "hd_error_info", "hd_event", "hd_expires", "hd_from", "hd_in_reply_to",
  "hd_max_forwards", "hd_min_expires", "hd_mime_version",
  "hd_organization", "hd_p_asserted_identity", "hd_p_preferred_identity",
  "hd_priority", "hd_privacy", "hd_proxy_authenticate",
  "hd_proxy_authorization", "hd_proxy_require", "hd_rack",
  "hd_record_route", "hd_service_route", "hd_refer_sub", "hd_refer_to",
  "hd_referred_by", "hd_replaces", "hd_reply_to", "hd_require",
  "hd_retry_after", "hd_route", "hd_rseq", "hd_server", "hd_sip_etag",
  "hd_sip_if_match", "hd_subject", "hd_subscription_state", "hd_supported",
  "hd_timestamp", "hd_to", "hd_unsupported", "hd_user_agent", "hd_via",
  "hd_warning", "hd_www_authenticate", "hdr_accept", "media_range",
  "parameters", "parameter", "@8", "@9", "parameter_val",
  "hdr_accept_encoding", "content_coding", "q_factor",
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
  "rec_route", "@54", "@55", "hdr_service_route", "hdr_replaces", "@56",
  "@57", "hdr_reply_to", "@58", "hdr_require", "hdr_retry_after", "@59",
  "@60", "comment", "@61", "@62", "hdr_route", "hdr_server", "server",
  "hdr_subject", "@63", "@64", "hdr_supported", "hdr_timestamp", "@65",
  "hdr_timestamp1", "timestamp", "delay", "hdr_to", "@66",
  "hdr_unsupported", "hdr_user_agent", "hdr_via", "via_parm",
  "sent_protocol", "host", "@67", "@68", "@69", "@70", "ipv6reference",
  "@71", "@72", "hdr_warning", "warning", "@73", "@74", "hdr_unknown",
  "@75", "@76", "ainfo", "hdr_authentication_info", "digest_response",
  "auth_params", "credentials", "@77", "@78", "hdr_authorization", "@79",
  "digest_challenge", "challenge", "@80", "@81", "hdr_proxy_authenticate",
  "@82", "hdr_proxy_authorization", "@83", "hdr_www_authenticate", "@84",
  "hdr_rseq", "@85", "@86", "hdr_rack", "@87", "@88", "hdr_event",
  "hdr_allow_events", "hdr_subscription_state", "hdr_refer_to", "@89",
  "hdr_referred_by", "@90", "hdr_refer_sub", "hdr_sip_etag",
  "hdr_sip_if_match", 0
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
     335,   336,   337,   338,   339,    47,    58,    44,    59,    61,
      60,    62,    64,    40,    41,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,    98,   100,    99,   101,   101,   101,   102,   104,   105,
     103,   107,   106,   108,   110,   111,   112,   109,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   174,
     174,   175,   176,   176,   177,   178,   179,   177,   180,   180,
     181,   181,   182,   182,   183,   185,   184,   186,   184,   187,
     188,   187,   189,   189,   191,   192,   190,   193,   193,   195,
     196,   194,   197,   197,   198,   198,   200,   201,   199,   203,
     204,   202,   202,   205,   205,   206,   208,   209,   207,   210,
     211,   212,   207,   213,   213,   213,   214,   215,   215,   217,
     216,   218,   216,   220,   221,   219,   222,   224,   225,   223,
     227,   228,   226,   229,   229,   231,   232,   230,   234,   235,
     233,   237,   236,   239,   238,   240,   241,   238,   243,   244,
     242,   245,   246,   242,   248,   249,   247,   251,   252,   250,
     253,   255,   256,   254,   258,   257,   257,   260,   259,   259,
     261,   262,   262,   263,   263,   264,   264,   266,   267,   265,
     268,   268,   270,   271,   269,   273,   272,   274,   274,   276,
     277,   275,   278,   279,   280,   278,   281,   281,   282,   282,
     283,   283,   283,   285,   286,   284,   287,   287,   287,   289,
     288,   290,   290,   291,   291,   292,   292,   294,   293,   295,
     295,   296,   296,   297,   297,   298,   299,   300,   301,   302,
     300,   300,   303,   304,   300,   306,   307,   305,   308,   308,
     310,   311,   309,   313,   314,   312,   315,   316,   316,   317,
     317,   318,   318,   320,   319,   321,   319,   323,   322,   324,
     324,   326,   325,   327,   325,   329,   328,   331,   330,   333,
     332,   335,   336,   334,   338,   339,   337,   340,   341,   341,
     342,   344,   343,   346,   345,   347,   348,   349
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
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       4,     3,     0,     3,     1,     0,     0,     5,     1,     1,
       1,     3,     1,     2,     2,     0,     2,     0,     4,     1,
       0,     3,     1,     3,     0,     0,     6,     1,     3,     0,
       0,     3,     1,     3,     1,     3,     0,     0,     6,     0,
       0,     3,     1,     1,     3,     2,     0,     0,     3,     0,
       0,     0,     7,     0,     1,     1,     2,     1,     3,     0,
       2,     0,     4,     0,     0,     3,     2,     0,     0,     4,
       0,     0,    13,     1,     3,     0,     0,     6,     0,     0,
       3,     0,     3,     0,     2,     0,     0,     6,     0,     0,
       3,     0,     0,     5,     0,     0,     3,     0,     0,     3,
       1,     0,     0,     3,     0,     2,     3,     0,     2,     3,
       1,     1,     3,     1,     3,     1,     3,     0,     0,     7,
       1,     3,     0,     0,     4,     0,     3,     1,     3,     0,
       0,     5,     0,     0,     0,     5,     1,     3,     1,     2,
       1,     2,     4,     0,     0,     3,     0,     1,     3,     0,
       2,     1,     2,     1,     3,     1,     3,     0,     3,     1,
       3,     1,     2,     1,     3,     3,     5,     1,     0,     0,
       5,     1,     0,     0,     5,     0,     0,     5,     1,     3,
       0,     0,     5,     0,     0,     3,     1,     1,     3,     1,
       3,     1,     3,     0,     3,     0,     3,     0,     2,     1,
       3,     0,     3,     0,     3,     0,     2,     0,     2,     0,
       2,     0,     0,     3,     0,     0,     5,     2,     1,     3,
       2,     0,     3,     0,     3,     2,     1,     1
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
       0,     7,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    13,    12,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   383,     0,     0,     0,   202,
       0,   212,     0,   210,     0,     0,     0,     0,   224,     0,
     222,     0,   227,     0,     0,   418,     0,     0,   204,   386,
     387,     0,     0,     0,     0,     0,     0,     0,     0,   236,
       0,   234,     0,     0,     0,   242,   243,   202,     0,   253,
       0,   202,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,   273,     0,   202,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
       0,   253,     0,     0,   253,     0,   310,     0,     0,   311,
       0,     0,     0,     0,     0,     0,     0,     0,   313,     0,
       0,     0,     0,     0,     0,   315,   253,     0,   320,     0,
       0,   202,     0,     0,     0,   253,     0,     0,   253,     0,
       0,     0,     0,     0,   253,     0,   313,     0,     0,     0,
       0,     0,     0,   336,     0,     0,     0,     0,     0,   332,
     333,   340,     0,   338,     0,   426,     0,     0,   427,     0,
       0,     0,     0,     0,   202,     0,     0,   347,     0,     0,
       0,     0,     0,     0,   253,     0,   359,     0,     0,   361,
       0,     0,     0,     0,   363,     0,     0,     0,   378,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,    20,
       0,   199,    81,     0,   213,    21,     0,    82,    22,   217,
     219,   216,    83,     0,    23,     0,    84,    24,     0,    85,
      25,     0,    86,   205,    26,     0,    87,    27,   393,   395,
     398,    88,    28,   232,   230,    89,     0,    29,     0,    90,
      30,   240,   249,   245,   247,   255,   254,     0,    91,   256,
      31,    92,    32,     0,    93,    33,   261,   260,    94,    34,
     264,    95,   266,    35,    96,    36,   268,    97,    37,     0,
      98,     0,    39,     0,    99,   417,    38,   100,    40,   279,
     101,    41,   283,     0,   202,   102,    42,   291,   289,   103,
      43,   295,   104,    44,   298,   105,    45,   106,    46,   302,
     107,    47,   253,   305,   108,    48,   253,   308,   109,    49,
     110,    50,     0,   111,    51,   401,   403,   406,   112,    52,
     408,   113,    53,     0,   114,    54,     0,   115,    55,   317,
       0,   116,    56,   317,   117,   425,    57,   118,    58,   202,
     119,    59,   202,   120,    60,   323,   121,    61,   202,   122,
       0,    62,   123,    63,   330,   124,    64,   317,   125,    65,
     412,   126,     0,   341,     0,    66,   339,   127,    67,   128,
      68,   129,    69,   344,   130,   420,    70,   131,    71,     0,
     132,    72,   353,   350,   351,   133,    73,   202,   134,    74,
       0,   135,    75,   362,   136,     0,    76,     0,   367,   375,
     202,   371,   137,    77,   380,   381,   138,    78,   410,    16,
      10,    79,   384,   201,   202,     0,   214,   211,     0,     0,
     225,   223,   228,   419,     0,   388,     0,     0,     0,   231,
     237,   235,   241,   244,   248,   250,   258,     0,   265,     0,
       0,   276,   274,   280,   284,   285,   282,     0,   290,   296,
     299,   303,   306,   309,   312,     0,     0,   314,   415,   316,
       0,   321,   422,   424,   202,   326,   314,   332,   337,   413,
     332,   334,   345,   348,     0,   355,   352,   358,   360,     0,
     364,   368,     0,   365,   372,   379,     0,     0,   385,   200,
     203,   218,   221,     0,   209,   208,   206,   389,   394,   391,
     396,   233,     0,     0,   262,   269,     0,     0,     0,   292,
     399,   402,   404,     0,   318,   324,   202,   342,     0,   354,
       0,     0,     0,   376,     0,     0,    17,   202,   207,     0,
       0,   202,   251,     0,   202,   286,   293,     0,   416,     0,
     331,   335,   356,   366,   369,     0,   373,   382,   226,   390,
     392,   238,     0,     0,   277,     0,   400,   202,   370,   377,
     374,   252,     0,   287,   319,     0,     0,     0,     0,   271,
     272
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    15,   145,    10,    14,
      11,    12,    17,   403,   697,    16,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   208,   209,   411,   229,
     634,   738,   706,   212,   213,   414,   215,   216,   628,   421,
     629,   219,   220,   423,   703,   223,   236,   237,   639,   444,
     240,   241,   446,   712,   243,   244,   642,   245,   246,   247,
     248,   644,   249,   713,   762,   493,   252,   255,   257,   258,
     647,   260,   261,   648,   264,   266,   267,   649,   269,   270,
     780,   273,   274,   481,   717,   279,   280,   653,   282,   283,
     494,   654,   718,   765,   285,   286,   658,   657,   746,   288,
     289,   659,   291,   292,   660,   295,   297,   298,   661,   300,
     301,   303,   304,   307,   310,   319,   324,   325,   326,   749,
     329,   340,   341,   674,   343,   344,   348,   350,   351,   677,
     361,   574,   728,   354,   362,   363,   371,   372,   682,   378,
     380,   381,   593,   594,   686,   383,   384,   387,   390,   393,
     394,   395,   610,   732,   768,   734,   770,   611,   692,   755,
     397,   398,   399,   696,   405,   406,   698,   230,   231,   708,
     710,   440,   636,   637,   233,   234,   721,   527,   665,   666,
     312,   313,   315,   316,   401,   402,   356,   357,   679,   321,
     322,   723,   277,   226,   375,   334,   335,   337,   338,   332,
     366,   369
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -408
static const yytype_int16 yypact[] =
{
    -408,   145,    75,  -408,   -27,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,    95,   190,   499,    93,   560,   219,
    -408,   141,   159,   170,   171,   189,   192,   193,   194,   195,
     196,   197,   198,   200,   201,   202,   206,   207,   208,   212,
     213,   214,   217,   218,   221,   222,   223,   226,   227,   228,
     229,   231,   233,   235,   237,   241,   243,   244,   245,   249,
     250,   253,   256,   257,   258,   259,   262,   263,   266,   267,
     270,   271,   272,   273,   274,   275,   276,   278,   279,   280,
     281,  -408,  -408,    61,   191,   117,    20,   199,   203,   204,
      62,   113,    34,    17,   205,   209,   119,   247,   210,   248,
     110,    41,   211,   251,    23,   121,   252,   260,   215,   131,
      29,    39,   216,   220,    70,    84,   224,   261,    31,    67,
     230,    45,    51,   125,    59,   232,   264,    73,   265,    11,
     234,   236,   133,   238,    78,   268,    65,   240,    16,   242,
     269,    98,  -408,  -408,  -408,   285,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,   286,   225,    13,  -408,
     287,   188,    57,  -408,   288,    64,   284,   289,  -408,    71,
    -408,   293,  -408,    72,   294,  -408,    74,   296,   290,  -408,
    -408,    80,   298,   299,    68,   300,   301,   277,   302,  -408,
      82,  -408,   303,   304,   282,   254,  -408,  -408,   308,   161,
     305,  -408,   306,   307,  -408,    86,   310,    88,   284,   311,
     312,   315,   313,  -408,   314,   316,   317,   321,   318,   319,
     283,   320,  -408,    90,  -408,   322,  -408,   323,   324,   325,
     331,   326,   327,   142,   328,    92,   277,   329,   330,   334,
     332,   333,   335,   336,  -408,   337,   338,   340,   339,   341,
      94,   142,   342,    96,   142,   344,  -408,   346,   347,  -408,
      54,   348,   349,   255,   350,   351,    68,   352,  -408,   100,
     353,   354,   387,   355,   102,  -408,   161,   356,  -408,   103,
     357,  -408,   358,   359,   360,   142,   361,   362,   142,   363,
     364,   277,   365,   366,   142,   368,   369,   367,   370,   371,
     373,   394,   374,  -408,   104,   375,   376,   400,   377,   -42,
    -408,  -408,    15,  -408,   378,  -408,   379,   380,  -408,   381,
     382,   383,   406,   384,  -408,   385,   386,  -408,   106,   388,
     389,   413,   390,   391,   142,   392,  -408,   112,   393,  -408,
      19,   395,   396,   114,  -408,     9,   398,   115,  -408,   414,
     401,   402,   255,   462,   403,   404,   469,  -408,   343,  -408,
     474,   399,  -408,   478,  -408,  -408,   484,  -408,  -408,  -408,
     405,  -408,  -408,   481,  -408,   187,  -408,  -408,   487,  -408,
    -408,   488,  -408,  -408,  -408,   478,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,   407,  -408,  -408,   490,  -408,   410,  -408,
    -408,  -408,   493,   399,  -408,  -408,  -408,   412,  -408,   399,
    -408,  -408,  -408,   484,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,   399,  -408,  -408,  -408,  -408,  -408,  -408,   408,
    -408,   495,  -408,   415,  -408,   399,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,   416,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,   142,  -408,  -408,  -408,   142,  -408,  -408,  -408,
    -408,  -408,   492,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,   500,  -408,  -408,   504,  -408,  -408,  -408,
     418,  -408,  -408,  -408,  -408,   399,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
     505,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,   506,  -408,   291,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,   399,  -408,  -408,  -408,   507,
    -408,  -408,   417,  -408,   510,  -408,  -408,  -408,  -408,  -408,
     511,  -408,  -408,  -408,  -408,   512,  -408,   513,   428,  -408,
    -408,   432,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,   478,  -408,  -408,   284,   188,
    -408,  -408,  -408,  -408,    85,  -408,   478,   478,   631,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,   284,  -408,   515,
     641,  -408,  -408,  -408,  -408,  -408,   399,   277,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,   478,   478,  -408,  -408,  -408,
     637,  -408,   399,   399,  -408,   399,   564,   554,  -408,  -408,
     554,  -408,  -408,  -408,   645,   555,  -408,   399,  -408,   566,
    -408,  -408,   629,   399,  -408,  -408,     9,   570,  -408,   399,
    -408,  -408,  -408,   562,  -408,  -408,  -408,  -408,   567,  -408,
     568,  -408,   565,   649,  -408,  -408,   292,   569,   650,  -408,
    -408,   572,   568,   657,  -408,   399,  -408,  -408,   571,  -408,
     659,   660,   663,  -408,   664,   658,  -408,  -408,  -408,   478,
     478,  -408,  -408,   665,  -408,  -408,  -408,   478,  -408,   578,
     399,  -408,  -408,  -408,  -408,   573,  -408,  -408,   399,  -408,
    -408,   399,   580,   669,   399,   582,  -408,  -408,  -408,  -408,
    -408,  -408,   588,  -408,   399,   672,   590,   674,   666,  -408,
    -408
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,   140,  -408,
    -408,  -408,  -408,  -408,  -408,   667,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,   -88,  -247,  -407,
    -408,  -408,  -408,  -408,   -90,  -339,  -408,  -408,  -408,  -256,
    -408,  -408,  -105,  -408,  -408,  -408,  -408,  -408,  -408,  -283,
    -408,   -97,  -408,  -408,  -408,  -408,  -408,  -408,   -98,  -408,
    -408,  -408,  -408,  -408,  -408,  -211,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -128,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -290,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,   553,  -408,  -118,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -352,  -408,  -408,  -408,  -408,  -130,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
      76,  -408,   -16,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,    77,  -408,  -408,  -408,  -408,  -408,   295,  -408,  -408,
      18,   372,  -408,  -408,  -408,  -408,  -408,   297,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,  -408,
    -408,  -408
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -424
static const yytype_int16 yytable[] =
{
     453,   328,   467,   498,   459,   254,   626,   573,   389,   353,
     263,   513,   358,   608,   517,   359,   472,   388,   242,   359,
     359,   217,  -249,   359,   281,  -246,  -239,  -249,  -281,   485,
     299,  -281,   323,  -281,  -304,   238,  -317,  -304,   457,  -304,
     302,  -317,   271,   572,  -307,   549,   333,  -307,   552,  -307,
    -421,   360,   336,  -421,   558,  -421,  -423,    13,   555,  -423,
     342,  -423,   206,   232,  -325,   207,   382,  -325,   327,  -325,
    -357,   311,  -317,  -357,   352,  -357,     4,  -317,  -317,   376,
    -397,  -397,   377,  -317,   545,   314,   438,   439,  -405,  -405,
     704,     5,     6,  -332,   597,   409,   142,   575,  -332,   400,
     410,   602,  -407,  -407,   360,   609,   705,  -249,   360,   360,
     218,   268,   360,  -281,   235,   540,  -409,  -409,   214,  -304,
     256,  -317,   284,  -270,   239,  -229,   339,   585,  -215,  -307,
    -259,   272,   296,  -288,   370,  -421,   521,  -322,  -301,   415,
    -343,  -423,   522,  -198,   416,     3,   418,   455,  -198,  -325,
     492,   419,   456,   424,   427,  -357,   430,  -317,   425,   428,
    -346,   431,   434,  -317,   447,  -346,   455,   435,   462,   448,
     465,   456,   482,   463,   496,   466,   511,   483,   515,   497,
      19,   512,   532,   516,   538,   542,   566,   533,   588,   539,
     543,   567,   210,   589,   599,   211,   606,   613,    20,   600,
     221,   607,   614,   222,   224,   227,   250,   225,   228,   251,
     253,   262,   275,   211,   207,   276,   293,   305,   700,   294,
     306,   308,   662,   144,   309,   317,   663,   146,   318,   707,
     709,   330,   576,   345,   331,   364,   346,   367,   365,   373,
     368,   385,   374,   391,   386,   147,   392,   656,   259,   265,
    -263,  -267,   278,   287,  -278,  -294,   148,   149,   720,   709,
     603,   290,   320,  -297,  -414,   349,   355,  -329,  -411,   379,
     396,  -349,  -380,   525,   526,   150,   413,   218,   151,   152,
     153,   154,   155,   156,   157,   404,   158,   159,   160,   443,
     702,   451,   161,   162,   163,   420,   479,   681,   164,   165,
     166,     5,   672,   167,   168,   673,   743,   169,   170,   171,
     408,   675,   172,   173,   174,   175,   454,   176,   470,   177,
     631,   178,   624,   179,   476,   726,   627,   180,   727,   181,
     182,   183,   759,   760,   489,   184,   185,   501,   504,   186,
     766,   452,   187,   188,   189,   190,   509,   623,   191,   192,
     687,   641,   193,   194,   643,   652,   195,   196,   197,   198,
     199,   200,   201,   693,   202,   203,   204,   205,   407,   412,
     417,   422,   701,   646,   719,   426,   429,   699,   432,   433,
     436,   437,   441,   442,   445,   449,   450,   458,   460,   461,
     536,   714,   464,   468,   469,   471,   473,   564,   474,   475,
     477,   478,   480,   570,   484,   486,   487,   488,   490,   491,
     495,   499,   500,   583,   502,   503,   592,   615,   505,   506,
     507,   669,   508,   510,   514,   671,   518,   725,   519,   520,
     523,   524,   528,   529,   531,   534,   535,   537,   541,   544,
     546,   547,   548,   550,   551,   553,   554,   556,   557,   678,
     559,  -327,   561,   562,   560,   563,   565,   568,   569,   571,
     577,   578,   579,   580,   581,   582,   584,   586,   587,   619,
     590,   591,   595,   596,   598,   601,   622,   604,   207,   750,
     612,   605,   228,   616,   617,   620,   621,   625,   211,   630,
     758,   632,   633,  -220,   761,   650,   664,   764,   640,   638,
     239,  -246,   645,   651,   667,   272,   655,   668,   670,   676,
     680,   683,   684,   685,   691,   688,   689,   392,   694,   715,
     774,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   143,   711,   716,   724,  -328,   360,   729,   733,
     730,   731,   736,   737,   739,   740,   741,   742,   745,   747,
     744,   748,   752,   757,   753,   751,   754,   756,   763,   767,
     769,   771,   772,   773,   775,   776,   777,   778,   347,    18,
     735,   779,     0,   690,   722,     0,     0,     0,   530,     0,
       0,   695,     0,     0,     0,     0,     0,     0,     0,   618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     635
};

static const yytype_int16 yycheck[] =
{
     247,   119,   258,   286,   251,    95,   413,   359,   138,   127,
      98,   301,     1,     4,   304,     4,   263,     1,     1,     4,
       4,     1,     5,     4,     1,     8,     9,    10,     5,   276,
       1,     8,     1,    10,     5,     1,     5,     8,   249,    10,
       1,    10,     1,    85,     5,   335,     1,     8,   338,    10,
       5,    93,     1,     8,   344,    10,     5,    84,   341,     8,
       1,    10,     1,     1,     5,     4,     1,     8,     1,    10,
       5,     1,     5,     8,     1,    10,     1,    10,     5,     1,
      18,    19,     4,    10,   331,     1,    18,    19,    18,    19,
       5,    16,    17,    82,   384,    82,     3,    82,    82,     1,
      87,    82,    18,    19,    93,    96,    21,    90,    93,    93,
      90,     1,    93,    90,     1,   326,    18,    19,     1,    90,
       1,    90,     1,    13,    90,    12,     1,   374,    11,    90,
      11,    90,     1,    12,     1,    90,    82,    12,     7,    82,
       7,    90,    88,    82,    87,     0,    82,     5,    87,    90,
       8,    87,    10,    82,    82,    90,    82,    90,    87,    87,
      82,    87,    82,    90,    82,    87,     5,    87,    82,    87,
      82,    10,    82,    87,    82,    87,    82,    87,    82,    87,
      85,    87,    82,    87,    82,    82,    82,    87,    82,    87,
      87,    87,     1,    87,    82,     4,    82,    82,     8,    87,
       1,    87,    87,     4,     1,     1,     1,     4,     4,     4,
       1,     1,     1,     4,     4,     4,     1,     1,   625,     4,
       4,     1,   512,     4,     4,     1,   516,    86,     4,   636,
     637,     1,   362,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     4,    86,     4,   494,     1,     1,
       3,     3,     1,     1,     3,     3,    86,    86,   665,   666,
     390,     1,     1,     3,     3,     1,     1,     3,     3,     1,
       1,     3,     3,    18,    19,    86,    88,    90,    86,    86,
      86,    86,    86,    86,    86,   145,    86,    86,    86,    12,
     629,     9,    86,    86,    86,    11,    13,     6,    86,    86,
      86,    16,   549,    86,    86,   552,    14,    86,    86,    86,
      85,   558,    86,    86,    86,    86,     8,    86,     3,    86,
     425,    86,   410,    86,     3,   677,   416,    86,   680,    86,
      86,    86,   739,   740,     3,    86,    86,     3,     3,    86,
     747,    87,    86,    86,    86,    86,     7,     4,    86,    86,
     597,   448,    86,    86,   452,   483,    86,    86,    86,    86,
      86,    86,    86,   610,    86,    86,    86,    86,    82,    82,
      82,    82,   628,   463,   657,    82,    82,   624,    82,    89,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
       3,   647,    82,    82,    82,    82,    82,     3,    82,    82,
      82,    82,    82,     3,    82,    82,    82,    82,    82,    82,
      82,    82,    82,     7,    82,    82,     3,     3,    82,    82,
      82,   539,    82,    82,    82,   543,    82,   674,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,   567,
      82,    82,    82,    82,    87,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,     7,
      82,    82,    82,    82,    82,    82,     7,    82,     4,   726,
      82,    85,     4,    82,    82,    82,    82,    88,     4,     8,
     737,     4,     4,    88,   741,    87,     4,   744,     8,    92,
      90,     8,    90,     8,     4,    90,    90,     3,    90,     4,
       4,     4,    95,     3,    86,     4,     4,     4,    86,     4,
     767,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    12,     3,     8,    82,    93,     3,    20,
      95,    85,    82,    91,    87,    87,    91,     8,     8,    87,
      91,     4,     3,     5,     4,    94,     3,     3,     3,    91,
      97,    91,     3,    91,    86,     3,    86,     3,   125,    12,
     696,    15,    -1,   607,   666,    -1,    -1,    -1,   316,    -1,
      -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     435
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    99,   100,     0,     1,    16,    17,   101,   102,   103,
     106,   108,   109,    84,   107,   104,   113,   110,   113,    85,
       8,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     3,    82,     4,   105,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,     1,     4,   174,   175,
       1,     4,   181,   182,     1,   184,   185,     1,    90,   189,
     190,     1,     4,   193,     1,     4,   341,     1,     4,   177,
     315,   316,     1,   322,   323,     1,   194,   195,     1,    90,
     198,   199,     1,   202,   203,   205,   206,   207,   208,   210,
       1,     4,   214,     1,   182,   215,     1,   216,   217,     1,
     219,   220,     1,   175,   222,     1,   223,   224,     1,   226,
     227,     1,    90,   229,   230,     1,     4,   340,     1,   233,
     234,     1,   236,   237,     1,   242,   243,     1,   247,   248,
       1,   250,   251,     1,     4,   253,     1,   254,   255,     1,
     257,   258,     1,   259,   260,     1,     4,   261,     1,     4,
     262,     1,   328,   329,     1,   330,   331,     1,     4,   263,
       1,   337,   338,     1,   264,   265,   266,     1,   265,   268,
       1,     4,   347,     1,   343,   344,     1,   345,   346,     1,
     269,   270,     1,   272,   273,     1,     4,   263,   274,     1,
     275,   276,     1,   265,   281,     1,   334,   335,     1,     4,
      93,   278,   282,   283,     1,     4,   348,     1,     4,   349,
       1,   284,   285,     1,     4,   342,     1,     4,   287,     1,
     288,   289,     1,   293,   294,     1,     4,   295,     1,   283,
     296,     1,     4,   297,   298,   299,     1,   308,   309,   310,
       1,   332,   333,   111,   106,   312,   313,    82,    85,    82,
      87,   176,    82,    88,   183,    82,    87,    82,    82,    87,
      11,   187,    82,   191,    82,    87,    82,    82,    87,    82,
      82,    87,    82,    89,    82,    87,    82,    82,    18,    19,
     319,    82,    82,    12,   197,    82,   200,    82,    87,    82,
      82,     9,    87,   176,     8,     5,    10,   213,    82,   176,
      82,    82,    82,    87,    82,    82,    87,   187,    82,    82,
       3,    82,   176,    82,    82,    82,     3,    82,    82,    13,
      82,   231,    82,    87,    82,   176,    82,    82,    82,     3,
      82,    82,     8,   213,   238,    82,    82,    87,   197,    82,
      82,     3,    82,    82,     3,    82,    82,    82,    82,     7,
      82,    82,    87,   238,    82,    82,    87,   238,    82,    82,
      82,    82,    88,    82,    82,    18,    19,   325,    82,    82,
     319,    82,    82,    87,    82,    82,     3,    82,    82,    87,
     213,    82,    82,    87,    82,   176,    82,    82,    82,   238,
      82,    82,   238,    82,    82,   197,    82,    82,   238,    82,
      87,    82,    82,    82,     3,    82,    82,    87,    82,    82,
       3,    82,    85,   278,   279,    82,   283,    82,    82,    82,
      82,    82,    82,     7,    82,   176,    82,    82,    82,    87,
      82,    82,     3,   290,   291,    82,    82,   238,    82,    82,
      87,    82,    82,   283,    82,    85,    82,    87,     4,    96,
     300,   305,    82,    82,    87,     3,    82,    82,   325,     7,
      82,    82,     7,     4,   175,    88,   177,   182,   186,   188,
       8,   190,     4,     4,   178,   315,   320,   321,    92,   196,
       8,   199,   204,   206,   209,    90,   182,   218,   221,   225,
      87,     8,   230,   235,   239,    90,   176,   245,   244,   249,
     252,   256,   238,   238,     4,   326,   327,     4,     3,   265,
      90,   265,   176,   176,   271,   176,     4,   277,   265,   336,
       4,     6,   286,     4,    95,     3,   292,   176,     4,     4,
     298,    86,   306,   176,    86,   309,   311,   112,   314,   176,
     177,   187,   183,   192,     5,    21,   180,   177,   317,   177,
     318,    12,   201,   211,   187,     4,     3,   232,   240,   197,
     177,   324,   318,   339,     8,   176,   278,   278,   280,     3,
      95,    85,   301,    20,   303,   300,    82,    91,   179,    87,
      87,    91,     8,    14,    91,     8,   246,    87,     4,   267,
     176,    94,     3,     4,     3,   307,     3,     5,   176,   177,
     177,   176,   212,     3,   176,   241,   177,    91,   302,    97,
     304,    91,     3,    91,   176,    86,     3,    86,     3,    15,
     228
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
#line 163 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2013 "parser.cxx"
	break;
      case 5: /* "T_QSTRING" */
#line 164 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2018 "parser.cxx"
	break;
      case 6: /* "T_COMMENT" */
#line 165 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2023 "parser.cxx"
	break;
      case 7: /* "T_LINE" */
#line 166 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2028 "parser.cxx"
	break;
      case 8: /* "T_URI" */
#line 167 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2033 "parser.cxx"
	break;
      case 10: /* "T_DISPLAY" */
#line 168 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2038 "parser.cxx"
	break;
      case 11: /* "T_LANG" */
#line 169 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2043 "parser.cxx"
	break;
      case 12: /* "T_WORD" */
#line 170 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2048 "parser.cxx"
	break;
      case 17: /* "T_METHOD" */
#line 171 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2053 "parser.cxx"
	break;
      case 19: /* "T_AUTH_OTHER" */
#line 172 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2058 "parser.cxx"
	break;
      case 20: /* "T_IPV6ADDR" */
#line 173 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2063 "parser.cxx"
	break;
      case 21: /* "T_PARAMVAL" */
#line 174 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2068 "parser.cxx"
	break;
      case 81: /* "T_HDR_UNKNOWN" */
#line 175 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2073 "parser.cxx"
	break;
      case 106: /* "sip_version" */
#line 238 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2078 "parser.cxx"
	break;
      case 175: /* "media_range" */
#line 231 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_media)); delete (yyvaluep->yyt_media); };
#line 2083 "parser.cxx"
	break;
      case 176: /* "parameters" */
#line 234 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_params)); delete (yyvaluep->yyt_params); };
#line 2088 "parser.cxx"
	break;
      case 177: /* "parameter" */
#line 232 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_param)); delete (yyvaluep->yyt_param); };
#line 2093 "parser.cxx"
	break;
      case 180: /* "parameter_val" */
#line 233 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2098 "parser.cxx"
	break;
      case 182: /* "content_coding" */
#line 219 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_coding)); delete (yyvaluep->yyt_coding); };
#line 2103 "parser.cxx"
	break;
      case 187: /* "language" */
#line 230 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_language)); delete (yyvaluep->yyt_language); };
#line 2108 "parser.cxx"
	break;
      case 190: /* "alert_param" */
#line 211 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_alert_param)); delete (yyvaluep->yyt_alert_param); };
#line 2113 "parser.cxx"
	break;
      case 197: /* "call_id" */
#line 213 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2118 "parser.cxx"
	break;
      case 199: /* "info_param" */
#line 229 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_info_param)); delete (yyvaluep->yyt_info_param); };
#line 2123 "parser.cxx"
	break;
      case 205: /* "contacts" */
#line 218 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contacts)); delete (yyvaluep->yyt_contacts); };
#line 2128 "parser.cxx"
	break;
      case 206: /* "contact_param" */
#line 217 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contact)); delete (yyvaluep->yyt_contact); };
#line 2133 "parser.cxx"
	break;
      case 207: /* "contact_addr" */
#line 216 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_contact)); delete (yyvaluep->yyt_contact); };
#line 2138 "parser.cxx"
	break;
      case 213: /* "display_name" */
#line 223 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2143 "parser.cxx"
	break;
      case 230: /* "error_param" */
#line 224 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_error_param)); delete (yyvaluep->yyt_error_param); };
#line 2148 "parser.cxx"
	break;
      case 238: /* "from_addr" */
#line 225 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_from_addr)); delete (yyvaluep->yyt_from_addr); };
#line 2153 "parser.cxx"
	break;
      case 265: /* "rec_route" */
#line 235 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_route)); delete (yyvaluep->yyt_route); };
#line 2158 "parser.cxx"
	break;
      case 278: /* "comment" */
#line 215 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2163 "parser.cxx"
	break;
      case 283: /* "server" */
#line 237 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_server)); delete (yyvaluep->yyt_server); };
#line 2168 "parser.cxx"
	break;
      case 298: /* "via_parm" */
#line 239 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2173 "parser.cxx"
	break;
      case 299: /* "sent_protocol" */
#line 236 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2178 "parser.cxx"
	break;
      case 300: /* "host" */
#line 227 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_via)); delete (yyvaluep->yyt_via); };
#line 2183 "parser.cxx"
	break;
      case 305: /* "ipv6reference" */
#line 228 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2188 "parser.cxx"
	break;
      case 309: /* "warning" */
#line 240 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_warning)); delete (yyvaluep->yyt_warning); };
#line 2193 "parser.cxx"
	break;
      case 312: /* "hdr_unknown" */
#line 226 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_str)); delete (yyvaluep->yyt_str); };
#line 2198 "parser.cxx"
	break;
      case 317: /* "digest_response" */
#line 222 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_dig_resp)); delete (yyvaluep->yyt_dig_resp); };
#line 2203 "parser.cxx"
	break;
      case 318: /* "auth_params" */
#line 212 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_params)); delete (yyvaluep->yyt_params); };
#line 2208 "parser.cxx"
	break;
      case 319: /* "credentials" */
#line 220 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_credentials)); delete (yyvaluep->yyt_credentials); };
#line 2213 "parser.cxx"
	break;
      case 324: /* "digest_challenge" */
#line 221 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_dig_chlg)); delete (yyvaluep->yyt_dig_chlg); };
#line 2218 "parser.cxx"
	break;
      case 325: /* "challenge" */
#line 214 "parser.yxx"
	{ MEMMAN_DELETE((yyvaluep->yyt_challenge)); delete (yyvaluep->yyt_challenge); };
#line 2223 "parser.cxx"
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
#line 243 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 6:
#line 248 "parser.yxx"
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
#line 268 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 8:
#line 277 "parser.yxx"
    { CTXT_URI; }
    break;

  case 9:
#line 277 "parser.yxx"
    { CTXT_NEW; }
    break;

  case 10:
#line 278 "parser.yxx"
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
#line 295 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 12:
#line 295 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(4) - (4)].yyt_str); }
    break;

  case 13:
#line 299 "parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 14:
#line 306 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 15:
#line 306 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 16:
#line 307 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 17:
#line 307 "parser.yxx"
    {
			MSG = new t_response();
			MEMMAN_NEW(MSG);
		  	MSG->version = *(yyvsp[(1) - (7)].yyt_str);
			((t_response *)MSG)->code = (yyvsp[(3) - (7)].yyt_ulong);
			((t_response *)MSG)->reason = trim(*(yyvsp[(5) - (7)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (7)].yyt_str)); delete (yyvsp[(1) - (7)].yyt_str);
			MEMMAN_DELETE((yyvsp[(5) - (7)].yyt_str)); delete (yyvsp[(5) - (7)].yyt_str); }
    break;

  case 79:
#line 380 "parser.yxx"
    {
			MSG->add_unknown_header(*(yyvsp[(1) - (4)].yyt_str), trim(*(yyvsp[(3) - (4)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (4)].yyt_str)); delete (yyvsp[(1) - (4)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (4)].yyt_str)); delete (yyvsp[(3) - (4)].yyt_str); }
    break;

  case 80:
#line 385 "parser.yxx"
    { PARSE_ERROR("Accept"); }
    break;

  case 81:
#line 387 "parser.yxx"
    { PARSE_ERROR("Accept-Encoding"); }
    break;

  case 82:
#line 389 "parser.yxx"
    { PARSE_ERROR("Accept-Language"); }
    break;

  case 83:
#line 391 "parser.yxx"
    { PARSE_ERROR("Alert-Info"); }
    break;

  case 84:
#line 393 "parser.yxx"
    { PARSE_ERROR("Allow"); }
    break;

  case 85:
#line 395 "parser.yxx"
    { PARSE_ERROR("Allow-Events"); }
    break;

  case 86:
#line 397 "parser.yxx"
    { PARSE_ERROR("Authentication-Info"); }
    break;

  case 87:
#line 399 "parser.yxx"
    { PARSE_ERROR("Authorization"); }
    break;

  case 88:
#line 401 "parser.yxx"
    { PARSE_ERROR("Call-ID"); }
    break;

  case 89:
#line 403 "parser.yxx"
    { PARSE_ERROR("Call-Info"); }
    break;

  case 90:
#line 405 "parser.yxx"
    { PARSE_ERROR("Contact"); }
    break;

  case 91:
#line 407 "parser.yxx"
    { PARSE_ERROR("Content-Disposition"); }
    break;

  case 92:
#line 409 "parser.yxx"
    { PARSE_ERROR("Content-Encoding"); }
    break;

  case 93:
#line 411 "parser.yxx"
    { PARSE_ERROR("Content-Language"); }
    break;

  case 94:
#line 413 "parser.yxx"
    { PARSE_ERROR("Content-Length"); }
    break;

  case 95:
#line 415 "parser.yxx"
    { PARSE_ERROR("Content-Type"); }
    break;

  case 96:
#line 417 "parser.yxx"
    { PARSE_ERROR("CSeq"); }
    break;

  case 97:
#line 419 "parser.yxx"
    { PARSE_ERROR("Date"); }
    break;

  case 98:
#line 421 "parser.yxx"
    { PARSE_ERROR("Error-Info"); }
    break;

  case 99:
#line 423 "parser.yxx"
    { PARSE_ERROR("Event"); }
    break;

  case 100:
#line 425 "parser.yxx"
    { PARSE_ERROR("Expires"); }
    break;

  case 101:
#line 427 "parser.yxx"
    { PARSE_ERROR("From"); }
    break;

  case 102:
#line 429 "parser.yxx"
    { PARSE_ERROR("In-Reply-To"); }
    break;

  case 103:
#line 431 "parser.yxx"
    { PARSE_ERROR("Max-Forwards"); }
    break;

  case 104:
#line 433 "parser.yxx"
    { PARSE_ERROR("Min-Expires"); }
    break;

  case 105:
#line 435 "parser.yxx"
    { PARSE_ERROR("MIME-Version"); }
    break;

  case 106:
#line 437 "parser.yxx"
    { PARSE_ERROR("Organization"); }
    break;

  case 107:
#line 439 "parser.yxx"
    { PARSE_ERROR("P-Asserted-Identity"); }
    break;

  case 108:
#line 441 "parser.yxx"
    { PARSE_ERROR("P-Preferred-Identity"); }
    break;

  case 109:
#line 443 "parser.yxx"
    { PARSE_ERROR("Priority"); }
    break;

  case 110:
#line 445 "parser.yxx"
    { PARSE_ERROR("Privacy"); }
    break;

  case 111:
#line 447 "parser.yxx"
    { PARSE_ERROR("Proxy-Authenticate"); }
    break;

  case 112:
#line 449 "parser.yxx"
    { PARSE_ERROR("Proxy-Authorization"); }
    break;

  case 113:
#line 451 "parser.yxx"
    { PARSE_ERROR("Proxy-Require"); }
    break;

  case 114:
#line 453 "parser.yxx"
    { PARSE_ERROR("RAck"); }
    break;

  case 115:
#line 455 "parser.yxx"
    { PARSE_ERROR("Record-Route"); }
    break;

  case 116:
#line 457 "parser.yxx"
    { PARSE_ERROR("Service-Route"); }
    break;

  case 117:
#line 459 "parser.yxx"
    { PARSE_ERROR("Refer-Sub"); }
    break;

  case 118:
#line 461 "parser.yxx"
    { PARSE_ERROR("Refer-To"); }
    break;

  case 119:
#line 463 "parser.yxx"
    { PARSE_ERROR("Referred-By"); }
    break;

  case 120:
#line 465 "parser.yxx"
    { PARSE_ERROR("Replaces"); }
    break;

  case 121:
#line 467 "parser.yxx"
    { PARSE_ERROR("Reply-To"); }
    break;

  case 122:
#line 469 "parser.yxx"
    { PARSE_ERROR("Require"); }
    break;

  case 123:
#line 471 "parser.yxx"
    { PARSE_ERROR("Retry-After"); }
    break;

  case 124:
#line 473 "parser.yxx"
    { PARSE_ERROR("Route"); }
    break;

  case 125:
#line 475 "parser.yxx"
    { PARSE_ERROR("RSeq"); }
    break;

  case 126:
#line 477 "parser.yxx"
    { PARSE_ERROR("Server"); }
    break;

  case 127:
#line 479 "parser.yxx"
    { PARSE_ERROR("SIP-ETag"); }
    break;

  case 128:
#line 481 "parser.yxx"
    { PARSE_ERROR("SIP-If-Match"); }
    break;

  case 129:
#line 483 "parser.yxx"
    { PARSE_ERROR("Subject"); }
    break;

  case 130:
#line 485 "parser.yxx"
    { PARSE_ERROR("Subscription-State"); }
    break;

  case 131:
#line 487 "parser.yxx"
    { PARSE_ERROR("Supported"); }
    break;

  case 132:
#line 489 "parser.yxx"
    { PARSE_ERROR("Timestamp"); }
    break;

  case 133:
#line 491 "parser.yxx"
    { PARSE_ERROR("To"); }
    break;

  case 134:
#line 493 "parser.yxx"
    { PARSE_ERROR("Unsupported"); }
    break;

  case 135:
#line 495 "parser.yxx"
    { PARSE_ERROR("User-Agent"); }
    break;

  case 136:
#line 497 "parser.yxx"
    { PARSE_ERROR("Via"); }
    break;

  case 137:
#line 499 "parser.yxx"
    { PARSE_ERROR("Warning"); }
    break;

  case 138:
#line 501 "parser.yxx"
    { PARSE_ERROR("WWW-Authenticate"); }
    break;

  case 141:
#line 517 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 146:
#line 527 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 147:
#line 529 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 149:
#line 533 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 152:
#line 539 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 153:
#line 541 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 155:
#line 545 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 156:
#line 547 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 159:
#line 553 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 160:
#line 555 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 161:
#line 557 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 162:
#line 559 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 163:
#line 561 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 165:
#line 565 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 166:
#line 567 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 167:
#line 569 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 170:
#line 575 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 171:
#line 577 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 173:
#line 581 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 174:
#line 583 "parser.yxx"
    { CTXT_URI; }
    break;

  case 175:
#line 585 "parser.yxx"
    { CTXT_URI; }
    break;

  case 177:
#line 589 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 178:
#line 591 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 179:
#line 593 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 180:
#line 595 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 182:
#line 599 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 183:
#line 601 "parser.yxx"
    { CTXT_URI; }
    break;

  case 184:
#line 603 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 188:
#line 611 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 191:
#line 617 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 192:
#line 619 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 196:
#line 627 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 197:
#line 629 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 199:
#line 633 "parser.yxx"
    {
			(yyvsp[(1) - (2)].yyt_media)->add_params(*(yyvsp[(2) - (2)].yyt_params));
			MSG->hdr_accept.add_media(*(yyvsp[(1) - (2)].yyt_media));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_media)); delete (yyvsp[(1) - (2)].yyt_media);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 200:
#line 638 "parser.yxx"
    {
			(yyvsp[(3) - (4)].yyt_media)->add_params(*(yyvsp[(4) - (4)].yyt_params));
			MSG->hdr_accept.add_media(*(yyvsp[(3) - (4)].yyt_media));
			MEMMAN_DELETE((yyvsp[(3) - (4)].yyt_media)); delete (yyvsp[(3) - (4)].yyt_media);
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_params)); delete (yyvsp[(4) - (4)].yyt_params); }
    break;

  case 201:
#line 645 "parser.yxx"
    { (yyval.yyt_media) = new t_media(tolower(*(yyvsp[(1) - (3)].yyt_str)), tolower(*(yyvsp[(3) - (3)].yyt_str)));
					MEMMAN_NEW((yyval.yyt_media));
					MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
					MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 202:
#line 651 "parser.yxx"
    { (yyval.yyt_params) = new list<t_parameter>; MEMMAN_NEW((yyval.yyt_params)); }
    break;

  case 203:
#line 652 "parser.yxx"
    {
			(yyvsp[(1) - (3)].yyt_params)->push_back(*(yyvsp[(3) - (3)].yyt_param));
			(yyval.yyt_params) = (yyvsp[(1) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 204:
#line 658 "parser.yxx"
    {
			(yyval.yyt_param) = new t_parameter(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 205:
#line 662 "parser.yxx"
    { CTXT_PARAMVAL; }
    break;

  case 206:
#line 662 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 207:
#line 662 "parser.yxx"
    {
			(yyval.yyt_param) = new t_parameter(tolower(*(yyvsp[(1) - (5)].yyt_str)), *(yyvsp[(4) - (5)].yyt_str));
			MEMMAN_NEW((yyval.yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str);
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_str)); delete (yyvsp[(4) - (5)].yyt_str); }
    break;

  case 208:
#line 669 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 209:
#line 671 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 210:
#line 675 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*(yyvsp[(1) - (1)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_coding)); delete (yyvsp[(1) - (1)].yyt_coding); }
    break;

  case 211:
#line 678 "parser.yxx"
    {
			MSG->hdr_accept_encoding.add_coding(*(yyvsp[(3) - (3)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_coding)); delete (yyvsp[(3) - (3)].yyt_coding); }
    break;

  case 212:
#line 683 "parser.yxx"
    {
			(yyval.yyt_coding) = new t_coding(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 213:
#line 687 "parser.yxx"
    {
			(yyval.yyt_coding) = new t_coding(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_coding));
			(yyval.yyt_coding)->q = (yyvsp[(2) - (2)].yyt_float);
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str); }
    break;

  case 214:
#line 694 "parser.yxx"
    {
			if ((yyvsp[(2) - (2)].yyt_param)->name != "q") YYERROR;
			(yyval.yyt_float) = atof((yyvsp[(2) - (2)].yyt_param)->value.c_str());
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_param)); delete (yyvsp[(2) - (2)].yyt_param);
			}
    break;

  case 215:
#line 701 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 216:
#line 701 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*(yyvsp[(2) - (2)].yyt_language));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_language)); delete (yyvsp[(2) - (2)].yyt_language); }
    break;

  case 217:
#line 704 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 218:
#line 704 "parser.yxx"
    {
			MSG->hdr_accept_language.add_language(*(yyvsp[(4) - (4)].yyt_language));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_language)); delete (yyvsp[(4) - (4)].yyt_language); }
    break;

  case 219:
#line 709 "parser.yxx"
    {
			CTXT_INITIAL;
		  	(yyval.yyt_language) = new t_language(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_language));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 220:
#line 714 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 221:
#line 714 "parser.yxx"
    {
			(yyval.yyt_language) = new t_language(tolower(*(yyvsp[(1) - (3)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_language));
			(yyval.yyt_language)->q = (yyvsp[(3) - (3)].yyt_float);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str); }
    break;

  case 222:
#line 721 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*(yyvsp[(1) - (1)].yyt_alert_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_alert_param)); delete (yyvsp[(1) - (1)].yyt_alert_param); }
    break;

  case 223:
#line 724 "parser.yxx"
    {
			MSG->hdr_alert_info.add_param(*(yyvsp[(3) - (3)].yyt_alert_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_alert_param)); delete (yyvsp[(3) - (3)].yyt_alert_param); }
    break;

  case 224:
#line 729 "parser.yxx"
    { CTXT_URI; }
    break;

  case 225:
#line 729 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 226:
#line 729 "parser.yxx"
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

  case 227:
#line 744 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 228:
#line 747 "parser.yxx"
    {
			MSG->hdr_allow.add_method(*(yyvsp[(3) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 229:
#line 752 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 230:
#line 752 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 231:
#line 752 "parser.yxx"
    {
			MSG->hdr_call_id.set_call_id(*(yyvsp[(2) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 232:
#line 757 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 233:
#line 758 "parser.yxx"
    {
			(yyval.yyt_str) = new string(*(yyvsp[(1) - (3)].yyt_str) + '@' + *(yyvsp[(3) - (3)].yyt_str));
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 234:
#line 765 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*(yyvsp[(1) - (1)].yyt_info_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_info_param)); delete (yyvsp[(1) - (1)].yyt_info_param); }
    break;

  case 235:
#line 768 "parser.yxx"
    {
			MSG->hdr_call_info.add_param(*(yyvsp[(3) - (3)].yyt_info_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_info_param)); delete (yyvsp[(3) - (3)].yyt_info_param); }
    break;

  case 236:
#line 773 "parser.yxx"
    { CTXT_URI; }
    break;

  case 237:
#line 773 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 238:
#line 773 "parser.yxx"
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

  case 239:
#line 788 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 240:
#line 788 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 241:
#line 788 "parser.yxx"
    {
			MSG->hdr_contact.set_any(); }
    break;

  case 242:
#line 790 "parser.yxx"
    {
			MSG->hdr_contact.add_contacts(*(yyvsp[(1) - (1)].yyt_contacts));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_contacts)); delete (yyvsp[(1) - (1)].yyt_contacts); }
    break;

  case 243:
#line 795 "parser.yxx"
    {
			(yyval.yyt_contacts) = new list<t_contact_param>;
			MEMMAN_NEW((yyval.yyt_contacts));
			(yyval.yyt_contacts)->push_back(*(yyvsp[(1) - (1)].yyt_contact));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_contact)); delete (yyvsp[(1) - (1)].yyt_contact); }
    break;

  case 244:
#line 800 "parser.yxx"
    {
			(yyvsp[(1) - (3)].yyt_contacts)->push_back(*(yyvsp[(3) - (3)].yyt_contact));
			(yyval.yyt_contacts) = (yyvsp[(1) - (3)].yyt_contacts);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_contact)); delete (yyvsp[(3) - (3)].yyt_contact); }
    break;

  case 245:
#line 806 "parser.yxx"
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

  case 246:
#line 822 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 247:
#line 822 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 248:
#line 822 "parser.yxx"
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

  case 249:
#line 833 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 250:
#line 833 "parser.yxx"
    { CTXT_URI; }
    break;

  case 251:
#line 833 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 252:
#line 833 "parser.yxx"
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

  case 253:
#line 848 "parser.yxx"
    { (yyval.yyt_str) = new string(); MEMMAN_NEW((yyval.yyt_str)); }
    break;

  case 254:
#line 849 "parser.yxx"
    {
			(yyval.yyt_str) = new string(rtrim(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 255:
#line 853 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 256:
#line 856 "parser.yxx"
    {
			MSG->hdr_content_disp.set_type(tolower(*(yyvsp[(1) - (2)].yyt_str)));
			
			list<t_parameter>::const_iterator i;
			for (i = (yyvsp[(2) - (2)].yyt_params)->begin(); i != (yyvsp[(2) - (2)].yyt_params)->end(); i++) {
				if (i->name == "filename") {
					MSG->hdr_content_disp.set_filename(i->value);
				} else {
					MSG->hdr_content_disp.add_param(*i);
				}
			}

			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 257:
#line 872 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*(yyvsp[(1) - (1)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_coding)); delete (yyvsp[(1) - (1)].yyt_coding); }
    break;

  case 258:
#line 875 "parser.yxx"
    {
			MSG->hdr_content_encoding.add_coding(*(yyvsp[(3) - (3)].yyt_coding));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_coding)); delete (yyvsp[(3) - (3)].yyt_coding); }
    break;

  case 259:
#line 880 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 260:
#line 880 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*(yyvsp[(2) - (2)].yyt_language));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_language)); delete (yyvsp[(2) - (2)].yyt_language); }
    break;

  case 261:
#line 883 "parser.yxx"
    { CTXT_LANG; }
    break;

  case 262:
#line 883 "parser.yxx"
    {
			MSG->hdr_content_language.add_language(*(yyvsp[(4) - (4)].yyt_language));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_language)); delete (yyvsp[(4) - (4)].yyt_language); }
    break;

  case 263:
#line 888 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 264:
#line 888 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 265:
#line 888 "parser.yxx"
    {
			MSG->hdr_content_length.set_length((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 266:
#line 892 "parser.yxx"
    {
			(yyvsp[(1) - (2)].yyt_media)->add_params(*(yyvsp[(2) - (2)].yyt_params));
			MSG->hdr_content_type.set_media(*(yyvsp[(1) - (2)].yyt_media));
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_media)); delete (yyvsp[(1) - (2)].yyt_media);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_params)); delete (yyvsp[(2) - (2)].yyt_params); }
    break;

  case 267:
#line 899 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 268:
#line 899 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 269:
#line 899 "parser.yxx"
    {
			MSG->hdr_cseq.set_seqnr((yyvsp[(2) - (4)].yyt_ulong));
			MSG->hdr_cseq.set_method(*(yyvsp[(4) - (4)].yyt_str));
			MEMMAN_DELETE((yyvsp[(4) - (4)].yyt_str)); delete (yyvsp[(4) - (4)].yyt_str); }
    break;

  case 270:
#line 905 "parser.yxx"
    { CTXT_DATE;}
    break;

  case 271:
#line 908 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 272:
#line 908 "parser.yxx"
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

  case 273:
#line 919 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*(yyvsp[(1) - (1)].yyt_error_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_error_param)); delete (yyvsp[(1) - (1)].yyt_error_param); }
    break;

  case 274:
#line 922 "parser.yxx"
    {
			MSG->hdr_error_info.add_param(*(yyvsp[(3) - (3)].yyt_error_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_error_param)); delete (yyvsp[(3) - (3)].yyt_error_param); }
    break;

  case 275:
#line 927 "parser.yxx"
    { CTXT_URI; }
    break;

  case 276:
#line 927 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 277:
#line 927 "parser.yxx"
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

  case 278:
#line 942 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 279:
#line 942 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 280:
#line 942 "parser.yxx"
    {
			MSG->hdr_expires.set_time((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 281:
#line 946 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 282:
#line 946 "parser.yxx"
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

  case 283:
#line 961 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 284:
#line 961 "parser.yxx"
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

  case 285:
#line 972 "parser.yxx"
    { CTXT_URI; }
    break;

  case 286:
#line 972 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 287:
#line 972 "parser.yxx"
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

  case 288:
#line 987 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 289:
#line 987 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 290:
#line 987 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*(yyvsp[(2) - (3)].yyt_str));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 291:
#line 990 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 292:
#line 990 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 293:
#line 990 "parser.yxx"
    {
			MSG->hdr_in_reply_to.add_call_id(*(yyvsp[(4) - (5)].yyt_str));
			MEMMAN_DELETE((yyvsp[(4) - (5)].yyt_str)); delete (yyvsp[(4) - (5)].yyt_str); }
    break;

  case 294:
#line 995 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 295:
#line 995 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 296:
#line 995 "parser.yxx"
    {
			MSG->hdr_max_forwards.set_max_forwards((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 297:
#line 999 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 298:
#line 999 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 299:
#line 999 "parser.yxx"
    {
			MSG->hdr_min_expires.set_time((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 300:
#line 1003 "parser.yxx"
    {
			MSG->hdr_mime_version.set_version(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 301:
#line 1008 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 302:
#line 1008 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 303:
#line 1008 "parser.yxx"
    {
			MSG->hdr_organization.set_name(trim(*(yyvsp[(2) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 304:
#line 1013 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 305:
#line 1013 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*(yyvsp[(2) - (2)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_from_addr)); delete (yyvsp[(2) - (2)].yyt_from_addr); }
    break;

  case 306:
#line 1016 "parser.yxx"
    {
				MSG->hdr_p_asserted_identity.add_identity(*(yyvsp[(3) - (3)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_from_addr)); delete (yyvsp[(3) - (3)].yyt_from_addr); }
    break;

  case 307:
#line 1021 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 308:
#line 1021 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*(yyvsp[(2) - (2)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_from_addr)); delete (yyvsp[(2) - (2)].yyt_from_addr); }
    break;

  case 309:
#line 1024 "parser.yxx"
    {
				MSG->hdr_p_preferred_identity.add_identity(*(yyvsp[(3) - (3)].yyt_from_addr));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_from_addr)); delete (yyvsp[(3) - (3)].yyt_from_addr); }
    break;

  case 310:
#line 1029 "parser.yxx"
    {
			MSG->hdr_priority.set_priority(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 311:
#line 1034 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 312:
#line 1037 "parser.yxx"
    {
			MSG->hdr_privacy.add_privacy(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 313:
#line 1042 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 314:
#line 1045 "parser.yxx"
    {
			MSG->hdr_proxy_require.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 315:
#line 1050 "parser.yxx"
    {
			MSG->hdr_record_route.add_route(*(yyvsp[(1) - (1)].yyt_route));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_route)); delete (yyvsp[(1) - (1)].yyt_route); }
    break;

  case 316:
#line 1053 "parser.yxx"
    {
		  	MSG->hdr_record_route.add_route(*(yyvsp[(3) - (3)].yyt_route));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_route)); delete (yyvsp[(3) - (3)].yyt_route); }
    break;

  case 317:
#line 1058 "parser.yxx"
    { CTXT_URI; }
    break;

  case 318:
#line 1058 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 319:
#line 1059 "parser.yxx"
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

  case 320:
#line 1076 "parser.yxx"
    {
			MSG->hdr_service_route.add_route(*(yyvsp[(1) - (1)].yyt_route));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_route)); delete (yyvsp[(1) - (1)].yyt_route); }
    break;

  case 321:
#line 1079 "parser.yxx"
    {
		  	MSG->hdr_service_route.add_route(*(yyvsp[(3) - (3)].yyt_route));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_route)); delete (yyvsp[(3) - (3)].yyt_route); }
    break;

  case 322:
#line 1084 "parser.yxx"
    { CTXT_WORD; }
    break;

  case 323:
#line 1084 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 324:
#line 1084 "parser.yxx"
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

  case 325:
#line 1106 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 326:
#line 1106 "parser.yxx"
    {
			MSG->hdr_reply_to.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_reply_to.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			MSG->hdr_reply_to.set_params(*(yyvsp[(3) - (3)].yyt_params));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 327:
#line 1114 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 328:
#line 1117 "parser.yxx"
    {
			MSG->hdr_require.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 329:
#line 1122 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 330:
#line 1122 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 331:
#line 1122 "parser.yxx"
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

  case 332:
#line 1138 "parser.yxx"
    { (yyval.yyt_str) = new string(); MEMMAN_NEW((yyval.yyt_str)); }
    break;

  case 333:
#line 1139 "parser.yxx"
    { CTXT_COMMENT; }
    break;

  case 334:
#line 1139 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 335:
#line 1139 "parser.yxx"
    {
			(yyval.yyt_str) = (yyvsp[(3) - (5)].yyt_str); }
    break;

  case 336:
#line 1143 "parser.yxx"
    {
			MSG->hdr_route.add_route(*(yyvsp[(1) - (1)].yyt_route));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_route)); delete (yyvsp[(1) - (1)].yyt_route); }
    break;

  case 337:
#line 1146 "parser.yxx"
    {
		  	MSG->hdr_route.add_route(*(yyvsp[(3) - (3)].yyt_route));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_route)); delete (yyvsp[(3) - (3)].yyt_route); }
    break;

  case 338:
#line 1151 "parser.yxx"
    {
			MSG->hdr_server.add_server(*(yyvsp[(1) - (1)].yyt_server));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_server)); delete (yyvsp[(1) - (1)].yyt_server); }
    break;

  case 339:
#line 1154 "parser.yxx"
    {
			MSG->hdr_server.add_server(*(yyvsp[(2) - (2)].yyt_server));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_server)); delete (yyvsp[(2) - (2)].yyt_server); }
    break;

  case 340:
#line 1159 "parser.yxx"
    {
			(yyval.yyt_server) = new t_server();
			MEMMAN_NEW((yyval.yyt_server));
			(yyval.yyt_server)->comment = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 341:
#line 1164 "parser.yxx"
    {
			(yyval.yyt_server) = new t_server();
			MEMMAN_NEW((yyval.yyt_server));
			(yyval.yyt_server)->product = *(yyvsp[(1) - (2)].yyt_str);
			(yyval.yyt_server)->comment = *(yyvsp[(2) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (2)].yyt_str)); delete (yyvsp[(1) - (2)].yyt_str);
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_str)); delete (yyvsp[(2) - (2)].yyt_str); }
    break;

  case 342:
#line 1171 "parser.yxx"
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

  case 343:
#line 1182 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 344:
#line 1182 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 345:
#line 1182 "parser.yxx"
    {
			MSG->hdr_subject.set_subject(trim(*(yyvsp[(2) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_str)); delete (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 346:
#line 1187 "parser.yxx"
    {
			MSG->hdr_supported.set_empty(); }
    break;

  case 347:
#line 1189 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 348:
#line 1192 "parser.yxx"
    {
			MSG->hdr_supported.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 349:
#line 1197 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 350:
#line 1197 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 351:
#line 1200 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp((yyvsp[(1) - (1)].yyt_float)); }
    break;

  case 352:
#line 1202 "parser.yxx"
    {
			MSG->hdr_timestamp.set_timestamp((yyvsp[(1) - (2)].yyt_float));
			MSG->hdr_timestamp.set_delay((yyvsp[(2) - (2)].yyt_float)); }
    break;

  case 353:
#line 1207 "parser.yxx"
    { (yyval.yyt_float) = (yyvsp[(1) - (1)].yyt_ulong); }
    break;

  case 354:
#line 1208 "parser.yxx"
    {
			string s = int2str((yyvsp[(1) - (3)].yyt_ulong)) + '.' + int2str((yyvsp[(3) - (3)].yyt_ulong));
			(yyval.yyt_float) = atof(s.c_str()); }
    break;

  case 355:
#line 1213 "parser.yxx"
    { (yyval.yyt_float) = (yyvsp[(1) - (1)].yyt_ulong); }
    break;

  case 356:
#line 1214 "parser.yxx"
    {
			string s = int2str((yyvsp[(1) - (3)].yyt_ulong)) + '.' + int2str((yyvsp[(3) - (3)].yyt_ulong));
			(yyval.yyt_float) = atof(s.c_str()); }
    break;

  case 357:
#line 1219 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 358:
#line 1219 "parser.yxx"
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

  case 359:
#line 1234 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*(yyvsp[(1) - (1)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 360:
#line 1237 "parser.yxx"
    {
			MSG->hdr_unsupported.add_feature(tolower(*(yyvsp[(3) - (3)].yyt_str)));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 361:
#line 1242 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*(yyvsp[(1) - (1)].yyt_server));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_server)); delete (yyvsp[(1) - (1)].yyt_server); }
    break;

  case 362:
#line 1245 "parser.yxx"
    {
			MSG->hdr_user_agent.add_server(*(yyvsp[(2) - (2)].yyt_server));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_server)); delete (yyvsp[(2) - (2)].yyt_server); }
    break;

  case 363:
#line 1250 "parser.yxx"
    {
			MSG->hdr_via.add_via(*(yyvsp[(1) - (1)].yyt_via));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_via)); delete (yyvsp[(1) - (1)].yyt_via); }
    break;

  case 364:
#line 1253 "parser.yxx"
    {
			MSG->hdr_via.add_via(*(yyvsp[(3) - (3)].yyt_via));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_via)); delete (yyvsp[(3) - (3)].yyt_via); }
    break;

  case 365:
#line 1258 "parser.yxx"
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

  case 366:
#line 1286 "parser.yxx"
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

  case 367:
#line 1297 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 368:
#line 1302 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 369:
#line 1302 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 370:
#line 1302 "parser.yxx"
    {
			if ((yyvsp[(4) - (5)].yyt_ulong) > 65535) YYERROR;
			
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (5)].yyt_str);
			(yyval.yyt_via)->port = (yyvsp[(4) - (5)].yyt_ulong);
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str); }
    break;

  case 371:
#line 1310 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (1)].yyt_str);
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 372:
#line 1315 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 373:
#line 1315 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 374:
#line 1315 "parser.yxx"
    {
			(yyval.yyt_via) = new t_via();
			MEMMAN_NEW((yyval.yyt_via));
			(yyval.yyt_via)->host = *(yyvsp[(1) - (5)].yyt_str);
			(yyval.yyt_via)->port = (yyvsp[(4) - (5)].yyt_ulong);
			MEMMAN_DELETE((yyvsp[(1) - (5)].yyt_str)); delete (yyvsp[(1) - (5)].yyt_str); }
    break;

  case 375:
#line 1323 "parser.yxx"
    { CTXT_IPV6ADDR; }
    break;

  case 376:
#line 1323 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 377:
#line 1323 "parser.yxx"
    {
			// TODO: check correct format of IPv6 address
			(yyval.yyt_str) = new string('[' + *(yyvsp[(3) - (5)].yyt_str) + ']');
			MEMMAN_NEW((yyval.yyt_str));
			MEMMAN_DELETE((yyvsp[(3) - (5)].yyt_str)); }
    break;

  case 378:
#line 1330 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*(yyvsp[(1) - (1)].yyt_warning));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_warning)); delete (yyvsp[(1) - (1)].yyt_warning); }
    break;

  case 379:
#line 1333 "parser.yxx"
    {
			MSG->hdr_warning.add_warning(*(yyvsp[(3) - (3)].yyt_warning));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_warning)); delete (yyvsp[(3) - (3)].yyt_warning); }
    break;

  case 380:
#line 1338 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 381:
#line 1338 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 382:
#line 1338 "parser.yxx"
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

  case 383:
#line 1349 "parser.yxx"
    { CTXT_LINE; }
    break;

  case 384:
#line 1349 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 385:
#line 1349 "parser.yxx"
    { (yyval.yyt_str) = (yyvsp[(2) - (3)].yyt_str); }
    break;

  case 386:
#line 1352 "parser.yxx"
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

  case 389:
#line 1376 "parser.yxx"
    {
			(yyval.yyt_dig_resp) = new t_digest_response();
			MEMMAN_NEW((yyval.yyt_dig_resp));
			if (!(yyval.yyt_dig_resp)->set_attr(*(yyvsp[(1) - (1)].yyt_param))) {
				MEMMAN_DELETE((yyval.yyt_dig_resp)); delete (yyval.yyt_dig_resp);
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 390:
#line 1384 "parser.yxx"
    {
			(yyval.yyt_dig_resp) = (yyvsp[(1) - (3)].yyt_dig_resp);
			if (!(yyval.yyt_dig_resp)->set_attr(*(yyvsp[(3) - (3)].yyt_param))) {
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 391:
#line 1392 "parser.yxx"
    {
			(yyval.yyt_params) = new list<t_parameter>;
			MEMMAN_NEW((yyval.yyt_params));
			(yyval.yyt_params)->push_back(*(yyvsp[(1) - (1)].yyt_param));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 392:
#line 1397 "parser.yxx"
    {
			(yyval.yyt_params) = (yyvsp[(1) - (3)].yyt_params);
			(yyval.yyt_params)->push_back(*(yyvsp[(3) - (3)].yyt_param));
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 393:
#line 1403 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 394:
#line 1403 "parser.yxx"
    {
			(yyval.yyt_credentials) = new t_credentials;
			MEMMAN_NEW((yyval.yyt_credentials));
			(yyval.yyt_credentials)->auth_scheme = AUTH_DIGEST;
			(yyval.yyt_credentials)->digest_response = *(yyvsp[(3) - (3)].yyt_dig_resp);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_dig_resp)); delete (yyvsp[(3) - (3)].yyt_dig_resp); }
    break;

  case 395:
#line 1409 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 396:
#line 1409 "parser.yxx"
    {
			(yyval.yyt_credentials) = new t_credentials;
			MEMMAN_NEW((yyval.yyt_credentials));
			(yyval.yyt_credentials)->auth_scheme = *(yyvsp[(1) - (3)].yyt_str);
			(yyval.yyt_credentials)->auth_params = *(yyvsp[(3) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 397:
#line 1418 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 398:
#line 1418 "parser.yxx"
    {
			MSG->hdr_authorization.add_credentials(*(yyvsp[(2) - (2)].yyt_credentials));
			MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_credentials)); delete (yyvsp[(2) - (2)].yyt_credentials); }
    break;

  case 399:
#line 1423 "parser.yxx"
    {
			(yyval.yyt_dig_chlg) = new t_digest_challenge();
			MEMMAN_NEW((yyval.yyt_dig_chlg));
			if (!(yyval.yyt_dig_chlg)->set_attr(*(yyvsp[(1) - (1)].yyt_param))) {
				MEMMAN_DELETE((yyval.yyt_dig_chlg)); delete (yyval.yyt_dig_chlg);
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_param)); delete (yyvsp[(1) - (1)].yyt_param); }
    break;

  case 400:
#line 1431 "parser.yxx"
    {
			(yyval.yyt_dig_chlg) = (yyvsp[(1) - (3)].yyt_dig_chlg);
			if (!(yyval.yyt_dig_chlg)->set_attr(*(yyvsp[(3) - (3)].yyt_param))) {
				YYERROR;
			}
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_param)); delete (yyvsp[(3) - (3)].yyt_param); }
    break;

  case 401:
#line 1439 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 402:
#line 1439 "parser.yxx"
    {
			(yyval.yyt_challenge) = new t_challenge;
			MEMMAN_NEW((yyval.yyt_challenge));
			(yyval.yyt_challenge)->auth_scheme = AUTH_DIGEST;
			(yyval.yyt_challenge)->digest_challenge = *(yyvsp[(3) - (3)].yyt_dig_chlg);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_dig_chlg)); delete (yyvsp[(3) - (3)].yyt_dig_chlg); }
    break;

  case 403:
#line 1445 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 404:
#line 1445 "parser.yxx"
    {
			(yyval.yyt_challenge) = new t_challenge;
			MEMMAN_NEW((yyval.yyt_challenge));
			(yyval.yyt_challenge)->auth_scheme = *(yyvsp[(1) - (3)].yyt_str);
			(yyval.yyt_challenge)->auth_params = *(yyvsp[(3) - (3)].yyt_params);
			MEMMAN_DELETE((yyvsp[(1) - (3)].yyt_str)); delete (yyvsp[(1) - (3)].yyt_str);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 405:
#line 1454 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 406:
#line 1454 "parser.yxx"
    {
				MSG->hdr_proxy_authenticate.set_challenge(*(yyvsp[(2) - (2)].yyt_challenge));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_challenge)); delete (yyvsp[(2) - (2)].yyt_challenge); }
    break;

  case 407:
#line 1459 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 408:
#line 1459 "parser.yxx"
    {
				MSG->hdr_proxy_authorization.
							add_credentials(*(yyvsp[(2) - (2)].yyt_credentials));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_credentials)); delete (yyvsp[(2) - (2)].yyt_credentials); }
    break;

  case 409:
#line 1465 "parser.yxx"
    { CTXT_AUTH_SCHEME; }
    break;

  case 410:
#line 1465 "parser.yxx"
    {
				MSG->hdr_www_authenticate.set_challenge(*(yyvsp[(2) - (2)].yyt_challenge));
				MEMMAN_DELETE((yyvsp[(2) - (2)].yyt_challenge)); delete (yyvsp[(2) - (2)].yyt_challenge); }
    break;

  case 411:
#line 1470 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 412:
#line 1470 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 413:
#line 1470 "parser.yxx"
    {
			MSG->hdr_rseq.set_resp_nr((yyvsp[(2) - (3)].yyt_ulong)); }
    break;

  case 414:
#line 1474 "parser.yxx"
    { CTXT_NUM; }
    break;

  case 415:
#line 1474 "parser.yxx"
    { CTXT_INITIAL; }
    break;

  case 416:
#line 1474 "parser.yxx"
    {
			MSG->hdr_rack.set_resp_nr((yyvsp[(2) - (5)].yyt_ulong));
			MSG->hdr_rack.set_cseq_nr((yyvsp[(3) - (5)].yyt_ulong));
			MSG->hdr_rack.set_method(*(yyvsp[(5) - (5)].yyt_str));
			MEMMAN_DELETE((yyvsp[(5) - (5)].yyt_str)); delete (yyvsp[(5) - (5)].yyt_str); }
    break;

  case 417:
#line 1481 "parser.yxx"
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

  case 418:
#line 1495 "parser.yxx"
    {
				MSG->hdr_allow_events.add_event_type(tolower(*(yyvsp[(1) - (1)].yyt_str)));
				MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 419:
#line 1498 "parser.yxx"
    {
		      		MSG->hdr_allow_events.add_event_type(tolower(*(yyvsp[(3) - (3)].yyt_str)));
				MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_str)); delete (yyvsp[(3) - (3)].yyt_str); }
    break;

  case 420:
#line 1503 "parser.yxx"
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

  case 421:
#line 1529 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 422:
#line 1529 "parser.yxx"
    {
			MSG->hdr_refer_to.set_display((yyvsp[(2) - (3)].yyt_from_addr)->display);
			MSG->hdr_refer_to.set_uri((yyvsp[(2) - (3)].yyt_from_addr)->uri);
			MSG->hdr_refer_to.set_params(*(yyvsp[(3) - (3)].yyt_params));
			MEMMAN_DELETE((yyvsp[(2) - (3)].yyt_from_addr)); delete (yyvsp[(2) - (3)].yyt_from_addr);
			MEMMAN_DELETE((yyvsp[(3) - (3)].yyt_params)); delete (yyvsp[(3) - (3)].yyt_params); }
    break;

  case 423:
#line 1537 "parser.yxx"
    { CTXT_URI_SPECIAL; }
    break;

  case 424:
#line 1537 "parser.yxx"
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

  case 425:
#line 1552 "parser.yxx"
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

  case 426:
#line 1563 "parser.yxx"
    {
			MSG->hdr_sip_etag.set_etag(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;

  case 427:
#line 1568 "parser.yxx"
    {
			MSG->hdr_sip_if_match.set_etag(*(yyvsp[(1) - (1)].yyt_str));
			MEMMAN_DELETE((yyvsp[(1) - (1)].yyt_str)); delete (yyvsp[(1) - (1)].yyt_str); }
    break;


/* Line 1267 of yacc.c.  */
#line 4852 "parser.cxx"
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


#line 1573 "parser.yxx"


void
yyerror (const char *s)  /* Called by yyparse on error */
{
  // printf ("%s\n", s);
}

