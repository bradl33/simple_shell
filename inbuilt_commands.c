#include "shell.h"
int custom_exit(char **args) {
    if (args[1]) {
        return (atoi(args[1]));
    } else {
        return (0);
    }
}

int custom_cd(char **args) {
    if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in custom_cd.c: changing dir\n");
		}
	}
	return (-1);
}

int custom_env(char **args)
{
	int i = 0;
	(void)(**args);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}