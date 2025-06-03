#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdbool.h>

typedef struct Symbol {
    char* name;
    struct Symbol* next;
    struct Node* node; // מצביע לעץ ההגדרה (רק לפונקציות)
} Symbol;

typedef struct SymbolTable {
    Symbol* head;
    struct SymbolTable* parent; 
} SymbolTable;

extern SymbolTable* function_table;

extern SymbolTable* var_scope_stack;

bool add_symbol(SymbolTable** table, const char* name);
bool add_symbol_ex(SymbolTable** table, const char* name, struct Node* node);
bool symbol_exists(SymbolTable* table, const char* name);
bool var_defined(const char* name);
bool func_defined(const char* name);
void push_scope();
void pop_scope();
void free_symbol_table(SymbolTable* table);

typedef struct Node {
    char* name;             
    struct Node** children; 
    int child_count;       
} Node;

Node* make_node(const char* name, int child_count, ...);

void print_ast(Node* node, int indent);
void print_indent(int indent);

void count_params(Node* params, int* total, int* required);
int count_args(Node* args);

// טיפוסי ארגומנטים תואמים לטיפוסי פרמטרים
bool type_match(Node* param, Node* arg);
int check_arg_types(Node* params, Node* args);
Symbol* find_symbol(const char* name);
void add_params_to_scope(Node* params_node);

// פונקציה להשגת טיפוס הביטוי
const char* get_expression_type(Node* expr);

// פונקציה לבדיקת התאמת טיפוסים בהשמה
int check_assignment_types(Node* lhs, Node* rhs);
void validate_node(Node* node, const char* context);

#endif
