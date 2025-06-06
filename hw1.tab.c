/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "hw1.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
extern FILE* yyin;
extern int line_number;

void yyerror(const char* s);
node_t* ast_root = NULL;

#line 84 "hw1.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HW1_TAB_H_INCLUDED
# define YY_YY_HW1_TAB_H_INCLUDED
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
    ID = 258,
    INT_LIT = 259,
    FLOAT_LIT = 260,
    STRING_LIT = 261,
    TRUE_LIT = 262,
    FALSE_LIT = 263,
    DEF = 264,
    IF = 265,
    ELIF = 266,
    ELSE = 267,
    WHILE = 268,
    RETURN = 269,
    PASS = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    IS = 274,
    INT = 275,
    FLOAT = 276,
    BOOL = 277,
    STRING = 278,
    GE = 279,
    LE = 280,
    EQ = 281,
    NE = 282,
    GT = 283,
    LT = 284,
    ASSIGN = 285,
    ARROW = 286,
    PLUS = 287,
    MINUS = 288,
    TIMES = 289,
    DIVIDE = 290,
    POW = 291,
    LPAREN = 292,
    RPAREN = 293,
    LBRACE = 294,
    RBRACE = 295,
    LBRACKET = 296,
    RBRACKET = 297,
    COLON = 298,
    SEMICOLON = 299,
    COMMA = 300,
    UMINUS = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "hw1.y"

    char* str;
    node_t* node;
    data_type_t type;

