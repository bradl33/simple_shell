#include "shell.h"

void execute_command(char **argv) {
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
                    int exit_code = WEXITSTATUS(child_status);
                    printf("Child process exited with status %d\n", exit_code);
                }
            }
            free(actual_command);
        } else {
            fprintf(stderr, "Command not found: %s\n", command);
            exit(1);
        }
    }
}
