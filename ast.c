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
