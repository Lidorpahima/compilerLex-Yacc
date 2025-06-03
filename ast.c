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

// בדיקת טיפוס בין פרמטר לארגומנט
bool type_match(Node* param, Node* arg) {
    if (!param || !arg) return false;
    // פרמטר עם טיפוס: PARAM, PARAM_DEFAULT
    Node* type_node = NULL;
    if (strcmp(param->name, "PARAM") == 0)
        type_node = param->children[0];
    else if (strcmp(param->name, "PARAM_DEFAULT") == 0)
        type_node = param->children[0];
    else
        return false;
    if (!type_node) return false;
    // קבל שם טיפוס פרמטר
    const char* param_type = type_node->name;
    // קבל טיפוס בפועל של הארגומנט
    const char* arg_type = NULL;
    if (strcmp(arg->name, "LIT_INT") == 0) arg_type = "TYPE_INT";
    else if (strcmp(arg->name, "LIT_FLOAT") == 0) arg_type = "TYPE_FLOAT";
    else if (strcmp(arg->name, "LIT_STR") == 0) arg_type = "TYPE_STRING";
    else if (strcmp(arg->name, "LIT_BOOL") == 0) arg_type = "TYPE_BOOL";
    else if (strcmp(arg->name, "VAR_USE") == 0 && arg->children[0]) {
        Symbol* s = find_symbol(arg->children[0]->children[0]->name);
        if (s && s->node && (strcmp(s->node->name, "VAR") == 0 || strcmp(s->node->name, "VAR_INIT") == 0))
            arg_type = s->node->children[0]->name;
    }
    if (!arg_type) return true; // אם לא ידוע, לא בודקים
    return strcmp(param_type, arg_type) == 0;
}

// בדיקת כל הארגומנטים מול הפרמטרים
int check_arg_types(Node* params, Node* args) {
    // הפוך רשימות לפרמטרים וארגומנטים
    Node* plist[32], *alist[32];
    int pc=0, ac=0;
    void flatten(Node* n, Node** arr, int* cnt, const char* list_name) {
        if (!n) return;
        if (strcmp(n->name, list_name) == 0) {
            flatten(n->children[0], arr, cnt, list_name);
            flatten(n->children[1], arr, cnt, list_name);
        } else {
            arr[(*cnt)++] = n;
        }
    }
    if (params && strcmp(params->name, "PARAM_LIST") == 0)
        flatten(params, plist, &pc, "PARAM_LIST");
    else if (params && (strcmp(params->name, "PARAM") == 0 || strcmp(params->name, "PARAM_DEFAULT") == 0))
        plist[pc++] = params;
    if (args && strcmp(args->name, "ARG_LIST") == 0)
        flatten(args, alist, &ac, "ARG_LIST");
    else if (args && strcmp(args->name, "ARGS_EMPTY") != 0)
        alist[ac++] = args;
    int n = (ac < pc) ? ac : pc;
    for (int i = 0; i < n; i++) {
        if (!type_match(plist[i], alist[i]))
            return i+1;
    }
    return 0;
}

// חיפוש סמל בסקופים
Symbol* find_symbol(const char* name) {
    SymbolTable* t = var_scope_stack;
    while (t) {
        Symbol* s = t->head;
        while (s) {
            if (strcmp(s->name, name) == 0) return s;
            s = s->next;
        }
        t = t->parent;
    }
    if (function_table) {
        Symbol* s = function_table->head;
        while (s) {
            if (strcmp(s->name, name) == 0) return s;
            s = s->next;
        }
    }
    return NULL;
}

// הוספת פרמטרים לסקופ
void add_params_to_scope(Node* params) {
    if (!params) return;
    void add(Node* n) {
        if (!n) return;
        if (strcmp(n->name, "PARAM_LIST") == 0) {
            add(n->children[0]);
            add(n->children[1]);
        } else if (strcmp(n->name, "PARAM") == 0 || strcmp(n->name, "PARAM_DEFAULT") == 0) {
            Node* id = (strcmp(n->name, "PARAM") == 0) ? n->children[1] : n->children[1];
            if (id && strcmp(id->name, "ID") == 0)
                add_symbol_ex(&var_scope_stack, id->children[0]->name, n);
        }
    }
    add(params);
}

