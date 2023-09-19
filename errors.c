#include "shell.h"

int err_not_found(char *program_name, size_t command_num, char *command_name) {
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

    return(127);
}

