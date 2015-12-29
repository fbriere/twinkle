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

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse yysdpparse
#define yylex   yysdplex
#define yyerror yysdperror
#define yylval  yysdplval
#define yychar  yysdpchar
#define yydebug yysdpdebug
#define yynerrs yysdpnerrs


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




/* Copy the first part of user declarations.  */
#line 19 "sdp_parser.yxx"

#include <cstdio>
#include <string>
#include "sdp_parse_ctrl.h"
#include "sdp.h"
#include "util.h"
#include "audits/memman.h"

using namespace std;

extern int yysdplex(void);
void yysdperror(const char *s);


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
/* Line 193 of /usr/share/bison/yacc.c.  */
#line 137 "sdp_parser.cxx"
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
#line 158 "sdp_parser.cxx"

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
#define YYFINAL  5
#define YYLAST   51

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  34
/* YYNRULES -- Number of rules. */
#define YYNRULES  41
/* YYNRULES -- Number of states. */
#define YYNSTATES  75

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   269

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    15,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,    12,    13,    14,    20,    21,    22,    33,
      35,    37,    38,    39,    45,    47,    48,    54,    56,    57,
      60,    64,    66,    67,    68,    74,    75,    78,    79,    80,
      93,    95,    99,   100,   101,   105,   106,   109,   110,   113,
     114,   115
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      18,     0,    -1,    19,    22,    27,    47,    30,    47,    32,
      38,    -1,    -1,    -1,     8,    20,     3,    21,     7,    -1,
      -1,    -1,     9,    23,     5,    24,     4,     4,    25,    26,
       4,     7,    -1,     4,    -1,     4,    -1,    -1,    -1,    10,
      28,     6,    29,     7,    -1,    31,    -1,    -1,    11,    25,
      26,     4,     7,    -1,    33,    -1,    -1,    33,    34,    -1,
      12,    35,     7,    -1,     4,    -1,    -1,    -1,     4,    15,
      36,     6,    37,    -1,    -1,    38,    39,    -1,    -1,    -1,
      13,     4,    40,     3,    41,    42,    43,     7,    47,    31,
      47,    33,    -1,     4,    -1,     4,    16,     4,    -1,    -1,
      -1,    44,    46,    45,    -1,    -1,    46,     3,    -1,    -1,
      47,    48,    -1,    -1,    -1,    14,    49,     6,    50,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   103,   103,   117,   117,   117,   122,   122,   122,   136,
     151,   162,   163,   162,   168,   173,   174,   184,   189,   190,
     195,   199,   203,   203,   203,   210,   211,   217,   217,   217,
     234,   242,   254,   254,   254,   258,   259,   264,   265,   268,
     268,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_TOKEN", "T_SAFE", "T_LINE", 
  "T_CRLF", "T_LINE_VERSION", "T_LINE_ORIGIN", "T_LINE_SESSION_NAME", 
  "T_LINE_CONNECTION", "T_LINE_ATTRIBUTE", "T_LINE_MEDIA", 
  "T_LINE_UNKNOWN", "':'", "'/'", "$accept", "sdp_body", "version", "@1", 
  "@2", "origin", "@3", "@4", "network_type", "address_type", 
  "session_name", "@5", "@6", "sess_connection", "connection", 
  "sess_attributes", "attributes", "attribute", "attribute2", "@7", "@8", 
  "media_list", "media", "@9", "@10", "transport", "formats", "@11", 
  "@12", "formats2", "unknown_lines", "unknown_line", "@13", "@14", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    58,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    17,    18,    20,    21,    19,    23,    24,    22,    25,
      26,    28,    29,    27,    30,    31,    31,    32,    33,    33,
      34,    35,    36,    37,    35,    38,    38,    40,    41,    39,
      42,    42,    44,    45,    43,    46,    46,    47,    47,    49,
      50,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     8,     0,     0,     5,     0,     0,    10,     1,
       1,     0,     0,     5,     1,     0,     5,     1,     0,     2,
       3,     1,     0,     0,     5,     0,     2,     0,     0,    12,
       1,     3,     0,     0,     3,     0,     2,     0,     2,     0,
       0,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     3,     0,     0,     0,     1,     6,     0,     4,     0,
      11,    37,     0,     7,     0,    15,     5,     0,    12,     0,
      39,    37,    14,    38,     0,     0,     9,     0,     0,    18,
       0,    13,    10,     0,    40,    25,    17,     0,     0,     0,
       2,     0,    19,     0,    16,    41,     0,    26,    21,     0,
       0,    27,    22,    20,     8,     0,     0,    28,    23,     0,
      24,    30,    32,     0,     0,    35,    31,    37,    33,    15,
      36,    34,    37,    18,    29
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     2,     3,     4,    12,     7,     9,    17,    27,    33,
      11,    14,    25,    21,    22,    35,    36,    42,    49,    56,
      60,    40,    47,    55,    59,    62,    64,    65,    71,    68,
      15,    23,    28,    39
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yysigned_char yypact[] =
{
      -6,   -50,     3,    -4,     4,   -50,   -50,    -2,   -50,     1,
     -50,   -50,     2,   -50,     5,   -10,   -50,     6,   -50,     8,
     -50,   -50,   -50,   -50,     9,     7,   -50,    11,    10,    12,
       8,   -50,   -50,    13,   -50,   -50,    15,    11,    14,    16,
      17,    18,   -50,    20,   -50,   -50,    21,   -50,    19,    22,
      24,   -50,   -50,   -50,   -50,    25,    26,   -50,   -50,    29,
     -50,    23,   -50,    31,    30,   -50,   -50,   -50,    33,   -10,
     -50,   -50,   -50,    12,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -12,   -18,
     -50,   -50,   -50,   -50,   -49,   -50,   -35,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -21,   -50,   -50,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      29,    19,     1,     5,    20,     6,    13,     8,    10,    16,
      24,    18,    26,    30,    31,    32,    34,    38,    37,    43,
      72,    44,    48,    45,    50,    51,    20,    41,    57,    53,
      46,    54,    58,    61,    52,    66,    70,    67,    74,    63,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,    73
};