#line 189 "hw1.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HW1_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    63,    66,    75,    83,    91,    99,   110,
     113,   119,   122,   131,   143,   146,   155,   161,   171,   172,
     173,   174,   178,   183,   188,   193,   198,   206,   214,   217,
     230,   242,   245,   254,   259,   268,   271,   284,   287,   293,
     296,   299,   302,   308,   311,   314,   320,   327,   335,   338,
     345,   350,   355,   361,   370,   375,   383,   389,   398,   401,
     410,   413,   418,   421,   424,   427,   432,   437,   442,   447,
     452,   457,   462,   467,   472,   477,   482,   487,   492,   497,
     501,   508,   515,   525,   530,   536,   541,   547
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT_LIT", "FLOAT_LIT",
  "STRING_LIT", "TRUE_LIT", "FALSE_LIT", "DEF", "IF", "ELIF", "ELSE",
  "WHILE", "RETURN", "PASS", "AND", "OR", "NOT", "IS", "INT", "FLOAT",
  "BOOL", "STRING", "GE", "LE", "EQ", "NE", "GT", "LT", "ASSIGN", "ARROW",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "POW", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACKET", "RBRACKET", "COLON", "SEMICOLON", "COMMA",
  "UMINUS", "$accept", "program", "function_list", "function",
  "parameters", "parameter_list", "parameter_group", "param_names",
  "param", "type", "literal", "block", "variable_declarations",
  "variable_declaration", "variable_list", "variable_spec", "statements",
  "statement", "simple_statement", "compound_statement",
  "assignment_statement", "return_statement", "if_statement",
  "while_statement", "function_call", "argument_list", "expression",
  "string_access", "string_slice", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    31,    42,     9,   -45,     6,   -45,   -45,    38,   -45,
     -45,   -45,   -45,    10,     8,   -45,    53,   -18,    38,    20,
      19,   -45,    38,    18,   -45,    66,    53,    23,   -11,   139,
     -45,   -45,   -45,    24,   -45,   -45,   -45,    59,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,    18,   139,   103,     2,   -14,
     139,   139,   139,   -45,   -45,   249,   -45,    38,   -45,   139,
     -45,    46,   249,   -45,    -7,   249,   139,   135,    54,   288,
     -45,   226,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,    94,   -45,     1,   249,
     -45,   -45,   139,   249,   -45,   139,   -45,   -45,   288,   270,
      98,    98,    98,   306,   306,    98,    98,    65,    65,    69,
      69,    69,    72,    -8,   -45,   139,   139,   -45,   -45,   -45,
      73,   -45,   -45,   -45,   249,   163,   139,   -45,    94,   184,
     205,   -45,   139,   249,   -45,    18,    18,   249,   104,    76,
     -45,    78,    80,   112,   -45,    87,    85,   -45,    14,    93,
     -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     9,    18,
      19,    20,    21,     0,    10,    11,     0,     0,     0,    16,
      13,    14,     0,     0,    12,     0,     0,     0,     0,    48,
      42,    28,     5,     0,    39,    41,    40,     0,    22,    23,
      24,    25,    26,    17,    15,     0,     0,     0,     0,    61,
       0,     0,     0,    60,    62,    49,    63,    35,     7,     0,
       6,     0,    46,    56,     0,    58,    86,     0,     0,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,    47,
       8,    57,     0,    84,    81,    85,    82,    64,    76,    77,
      78,    72,    73,    74,    75,    70,    71,    65,    66,    67,
      68,    69,    33,     0,    31,     0,     0,    27,    45,    36,
       0,    38,    43,    44,    59,    83,     0,    30,     0,     0,
       0,    37,     0,    34,    32,     0,     0,    87,    50,     0,
      54,     0,     0,    51,    55,     0,     0,    52,     0,     0,
      53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   136,   -45,   -45,   120,   -45,   122,   -10,
     124,   -42,   -45,   -45,   -45,    22,   -45,   -45,   -44,   -45,
     -45,   -45,   -45,   -45,   -23,   -45,     3,   -21,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    13,    14,    15,    20,    21,    16,
      53,    32,    57,    87,   113,   114,    88,   119,    33,   121,
      34,    35,   122,   123,    54,    64,    55,    56,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    61,    37,    60,    28,    49,    38,    39,    40,    41,
      42,   115,    27,    22,   116,    29,    30,    28,     1,    46,
      50,    28,    36,    47,    37,    23,    47,    48,    29,    30,
      48,    91,    29,    30,     5,    51,   127,   128,    92,    52,
      31,   117,     6,     8,   120,    66,   118,    86,    17,    62,
      65,    67,    18,    69,    70,    71,    19,    31,     9,    10,
      11,    12,    89,    25,    26,    36,    45,    37,    58,    93,
      38,    39,    40,    41,    42,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    59,
      90,   139,   141,   138,   140,   124,    96,   112,   125,    83,
      84,    85,   126,   147,   149,    85,    49,    38,    39,    40,
      41,    42,    36,    36,    37,    37,   142,   131,   129,   130,
     143,    50,   144,   145,   146,    36,    31,    37,   148,   133,
      81,    82,    83,    84,    85,   137,    51,   150,    24,     7,
      52,    63,    49,    38,    39,    40,    41,    42,    44,    43,
     134,    72,    73,     0,    74,     0,     0,    50,     0,    75,
      76,    77,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    51,     0,     0,     0,    52,    94,    95,    72,
      73,     0,    74,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,     0,     0,    81,    82,    83,    84,    85,
      72,    73,     0,    74,     0,     0,   132,     0,    75,    76,
      77,    78,    79,    80,     0,     0,    81,    82,    83,    84,
      85,    72,    73,     0,    74,     0,     0,   135,     0,    75,
      76,    77,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    72,    73,     0,    74,     0,     0,   136,     0,
      75,    76,    77,    78,    79,    80,     0,     0,    81,    82,
      83,    84,    85,     0,    97,    72,    73,     0,    74,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    82,    83,    84,    85,    72,     0,     0,    74,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
       0,     0,    81,    82,    83,    84,    85,    74,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,    85,    74,     0,     0,     0,     0,
      75,    76,     0,     0,    79,    80,     0,     0,    81,    82,
      83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      23,    45,    23,    45,     3,     3,     4,     5,     6,     7,
       8,    10,    22,    31,    13,    14,    15,     3,     9,    30,
      18,     3,    45,    37,    45,    43,    37,    41,    14,    15,
      41,    38,    14,    15,     3,    33,    44,    45,    45,    37,
      39,    40,     0,    37,    88,    43,    88,    57,    38,    46,
      47,    48,    44,    50,    51,    52,     3,    39,    20,    21,
      22,    23,    59,    43,    45,    88,    43,    88,    44,    66,
       4,     5,     6,     7,     8,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    30,
      44,   135,   136,   135,   136,    92,    42,     3,    95,    34,
      35,    36,    30,   145,   148,    36,     3,     4,     5,     6,
       7,     8,   135,   136,   135,   136,    12,    44,   115,   116,
      44,    18,    44,    43,    12,   148,    39,   148,    43,   126,
      32,    33,    34,    35,    36,   132,    33,    44,    18,     3,
      37,    38,     3,     4,     5,     6,     7,     8,    26,    25,
     128,    16,    17,    -1,    19,    -1,    -1,    18,    -1,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    33,    -1,    -1,    -1,    37,    42,    43,    16,
      17,    -1,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    36,
      16,    17,    -1,    19,    -1,    -1,    43,    -1,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      36,    16,    17,    -1,    19,    -1,    -1,    43,    -1,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    36,    16,    17,    -1,    19,    -1,    -1,    43,    -1,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36,    -1,    38,    16,    17,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    36,    16,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    36,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    36,    19,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    48,    49,    50,     3,     0,    50,    37,    20,
      21,    22,    23,    51,    52,    53,    56,    38,    44,     3,
      54,    55,    31,    43,    53,    43,    45,    56,     3,    14,
      15,    39,    58,    65,    67,    68,    71,    74,     4,     5,
       6,     7,     8,    57,    55,    43,    30,    37,    41,     3,
      18,    33,    37,    57,    71,    73,    74,    59,    44,    30,
      58,    65,    73,    38,    72,    73,    43,    73,    75,    73,
      73,    73,    16,    17,    19,    24,    25,    26,    27,    28,
      29,    32,    33,    34,    35,    36,    56,    60,    63,    73,
      44,    38,    45,    73,    42,    43,    42,    38,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,     3,    61,    62,    10,    13,    40,    58,    64,
      65,    66,    69,    70,    73,    73,    30,    44,    45,    73,
      73,    44,    43,    73,    62,    43,    43,    73,    58,    65,
      58,    65,    12,    44,    44,    43,    12,    58,    43,    65,
      44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,     9,     8,    10,     0,
       1,     1,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     2,
       3,     1,     3,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     2,
       4,     5,     7,     9,     4,     5,     3,     4,     1,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     4,     3,     2,     2,     1,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2:
