#include "shell.h"
#include <sys/wait.h>

/**
 * execute_external - executes external command
 * @cmd_path: path to command to be executed
 * @tokens_arr: array of tokens, command being arr[0]
 *
 * Return: command execution status, -1 if error
*/
int execute_external(char *cmd_path, char **tokens_arr)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		/* execute execve and check if error */
		if (execve(cmd_path, tokens_arr, __environ) == -1)
			return (-1);
	} else
	{
		wait(&status);
		/* free(cmd_path); */
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			return (status);
		}

		if (!isatty(STDIN_FILENO))
			return (status);
	}
	return (0);
}
