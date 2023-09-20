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
#include<signal.h>

void _sigint(int signal);
void prompt(void);
char *_getline(char **lineptr, FILE *stream);
char *_memcpy(char *dest, char *src, unsigned int n);
char **tokenize_line(char *line, int *token_count);
void free_tokens_arr(char **tokens_arr, int token_count, char *line);

char *_strdup(char *str);
char *_itos(size_t command_num);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);

int exit_builtin(char **tokens_arr, int token_count);
int env_builtin(char **tokens_arr);
int cd_builtin(char **tokens_arr);

int is_builtin_command(char *command);
int execute_builtin(char **tokens_arr);

char *get_cmd_path(char *command);
int execute_external(char *cmd_path, char **tokens_arr);

int err_exit_illegal_num(char *program_name, size_t command_num, char *exit_arg);
int err_not_found(char *program_name, size_t command_num, char *command_name);

#endif