#line 56 "hw1.y"
                  {
        ast_root = (yyvsp[0].node);
        (yyval.node) = (yyvsp[0].node);
    }
#line 1516 "hw1.tab.c"
    break;

  case 3:
#line 63 "hw1.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1524 "hw1.tab.c"
    break;

  case 4:
#line 66 "hw1.y"
                             {
        node_t* last = (yyvsp[-1].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1535 "hw1.tab.c"
    break;

  case 5:
#line 75 "hw1.y"
                                                {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-5].str));
        (yyval.node)->name = strdup((yyvsp[-5].str));
        (yyval.node)->data_type = TYPE_VOID;
        (yyval.node)->params = (yyvsp[-3].node);
        (yyval.node)->body = (yyvsp[0].node);
        free((yyvsp[-5].str));
    }
#line 1548 "hw1.tab.c"
    break;

  case 6:
#line 83 "hw1.y"
                                                             {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-7].str));
        (yyval.node)->name = strdup((yyvsp[-7].str));
        (yyval.node)->data_type = (yyvsp[-2].type);
        (yyval.node)->params = (yyvsp[-5].node);
        (yyval.node)->body = (yyvsp[0].node);
        free((yyvsp[-7].str));
    }
#line 1561 "hw1.tab.c"
    break;

  case 7:
#line 91 "hw1.y"
                                                                       {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-6].str));
        (yyval.node)->name = strdup((yyvsp[-6].str));
        (yyval.node)->data_type = TYPE_VOID;
        (yyval.node)->params = (yyvsp[-4].node);
        (yyval.node)->body = (yyvsp[-1].node);
        free((yyvsp[-6].str));
    }
#line 1574 "hw1.tab.c"
    break;

  case 8:
#line 99 "hw1.y"
                                                                                  {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-8].str));
        (yyval.node)->name = strdup((yyvsp[-8].str));
        (yyval.node)->data_type = (yyvsp[-3].type);
        (yyval.node)->params = (yyvsp[-6].node);
        (yyval.node)->body = (yyvsp[-1].node);
        free((yyvsp[-8].str));
    }
#line 1587 "hw1.tab.c"
    break;

  case 9:
#line 110 "hw1.y"
                {
        (yyval.node) = NULL;
    }
#line 1595 "hw1.tab.c"
    break;

  case 10:
#line 113 "hw1.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1603 "hw1.tab.c"
    break;

  case 11:
#line 119 "hw1.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1611 "hw1.tab.c"
    break;

  case 12:
#line 122 "hw1.y"
                                               {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1622 "hw1.tab.c"
    break;

  case 13:
#line 131 "hw1.y"
                     {
        // Set type for all parameters in this group
        node_t* param = (yyvsp[0].node);
        while (param) {
            param->data_type = (yyvsp[-1].type);
            param = param->next;
        }
        (yyval.node) = (yyvsp[0].node);
    }
#line 1636 "hw1.tab.c"
    break;

  case 14:
#line 143 "hw1.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1644 "hw1.tab.c"
    break;

  case 15:
#line 146 "hw1.y"
                              {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1655 "hw1.tab.c"
    break;

  case 16:
#line 155 "hw1.y"
       {
        (yyval.node) = make_node(NODE_PARAM, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        (yyval.node)->has_default = false;
        free((yyvsp[0].str));
    }
#line 1666 "hw1.tab.c"
    break;

  case 17:
#line 161 "hw1.y"
                       {
        (yyval.node) = make_node(NODE_PARAM, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->has_default = true;
        (yyval.node)->default_value = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1678 "hw1.tab.c"
    break;

  case 18:
#line 171 "hw1.y"
            { (yyval.type) = TYPE_INT; }
#line 1684 "hw1.tab.c"
    break;

  case 19:
#line 172 "hw1.y"
            { (yyval.type) = TYPE_FLOAT; }
#line 1690 "hw1.tab.c"
    break;

  case 20:
#line 173 "hw1.y"
            { (yyval.type) = TYPE_BOOL; }
#line 1696 "hw1.tab.c"
    break;

  case 21:
#line 174 "hw1.y"
             { (yyval.type) = TYPE_STRING; }
#line 1702 "hw1.tab.c"
    break;

  case 22:
#line 178 "hw1.y"
            {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_INT;
        free((yyvsp[0].str));
    }
#line 1712 "hw1.tab.c"
    break;

  case 23:
#line 183 "hw1.y"
                {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_FLOAT;
        free((yyvsp[0].str));
    }
#line 1722 "hw1.tab.c"
    break;

  case 24:
#line 188 "hw1.y"
                 {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_STRING;
        free((yyvsp[0].str));
    }
#line 1732 "hw1.tab.c"
    break;

  case 25:
#line 193 "hw1.y"
               {
        (yyval.node) = make_node(NODE_LITERAL, "True");
        (yyval.node)->data_type = TYPE_BOOL;
        free((yyvsp[0].str));
    }
#line 1742 "hw1.tab.c"
    break;

  case 26:
#line 198 "hw1.y"
                {
        (yyval.node) = make_node(NODE_LITERAL, "False");
        (yyval.node)->data_type = TYPE_BOOL;
        free((yyvsp[0].str));
    }
#line 1752 "hw1.tab.c"
    break;

  case 27:
#line 206 "hw1.y"
                                                   {
        (yyval.node) = make_node(NODE_BLOCK, NULL);
        (yyval.node)->left = (yyvsp[-2].node);  // declarations
        (yyval.node)->body = (yyvsp[-1].node);  // statements
    }
#line 1762 "hw1.tab.c"
    break;

  case 28:
#line 214 "hw1.y"
                {
        (yyval.node) = NULL;
    }
#line 1770 "hw1.tab.c"
    break;

  case 29:
#line 217 "hw1.y"
                                                 {
        if ((yyvsp[-1].node)) {
            node_t* last = (yyvsp[-1].node);
            while (last->next) last = last->next;
            last->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1785 "hw1.tab.c"
    break;

  case 30:
#line 230 "hw1.y"
                                 {
        // Set type for all variables in the list
        node_t* var = (yyvsp[-1].node);
        while (var) {
            var->data_type = (yyvsp[-2].type);
            var = var->next;
        }
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1799 "hw1.tab.c"
    break;

  case 31:
#line 242 "hw1.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1807 "hw1.tab.c"
    break;

  case 32:
#line 245 "hw1.y"
                                        {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1818 "hw1.tab.c"
    break;

  case 33:
#line 254 "hw1.y"
       {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1828 "hw1.tab.c"
    break;

  case 34:
#line 259 "hw1.y"
                           {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->right = (yyvsp[0].node);  // initialization expression
        free((yyvsp[-2].str));
    }
#line 1839 "hw1.tab.c"
    break;

  case 35:
#line 268 "hw1.y"
                {
        (yyval.node) = NULL;
    }
#line 1847 "hw1.tab.c"
    break;

  case 36:
#line 271 "hw1.y"
                           {
        if ((yyvsp[-1].node)) {
            node_t* last = (yyvsp[-1].node);
            while (last->next) last = last->next;
            last->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        } else {
            (yyval.node) = (yyvsp[0].node);
        }
    }
#line 1862 "hw1.tab.c"
    break;

  case 37:
#line 284 "hw1.y"
                               {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1870 "hw1.tab.c"
    break;

  case 38:
#line 287 "hw1.y"
                         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1878 "hw1.tab.c"
    break;

  case 39:
#line 293 "hw1.y"
                         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1886 "hw1.tab.c"
    break;

  case 40:
#line 296 "hw1.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1894 "hw1.tab.c"
    break;

  case 41:
#line 299 "hw1.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1902 "hw1.tab.c"
    break;

  case 42:
#line 302 "hw1.y"
           {
        (yyval.node) = make_node(NODE_PASS, NULL);
    }
#line 1910 "hw1.tab.c"
    break;

  case 43:
#line 308 "hw1.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1918 "hw1.tab.c"
    break;

  case 44:
#line 311 "hw1.y"
                      {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1926 "hw1.tab.c"
    break;

  case 45:
#line 314 "hw1.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1934 "hw1.tab.c"
    break;

  case 46:
#line 320 "hw1.y"
                         {
        (yyval.node) = make_node(NODE_ASSIGN, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-2].str));
        (yyval.node)->left->name = strdup((yyvsp[-2].str));
        (yyval.node)->right = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1946 "hw1.tab.c"
    break;

  case 47:
#line 327 "hw1.y"
                                      {
        (yyval.node) = make_node(NODE_ASSIGN, NULL);
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1956 "hw1.tab.c"
    break;

  case 48:
#line 335 "hw1.y"
           {
        (yyval.node) = make_node(NODE_RETURN, NULL);
    }
#line 1964 "hw1.tab.c"
    break;

  case 49:
#line 338 "hw1.y"
                        {
        (yyval.node) = make_node(NODE_RETURN, NULL);
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1973 "hw1.tab.c"
    break;

  case 50:
#line 345 "hw1.y"
                              {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-2].node);
        (yyval.node)->if_body = (yyvsp[0].node);
    }
#line 1983 "hw1.tab.c"
    break;

  case 51:
#line 350 "hw1.y"
                                                     {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-3].node);
        (yyval.node)->if_body = (yyvsp[-1].node);
    }
#line 1993 "hw1.tab.c"
    break;

  case 52:
#line 355 "hw1.y"
                                                 {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-5].node);
        (yyval.node)->if_body = (yyvsp[-3].node);
        (yyval.node)->else_body = (yyvsp[0].node);
    }
#line 2004 "hw1.tab.c"
    break;

  case 53:
#line 361 "hw1.y"
                                                                                           {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-7].node);
        (yyval.node)->if_body = (yyvsp[-5].node);
        (yyval.node)->else_body = (yyvsp[-1].node);
    }
#line 2015 "hw1.tab.c"
    break;

  case 54:
#line 370 "hw1.y"
                                 {
        (yyval.node) = make_node(NODE_WHILE, NULL);
        (yyval.node)->condition = (yyvsp[-2].node);
        (yyval.node)->body = (yyvsp[0].node);
    }
#line 2025 "hw1.tab.c"
    break;

  case 55:
#line 375 "hw1.y"
                                                        {
        (yyval.node) = make_node(NODE_WHILE, NULL);
        (yyval.node)->condition = (yyvsp[-3].node);
        (yyval.node)->body = (yyvsp[-1].node);
    }
#line 2035 "hw1.tab.c"
    break;

  case 56:
#line 383 "hw1.y"
                     {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->args = NULL;
        free((yyvsp[-2].str));
    }
#line 2046 "hw1.tab.c"
    break;

  case 57:
#line 389 "hw1.y"
                                     {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-3].str));
        (yyval.node)->name = strdup((yyvsp[-3].str));
        (yyval.node)->args = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 2057 "hw1.tab.c"
    break;

  case 58:
#line 398 "hw1.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2065 "hw1.tab.c"
    break;

  case 59:
#line 401 "hw1.y"
                                     {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2076 "hw1.tab.c"
    break;

  case 60:
#line 410 "hw1.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2084 "hw1.tab.c"
    break;

  case 61:
#line 413 "hw1.y"
         {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 2094 "hw1.tab.c"
    break;

  case 62:
#line 418 "hw1.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2102 "hw1.tab.c"
    break;

  case 63:
#line 421 "hw1.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2110 "hw1.tab.c"
    break;

  case 64:
#line 424 "hw1.y"
                               {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2118 "hw1.tab.c"
    break;

  case 65:
#line 427 "hw1.y"
                                 {
        (yyval.node) = make_node(NODE_BINARY_OP, "+");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2128 "hw1.tab.c"
    break;

  case 66:
#line 432 "hw1.y"
                                  {
        (yyval.node) = make_node(NODE_BINARY_OP, "-");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2138 "hw1.tab.c"
    break;

  case 67:
#line 437 "hw1.y"
                                  {
        (yyval.node) = make_node(NODE_BINARY_OP, "*");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2148 "hw1.tab.c"
    break;

  case 68:
#line 442 "hw1.y"
                                   {
        (yyval.node) = make_node(NODE_BINARY_OP, "/");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2158 "hw1.tab.c"
    break;

  case 69:
#line 447 "hw1.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "**");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2168 "hw1.tab.c"
    break;

  case 70:
#line 452 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, ">");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2178 "hw1.tab.c"
    break;

  case 71:
#line 457 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "<");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2188 "hw1.tab.c"
    break;

  case 72:
#line 462 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, ">=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2198 "hw1.tab.c"
    break;

  case 73:
#line 467 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "<=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2208 "hw1.tab.c"
    break;

  case 74:
#line 472 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "==");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2218 "hw1.tab.c"
    break;

  case 75:
#line 477 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "!=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2228 "hw1.tab.c"
    break;

  case 76:
#line 482 "hw1.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "and");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2238 "hw1.tab.c"
    break;

  case 77:
#line 487 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "or");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2248 "hw1.tab.c"
    break;

  case 78:
#line 492 "hw1.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "is");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2258 "hw1.tab.c"
    break;

  case 79:
#line 497 "hw1.y"
                     {
        (yyval.node) = make_node(NODE_UNARY_OP, "not");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2267 "hw1.tab.c"
    break;

  case 80:
#line 501 "hw1.y"
                                    {
        (yyval.node) = make_node(NODE_UNARY_OP, "-");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2276 "hw1.tab.c"
    break;

  case 81:
#line 508 "hw1.y"
                                    {
        (yyval.node) = make_node(NODE_STRING_ACCESS, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-3].str));
        (yyval.node)->left->name = strdup((yyvsp[-3].str));
        (yyval.node)->right = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 2288 "hw1.tab.c"
    break;

  case 82:
#line 515 "hw1.y"
                                        {
        (yyval.node) = make_node(NODE_STRING_ACCESS, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-3].str));
        (yyval.node)->left->name = strdup((yyvsp[-3].str));
        (yyval.node)->right = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 2300 "hw1.tab.c"
    break;

  case 83:
#line 525 "hw1.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2310 "hw1.tab.c"
    break;

  case 84:
#line 530 "hw1.y"
                       {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = make_node(NODE_LITERAL, "0");
        (yyval.node)->left->data_type = TYPE_INT;
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2321 "hw1.tab.c"
    break;

  case 85:
#line 536 "hw1.y"
                       {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = (yyvsp[-1].node);
        (yyval.node)->right = NULL;
    }
#line 2331 "hw1.tab.c"
    break;

  case 86:
#line 541 "hw1.y"
            {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = make_node(NODE_LITERAL, "0");
        (yyval.node)->left->data_type = TYPE_INT;
        (yyval.node)->right = NULL;
    }
#line 2342 "hw1.tab.c"
    break;

  case 87:
#line 547 "hw1.y"
                                                   {
        node_t* slice = make_node(NODE_BINARY_OP, "slice");
        slice->left = (yyvsp[-4].node);
        slice->right = (yyvsp[-2].node);
        
        (yyval.node) = make_node(NODE_BINARY_OP, "slice_step");
        (yyval.node)->left = slice;
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2356 "hw1.tab.c"
    break;


#line 2360 "hw1.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 558 "hw1.y"


void yyerror(const char* s) {
    printf("❌ \033[1;31mSYNTAX ERROR\033[0m on line \033[1;33m%d\033[0m: \033[1;37m%s\033[0m\n", line_number, s);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    error_count++;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    
    FILE* input = fopen(argv[1], "r");
    if (!input) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    
    yyin = input;
    
    printf("🔥 Starting Compilation Process...\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    if (yyparse() == 0 && error_count == 0) {
        printf("✅ Syntax Analysis: PASSED\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        
        if (ast_root) {
            printf("🔍 Starting Semantic Analysis...\n");
            analyze_program(ast_root);
            
            if (error_count == 0) {
                printf("✅ Semantic Analysis: PASSED\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("🌳 ABSTRACT SYNTAX TREE (AST)\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                print_ast(ast_root, 0);
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                printf("🎉 \033[1;32mCOMPILATION SUCCESSFUL!\033[0m All phases completed without errors.\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            } else {
                printf("❌ Semantic Analysis: FAILED with %d errors.\n", error_count);
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
            }
            
            free_node(ast_root);
        } else {
            printf("❌ Error: Empty program - no AST generated\n");
            printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        }
    } else {
        printf("❌ Compilation FAILED - Syntax errors detected\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    }
    
    fclose(input);
    return error_count > 0 ? 1 : 0;
}
