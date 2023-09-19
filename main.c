#include "shell.h"

int main(int argc, char *argv[]) {
    char **tokens_arr = NULL;
    char *line, *program_name, *command_name, *cmd_path;
    size_t len, command_num;
    ssize_t read;
    int token_count, exit_code, status;
    bool exiting = false;

    line = NULL;
    len = token_count = status = command_num = 0;

    (void)argc;

    while (1) {
        command_num++;
        read = _getline(&line, &len);

        if (read != -1) {
            tokens_arr = tokenize_line(line, &token_count);

            program_name = argv[0];
            command_name = tokens_arr[0];

            /* handle exit here as is a special case compared to other builtins */
            if (strcmp(tokens_arr[0], "exit") == 0) {
                if (token_count > 2 && atoi(tokens_arr[1]) != 0) {
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
                        status = execute_external(tokens_arr[0], tokens_arr);
                        exit(status);
                    } else {
                        cmd_path = get_cmd_path(tokens_arr[0]);
                        if (cmd_path != NULL) {
                            status = execute_external(cmd_path, tokens_arr);
                            
                        }
                        else
                           err_not_found(program_name, command_num, command_name);
                    }
                }
            }

            free_tokens_arr(tokens_arr, token_count, line);
            line = NULL;
        }
        if (exiting)
            exit(exit_code);
    }
    return (0);
}
