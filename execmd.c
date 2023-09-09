#include "shell.h"

void execute_command(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        command = argv[0];

        actual_command = get_cmd_path(command);

        if (execve(actual_command, argv, NULL) == -1) {
            perror("error:");
        }
    }
}