static const yysigned_char yycheck[] =
{
      21,    11,     8,     0,    14,     9,     5,     3,    10,     7,
       4,     6,     4,     4,     7,     4,     6,     4,    30,    37,
      69,     7,     4,     7,     4,     4,    14,    12,     3,     7,
      13,     7,     6,     4,    15,     4,     3,     7,    73,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    72
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     8,    18,    19,    20,     0,     9,    22,     3,    23,
      10,    27,    21,     5,    28,    47,     7,    24,     6,    11,
      14,    30,    31,    48,     4,    29,     4,    25,    49,    47,
       4,     7,     4,    26,     6,    32,    33,    25,     4,    50,
      38,    12,    34,    26,     7,     7,    13,    39,     4,    35,
       4,     4,    15,     7,     7,    40,    36,     3,     6,    41,
      37,     4,    42,    16,    43,    44,     4,     7,    46,    47,
       3,    45,    31,    47,    33
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
#line 0 "sdp_parser.yxx"
        (null);
#line 685 "sdp_parser.cxx"
        break;
      case 5: /* T_SAFE */
#line 0 "sdp_parser.yxx"
        (null);
#line 690 "sdp_parser.cxx"
        break;
      case 6: /* T_LINE */
#line 0 "sdp_parser.yxx"
        (null);
#line 695 "sdp_parser.cxx"
        break;
      case 31: /* connection */
#line 0 "sdp_parser.yxx"
        (null);
#line 700 "sdp_parser.cxx"
        break;
      case 33: /* attributes */
#line 0 "sdp_parser.yxx"
        (null);
#line 705 "sdp_parser.cxx"
        break;
      case 34: /* attribute */
#line 0 "sdp_parser.yxx"
        (null);
#line 710 "sdp_parser.cxx"
        break;
      case 35: /* attribute2 */
#line 0 "sdp_parser.yxx"
        (null);
#line 715 "sdp_parser.cxx"
        break;
      case 39: /* media */
#line 0 "sdp_parser.yxx"
        (null);
#line 720 "sdp_parser.cxx"
        break;
      case 43: /* formats */
#line 0 "sdp_parser.yxx"
        (null);
#line 725 "sdp_parser.cxx"
        break;
      case 46: /* formats2 */
#line 0 "sdp_parser.yxx"
        (null);
#line 730 "sdp_parser.cxx"
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
#line 77 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_str); delete yyvalue.yysdpt_str; };
#line 761 "sdp_parser.cxx"
        break;
      case 5: /* T_SAFE */
#line 78 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_str); delete yyvalue.yysdpt_str; };
#line 766 "sdp_parser.cxx"
        break;
      case 6: /* T_LINE */
#line 79 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_str); delete yyvalue.yysdpt_str; };
#line 771 "sdp_parser.cxx"
        break;
      case 31: /* connection */
#line 92 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_connection); delete yyvalue.yysdpt_connection; };
#line 776 "sdp_parser.cxx"
        break;
      case 33: /* attributes */
#line 93 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_attributes); delete yyvalue.yysdpt_attributes; };
#line 781 "sdp_parser.cxx"
        break;
      case 34: /* attribute */
#line 94 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_attribute); delete yyvalue.yysdpt_attribute; };
#line 786 "sdp_parser.cxx"
        break;
      case 35: /* attribute2 */
#line 95 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_attribute); delete yyvalue.yysdpt_attribute; };
#line 791 "sdp_parser.cxx"
        break;
      case 39: /* media */
#line 96 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_media); delete yyvalue.yysdpt_media; };
#line 796 "sdp_parser.cxx"
        break;
      case 43: /* formats */
#line 97 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_num_list); delete yyvalue.yysdpt_num_list; };
#line 801 "sdp_parser.cxx"
        break;
      case 46: /* formats2 */
#line 98 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvalue.yysdpt_num_list); delete yyvalue.yysdpt_num_list; };
#line 806 "sdp_parser.cxx"
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
#line 110 "sdp_parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 3:
#line 117 "sdp_parser.yxx"
    { CTX_NUM; }
    break;

  case 4:
#line 117 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 5:
#line 118 "sdp_parser.yxx"
    {
			SDP->version = yyvsp[-2].yysdpt_int; }
    break;

  case 6:
#line 122 "sdp_parser.yxx"
    { CTX_SAFE; }
    break;

  case 7:
#line 122 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 8:
#line 123 "sdp_parser.yxx"
    {
			SDP->origin.username = *yyvsp[-7].yysdpt_str;
			SDP->origin.session_id = *yyvsp[-5].yysdpt_str;
			SDP->origin.session_version = *yyvsp[-4].yysdpt_str;
			SDP->origin.network_type = yyvsp[-3].yysdpt_ntwk_type;
			SDP->origin.address_type = yyvsp[-2].yysdpt_addr_type;
			SDP->origin.address = *yyvsp[-1].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-7].yysdpt_str); delete yyvsp[-7].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-5].yysdpt_str); delete yyvsp[-5].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-4].yysdpt_str); delete yyvsp[-4].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-1].yysdpt_str); delete yyvsp[-1].yysdpt_str; }
    break;

  case 9:
