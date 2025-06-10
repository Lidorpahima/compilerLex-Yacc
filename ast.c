#include "ast.h"

// Global variables
scope_t* current_scope = NULL;
scope_t* global_scope = NULL;
int line_number = 1;
int error_count = 0;
int main_count = 0;

// AC3 code generation variables
int temp_counter = 0;
int label_counter = 0;

// Create a new AST node
node_t* make_node(node_type_t type, const char* value) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    node->type = type;
    node->data_type = TYPE_VOID;
    node->value = value ? strdup(value) : NULL;
    node->name = NULL;
    
    node->left = NULL;
    node->right = NULL;
    node->condition = NULL;
    node->if_body = NULL;
    node->else_body = NULL;
    node->params = NULL;
    node->body = NULL;
    node->args = NULL;
    node->next = NULL;
    
    node->has_default = false;
    node->default_value = NULL;
    
    node->line_number = line_number;
    
    return node;
}

// Free AST node and its children
void free_node(node_t* node) {
    if (!node) return;
    
    free(node->value);
    free(node->name);
    
    free_node(node->left);
    free_node(node->right);
    free_node(node->condition);
    free_node(node->if_body);
    free_node(node->else_body);
    free_node(node->params);
    free_node(node->body);
    free_node(node->args);
    free_node(node->next);
    free_node(node->default_value);
    
    free(node);
}

// Print AST with indentation and colors
void print_ast(node_t* node, int indent) {
    if (!node) return;
    
    // Print indentation with tree structure
    for (int i = 0; i < indent; i++) {
        if (i == indent - 1) {
            printf("├── ");
        } else {
            printf("│   ");
        }
    }
    
    // Use colors and emojis for different node types
    switch (node->type) {
        case NODE_PROGRAM: 
            printf("🚀 \033[1;36mPROGRAM\033[0m\n"); 
            break;
        case NODE_FUNCTION: 
            printf("🔧 \033[1;32mFUNCTION\033[0m \033[1;33m%s\033[0m", node->name ? node->name : "unnamed");
            if (node->data_type != TYPE_VOID) {
                printf(" -> \033[1;35m%s\033[0m", type_to_string(node->data_type));
            }
            printf("\n");
            break;
        case NODE_PARAM: 
            printf("📝 \033[1;34mPARAM\033[0m \033[1;33m%s\033[0m", node->name ? node->name : "unnamed"); 
            if (node->data_type != TYPE_VOID) {
                printf(": \033[1;35m%s\033[0m", type_to_string(node->data_type));
            }
            printf("\n");
            break;
        case NODE_VARIABLE: 
            printf("📦 \033[1;36mVAR\033[0m \033[1;33m%s\033[0m", node->name ? node->name : "unnamed");
            if (node->data_type != TYPE_VOID) {
                printf(": \033[1;35m%s\033[0m", type_to_string(node->data_type));
            }
            printf("\n");
            break;
        case NODE_LITERAL: 
            printf("💎 \033[1;93mLIT\033[0m \033[1;37m%s\033[0m", node->value ? node->value : "null");
            if (node->data_type != TYPE_VOID) {
                printf(" (\033[1;35m%s\033[0m)", type_to_string(node->data_type));
            }
            printf("\n");
            break;
        case NODE_BINARY_OP: 
            printf("⚡ \033[1;91mOP\033[0m \033[1;37m%s\033[0m\n", node->value ? node->value : "unknown"); 
            break;
        case NODE_UNARY_OP: 
            printf("🔄 \033[1;91mUNARY\033[0m \033[1;37m%s\033[0m\n", node->value ? node->value : "unknown"); 
            break;
        case NODE_ASSIGN: 
            printf("📝 \033[1;95mASSIGN\033[0m\n"); 
            break;
        case NODE_CALL: 
            printf("📞 \033[1;92mCALL\033[0m \033[1;33m%s\033[0m\n", node->name ? node->name : "unknown"); 
            break;
        case NODE_IF: 
            printf("🔀 \033[1;94mIF\033[0m\n"); 
            break;
        case NODE_WHILE: 
            printf("🔄 \033[1;94mWHILE\033[0m\n"); 
            break;
        case NODE_RETURN: 
            printf("↩️  \033[1;93mRETURN\033[0m\n"); 
            break;
        case NODE_BLOCK: 
            printf("📋 \033[1;90mBLOCK\033[0m\n"); 
            break;
        case NODE_STRING_ACCESS: 
            printf("🔤 \033[1;96mSTRING_ACCESS\033[0m\n"); 
            break;
        case NODE_PASS: 
            printf("⏭️  \033[1;90mPASS\033[0m\n"); 
            break;
        default:
            printf("❓ \033[1;31mUNKNOWN\033[0m\n");
            break;
    }
    
    // Print children with proper tree structure
    if (node->condition) {
        print_ast(node->condition, indent + 1);
    }
    if (node->params) {
        print_ast(node->params, indent + 1);
    }
    if (node->args) {
        print_ast(node->args, indent + 1);
    }
    if (node->left) {
        print_ast(node->left, indent + 1);
    }
    if (node->right) {
        print_ast(node->right, indent + 1);
    }
    if (node->if_body) {
        print_ast(node->if_body, indent + 1);
    }
    if (node->else_body) {
        print_ast(node->else_body, indent + 1);
    }
    if (node->body) {
        print_ast(node->body, indent + 1);
    }
    if (node->next) {
        print_ast(node->next, indent);
    }
}

