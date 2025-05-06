%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineno = 1;
Node* ast_root = NULL;
extern int yylex(void);

void yyerror(const char* s) {
    fprintf(stderr, "Syntax Error on line %d: %s\n", lineno, s);
}
%}

%union {
    Node* node;
    char* str;
}

%token <str> ID INT_LITERAL FLOAT_LITERAL STR_LITERAL BOOL_LITERAL
%token DEF IF ELIF ELSE WHILE RETURN PASS AND OR NOT
%token INT FLOAT BOOL STRING
%token GE LE EQ NE GT LT ASSIGN
%token PLUS MINUS TIMES DIVIDE POW
%token SEMICOLON COLON COMMA
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET
%token ARROW

%left OR
%left AND
%right NOT
%left EQ NE GE LE GT LT
%left PLUS MINUS
%left TIMES DIVIDE
%right POW
%right UMINUS

%start program

%type <node> program function_list function func_body
%type <node> parameters param_groups param_group param_id_list plain_param_ids defaulted_param_ids default_param_decl literal
%type <node> type block declarations declaration var_decl_list var_spec
%type <node> statements statement simple_statement compound_statement suite
%type <node> assignment assignable assignable_list expression_list function_call_stmt function_call args arg_list
%type <node> if_statement elif_chain else_part while_statement return_statement pass_statement
%type <node> expression string_access string_slice_content opt_expr opt_slice_step

%%

program:
    function_list {
        ast_root = $1;
        $$ = $1;
    }
;

function_list:
    function { $$ = make_node("FUNC_LIST", 1, $1); }
  | function_list function { $$ = make_node("FUNC_LIST", 2, $1, $2); }
;

function:
    DEF ID LPAREN parameters RPAREN ARROW type COLON func_body {
        $$ = make_node("FUNC_DEF_TYPED", 4, make_node("ID", 1, make_node($2,0)), $4, $7, $9);
    }
  | DEF ID LPAREN parameters RPAREN COLON func_body {
        $$ = make_node("FUNC_DEF", 3, make_node("ID", 1, make_node($2,0)), $4, $7);
    }
;

func_body:
    block { $$ = $1; }
  | simple_statement SEMICOLON { $$ = make_node("SINGLE_STMT_BODY", 1, $1); }
;

parameters:
    { $$ = make_node("PARAMS_EMPTY", 0); }
  | param_groups { $$ = $1; }
;

param_groups:
    param_group { $$ = make_node("PARAM_GROUPS", 1, $1); }
  | param_groups SEMICOLON param_group { $$ = make_node("PARAM_GROUPS", 2, $1, $3); }
;

param_group:
    type param_id_list { $$ = make_node("PARAM_GROUP", 2, $1, $2); }
;

param_id_list:
    plain_param_ids { $$ = $1; }
  | defaulted_param_ids { $$ = $1; }
  | plain_param_ids COMMA defaulted_param_ids { $$ = make_node("PARAM_LIST", 2, $1, $3); }
;

plain_param_ids:
    ID { $$ = make_node("PARAM", 1, make_node("ID", 1, make_node($1,0))); }
  | plain_param_ids COMMA ID { $$ = make_node("PARAM_LIST", 2, $1, make_node("PARAM", 1, make_node("ID", 1, make_node($3,0)))); }
;

defaulted_param_ids:
    default_param_decl { $$ = $1; }
  | defaulted_param_ids COMMA default_param_decl { $$ = make_node("PARAM_LIST", 2, $1, $3); }
;

default_param_decl:
    ID COLON literal { $$ = make_node("PARAM_DEFAULT", 2, make_node("ID", 1, make_node($1,0)), $3); }
;

literal:
    INT_LITERAL   { $$ = make_node("LIT_INT", 1, make_node($1,0)); }
  | FLOAT_LITERAL { $$ = make_node("LIT_FLOAT", 1, make_node($1,0)); }
  | STR_LITERAL   { $$ = make_node("LIT_STR", 1, make_node($1,0)); }
  | BOOL_LITERAL  { $$ = make_node("LIT_BOOL", 1, make_node($1,0)); }
;

type:
    INT { $$ = make_node("TYPE_INT", 0); }
  | FLOAT { $$ = make_node("TYPE_FLOAT", 0); }
  | BOOL { $$ = make_node("TYPE_BOOL", 0); }
  | STRING { $$ = make_node("TYPE_STRING", 0); }
;

block:
    LBRACE declarations statements RBRACE { $$ = make_node("BLOCK", 2, $2, $3); }
;

declarations:
    { $$ = make_node("DECLS_EMPTY", 0); }
  | declarations declaration { $$ = make_node("DECLS", 2, $1, $2); }
;

declaration:
    type var_decl_list SEMICOLON { $$ = make_node("VAR_DECL", 2, $1, $2); }
;

var_decl_list:
    var_spec { $$ = make_node("VAR_SPEC_LIST", 1, $1); }
  | var_decl_list COMMA var_spec { $$ = make_node("VAR_SPEC_LIST", 2, $1, $3); }
;

var_spec:
    ID { $$ = make_node("VAR", 1, make_node("ID", 1, make_node($1,0))); }
  | ID ASSIGN expression { $$ = make_node("VAR_INIT", 2, make_node("ID", 1, make_node($1,0)), $3); }
