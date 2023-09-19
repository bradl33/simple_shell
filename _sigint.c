#include "shell.h"

/**
 * _sigint - handles signal interruption
 * @signal: signal to be handled
 *
 * Return: void
*/
void _sigint(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
