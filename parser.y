%{
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
%}

%union {
    Node* node;
    char* str;
}

%token <str> ID INT_LITERAL FLOAT_LITERAL STR_LITERAL BOOL_LITERAL
%token DEF IF ELIF ELSE WHILE RETURN PASS AND OR NOT
%token INT FLOAT BOOL STRING
%token GE LE EQ NE GT LT ASSIGN IS
%token PLUS MINUS TIMES DIVIDE POW
%token SEMICOLON COLON COMMA
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET
%token ARROW

%left OR
%left AND
%right NOT
%left EQ NE GE LE GT LT IS
%left PLUS MINUS
%left TIMES DIVIDE
%right POW
%right UMINUS

%start program

%type <node> program function_list function func_body
%type <node> parameters param_list param literal
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
        clear_all_symbols();
    }
;

function_list:
    function {
        if (!add_symbol_ex(&function_table, $1->children[0]->children[0]->name, $1)) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        $$ = make_node("FUNC_LIST", 1, $1);
    }
  | function_list function {
        if (!add_symbol_ex(&function_table, $2->children[0]->children[0]->name, $2)) {
            yyerror("Duplicate function name");
            YYERROR;
        }
        $$ = make_node("FUNC_LIST", 2, $1, $2);
    }
;

function:
    DEF ID LPAREN parameters RPAREN ARROW type COLON {
        push_scope();
        add_params_to_scope($4);
    } func_body {
        pop_scope();
        if (strcmp($2, "__main__") == 0) {
            yyerror("__main__ must not have a return type");
            YYERROR;
        }
        $$ = make_node("FUNC_DEF_TYPED", 4, make_node("ID", 1, make_node($2,0)), $4, $7, $10);
    }
  | DEF ID LPAREN parameters RPAREN COLON {
        push_scope();
        add_params_to_scope($4);
    } func_body {
        pop_scope();
        if (strcmp($2, "__main__") == 0) {
            main_count++;
            if (main_count > 1) {
                yyerror("Multiple definitions of __main__ are not allowed");
                YYERROR;
            }
            if (strcmp($4->name, "PARAMS_EMPTY") != 0) {
                yyerror("__main__ must not have parameters");
                YYERROR;
            }
        }
        $$ = make_node("FUNC_DEF", 3, make_node("ID", 1, make_node($2,0)), $4, $8);
    }
;

func_body:
    block { $$ = $1; }
  | simple_statement SEMICOLON { $$ = make_node("SINGLE_STMT_BODY", 1, $1); }
;

parameters:
    { $$ = make_node("PARAMS_EMPTY", 0); }
  | param_list { $$ = $1; }
;

param_list:
    param { $$ = make_node("PARAM_LIST", 1, $1); }
  | param_list COMMA param { $$ = make_node("PARAM_LIST", 2, $1, $3); }
  | param_list SEMICOLON param { $$ = make_node("PARAM_LIST", 2, $1, $3); }
;

param:
    type ID ASSIGN literal {
        // בדיקת טיפוס ערך ברירת מחדל
        int type_ok = 0;
        if ($1 && $4) {
            // $1 = type node, $4 = literal node
            const char* param_type = $1->name;
            const char* lit_type = NULL;
            if (strcmp($4->name, "LIT_INT") == 0) lit_type = "TYPE_INT";
            else if (strcmp($4->name, "LIT_FLOAT") == 0) lit_type = "TYPE_FLOAT";
            else if (strcmp($4->name, "LIT_STR") == 0) lit_type = "TYPE_STRING";
            else if (strcmp($4->name, "LIT_BOOL") == 0) lit_type = "TYPE_BOOL";
            if (lit_type && strcmp(param_type, lit_type) == 0) type_ok = 1;
        }
        if (!type_ok) {
            char err[256];
            snprintf(err, sizeof(err), "Default value type does not match parameter type for '%s'", $2);
            yyerror(err);
            YYERROR;
        }
        $$ = make_node("PARAM_DEFAULT", 3, $1, make_node("ID", 1, make_node($2,0)), $4);
    }
  | type ID { $$ = make_node("PARAM", 2, $1, make_node("ID", 1, make_node($2,0))); }
  | ID ASSIGN literal { $$ = make_node("PARAM_DEFAULT", 2, make_node("ID", 1, make_node($1,0)), $3); }
  | ID { $$ = make_node("PARAM", 1, make_node("ID", 1, make_node($1,0))); }
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
    LBRACE {
        push_scope();
    } declarations statements RBRACE {
        if (strcmp($3->name, "DECLS_EMPTY") == 0 && strcmp($4->name, "STMTS_EMPTY") == 0) {
            yyerror("Empty blocks {} are not allowed");
            YYERROR;
        }
        pop_scope();
        $$ = make_node("BLOCK", 2, $3, $4);
    }
