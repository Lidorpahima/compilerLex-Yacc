/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

extern int yylex(void);
extern FILE* yyin;
extern int line_number;

void yyerror(const char* s);
node_t* ast_root = NULL;

#line 85 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INT_LIT = 4,                    /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 5,                  /* FLOAT_LIT  */
  YYSYMBOL_STRING_LIT = 6,                 /* STRING_LIT  */
  YYSYMBOL_TRUE_LIT = 7,                   /* TRUE_LIT  */
  YYSYMBOL_FALSE_LIT = 8,                  /* FALSE_LIT  */
  YYSYMBOL_DEF = 9,                        /* DEF  */
  YYSYMBOL_CALL = 10,                      /* CALL  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELIF = 12,                      /* ELIF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_PASS = 16,                      /* PASS  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_IS = 20,                        /* IS  */
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_FLOAT = 22,                     /* FLOAT  */
  YYSYMBOL_BOOL = 23,                      /* BOOL  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 32,                     /* ARROW  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_TIMES = 35,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 36,                    /* DIVIDE  */
  YYSYMBOL_POW = 37,                       /* POW  */
  YYSYMBOL_LPAREN = 38,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 39,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 41,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 42,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 43,                  /* RBRACKET  */
  YYSYMBOL_COLON = 44,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 45,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_UMINUS = 47,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_function_list = 50,             /* function_list  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_parameters = 52,                /* parameters  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_parameter_group = 54,           /* parameter_group  */
  YYSYMBOL_param_names = 55,               /* param_names  */
  YYSYMBOL_param = 56,                     /* param  */
  YYSYMBOL_type = 57,                      /* type  */
  YYSYMBOL_literal = 58,                   /* literal  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_variable_declarations = 60,     /* variable_declarations  */
  YYSYMBOL_variable_declaration = 61,      /* variable_declaration  */
  YYSYMBOL_variable_list = 62,             /* variable_list  */
  YYSYMBOL_variable_spec = 63,             /* variable_spec  */
  YYSYMBOL_statements = 64,                /* statements  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_simple_statement = 66,          /* simple_statement  */
  YYSYMBOL_compound_statement = 67,        /* compound_statement  */
  YYSYMBOL_assignment_statement = 68,      /* assignment_statement  */
  YYSYMBOL_return_statement = 69,          /* return_statement  */
  YYSYMBOL_if_statement = 70,              /* if_statement  */
  YYSYMBOL_while_statement = 71,           /* while_statement  */
  YYSYMBOL_function_call = 72,             /* function_call  */
  YYSYMBOL_argument_list = 73,             /* argument_list  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_string_access = 75,             /* string_access  */
  YYSYMBOL_string_slice = 76               /* string_slice  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      45,    46,    47
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
     345,   350,   355,   361,   370,   375,   383,   389,   395,   401,
     410,   413,   422,   425,   430,   433,   436,   439,   444,   449,
     454,   459,   464,   469,   474,   479,   484,   489,   494,   499,
     504,   509,   513,   520,   527,   537,   542,   548,   553,   559
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INT_LIT",
  "FLOAT_LIT", "STRING_LIT", "TRUE_LIT", "FALSE_LIT", "DEF", "CALL", "IF",
  "ELIF", "ELSE", "WHILE", "RETURN", "PASS", "AND", "OR", "NOT", "IS",
  "INT", "FLOAT", "BOOL", "STRING", "GE", "LE", "EQ", "NE", "GT", "LT",
  "ASSIGN", "ARROW", "PLUS", "MINUS", "TIMES", "DIVIDE", "POW", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COLON",
  "SEMICOLON", "COMMA", "UMINUS", "$accept", "program", "function_list",
  "function", "parameters", "parameter_list", "parameter_group",
  "param_names", "param", "type", "literal", "block",
  "variable_declarations", "variable_declaration", "variable_list",
  "variable_spec", "statements", "statement", "simple_statement",
  "compound_statement", "assignment_statement", "return_statement",
  "if_statement", "while_statement", "function_call", "argument_list",
  "expression", "string_access", "string_slice", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,     4,    21,    -5,   -46,   -16,   -46,   -46,    15,   -46,
     -46,   -46,   -46,   -15,     7,   -46,    52,   -24,    15,    17,
      47,   -46,    15,     2,   -46,    82,    52,    18,    16,    64,
     144,   -46,   -46,   -46,    65,   -46,   -46,   -46,    77,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     2,   144,   119,    25,
      57,   -29,   144,   144,   144,   -46,   -46,   266,   -46,    15,
     -46,   144,   -46,    69,   266,   -46,   -12,   266,   144,   159,
      72,   136,   305,   -46,   243,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   127,
     -46,     0,   266,   -46,   -46,   144,   266,   -46,   144,   -46,
     -46,    46,   -46,   305,   287,    70,    70,    70,   323,   323,
      70,    70,    63,    63,    95,    95,    95,   104,    67,   -46,
     144,   144,   -46,   -46,   -46,    91,   -46,   -46,   -46,   266,
     180,   -46,   144,   -46,   127,   201,   222,   -46,   144,   266,
     -46,     2,     2,   266,   124,   100,   -46,   111,   115,   147,
     -46,   121,   118,   -46,    50,   120,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     0,     1,     4,     9,    18,
      19,    20,    21,     0,    10,    11,     0,     0,     0,    16,
      13,    14,     0,     0,    12,     0,     0,     0,     0,     0,
      48,    42,    28,     5,     0,    39,    41,    40,     0,    22,
      23,    24,    25,    26,    17,    15,     0,     0,     0,     0,
       0,    63,     0,     0,     0,    62,    64,    49,    65,    35,
       7,     0,     6,     0,    46,    56,     0,    60,    88,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    47,     8,    57,     0,    86,    83,    87,    84,
      58,     0,    66,    78,    79,    80,    74,    75,    76,    77,
      72,    73,    67,    68,    69,    70,    71,    33,     0,    31,
       0,     0,    27,    45,    36,     0,    38,    43,    44,    61,
      85,    59,     0,    30,     0,     0,     0,    37,     0,    34,
      32,     0,     0,    89,    50,     0,    54,     0,     0,    51,
      55,     0,     0,    52,     0,     0,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -46,   -46,   -46,   161,   -46,   -46,   148,   -46,   141,    -3,
     143,   -40,   -46,   -46,   -46,    35,   -46,   -46,   -45,   -46,
     -46,   -46,   -46,   -46,   -23,   101,    -4,   -21,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    14,    15,    20,    21,    16,
      55,    33,    59,    90,   118,   119,    91,   124,    34,   126,
      35,    36,   127,   128,    56,    66,    67,    58,    70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    63,    38,    28,     1,    28,    62,     5,    22,    48,
      29,   120,    29,    49,   121,    30,    31,    30,    31,    27,
      23,     6,     8,    37,    17,    38,    57,    94,    51,    39,
      40,    41,    42,    43,    95,    29,     9,    10,    11,    12,
      32,   122,    32,    64,    52,    69,   125,    47,    72,    73,
      74,   123,    18,    28,    48,    19,    89,    92,    49,    53,
      29,    25,    46,    54,    96,    30,    31,    50,    37,    68,
      38,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   131,    39,    40,    41,    42,
      43,   129,    95,    26,   130,    71,   145,   147,    86,    87,
      88,   144,   146,    84,    85,    86,    87,    88,    61,   155,
      60,   153,   133,   134,    93,    99,   135,   136,    37,    37,
      38,    38,    51,    39,    40,    41,    42,    43,   139,    29,
     117,    37,    88,    38,   143,   132,   137,   148,    52,    51,
      39,    40,    41,    42,    43,   149,    29,    51,    39,    40,
      41,    42,    43,    53,    29,    52,   150,    54,    65,   151,
     152,    32,   154,    52,     7,   156,    24,    45,    44,   140,
      53,     0,   101,     0,    54,   100,    75,    76,    53,    77,
       0,     0,    54,     0,    78,    79,    80,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    75,    76,     0,
      77,     0,    97,    98,     0,    78,    79,    80,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    88,    75,    76,
       0,    77,     0,     0,   138,     0,    78,    79,    80,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    88,    75,
      76,     0,    77,     0,     0,   141,     0,    78,    79,    80,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    88,
      75,    76,     0,    77,     0,     0,   142,     0,    78,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      88,     0,   102,    75,    76,     0,    77,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,     0,     0,    84,
      85,    86,    87,    88,    75,     0,     0,    77,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    88,    77,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,     0,     0,    84,    85,
      86,    87,    88,    77,     0,     0,     0,     0,    78,    79,
       0,     0,    82,    83,     0,     0,    84,    85,    86,    87,
      88
};

static const yytype_int16 yycheck[] =
{
      23,    46,    23,     3,     9,     3,    46,     3,    32,    38,
      10,    11,    10,    42,    14,    15,    16,    15,    16,    22,
      44,     0,    38,    46,    39,    46,    30,    39,     3,     4,
       5,     6,     7,     8,    46,    10,    21,    22,    23,    24,
      40,    41,    40,    47,    19,    49,    91,    31,    52,    53,
      54,    91,    45,     3,    38,     3,    59,    61,    42,    34,
      10,    44,    44,    38,    68,    15,    16,     3,    91,    44,
      91,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    39,     4,     5,     6,     7,
       8,    95,    46,    46,    98,    38,   141,   142,    35,    36,
      37,   141,   142,    33,    34,    35,    36,    37,    31,   154,
      45,   151,    45,    46,    45,    43,   120,   121,   141,   142,
     141,   142,     3,     4,     5,     6,     7,     8,   132,    10,
       3,   154,    37,   154,   138,    31,    45,    13,    19,     3,
       4,     5,     6,     7,     8,    45,    10,     3,     4,     5,
       6,     7,     8,    34,    10,    19,    45,    38,    39,    44,
      13,    40,    44,    19,     3,    45,    18,    26,    25,   134,
      34,    -1,    71,    -1,    38,    39,    17,    18,    34,    20,
      -1,    -1,    38,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    33,    34,    35,    36,    37,    17,    18,    -1,
      20,    -1,    43,    44,    -1,    25,    26,    27,    28,    29,
      30,    -1,    -1,    33,    34,    35,    36,    37,    17,    18,
      -1,    20,    -1,    -1,    44,    -1,    25,    26,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    17,
      18,    -1,    20,    -1,    -1,    44,    -1,    25,    26,    27,
      28,    29,    30,    -1,    -1,    33,    34,    35,    36,    37,
      17,    18,    -1,    20,    -1,    -1,    44,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    -1,    39,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    -1,    -1,    33,
      34,    35,    36,    37,    17,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    34,
      35,    36,    37,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    49,    50,    51,     3,     0,    51,    38,    21,
      22,    23,    24,    52,    53,    54,    57,    39,    45,     3,
      55,    56,    32,    44,    54,    44,    46,    57,     3,    10,
      15,    16,    40,    59,    66,    68,    69,    72,    75,     4,
       5,     6,     7,     8,    58,    56,    44,    31,    38,    42,
       3,     3,    19,    34,    38,    58,    72,    74,    75,    60,
      45,    31,    59,    66,    74,    39,    73,    74,    44,    74,
      76,    38,    74,    74,    74,    17,    18,    20,    25,    26,
      27,    28,    29,    30,    33,    34,    35,    36,    37,    57,
      61,    64,    74,    45,    39,    46,    74,    43,    44,    43,
      39,    73,    39,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,     3,    62,    63,
      11,    14,    41,    59,    65,    66,    67,    70,    71,    74,
      74,    39,    31,    45,    46,    74,    74,    45,    44,    74,
      63,    44,    44,    74,    59,    66,    59,    66,    13,    45,
      45,    44,    13,    59,    44,    66,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    59,    60,    60,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     7,     9,     8,    10,     0,
       1,     1,     3,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     2,
       3,     1,     3,     1,     3,     0,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     2,
       4,     5,     7,     9,     4,     5,     3,     4,     4,     5,
       1,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     4,     3,     2,     2,     1,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: function_list  */