// Create new scope
scope_t* create_scope(scope_t* parent) {
    scope_t* scope = (scope_t*)malloc(sizeof(scope_t));
    if (!scope) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    scope->symbols = NULL;
    scope->parent = parent;
    return scope;
}

// Push new scope
void push_scope(void) {
    current_scope = create_scope(current_scope);
    if (!global_scope) {
        global_scope = current_scope;
    }
}

// Pop current scope
void pop_scope(void) {
    if (!current_scope) return;
    
    scope_t* old_scope = current_scope;
    current_scope = current_scope->parent;
    
    // Free symbols in the old scope
    symbol_t* sym = old_scope->symbols;
    while (sym) {
        symbol_t* next = sym->next;
        free(sym->name);
        free(sym);
        sym = next;
    }
    free(old_scope);
}

// Add symbol to current scope
symbol_t* add_symbol(const char* name, data_type_t type, node_t* node, bool is_function) {
    if (!current_scope) {
        push_scope();
    }
    
    // Check if symbol already exists in current scope
    symbol_t* existing = find_symbol_current_scope(name);
    if (existing) {
        return NULL; // Symbol already exists
    }
    
    symbol_t* symbol = (symbol_t*)malloc(sizeof(symbol_t));
    if (!symbol) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    symbol->name = strdup(name);
    symbol->type = type;
    symbol->node = node;
    symbol->is_function = is_function;
    symbol->param_count = 0;
    symbol->required_params = 0;
    
    if (is_function && node && node->params) {
        symbol->param_count = count_parameters(node->params);
        symbol->required_params = count_required_parameters(node->params);
    }
    
    symbol->next = current_scope->symbols;
    current_scope->symbols = symbol;
    
    return symbol;
}