// השגת טיפוס של ביטוי
const char* get_expression_type(Node* expr) {
    if (!expr) return NULL;
    
    // זיהוי טיפוס לפי סוג הביטוי
    if (strcmp(expr->name, "LIT_INT") == 0) return "TYPE_INT";
    if (strcmp(expr->name, "LIT_FLOAT") == 0) return "TYPE_FLOAT";
    if (strcmp(expr->name, "LIT_STR") == 0) return "TYPE_STRING";
    if (strcmp(expr->name, "LIT_BOOL") == 0) return "TYPE_BOOL";
    if (strcmp(expr->name, "STRING_ACCESS") == 0) return "TYPE_STRING"; // גישה למחרוזת מחזירה מחרוזת
    if (strcmp(expr->name, "INDEX") == 0) return "TYPE_STRING"; // גישה למחרוזת באינדקס מחזירה מחרוזת
    
    // טיפול במשתנים
    if (strcmp(expr->name, "VAR_USE") == 0 && expr->child_count > 0) {
        const char* var_name = expr->children[0]->children[0]->name;
        
        // חיפוש המשתנה בסקופ
        Symbol* s = find_symbol(var_name);
        
        if (s && s->node) {
            // טיפול בפרמטרים של פונקציה
            if (strcmp(s->node->name, "PARAM") == 0) {
                if (s->node->child_count >= 1)
                    return s->node->children[0]->name;  // TYPE_*
            }
            else if (strcmp(s->node->name, "PARAM_DEFAULT") == 0) {
                if (s->node->child_count >= 1)
                    return s->node->children[0]->name;  // TYPE_*
            }
            // טיפול בהצהרת משתנה
            else if (strcmp(s->node->name, "VAR_DECL") == 0) {
                return s->node->children[0]->name;  // TYPE_*
            }
        }
    }
    
    // טיפול בקריאות לפונקציה
    if (strcmp(expr->name, "CALL") == 0 && expr->child_count > 0) {
        const char* func_name = expr->children[0]->children[0]->name;
        Symbol* s = NULL;
        if (function_table) {
            Symbol* curr = function_table->head;
            while (curr) {
                if (strcmp(curr->name, func_name) == 0) {
                    s = curr;
                    break;
                }
                curr = curr->next;
            }
        }
        
        if (s && s->node && strcmp(s->node->name, "FUNC_DEF_TYPED") == 0) {
            return s->node->children[2]->name;  // TYPE_*
        }
        // פונקציות ללא החזרת ערך מפורשת
        return NULL;
    }
    
    // ביטויים אריתמטיים
    if (strcmp(expr->name, "+") == 0 || strcmp(expr->name, "-") == 0 ||
        strcmp(expr->name, "*") == 0 || strcmp(expr->name, "/") == 0 ||
        strcmp(expr->name, "**") == 0) {
        const char* left_type = get_expression_type(expr->children[0]);
        const char* right_type = get_expression_type(expr->children[1]);
        
        if (!left_type || !right_type) return NULL;
        
        // אם אחד מהם לא מספר, זו שגיאה
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            return NULL;  // שגיאה טיפוסית
        }
        
        // אם אחד מהם float, התוצאה float
        if (strcmp(left_type, "TYPE_FLOAT") == 0 || strcmp(right_type, "TYPE_FLOAT") == 0) {
            return "TYPE_FLOAT";
        }
        
        // אחרת, int
        return "TYPE_INT";
    }
    
    // אופרטור המינוס החד-אברי
    if (strcmp(expr->name, "UMINUS") == 0) {
        const char* type = get_expression_type(expr->children[0]);
        if (!type) return NULL;
        
        if (strcmp(type, "TYPE_INT") != 0 && strcmp(type, "TYPE_FLOAT") != 0) {
            return NULL;  // שגיאה טיפוסית
        }
        
        return type;  // שומר על אותו הטיפוס
    }
    
    // ביטויים לוגיים
    if (strcmp(expr->name, "AND") == 0 || strcmp(expr->name, "OR") == 0) {
        const char* left_type = get_expression_type(expr->children[0]);
        const char* right_type = get_expression_type(expr->children[1]);
        
        if (!left_type || !right_type) return NULL;
        
        // שני האופרנדים חייבים להיות מסוג בוליאני
        if (strcmp(left_type, "TYPE_BOOL") != 0 || strcmp(right_type, "TYPE_BOOL") != 0) {
            return NULL;  // שגיאה טיפוסית
        }
        
        return "TYPE_BOOL";
    }
    
    // אופרטור השלילה הלוגית
    if (strcmp(expr->name, "NOT") == 0) {
        const char* type = get_expression_type(expr->children[0]);
        if (!type || strcmp(type, "TYPE_BOOL") != 0) {
            return NULL;  // שגיאה טיפוסית
        }
        
        return "TYPE_BOOL";
    }
    
    // אופרטורים של השוואת ערכים
    if (strcmp(expr->name, "==") == 0 || strcmp(expr->name, "!=") == 0) {
        const char* left_type = get_expression_type(expr->children[0]);
        const char* right_type = get_expression_type(expr->children[1]);
        
        if (!left_type || !right_type) return NULL;
        
        // שני הצדדים חייבים להיות מאותו טיפוס
        if (strcmp(left_type, right_type) != 0) {
            return NULL;  // שגיאה טיפוסית
        }
        
        return "TYPE_BOOL";
    }
    
    // אופרטורים של השוואה מספרית
    if (strcmp(expr->name, ">") == 0 || strcmp(expr->name, "<") == 0 ||
        strcmp(expr->name, ">=") == 0 || strcmp(expr->name, "<=") == 0) {
        const char* left_type = get_expression_type(expr->children[0]);
        const char* right_type = get_expression_type(expr->children[1]);
        
        if (!left_type || !right_type) return NULL;
        
        // שני הצדדים חייבים להיות מספרים (int או float)
        if ((strcmp(left_type, "TYPE_INT") != 0 && strcmp(left_type, "TYPE_FLOAT") != 0) ||
            (strcmp(right_type, "TYPE_INT") != 0 && strcmp(right_type, "TYPE_FLOAT") != 0)) {
            return NULL;  // שגיאה טיפוסית
        }
        
        return "TYPE_BOOL";
    }
    
    // אופרטור IS
    if (strcmp(expr->name, "IS") == 0) {
        // IS תמיד מחזיר תוצאה בוליאנית
        return "TYPE_BOOL";
    }
    
    // לא זוהה הטיפוס
    return NULL;
}

