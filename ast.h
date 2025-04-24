#ifndef AST_H
#define AST_H

#include <stdio.h>

typedef struct Node {
    char* name;             
    struct Node** children; 
    int child_count;       
} Node;

Node* make_node(const char* name, int child_count, ...);

void print_ast(Node* node, int indent);
void print_indent(int indent);

#endif