#line 56 "parser.y"
                  {
        ast_root = (yyvsp[0].node);
        (yyval.node) = (yyvsp[0].node);
    }
#line 1299 "parser.tab.c"
    break;

  case 3: /* function_list: function  */
#line 63 "parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1307 "parser.tab.c"
    break;

  case 4: /* function_list: function_list function  */
#line 66 "parser.y"
                             {
        node_t* last = (yyvsp[-1].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1318 "parser.tab.c"
    break;

  case 5: /* function: DEF ID LPAREN parameters RPAREN COLON block  */
#line 75 "parser.y"
                                                {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-5].str));
        (yyval.node)->name = strdup((yyvsp[-5].str));
        (yyval.node)->data_type = TYPE_VOID;
        (yyval.node)->params = (yyvsp[-3].node);
        (yyval.node)->body = (yyvsp[0].node);
        free((yyvsp[-5].str));
    }
#line 1331 "parser.tab.c"
    break;

  case 6: /* function: DEF ID LPAREN parameters RPAREN ARROW type COLON block  */
#line 83 "parser.y"
                                                             {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-7].str));
        (yyval.node)->name = strdup((yyvsp[-7].str));
        (yyval.node)->data_type = (yyvsp[-2].type);
        (yyval.node)->params = (yyvsp[-5].node);
        (yyval.node)->body = (yyvsp[0].node);
        free((yyvsp[-7].str));
    }