// בדיקת תאימות טיפוסים עבור השמה
int check_assignment_types(Node* lhs, Node* rhs) {
    // אם אחד מהם ריק, אין שגיאה
    if (!lhs || !rhs) return 0;
    
    // שליפת רשימות של LHS ו-RHS
    Node* lhs_list[32], *rhs_list[32];
    int lc = 0, rc = 0;
    
    // שטח רשימת LHS
    void flatten_lhs(Node* node) {
        if (!node) return;
        
        if (strcmp(node->name, "LHS_LIST") == 0) {
            for (int i = 0; i < node->child_count; i++) {
                flatten_lhs(node->children[i]);
            }
        } else {
            lhs_list[lc++] = node;
        }
    }
    
    // שטח רשימת RHS
    void flatten_rhs(Node* node) {
        if (!node) return;
        
        if (strcmp(node->name, "RHS_LIST") == 0) {
            for (int i = 0; i < node->child_count; i++) {
                flatten_rhs(node->children[i]);
            }
        } else {
            rhs_list[rc++] = node;
        }
    }
    
    flatten_lhs(lhs);
    flatten_rhs(rhs);
    
    // אם יש יותר ערכים בצד ימין מאשר בצד שמאל, זו שגיאה
    if (rc > lc) return -1;  // יותר מדי ערכים בצד ימין
    
    // אם יש פחות ערכים בצד ימין מאשר בצד שמאל, זו שגיאה
    if (rc < lc) return -2;  // לא מספיק ערכים בצד ימין
    
    // בדיקת התאמת טיפוסים
    for (int i = 0; i < lc; i++) {
        // קבל את המשתנה השמאלי
        Node* lvar = lhs_list[i];
        const char* lvar_type = NULL;
        
        // אם זה ID, מצא את טיפוס המשתנה
        if (strcmp(lvar->name, "ID") == 0 && lvar->child_count > 0) {
            Symbol* s = find_symbol(lvar->children[0]->name);
            if (s && s->node) {
                if (strcmp(s->node->name, "VAR_DECL") == 0) {
                    lvar_type = s->node->children[0]->name;
                }
                else if (strcmp(s->node->name, "PARAM") == 0 && s->node->child_count >= 1) {
                    lvar_type = s->node->children[0]->name;
                }
                else if (strcmp(s->node->name, "PARAM_DEFAULT") == 0 && s->node->child_count >= 1) {
                    lvar_type = s->node->children[0]->name;
                }
            }
        }
        else if (strcmp(lvar->name, "STRING_ACCESS") == 0) {
            // גישה למחרוזת תמיד מחזירה מחרוזת
            lvar_type = "TYPE_STRING";
        }
        
        if (!lvar_type) {
            // לא ניתן לקבוע את הטיפוס של המשתנה השמאלי
            return i + 1;
        }
        
        // קבל את הטיפוס של הביטוי הימני
        const char* rhs_type = get_expression_type(rhs_list[i]);
        
        if (!rhs_type) {
            // לא ניתן לקבוע את הטיפוס של הביטוי הימני או שיש שגיאה טיפוסית
            return i + 1;
        }
        
        // בדוק התאמה
        if (strcmp(lvar_type, rhs_type) != 0) {
            // אם המשתנה הוא float והביטוי הוא int, זה בסדר
            if (strcmp(lvar_type, "TYPE_FLOAT") == 0 && strcmp(rhs_type, "TYPE_INT") == 0) {
                continue;
            }
            
            // אחרת, אין התאמת טיפוסים
            return i + 1;
        }
    }
    
    return 0;  // אין שגיאה
}

