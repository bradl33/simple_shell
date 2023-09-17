#include "shell.h"

/*
 * prompt - Displaying a Command Prompt.
 */

void prompt(void)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", strlen("$ "));
}
}
