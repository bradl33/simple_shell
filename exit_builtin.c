#include "shell.h"

#define SUCCESS_EXIT_CODE 0
#define INVALID_ARGS_EXIT_CODE 2

/**
 * exit_builtin - handles the exit builtin
 * @tokens_arr: double pointer to char tokens
 * @token_count: count of tokens
 *
 * Return: exit code
*/

int exit_builtin(char **tokens_arr, int token_count)
{
	int exit_code = SUCCESS_EXIT_CODE;
	int ret_val; /* return value by atoi */

	if (tokens_arr[1] == 0)
		exit_code = SUCCESS_EXIT_CODE;

	/* handles exit value argument */
	if (token_count > 1)
	{
		ret_val = atoi(tokens_arr[1]);

		/* if exit argument successfully converted to int */
		if (ret_val != 0)
			exit_code = ret_val;
		else
			exit_code = INVALID_ARGS_EXIT_CODE;
	}

	return (exit_code);
}
