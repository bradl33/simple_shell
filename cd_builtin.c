#include "shell.h"

int cd_builtin(char **tokens_arr)
{
char *home_dir = getenv("HOME");

	if (tokens_arr[1] == NULL)
	{
		if (home_dir == NULL)
		{
		perror("Home directory not set");
return (1);
		}

	if (chdir(home_dir) != 0)
		{
		return (2);
		}
	}
	else
	{
	if (chdir(tokens_arr[1]) != 0)
		{
	return (2);
		}
	}
	return (0);
}
