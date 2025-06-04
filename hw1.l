%{
#include "ast.h"
#include "hw1.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_number;
%}

%option noyywrap

digit           [0-9]
letter          [a-zA-Z]
id              ({letter}|_)({letter}|{digit}|_)*
integer         (0|[1-9]{digit}*)
float           {digit}+\.{digit}+
string_literal  \"([^\"\n]*)\"
string_literal_sq \'([^\'\n]*)\'

%%

"def"           { return DEF; }
"if"            { return IF; }
"elif"          { return ELIF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }
"pass"          { return PASS; }
"and"           { return AND; }
"or"            { return OR; }
"not"           { return NOT; }
"is"            { return IS; }

"int"           { return INT; }
"float"         { return FLOAT; }
"bool"          { return BOOL; }
"string"        { return STRING; }

"True"          { yylval.str = strdup(yytext); return TRUE_LIT; }
"False"         { yylval.str = strdup(yytext); return FALSE_LIT; }

">="            { return GE; }
"<="            { return LE; }
"=="            { return EQ; }
"!="            { return NE; }
">"             { return GT; }
"<"             { return LT; }
"**"            { return POW; }
"->"            { return ARROW; }

"="             { return ASSIGN; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return TIMES; }
"/"             { return DIVIDE; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
":"             { return COLON; }
";"             { return SEMICOLON; }
","             { return COMMA; }

{integer}       { yylval.str = strdup(yytext); return INT_LIT; }
{float}         { yylval.str = strdup(yytext); return FLOAT_LIT; }
{string_literal} { 
                  yylval.str = strdup(yytext); 
                  return STRING_LIT; 
                }
{string_literal_sq} { 
                      yylval.str = strdup(yytext); 
                      return STRING_LIT; 
                    }
{id}            { yylval.str = strdup(yytext); return ID; }

[ \t\r]+        { /* ignore whitespace */ }
\n              { line_number++; }
#.*             { /* ignore comments */ }

.               { 
                  fprintf(stderr, "Lexical error on line %d: unexpected character '%s'\n", 
                          line_number, yytext); 
                  exit(1); 
                }

%%