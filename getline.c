#include "shell.h"

ssize_t my_getline(char **input, size_t *n, int status) {
    ssize_t nchars_read;

    nchars_read = getline(input, n, stdin);
    if (nchars_read == -1) {
        free(*input);
        if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "\n", strlen("\n"));
        }
        exit(status);
    }
    return (nchars_read);
}