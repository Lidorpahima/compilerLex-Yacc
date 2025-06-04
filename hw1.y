%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex(void);
extern FILE* yyin;
extern int line_number;

void yyerror(const char* s);
node_t* ast_root = NULL;
%}

%union {
    char* str;
    node_t* node;
    data_type_t type;
}

%token <str> ID INT_LIT FLOAT_LIT STRING_LIT TRUE_LIT FALSE_LIT
%token DEF IF ELIF ELSE WHILE RETURN PASS AND OR NOT IS
%token INT FLOAT BOOL STRING
%token GE LE EQ NE GT LT ASSIGN ARROW
%token PLUS MINUS TIMES DIVIDE POW
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token COLON SEMICOLON COMMA

%type <node> program function_list function
%type <node> parameters parameter_list parameter_group param_names param
%type <node> literal
%type <node> block variable_declarations variable_declaration variable_list variable_spec
%type <node> statements statement simple_statement compound_statement
%type <node> assignment_statement return_statement if_statement while_statement
%type <node> expression_list expression
%type <node> function_call argument_list
%type <node> string_access string_slice

%type <type> type

%left OR
%left AND
%right NOT
%left EQ NE
%left GT LT GE LE IS
%left PLUS MINUS
%left TIMES DIVIDE
%right POW
%right UMINUS

%start program

%%

program:
    function_list {
        ast_root = $1;
        $$ = $1;
    }
;

function_list:
    function {
        $$ = $1;
    }
    | function_list function {
        node_t* last = $1;
        while (last->next) last = last->next;
        last->next = $2;
        $$ = $1;
    }
;

function:
    DEF ID LPAREN parameters RPAREN COLON block {
        $$ = make_node(NODE_FUNCTION, $2);
        $$->name = strdup($2);
        $$->data_type = TYPE_VOID;
        $$->params = $4;
        $$->body = $7;
        free($2);
    }
    | DEF ID LPAREN parameters RPAREN ARROW type COLON block {
        $$ = make_node(NODE_FUNCTION, $2);
        $$->name = strdup($2);
        $$->data_type = $7;
        $$->params = $4;
        $$->body = $9;
        free($2);
    }
    | DEF ID LPAREN parameters RPAREN COLON simple_statement SEMICOLON {
        $$ = make_node(NODE_FUNCTION, $2);
        $$->name = strdup($2);
        $$->data_type = TYPE_VOID;
        $$->params = $4;
        $$->body = $7;
        free($2);
    }
    | DEF ID LPAREN parameters RPAREN ARROW type COLON simple_statement SEMICOLON {
        $$ = make_node(NODE_FUNCTION, $2);
        $$->name = strdup($2);
        $$->data_type = $7;
        $$->params = $4;
        $$->body = $9;
        free($2);
    }
;

parameters:
    /* empty */ {
        $$ = NULL;
    }
    | parameter_list {
        $$ = $1;
    }
;

