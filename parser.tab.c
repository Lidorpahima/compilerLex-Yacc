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
#line 1 "parser.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineno = 1;
Node* ast_root = NULL;
extern int yylex(void);

int main_count = 0;

void clear_all_symbols() {
    if (function_table) {
        free_symbol_table(function_table);
        function_table = NULL;
    }
    while (var_scope_stack) {
        pop_scope();
    }
}

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error on line %d: %s\n", lineno, s);
}

#line 97 "parser.tab.c"

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
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INT_LITERAL = 259,
    FLOAT_LITERAL = 260,
    STR_LITERAL = 261,
    BOOL_LITERAL = 262,
    DEF = 263,
    IF = 264,
    ELIF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    PASS = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    INT = 273,
    FLOAT = 274,
    BOOL = 275,
    STRING = 276,
    GE = 277,
    LE = 278,
    EQ = 279,
    NE = 280,
    GT = 281,
    LT = 282,
    ASSIGN = 283,
    IS = 284,
    PLUS = 285,
    MINUS = 286,
    TIMES = 287,
    DIVIDE = 288,
    POW = 289,
    SEMICOLON = 290,
    COLON = 291,
    COMMA = 292,
    LBRACE = 293,
    RBRACE = 294,
    LPAREN = 295,
    RPAREN = 296,
    LBRACKET = 297,
    RBRACKET = 298,
    ARROW = 299,
    UMINUS = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    Node* node;
    char* str;