// Find symbol in current scope only
symbol_t* find_symbol_current_scope(const char* name) {
    if (!current_scope) return NULL;
    
    symbol_t* sym = current_scope->symbols;
    while (sym) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

// Find symbol in all scopes
symbol_t* find_symbol(const char* name) {
    scope_t* scope = current_scope;
    while (scope) {
        symbol_t* sym = scope->symbols;
        while (sym) {
            if (strcmp(sym->name, name) == 0) {
                return sym;
            }
            sym = sym->next;
        }
        scope = scope->parent;
    }
    return NULL;
}

// Convert type to string
const char* type_to_string(data_type_t type) {
    switch (type) {
        case TYPE_VOID: return "void";
        case TYPE_INT: return "int";
        case TYPE_FLOAT: return "float";
        case TYPE_BOOL: return "bool";
        case TYPE_STRING: return "string";
        default: return "unknown";
    }
}

// Convert string to type
data_type_t string_to_type(const char* type_str) {
    if (strcmp(type_str, "int") == 0) return TYPE_INT;
    if (strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "bool") == 0) return TYPE_BOOL;
    if (strcmp(type_str, "string") == 0) return TYPE_STRING;
    return TYPE_VOID;
}

// Get expression type
data_type_t get_expression_type(node_t* expr) {
    if (!expr) return TYPE_VOID;
    
    switch (expr->type) {
        case NODE_LITERAL:
            return expr->data_type;
            
        case NODE_VARIABLE: {
            symbol_t* sym = find_symbol(expr->name);
            return sym ? sym->type : TYPE_VOID;
        }
        
        case NODE_BINARY_OP: {
            if (!expr->value) return TYPE_VOID;
            
            data_type_t left_type = get_expression_type(expr->left);
            data_type_t right_type = get_expression_type(expr->right);
            
            // Arithmetic operators
            if (strcmp(expr->value, "+") == 0 || strcmp(expr->value, "-") == 0 ||
                strcmp(expr->value, "*") == 0 || strcmp(expr->value, "/") == 0 ||
                strcmp(expr->value, "**") == 0) {
                if (left_type == TYPE_FLOAT || right_type == TYPE_FLOAT) {
                    return TYPE_FLOAT;
                }
                return TYPE_INT;
            }
            
            // Comparison operators
            if (strcmp(expr->value, ">") == 0 || strcmp(expr->value, "<") == 0 ||
                strcmp(expr->value, ">=") == 0 || strcmp(expr->value, "<=") == 0 ||
                strcmp(expr->value, "==") == 0 || strcmp(expr->value, "!=") == 0 ||
                strcmp(expr->value, "is") == 0) {
                return TYPE_BOOL;
            }
            
            // Logical operators
            if (strcmp(expr->value, "and") == 0 || strcmp(expr->value, "or") == 0) {
                return TYPE_BOOL;
            }
            
            break;
        }
        
        case NODE_UNARY_OP: {
            if (!expr->value) return TYPE_VOID;
            
            if (strcmp(expr->value, "not") == 0) {
                return TYPE_BOOL;
            }
            if (strcmp(expr->value, "-") == 0) {
                return get_expression_type(expr->left);
            }
            break;
        }
        
        case NODE_CALL: {
            symbol_t* sym = find_symbol(expr->name);
            return sym ? sym->type : TYPE_VOID;
        }
        
        case NODE_STRING_ACCESS:
            return TYPE_STRING;
            
        default:
            break;
    }
    
    return TYPE_VOID;
}

// Check if types are compatible
bool types_compatible(data_type_t expected, data_type_t actual) {
    if (expected == actual) return true;
    if (expected == TYPE_FLOAT && actual == TYPE_INT) return true;
    return false;
}

// Count parameters
int count_parameters(node_t* params) {
    if (!params) return 0;
    
    int count = 0;
    node_t* param = params;
    while (param) {
        if (param->type == NODE_PARAM) {
            count++;
        }
        param = param->next;
    }
    return count;
}

// Count required parameters (without default values)
int count_required_parameters(node_t* params) {
    if (!params) return 0;
    
    int count = 0;
    node_t* param = params;
    while (param) {
        if (param->type == NODE_PARAM && !param->has_default) {
            count++;
        }
        param = param->next;
    }
    return count;
}

// Semantic error reporting
void semantic_error(const char* msg, int line) {
    fprintf(stderr, "Semantic error on line %d: %s\n", line, msg);
    error_count++;
}

