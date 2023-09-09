#include "shell.h"

#define MAX_TOKENS 100

int main(int argc, char **argv) {
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int i;

    (void)argc;
    (void)argv;

    while (1) {
        prompt();
        nchars_read = getline(&lineptr, &n, stdin);
        
        if (nchars_read == -1) {
            printf("\nexit\n");
            break;
        } else {
            char *tokens[MAX_TOKENS] = {NULL};
            int num_tokens = 0;

            char *token = strtok(lineptr, delim);
            while (token != NULL && num_tokens < MAX_TOKENS) {
                tokens[num_tokens] = strdup(token);
                num_tokens++;
                token = strtok(NULL, delim);
            }

            if(num_tokens > 0) {
                execute_command(tokens);
            }

            /* printf("\ntokens: %d\n", num_tokens); */

            for (i = 0; i < num_tokens; i++) {
                /* printf("%s\n", tokens[i]); */
                free(tokens[i]);
            }
        }
    }

    free(lineptr);
    return 0;
}
