#include "shell.h"

#define MAX_TOKENS 100

int main(int argc, char **argv) {
    char *lineptr = NULL;
    char *tokens[MAX_TOKENS] = {NULL};
    size_t n, command_num;
    int i, status = 0, num_tokens;

    n = command_num = 0;

    (void)argc;
    (void)argv;

    while (1) {
        command_num++;
        prompt();
        my_getline(&lineptr, &n, status);
        num_tokens = tokenize_input(lineptr, tokens);

        if (num_tokens > 0) {
            if (strcmp(tokens[0], "exit") == 0) {
                break;
            }
            execute_command(tokens);
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
