#include "shell.h"

/**
 * env_builtin - handles the env builtin
 * @tokens_arr: double pointer to char tokens
 *
 * Return: 1 on error, 0 on success
*/
int env_builtin(char **tokens_arr)
{
	int env_index = 0;

	(void)tokens_arr;

	while (__environ[env_index])
	{
		if (write(STDOUT_FILENO, __environ[env_index],
				_strlen(__environ[env_index])) == -1)
		{
			return (1);
		}

		if (write(STDOUT_FILENO, "\n", _strlen("\n")) == -1)
			return (1);

		env_index++;
	}
	return (0);
}

