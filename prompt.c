#include "shell.h"

void prompt(void) {
	if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, "$ ", strlen("$ "));
    }
}