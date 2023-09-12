#include "shell.h"

void execute_non_builtin_command(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        command = argv[0];

        actual_command = get_cmd_path(command);

        if (actual_command != NULL) {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Fork failed");
                exit(1);
            } else if (child_pid == 0) {
                if (execve(actual_command, argv, NULL) == -1) {
                    perror("Error executing command");
                    exit(1);
                }
            } else {
                int child_status;
                waitpid(child_pid, &child_status, 0);

                if (WIFEXITED(child_status)) {
                    WEXITSTATUS(child_status);
                    /* printf("Child process exited with status %d\n", exit_code); */
                }
            }
            free(actual_command);
        } else {
            fprintf(stderr, "Command not found: %s\n", command);
            exit(1);
        }
    }
}

char *builtin_func_list[] = {
    "exit",
    "cd",
    "env"
};

int (*builtin_func[])(char **) = {
    &custom_exit, 
    &custom_cd,
    &custom_env
};

int is_builtin_command(char *command) {
    int i;
    int num_builtins;
    num_builtins = sizeof(builtin_func_list) / sizeof(char *);

    for (i = 0; i < num_builtins; i++) {
        if (strcmp(command, builtin_func_list[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void execute_builtin_command(char **argv){
    int i, exit_code, num_builtins;
    if (argv[0] == NULL) {
        return;
    }

    num_builtins = sizeof(builtin_func_list) / sizeof(char *);

    for (i = 0; i < num_builtins; i++) {
        if (strcmp(argv[0], builtin_func_list[i]) == 0) {
            exit_code =  (*builtin_func[i])(argv);
            printf("Builtin command executes with exit code %d\n", exit_code);
            return;
        }
    }

    fprintf(stderr, "Command not found: %s\n", argv[0]);
}
