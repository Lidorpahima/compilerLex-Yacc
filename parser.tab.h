/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 15 "parser.y"

    char* str;
    node_t* node;
    data_type_t type;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