#line 136 "sdp_parser.yxx"
    { try {
				yyval.yysdpt_ntwk_type = str2sdp_ntwk_type(*yyvsp[0].yysdpt_str);
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			    }
			    catch (t_sdp_syntax_error) {
			    	// Invalid network type.
				// Set network type to NULL. This way the message
				// will not be discarded and the error can be
				// handled on the SIP level (error response or
				// call tear down).
			    	MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
				yyval.yysdpt_ntwk_type = SDP_NTWK_NULL;
			    } }
    break;

  case 10:
#line 151 "sdp_parser.yxx"
    { try {
				yyval.yysdpt_addr_type = str2sdp_addr_type(*yyvsp[0].yysdpt_str);
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			    }
			    catch (t_sdp_syntax_error) {
			    	// Invalid address type
			    	MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
				yyval.yysdpt_addr_type = SDP_ADDR_NULL;
			    } }
    break;

  case 11:
#line 162 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 12:
#line 163 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 13:
#line 163 "sdp_parser.yxx"
    {
			SDP->session_name = *yyvsp[-2].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str; }
    break;

  case 14:
#line 168 "sdp_parser.yxx"
    {
			SDP->connection = *yyvsp[0].yysdpt_connection;
			MEMMAN_DELETE(yyvsp[0].yysdpt_connection); delete yyvsp[0].yysdpt_connection; }
    break;

  case 15:
#line 173 "sdp_parser.yxx"
    { yyval.yysdpt_connection = new t_sdp_connection(); MEMMAN_NEW(yyval.yysdpt_connection); }
    break;

  case 16:
#line 175 "sdp_parser.yxx"
    {
			yyval.yysdpt_connection = new t_sdp_connection();
			MEMMAN_NEW(yyval.yysdpt_connection);
			yyval.yysdpt_connection->network_type = yyvsp[-3].yysdpt_ntwk_type;
			yyval.yysdpt_connection->address_type = yyvsp[-2].yysdpt_addr_type;
			yyval.yysdpt_connection->address = *yyvsp[-1].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-1].yysdpt_str); delete yyvsp[-1].yysdpt_str; }
    break;

  case 17:
#line 184 "sdp_parser.yxx"
    {
			SDP->attributes = *yyvsp[0].yysdpt_attributes;
			MEMMAN_DELETE(yyvsp[0].yysdpt_attributes); delete yyvsp[0].yysdpt_attributes; }
    break;

  case 18:
#line 189 "sdp_parser.yxx"
    { yyval.yysdpt_attributes = new list<t_sdp_attr>; MEMMAN_NEW(yyval.yysdpt_attributes); }
    break;

  case 19:
#line 190 "sdp_parser.yxx"
    {
			yyval.yysdpt_attributes->push_back(*yyvsp[0].yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[0].yysdpt_attribute); delete yyvsp[0].yysdpt_attribute; }
    break;

  case 20:
#line 195 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = yyvsp[-1].yysdpt_attribute; }
    break;

  case 21:
#line 199 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = new t_sdp_attr(*yyvsp[0].yysdpt_str);
			MEMMAN_NEW(yyval.yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str; }
    break;

  case 22:
#line 203 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 23:
#line 203 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 24:
#line 203 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = new t_sdp_attr(*yyvsp[-4].yysdpt_str, *yyvsp[-1].yysdpt_str);
			MEMMAN_NEW(yyval.yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[-4].yysdpt_str); delete yyvsp[-4].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-1].yysdpt_str); delete yyvsp[-1].yysdpt_str; }
    break;

  case 26:
#line 211 "sdp_parser.yxx"
    {
			SDP->media.push_back(*yyvsp[0].yysdpt_media);
			MEMMAN_DELETE(yyvsp[0].yysdpt_media); delete yyvsp[0].yysdpt_media; }
    break;

  case 27:
#line 217 "sdp_parser.yxx"
    { CTX_NUM; }
    break;

  case 28:
#line 217 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 29:
#line 219 "sdp_parser.yxx"
    {
		  	yyval.yysdpt_media = new t_sdp_media();
			MEMMAN_NEW(yyval.yysdpt_media);
			yyval.yysdpt_media->media_type = tolower(*yyvsp[-10].yysdpt_str);
			yyval.yysdpt_media->port = yyvsp[-8].yysdpt_int;
			yyval.yysdpt_media->transport = yyvsp[-6].yysdpt_transport;
			yyval.yysdpt_media->formats = *yyvsp[-5].yysdpt_num_list;
			yyval.yysdpt_media->connection = *yyvsp[-2].yysdpt_connection;
			yyval.yysdpt_media->attributes = *yyvsp[0].yysdpt_attributes;
			MEMMAN_DELETE(yyvsp[-10].yysdpt_str); delete yyvsp[-10].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-5].yysdpt_num_list); delete yyvsp[-5].yysdpt_num_list;
			MEMMAN_DELETE(yyvsp[-2].yysdpt_connection); delete yyvsp[-2].yysdpt_connection;
			MEMMAN_DELETE(yyvsp[0].yysdpt_attributes); delete yyvsp[0].yysdpt_attributes; }
    break;

  case 30:
#line 234 "sdp_parser.yxx"
    { try {
				yyval.yysdpt_transport = str2sdp_transport(*yyvsp[0].yysdpt_str);
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			    }
			    catch (t_sdp_syntax_error) {
			    	MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			        YYABORT;
			    } }
    break;

  case 31:
#line 242 "sdp_parser.yxx"
    { try {
				yyval.yysdpt_transport = str2sdp_transport(*yyvsp[-2].yysdpt_str + '/' + *yyvsp[0].yysdpt_str);
				MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str;
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			    }
			    catch (t_sdp_syntax_error) {
			    	MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str;
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
				yyval.yysdpt_transport = SDP_TRANS_NULL;
			    } }
    break;

  case 32:
#line 254 "sdp_parser.yxx"
    { CTX_NUM; }
    break;

  case 33:
#line 254 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 34:
#line 254 "sdp_parser.yxx"
    {
			yyval.yysdpt_num_list = yyvsp[-1].yysdpt_num_list; }
    break;

  case 35:
#line 258 "sdp_parser.yxx"
    { yyval.yysdpt_num_list = new list<unsigned short>; MEMMAN_NEW(yyval.yysdpt_num_list); }
    break;

  case 36:
#line 259 "sdp_parser.yxx"
    {
			yyval.yysdpt_num_list->push_back(yyvsp[0].yysdpt_int); }
    break;

  case 39:
#line 268 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 40:
#line 268 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 41:
#line 269 "sdp_parser.yxx"
    {
		  	MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str; }
    break;


    }

/* Line 1016 of /usr/share/bison/yacc.c.  */
#line 1407 "sdp_parser.cxx"

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


#line 273 "sdp_parser.yxx"


void
yysdperror (const char *s)  /* Called by yysdpparse on error */
{
  // printf ("%s\n", s);
}