// AC3 Generation Implementation

char* new_temp(AC3Context* ctx) {
    char* temp = malloc(20);
    snprintf(temp, 20, "t%d", ctx->temp_count++);
    return temp;
}

char* new_label(AC3Context* ctx) {
    char* label = malloc(20);
    snprintf(label, 20, "L%d", ctx->label_count++);
    return label;
}

void generate_ac3(Node* ast_root) {
    if (!ast_root) {
        printf("// No AC3 to generate - empty AST\n");
        return;
    }
    
    printf("// Three-Address Code (AC3) \n");
    printf("// ===================================\n\n");
    
    AC3Context ctx = {0, 0};
    generate_ac3_node(ast_root, &ctx);
}

void generate_ac3_node(Node* node, AC3Context* ctx) {
    if (!node) return;
    
    if (strcmp(node->name, "PROGRAM") == 0 || strcmp(node->name, "FUNC_LIST") == 0) {
        // Process all children (function definitions and statements)
        for (int i = 0; i < node->child_count; i++) {
            generate_ac3_node(node->children[i], ctx);
        }
    }
    else if (strcmp(node->name, "FUNC_DEF") == 0 || strcmp(node->name, "FUNC_DEF_TYPED") == 0) {
        generate_ac3_function(node, ctx);
    }
    else if (strcmp(node->name, "ASSIGN") == 0 || 
             strcmp(node->name, "IF_STMT") == 0 ||
             strcmp(node->name, "WHILE") == 0 ||
             strcmp(node->name, "RETURN_VALUE") == 0 ||
             strcmp(node->name, "RETURN_EMPTY") == 0 ||
             strcmp(node->name, "CALL") == 0) {
        generate_ac3_statement(node, ctx);
    }
    else {
        // Process other nodes recursively
        for (int i = 0; i < node->child_count; i++) {
            generate_ac3_node(node->children[i], ctx);
        }
    }
}

