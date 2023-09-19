#ifndef SHELL_H
#define SHELL_H

#define BUFFER 1024

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include<limits.h>
#include<stdbool.h>

void prompt(void);
ssize_t _getline(char **lineptr, size_t *n);
char **tokenize_line(char *line, int *token_count);
void free_tokens_arr(char **tokens_arr, int token_count, char *line);

char *_itos(size_t command_num);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *str);

int exit_builtin(char **tokens_arr, int token_count);
int env_builtin(char **tokens_arr);
int cd_builtin(char **tokens_arr);

int is_builtin_command(char *command);
int execute_builtin(char **tokens_arr);

char *get_cmd_path(char *command);
int execute_external(char *cmd_path, char **tokens_arr);
int err_not_found(char *program_name, size_t command_num, char *command_name);

int handle_exit(char **tokens_arr, int token_count, char *line, char *program_name, char *command_name, int *exit_code, bool *exiting);

#endif