// Analyze variable declarations
void analyze_variable_declarations(node_t* decls) {
    if (!decls) return;
    
    node_t* decl = decls;
    while (decl) {
        if (decl->type == NODE_VARIABLE) {
            // Check for duplicate variable names in current scope
            if (find_symbol_current_scope(decl->name)) {
                semantic_error("Duplicate variable name in scope", decl->line_number);
            } else {
                // Add variable to symbol table
                add_symbol(decl->name, decl->data_type, decl, false);
                
                // Check initialization expression if present
                if (decl->right) {
                    analyze_expression(decl->right);
                    data_type_t init_type = get_expression_type(decl->right);
                    if (!types_compatible(decl->data_type, init_type)) {
                        semantic_error("Type mismatch in variable initialization", decl->line_number);
                    }
                }
            }
        }
        decl = decl->next;
    }
}

// Analyze program
void analyze_program(node_t* root) {
    if (!root) return;
    
    error_count = 0;
    main_count = 0;
    
    push_scope(); // Global scope
    
    // First pass: collect all function declarations
    node_t* func = root;
    while (func) {
        if (func->type == NODE_FUNCTION) {
            if (find_symbol_current_scope(func->name)) {
                semantic_error("Duplicate function definition", func->line_number);
            } else {
                add_symbol(func->name, func->data_type, func, true);
                if (strcmp(func->name, "__main__") == 0) {
                    main_count++;
                    
                    // Check __main__ constraints
                    if (func->data_type != TYPE_VOID) {
                        semantic_error("__main__ must not have a return type", func->line_number);
                    }
                    if (count_parameters(func->params) > 0) {
                        semantic_error("__main__ must not have parameters", func->line_number);
                    }
                }
            }
        }
        func = func->next;
    }
    
    // Check for __main__ function
    if (main_count == 0) {
        semantic_error("Missing __main__ function", 0);
    } else if (main_count > 1) {
        semantic_error("Multiple __main__ function definitions", 0);
    }
    
    // Second pass: analyze function bodies
    func = root;
    while (func) {
        if (func->type == NODE_FUNCTION) {
            analyze_function(func);
        }
        func = func->next;
    }
    
    pop_scope(); // Global scope
}

// Analyze function
void analyze_function(node_t* func) {
    if (!func) return;
    
    push_scope(); // Function scope
    
    // Add parameters to scope
    node_t* param = func->params;
    while (param) {
        if (param->type == NODE_PARAM) {
            if (find_symbol_current_scope(param->name)) {
                semantic_error("Duplicate parameter name", param->line_number);
            } else {
                add_symbol(param->name, param->data_type, param, false);
                
                // Check default value type
                if (param->has_default && param->default_value) {
                    data_type_t default_type = get_expression_type(param->default_value);
                    if (!types_compatible(param->data_type, default_type)) {
                        semantic_error("Default value type does not match parameter type", param->line_number);
                    }
                }
            }
        }
        param = param->next;
    }
    
    // Analyze function body
    analyze_statement(func->body);
    
    pop_scope(); // Function scope
}

