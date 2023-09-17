#include "shell.h"
#include <sys/wait.h>

int execute_external(char *cmd_path, char **tokens_arr) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        return (-1);
    }

    if (pid == 0) {
        /* execute execve and check if error */
        if (execve(cmd_path, tokens_arr, __environ) == -1) {
            return (-1);
        }
    } else {
        wait(&status);
        free(cmd_path);
        if(WIFEXITED(status))
            status = WEXITSTATUS(status);

        if(!isatty(STDIN_FILENO))
            return(status);
    }

    return 0;
}