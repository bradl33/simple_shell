#include "shell.h"

int main(int argc, char *argv[]) {
    char *line = NULL;
    char **tokens_arr = NULL;
    size_t len = 0;
    ssize_t read;
    int token_count = 0;
    int exit_code, status = 0;
    bool exiting = false;
    char *program_name, *command_name, *cmd_path;

    (void)argc;
    /*
    (void)program_name;
    (void)command_name;
    */

    while (1) {
        /* printf("Enter a line of text:\n"); */
        read = _getline(&line, &len);

        if (read != -1) {
            /* printf("Line: %s\n", line); */

            tokens_arr = tokenize_line(line, &token_count);

            program_name = argv[0];
            command_name = tokens_arr[0];

            #if 0
            for (i = 0; i < token_count; i++) {
                printf("Token %d: %s\n", i, tokens_arr[i]);
            }
            #endif

            /* handle exit here as is a special case compared to other builtins */
            if (strcmp(tokens_arr[0], "exit") == 0) {

                /* exit_code = handle_exit(tokens_arr, token_count, line, program_name, command_name, &exit_code, &exiting); */

                if (token_count > 2 && atoi(tokens_arr[1]) != 0) {
                    fprintf(stderr, "%s\n", command_name);
                    fprintf(stderr, "%s: %s: too many arguments\n", program_name, command_name);

                    free_tokens_arr(tokens_arr, token_count, line);
                    line = NULL;
                    
                    return (1);
                }
                exit_code = exit_builtin(tokens_arr, token_count);
                exiting = true; /* exit is ready. Will be executed after free(s)*/
            }
            
            if(!exiting) {
                if (is_builtin_command(tokens_arr[0])) {
                    execute_builtin(tokens_arr);
                } else {
                    if(strchr(tokens_arr[0], '/') != NULL) {
                        execute_external(tokens_arr[0], tokens_arr);
                        exit(status);
                    } else {
                        cmd_path = get_cmd_path(tokens_arr[0]);
                        if (cmd_path != NULL) {
                            execute_external(cmd_path, tokens_arr);
                        }
                    }
                }
            }
            free_tokens_arr(tokens_arr, token_count, line);
            line = NULL;
            command_name = NULL;
        }

        if (exiting)
            exit(exit_code);
    }
    return (0);
}