// Analyze statement
void analyze_statement(node_t* stmt) {
    if (!stmt) return;
    
    switch (stmt->type) {
        case NODE_BLOCK:
            push_scope();
            // Analyze variable declarations first
            if (stmt->left) {
                analyze_variable_declarations(stmt->left);
            }
            // Then analyze statements
            analyze_statement(stmt->body);
            pop_scope();
            break;
            
        case NODE_ASSIGN: {
            analyze_expression(stmt->right);
            
            if (stmt->left && stmt->left->type == NODE_VARIABLE) {
                symbol_t* sym = find_symbol(stmt->left->name);
                if (!sym) {
                    semantic_error("Variable used before declaration", stmt->line_number);
                } else {
                    data_type_t expr_type = get_expression_type(stmt->right);
                    if (!types_compatible(sym->type, expr_type)) {
                        semantic_error("Type mismatch in assignment", stmt->line_number);
                    }
                }
            }
            break;
        }
        
        case NODE_IF:
            analyze_expression(stmt->condition);
            if (get_expression_type(stmt->condition) != TYPE_BOOL) {
                semantic_error("Condition in if statement must be boolean", stmt->line_number);
            }
            analyze_statement(stmt->if_body);
            if (stmt->else_body) {
                analyze_statement(stmt->else_body);
            }
            break;
            
        case NODE_WHILE:
            analyze_expression(stmt->condition);
            if (get_expression_type(stmt->condition) != TYPE_BOOL) {
                semantic_error("Condition in while statement must be boolean", stmt->line_number);
            }
            analyze_statement(stmt->body);
            break;
            
        case NODE_RETURN:
            if (stmt->left) {
                analyze_expression(stmt->left);
            }
            break;
            
        case NODE_CALL:
            check_function_call(stmt);
            break;
            
        default:
            break;
    }
    
    // Analyze next statement
    if (stmt->next) {
        analyze_statement(stmt->next);
    }
}

// Analyze expression
void analyze_expression(node_t* expr) {
    if (!expr) return;
    
    switch (expr->type) {
        case NODE_VARIABLE: {
            symbol_t* sym = find_symbol(expr->name);
            if (!sym) {
                semantic_error("Variable used before declaration", expr->line_number);
            }
            break;
        }
        
        case NODE_BINARY_OP:
            analyze_expression(expr->left);
            analyze_expression(expr->right);
            
            if (expr->value) {
                data_type_t left_type = get_expression_type(expr->left);
                data_type_t right_type = get_expression_type(expr->right);
                
                // Check operator compatibility
                if (strcmp(expr->value, "+") == 0 || strcmp(expr->value, "-") == 0 ||
                    strcmp(expr->value, "*") == 0 || strcmp(expr->value, "/") == 0 ||
                    strcmp(expr->value, "**") == 0) {
                    if ((left_type != TYPE_INT && left_type != TYPE_FLOAT) ||
                        (right_type != TYPE_INT && right_type != TYPE_FLOAT)) {
                        semantic_error("Arithmetic operators require numeric operands", expr->line_number);
                    }
                } else if (strcmp(expr->value, "and") == 0 || strcmp(expr->value, "or") == 0) {
                    if (left_type != TYPE_BOOL || right_type != TYPE_BOOL) {
                        semantic_error("Logical operators require boolean operands", expr->line_number);
                    }
                } else if (strcmp(expr->value, "==") == 0 || strcmp(expr->value, "!=") == 0) {
                    if (left_type != right_type) {
                        semantic_error("Equality operators require same types", expr->line_number);
                    }
                } else if (strcmp(expr->value, ">") == 0 || strcmp(expr->value, "<") == 0 ||
                          strcmp(expr->value, ">=") == 0 || strcmp(expr->value, "<=") == 0) {
                    if ((left_type != TYPE_INT && left_type != TYPE_FLOAT) ||
                        (right_type != TYPE_INT && right_type != TYPE_FLOAT)) {
                        semantic_error("Comparison operators require numeric operands", expr->line_number);
                    }
                }
            }
            break;
            
        case NODE_UNARY_OP:
            analyze_expression(expr->left);
            
            if (expr->value) {
                data_type_t operand_type = get_expression_type(expr->left);
                
                if (strcmp(expr->value, "not") == 0) {
                    if (operand_type != TYPE_BOOL) {
                        semantic_error("'not' operator requires boolean operand", expr->line_number);
                    }
                } else if (strcmp(expr->value, "-") == 0) {
                    if (operand_type != TYPE_INT && operand_type != TYPE_FLOAT) {
                        semantic_error("Unary minus requires numeric operand", expr->line_number);
                    }
                }
            }
            break;
            
        case NODE_CALL:
            check_function_call(expr);
            break;
            
        case NODE_STRING_ACCESS: {
            // Check that variable is string type
            if (expr->left && expr->left->type == NODE_VARIABLE) {
                symbol_t* sym = find_symbol(expr->left->name);
                if (!sym) {
                    semantic_error("Variable used before declaration", expr->line_number);
                } else if (sym->type != TYPE_STRING) {
                    semantic_error("String access operator can only be used with string variables", expr->line_number);
                }
            }
            
            // Check that index is integer
            if (expr->right) {
                analyze_expression(expr->right);
                if (get_expression_type(expr->right) != TYPE_INT) {
                    semantic_error("String index must be integer", expr->line_number);
                }
            }
            break;
        }
        
        default:
            break;
    }
}

