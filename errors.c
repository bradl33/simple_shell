#include "shell.h"

/**
 * err_not_found - handles error when not found
 * @program_name: pointer to name of program
 * @command_num: command number
 * @command_name: command name
 *
 * Return: return 127
*/
int err_not_found(char *program_name, size_t command_num, char *command_name)
{
	char *error_string = NULL;
	char *str_command_num = _itos(command_num);
	int err_str_size = (_strlen(program_name) + (2 * _strlen(": ")) +
					_strlen(str_command_num) + _strlen(command_name) +
					_strlen(": not found\n") + 1);
	error_string = (char *) malloc(sizeof(char) * err_str_size);

	_strcpy(error_string, program_name);
	_strcat(error_string, ": ");
	_strcat(error_string, str_command_num);
	_strcat(error_string, ": ");
	_strcat(error_string, command_name);
	_strcat(error_string, ": not found\n");
	_strcat(error_string, "\0");

	write(STDERR_FILENO, error_string, _strlen(error_string));
	free(error_string);
	free(str_command_num);

	return (127);
}

/**
 * err_exit_illegal_num - handles error when exit has illegal number
 * @program_name: pointer to name of program
 * @command_num: command number
 * @exit_arg: exit argument
 *
 * Return: 2
*/
int err_exit_illegal_num(char *program_name, size_t command_num,
												char *exit_arg) {
	char *error_string = NULL;
	char *str_command_num = _itos(command_num);
	char *msg_str = NULL;
	int err_str_size;
	int sz_program_name, sz_2_colons_2_spaces, sz_str_cmd_num,
			sz_msg_str, sz_exit_arg_plus_2;

	/** add negative sign if exit argument is a number */
	if (atoi(exit_arg) == 0)
		msg_str = "exit: Illegal number: ";
	else
		msg_str = "exit: Illegal number: -";

	sz_program_name = _strlen(program_name);
	sz_2_colons_2_spaces = 2 * _strlen(": ");
	sz_str_cmd_num = _strlen(str_command_num);
	sz_msg_str = _strlen(msg_str);
	sz_exit_arg_plus_2 = _strlen(exit_arg) + 2;
	err_str_size = sz_program_name + sz_2_colons_2_spaces +
						sz_str_cmd_num + sz_msg_str + sz_exit_arg_plus_2;

	error_string = (char *) malloc(sizeof(char) * err_str_size);

	_strcpy(error_string, program_name);
	_strcat(error_string, ": ");
	_strcat(error_string, str_command_num);
	_strcat(error_string, ": ");
	_strcat(error_string, msg_str);
	_strcat(error_string, exit_arg);
	_strcat(error_string, "\n");
	_strcat(error_string, "\0");

	write(STDERR_FILENO, error_string, _strlen(error_string));
	free(error_string);
	free(str_command_num);

	return (2);
}
