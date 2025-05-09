#include "ast.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

Node* make_node(const char* name, int child_count, ...) {
    if (name == NULL) {
        printf("make_node ERROR: name is NULL\n");
        exit(1);
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->name = strdup(name);
    node->child_count = child_count;

    if (child_count > 0) {
        node->children = (Node**)malloc(sizeof(Node*) * child_count);
        va_list args;
        va_start(args, child_count);
        for (int i = 0; i < child_count; i++) {
            node->children[i] = va_arg(args, Node*);
            if (node->children[i] == NULL) {
                printf("make_node ERROR: child %d is NULL for node %s\n", i, name);
                exit(1);
            }
        }
        va_end(args);
    } else {
        node->children = NULL;
    }

    return node;
}

void print_indent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

bool is_internal_node(const char* name) {
    return (
        strcmp(name, "PARAM_LIST") == 0 ||
        strcmp(name, "PARAM_GROUPS") == 0 ||
        strcmp(name, "PARAM_GROUP") == 0 ||
        strcmp(name, "PARAMS_EMPTY") == 0 ||
        strcmp(name, "ARGS_EMPTY") == 0 ||
        strcmp(name, "ARG_LIST") == 0
    );
}

void print_ast(Node* node, int indent) {
    if (!node) return;

    if (is_internal_node(node->name)) {
        for (int i = 0; i < node->child_count; i++) {
            print_ast(node->children[i], indent);
        }
        return;
    }

    print_indent(indent);
    printf("(%s", node->name);

    if (node->child_count > 0) {
        printf("\n");
        for (int i = 0; i < node->child_count; i++) {
            print_ast(node->children[i], indent + 1);
        }
        print_indent(indent);
    }

    printf(")\n");
}

// פונקציות עזר לניהול סמלים, AST, וספירת פרמטרים/ארגומנטים

SymbolTable* function_table = NULL;
SymbolTable* var_scope_stack = NULL;

// הוספת סמל לטבלה (פונקציה או משתנה)
bool add_symbol_ex(SymbolTable** table, const char* name, Node* node) {
    if (symbol_exists(*table, name)) return false;
    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->next = (*table) ? (*table)->head : NULL;
    sym->node = node;
    if (!*table) {
        *table = (SymbolTable*)malloc(sizeof(SymbolTable));
        (*table)->parent = NULL;
    }
    sym->next = (*table)->head;
    (*table)->head = sym;
    return true;
}

bool add_symbol(SymbolTable** table, const char* name) {
    return add_symbol_ex(table, name, NULL);
}

// בדיקת קיום סמל בטבלה (ללא חיפוש בהורה)
bool symbol_exists(SymbolTable* table, const char* name) {
    if (!table) return false;
    Symbol* curr = table->head;
    while (curr) {
        if (strcmp(curr->name, name) == 0) return true;
        curr = curr->next;
    }
    return false;
}

// בדיקת קיום משתנה בכל ה-scopeים
bool var_defined(const char* name) {
    SymbolTable* curr = var_scope_stack;
    while (curr) {
        if (symbol_exists(curr, name)) return true;
        curr = curr->parent;
    }
    return false;
}

// בדיקת קיום פונקציה (גלובלי)
bool func_defined(const char* name) {
    return symbol_exists(function_table, name);
}

void push_scope() {
    SymbolTable* new_scope = (SymbolTable*)malloc(sizeof(SymbolTable));
    new_scope->head = NULL;
    new_scope->parent = var_scope_stack;
    var_scope_stack = new_scope;
}

void pop_scope() {
    if (!var_scope_stack) return;
    SymbolTable* old = var_scope_stack;
    var_scope_stack = var_scope_stack->parent;
    free_symbol_table(old);
}

void free_symbol_table(SymbolTable* table) {
    Symbol* curr = table->head;
    while (curr) {
        Symbol* next = curr->next;
        free(curr->name);
        free(curr);
        curr = next;
    }
    free(table);
}

// ספירת פרמטרים (סה"כ וחובה)
void count_params(Node* params, int* total, int* required) {
    if (!params) return;
    if (strcmp(params->name, "PARAMS_EMPTY") == 0) return;
    if (strcmp(params->name, "PARAM") == 0) {
        (*total)++;
        (*required)++;
    } else if (strcmp(params->name, "PARAM_DEFAULT") == 0) {
        (*total)++;
    } else if (strcmp(params->name, "PARAM_LIST") == 0 || strcmp(params->name, "PARAM_GROUPS") == 0) {
        for (int i = 0; i < params->child_count; i++)
            count_params(params->children[i], total, required);
    } else if (strcmp(params->name, "PARAM_GROUP") == 0) {
        count_params(params->children[1], total, required);
    }
}

// ספירת ארגומנטים בקריאה
int count_args(Node* args) {
    if (!args) return 0;
    if (strcmp(args->name, "ARGS_EMPTY") == 0) return 0;
    if (strcmp(args->name, "ARG_LIST") == 0) {
        int left = count_args(args->children[0]);
        int right = count_args(args->children[1]);
        return left + right;
    }
    return 1;
}