// Check function call
bool check_function_call(node_t* call) {
    if (!call || !call->name) return false;
    
    symbol_t* func_sym = find_symbol(call->name);
    if (!func_sym) {
        semantic_error("Function called before declaration", call->line_number);
        return false;
    }
    
    if (!func_sym->is_function) {
        semantic_error("Attempting to call non-function", call->line_number);
        return false;
    }
    
    // Count arguments
    int arg_count = 0;
    node_t* arg = call->args;
    while (arg) {
        arg_count++;
        analyze_expression(arg);
        arg = arg->next;
    }
    
    // Check argument count
    if (arg_count > func_sym->param_count) {
        semantic_error("Too many arguments in function call", call->line_number);
        return false;
    }
    
    if (arg_count < func_sym->required_params) {
        semantic_error("Too few arguments in function call", call->line_number);
        return false;
    }
    
    // Check argument types
    node_t* param = func_sym->node->params;
    arg = call->args;
    int i = 0;
    
    while (param && arg && i < arg_count) {
        if (param->type == NODE_PARAM) {
            data_type_t param_type = param->data_type;
            data_type_t arg_type = get_expression_type(arg);
            
            if (!types_compatible(param_type, arg_type)) {
                semantic_error("Argument type does not match parameter type", call->line_number);
                return false;
            }
            i++;
        }
        param = param->next;
        arg = arg->next;
    }
    
    return true;
}

// AC3 code generation functions
char* generate_new_temp(void) {
    char* temp = (char*)malloc(10);
    sprintf(temp, "t%d", temp_counter++);
    return temp;
}

char* generate_new_label(void) {
    char* label = (char*)malloc(10);
    sprintf(label, "L%d", label_counter++);
    return label;
}

int calculate_frame_size(node_t* func) {
    // Basic frame size calculation - can be enhanced
    int param_count = count_parameters(func->params);
    return 20 + param_count * 4; // Base + parameters
}

void generate_ac3_code(node_t* root) {
    if (!root) return;
    
    temp_counter = 0;
    label_counter = 1; // Start from L1
    
    node_t* func = root;
    while (func) {
        if (func->type == NODE_FUNCTION) {
            generate_function_ac3(func);
        }
        func = func->next;
    }
}

void generate_function_ac3(node_t* func) {
    if (!func) return;
    
    // Reset temp counter for each function
    temp_counter = 0;
    
    // Convert __main__ to main for AC3
    char* func_name = strcmp(func->name, "__main__") == 0 ? "main" : func->name;
    
    printf("%s:\n", func_name);
    
    int frame_size = calculate_frame_size(func);
    printf("BeginFunc %d\n", frame_size);
    
    // Generate code for function body
    if (func->body) {
        generate_statement_ac3(func->body);
    }
    
    printf("EndFunc\n");
}