void generate_ac3_function(Node* func_def, AC3Context* ctx) {
    if (!func_def || func_def->child_count < 2) return;
    
    Node* func_name = func_def->children[0];
    Node* params_or_body = func_def->children[1];
    Node* body = NULL;
    
    // Extract function name
    char* actual_func_name = "unknown";
    if (func_name && strcmp(func_name->name, "ID") == 0 && func_name->child_count > 0) {
        actual_func_name = func_name->children[0]->name;
    }
    
    printf("// Function: %s\n", actual_func_name);
    printf("%s:\n", actual_func_name);
    
    // Handle different function definition structures
    if (strcmp(func_def->name, "FUNC_DEF") == 0) {
        // Untyped function: func_name, params, body
        if (func_def->child_count >= 3) {
            Node* params = func_def->children[1];
            body = func_def->children[2];
            
            // Handle parameters
            generate_ac3_params(params, ctx);
        }
    } else if (strcmp(func_def->name, "FUNC_DEF_TYPED") == 0) {
        // Typed function: temporarily skip parameter processing to avoid hang
        if (func_def->child_count >= 3) {
            body = func_def->children[func_def->child_count - 1];
            // Skip parameters for now
        }
    } else {
        // Simple structure - assume it's body
        body = params_or_body;
    }
    
    // Generate body
    if (body) {
        generate_ac3_node(body, ctx);
    }
    
    printf("    return\n\n");
}

void generate_ac3_params(Node* params, AC3Context* ctx) {
    if (!params) return;
    
    if (strcmp(params->name, "PARAM_LIST") == 0) {
        for (int i = 0; i < params->child_count; i++) {
            generate_ac3_params(params->children[i], ctx);
        }
    } else if (strcmp(params->name, "PARAM") == 0 && params->child_count >= 2) {
        Node* param_id = params->children[1];
        if (param_id && strcmp(param_id->name, "ID") == 0 && param_id->child_count > 0) {
            printf("    param %s\n", param_id->children[0]->name);
        }
    } else if (strcmp(params->name, "PARAM_DEFAULT") == 0 && params->child_count >= 2) {
        Node* param_id = params->children[1];
        if (param_id && strcmp(param_id->name, "ID") == 0 && param_id->child_count > 0) {
            printf("    param %s\n", param_id->children[0]->name);
        }
    }
}

