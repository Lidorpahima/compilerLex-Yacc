%{
#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
extern int lineno;
%}

digit       [0-9]
letter      [a-zA-Z]
id          ({letter}|[_])({letter}|{digit}|[_])*
int_lit     0|([1-9][0-9]*)
float_lit   {digit}+\.{digit}+
string_lit  \"([^\"\n]*)\"|\'([^\'\n]*)\'

%%

"def"        { return DEF; }
"if"         { return IF; }
"elif"       { return ELIF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"return"     { return RETURN; }
"pass"       { return PASS; }
"int"        { return INT; }
"float"      { return FLOAT; }
"bool"       { return BOOL; }
"string"     { return STRING; }
"True"       { yylval.str = strdup(yytext); return BOOL_LITERAL; }
"False"      { yylval.str = strdup(yytext); return BOOL_LITERAL; }

">="         { return GE; }
"<="         { return LE; }
"=="         { return EQ; }
"!="         { return NE; }
">"          { return GT; }
"<"          { return LT; }
"="          { return ASSIGN; }
"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return TIMES; }
"/"          { return DIVIDE; }
"**"         { return POW; }
"->"         { return ARROW; }

";"          { return SEMICOLON; }
":"          { return COLON; }
","          { return COMMA; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
"("          { return LPAREN; }
")"          { return RPAREN; }
"["          { return LBRACKET; }
"]"          { return RBRACKET; }

{id}         { yylval.str = strdup(yytext); return ID; }
{int_lit}    { yylval.str = strdup(yytext); return INT_LITERAL; }
{float_lit}  { yylval.str = strdup(yytext); return FLOAT_LITERAL; }
{string_lit} { yylval.str = strdup(yytext); return STR_LITERAL; }

[ \t\r]+     { /* ignore whitespace */ }
\n           { lineno++; }
"#".*        { /* ignore comments */ }

.            { printf("ERROR: '%s' IN LINE %d\n", yytext, lineno); exit(1); }

%%

int yywrap() { return 1; }