void generate_statement_ac3(node_t* stmt) {
    if (!stmt) return;
    
    switch (stmt->type) {
        case NODE_BLOCK:
            // Generate variable declarations
            if (stmt->left) {
                // Variable declarations are handled implicitly
            }
            // Generate statements
            if (stmt->body) {
                generate_statement_ac3(stmt->body);
            }
            break;
            
        case NODE_ASSIGN: {
            char* rhs = generate_expression_ac3(stmt->right);
            if (stmt->left && stmt->left->type == NODE_VARIABLE) {
                printf("%s = %s\n", stmt->left->name, rhs);
            }
            free(rhs);
            break;
        }
        
        case NODE_IF: {
            char* true_label = generate_new_label();
            char* false_label = generate_new_label();
            char* end_label = generate_new_label();
            
            // Generate condition directly in if statement
            char* cond_str = generate_condition_ac3(stmt->condition);
            printf("if %s Goto %s\n", cond_str, true_label);
            printf("Goto %s\n", false_label);
            
            printf(" %s: ", true_label);
            if (stmt->if_body) {
                generate_statement_ac3(stmt->if_body);
            }
            
            if (stmt->else_body) {
                printf("Goto %s\n", end_label);
                printf(" %s: ", false_label);
                generate_statement_ac3(stmt->else_body);
                printf(" %s: ", end_label);
            } else {
                printf(" %s: ", false_label);
            }
            
            free(cond_str);
            free(true_label);
            free(false_label);
            free(end_label);
            break;
        }
        
        case NODE_WHILE: {
            char* loop_label = generate_new_label();
            char* body_label = generate_new_label();
            char* end_label = generate_new_label();
            
            printf("%s: ", loop_label);
            char* cond_str = generate_condition_ac3(stmt->condition);
            printf("if %s Goto %s\n", cond_str, body_label);
            printf("Goto %s\n", end_label);
            
            printf(" %s: ", body_label);
            if (stmt->body) {
                generate_statement_ac3(stmt->body);
            }
            printf("Goto %s\n", loop_label);
            
            printf("%s: ", end_label);
            
            free(cond_str);
            free(loop_label);
            free(body_label);
            free(end_label);
            break;
        }
        
        case NODE_RETURN:
            if (stmt->left) {
                char* ret_val = generate_expression_ac3(stmt->left);
                printf("Return %s\n", ret_val);
                free(ret_val);
            } else {
                printf("Return\n");
            }
            break;
            
        case NODE_CALL: {
            // Handle function call arguments
            node_t* arg = stmt->args;
            int param_size = 0;
            
            while (arg) {
                char* arg_val = generate_expression_ac3(arg);
                printf("PushParam %s\n", arg_val);
                param_size += 8; // Assume 8 bytes per parameter
                free(arg_val);
                arg = arg->next;
            }
            
            char* temp = generate_new_temp();
            printf("%s = LCall %s\n", temp, stmt->name);
            
            if (param_size > 0) {
                printf("PopParams %d\n", param_size);
            }
            
            free(temp);
            break;
        }
        
        default:
            break;
    }
    
    // Process next statement
    if (stmt->next) {
        generate_statement_ac3(stmt->next);
    }
}

char* generate_condition_ac3(node_t* expr) {
    if (!expr) return strdup("0");
    
    if (expr->type == NODE_BINARY_OP && expr->value) {
        // For comparison operators, generate direct condition
        if (strcmp(expr->value, "==") == 0 || strcmp(expr->value, "!=") == 0 ||
            strcmp(expr->value, ">") == 0 || strcmp(expr->value, "<") == 0 ||
            strcmp(expr->value, ">=") == 0 || strcmp(expr->value, "<=") == 0) {
            
            // Handle left operand
            char* left;
            if (expr->left->type == NODE_VARIABLE) {
                left = strdup(expr->left->name);
            } else {
                left = generate_expression_ac3(expr->left);
            }
            
            // Handle right operand - keep literals direct
            char* right;
            if (expr->right->type == NODE_LITERAL) {
                right = strdup(expr->right->value);
            } else if (expr->right->type == NODE_VARIABLE) {
                right = strdup(expr->right->name);
            } else {
                right = generate_expression_ac3(expr->right);
            }
            
            char* result = malloc(strlen(left) + strlen(right) + strlen(expr->value) + 5);
            sprintf(result, "%s %s %s", left, expr->value, right);
            
            free(left);
            free(right);
            return result;
        }
    }
    
    // For other expressions, generate normally
    return generate_expression_ac3(expr);
}