;

statements:
    { $$ = make_node("STMTS_EMPTY", 0); }
  | statements statement { $$ = make_node("STMTS", 2, $1, $2); }
;

statement:
    simple_statement SEMICOLON { $$ = $1; }
  | compound_statement { $$ = $1; }
;

simple_statement:
    assignment { $$ = $1; }
  | function_call_stmt { $$ = $1; }
  | return_statement { $$ = $1; }
  | pass_statement { $$ = $1; }
;

pass_statement:
    PASS { $$ = make_node("PASS", 0); }
;

compound_statement:
    if_statement { $$ = $1; }
  | while_statement { $$ = $1; }
  | block { $$ = $1; }
;

suite:
    block { $$ = $1; }
  | simple_statement SEMICOLON { $$ = make_node("SINGLE_STMT_SUITE", 1, $1); }
;

assignment:
    assignable_list ASSIGN expression_list {
        $$ = make_node("ASSIGN", 2, $1, $3);
    }
;

assignable_list:
    assignable { $$ = make_node("LHS_LIST", 1, $1); }
  | assignable_list COMMA assignable { $$ = make_node("LHS_LIST", 2, $1, $3); }
;

assignable:
    ID { $$ = make_node("ID", 1, make_node($1,0)); }
  | string_access { $$ = $1; }
;

expression_list:
    expression { $$ = make_node("RHS_LIST", 1, $1); }
  | expression_list COMMA expression { $$ = make_node("RHS_LIST", 2, $1, $3); }
;

function_call_stmt:
    function_call { $$ = make_node("CALL_STMT", 1, $1); }
;

function_call:
    ID LPAREN args RPAREN { $$ = make_node("CALL", 2, make_node("ID", 1, make_node($1,0)), $3); }
;

args:
    { $$ = make_node("ARGS_EMPTY", 0); }
  | arg_list { $$ = $1; }
;

arg_list:
    expression { $$ = make_node("ARG_LIST", 1, $1); }
  | arg_list COMMA expression { $$ = make_node("ARG_LIST", 2, $1, $3); }
;

if_statement:
    IF expression COLON suite elif_chain else_part {
        $$ = make_node("IF_STMT", 4, $2, $4, $5, $6);
    }
;

elif_chain:
    { $$ = make_node("ELIF_EMPTY", 0); }
  | elif_chain ELIF expression COLON suite {
        $$ = make_node("ELIF_CHAIN", 2, $1, make_node("ELIF", 2, $3, $5));
    }
;

else_part:
    { $$ = make_node("ELSE_EMPTY", 0); }
  | ELSE COLON suite { $$ = make_node("ELSE", 1, $3); }
;

while_statement:
    WHILE expression COLON suite { $$ = make_node("WHILE", 2, $2, $4); }
;

return_statement:
    RETURN expression { $$ = make_node("RETURN_VALUE", 1, $2); }
  | RETURN { $$ = make_node("RETURN_EMPTY", 0); }
;

expression:
    expression OR expression { $$ = make_node("OR", 2, $1, $3); }
  | expression AND expression { $$ = make_node("AND", 2, $1, $3); }
  | NOT expression { $$ = make_node("NOT", 1, $2); }
  | expression EQ expression { $$ = make_node("==", 2, $1, $3); }
  | expression NE expression { $$ = make_node("!=", 2, $1, $3); }
  | expression GE expression { $$ = make_node(">=", 2, $1, $3); }
  | expression LE expression { $$ = make_node("<=", 2, $1, $3); }
  | expression GT expression { $$ = make_node(">", 2, $1, $3); }
  | expression LT expression { $$ = make_node("<", 2, $1, $3); }
  | expression PLUS expression { $$ = make_node("+", 2, $1, $3); }
  | expression MINUS expression { $$ = make_node("-", 2, $1, $3); }
  | expression TIMES expression { $$ = make_node("*", 2, $1, $3); }
  | expression DIVIDE expression { $$ = make_node("/", 2, $1, $3); }
  | expression POW expression { $$ = make_node("**", 2, $1, $3); }
  | MINUS expression %prec UMINUS { $$ = make_node("UMINUS", 1, $2); }
  | LPAREN expression RPAREN { $$ = $2; }
  | literal { $$ = $1; }
  | ID { $$ = make_node("VAR_USE", 1, make_node("ID", 1, make_node($1,0))); }
  | string_access { $$ = $1; }
  | function_call { $$ = $1; }
;

string_access:
    ID LBRACKET string_slice_content RBRACKET {
        $$ = make_node("STRING_ACCESS", 2, make_node("ID", 1, make_node($1,0)), $3);
    }
;

string_slice_content:
    expression { $$ = make_node("INDEX", 1, $1); }
  | opt_expr COLON opt_expr opt_slice_step {
        $$ = make_node("SLICE", 3, $1, $3, $4);
    }
;

opt_expr:
    { $$ = make_node("EMPTY", 0); }
  | expression { $$ = $1; }
;

opt_slice_step:
    { $$ = make_node("EMPTY", 0); }
  | COLON opt_expr { $$ = $2; }
;

%%

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
    return 0;
}