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
    // בדיקה אם זו שגיאת תחביר או סמנטיקה לפי תוכן ההודעה
    if (strstr(s, "Type mismatch") ||
        strstr(s, "cannot be") ||
        strstr(s, "must be") ||
        strstr(s, "operand") ||
        strstr(s, "operands")) {
        fprintf(stderr, "Semantic Error on line %d: %s\n", lineno, s);
    } else {
        fprintf(stderr, "Syntax Error on line %d: %s\n", lineno, s);
    }
}

#line 106 "parser.tab.c"

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
#line 37 "parser.y"

    Node* node;
    char* str;

#line 209 "parser.tab.c"

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
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

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
       0,    73,    73,    81,    88,    98,    98,   109,   109,   130,
     131,   135,   136,   140,   141,   142,   146,   167,   168,   169,
     173,   174,   175,   176,   180,   181,   182,   183,   187,   187,
     200,   201,   205,   259,   260,   264,   265,   269,   270,   274,
     275,   279,   280,   281,   282,   286,   290,   291,   292,   296,
     297,   301,   323,   324,   328,   329,   333,   334,   338,   342,
     396,   397,   401,   402,   406,   412,   413,   419,   420,   424,
     428,   429,   433,   448,   463,   473,   489,   505,   522,   539,
     556,   573,   574,   591,   608,   625,   642,   659,   669,   670,
     671,   680,   681,   685,   726,   735,   763,   764,   768,   769
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
  "$accept", "program", "function_list", "function", "$@1", "$@2",
  "func_body", "parameters", "param_list", "param", "literal", "type",
  "block", "$@3", "declarations", "declaration", "var_decl_list",
  "var_spec", "statements", "statement", "simple_statement",
  "pass_statement", "compound_statement", "suite", "assignment",
  "assignable_list", "assignable", "expression_list", "function_call_stmt",
  "function_call", "args", "arg_list", "if_statement", "elif_chain",
  "else_part", "while_statement", "return_statement", "expression",
  "string_access", "string_slice_content", "opt_expr", "opt_slice_step", YY_NULLPTR
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

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    57,    67,    26,  -121,    36,  -121,  -121,     4,    63,
    -121,  -121,  -121,  -121,    44,    28,  -121,    97,    89,    34,
       4,     4,    79,  -121,  -121,  -121,  -121,  -121,  -121,   -10,
    -121,  -121,    89,    61,    75,  -121,    37,    52,  -121,  -121,
    -121,  -121,    74,  -121,  -121,   -22,  -121,  -121,  -121,  -121,
    -121,  -121,    52,    52,    37,    52,    52,    52,  -121,  -121,
     215,  -121,  -121,  -121,    52,   109,    61,    76,    82,   215,
     127,    77,    85,   241,  -121,   107,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
     -10,    87,   215,    93,  -121,  -121,  -121,    52,  -121,    52,
    -121,   241,   228,    72,    72,    72,    72,    72,    72,    72,
      -3,    -3,   110,   110,   110,   142,  -121,    59,    52,   215,
     215,   111,   118,    73,  -121,    52,    52,  -121,  -121,  -121,
     120,  -121,  -121,  -121,   215,    52,  -121,    52,  -121,   142,
     149,   171,  -121,  -121,   215,  -121,    61,    61,  -121,   131,
    -121,  -121,  -121,     3,    52,   126,  -121,   193,    61,    61,
    -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,    11,    19,
      24,    25,    26,    27,     0,    12,    13,     0,     0,     0,
       0,     0,    17,    20,    21,    22,    23,    18,     7,     0,
      15,    14,     0,     0,     0,    16,    54,    71,    45,    28,
       8,     9,     0,    44,    41,     0,    52,    42,    58,    43,
      55,     5,    60,    96,    90,     0,     0,     0,    89,    92,
      70,    91,    30,    10,     0,     0,     0,     0,    61,    62,
      94,     0,     0,    74,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    51,    56,    54,    53,     6,    59,     0,    93,    96,
      88,    73,    72,    77,    78,    75,    76,    79,    80,    81,
      82,    83,    84,    85,    86,     0,    31,     0,     0,    63,
      97,    98,    35,     0,    33,     0,     0,    29,    48,    38,
       0,    40,    46,    47,    57,    96,    95,     0,    32,     0,
       0,     0,    39,    99,    36,    34,     0,     0,    49,     0,
      65,    69,    50,    67,     0,     0,    64,     0,     0,     0,
      68,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,   164,  -121,  -121,   102,  -121,  -121,    60,
      -6,   -24,   -30,  -121,  -121,  -121,  -121,    30,  -121,  -121,
     -29,  -121,  -121,  -120,  -121,  -121,   105,  -121,  -121,   -31,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,   -36,   -33,  -121,
     -81,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    66,    33,    40,    14,    15,    16,
      58,    17,   148,    62,    90,   116,   123,   124,   117,   129,
     149,    43,   131,   150,    44,    45,    46,    91,    47,    59,
      67,    68,   132,   153,   156,   133,    49,   120,    61,    71,
      72,   136
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    60,    48,    41,    42,    34,    64,     9,    10,    11,
      12,    13,    27,   154,   155,    65,    69,    70,   121,    73,
      74,    75,    10,    11,    12,    13,    35,   151,    92,    87,
      88,    89,    50,    50,     1,    48,    41,    42,   160,   161,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   143,    54,    23,    24,    25,    26,
       5,   119,    36,    20,    36,    21,   115,     6,   125,    55,
      28,   126,    37,    38,    37,    38,     8,    52,    29,    53,
      30,    31,   134,    56,    50,    19,    48,   128,   130,   140,
     141,    18,    57,    23,    24,    25,    26,    39,   127,    39,
      22,   144,    85,    86,    87,    88,    89,    32,   138,    63,
     139,    51,    93,    50,    50,    48,    48,    96,   157,    97,
      98,    99,    76,    77,   118,    50,    50,    48,    48,    78,
      79,    80,    81,    82,    83,    53,    84,    85,    86,    87,
      88,    89,    76,    77,    89,   122,   137,   135,   100,    78,
      79,    80,    81,    82,    83,   142,    84,    85,    86,    87,
      88,    89,   158,   -97,    76,    77,   152,     7,    95,   145,
      94,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      86,    87,    88,    89,     0,   146,    76,    77,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,     0,
      84,    85,    86,    87,    88,    89,     0,   147,    76,    77,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,     0,    84,    85,    86,    87,    88,    89,     0,   159,
      76,    77,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    76,    84,    85,    86,    87,    88,    89,
      78,    79,    80,    81,    82,    83,     0,    84,    85,    86,
      87,    88,    89,    78,    79,    80,    81,    82,    83,     0,
      84,    85,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      33,    37,    33,    33,    33,    29,    28,     3,    18,    19,
      20,    21,    18,    10,    11,    37,    52,    53,    99,    55,
      56,    57,    18,    19,    20,    21,    32,   147,    64,    32,
      33,    34,    65,    66,     8,    66,    66,    66,   158,   159,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   135,     3,     4,     5,     6,     7,
       3,    97,     3,    35,     3,    37,    90,     0,     9,    17,
      36,    12,    13,    14,    13,    14,    40,    40,    44,    42,
      20,    21,   118,    31,   117,    41,   117,   117,   117,   125,
     126,    28,    40,     4,     5,     6,     7,    38,    39,    38,
       3,   137,    30,    31,    32,    33,    34,    28,    35,    35,
      37,    36,     3,   146,   147,   146,   147,    41,   154,    37,
      43,    36,    15,    16,    37,   158,   159,   158,   159,    22,
      23,    24,    25,    26,    27,    42,    29,    30,    31,    32,
      33,    34,    15,    16,    34,     3,    28,    36,    41,    22,
      23,    24,    25,    26,    27,    35,    29,    30,    31,    32,
      33,    34,    36,    36,    15,    16,    35,     3,    66,   139,
      65,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    15,    16,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    15,    16,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    -1,    36,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    15,    29,    30,    31,    32,    33,    34,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    47,    48,    49,     3,     0,    49,    40,     3,
      18,    19,    20,    21,    53,    54,    55,    57,    28,    41,
      35,    37,     3,     4,     5,     6,     7,    56,    36,    44,
      55,    55,    28,    51,    57,    56,     3,    13,    14,    38,
      52,    58,    66,    67,    70,    71,    72,    74,    75,    82,
      84,    36,    40,    42,     3,    17,    31,    40,    56,    75,
      83,    84,    59,    35,    28,    37,    50,    76,    77,    83,
      83,    85,    86,    83,    83,    83,    15,    16,    22,    23,
      24,    25,    26,    27,    29,    30,    31,    32,    33,    34,
      60,    73,    83,     3,    72,    52,    41,    37,    43,    36,
      41,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    57,    61,    64,    37,    83,
      83,    86,     3,    62,    63,     9,    12,    39,    58,    65,
      66,    68,    78,    81,    83,    36,    87,    28,    35,    37,
      83,    83,    35,    86,    83,    63,    36,    36,    58,    66,
      69,    69,    35,    79,    10,    11,    80,    83,    36,    36,
      69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    50,    49,    51,    49,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    59,    58,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    67,    68,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    74,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    85,    85,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,    10,     0,     8,     1,
       2,     0,     1,     1,     3,     3,     4,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       0,     2,     3,     1,     3,     1,     3,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3,     1,     1,     1,     3,     1,     4,
       0,     1,     1,     3,     6,     0,     5,     0,     3,     4,
       2,     1,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     4,     1,     4,     0,     1,     0,     2
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
#line 73 "parser.y"
                  {
        ast_root = (yyvsp[0].node);
        (yyval.node) = (yyvsp[0].node);
        clear_all_symbols();
    }