char* generate_expression_ac3(node_t* expr) {
    if (!expr) return strdup("0");
    
    switch (expr->type) {
        case NODE_LITERAL: {
            char* temp = generate_new_temp();
            printf("%s = %s\n", temp, expr->value ? expr->value : "0");
            return temp;
        }
            
        case NODE_VARIABLE:
            return strdup(expr->name ? expr->name : "unknown");
            
        case NODE_BINARY_OP: {
            if (!expr->value) return strdup("0");
            
            // Handle short-circuit evaluation for AND and OR
            if (strcmp(expr->value, "and") == 0) {
                char* left = generate_expression_ac3(expr->left);
                char* temp1 = generate_new_temp();
                char* true_label = generate_new_label();
                char* false_label = generate_new_label();
                char* end_label = generate_new_label();
                
                printf("%s = %s\n", temp1, left);
                printf("if %s Goto %s\n", temp1, true_label);
                printf("Goto %s\n", false_label);
                
                printf(" %s: ", true_label);
                char* right = generate_expression_ac3(expr->right);
                printf("%s = %s\n", temp1, right);
                printf("Goto %s\n", end_label);
                
                printf(" %s: %s = 0\n", false_label, temp1);
                printf(" %s: ", end_label);
                
                free(left);
                free(right);
                free(true_label);
                free(false_label);
                free(end_label);
                return temp1;
            }
            
            if (strcmp(expr->value, "or") == 0) {
                char* left = generate_expression_ac3(expr->left);
                char* temp1 = generate_new_temp();
                char* true_label = generate_new_label();
                char* false_label = generate_new_label();
                char* end_label = generate_new_label();
                
                printf("%s = %s\n", temp1, left);
                printf("if %s Goto %s\n", temp1, true_label);
                printf("Goto %s\n", false_label);
                
                printf(" %s: %s = 1\n", true_label, temp1);
                printf("Goto %s\n", end_label);
                
                printf(" %s: ", false_label);
                char* right = generate_expression_ac3(expr->right);
                printf("%s = %s\n", temp1, right);
                
                printf(" %s: ", end_label);
                
                free(left);
                free(right);
                free(true_label);
                free(false_label);
                free(end_label);
                return temp1;
            }
            
            // Regular binary operations
            char* left = generate_expression_ac3(expr->left);
            char* right = generate_expression_ac3(expr->right);
            char* temp = generate_new_temp();
            
            printf("%s = %s %s %s\n", temp, left, expr->value, right);
            
            free(left);
            free(right);
            return temp;
        }
        
        case NODE_UNARY_OP: {
            char* operand = generate_expression_ac3(expr->left);
            char* temp = generate_new_temp();
            
            if (strcmp(expr->value, "not") == 0) {
                printf("%s = !%s\n", temp, operand);
            } else if (strcmp(expr->value, "-") == 0) {
                printf("%s = -%s\n", temp, operand);
            }
            
            free(operand);
            return temp;
        }
        
        case NODE_CALL: {
            // Handle function call arguments
            node_t* arg = expr->args;
            int param_size = 0;
            
            while (arg) {
                char* arg_val = generate_expression_ac3(arg);
                printf("PushParam %s\n", arg_val);
                param_size += 8; // Assume 8 bytes per parameter
                free(arg_val);
                arg = arg->next;
            }
            
            char* temp = generate_new_temp();
            printf("%s = LCall %s\n", temp, expr->name);
            
            if (param_size > 0) {
                printf("PopParams %d\n", param_size);
            }
            
            return temp;
        }
        
        default:
            return strdup("0");
    }
}