void generate_ac3_statement(Node* stmt, AC3Context* ctx) {
    if (!stmt) return;
    
    if (strcmp(stmt->name, "ASSIGN") == 0) {
        if (stmt->child_count >= 2) {
            Node* lhs = stmt->children[0];
            Node* rhs = stmt->children[1];
            
            // Extract variable name from LHS_LIST structure
            char* var_name = NULL;
            if (lhs && strcmp(lhs->name, "LHS_LIST") == 0 && lhs->child_count > 0) {
                Node* var_node = lhs->children[0];
                if (var_node && strcmp(var_node->name, "ID") == 0 && var_node->child_count > 0) {
                    var_name = var_node->children[0]->name;
                }
            }
            
            // Extract expression from RHS_LIST structure
            Node* expr = NULL;
            if (rhs && strcmp(rhs->name, "RHS_LIST") == 0 && rhs->child_count > 0) {
                expr = rhs->children[0];
            }
            
            if (var_name && expr) {
                char* result = NULL;
                generate_ac3_expression(expr, ctx, &result);
                
                if (result) {
                    printf("    %s = %s\n", var_name, result);
                    free(result);
                }
            }
        }
    }
    else if (strcmp(stmt->name, "IF_STMT") == 0) {
        generate_ac3_control_flow(stmt, ctx);
    }
    else if (strcmp(stmt->name, "WHILE") == 0) {
        generate_ac3_control_flow(stmt, ctx);
    }
    else if (strcmp(stmt->name, "RETURN_VALUE") == 0) {
        if (stmt->child_count > 0 && stmt->children[0]) {
            char* result = NULL;
            generate_ac3_expression(stmt->children[0], ctx, &result);
            if (result) {
                printf("    return %s\n", result);
                free(result);
            }
        } else {
            printf("    return\n");
        }
    }
    else if (strcmp(stmt->name, "RETURN_EMPTY") == 0) {
        printf("    return\n");
    }
    else if (strcmp(stmt->name, "CALL") == 0) {
        char* result = NULL;
        generate_ac3_expression(stmt, ctx, &result);
        if (result) {
            printf("    call %s\n", result);
            free(result);
        }
    }
    else if (strcmp(stmt->name, "BLOCK") == 0) {
        for (int i = 0; i < stmt->child_count; i++) {
            generate_ac3_statement(stmt->children[i], ctx);
        }
    }
    else if (strcmp(stmt->name, "STMTS") == 0) {
        for (int i = 0; i < stmt->child_count; i++) {
            generate_ac3_statement(stmt->children[i], ctx);
        }
    }
    else if (strcmp(stmt->name, "SINGLE_STMT_SUITE") == 0) {
        // Handle single statement suites (used in if/else without braces)
        if (stmt->child_count > 0 && stmt->children[0]) {
            generate_ac3_statement(stmt->children[0], ctx);
        }
    }
    else if (strcmp(stmt->name, "DECLS") == 0 || 
             strcmp(stmt->name, "DECLS_EMPTY") == 0 ||
             strcmp(stmt->name, "VAR_DECL") == 0) {
        // Skip declarations in AC3 generation
        return;
    }
}

