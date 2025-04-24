%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lineno = 1;
Node* ast_root = NULL;
void yyerror(const char* s) {
    fprintf(stderr, "ERROR IN LINE %d: %s\n", lineno, s);
}
int yylex(void);
%}

%union {
    Node* node;
    char* str;
}

/* Token definitions */
%token <str> ID INT_LITERAL FLOAT_LITERAL STR_LITERAL BOOL_LITERAL
%token DEF IF ELIF ELSE WHILE RETURN PASS
%token INT FLOAT BOOL STRING
%token GE LE EQ NE GT LT ASSIGN
%token PLUS MINUS TIMES DIVIDE POW
%token SEMICOLON COLON COMMA
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET
%token ARROW

/* Operator precedence (lowest to highest) */
%left EQ NE
%left GE LE GT LT
%left PLUS MINUS
%left TIMES DIVIDE
%right POW
%right UMINUS

%start program
%type <node> program function_list function parameters param_groups param_group id_list type block declarations declaration statements statement simple_statement compound_statement assignment function_call args arg_list if_statement while_statement return_statement expression
%%

program:
    function_list {
        ast_root = $1;
        $$ = $1;
    }
;

function_list:
    function {
        $$ = make_node("FUNC_LIST", 1, $1);
    }
  | function_list function {
        $$ = make_node("FUNC_LIST", 2, $1, $2);
    }
;

function:
    DEF ID LPAREN parameters RPAREN ARROW type COLON block {
        $$ = make_node("FUNC_TYPED", 4, make_node($2, 0), $4, $7, $9);
    }
  | DEF ID LPAREN parameters RPAREN COLON block {
        $$ = make_node("FUNC", 3, make_node($2, 0), $4, $7);
    }
;

parameters:
    { $$ = make_node("PARAMS", 0); }
  | param_groups { $$ = $1; }
;

param_groups:
    param_group { $$ = make_node("PARAM_GROUPS", 1, $1); }
  | param_groups SEMICOLON param_group {
        $$ = make_node("PARAM_GROUPS", 2, $1, $3);
    }
;

param_group:
    type id_list {
        $$ = make_node("PARAM_GROUP", 2, $1, $2);
    }
;

id_list:
    ID { $$ = make_node($1, 0); }
  | id_list COMMA ID { $$ = make_node("ID_LIST", 2, $1, make_node($3, 0)); }
;

type:
    INT { $$ = make_node("int", 0); }
  | FLOAT { $$ = make_node("float", 0); }
  | BOOL { $$ = make_node("bool", 0); }
  | STRING { $$ = make_node("string", 0); }
;

block:
    LBRACE declarations statements RBRACE {
        $$ = make_node("BLOCK", 2, $2, $3);
    }
;

declarations:
    { $$ = make_node("DECLS_EMPTY", 0); }
  | declarations declaration {
        $$ = make_node("DECLS", 2, $1, $2);
    }
;

declaration:
    type id_list SEMICOLON {
        $$ = make_node("DECL", 2, $1, $2);
    }
;

statements:
    { $$ = make_node("STMTS_EMPTY", 0); }
  | statements statement {
        $$ = make_node("STMTS", 2, $1, $2);
    }
;

statement:
    simple_statement SEMICOLON {
        $$ = $1;
    }
  | compound_statement {
        $$ = $1;
    }
  | compound_statement SEMICOLON {
        $$ = $1;
    }
;

simple_statement:
    assignment { $$ = $1; }
  | function_call { $$ = $1; }
  | return_statement { $$ = $1; }
  | PASS { $$ = make_node("pass", 0); }
;

compound_statement:
    if_statement { $$ = $1; }
  | while_statement { $$ = $1; }
  | block { $$ = $1; }
;

assignment:
    ID ASSIGN expression {
        $$ = make_node("ASSIGN", 2, make_node($1, 0), $3);
    }
;

function_call:
    ID LPAREN args RPAREN {
        $$ = make_node("CALL", 2, make_node($1, 0), $3);
    }
;

args:
    { $$ = make_node("ARGS_EMPTY", 0); }
  | arg_list { $$ = $1; }
;

arg_list:
    expression { $$ = make_node("ARGS", 1, $1); }
  | arg_list COMMA expression { $$ = make_node("ARGS", 2, $1, $3); }
;

if_statement:
    IF expression COLON block {
        $$ = make_node("IF", 2, $2, $4);
    }
  | IF expression COLON block ELSE COLON block {
        $$ = make_node("IF_ELSE", 3, $2, $4, $7);
    }
  | IF expression COLON block ELIF expression COLON block {
        $$ = make_node("IF_ELIF", 4, $2, $4, $6, $8);
    }
  | IF expression COLON block ELIF expression COLON block ELSE COLON block {
        $$ = make_node("IF_ELIF_ELSE", 5, $2, $4, $6, $8, $11);
    }
;

while_statement:
    WHILE expression COLON block {
        $$ = make_node("WHILE", 2, $2, $4);
    }
;

return_statement:
    RETURN expression {
        $$ = make_node("RETURN", 1, $2);
    }
  | RETURN {
        $$ = make_node("RETURN", 0);
    }
;

expression:
    expression PLUS expression { $$ = make_node("+", 2, $1, $3); }
  | expression MINUS expression { $$ = make_node("-", 2, $1, $3); }
  | expression TIMES expression { $$ = make_node("*", 2, $1, $3); }
  | expression DIVIDE expression { $$ = make_node("/", 2, $1, $3); }
  | expression POW expression { $$ = make_node("**", 2, $1, $3); }
  | expression EQ expression { $$ = make_node("EQ", 2, $1, $3); }
  | expression NE expression { $$ = make_node("NE", 2, $1, $3); }
  | expression GE expression { $$ = make_node("GE", 2, $1, $3); }
  | expression LE expression { $$ = make_node("LE", 2, $1, $3); }
  | expression GT expression { $$ = make_node("GT", 2, $1, $3); }
  | expression LT expression { $$ = make_node("LT", 2, $1, $3); }
  | MINUS expression %prec UMINUS { $$ = make_node("NEG", 1, $2); }
  | LPAREN expression RPAREN { $$ = $2; }
  | INT_LITERAL { $$ = make_node($1, 0); }
  | FLOAT_LITERAL { $$ = make_node($1, 0); }
  | STR_LITERAL { $$ = make_node($1, 0); }
  | BOOL_LITERAL { $$ = make_node($1, 0); }
  | ID { $$ = make_node($1, 0); }
  | ID LBRACKET expression RBRACKET {
        $$ = make_node("INDEX", 2, make_node($1, 0), $3);
    }
  | function_call { $$ = $1; }
;

%%

int main() {
    if (yyparse() == 0) {
        if (ast_root == NULL) {
            return 1;
        } else {
            print_ast(ast_root, 0);
        }
    }
    return 0;
}