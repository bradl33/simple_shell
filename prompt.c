#include "shell.h"

/**
 * prompt - displays prompt
 *
 * Return: void
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", _strlen("$ "));
	}
}
