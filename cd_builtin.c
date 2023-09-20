#include "shell.h"

/**
 * cd_builtin - handles the cd builtin command
 * @tokens_arr: double pointer to array of char tokens
 *
 * Return: 0 on success, 1 or 2 on error
*/

int cd_builtin(char **tokens_arr)
{
	char *home_dir = getenv("HOME");

	if (tokens_arr[1] == NULL)
	{
		if (home_dir == NULL)
		{
			return (1);
		}

		if (chdir(home_dir) != 0)
			return (2);
	}
	else
	{
		if (chdir(tokens_arr[1]) != 0)
			return (1);
	}
	return (0);
}
