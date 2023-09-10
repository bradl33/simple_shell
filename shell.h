#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

void prompt(void);
void execute_command(char **argv);
char *get_cmd_path(char *command);
ssize_t my_getline(char **input, size_t *n, int status);
int tokenize_input(char *lineptr, char *tokens[]);

#endif