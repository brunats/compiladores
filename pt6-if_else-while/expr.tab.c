/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "expr.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "compilador.h"
#define YYSTYPE struct Atributo


#line 74 "expr.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TADD = 258,
    TMUL = 259,
    TSUB = 260,
    TDIV = 261,
    TAPAR = 262,
    TFPAR = 263,
    TNUM = 264,
    TFIM = 265,
    TIGUAL = 266,
    TMENORIGUAL = 267,
    TMAIORIGUAL = 268,
    TATRIBUICAO = 269,
    TMENOR = 270,
    TMAIOR = 271,
    TAND = 272,
    TOR = 273,
    TDIF = 274,
    TNOT = 275,
    TID = 276,
    TLIT = 277,
    TVOID = 278,
    TVIRG = 279,
    TACHA = 280,
    TFCHA = 281,
    TINT = 282,
    TSTRING = 283,
    TPVIRG = 284,
    TRET = 285,
    TIF = 286,
    TELSE = 287,
    TWHILE = 288,
    TPRINT = 289,
    TREAD = 290,
    TINC = 291,
    TDEC = 292,
    TATSUM = 293,
    TATSUB = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 162 "expr.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    13,    13,    14,    17,    18,    21,    22,    25,    26,
      29,    30,    33,    36,    37,    40,    41,    44,    47,    48,
      51,    52,    55,    58,    59,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    73,    76,    79,    82,    83,    86,
      89,    90,    91,    94,    95,    98,   101,   104,   107,   108,
     111,   112,   115,   116,   117,   120,   123,   126,   127,   128,
     131,   132,   133,   134,   135,   136,   139,   142,   143,   144,
     146,   147,   148,   150,   151,   152,   153,   154
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TADD", "TMUL", "TSUB", "TDIV", "TAPAR",
  "TFPAR", "TNUM", "TFIM", "TIGUAL", "TMENORIGUAL", "TMAIORIGUAL",
  "TATRIBUICAO", "TMENOR", "TMAIOR", "TAND", "TOR", "TDIF", "TNOT", "TID",
  "TLIT", "TVOID", "TVIRG", "TACHA", "TFCHA", "TINT", "TSTRING", "TPVIRG",
  "TRET", "TIF", "TELSE", "TWHILE", "TPRINT", "TREAD", "TINC", "TDEC",
  "TATSUM", "TATSUB", "$accept", "Programa", "ListaFuncoes", "Funcao",
  "TipoRetorno", "DeclParametros", "Parametro", "BlocoPrincipal",
  "Declaracoes", "Declaracao", "Tipo", "ListaId", "Bloco", "ListaCmd",
  "Comando", "CmdInc", "CmdDec", "Retorno", "CmdSe", "CmdEnquanto",
  "CmdAtrib", "CmdEscrita", "M", "CmdLeitura", "ChamadaProcedimento",
  "ChamadaFuncao", "ListaParametros", "ExpressaoLogica", "L", "N",
  "TLogico", "ExpressaoRelacional", "ExpressaoAritmetica", "Expr", "Termo",
  "Fator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,  -119,    63,  -119,  -119,    13,   135,  -119,    -4,  -119,
    -119,     7,    62,    27,  -119,  -119,    48,    63,  -119,    59,
     101,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,    47,  -119,  -119,  -119,    85,    17,    43,    56,    66,
      62,    62,    62,  -119,    93,  -119,    72,    46,    55,  -119,
      61,   103,   114,   109,  -119,   107,  -119,    -1,  -119,  -119,
    -119,    12,  -119,     8,  -119,    96,   115,  -119,  -119,   120,
    -119,   142,  -119,    62,    62,    62,    62,    61,    61,   106,
      71,  -119,   104,    61,    53,   143,  -119,   133,  -119,   134,
      23,  -119,   140,  -119,    62,  -119,  -119,  -119,  -119,    55,
      55,  -119,  -119,   156,   142,  -119,  -119,  -119,  -119,    62,
      62,    62,    62,    62,    62,   157,   158,   159,   139,  -119,
    -119,   134,    45,  -119,  -119,  -119,   144,    61,    61,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,   141,   145,  -119,  -119,
    -119,    78,   146,  -119,  -119,   144,  -119,  -119,   122,   147,
    -119,  -119,  -119,   144,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,    18,    19,     0,     0,     5,     0,     3,
       8,     0,     0,     0,    55,    45,     0,     0,    16,     0,
       0,    24,    31,    32,    33,    25,    26,    27,    28,    29,
      30,     0,     1,     4,     2,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    76,    77,     0,    66,    69,    72,
       0,     0,     0,     0,    15,     0,    21,     0,    14,    23,
      47,     0,    49,     0,    51,     0,     0,    34,    35,     0,
      75,     0,    36,     0,     0,     0,     0,     0,     0,     0,
      54,    59,     0,     0,     0,     0,    13,     0,    17,     0,
       0,    11,     0,    48,     0,    41,    40,    42,    74,    67,
      68,    70,    71,     0,    66,    57,    55,    55,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       7,     0,     0,    12,    50,    58,     0,     0,     0,    64,
      61,    60,    63,    62,    65,    55,     0,     0,    46,     6,
      10,     0,    37,    52,    53,     0,    44,    43,     0,     0,
      39,    22,    55,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   165,  -119,  -119,    50,    -3,  -119,   160,
       2,  -119,  -118,   -15,   -19,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,    -2,  -119,   -71,   -98,  -119,
      95,  -119,    -7,   -31,     5,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    90,    91,     9,    17,    18,
      10,    57,   142,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    52,    29,    30,    45,    63,    79,    51,   149,
      80,    81,    82,    47,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    59,    55,    34,    19,    46,   103,    70,   126,   127,
     128,    71,   115,    32,    36,    31,    93,    35,    31,    19,
      89,    37,    41,    87,    42,    62,    43,   150,    88,    64,
      66,   121,    94,    69,    50,   154,    59,   145,    44,     3,
       4,   101,   102,    38,    39,    40,   104,   122,    41,    73,
      42,    74,    43,    31,   153,    53,   143,   144,    41,    75,
      42,    76,    43,    92,    44,    65,    41,    41,    77,    42,
      43,    43,     3,     4,    44,   116,    60,   117,    99,   100,
      56,    78,    44,    44,    11,    67,   120,   124,   107,   108,
       3,     4,    61,    12,    13,    68,    14,    15,    16,    11,
      36,    72,   129,   130,   131,   132,   133,   134,    12,    13,
      83,    14,    15,    16,   106,   109,   110,   111,   139,   112,
     113,    84,    11,   114,    92,    95,   148,    58,    11,    59,
      85,    12,    13,    86,    14,    15,    16,    12,    13,    31,
      14,    15,    16,    11,    96,    73,    31,    74,   151,    97,
      98,   118,    12,    13,   119,    14,    15,    16,     1,     2,
       2,   123,     3,     4,   125,   135,   136,   137,   138,   141,
     146,    33,   140,   105,   147,     0,     0,    54,   -56,   152
};

