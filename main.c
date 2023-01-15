#include "9cc.h"
char *user_input;
Token *token;

int main(int argc, char **argv) {
    if (argc != 2) {
        error("incorrect number of arguments");
        return 1;
    }
    
    token = tokenize(argv[1]);
    Node *node = expr();

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    codegen(node);

    printf("    pop rax\n");
    printf("    ret\n");
    return 0;
}