void generate_ac3_expression(Node* expr, AC3Context* ctx, char** result) {
    if (!expr || !result) return;
    
    // Handle literals
    if (strcmp(expr->name, "LIT_INT") == 0 ||
        strcmp(expr->name, "LIT_FLOAT") == 0 ||
        strcmp(expr->name, "LIT_STR") == 0 ||
        strcmp(expr->name, "LIT_BOOL") == 0) {
        if (expr->child_count > 0 && expr->children[0]) {
            *result = strdup(expr->children[0]->name);
        } else {
            *result = strdup("0");
        }
        return;
    }
    
    // Handle variable references
    if (strcmp(expr->name, "VAR_USE") == 0) {
        if (expr->child_count > 0 && expr->children[0] && 
            strcmp(expr->children[0]->name, "ID") == 0 &&
            expr->children[0]->child_count > 0) {
            *result = strdup(expr->children[0]->children[0]->name);
        } else {
            *result = strdup("unknown_var");
        }
        return;
    }
    
    // Handle direct ID nodes
    if (strcmp(expr->name, "ID") == 0) {
        if (expr->child_count > 0) {
            *result = strdup(expr->children[0]->name);
        } else {
            *result = strdup(expr->name);
        }
        return;
    }
    
    // Handle short-circuit operators
    if (strcmp(expr->name, "AND") == 0 || strcmp(expr->name, "OR") == 0) {
        char* true_label = new_label(ctx);
        char* false_label = new_label(ctx);
        char* end_label = new_label(ctx);
        
        *result = new_temp(ctx);
        
        generate_ac3_short_circuit(expr, ctx, result, true_label, false_label);
        
        printf("%s:\n", true_label);
        printf("    %s = 1\n", *result);
        printf("    goto %s\n", end_label);
        printf("%s:\n", false_label);
        printf("    %s = 0\n", *result);
        printf("%s:\n", end_label);
        
        free(true_label);
        free(false_label);
        free(end_label);
        return;
    }
    
    // Handle binary operators - check for operator symbols
    if (expr->child_count == 2 && 
        (strcmp(expr->name, "+") == 0 || strcmp(expr->name, "-") == 0 ||
         strcmp(expr->name, "*") == 0 || strcmp(expr->name, "/") == 0 ||
         strcmp(expr->name, "**") == 0 || strcmp(expr->name, "<") == 0 ||
         strcmp(expr->name, ">") == 0 || strcmp(expr->name, "<=") == 0 ||
         strcmp(expr->name, ">=") == 0 || strcmp(expr->name, "==") == 0 ||
         strcmp(expr->name, "!=") == 0 || strcmp(expr->name, "PLUS") == 0 ||
         strcmp(expr->name, "MINUS") == 0 || strcmp(expr->name, "TIMES") == 0 ||
         strcmp(expr->name, "DIVIDE") == 0 || strcmp(expr->name, "POW") == 0 ||
         strcmp(expr->name, "LT") == 0 || strcmp(expr->name, "GT") == 0 ||
         strcmp(expr->name, "LE") == 0 || strcmp(expr->name, "GE") == 0 ||
         strcmp(expr->name, "EQ") == 0 || strcmp(expr->name, "NE") == 0)) {
        
        char* left = NULL;
        char* right = NULL;
        
        generate_ac3_expression(expr->children[0], ctx, &left);
        generate_ac3_expression(expr->children[1], ctx, &right);
        
        if (left && right) {
            *result = new_temp(ctx);
            
            // Use the operator as is if it's already a symbol, otherwise map it
            const char* op = expr->name;
            if (strcmp(op, "PLUS") == 0) op = "+";
            else if (strcmp(op, "MINUS") == 0) op = "-";
            else if (strcmp(op, "TIMES") == 0) op = "*";
            else if (strcmp(op, "DIVIDE") == 0) op = "/";
            else if (strcmp(op, "POW") == 0) op = "**";
            else if (strcmp(op, "LT") == 0) op = "<";
            else if (strcmp(op, "GT") == 0) op = ">";
            else if (strcmp(op, "LE") == 0) op = "<=";
            else if (strcmp(op, "GE") == 0) op = ">=";
            else if (strcmp(op, "EQ") == 0) op = "==";
            else if (strcmp(op, "NE") == 0) op = "!=";
            
            printf("    %s = %s %s %s\n", *result, left, op, right);
        }
        
        if (left) free(left);
        if (right) free(right);
        return;
    }
    
    // Handle unary operators
    if (expr->child_count == 1) {
        char* operand = NULL;
        generate_ac3_expression(expr->children[0], ctx, &operand);
        
        if (operand) {
            *result = new_temp(ctx);
            
            if (strcmp(expr->name, "NOT") == 0) {
                printf("    %s = !%s\n", *result, operand);
            } else if (strcmp(expr->name, "UMINUS") == 0) {
                printf("    %s = -%s\n", *result, operand);
            }
            
            free(operand);
        }
        return;
    }
    
    // Handle function calls
    if (strcmp(expr->name, "CALL") == 0 && expr->child_count >= 1) {
        Node* func_name = expr->children[0];
        *result = new_temp(ctx);
        
        // Get function name
        char* actual_func_name = "unknown";
        if (func_name && strcmp(func_name->name, "ID") == 0 && func_name->child_count > 0) {
            actual_func_name = func_name->children[0]->name;
        }
        
        // Handle arguments - they start from children[1]
        for (int i = 1; i < expr->child_count; i++) {
            char* arg_result = NULL;
            generate_ac3_expression(expr->children[i], ctx, &arg_result);
            if (arg_result) {
                printf("    param %s\n", arg_result);
                free(arg_result);
            }
        }
        
        printf("    %s = call %s\n", *result, actual_func_name);
        return;
    }
    
    *result = strdup("unknown");
}

