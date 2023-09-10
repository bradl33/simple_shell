#include "shell.h"

#define MAX_TOKENS 100

int tokenize_input(char *lineptr, char *tokens[]) {
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;

    token = strtok(lineptr, delim);
    while(token != NULL && num_tokens < MAX_TOKENS) {
        tokens[num_tokens] = strdup(token);
        if (tokens[num_tokens] == NULL) {
            perror("error: memory allocation failed!");
            exit(1);
        }
        num_tokens++;
        token = strtok(NULL, delim);
    }

    return num_tokens;
}