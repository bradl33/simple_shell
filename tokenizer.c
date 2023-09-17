#include "shell.h"

char **tokenize_line(char *line, int *token_count) {
    char **tokens_arr = NULL;
    char *token;

    *token_count = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        tokens_arr = (char **)realloc(tokens_arr, (*token_count + 2) * sizeof(char *));
        
        if (tokens_arr == NULL) {
            perror("memory allocation error.");
            exit(EXIT_FAILURE);
        }
        
        tokens_arr[*token_count] = strdup(token);

        (*token_count)++;
        token = strtok(NULL, " \n");
    }
    tokens_arr[*token_count] = NULL;
    return (tokens_arr);
}

#if 0
char **tokenize_line(char *line, int *token_count) {
    char **tokens_arr = NULL;
    char **new_tokens_arr = NULL;
    char *token;
    int i;

    *token_count = 0;

    token = strtok(line, " \n");
    while (token != NULL) {
        new_tokens_arr = (char **)realloc(tokens_arr, (*token_count + 1) * sizeof(char *));
        if (new_tokens_arr == NULL) {
            perror("memory allocation error.");
            if (tokens_arr != NULL) {
                for (i = 0; i < *token_count; i++) {
                    free(tokens_arr[i]);
                }
                free(tokens_arr);
            }
            exit(EXIT_FAILURE);
        }
        tokens_arr = new_tokens_arr;

        tokens_arr[*token_count] = strdup(token);
        if (tokens_arr[*token_count] == NULL) {
            perror("memory allocation error.");
            for (i = 0; i <= *token_count; i++) {
                free(tokens_arr[i]);
            }
            free(tokens_arr);
            exit(EXIT_FAILURE);
        }

        (*token_count)++;
        token = strtok(NULL, " \n");
    }
    return tokens_arr;
}
#endif
