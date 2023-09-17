#include "shell.h"

#define DEFAULT_EXIT_CODE 0
#define INVALID_ARGS_EXIT_CODE 2
#define MAX_EXIT_TOKENS 2

int exit_builtin(char **tokens_arr, int token_count) {
    int exit_code = DEFAULT_EXIT_CODE;
    char *endptr = NULL;
    long int exit_long;
    
    if(token_count > 1) {
        exit_long = strtol(tokens_arr[1], &endptr, 10);

        if (*endptr == '\0' && exit_long >= INT_MIN && exit_long <= INT_MAX) {
            exit_code = (int)exit_long;
        } else {
            exit_code = INVALID_ARGS_EXIT_CODE;
        }
    }
    
    return (exit_code);
}

/* TODO: attempt to make this work */
int handle_exit(char **tokens_arr, int token_count, char *line, char *program_name, char *command_name, int *exit_code, bool *exiting) {
    if (token_count > 2 && atoi(tokens_arr[1]) != 0) {
        fprintf(stderr, "%s\n", command_name);
        fprintf(stderr, "%s: %s: too many arguments\n", program_name, command_name);

        free_tokens_arr(tokens_arr, token_count, line);
        line = NULL;

        return (1);
    } else {
        *exit_code = exit_builtin(tokens_arr, token_count);
        *exiting = true; /* exit is ready. Will be executed after free(s)*/
    }
    return (*exit_code);
}

/*
int main (int argc, char *argv[]) {
    if(argc > MAX_EXIT_TOKENS) {
        printf("Too many arguments. Usage: %s [exit_code]\n", argv[0]);
        return (1);
    }

    exit_builtin(argv);

    return (0);
}
*/