;

declarations:
    { $$ = make_node("DECLS_EMPTY", 0); }
  | declarations declaration { $$ = make_node("DECLS", 2, $1, $2); }
;

declaration:
    type var_decl_list SEMICOLON {
        Node* type_node = $1;
        Node* list = $2;
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
        $$ = make_node("VAR_DECL", 2, $1, $2);
    }
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
        // בדיקת התאמת טיפוסים בין הצד השמאלי לצד הימני
        int error_code = check_assignment_types($1, $3);
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
    ID LPAREN args RPAREN {
        if (!func_defined($1)) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called before declaration", $1);
            yyerror(err);
            YYERROR;
        }
        Symbol* f = function_table ? function_table->head : NULL;
        Node* func_def = NULL;
        while (f) {
            if (strcmp(f->name, $1) == 0 && f->node) {
                func_def = f->node;
                break;
            }
            f = f->next;
        }
        if (!func_def) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' definition not found for argument check", $1);
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
        int nargs = count_args($3);
        if (nargs > total) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called with too many arguments (%d > %d)", $1, nargs, total);
            yyerror(err);
            YYERROR;
        }
        if (nargs < required) {
            char err[256];
            snprintf(err, sizeof(err), "Function '%s' called with too few arguments (%d < %d)", $1, nargs, required);
            yyerror(err);
            YYERROR;
        }
        int type_mismatch = check_arg_types(params, $3);
        if (type_mismatch > 0) {
            char err[256];
            snprintf(err, sizeof(err), "Type mismatch in argument %d of function '%s'", type_mismatch, $1);
            yyerror(err);
            YYERROR;
        }
        $$ = make_node("CALL", 2, make_node("ID", 1, make_node($1,0)), $3);
    }
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
    expression OR expression { 
        // בדיקה שהאופרנדים הם מטיפוס בוליאני
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || strcmp(left_type, "TYPE_BOOL") != 0) {
            yyerror("Left operand of 'or' must be of type bool");
            YYERROR;
        }
        if (!right_type || strcmp(right_type, "TYPE_BOOL") != 0) {
            yyerror("Right operand of 'or' must be of type bool");
            YYERROR;
        }
        $$ = make_node("OR", 2, $1, $3); 
    }
  | expression AND expression { 
        // בדיקה שהאופרנדים הם מטיפוס בוליאני
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || strcmp(left_type, "TYPE_BOOL") != 0) {
            yyerror("Left operand of 'and' must be of type bool");
            YYERROR;
        }
        if (!right_type || strcmp(right_type, "TYPE_BOOL") != 0) {
            yyerror("Right operand of 'and' must be of type bool");
            YYERROR;
        }
        $$ = make_node("AND", 2, $1, $3); 
    }
  | NOT expression { 
        // בדיקה שהאופרנד הוא מטיפוס בוליאני
        const char* type = get_expression_type($2);
        
        if (!type || strcmp(type, "TYPE_BOOL") != 0) {
            yyerror("Operand of 'not' must be of type bool");
            YYERROR;
        }
        $$ = make_node("NOT", 1, $2); 
    }
  | expression EQ expression { 
        // בדיקה שהאופרנדים מאותו טיפוס
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '=='");
            YYERROR;
        }
        
        if (strcmp(left_type, right_type) != 0) {
            yyerror("Both operands of '==' must be of the same type");
            YYERROR;
        }
        $$ = make_node("==", 2, $1, $3); 
    }
  | expression NE expression { 
        // בדיקה שהאופרנדים מאותו טיפוס
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '!='");
            YYERROR;
        }
        
        if (strcmp(left_type, right_type) != 0) {
            yyerror("Both operands of '!=' must be of the same type");
            YYERROR;
        }
        $$ = make_node("!=", 2, $1, $3); 
    }
  | expression GE expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '>='");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '>=' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node(">=", 2, $1, $3); 
    }
  | expression LE expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '<='");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '<=' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("<=", 2, $1, $3); 
    }
  | expression GT expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '>'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '>' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node(">", 2, $1, $3); 
    }
  | expression LT expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '<'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '<' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("<", 2, $1, $3); 
    }
  | expression IS expression { $$ = make_node("IS", 2, $1, $3); }
  | expression PLUS expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '+'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '+' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("+", 2, $1, $3); 
    }
  | expression MINUS expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '-'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '-' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("-", 2, $1, $3); 
    }
  | expression TIMES expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '*'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '*' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("*", 2, $1, $3); 
    }
  | expression DIVIDE expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '/'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '/' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("/", 2, $1, $3); 
    }
  | expression POW expression { 
        // בדיקה שהאופרנדים הם מטיפוס מספרי
        const char* left_type = get_expression_type($1);
        const char* right_type = get_expression_type($3);
        
        if (!left_type || !right_type) {
            yyerror("Invalid operands for '**'");
            YYERROR;
        }
        
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            yyerror("Both operands of '**' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("**", 2, $1, $3); 
    }
  | MINUS expression %prec UMINUS { 
        // בדיקה שהאופרנד הוא מטיפוס מספרי
        const char* type = get_expression_type($2);
        
        if (!type || (strcmp(type, "TYPE_INT") != 0 && strcmp(type, "TYPE_FLOAT") != 0)) {
            yyerror("Operand of unary '-' must be numeric (int or float)");
            YYERROR;
        }
        $$ = make_node("UMINUS", 1, $2); 
    }
  | LPAREN expression RPAREN { $$ = $2; }
  | literal { $$ = $1; }
  | ID {
      if (!var_defined($1)) {
        char err[256];
        snprintf(err, sizeof(err), "Variable '%s' used before declaration", $1);
        yyerror(err);
        YYERROR;
      }
      $$ = make_node("VAR_USE", 1, make_node("ID", 1, make_node($1,0)));
    }
  | string_access { $$ = $1; }
  | function_call { $$ = $1; }
;

string_access:
    ID LBRACKET string_slice_content RBRACKET {
        // בדיקה שהמשתנה הוא מחרוזת
        if (!var_defined($1)) {
            char err[256];
            snprintf(err, sizeof(err), "Variable '%s' used before declaration", $1);
            yyerror(err);
            YYERROR;
        }
        
        // מצא את המשתנה וודא שהוא מטיפוס מחרוזת
        Symbol* s = find_symbol($1);
        
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
                snprintf(err, sizeof(err), "Operator [] can only be used with string variables, but '%s' is not a string", $1);
                yyerror(err);
                YYERROR;
            }
        }
        
        $$ = make_node("STRING_ACCESS", 2, make_node("ID", 1, make_node($1,0)), $3);
    }
;

string_slice_content:
    expression { 
        // בדיקה שהאינדקס הוא מטיפוס int
        const char* expr_type = get_expression_type($1);
        if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
            yyerror("String index must be of type int");
            YYERROR;
        }
        $$ = make_node("INDEX", 1, $1); 
    }
  | opt_expr COLON opt_expr opt_slice_step {
        // בדיקת טיפוסים בslice
        if ($1 && strcmp($1->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type($1);
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice indices must be of type int");
                YYERROR;
            }
        }
        if ($3 && strcmp($3->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type($3);
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice indices must be of type int");
                YYERROR;
            }
        }
        if ($4 && strcmp($4->name, "EMPTY") != 0) {
            const char* expr_type = get_expression_type($4);
            if (expr_type == NULL || strcmp(expr_type, "TYPE_INT") != 0) {
                yyerror("String slice step must be of type int");
                YYERROR;
            }
        }
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
    clear_all_symbols();
    return 0;
}