#include "shell.h"

int main(int argc, char *argv[])
{
	char **tokens_arr = NULL;
	char *line, *command_name, *cmd_path;
	size_t command_num;
	char *read;
	int token_count, exit_code, status;
	bool exiting = false;
	char *str_exit_code, *exit_arg = NULL;

	signal(SIGINT, _sigint);
	line = NULL;
	token_count = status = command_num = 0;

	(void)argc;

	while (1)
	{
		command_num++;
		if (isatty(STDIN_FILENO) == 1)
			prompt();
		read = _getline(&line, stdin);

		if (strcmp(read, "") == 0)
			continue;
		else
		{
			tokens_arr = tokenize_line(line, &token_count);

			command_name = tokens_arr[0];

			/* handle exit here as is a special case compared to other builtins */
			if (strcmp(tokens_arr[0], "exit") == 0)
			{
				if (token_count > 2 && atoi(tokens_arr[1]) != 0)
				{
					free_tokens_arr(tokens_arr, token_count, line);
					line = NULL;

					return (1);
				}
				if (token_count == 2 && atoi(tokens_arr[1]) == 0)
				{
					exit_arg = tokens_arr[1];
					err_exit_illegal_num(argv[0], command_num, exit_arg);
					exit(2);
				}
				exit_code = exit_builtin(tokens_arr, token_count);
				exiting = true; /* exit is ready. Will be executed after free(s)*/
			}

			if (!exiting)
			{
				if (is_builtin_command(tokens_arr[0]))
					execute_builtin(tokens_arr);
				else
				{
					if (strchr(tokens_arr[0], '/') != NULL)
						status = execute_external(tokens_arr[0], tokens_arr);
					else
					{
						cmd_path = get_cmd_path(tokens_arr[0]);
						if (cmd_path != NULL)
							status = execute_external(cmd_path, tokens_arr);
						else
						   status = err_not_found(argv[0], command_num, command_name);
					}
				}
				exit_code = status;
			}
			free_tokens_arr(tokens_arr, token_count, line);
			line = NULL;
		}
		/**
		* if(!isatty(STDIN_FILENO)) {
		*	exiting = true;
		* }
		*/
		if (exiting)
		{
			/* handle illegal number in exit */
			if (exit_code < 0)
			{
				/* get absolute value of exit_code */
				exit_code = -exit_code;
				str_exit_code = _itos(exit_code);

				err_exit_illegal_num(argv[0], command_num, str_exit_code);
				exit(2);
			}
			exit(exit_code);
		}
	}
	return (0);
}