#line 200 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    72,    79,    89,    96,   113,   114,   118,
     119,   123,   124,   128,   129,   130,   131,   135,   136,   137,
     138,   142,   143,   144,   145,   149,   149,   162,   163,   167,
     194,   195,   199,   200,   204,   205,   209,   210,   214,   215,
     216,   217,   221,   225,   226,   227,   231,   232,   236,   242,
     243,   247,   248,   252,   253,   257,   261,   308,   309,   313,
     314,   318,   324,   325,   331,   332,   336,   340,   341,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   372,   373,
     377,   383,   384,   390,   391,   395,   396
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT_LITERAL", "FLOAT_LITERAL",
  "STR_LITERAL", "BOOL_LITERAL", "DEF", "IF", "ELIF", "ELSE", "WHILE",
  "RETURN", "PASS", "AND", "OR", "NOT", "INT", "FLOAT", "BOOL", "STRING",
  "GE", "LE", "EQ", "NE", "GT", "LT", "ASSIGN", "IS", "PLUS", "MINUS",
  "TIMES", "DIVIDE", "POW", "SEMICOLON", "COLON", "COMMA", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "ARROW", "UMINUS",
  "$accept", "program", "function_list", "function", "func_body",
  "parameters", "param_list", "param", "literal", "type", "block", "$@1",
  "declarations", "declaration", "var_decl_list", "var_spec", "statements",
  "statement", "simple_statement", "pass_statement", "compound_statement",
  "suite", "assignment", "assignable_list", "assignable",
  "expression_list", "function_call_stmt", "function_call", "args",
  "arg_list", "if_statement", "elif_chain", "else_part", "while_statement",
  "return_statement", "expression", "string_access",
  "string_slice_content", "opt_expr", "opt_slice_step", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,     9,    36,     3,   -84,    21,   -84,   -84,     6,    52,
     -84,   -84,   -84,   -84,    33,    48,   -84,    84,    26,    40,
       6,    72,   -84,   -84,   -84,   -84,   -84,    56,    85,   -84,
      26,    35,    61,   -84,   -84,   -84,   -84,    58,   -84,   -84,
      45,   -84,   -84,   -84,   -84,   -84,    71,   -84,    61,    61,
      35,    61,    61,    61,   -84,   -84,   217,   -84,   -84,   -84,
      61,   105,    56,    69,    74,   217,   129,    70,    76,   243,
     -84,   109,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    85,    77,   217,    78,
     -84,   -84,   -84,    61,   -84,    61,   -84,   243,   230,    65,
      65,    65,    65,    65,    65,    65,   -26,   -26,    87,    87,
      87,   119,   -84,     1,    61,   217,   217,    90,    95,    44,
     -84,    61,    61,   -84,   -84,   -84,   102,   -84,   -84,   -84,
     217,    61,   -84,    61,   -84,   119,   151,   173,   -84,   -84,
     217,   -84,    56,    56,   -84,   111,   -84,   -84,   -84,    46,
      61,   112,   -84,   195,    56,    56,   -84,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     9,    16,
      21,    22,    23,    24,     0,    10,    11,     0,     0,     0,
       0,    14,    17,    18,    19,    20,    15,     0,     0,    12,
       0,    51,    68,    42,    25,     6,     7,     0,    41,    38,
       0,    49,    39,    55,    40,    52,     0,    13,    57,    93,
      87,     0,     0,     0,    86,    89,    67,    88,    27,     8,
       0,     0,     0,     0,    58,    59,    91,     0,     0,    71,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    48,    53,    51,
      50,     5,    56,     0,    90,    93,    85,    70,    69,    74,
      75,    72,    73,    76,    77,    78,    79,    80,    81,    82,
      83,     0,    28,     0,     0,    60,    94,    95,    32,     0,
      30,     0,     0,    26,    45,    35,     0,    37,    43,    44,
      54,    93,    92,     0,    29,     0,     0,     0,    36,    96,
      33,    31,     0,     0,    46,     0,    62,    66,    47,    64,
       0,     0,    61,     0,     0,     0,    65,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   144,   106,   -84,   -84,   137,    -2,   -23,
     -24,   -84,   -84,   -84,   -84,    14,   -84,   -84,    -4,   -84,
     -84,   -83,   -84,   -84,   103,   -84,   -84,   -25,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -31,   -27,   -84,   -76,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    35,    14,    15,    16,    54,    17,
     144,    58,    86,   112,   119,   120,   113,   125,   145,    38,
     127,   146,    39,    40,    41,    87,    42,    55,    63,    64,
     128,   149,   152,   129,    44,   116,    57,    67,    68,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    43,    36,    31,    46,    83,    84,    85,     9,
     121,     1,     5,   122,    32,    33,    26,    65,    66,   117,
      69,    70,    71,    37,    10,    11,    12,    13,    47,    88,
      22,    23,    24,    25,    45,    45,     6,    43,    36,    34,
     123,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   139,   150,   151,    37,    31,
     147,     8,   115,   111,    50,    22,    23,    24,    25,    32,
      33,   156,   157,    60,    19,    48,    27,    49,    51,   134,
      18,   135,    61,   130,    28,    20,    45,    21,    43,   124,
     136,   137,    52,    59,    34,    81,    82,    83,    84,    85,
      30,    53,   140,    10,    11,    12,    13,    62,    89,   126,
      92,    93,    95,    94,   114,    45,    45,    43,    43,   153,
      49,    85,   118,   133,    72,    73,   131,    45,    45,    43,
      43,    74,    75,    76,    77,    78,    79,   138,    80,    81,
      82,    83,    84,    85,    72,    73,   148,     7,   154,   141,
      96,    74,    75,    76,    77,    78,    79,    29,    80,    81,
      82,    83,    84,    85,    90,   -94,    72,    73,    91,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,     0,
      80,    81,    82,    83,    84,    85,     0,   142,    72,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,     0,   143,
      72,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    85,
       0,   155,    72,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    72,    80,    81,    82,    83,
      84,    85,    74,    75,    76,    77,    78,    79,     0,    80,
      81,    82,    83,    84,    85,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      27,    32,    27,    27,     3,    28,    32,    33,    34,     3,
       9,     8,     3,    12,    13,    14,    18,    48,    49,    95,
      51,    52,    53,    27,    18,    19,    20,    21,    30,    60,
       4,     5,     6,     7,    61,    62,     0,    62,    62,    38,
      39,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   131,    10,    11,    62,     3,
     143,    40,    93,    86,     3,     4,     5,     6,     7,    13,
      14,   154,   155,    28,    41,    40,    36,    42,    17,    35,
      28,    37,    37,   114,    44,    37,   113,     3,   113,   113,
     121,   122,    31,    35,    38,    30,    31,    32,    33,    34,
      28,    40,   133,    18,    19,    20,    21,    36,     3,   113,
      41,    37,    36,    43,    37,   142,   143,   142,   143,   150,
      42,    34,     3,    28,    15,    16,    36,   154,   155,   154,
     155,    22,    23,    24,    25,    26,    27,    35,    29,    30,
      31,    32,    33,    34,    15,    16,    35,     3,    36,   135,
      41,    22,    23,    24,    25,    26,    27,    20,    29,    30,
      31,    32,    33,    34,    61,    36,    15,    16,    62,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    15,    16,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    15,    29,    30,    31,    32,
      33,    34,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    47,    48,    49,     3,     0,    49,    40,     3,
      18,    19,    20,    21,    51,    52,    53,    55,    28,    41,
      37,     3,     4,     5,     6,     7,    54,    36,    44,    53,
      28,     3,    13,    14,    38,    50,    56,    64,    65,    68,
      69,    70,    72,    73,    80,    82,    55,    54,    40,    42,
       3,    17,    31,    40,    54,    73,    81,    82,    57,    35,
      28,    37,    36,    74,    75,    81,    81,    83,    84,    81,
      81,    81,    15,    16,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    33,    34,    58,    71,    81,     3,
      70,    50,    41,    37,    43,    36,    41,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    55,    59,    62,    37,    81,    81,    84,     3,    60,
      61,     9,    12,    39,    56,    63,    64,    66,    76,    79,
      81,    36,    85,    28,    35,    37,    81,    81,    35,    84,
      81,    61,    36,    36,    56,    64,    67,    67,    35,    77,
      10,    11,    78,    81,    36,    36,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    54,    54,    54,
      54,    55,    55,    55,    55,    57,    56,    58,    58,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      64,    64,    65,    66,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    83,    84,    84,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     9,     7,     1,     2,     0,
       1,     1,     3,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     0,     2,     3,
       1,     3,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       3,     1,     1,     1,     3,     1,     4,     0,     1,     1,
       3,     6,     0,     5,     0,     3,     4,     2,     1,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       4,     1,     4,     0,     1,     0,     2
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
#line 64 "parser.y"
                  {
        ast_root = (yyvsp[0].node);
        (yyval.node) = (yyvsp[0].node);
        clear_all_symbols();
    }