parameter_list:
    parameter_group {
        $$ = $1;
    }
    | parameter_list SEMICOLON parameter_group {
        node_t* last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
;

parameter_group:
    type param_names {
        // Set type for all parameters in this group
        node_t* param = $2;
        while (param) {
            param->data_type = $1;
            param = param->next;
        }
        $$ = $2;
    }
;

param_names:
    param {
        $$ = $1;
    }
    | param_names COMMA param {
        node_t* last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
;

param:
    ID {
        $$ = make_node(NODE_PARAM, $1);
        $$->name = strdup($1);
        $$->has_default = false;
        free($1);
    }
    | ID COLON literal {
        $$ = make_node(NODE_PARAM, $1);
        $$->name = strdup($1);
        $$->has_default = true;
        $$->default_value = $3;
        free($1);
    }
;

type:
    INT     { $$ = TYPE_INT; }
    | FLOAT { $$ = TYPE_FLOAT; }
    | BOOL  { $$ = TYPE_BOOL; }
    | STRING { $$ = TYPE_STRING; }
;

literal:
    INT_LIT {
        $$ = make_node(NODE_LITERAL, $1);
        $$->data_type = TYPE_INT;
        free($1);
    }
    | FLOAT_LIT {
        $$ = make_node(NODE_LITERAL, $1);
        $$->data_type = TYPE_FLOAT;
        free($1);
    }
    | STRING_LIT {
        $$ = make_node(NODE_LITERAL, $1);
        $$->data_type = TYPE_STRING;
        free($1);
    }
    | TRUE_LIT {
        $$ = make_node(NODE_LITERAL, "True");
        $$->data_type = TYPE_BOOL;
        free($1);
    }
    | FALSE_LIT {
        $$ = make_node(NODE_LITERAL, "False");
        $$->data_type = TYPE_BOOL;
        free($1);
    }
;

block:
    LBRACE variable_declarations statements RBRACE {
        $$ = make_node(NODE_BLOCK, NULL);
        $$->left = $2;  // declarations
        $$->body = $3;  // statements
    }
;

variable_declarations:
    /* empty */ {
        $$ = NULL;
    }
    | variable_declarations variable_declaration {
        if ($1) {
            node_t* last = $1;
            while (last->next) last = last->next;
            last->next = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
;

variable_declaration:
    type variable_list SEMICOLON {
        // Set type for all variables in the list
        node_t* var = $2;
        while (var) {
            var->data_type = $1;
            var = var->next;
        }
        $$ = $2;
    }
;

variable_list:
    variable_spec {
        $$ = $1;
    }
    | variable_list COMMA variable_spec {
        node_t* last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
;

variable_spec:
    ID {
        $$ = make_node(NODE_VARIABLE, $1);
        $$->name = strdup($1);
        free($1);
    }
    | ID ASSIGN expression {
        $$ = make_node(NODE_VARIABLE, $1);
        $$->name = strdup($1);
        $$->right = $3;  // initialization expression
        free($1);
    }
;

statements:
    /* empty */ {
        $$ = NULL;
    }
    | statements statement {
        if ($1) {
            node_t* last = $1;
            while (last->next) last = last->next;
            last->next = $2;
            $$ = $1;
        } else {
            $$ = $2;
        }
    }
;

statement:
    simple_statement SEMICOLON {
        $$ = $1;
    }
    | compound_statement {
        $$ = $1;
    }
;

simple_statement:
    assignment_statement {
        $$ = $1;
    }
    | function_call {
        $$ = $1;
    }
    | return_statement {
        $$ = $1;
    }
    | PASS {
        $$ = make_node(NODE_PASS, NULL);
    }
;

compound_statement:
    if_statement {
        $$ = $1;
    }
    | while_statement {
        $$ = $1;
    }
    | block {
        $$ = $1;
    }
;

assignment_statement:
    ID ASSIGN expression {
        $$ = make_node(NODE_ASSIGN, NULL);
        $$->left = make_node(NODE_VARIABLE, $1);
        $$->left->name = strdup($1);
        $$->right = $3;
        free($1);
    }
    | string_access ASSIGN expression {
        $$ = make_node(NODE_ASSIGN, NULL);
        $$->left = $1;
        $$->right = $3;
    }
;

return_statement:
    RETURN {
        $$ = make_node(NODE_RETURN, NULL);
    }
    | RETURN expression {
        $$ = make_node(NODE_RETURN, NULL);
        $$->left = $2;
    }
;

if_statement:
    IF expression COLON block {
        $$ = make_node(NODE_IF, NULL);
        $$->condition = $2;
        $$->if_body = $4;
    }
    | IF expression COLON simple_statement SEMICOLON {
        $$ = make_node(NODE_IF, NULL);
        $$->condition = $2;
        $$->if_body = $4;
    }
    | IF expression COLON block ELSE COLON block {
        $$ = make_node(NODE_IF, NULL);
        $$->condition = $2;
        $$->if_body = $4;
        $$->else_body = $7;
    }
    | IF expression COLON simple_statement SEMICOLON ELSE COLON simple_statement SEMICOLON {
        $$ = make_node(NODE_IF, NULL);
        $$->condition = $2;
        $$->if_body = $4;
        $$->else_body = $8;
    }
;

while_statement:
    WHILE expression COLON block {
        $$ = make_node(NODE_WHILE, NULL);
        $$->condition = $2;
        $$->body = $4;
    }
    | WHILE expression COLON simple_statement SEMICOLON {
        $$ = make_node(NODE_WHILE, NULL);
        $$->condition = $2;
        $$->body = $4;
    }
;

function_call:
    ID LPAREN RPAREN {
        $$ = make_node(NODE_CALL, $1);
        $$->name = strdup($1);
        $$->args = NULL;
        free($1);
    }
    | ID LPAREN argument_list RPAREN {
        $$ = make_node(NODE_CALL, $1);
        $$->name = strdup($1);
        $$->args = $3;
        free($1);
    }
;

argument_list:
    expression {
        $$ = $1;
    }
    | argument_list COMMA expression {
        node_t* last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $$ = $1;
    }
;

expression:
    literal {
        $$ = $1;
    }
    | ID {
        $$ = make_node(NODE_VARIABLE, $1);
        $$->name = strdup($1);
        free($1);
    }
    | function_call {
        $$ = $1;
    }
    | string_access {
        $$ = $1;
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    | expression PLUS expression {
        $$ = make_node(NODE_BINARY_OP, "+");
        $$->left = $1;
        $$->right = $3;
    }
    | expression MINUS expression {
        $$ = make_node(NODE_BINARY_OP, "-");
        $$->left = $1;
        $$->right = $3;
    }
    | expression TIMES expression {
        $$ = make_node(NODE_BINARY_OP, "*");
        $$->left = $1;
        $$->right = $3;
    }
    | expression DIVIDE expression {
        $$ = make_node(NODE_BINARY_OP, "/");
        $$->left = $1;
        $$->right = $3;
    }
    | expression POW expression {
        $$ = make_node(NODE_BINARY_OP, "**");
        $$->left = $1;
        $$->right = $3;
    }
    | expression GT expression {
        $$ = make_node(NODE_BINARY_OP, ">");
        $$->left = $1;
        $$->right = $3;
    }
    | expression LT expression {
        $$ = make_node(NODE_BINARY_OP, "<");
        $$->left = $1;
        $$->right = $3;
    }
    | expression GE expression {
        $$ = make_node(NODE_BINARY_OP, ">=");
        $$->left = $1;
        $$->right = $3;
    }
    | expression LE expression {
        $$ = make_node(NODE_BINARY_OP, "<=");
        $$->left = $1;
        $$->right = $3;
    }
    | expression EQ expression {
        $$ = make_node(NODE_BINARY_OP, "==");
        $$->left = $1;
        $$->right = $3;
    }
    | expression NE expression {
        $$ = make_node(NODE_BINARY_OP, "!=");
        $$->left = $1;
        $$->right = $3;
    }
    | expression AND expression {
        $$ = make_node(NODE_BINARY_OP, "and");
        $$->left = $1;
        $$->right = $3;
    }
    | expression OR expression {
        $$ = make_node(NODE_BINARY_OP, "or");
        $$->left = $1;
        $$->right = $3;
    }
    | expression IS expression {
        $$ = make_node(NODE_BINARY_OP, "is");
        $$->left = $1;
        $$->right = $3;
    }
    | NOT expression {
        $$ = make_node(NODE_UNARY_OP, "not");
        $$->left = $2;
    }
    | MINUS expression %prec UMINUS {
        $$ = make_node(NODE_UNARY_OP, "-");
        $$->left = $2;
    }
;

string_access:
    ID LBRACKET expression RBRACKET {
        $$ = make_node(NODE_STRING_ACCESS, NULL);
        $$->left = make_node(NODE_VARIABLE, $1);
        $$->left->name = strdup($1);
        $$->right = $3;
        free($1);
    }
    | ID LBRACKET string_slice RBRACKET {
        $$ = make_node(NODE_STRING_ACCESS, NULL);
        $$->left = make_node(NODE_VARIABLE, $1);
        $$->left->name = strdup($1);
        $$->right = $3;
        free($1);
    }
;

string_slice:
    expression COLON expression {
        $$ = make_node(NODE_BINARY_OP, "slice");
        $$->left = $1;
        $$->right = $3;
    }
    | COLON expression {
        $$ = make_node(NODE_BINARY_OP, "slice");
        $$->left = make_node(NODE_LITERAL, "0");
        $$->left->data_type = TYPE_INT;
        $$->right = $2;
    }
    | expression COLON {
        $$ = make_node(NODE_BINARY_OP, "slice");
        $$->left = $1;
        $$->right = NULL;
    }
    | COLON {
        $$ = make_node(NODE_BINARY_OP, "slice");
        $$->left = make_node(NODE_LITERAL, "0");
        $$->left->data_type = TYPE_INT;
        $$->right = NULL;
    }
    | expression COLON expression COLON expression {
        node_t* slice = make_node(NODE_BINARY_OP, "slice");
        slice->left = $1;
        slice->right = $3;
        
        $$ = make_node(NODE_BINARY_OP, "slice_step");
        $$->left = slice;
        $$->right = $5;
    }
;

%%

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