#line 1344 "parser.tab.c"
    break;

  case 7: /* function: DEF ID LPAREN parameters RPAREN COLON simple_statement SEMICOLON  */
#line 91 "parser.y"
                                                                       {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-6].str));
        (yyval.node)->name = strdup((yyvsp[-6].str));
        (yyval.node)->data_type = TYPE_VOID;
        (yyval.node)->params = (yyvsp[-4].node);
        (yyval.node)->body = (yyvsp[-1].node);
        free((yyvsp[-6].str));
    }
#line 1357 "parser.tab.c"
    break;

  case 8: /* function: DEF ID LPAREN parameters RPAREN ARROW type COLON simple_statement SEMICOLON  */
#line 99 "parser.y"
                                                                                  {
        (yyval.node) = make_node(NODE_FUNCTION, (yyvsp[-8].str));
        (yyval.node)->name = strdup((yyvsp[-8].str));
        (yyval.node)->data_type = (yyvsp[-3].type);
        (yyval.node)->params = (yyvsp[-6].node);
        (yyval.node)->body = (yyvsp[-1].node);
        free((yyvsp[-8].str));
    }
#line 1370 "parser.tab.c"
    break;

  case 9: /* parameters: %empty  */
#line 110 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1378 "parser.tab.c"
    break;

  case 10: /* parameters: parameter_list  */
