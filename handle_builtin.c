#include "shell.h"

int is_builtin_command(char *command)
{
	char *builtin_func_list[] = {
		"cd",
		"env"
	};

	int i, num_builtins;

	if (command == NULL)
		return (0);

	num_builtins = sizeof(builtin_func_list) / sizeof(char *);

	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(command, builtin_func_list[i]) == 0)
			return (1);
	}

	return (0);
}

int execute_builtin(char **tokens_arr)
{
	int i, exec_status, num_builtins;

	char *builtin_func_list[] = {
		"cd",
		"env"
	};

	if (tokens_arr == NULL || tokens_arr[0] == NULL)
		return (1);

	num_builtins = sizeof(builtin_func_list) / sizeof(char *);

	for (i = 0; i < num_builtins; i++)
	{
		if (strcmp(tokens_arr[0], builtin_func_list[i]) == 0)
		{
			if (i == 0)
				exec_status = cd_builtin(tokens_arr);
			else if (i == 1)
				exec_status = env_builtin(tokens_arr);

			return (exec_status);
		}
	}

	perror("Command not found");

	return (1);
}