static const yytype_int16 yycheck[] =
{
       2,    20,    17,     6,     2,    12,    77,    41,   106,   107,
     108,    42,    83,     0,     7,    17,     8,    21,    20,    17,
       8,    14,     5,    24,     7,     8,     9,   145,    29,    36,
      37,     8,    24,    40,     7,   153,    55,   135,    21,    27,
      28,    75,    76,    36,    37,    38,    77,    24,     5,     3,
       7,     5,     9,    55,   152,     7,   127,   128,     5,     4,
       7,     6,     9,    61,    21,    22,     5,     5,     7,     7,
       9,     9,    27,    28,    21,    22,    29,    84,    73,    74,
      21,    20,    21,    21,    21,    29,    89,    94,    17,    18,
      27,    28,     7,    30,    31,    29,    33,    34,    35,    21,
       7,    29,   109,   110,   111,   112,   113,   114,    30,    31,
       7,    33,    34,    35,     8,    11,    12,    13,   121,    15,
      16,     7,    21,    19,   122,    29,   141,    26,    21,   148,
      21,    30,    31,    26,    33,    34,    35,    30,    31,   141,
      33,    34,    35,    21,    29,     3,   148,     5,    26,    29,
       8,     8,    30,    31,    21,    33,    34,    35,    23,    25,
      25,    21,    27,    28,     8,     8,     8,     8,    29,    25,
      29,     6,   122,    78,    29,    -1,    -1,    17,    32,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    25,    27,    28,    41,    42,    43,    44,    47,
      50,    21,    30,    31,    33,    34,    35,    48,    49,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    63,
      64,    65,     0,    43,    47,    21,     7,    14,    36,    37,
      38,     5,     7,     9,    21,    65,    72,    73,    74,    75,
       7,    68,    62,     7,    49,    53,    21,    51,    26,    54,
      29,     7,     8,    66,    72,    22,    72,    29,    29,    72,
      75,    73,    29,     3,     5,     4,     6,     7,    20,    67,
      70,    71,    72,     7,     7,    21,    26,    24,    29,     8,
      45,    46,    50,     8,    24,    29,    29,    29,     8,    74,
      74,    75,    75,    67,    73,    70,     8,    17,    18,    11,
      12,    13,    15,    16,    19,    67,    22,    72,     8,    21,
      47,     8,    24,    21,    72,     8,    68,    68,    68,    72,
      72,    72,    72,    72,    72,     8,     8,     8,    29,    47,
      46,    25,    52,    67,    67,    68,    29,    29,    53,    69,
      52,    26,    32,    68,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    48,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    56,    57,    58,    58,    59,
      60,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    69,    70,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    73,
      74,    74,    74,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     6,     5,     1,     1,
       3,     1,     2,     4,     3,     2,     1,     3,     1,     1,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     6,    10,     7,
       4,     4,     4,     6,     6,     0,     5,     2,     4,     3,
       3,     1,     4,     4,     1,     0,     0,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     1,     3,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 29 "expr.y" /* yacc.c:1646  */
    { }
#line 1351 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 44 "expr.y" /* yacc.c:1646  */
    {insereArvore((yyvsp[-1]).l,(yyvsp[-2]).tipo);imprimeAuxArvore();/*liberar(&$$.l);*/}
#line 1357 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 47 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = INT;}
#line 1363 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 48 "expr.y" /* yacc.c:1646  */
    {(yyval).tipo = STRING;}
#line 1369 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 51 "expr.y" /* yacc.c:1646  */
    {insere(&(yyvsp[-2]).l,(yyvsp[0]).nomeId);/*imprime($1.l)*/;(yyval).l = (yyvsp[-2]).l;}
#line 1375 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 52 "expr.y" /* yacc.c:1646  */
    {(yyval).l = NULL; insere(&(yyval).l,(yyvsp[0]).nomeId);}
#line 1381 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 73 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IINC,frameFind(&(yyvsp[-2])));}
#line 1387 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 76 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IDEC,frameFind(&(yyvsp[-2])));}
#line 1393 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 82 "expr.y" /* yacc.c:1646  */
    {corrigir((yyvsp[-3]).listaV,(yyvsp[-1]).label);corrigir((yyvsp[-3]).listaF,novoLabel());}
#line 1399 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 83 "expr.y" /* yacc.c:1646  */
    {corrigir((yyvsp[-7]).listaV,(yyvsp[-5]).label);corrigir((yyvsp[-7]).listaF,(yyvsp[-1]).label);corrigir((yyvsp[-3]).listaV,novoLabel());}
#line 1405 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 86 "expr.y" /* yacc.c:1646  */
    {corrigir((yyvsp[-3]).listaV,(yyvsp[-1]).label);adicionarInstrucao(IGOTO,(yyvsp[-5]).label);corrigir((yyvsp[-3]).listaF, novoLabel());}
#line 1411 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 89 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(ISTORE,frameFind(&(yyvsp[-3])));}
#line 1417 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 91 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(ILOAD,frameFind(&(yyvsp[-3]))); adicionarInstrucao(IADD,-1); adicionarInstrucao(ISTORE,frameFind(&(yyvsp[-3])));}
#line 1423 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 94 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IINV,-1);}
#line 1429 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 95 "expr.y" /* yacc.c:1646  */
    {adicionaInstrucaoLiteral(LDC,(yyvsp[-2]).lit);adicionarInstrucao(SINV,-1);}
#line 1435 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 98 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IGET,-1);}
#line 1441 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 115 "expr.y" /* yacc.c:1646  */
    {corrigir((yyvsp[-3]).listaV, (yyvsp[-1]).label); (yyval).listaF = NULL; merge(&(yyval).listaF,(yyvsp[0]).listaF,(yyvsp[-3]).listaF);(yyval).listaV = (yyvsp[0]).listaV;}
#line 1447 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 116 "expr.y" /* yacc.c:1646  */
    {corrigir((yyvsp[-3]).listaF, (yyvsp[-1]).label);(yyval).listaV = NULL; merge(&(yyval).listaV,(yyvsp[0]).listaV,(yyvsp[-3]).listaV);(yyval).listaF = (yyvsp[0]).listaF;}
#line 1453 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 117 "expr.y" /* yacc.c:1646  */
    {(yyval).listaF = (yyvsp[0]).listaF ; (yyval).listaV = (yyvsp[0]).listaV;}
#line 1459 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 120 "expr.y" /* yacc.c:1646  */
    {(yyval).label = novoLabel();}
#line 1465 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 123 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());adicionarInstrucao(IGOTO,-1);}
#line 1471 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 126 "expr.y" /* yacc.c:1646  */
    {(yyval).listaV = (yyvsp[0]).listaF ; (yyval).listaF = (yyvsp[0]).listaV;}
#line 1477 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 127 "expr.y" /* yacc.c:1646  */
    {(yyval).listaV = (yyvsp[-1]).listaV ; (yyval).listaF = (yyvsp[-1]).listaF;}
#line 1483 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 128 "expr.y" /* yacc.c:1646  */
    {(yyval).listaV = (yyvsp[0]).listaV ; (yyval).listaF = (yyvsp[0]).listaF;}
#line 1489 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 131 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPGE,-1);adicionarInstrucao(IGOTO,-1);}
#line 1495 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 132 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPLE,-1);adicionarInstrucao(IGOTO,-1);}
#line 1501 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 133 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPGT,-1);adicionarInstrucao(IGOTO,-1);}
#line 1507 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 134 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPLT,-1);adicionarInstrucao(IGOTO,-1);}
#line 1513 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 135 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPEQ,-1);adicionarInstrucao(IGOTO,-1);}
#line 1519 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 136 "expr.y" /* yacc.c:1646  */
    {criaLista(&(yyval).listaV,proxInst());criaLista(&(yyval).listaF,proxInst()+1);adicionarInstrucao(IICMPNE,-1);adicionarInstrucao(IGOTO,-1);}
#line 1525 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 142 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IADD,-1);}
#line 1531 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 143 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(ISUB,-1);}
#line 1537 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 146 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IMUL,-1);}
#line 1543 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 147 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(IDIV,-1);}
#line 1549 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 150 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(CONST,(yyvsp[0]).valor);}
#line 1555 "expr.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 153 "expr.y" /* yacc.c:1646  */
    {adicionarInstrucao(ILOAD,frameFind(&(yyvsp[0])));}
#line 1561 "expr.tab.c" /* yacc.c:1646  */
    break;


#line 1565 "expr.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 156 "expr.y" /* yacc.c:1906  */

#include "lex.yy.c"

int yyerror (char *str)
{
	printf("%s - antes %s\n", str, yytext);
	
} 		 

int yywrap()
{
	return 1;
}