#line 1520 "parser.tab.c"
    break;

  case 3:
#line 72 "parser.y"
             {
        if (!add_symbol_ex(&function_table, (yyvsp[0].node)->children[0]->children[0]->name, (yyvsp[0].node))) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_LIST", 1, (yyvsp[0].node));
    }
#line 1532 "parser.tab.c"
    break;

  case 4:
#line 79 "parser.y"
                           {
        if (!add_symbol_ex(&function_table, (yyvsp[0].node)->children[0]->children[0]->name, (yyvsp[0].node))) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_LIST", 2, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1544 "parser.tab.c"
    break;

  case 5:
#line 89 "parser.y"
                                                               {
        if (strcmp((yyvsp[-7].str), "__main__") == 0) {
            yyerror("__main__ must not have a return type");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_DEF_TYPED", 4, make_node("ID", 1, make_node((yyvsp[-7].str),0)), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1556 "parser.tab.c"
    break;

  case 6:
#line 96 "parser.y"
                                                    {
        if (strcmp((yyvsp[-5].str), "__main__") == 0) {
            main_count++;
            if (main_count > 1) {
                yyerror("Multiple definitions of __main__ are not allowed");
                YYERROR;
            }
            if (strcmp((yyvsp[-3].node)->name, "PARAMS_EMPTY") != 0) {
                yyerror("__main__ must not have parameters");
                YYERROR;
            }
        }
        (yyval.node) = make_node("FUNC_DEF", 3, make_node("ID", 1, make_node((yyvsp[-5].str),0)), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 1575 "parser.tab.c"
    break;

  case 7:
#line 113 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1581 "parser.tab.c"
    break;

  case 8:
#line 114 "parser.y"
                               { (yyval.node) = make_node("SINGLE_STMT_BODY", 1, (yyvsp[-1].node)); }
#line 1587 "parser.tab.c"
    break;

  case 9:
#line 118 "parser.y"
    { (yyval.node) = make_node("PARAMS_EMPTY", 0); }
#line 1593 "parser.tab.c"
    break;

  case 10:
#line 119 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1599 "parser.tab.c"
    break;

  case 11:
#line 123 "parser.y"
          { (yyval.node) = make_node("PARAM_LIST", 1, (yyvsp[0].node)); }
#line 1605 "parser.tab.c"
    break;

  case 12:
#line 124 "parser.y"
                           { (yyval.node) = make_node("PARAM_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1611 "parser.tab.c"
    break;

  case 13:
#line 128 "parser.y"
                           { (yyval.node) = make_node("PARAM_DEFAULT", 3, (yyvsp[-3].node), make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node)); }
#line 1617 "parser.tab.c"
    break;

  case 14:
#line 129 "parser.y"
            { (yyval.node) = make_node("PARAM", 2, (yyvsp[-1].node), make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1623 "parser.tab.c"
    break;

  case 15:
#line 130 "parser.y"
                      { (yyval.node) = make_node("PARAM_DEFAULT", 2, make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node)); }
#line 1629 "parser.tab.c"
    break;

  case 16:
#line 131 "parser.y"
       { (yyval.node) = make_node("PARAM", 1, make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1635 "parser.tab.c"
    break;

  case 17:
#line 135 "parser.y"
                  { (yyval.node) = make_node("LIT_INT", 1, make_node((yyvsp[0].str),0)); }
#line 1641 "parser.tab.c"
    break;

  case 18:
#line 136 "parser.y"
                  { (yyval.node) = make_node("LIT_FLOAT", 1, make_node((yyvsp[0].str),0)); }
#line 1647 "parser.tab.c"
    break;

  case 19:
#line 137 "parser.y"
                  { (yyval.node) = make_node("LIT_STR", 1, make_node((yyvsp[0].str),0)); }
#line 1653 "parser.tab.c"
    break;

  case 20:
#line 138 "parser.y"
                  { (yyval.node) = make_node("LIT_BOOL", 1, make_node((yyvsp[0].str),0)); }
#line 1659 "parser.tab.c"
    break;

  case 21:
#line 142 "parser.y"
        { (yyval.node) = make_node("TYPE_INT", 0); }
#line 1665 "parser.tab.c"
    break;

  case 22:
#line 143 "parser.y"
          { (yyval.node) = make_node("TYPE_FLOAT", 0); }
#line 1671 "parser.tab.c"
    break;

  case 23:
#line 144 "parser.y"
         { (yyval.node) = make_node("TYPE_BOOL", 0); }
#line 1677 "parser.tab.c"
    break;

  case 24:
#line 145 "parser.y"
           { (yyval.node) = make_node("TYPE_STRING", 0); }
#line 1683 "parser.tab.c"
    break;

  case 25:
#line 149 "parser.y"
           {
        push_scope();
    }
#line 1691 "parser.tab.c"
    break;

  case 26:
#line 151 "parser.y"
                                     {
        if (strcmp((yyvsp[-2].node)->name, "DECLS_EMPTY") == 0 && strcmp((yyvsp[-1].node)->name, "STMTS_EMPTY") == 0) {
            yyerror("Empty blocks {} are not allowed");
            YYERROR;
        }
        pop_scope();
        (yyval.node) = make_node("BLOCK", 2, (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1704 "parser.tab.c"
    break;

  case 27:
#line 162 "parser.y"
    { (yyval.node) = make_node("DECLS_EMPTY", 0); }
#line 1710 "parser.tab.c"
    break;

  case 28:
#line 163 "parser.y"
                             { (yyval.node) = make_node("DECLS", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1716 "parser.tab.c"
    break;

  case 29:
#line 167 "parser.y"
                                 {
        Node* list = (yyvsp[-1].node);
        int error_found = 0;
        void check_vars(Node* node) {
            if (!node) return;
            if (strcmp(node->name, "VAR") == 0 || strcmp(node->name, "VAR_INIT") == 0) {
                Node* id_node = node->children[0];
                if (id_node && strcmp(id_node->name, "ID") == 0) {
                    char* varname = id_node->children[0]->name;
                    if (!add_symbol(&var_scope_stack, varname)) {
                        yyerror("Duplicate variable name in scope");
                        error_found = 1;
                    }
                }
            } else if (strcmp(node->name, "VAR_SPEC_LIST") == 0) {
                for (int i = 0; i < node->child_count; i++) {
                    check_vars(node->children[i]);
                }
            }
        }
        check_vars(list);
        if (error_found) YYERROR;
        (yyval.node) = make_node("VAR_DECL", 2, (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1745 "parser.tab.c"
    break;

  case 30:
#line 194 "parser.y"
             { (yyval.node) = make_node("VAR_SPEC_LIST", 1, (yyvsp[0].node)); }
#line 1751 "parser.tab.c"
    break;

  case 31:
#line 195 "parser.y"
                                 { (yyval.node) = make_node("VAR_SPEC_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1757 "parser.tab.c"
    break;

  case 32:
#line 199 "parser.y"
       { (yyval.node) = make_node("VAR", 1, make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1763 "parser.tab.c"
    break;

  case 33:
#line 200 "parser.y"
                         { (yyval.node) = make_node("VAR_INIT", 2, make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node)); }
#line 1769 "parser.tab.c"
    break;

  case 34:
#line 204 "parser.y"
    { (yyval.node) = make_node("STMTS_EMPTY", 0); }
#line 1775 "parser.tab.c"
    break;

  case 35:
#line 205 "parser.y"
                         { (yyval.node) = make_node("STMTS", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1781 "parser.tab.c"
    break;

  case 36:
#line 209 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1787 "parser.tab.c"
    break;

  case 37:
#line 210 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1793 "parser.tab.c"
    break;

  case 38:
#line 214 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1799 "parser.tab.c"
    break;

  case 39:
#line 215 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1805 "parser.tab.c"
    break;

  case 40:
#line 216 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1811 "parser.tab.c"
    break;

  case 41:
#line 217 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1817 "parser.tab.c"
    break;

  case 42:
#line 221 "parser.y"
         { (yyval.node) = make_node("PASS", 0); }
#line 1823 "parser.tab.c"
    break;

  case 43:
#line 225 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1829 "parser.tab.c"
    break;

  case 44:
#line 226 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1835 "parser.tab.c"
    break;

  case 45:
#line 227 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1841 "parser.tab.c"
    break;

  case 46:
#line 231 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1847 "parser.tab.c"
    break;

  case 47:
#line 232 "parser.y"
                               { (yyval.node) = make_node("SINGLE_STMT_SUITE", 1, (yyvsp[-1].node)); }
#line 1853 "parser.tab.c"
    break;

  case 48:
#line 236 "parser.y"
                                           {
        (yyval.node) = make_node("ASSIGN", 2, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1861 "parser.tab.c"
    break;

  case 49:
#line 242 "parser.y"
               { (yyval.node) = make_node("LHS_LIST", 1, (yyvsp[0].node)); }
#line 1867 "parser.tab.c"
    break;

  case 50:
#line 243 "parser.y"
                                     { (yyval.node) = make_node("LHS_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1873 "parser.tab.c"
    break;

  case 51:
#line 247 "parser.y"
       { (yyval.node) = make_node("ID", 1, make_node((yyvsp[0].str),0)); }
#line 1879 "parser.tab.c"
    break;

  case 52:
#line 248 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1885 "parser.tab.c"
    break;

  case 53:
#line 252 "parser.y"
               { (yyval.node) = make_node("RHS_LIST", 1, (yyvsp[0].node)); }
#line 1891 "parser.tab.c"
    break;

  case 54:
#line 253 "parser.y"
                                     { (yyval.node) = make_node("RHS_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1897 "parser.tab.c"
    break;

  case 55:
#line 257 "parser.y"
                  { (yyval.node) = make_node("CALL_STMT", 1, (yyvsp[0].node)); }
#line 1903 "parser.tab.c"
    break;

  case 56:
#line 261 "parser.y"
                          {
        if (!func_defined((yyvsp[-3].str))) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called before declaration", (yyvsp[-3].str));
            yyerror(err);
            YYERROR;
        }
        Symbol* f = function_table ? function_table->head : NULL;
        Node* func_def = NULL;
        while (f) {
            if (strcmp(f->name, (yyvsp[-3].str)) == 0 && f->node) {
                func_def = f->node;
                break;
            }
            f = f->next;
        }
        if (!func_def) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' definition not found for argument check", (yyvsp[-3].str));
            yyerror(err);
            YYERROR;
        }
        Node* params = NULL;
        if (strcmp(func_def->name, "FUNC_DEF_TYPED") == 0)
            params = func_def->children[1];
        else if (strcmp(func_def->name, "FUNC_DEF") == 0)
            params = func_def->children[1];
        int total=0, required=0;
        count_params(params, &total, &required);
        int nargs = count_args((yyvsp[-1].node));
        if (nargs > total) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called with too many arguments (%d > %d)", (yyvsp[-3].str), nargs, total);
            yyerror(err);
            YYERROR;
        }
        if (nargs < required) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called with too few arguments (%d < %d)", (yyvsp[-3].str), nargs, required);
            yyerror(err);
            YYERROR;
        }
        (yyval.node) = make_node("CALL", 2, make_node("ID", 1, make_node((yyvsp[-3].str),0)), (yyvsp[-1].node));
    }
#line 1952 "parser.tab.c"
    break;

  case 57:
#line 308 "parser.y"
    { (yyval.node) = make_node("ARGS_EMPTY", 0); }
#line 1958 "parser.tab.c"
    break;

  case 58:
#line 309 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1964 "parser.tab.c"
    break;

  case 59:
#line 313 "parser.y"
               { (yyval.node) = make_node("ARG_LIST", 1, (yyvsp[0].node)); }
#line 1970 "parser.tab.c"
    break;

  case 60:
#line 314 "parser.y"
                              { (yyval.node) = make_node("ARG_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1976 "parser.tab.c"
    break;

  case 61:
#line 318 "parser.y"
                                                   {
        (yyval.node) = make_node("IF_STMT", 4, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1984 "parser.tab.c"
    break;

  case 62:
#line 324 "parser.y"
    { (yyval.node) = make_node("ELIF_EMPTY", 0); }
#line 1990 "parser.tab.c"
    break;

  case 63:
#line 325 "parser.y"
                                           {
        (yyval.node) = make_node("ELIF_CHAIN", 2, (yyvsp[-4].node), make_node("ELIF", 2, (yyvsp[-2].node), (yyvsp[0].node)));
    }
#line 1998 "parser.tab.c"
    break;

  case 64:
#line 331 "parser.y"
    { (yyval.node) = make_node("ELSE_EMPTY", 0); }
#line 2004 "parser.tab.c"
    break;

  case 65:
#line 332 "parser.y"
                     { (yyval.node) = make_node("ELSE", 1, (yyvsp[0].node)); }
#line 2010 "parser.tab.c"
    break;

  case 66:
#line 336 "parser.y"
                                 { (yyval.node) = make_node("WHILE", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2016 "parser.tab.c"
    break;

  case 67:
#line 340 "parser.y"
                      { (yyval.node) = make_node("RETURN_VALUE", 1, (yyvsp[0].node)); }
#line 2022 "parser.tab.c"
    break;

  case 68:
#line 341 "parser.y"
           { (yyval.node) = make_node("RETURN_EMPTY", 0); }
#line 2028 "parser.tab.c"
    break;

  case 69:
#line 345 "parser.y"
                             { (yyval.node) = make_node("OR", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2034 "parser.tab.c"
    break;

  case 70:
#line 346 "parser.y"
                              { (yyval.node) = make_node("AND", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2040 "parser.tab.c"
    break;

  case 71:
#line 347 "parser.y"
                   { (yyval.node) = make_node("NOT", 1, (yyvsp[0].node)); }
#line 2046 "parser.tab.c"
    break;

  case 72:
#line 348 "parser.y"
                             { (yyval.node) = make_node("==", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2052 "parser.tab.c"
    break;

  case 73:
#line 349 "parser.y"
                             { (yyval.node) = make_node("!=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2058 "parser.tab.c"
    break;

  case 74:
#line 350 "parser.y"
                             { (yyval.node) = make_node(">=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2064 "parser.tab.c"
    break;

  case 75:
#line 351 "parser.y"
                             { (yyval.node) = make_node("<=", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2070 "parser.tab.c"
    break;

  case 76:
#line 352 "parser.y"
                             { (yyval.node) = make_node(">", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2076 "parser.tab.c"
    break;

  case 77:
#line 353 "parser.y"
                             { (yyval.node) = make_node("<", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2082 "parser.tab.c"
    break;

  case 78:
#line 354 "parser.y"
                             { (yyval.node) = make_node("IS", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2088 "parser.tab.c"
    break;

  case 79:
#line 355 "parser.y"
                               { (yyval.node) = make_node("+", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2094 "parser.tab.c"
    break;

  case 80:
#line 356 "parser.y"
                                { (yyval.node) = make_node("-", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2100 "parser.tab.c"
    break;

  case 81:
#line 357 "parser.y"
                                { (yyval.node) = make_node("*", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2106 "parser.tab.c"
    break;

  case 82:
#line 358 "parser.y"
                                 { (yyval.node) = make_node("/", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2112 "parser.tab.c"
    break;

  case 83:
#line 359 "parser.y"
                              { (yyval.node) = make_node("**", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2118 "parser.tab.c"
    break;

  case 84:
#line 360 "parser.y"
                                  { (yyval.node) = make_node("UMINUS", 1, (yyvsp[0].node)); }
#line 2124 "parser.tab.c"
    break;

  case 85:
#line 361 "parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2130 "parser.tab.c"
    break;

  case 86:
#line 362 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2136 "parser.tab.c"
    break;

  case 87:
#line 363 "parser.y"
       {
      if (!var_defined((yyvsp[0].str))) {
        char err[256];
        snprintf(err, sizeof(err), "Variable '%s' used before declaration", (yyvsp[0].str));
        yyerror(err);
        YYERROR;
      }
      (yyval.node) = make_node("VAR_USE", 1, make_node("ID", 1, make_node((yyvsp[0].str),0)));
    }
#line 2150 "parser.tab.c"
    break;

  case 88:
#line 372 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2156 "parser.tab.c"
    break;

  case 89:
#line 373 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2162 "parser.tab.c"
    break;

  case 90:
#line 377 "parser.y"
                                              {
        (yyval.node) = make_node("STRING_ACCESS", 2, make_node("ID", 1, make_node((yyvsp[-3].str),0)), (yyvsp[-1].node));
    }
#line 2170 "parser.tab.c"
    break;

  case 91:
#line 383 "parser.y"
               { (yyval.node) = make_node("INDEX", 1, (yyvsp[0].node)); }
#line 2176 "parser.tab.c"
    break;

  case 92:
#line 384 "parser.y"
                                           {
        (yyval.node) = make_node("SLICE", 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2184 "parser.tab.c"
    break;

  case 93:
#line 390 "parser.y"
    { (yyval.node) = make_node("EMPTY", 0); }
#line 2190 "parser.tab.c"
    break;

  case 94:
#line 391 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2196 "parser.tab.c"
    break;

  case 95:
#line 395 "parser.y"
    { (yyval.node) = make_node("EMPTY", 0); }
#line 2202 "parser.tab.c"
    break;

  case 96:
#line 396 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2208 "parser.tab.c"
    break;


#line 2212 "parser.tab.c"

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
#line 399 "parser.y"


int main() {
    if (yyparse() == 0) {
        printf("Parsing successful!\n");
        if (ast_root == NULL) {
            fprintf(stderr, "Parsing OK, but AST root is NULL (empty input?).\n");
        } else {
            print_ast(ast_root, 0);
        }
    } else {
        fprintf(stderr, "Parsing failed.\n");
        return 1;
    }
    clear_all_symbols();
    return 0;
}
