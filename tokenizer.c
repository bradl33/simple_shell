#include "shell.h"

char **tokenize_line(char *line, int *token_count) {
    char **tokens_arr = NULL, **new_tokens_arr = NULL;
    char *token;
    int i;

    *token_count = 0;

    token = strtok(line, " \n");
    
    while (token != NULL) {
        new_tokens_arr = (char **)malloc((*token_count + 2) * sizeof(char *));
        
        if (new_tokens_arr == NULL) {
            perror("memory allocation error.");
            exit(EXIT_FAILURE);
        }

        if(tokens_arr != NULL) {
            for(i = 0; i < *token_count; i++)
                new_tokens_arr[i] = tokens_arr[i];
            free(tokens_arr);
        }
        
        new_tokens_arr[*token_count] = strdup(token);
        /* new_tokens_arr[*token_count + 1] = NULL; */

        tokens_arr = new_tokens_arr;
        tokens_arr[*token_count + 1] = NULL;
        (*token_count)++;
        token = strtok(NULL, " \n");
    }
    return (tokens_arr);
}

#if 0
int main() {
    char line[BUFFER_SIZE];
    int token_count;
    char **tokens_arr;
    int i;
    size_t line_length;

    printf("Enter a line of text: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        perror("Input error");
        return EXIT_FAILURE;
    }

    line_length = strlen(line);
    if (line_length > 0 && line[line_length - 1] == '\n') {
        line[line_length - 1] = '\0';
    }

    tokens_arr = tokenize_line(line, &token_count);

    printf("Tokenized Line:\n");
    for (i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i, tokens_arr[i]);
    }

    for (i = 0; i < token_count; i++) {
        free(tokens_arr[i]);
    }
    free(tokens_arr);

    return EXIT_SUCCESS;
}
#endif