#line 1534 "parser.tab.c"
    break;

  case 3:
#line 81 "parser.y"
             {
        if (!add_symbol_ex(&function_table, (yyvsp[0].node)->children[0]->children[0]->name, (yyvsp[0].node))) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_LIST", 1, (yyvsp[0].node));
    }
#line 1546 "parser.tab.c"
    break;

  case 4:
#line 88 "parser.y"
                           {
        if (!add_symbol_ex(&function_table, (yyvsp[0].node)->children[0]->children[0]->name, (yyvsp[0].node))) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_LIST", 2, (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1558 "parser.tab.c"
    break;

  case 5:
#line 98 "parser.y"
                                                     {
        push_scope();
        add_params_to_scope((yyvsp[-4].node));
    }
#line 1567 "parser.tab.c"
    break;

  case 6:
#line 101 "parser.y"
                {
        pop_scope();
        if (strcmp((yyvsp[-8].str), "__main__") == 0) {
            yyerror("__main__ must not have a return type");
            YYERROR;
        }
        (yyval.node) = make_node("FUNC_DEF_TYPED", 4, make_node("ID", 1, make_node((yyvsp[-8].str),0)), (yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node));
    }
#line 1580 "parser.tab.c"
    break;

  case 7:
#line 109 "parser.y"
                                          {
        push_scope();
        add_params_to_scope((yyvsp[-2].node));
    }
#line 1589 "parser.tab.c"
    break;

  case 8:
#line 112 "parser.y"
                {
        pop_scope();
        if (strcmp((yyvsp[-6].str), "__main__") == 0) {
            main_count++;
            if (main_count > 1) {
                yyerror("Multiple definitions of __main__ are not allowed");
                YYERROR;
            }
            if (strcmp((yyvsp[-4].node)->name, "PARAMS_EMPTY") != 0) {
                yyerror("__main__ must not have parameters");
                YYERROR;
            }
        }
        (yyval.node) = make_node("FUNC_DEF", 3, make_node("ID", 1, make_node((yyvsp[-6].str),0)), (yyvsp[-4].node), (yyvsp[0].node));
    }
#line 1609 "parser.tab.c"
    break;

  case 9:
#line 130 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1615 "parser.tab.c"
    break;

  case 10:
#line 131 "parser.y"
                               { (yyval.node) = make_node("SINGLE_STMT_BODY", 1, (yyvsp[-1].node)); }
#line 1621 "parser.tab.c"
    break;

  case 11:
#line 135 "parser.y"
    { (yyval.node) = make_node("PARAMS_EMPTY", 0); }
#line 1627 "parser.tab.c"
    break;

  case 12:
#line 136 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1633 "parser.tab.c"
    break;

  case 13:
#line 140 "parser.y"
          { (yyval.node) = make_node("PARAM_LIST", 1, (yyvsp[0].node)); }
#line 1639 "parser.tab.c"
    break;

  case 14:
#line 141 "parser.y"
                           { (yyval.node) = make_node("PARAM_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1645 "parser.tab.c"
    break;

  case 15:
#line 142 "parser.y"
                               { (yyval.node) = make_node("PARAM_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1651 "parser.tab.c"
    break;

  case 16:
#line 146 "parser.y"
                           {
        // בדיקת טיפוס ערך ברירת מחדל
        int type_ok = 0;
        if ((yyvsp[-3].node) && (yyvsp[0].node)) {
            // $1 = type node, $4 = literal node
            const char* param_type = (yyvsp[-3].node)->name;
            const char* lit_type = NULL;
            if (strcmp((yyvsp[0].node)->name, "LIT_INT") == 0) lit_type = "TYPE_INT";
            else if (strcmp((yyvsp[0].node)->name, "LIT_FLOAT") == 0) lit_type = "TYPE_FLOAT";
            else if (strcmp((yyvsp[0].node)->name, "LIT_STR") == 0) lit_type = "TYPE_STRING";
            else if (strcmp((yyvsp[0].node)->name, "LIT_BOOL") == 0) lit_type = "TYPE_BOOL";
            if (lit_type && strcmp(param_type, lit_type) == 0) type_ok = 1;
        }
        if (!type_ok) {
            char err[256];
            snprintf(err, sizeof(err), "Default value type does not match parameter type for '%s'", (yyvsp[-2].str));
            yyerror(err);
            YYERROR;
        }
        (yyval.node) = make_node("PARAM_DEFAULT", 3, (yyvsp[-3].node), make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node));
    }
#line 1677 "parser.tab.c"
    break;

  case 17:
#line 167 "parser.y"
            { (yyval.node) = make_node("PARAM", 2, (yyvsp[-1].node), make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1683 "parser.tab.c"
    break;

  case 18:
#line 168 "parser.y"
                      { (yyval.node) = make_node("PARAM_DEFAULT", 2, make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node)); }
#line 1689 "parser.tab.c"
    break;

  case 19:
#line 169 "parser.y"
       { (yyval.node) = make_node("PARAM", 1, make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1695 "parser.tab.c"
    break;

  case 20:
#line 173 "parser.y"
                  { (yyval.node) = make_node("LIT_INT", 1, make_node((yyvsp[0].str),0)); }
#line 1701 "parser.tab.c"
    break;

  case 21:
#line 174 "parser.y"
                  { (yyval.node) = make_node("LIT_FLOAT", 1, make_node((yyvsp[0].str),0)); }
#line 1707 "parser.tab.c"
    break;

  case 22:
#line 175 "parser.y"
                  { (yyval.node) = make_node("LIT_STR", 1, make_node((yyvsp[0].str),0)); }
#line 1713 "parser.tab.c"
    break;

  case 23:
#line 176 "parser.y"
                  { (yyval.node) = make_node("LIT_BOOL", 1, make_node((yyvsp[0].str),0)); }
#line 1719 "parser.tab.c"
    break;

  case 24:
#line 180 "parser.y"
        { (yyval.node) = make_node("TYPE_INT", 0); }
#line 1725 "parser.tab.c"
    break;

  case 25:
#line 181 "parser.y"
          { (yyval.node) = make_node("TYPE_FLOAT", 0); }
#line 1731 "parser.tab.c"
    break;

  case 26:
#line 182 "parser.y"
         { (yyval.node) = make_node("TYPE_BOOL", 0); }
#line 1737 "parser.tab.c"
    break;

  case 27:
#line 183 "parser.y"
           { (yyval.node) = make_node("TYPE_STRING", 0); }
#line 1743 "parser.tab.c"
    break;

  case 28:
#line 187 "parser.y"
           {
        push_scope();
    }
#line 1751 "parser.tab.c"
    break;

  case 29:
#line 189 "parser.y"
                                     {
        if (strcmp((yyvsp[-2].node)->name, "DECLS_EMPTY") == 0 && strcmp((yyvsp[-1].node)->name, "STMTS_EMPTY") == 0) {
            yyerror("Empty blocks {} are not allowed");
            YYERROR;
        }
        pop_scope();
        (yyval.node) = make_node("BLOCK", 2, (yyvsp[-2].node), (yyvsp[-1].node));
    }
#line 1764 "parser.tab.c"
    break;

  case 30:
#line 200 "parser.y"
    { (yyval.node) = make_node("DECLS_EMPTY", 0); }
#line 1770 "parser.tab.c"
    break;

  case 31:
#line 201 "parser.y"
                             { (yyval.node) = make_node("DECLS", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1776 "parser.tab.c"
    break;

  case 32:
#line 205 "parser.y"
                                 {
        Node* type_node = (yyvsp[-2].node);
        Node* list = (yyvsp[-1].node);
        int error_found = 0;
        void check_vars(Node* node) {
            if (!node) return;
            if (strcmp(node->name, "VAR") == 0 || strcmp(node->name, "VAR_INIT") == 0) {
                Node* id_node = node->children[0];
                if (id_node && strcmp(id_node->name, "ID") == 0) {
                    char* varname = id_node->children[0]->name;
                    
                    // בדיקת טיפוס אם יש אתחול
                    if (strcmp(node->name, "VAR_INIT") == 0 && node->child_count > 1) {
                        Node* expr = node->children[1];
                        const char* expr_type = get_expression_type(expr);
                        const char* var_type = type_node->name;
                        
                        if (!expr_type) {
                            char err[256];
                            snprintf(err, sizeof(err), "Cannot determine type of expression in initialization of '%s'", varname);
                            yyerror(err);
                            error_found = 1;
                        }
                        else if (strcmp(var_type, expr_type) != 0) {
                            // אם המשתנה הוא float והביטוי הוא int, זה בסדר
                            if (!(strcmp(var_type, "TYPE_FLOAT") == 0 && strcmp(expr_type, "TYPE_INT") == 0)) {
                                char err[256];
                                snprintf(err, sizeof(err), "Type mismatch in initialization of variable '%s'", varname);
                                yyerror(err);
                                error_found = 1;
                            }
                        }
                    }
                    
                    // משתמשים ב-var_decl כ־node במקום NULL
                    Node* var_decl = make_node("VAR_DECL", 2, type_node, node);
                    if (!add_symbol_ex(&var_scope_stack, varname, var_decl)) {
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
#line 1832 "parser.tab.c"
    break;

  case 33:
#line 259 "parser.y"
             { (yyval.node) = make_node("VAR_SPEC_LIST", 1, (yyvsp[0].node)); }
#line 1838 "parser.tab.c"
    break;

  case 34:
#line 260 "parser.y"
                                 { (yyval.node) = make_node("VAR_SPEC_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1844 "parser.tab.c"
    break;

  case 35:
#line 264 "parser.y"
       { (yyval.node) = make_node("VAR", 1, make_node("ID", 1, make_node((yyvsp[0].str),0))); }
#line 1850 "parser.tab.c"
    break;

  case 36:
#line 265 "parser.y"
                         { (yyval.node) = make_node("VAR_INIT", 2, make_node("ID", 1, make_node((yyvsp[-2].str),0)), (yyvsp[0].node)); }
#line 1856 "parser.tab.c"
    break;

  case 37:
#line 269 "parser.y"
    { (yyval.node) = make_node("STMTS_EMPTY", 0); }
#line 1862 "parser.tab.c"
    break;

  case 38:
#line 270 "parser.y"
                         { (yyval.node) = make_node("STMTS", 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1868 "parser.tab.c"
    break;

  case 39:
#line 274 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 1874 "parser.tab.c"
    break;

  case 40:
#line 275 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1880 "parser.tab.c"
    break;

  case 41:
#line 279 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1886 "parser.tab.c"
    break;

  case 42:
#line 280 "parser.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1892 "parser.tab.c"
    break;

  case 43:
#line 281 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1898 "parser.tab.c"
    break;

  case 44:
#line 282 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1904 "parser.tab.c"
    break;

  case 45:
#line 286 "parser.y"
         { (yyval.node) = make_node("PASS", 0); }
#line 1910 "parser.tab.c"
    break;

  case 46:
#line 290 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1916 "parser.tab.c"
    break;

  case 47:
#line 291 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1922 "parser.tab.c"
    break;

  case 48:
#line 292 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1928 "parser.tab.c"
    break;

  case 49:
#line 296 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1934 "parser.tab.c"
    break;

  case 50:
#line 297 "parser.y"
                               { (yyval.node) = make_node("SINGLE_STMT_SUITE", 1, (yyvsp[-1].node)); }
#line 1940 "parser.tab.c"
    break;

  case 51:
#line 301 "parser.y"
                                           {
        // בדיקת התאמת טיפוסים בין הצד השמאלי לצד הימני
        int error_code = check_assignment_types((yyvsp[-2].node), (yyvsp[0].node));
        if (error_code != 0) {
            if (error_code == -1) {
                yyerror("Too many values to unpack");
                YYERROR;
            } else if (error_code == -2) {
                yyerror("Not enough values to unpack");
                YYERROR;
            } else {
                char err[256];
                snprintf(err, sizeof(err), "Type mismatch in assignment at position %d", error_code);
                yyerror(err);
                YYERROR;
            }
        }
        (yyval.node) = make_node("ASSIGN", 2, (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1964 "parser.tab.c"
    break;

  case 52:
#line 323 "parser.y"
               { (yyval.node) = make_node("LHS_LIST", 1, (yyvsp[0].node)); }
#line 1970 "parser.tab.c"
    break;

  case 53:
#line 324 "parser.y"
                                     { (yyval.node) = make_node("LHS_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1976 "parser.tab.c"
    break;

  case 54:
#line 328 "parser.y"
       { (yyval.node) = make_node("ID", 1, make_node((yyvsp[0].str),0)); }
#line 1982 "parser.tab.c"
    break;

  case 55:
#line 329 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1988 "parser.tab.c"
    break;

  case 56:
#line 333 "parser.y"
               { (yyval.node) = make_node("RHS_LIST", 1, (yyvsp[0].node)); }
#line 1994 "parser.tab.c"
    break;

  case 57:
#line 334 "parser.y"
                                     { (yyval.node) = make_node("RHS_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2000 "parser.tab.c"
    break;

  case 58:
#line 338 "parser.y"
                  { (yyval.node) = make_node("CALL_STMT", 1, (yyvsp[0].node)); }
#line 2006 "parser.tab.c"
    break;

  case 59:
#line 342 "parser.y"
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
        int type_mismatch = check_arg_types(params, (yyvsp[-1].node));
        if (type_mismatch > 0) {
            char err[256];
            snprintf(err, sizeof(err), "Type mismatch in argument %d of function '%s'", type_mismatch, (yyvsp[-3].str));
            yyerror(err);
            YYERROR;
        }
        (yyval.node) = make_node("CALL", 2, make_node("ID", 1, make_node((yyvsp[-3].str),0)), (yyvsp[-1].node));
    }
#line 2062 "parser.tab.c"
    break;

  case 60:
#line 396 "parser.y"
    { (yyval.node) = make_node("ARGS_EMPTY", 0); }
#line 2068 "parser.tab.c"
    break;

  case 61:
#line 397 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2074 "parser.tab.c"
    break;

  case 62:
#line 401 "parser.y"
               { (yyval.node) = make_node("ARG_LIST", 1, (yyvsp[0].node)); }
#line 2080 "parser.tab.c"
    break;

  case 63:
#line 402 "parser.y"
                              { (yyval.node) = make_node("ARG_LIST", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2086 "parser.tab.c"
    break;

  case 64:
#line 406 "parser.y"
                                                   {
        (yyval.node) = make_node("IF_STMT", 4, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2094 "parser.tab.c"
    break;

  case 65:
#line 412 "parser.y"
    { (yyval.node) = make_node("ELIF_EMPTY", 0); }
#line 2100 "parser.tab.c"
    break;

  case 66:
#line 413 "parser.y"
                                           {
        (yyval.node) = make_node("ELIF_CHAIN", 2, (yyvsp[-4].node), make_node("ELIF", 2, (yyvsp[-2].node), (yyvsp[0].node)));
    }
#line 2108 "parser.tab.c"
    break;

  case 67:
#line 419 "parser.y"
    { (yyval.node) = make_node("ELSE_EMPTY", 0); }
#line 2114 "parser.tab.c"
    break;

  case 68:
#line 420 "parser.y"
                     { (yyval.node) = make_node("ELSE", 1, (yyvsp[0].node)); }
#line 2120 "parser.tab.c"
    break;

  case 69:
#line 424 "parser.y"
                                 { (yyval.node) = make_node("WHILE", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2126 "parser.tab.c"
    break;

  case 70:
#line 428 "parser.y"
                      { (yyval.node) = make_node("RETURN_VALUE", 1, (yyvsp[0].node)); }
#line 2132 "parser.tab.c"
    break;

  case 71:
#line 429 "parser.y"
           { (yyval.node) = make_node("RETURN_EMPTY", 0); }
#line 2138 "parser.tab.c"
    break;

  case 72:
#line 433 "parser.y"
                             { 
        // בדיקה שהאופרנדים הם מטיפוס בוליאני
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || strcmp(left_type, "TYPE_BOOL") != 0) {
            yyerror("Left operand of 'or' must be of type bool");
            YYERROR;
        }
        if (!right_type || strcmp(right_type, "TYPE_BOOL") != 0) {
            yyerror("Right operand of 'or' must be of type bool");
            YYERROR;
        }
        (yyval.node) = make_node("OR", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2158 "parser.tab.c"
    break;

  case 73:
#line 448 "parser.y"
                              { 
        // בדיקה שהאופרנדים הם מטיפוס בוליאני
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || strcmp(left_type, "TYPE_BOOL") != 0) {
            yyerror("Left operand of 'and' must be of type bool");
            YYERROR;
        }
        if (!right_type || strcmp(right_type, "TYPE_BOOL") != 0) {
            yyerror("Right operand of 'and' must be of type bool");
            YYERROR;
        }
        (yyval.node) = make_node("AND", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2178 "parser.tab.c"
    break;

  case 74:
#line 463 "parser.y"
                   { 
        // בדיקה שהאופרנד הוא מטיפוס בוליאני
        const char* type = get_expression_type((yyvsp[0].node));
        
        if (!type || strcmp(type, "TYPE_BOOL") != 0) {
            yyerror("Operand of 'not' must be of type bool");
            YYERROR;
        }
        (yyval.node) = make_node("NOT", 1, (yyvsp[0].node)); 
    }
#line 2193 "parser.tab.c"
    break;

  case 75:
#line 473 "parser.y"
                             { 
        // בדיקה שהאופרנדים מאותו טיפוס
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '=='");
            YYERROR;
        }
        
        if (strcmp(left_type, right_type) != 0) {
            yyerror("Both operands of '==' must be of the same type");
            YYERROR;
        }
        (yyval.node) = make_node("==", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2214 "parser.tab.c"
    break;

  case 76:
#line 489 "parser.y"
                             { 
        // בדיקה שהאופרנדים מאותו טיפוס
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '!='");
            YYERROR;
        }
        
        if (strcmp(left_type, right_type) != 0) {
            yyerror("Both operands of '!=' must be of the same type");
            YYERROR;
        }
        (yyval.node) = make_node("!=", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2235 "parser.tab.c"
    break;

  case 77:
#line 505 "parser.y"
                             { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '>='");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '>=' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node(">=", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2257 "parser.tab.c"
    break;

  case 78:
#line 522 "parser.y"
                             { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '<='");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '<=' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("<=", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2279 "parser.tab.c"
    break;

  case 79:
#line 539 "parser.y"
                             { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '>'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '>' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node(">", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2301 "parser.tab.c"
    break;

  case 80:
#line 556 "parser.y"
                             { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '<'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '<' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("<", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2323 "parser.tab.c"
    break;

  case 81:
#line 573 "parser.y"
                             { (yyval.node) = make_node("IS", 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2329 "parser.tab.c"
    break;

  case 82:
#line 574 "parser.y"
                               { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '+'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '+' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("+", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2351 "parser.tab.c"
    break;

  case 83:
#line 591 "parser.y"
                                { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '-'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '-' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("-", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2373 "parser.tab.c"
    break;

  case 84:
#line 608 "parser.y"
                                { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '*'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '*' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("*", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2395 "parser.tab.c"
    break;

  case 85:
#line 625 "parser.y"
                                 { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '/'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '/' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("/", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2417 "parser.tab.c"
    break;

  case 86:
#line 642 "parser.y"
                              { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type((yyvsp[-2].node));
        const char* right_type = get_expression_type((yyvsp[0].node));
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '**'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '**' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("**", 2, (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2439 "parser.tab.c"
    break;

  case 87:
#line 659 "parser.y"
                                  { 
        // בדיקה שהאופרנד הוא מטיפוס מספרי
        const char* type = get_expression_type((yyvsp[0].node));
        
        if (!type || (strcmp(type, "TYPE_INT") != 0 && strcmp(type, "TYPE_FLOAT") != 0)) {
            yyerror("Operand of unary '-' must be numeric (int or float)");
            YYERROR;
        }
        (yyval.node) = make_node("UMINUS", 1, (yyvsp[0].node)); 
    }
#line 2454 "parser.tab.c"
    break;

  case 88:
#line 669 "parser.y"
                             { (yyval.node) = (yyvsp[-1].node); }
#line 2460 "parser.tab.c"
    break;

  case 89:
#line 670 "parser.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2466 "parser.tab.c"
    break;

  case 90:
#line 671 "parser.y"
       {
      if (!var_defined((yyvsp[0].str))) {
        char err[256];
        snprintf(err, sizeof(err), "Variable '%s' used before declaration", (yyvsp[0].str));
        yyerror(err);
        YYERROR;
      }
      (yyval.node) = make_node("VAR_USE", 1, make_node("ID", 1, make_node((yyvsp[0].str),0)));
    }
#line 2480 "parser.tab.c"
    break;

  case 91:
#line 680 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2486 "parser.tab.c"
    break;

  case 92:
#line 681 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2492 "parser.tab.c"
    break;

  case 93:
#line 685 "parser.y"
                                              {
        // בדיקה שהמשתנה הוא מחרוזת
        if (!var_defined((yyvsp[-3].str))) {
            char err[256];
            snprintf(err, sizeof(err), "Variable '%s' used before declaration", (yyvsp[-3].str));
            yyerror(err);
            YYERROR;
        }
        
        // מצא את המשתנה וודא שהוא מטיפוס מחרוזת
        Symbol* s = find_symbol((yyvsp[-3].str));
        
        if (s && s->node) {
            const char* var_type = NULL;
            
            // בדיקה לפי סוג הסמל
            if (strcmp(s->node->name, "VAR_DECL") == 0) {
                var_type = s->node->children[0]->name;
            }
            else if (strcmp(s->node->name, "PARAM") == 0) {
                if (s->node->child_count >= 1)
                    var_type = s->node->children[0]->name; // TYPE_*
            }
            else if (strcmp(s->node->name, "PARAM_DEFAULT") == 0) {
                if (s->node->child_count >= 1)
                    var_type = s->node->children[0]->name; // TYPE_*
            }
            
            if (var_type == NULL || strcmp(var_type, "TYPE_STRING") != 0) {
                char err[256];
                snprintf(err, sizeof(err), "Operator [] can only be used with string variables, but '%s' is not a string", (yyvsp[-3].str));
                yyerror(err);
                YYERROR;
            }
        }
        
        (yyval.node) = make_node("STRING_ACCESS", 2, make_node("ID", 1, make_node((yyvsp[-3].str),0)), (yyvsp[-1].node));
    }
#line 2535 "parser.tab.c"
    break;

  case 94:
#line 726 "parser.y"
               { 
        // בדיקה שהאינדקס הוא מטיפוס int
        const char* expr_type = get_expression_type((yyvsp[0].node));
        if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
            yyerror("String index must be of type int");
            YYERROR;
        }
        (yyval.node) = make_node("INDEX", 1, (yyvsp[0].node)); 
    }
#line 2549 "parser.tab.c"
    break;

  case 95:
#line 735 "parser.y"
                                           {
        // בדיקת טיפוסים בslice
        if ((yyvsp[-3].node) && strcmp((yyvsp[-3].node)->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type((yyvsp[-3].node));
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice indices must be of type int");
                YYERROR;
            }
        }
        if ((yyvsp[-1].node) && strcmp((yyvsp[-1].node)->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type((yyvsp[-1].node));
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice indices must be of type int");
                YYERROR;
            }
        }
        if ((yyvsp[0].node) && strcmp((yyvsp[0].node)->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type((yyvsp[0].node));
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice step must be of type int");
                YYERROR;
            }
        }
        (yyval.node) = make_node("SLICE", 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2579 "parser.tab.c"
    break;

  case 96:
#line 763 "parser.y"
    { (yyval.node) = make_node("EMPTY", 0); }
#line 2585 "parser.tab.c"
    break;

  case 97:
#line 764 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2591 "parser.tab.c"
    break;

  case 98:
#line 768 "parser.y"
    { (yyval.node) = make_node("EMPTY", 0); }
#line 2597 "parser.tab.c"
    break;

  case 99:
#line 769 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2603 "parser.tab.c"
    break;


#line 2607 "parser.tab.c"

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
#line 772 "parser.y"


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
