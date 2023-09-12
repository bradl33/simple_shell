#include "shell.h"

#define MAX_TOKENS 100

int main(int argc, char **argv) {
    char *lineptr = NULL;
    char *tokens[MAX_TOKENS] = {NULL};
    size_t n, command_num;
    int i, status, num_tokens;

    n = command_num = status = 0;

    (void)argc;
    (void)argv;

    while (1) {
        command_num++;
        prompt();
        my_getline(&lineptr, &n, status);
        num_tokens = tokenize_input(lineptr, tokens);

        if (num_tokens > 0) {
            if (is_builtin_command(tokens[0])) {
                execute_builtin_command(tokens);
            } else {
                execute_non_builtin_command(tokens);
            }
        }

        
        for (i = 0; i < num_tokens; i++) {
            if (tokens[i] != NULL) {
                free(tokens[i]);
                tokens[i] = NULL;
            }
        }
    
    }

    
    for (i = 0; i < num_tokens; i++) {
        if (tokens[i] != NULL) {
            free(tokens[i]);
            tokens[i] = NULL;
        }
    }
    
    free(lineptr);
    
    return 0;
}
