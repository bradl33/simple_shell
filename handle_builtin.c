#include "shell.h"

char *builtin_func_list[] = {
    "cd",
    "env"
};

int (*builtin_func[])(char **) = {
    &cd_builtin,
    &env_builtin
};

int is_builtin_command(char *command) {
    int i, num_builtins;

    if (command == NULL) {
        return (0);
    }

    num_builtins = sizeof(builtin_func_list) / sizeof(char *);

    for (i = 0; i < num_builtins; i++) {
        if(strcmp(command, builtin_func_list[i]) == 0) {
            return (1);
        }
    }

    return (0);
}

int execute_builtin(char **tokens_arr) {
    int i, exec_status, num_builtins;

    if (tokens_arr == NULL || tokens_arr[0] == NULL) {
        return (1);
    }

    num_builtins = sizeof(builtin_func_list) / sizeof(char *);

    for (i = 0; i < num_builtins; i++) {
        if (strcmp(tokens_arr[0], builtin_func_list[i]) == 0) {
            exec_status = (*builtin_func[i])(tokens_arr);
            return (exec_status);
        }
    }

    fprintf(stderr, "Command not found: %s\n", tokens_arr[0]);

    return (1);
}