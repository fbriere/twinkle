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
     T_LINE_UNKNOWN = 269,
     T_NULL = 270
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
#define T_NULL 270




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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 49 "sdp_parser.yxx"
typedef union YYSTYPE {
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
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 141 "sdp_parser.cxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 153 "sdp_parser.cxx"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   48

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  18
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  31
/* YYNRULES -- Number of rules. */
#define YYNRULES  39
/* YYNRULES -- Number of states. */
#define YYNSTATES  74

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,    12,    15,    16,    17,    23,    24,    25,
      36,    38,    40,    41,    42,    48,    50,    51,    57,    59,
      60,    63,    67,    69,    70,    71,    77,    78,    81,    82,
      83,    96,    98,   102,   103,   106,   107,   110,   111,   112
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      19,     0,    -1,    20,    23,    28,    45,    31,    45,    33,
      39,    -1,     1,    15,    -1,    -1,    -1,     8,    21,     3,
      22,     7,    -1,    -1,    -1,     9,    24,     5,    25,     4,
       4,    26,    27,     4,     7,    -1,     4,    -1,     4,    -1,
      -1,    -1,    10,    29,     6,    30,     7,    -1,    32,    -1,
      -1,    11,    26,    27,     4,     7,    -1,    34,    -1,    -1,
      34,    35,    -1,    12,    36,     7,    -1,     4,    -1,    -1,
      -1,     4,    16,    37,     6,    38,    -1,    -1,    39,    40,
      -1,    -1,    -1,    13,     4,    41,     3,    42,    43,    44,
       7,    45,    32,    45,    34,    -1,     4,    -1,     4,    17,
       4,    -1,    -1,    44,     4,    -1,    -1,    45,    46,    -1,
      -1,    -1,    14,    47,     6,    48,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   104,   104,   116,   124,   124,   124,   129,   129,   129,
     143,   158,   169,   170,   169,   175,   180,   181,   191,   196,
     197,   202,   206,   210,   210,   210,   217,   218,   224,   224,
     224,   244,   252,   267,   268,   275,   276,   279,   279,   279
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
  "T_LINE_UNKNOWN", "T_NULL", "':'", "'/'", "$accept", "sdp_body", 
  "version", "@1", "@2", "origin", "@3", "@4", "network_type", 
  "address_type", "session_name", "@5", "@6", "sess_connection", 
  "connection", "sess_attributes", "attributes", "attribute", 
  "attribute2", "@7", "@8", "media_list", "media", "@9", "@10", 
  "transport", "formats", "unknown_lines", "unknown_line", "@11", "@12", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    58,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    18,    19,    19,    21,    22,    20,    24,    25,    23,
      26,    27,    29,    30,    28,    31,    32,    32,    33,    34,
      34,    35,    36,    37,    38,    36,    39,    39,    41,    42,
      40,    43,    43,    44,    44,    45,    45,    47,    48,    46
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     8,     2,     0,     0,     5,     0,     0,    10,
       1,     1,     0,     0,     5,     1,     0,     5,     1,     0,
       2,     3,     1,     0,     0,     5,     0,     2,     0,     0,
      12,     1,     3,     0,     2,     0,     2,     0,     0,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     4,     0,     0,     3,     0,     1,     7,     0,
       5,     0,    12,    35,     0,     8,     0,    16,     6,     0,
      13,     0,    37,    35,    15,    36,     0,     0,    10,     0,
       0,    19,     0,    14,    11,     0,    38,    26,    18,     0,
       0,     0,     2,     0,    20,     0,    17,    39,     0,    27,
      22,     0,     0,    28,    23,    21,     9,     0,     0,    29,
      24,     0,    25,    31,    33,     0,     0,    32,    34,    35,
      16,    35,    19,    30
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     3,     4,     6,    14,     9,    11,    19,    29,    35,
      13,    16,    27,    23,    24,    37,    38,    44,    51,    58,
      62,    42,    49,    57,    61,    64,    66,    17,    25,    30,
      41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yysigned_char yypact[] =
{
       0,   -11,   -32,     7,     1,   -32,     6,   -32,   -32,     2,
     -32,     8,   -32,   -32,     4,   -32,     9,    -9,   -32,    10,
     -32,    12,   -32,   -32,   -32,   -32,    13,    11,   -32,    15,
      14,    16,    12,   -32,   -32,    17,   -32,   -32,    19,    15,
      18,    20,    21,    22,   -32,    24,   -32,   -32,    25,   -32,
      23,    26,    28,   -32,   -32,   -32,   -32,    29,    30,   -32,
     -32,    33,   -32,     5,   -32,    34,    -1,   -32,   -32,   -32,
      -9,   -32,    16,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,    -8,   -16,
     -32,   -32,   -32,   -32,   -30,   -32,   -31,   -32,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -23,   -32,   -32,
     -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      31,     1,    21,    68,     5,    22,    69,     7,     2,    10,
       8,    18,    12,    15,    26,    20,    28,    32,    33,    34,
      36,    40,    65,    45,    39,    46,    50,    47,    52,    53,
      22,    43,    59,    55,    48,    56,    60,    63,    67,    54,
      71,    73,     0,     0,     0,     0,    70,     0,    72
};

static const yysigned_char yycheck[] =
{
      23,     1,    11,     4,    15,    14,     7,     0,     8,     3,
       9,     7,    10,     5,     4,     6,     4,     4,     7,     4,
       6,     4,    17,    39,    32,     7,     4,     7,     4,     4,
      14,    12,     3,     7,    13,     7,     6,     4,     4,    16,
      70,    72,    -1,    -1,    -1,    -1,    69,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,     8,    19,    20,    15,    21,     0,     9,    23,
       3,    24,    10,    28,    22,     5,    29,    45,     7,    25,
       6,    11,    14,    31,    32,    46,     4,    30,     4,    26,
      47,    45,     4,     7,     4,    27,     6,    33,    34,    26,
       4,    48,    39,    12,    35,    27,     7,     7,    13,    40,
       4,    36,     4,     4,    16,     7,     7,    41,    37,     3,
       6,    42,    38,     4,    43,    17,    44,     4,     4,     7,
      45,    32,    45,    34
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
#line 80 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_str); delete yyvaluep->yysdpt_str; };
#line 780 "sdp_parser.cxx"
        break;
      case 5: /* T_SAFE */
#line 81 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_str); delete yyvaluep->yysdpt_str; };
#line 785 "sdp_parser.cxx"
        break;
      case 6: /* T_LINE */
#line 82 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_str); delete yyvaluep->yysdpt_str; };
#line 790 "sdp_parser.cxx"
        break;
      case 32: /* connection */
#line 94 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_connection); delete yyvaluep->yysdpt_connection; };
#line 795 "sdp_parser.cxx"
        break;
      case 34: /* attributes */
#line 95 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_attributes); delete yyvaluep->yysdpt_attributes; };
#line 800 "sdp_parser.cxx"
        break;
      case 35: /* attribute */
#line 96 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_attribute); delete yyvaluep->yysdpt_attribute; };
#line 805 "sdp_parser.cxx"
        break;
      case 36: /* attribute2 */
#line 97 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_attribute); delete yyvaluep->yysdpt_attribute; };
#line 810 "sdp_parser.cxx"
        break;
      case 40: /* media */
#line 98 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_media); delete yyvaluep->yysdpt_media; };
#line 815 "sdp_parser.cxx"
        break;
      case 44: /* formats */
#line 99 "sdp_parser.yxx"
        { MEMMAN_DELETE(yyvaluep->yysdpt_num_list); delete yyvaluep->yysdpt_num_list; };
#line 820 "sdp_parser.cxx"
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
#line 111 "sdp_parser.yxx"
    {
		  	/* Parsing stops here. Remaining text is
			 * not parsed.
			 */
		  	YYACCEPT; }
    break;

  case 3:
#line 116 "sdp_parser.yxx"
    {
			/* KLUDGE to avoid memory leak in bison.
			 * See the SIP parser for an explanation.
			 */
			YYABORT;
		}
    break;

  case 4:
#line 124 "sdp_parser.yxx"
    { CTX_NUM; }
    break;

  case 5:
#line 124 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 6:
#line 125 "sdp_parser.yxx"
    {
			SDP->version = yyvsp[-2].yysdpt_int; }
    break;

  case 7:
#line 129 "sdp_parser.yxx"
    { CTX_SAFE; }
    break;

  case 8:
#line 129 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 9:
#line 130 "sdp_parser.yxx"
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

  case 10:
#line 143 "sdp_parser.yxx"
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

  case 11:
#line 158 "sdp_parser.yxx"
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

  case 12:
#line 169 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 13:
#line 170 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 14:
#line 170 "sdp_parser.yxx"
    {
			SDP->session_name = *yyvsp[-2].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str; }
    break;

  case 15:
#line 175 "sdp_parser.yxx"
    {
			SDP->connection = *yyvsp[0].yysdpt_connection;
			MEMMAN_DELETE(yyvsp[0].yysdpt_connection); delete yyvsp[0].yysdpt_connection; }
    break;

  case 16:
#line 180 "sdp_parser.yxx"
    { yyval.yysdpt_connection = new t_sdp_connection(); MEMMAN_NEW(yyval.yysdpt_connection); }
    break;

  case 17:
#line 182 "sdp_parser.yxx"
    {
			yyval.yysdpt_connection = new t_sdp_connection();
			MEMMAN_NEW(yyval.yysdpt_connection);
			yyval.yysdpt_connection->network_type = yyvsp[-3].yysdpt_ntwk_type;
			yyval.yysdpt_connection->address_type = yyvsp[-2].yysdpt_addr_type;
			yyval.yysdpt_connection->address = *yyvsp[-1].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-1].yysdpt_str); delete yyvsp[-1].yysdpt_str; }
    break;

  case 18:
