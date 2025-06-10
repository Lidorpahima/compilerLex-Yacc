#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Data types
typedef enum {
    TYPE_VOID,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_BOOL,
    TYPE_STRING
} data_type_t;

// Node types
typedef enum {
    NODE_PROGRAM,
    NODE_FUNCTION,
    NODE_PARAM,
    NODE_VARIABLE,
    NODE_LITERAL,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_ASSIGN,
    NODE_CALL,
    NODE_IF,
    NODE_WHILE,
    NODE_RETURN,
    NODE_BLOCK,
    NODE_STRING_ACCESS,
    NODE_PASS
} node_type_t;

// AST Node structure
typedef struct node {
    node_type_t type;
    data_type_t data_type;
    char* value;
    char* name;
    
    struct node* left;
    struct node* right;
    struct node* condition;
    struct node* if_body;
    struct node* else_body;
    struct node* params;
    struct node* body;
    struct node* args;
    struct node* next;
    
    bool has_default;
    struct node* default_value;
    
    int line_number;
} node_t;

// Symbol table structures
typedef struct symbol {
    char* name;
    data_type_t type;
    node_t* node;
    struct symbol* next;
    bool is_function;
    int param_count;
    int required_params;
} symbol_t;

typedef struct scope {
    symbol_t* symbols;
    struct scope* parent;
} scope_t;

// Global variables
extern scope_t* current_scope;
extern scope_t* global_scope;
extern int line_number;
extern int error_count;
extern int main_count;

// AC3 code generation variables
extern int temp_counter;
extern int label_counter;

// Function declarations
node_t* make_node(node_type_t type, const char* value);
void free_node(node_t* node);
void print_ast(node_t* node, int indent);

// Symbol table functions
scope_t* create_scope(scope_t* parent);
void push_scope(void);
void pop_scope(void);
symbol_t* add_symbol(const char* name, data_type_t type, node_t* node, bool is_function);
symbol_t* find_symbol(const char* name);
symbol_t* find_symbol_current_scope(const char* name);

// Type checking functions
const char* type_to_string(data_type_t type);
data_type_t string_to_type(const char* type_str);
data_type_t get_expression_type(node_t* expr);
bool types_compatible(data_type_t expected, data_type_t actual);

// Semantic analysis functions
void semantic_error(const char* msg, int line);
void analyze_program(node_t* root);
void analyze_function(node_t* func);
void analyze_statement(node_t* stmt);
void analyze_expression(node_t* expr);
void analyze_variable_declarations(node_t* decls);
int count_parameters(node_t* params);
int count_required_parameters(node_t* params);
bool check_function_call(node_t* call);

// AC3 code generation functions
void generate_ac3_code(node_t* root);
void generate_function_ac3(node_t* func);
void generate_statement_ac3(node_t* stmt);
char* generate_expression_ac3(node_t* expr);
char* generate_condition_ac3(node_t* expr);
char* generate_new_temp(void);
char* generate_new_label(void);
int calculate_frame_size(node_t* func);

#endif