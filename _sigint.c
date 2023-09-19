#include "shell.h"

void _sigint(int signal)
{
    if (signal == SIGINT)
    {
        write(STDOUT_FILENO, "\n", 1);
        prompt();
        fflush(stdout);
    }
}