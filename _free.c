#include "shell.h"

void free_tokens_arr(char **tokens_arr, int token_count, char *line) {
    int i;

    for (i = 0; i < token_count; i++) {
        free(tokens_arr[i]);
    }
    free(tokens_arr);
    free(line);
}