#line 113 "parser.y"
                     {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1386 "parser.tab.c"
    break;

  case 11: /* parameter_list: parameter_group  */
#line 119 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1394 "parser.tab.c"
    break;

  case 12: /* parameter_list: parameter_list SEMICOLON parameter_group  */
#line 122 "parser.y"
                                               {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1405 "parser.tab.c"
    break;

  case 13: /* parameter_group: type param_names  */
#line 131 "parser.y"
                     {
        // Set type for all parameters in this group
        node_t* param = (yyvsp[0].node);
        while (param) {
            param->data_type = (yyvsp[-1].type);
            param = param->next;
        }
        (yyval.node) = (yyvsp[0].node);
    }
#line 1419 "parser.tab.c"
    break;

  case 14: /* param_names: param  */
#line 143 "parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1427 "parser.tab.c"
    break;

  case 15: /* param_names: param_names COMMA param  */
#line 146 "parser.y"
                              {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1438 "parser.tab.c"
    break;

  case 16: /* param: ID  */
#line 155 "parser.y"
       {
        (yyval.node) = make_node(NODE_PARAM, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        (yyval.node)->has_default = false;
        free((yyvsp[0].str));
    }
#line 1449 "parser.tab.c"
    break;

  case 17: /* param: ID COLON literal  */
#line 161 "parser.y"
                       {
        (yyval.node) = make_node(NODE_PARAM, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->has_default = true;
        (yyval.node)->default_value = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1461 "parser.tab.c"
    break;

  case 18: /* type: INT  */
#line 171 "parser.y"
            { (yyval.type) = TYPE_INT; }
#line 1467 "parser.tab.c"
    break;

  case 19: /* type: FLOAT  */
#line 172 "parser.y"
            { (yyval.type) = TYPE_FLOAT; }
#line 1473 "parser.tab.c"
    break;

  case 20: /* type: BOOL  */
#line 173 "parser.y"
            { (yyval.type) = TYPE_BOOL; }
#line 1479 "parser.tab.c"
    break;

  case 21: /* type: STRING  */
#line 174 "parser.y"
             { (yyval.type) = TYPE_STRING; }
#line 1485 "parser.tab.c"
    break;

  case 22: /* literal: INT_LIT  */
#line 178 "parser.y"
            {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_INT;
        free((yyvsp[0].str));
    }
#line 1495 "parser.tab.c"
    break;

  case 23: /* literal: FLOAT_LIT  */
#line 183 "parser.y"
                {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_FLOAT;
        free((yyvsp[0].str));
    }
#line 1505 "parser.tab.c"
    break;

  case 24: /* literal: STRING_LIT  */
#line 188 "parser.y"
                 {
        (yyval.node) = make_node(NODE_LITERAL, (yyvsp[0].str));
        (yyval.node)->data_type = TYPE_STRING;
        free((yyvsp[0].str));
    }
#line 1515 "parser.tab.c"
    break;

  case 25: /* literal: TRUE_LIT  */
#line 193 "parser.y"
               {
        (yyval.node) = make_node(NODE_LITERAL, "True");
        (yyval.node)->data_type = TYPE_BOOL;
        free((yyvsp[0].str));
    }
#line 1525 "parser.tab.c"
    break;

  case 26: /* literal: FALSE_LIT  */
#line 198 "parser.y"
                {
        (yyval.node) = make_node(NODE_LITERAL, "False");
        (yyval.node)->data_type = TYPE_BOOL;
        free((yyvsp[0].str));
    }
#line 1535 "parser.tab.c"
    break;

  case 27: /* block: LBRACE variable_declarations statements RBRACE  */
#line 206 "parser.y"
                                                   {
        (yyval.node) = make_node(NODE_BLOCK, NULL);
        (yyval.node)->left = (yyvsp[-2].node);  // declarations
        (yyval.node)->body = (yyvsp[-1].node);  // statements
    }
#line 1545 "parser.tab.c"
    break;

  case 28: /* variable_declarations: %empty  */
#line 214 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1553 "parser.tab.c"
    break;

  case 29: /* variable_declarations: variable_declarations variable_declaration  */
#line 217 "parser.y"
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
#line 1568 "parser.tab.c"
    break;

  case 30: /* variable_declaration: type variable_list SEMICOLON  */
#line 230 "parser.y"
                                 {
        // Set type for all variables in the list
        node_t* var = (yyvsp[-1].node);
        while (var) {
            var->data_type = (yyvsp[-2].type);
            var = var->next;
        }
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1582 "parser.tab.c"
    break;

  case 31: /* variable_list: variable_spec  */
#line 242 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1590 "parser.tab.c"
    break;

  case 32: /* variable_list: variable_list COMMA variable_spec  */
#line 245 "parser.y"
                                        {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1601 "parser.tab.c"
    break;

  case 33: /* variable_spec: ID  */
#line 254 "parser.y"
       {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1611 "parser.tab.c"
    break;

  case 34: /* variable_spec: ID ASSIGN expression  */
#line 259 "parser.y"
                           {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->right = (yyvsp[0].node);  // initialization expression
        free((yyvsp[-2].str));
    }
#line 1622 "parser.tab.c"
    break;

  case 35: /* statements: %empty  */
#line 268 "parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1630 "parser.tab.c"
    break;

  case 36: /* statements: statements statement  */
#line 271 "parser.y"
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
#line 1645 "parser.tab.c"
    break;

  case 37: /* statement: simple_statement SEMICOLON  */
#line 284 "parser.y"
                               {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1653 "parser.tab.c"
    break;

  case 38: /* statement: compound_statement  */
#line 287 "parser.y"
                         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1661 "parser.tab.c"
    break;

  case 39: /* simple_statement: assignment_statement  */
#line 293 "parser.y"
                         {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1669 "parser.tab.c"
    break;

  case 40: /* simple_statement: function_call  */
#line 296 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1677 "parser.tab.c"
    break;

  case 41: /* simple_statement: return_statement  */
#line 299 "parser.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1685 "parser.tab.c"
    break;

  case 42: /* simple_statement: PASS  */
#line 302 "parser.y"
           {
        (yyval.node) = make_node(NODE_PASS, NULL);
    }
#line 1693 "parser.tab.c"
    break;

  case 43: /* compound_statement: if_statement  */
#line 308 "parser.y"
                 {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1701 "parser.tab.c"
    break;

  case 44: /* compound_statement: while_statement  */
#line 311 "parser.y"
                      {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1709 "parser.tab.c"
    break;

  case 45: /* compound_statement: block  */
#line 314 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1717 "parser.tab.c"
    break;

  case 46: /* assignment_statement: ID ASSIGN expression  */
#line 320 "parser.y"
                         {
        (yyval.node) = make_node(NODE_ASSIGN, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-2].str));
        (yyval.node)->left->name = strdup((yyvsp[-2].str));
        (yyval.node)->right = (yyvsp[0].node);
        free((yyvsp[-2].str));
    }
#line 1729 "parser.tab.c"
    break;

  case 47: /* assignment_statement: string_access ASSIGN expression  */
#line 327 "parser.y"
                                      {
        (yyval.node) = make_node(NODE_ASSIGN, NULL);
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1739 "parser.tab.c"
    break;

  case 48: /* return_statement: RETURN  */
#line 335 "parser.y"
           {
        (yyval.node) = make_node(NODE_RETURN, NULL);
    }
#line 1747 "parser.tab.c"
    break;

  case 49: /* return_statement: RETURN expression  */
#line 338 "parser.y"
                        {
        (yyval.node) = make_node(NODE_RETURN, NULL);
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1756 "parser.tab.c"
    break;

  case 50: /* if_statement: IF expression COLON block  */
#line 345 "parser.y"
                              {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-2].node);
        (yyval.node)->if_body = (yyvsp[0].node);
    }
#line 1766 "parser.tab.c"
    break;

  case 51: /* if_statement: IF expression COLON simple_statement SEMICOLON  */
#line 350 "parser.y"
                                                     {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-3].node);
        (yyval.node)->if_body = (yyvsp[-1].node);
    }
#line 1776 "parser.tab.c"
    break;

  case 52: /* if_statement: IF expression COLON block ELSE COLON block  */
#line 355 "parser.y"
                                                 {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-5].node);
        (yyval.node)->if_body = (yyvsp[-3].node);
        (yyval.node)->else_body = (yyvsp[0].node);
    }
#line 1787 "parser.tab.c"
    break;

  case 53: /* if_statement: IF expression COLON simple_statement SEMICOLON ELSE COLON simple_statement SEMICOLON  */
#line 361 "parser.y"
                                                                                           {
        (yyval.node) = make_node(NODE_IF, NULL);
        (yyval.node)->condition = (yyvsp[-7].node);
        (yyval.node)->if_body = (yyvsp[-5].node);
        (yyval.node)->else_body = (yyvsp[-1].node);
    }
#line 1798 "parser.tab.c"
    break;

  case 54: /* while_statement: WHILE expression COLON block  */
#line 370 "parser.y"
                                 {
        (yyval.node) = make_node(NODE_WHILE, NULL);
        (yyval.node)->condition = (yyvsp[-2].node);
        (yyval.node)->body = (yyvsp[0].node);
    }
#line 1808 "parser.tab.c"
    break;

  case 55: /* while_statement: WHILE expression COLON simple_statement SEMICOLON  */
#line 375 "parser.y"
                                                        {
        (yyval.node) = make_node(NODE_WHILE, NULL);
        (yyval.node)->condition = (yyvsp[-3].node);
        (yyval.node)->body = (yyvsp[-1].node);
    }
#line 1818 "parser.tab.c"
    break;

  case 56: /* function_call: ID LPAREN RPAREN  */
#line 383 "parser.y"
                     {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->args = NULL;
        free((yyvsp[-2].str));
    }
#line 1829 "parser.tab.c"
    break;

  case 57: /* function_call: ID LPAREN argument_list RPAREN  */
#line 389 "parser.y"
                                     {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-3].str));
        (yyval.node)->name = strdup((yyvsp[-3].str));
        (yyval.node)->args = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 1840 "parser.tab.c"
    break;

  case 58: /* function_call: CALL ID LPAREN RPAREN  */
#line 395 "parser.y"
                            {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-2].str));
        (yyval.node)->name = strdup((yyvsp[-2].str));
        (yyval.node)->args = NULL;
        free((yyvsp[-2].str));
    }
#line 1851 "parser.tab.c"
    break;

  case 59: /* function_call: CALL ID LPAREN argument_list RPAREN  */
#line 401 "parser.y"
                                          {
        (yyval.node) = make_node(NODE_CALL, (yyvsp[-3].str));
        (yyval.node)->name = strdup((yyvsp[-3].str));
        (yyval.node)->args = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 1862 "parser.tab.c"
    break;

  case 60: /* argument_list: expression  */
#line 410 "parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1870 "parser.tab.c"
    break;

  case 61: /* argument_list: argument_list COMMA expression  */
#line 413 "parser.y"
                                     {
        node_t* last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1881 "parser.tab.c"
    break;

  case 62: /* expression: literal  */
#line 422 "parser.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1889 "parser.tab.c"
    break;

  case 63: /* expression: ID  */
#line 425 "parser.y"
         {
        (yyval.node) = make_node(NODE_VARIABLE, (yyvsp[0].str));
        (yyval.node)->name = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1899 "parser.tab.c"
    break;

  case 64: /* expression: function_call  */
#line 430 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1907 "parser.tab.c"
    break;

  case 65: /* expression: string_access  */
#line 433 "parser.y"
                    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1915 "parser.tab.c"
    break;

  case 66: /* expression: LPAREN expression RPAREN  */
#line 436 "parser.y"
                               {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1923 "parser.tab.c"
    break;

  case 67: /* expression: expression PLUS expression  */
#line 439 "parser.y"
                                 {
        (yyval.node) = make_node(NODE_BINARY_OP, "+");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1933 "parser.tab.c"
    break;

  case 68: /* expression: expression MINUS expression  */
#line 444 "parser.y"
                                  {
        (yyval.node) = make_node(NODE_BINARY_OP, "-");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1943 "parser.tab.c"
    break;

  case 69: /* expression: expression TIMES expression  */
#line 449 "parser.y"
                                  {
        (yyval.node) = make_node(NODE_BINARY_OP, "*");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1953 "parser.tab.c"
    break;

  case 70: /* expression: expression DIVIDE expression  */
#line 454 "parser.y"
                                   {
        (yyval.node) = make_node(NODE_BINARY_OP, "/");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1963 "parser.tab.c"
    break;

  case 71: /* expression: expression POW expression  */
#line 459 "parser.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "**");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1973 "parser.tab.c"
    break;

  case 72: /* expression: expression GT expression  */
#line 464 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, ">");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1983 "parser.tab.c"
    break;

  case 73: /* expression: expression LT expression  */
#line 469 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "<");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1993 "parser.tab.c"
    break;

  case 74: /* expression: expression GE expression  */
#line 474 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, ">=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2003 "parser.tab.c"
    break;

  case 75: /* expression: expression LE expression  */
#line 479 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "<=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2013 "parser.tab.c"
    break;

  case 76: /* expression: expression EQ expression  */
#line 484 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "==");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2023 "parser.tab.c"
    break;

  case 77: /* expression: expression NE expression  */
#line 489 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "!=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2033 "parser.tab.c"
    break;

  case 78: /* expression: expression AND expression  */
#line 494 "parser.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "and");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2043 "parser.tab.c"
    break;

  case 79: /* expression: expression OR expression  */
#line 499 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "or");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2053 "parser.tab.c"
    break;

  case 80: /* expression: expression IS expression  */
#line 504 "parser.y"
                               {
        (yyval.node) = make_node(NODE_BINARY_OP, "is");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2063 "parser.tab.c"
    break;

  case 81: /* expression: NOT expression  */
#line 509 "parser.y"
                     {
        (yyval.node) = make_node(NODE_UNARY_OP, "not");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2072 "parser.tab.c"
    break;

  case 82: /* expression: MINUS expression  */
#line 513 "parser.y"
                                    {
        (yyval.node) = make_node(NODE_UNARY_OP, "-");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2081 "parser.tab.c"
    break;

  case 83: /* string_access: ID LBRACKET expression RBRACKET  */
#line 520 "parser.y"
                                    {
        (yyval.node) = make_node(NODE_STRING_ACCESS, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-3].str));
        (yyval.node)->left->name = strdup((yyvsp[-3].str));
        (yyval.node)->right = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 2093 "parser.tab.c"
    break;

  case 84: /* string_access: ID LBRACKET string_slice RBRACKET  */
#line 527 "parser.y"
                                        {
        (yyval.node) = make_node(NODE_STRING_ACCESS, NULL);
        (yyval.node)->left = make_node(NODE_VARIABLE, (yyvsp[-3].str));
        (yyval.node)->left->name = strdup((yyvsp[-3].str));
        (yyval.node)->right = (yyvsp[-1].node);
        free((yyvsp[-3].str));
    }
#line 2105 "parser.tab.c"
    break;

  case 85: /* string_slice: expression COLON expression  */
#line 537 "parser.y"
                                {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2115 "parser.tab.c"
    break;

  case 86: /* string_slice: COLON expression  */
#line 542 "parser.y"
                       {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = make_node(NODE_LITERAL, "0");
        (yyval.node)->left->data_type = TYPE_INT;
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2126 "parser.tab.c"
    break;

  case 87: /* string_slice: expression COLON  */
#line 548 "parser.y"
                       {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = (yyvsp[-1].node);
        (yyval.node)->right = NULL;
    }
#line 2136 "parser.tab.c"
    break;

  case 88: /* string_slice: COLON  */
#line 553 "parser.y"
            {
        (yyval.node) = make_node(NODE_BINARY_OP, "slice");
        (yyval.node)->left = make_node(NODE_LITERAL, "0");
        (yyval.node)->left->data_type = TYPE_INT;
        (yyval.node)->right = NULL;
    }
#line 2147 "parser.tab.c"
    break;

  case 89: /* string_slice: expression COLON expression COLON expression  */
#line 559 "parser.y"
                                                   {
        node_t* slice = make_node(NODE_BINARY_OP, "slice");
        slice->left = (yyvsp[-4].node);
        slice->right = (yyvsp[-2].node);
        
        (yyval.node) = make_node(NODE_BINARY_OP, "slice_step");
        (yyval.node)->left = slice;
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 2161 "parser.tab.c"
    break;


#line 2165 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 570 "parser.y"


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
                
                // AC3 Code Generation
                printf("⚡ Starting AC3 Code Generation...\n");
                printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                generate_ac3_code(ast_root);
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
