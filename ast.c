#include "ast.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

Node* make_node(const char* name, int child_count, ...) {
    if (name == NULL) {
        printf("make_node ERROR: name is NULL\\n");
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
                printf("make_node ERROR: child %d is NULL for node %s\\n", i, name);
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

void print_ast(Node* node, int indent) {
    if (!node) return;

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