void generate_ac3_short_circuit(Node* expr, AC3Context* ctx, char** result, char* true_label, char* false_label) {
    if (!expr) return;
    
    if (strcmp(expr->name, "AND") == 0 && expr->child_count == 2) {
        char* left_result = NULL;
        generate_ac3_expression(expr->children[0], ctx, &left_result);
        
        if (left_result) {
            printf("    if %s == 0 goto %s\n", left_result, false_label);
            free(left_result);
        }
        
        char* right_result = NULL;
        generate_ac3_expression(expr->children[1], ctx, &right_result);
        
        if (right_result) {
            printf("    if %s == 0 goto %s\n", right_result, false_label);
            printf("    goto %s\n", true_label);
            free(right_result);
        }
    }
    else if (strcmp(expr->name, "OR") == 0 && expr->child_count == 2) {
        char* left_result = NULL;
        generate_ac3_expression(expr->children[0], ctx, &left_result);
        
        if (left_result) {
            printf("    if %s != 0 goto %s\n", left_result, true_label);
            free(left_result);
        }
        
        char* right_result = NULL;
        generate_ac3_expression(expr->children[1], ctx, &right_result);
        
        if (right_result) {
            printf("    if %s != 0 goto %s\n", right_result, true_label);
            printf("    goto %s\n", false_label);
            free(right_result);
        }
    }
}

void generate_ac3_control_flow(Node* stmt, AC3Context* ctx) {
    if (!stmt) return;
    
    if (strcmp(stmt->name, "IF_STMT") == 0) {
        char* else_label = new_label(ctx);
        char* end_label = new_label(ctx);
        
        // Generate condition
        if (stmt->child_count > 0 && stmt->children[0]) {
            char* cond_result = NULL;
            generate_ac3_expression(stmt->children[0], ctx, &cond_result);
            if (cond_result) {
                printf("    if %s == 0 goto %s\n", cond_result, else_label);
                free(cond_result);
            }
        }
        
        // Generate then block
        if (stmt->child_count > 1 && stmt->children[1]) {
            generate_ac3_statement(stmt->children[1], ctx);
        }
        
        printf("    goto %s\n", end_label);
        printf("%s:\n", else_label);
        
        // Check for elif chain (children[2]) - skip if empty
        if (stmt->child_count > 2 && stmt->children[2] && 
            strcmp(stmt->children[2]->name, "ELIF_EMPTY") != 0) {
            generate_ac3_statement(stmt->children[2], ctx);
        }
        
        // Generate else block if present (children[3])
        if (stmt->child_count > 3 && stmt->children[3] && 
            strcmp(stmt->children[3]->name, "ELSE_EMPTY") != 0) {
            Node* else_node = stmt->children[3];
            // ELSE node contains the actual statement/block as its first child
            if (else_node->child_count > 0 && else_node->children[0]) {
                generate_ac3_statement(else_node->children[0], ctx);
            }
        }
        
        printf("%s:\n", end_label);
        
        free(else_label);
        free(end_label);
    }
    else if (strcmp(stmt->name, "WHILE") == 0) {
        char* loop_start = new_label(ctx);
        char* loop_end = new_label(ctx);
        
        printf("%s:\n", loop_start);
        
        // Generate condition
        if (stmt->child_count > 0 && stmt->children[0]) {
            char* cond_result = NULL;
            generate_ac3_expression(stmt->children[0], ctx, &cond_result);
            if (cond_result) {
                printf("    if %s == 0 goto %s\n", cond_result, loop_end);
                free(cond_result);
            }
        }
        
        // Generate body
        if (stmt->child_count > 1 && stmt->children[1]) {
            generate_ac3_statement(stmt->children[1], ctx);
        }
        
        printf("    goto %s\n", loop_start);
        printf("%s:\n", loop_end);
        
        free(loop_start);
        free(loop_end);
    }
}
