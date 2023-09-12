#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void prompt(void);
int is_builtin_command(char *command);
void execute_builtin_command(char **argv);
void execute_non_builtin_command(char **argv);
char *get_cmd_path(char *command);
ssize_t my_getline(char **input, size_t *n, int status);
int tokenize_input(char *lineptr, char *tokens[]);
int custom_exit(char **args);
int custom_cd(char **args);
int custom_env(char **args);

#endif