#line 191 "sdp_parser.yxx"
    {
			SDP->attributes = *yyvsp[0].yysdpt_attributes;
			MEMMAN_DELETE(yyvsp[0].yysdpt_attributes); delete yyvsp[0].yysdpt_attributes; }
    break;

  case 19:
#line 196 "sdp_parser.yxx"
    { yyval.yysdpt_attributes = new list<t_sdp_attr>; MEMMAN_NEW(yyval.yysdpt_attributes); }
    break;

  case 20:
#line 197 "sdp_parser.yxx"
    {
			yyval.yysdpt_attributes->push_back(*yyvsp[0].yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[0].yysdpt_attribute); delete yyvsp[0].yysdpt_attribute; }
    break;

  case 21:
#line 202 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = yyvsp[-1].yysdpt_attribute; }
    break;

  case 22:
#line 206 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = new t_sdp_attr(*yyvsp[0].yysdpt_str);
			MEMMAN_NEW(yyval.yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str; }
    break;

  case 23:
#line 210 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 24:
#line 210 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 25:
#line 210 "sdp_parser.yxx"
    {
			yyval.yysdpt_attribute = new t_sdp_attr(*yyvsp[-4].yysdpt_str, *yyvsp[-1].yysdpt_str);
			MEMMAN_NEW(yyval.yysdpt_attribute);
			MEMMAN_DELETE(yyvsp[-4].yysdpt_str); delete yyvsp[-4].yysdpt_str;
			MEMMAN_DELETE(yyvsp[-1].yysdpt_str); delete yyvsp[-1].yysdpt_str; }
    break;

  case 27:
#line 218 "sdp_parser.yxx"
    {
			SDP->media.push_back(*yyvsp[0].yysdpt_media);
			MEMMAN_DELETE(yyvsp[0].yysdpt_media); delete yyvsp[0].yysdpt_media; }
    break;

  case 28:
#line 224 "sdp_parser.yxx"
    { CTX_NUM; }
    break;

  case 29:
#line 224 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 30:
#line 226 "sdp_parser.yxx"
    {
		  	yyval.yysdpt_media = new t_sdp_media();
			MEMMAN_NEW(yyval.yysdpt_media);
			
			if (yyvsp[-8].yysdpt_int > 65535) YYERROR;
			
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

  case 31:
#line 244 "sdp_parser.yxx"
    { try {
				yyval.yysdpt_transport = str2sdp_transport(*yyvsp[0].yysdpt_str);
				MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			    }
			    catch (t_sdp_syntax_error) {
			    	MEMMAN_DELETE(yyvsp[0].yysdpt_str); delete yyvsp[0].yysdpt_str;
			        YYABORT;
			    } }
    break;

  case 32:
#line 252 "sdp_parser.yxx"
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

  case 33:
#line 267 "sdp_parser.yxx"
    { yyval.yysdpt_num_list = new list<unsigned short>; MEMMAN_NEW(yyval.yysdpt_num_list); }
    break;

  case 34:
#line 268 "sdp_parser.yxx"
    {
			if (is_number(*yyvsp[0].yysdpt_str)) yyval.yysdpt_num_list->push_back(atoi(yyvsp[0].yysdpt_str->c_str()));
			MEMMAN_DELETE(yyvsp[0].yysdpt_str);
			delete yyvsp[0].yysdpt_str; }
    break;

  case 37:
#line 279 "sdp_parser.yxx"
    { CTX_LINE; }
    break;

  case 38:
#line 279 "sdp_parser.yxx"
    { CTX_INITIAL; }
    break;

  case 39:
#line 280 "sdp_parser.yxx"
    {
		  	MEMMAN_DELETE(yyvsp[-2].yysdpt_str); delete yyvsp[-2].yysdpt_str; }
    break;


    }

/* Line 991 of yacc.c.  */
#line 1400 "sdp_parser.cxx"

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


#line 284 "sdp_parser.yxx"


void
yysdperror (const char *s)  /* Called by yysdpparse on error */
{
  // printf ("%s\n", s);
}

