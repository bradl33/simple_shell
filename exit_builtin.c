#include "shell.h"

#define SUCCESS_EXIT_CODE 0
#define INVALID_ARGS_EXIT_CODE 2

int exit_builtin(char **tokens_arr, int token_count)
{
	int exit_code = SUCCESS_EXIT_CODE;
	int ret_val; /* return value by atoi */

	if (token_count > 1)
	{
	ret_val = atoi(tokens_arr[1]);

	if (ret_val != 0)
	{
	exit_code = ret_val;
	}
	else
	{
	exit_code = INVALID_ARGS_EXIT_CODE;
	}
	}

	return (exit_code);
}
