#include "shell.h"

int cd_builtin(char **tokens_arr) {
    char *home_dir = getenv("HOME");

    if (tokens_arr[1] == NULL)
	{
		if(home_dir == NULL) {
            return (1);
        }

        if(chdir(home_dir) != 0){
            return (2);
        }
	}
	else
	{
		if (chdir(tokens_arr[1]) != 0)
		{
            return (2);
		}
	}
	return (0);
}

#if 0
int main() {
	char cwd[1024];
    char *tokens1[] = {"cd", NULL};
    char *tokens2[] = {"cd", "/tmp"};
    char *tokens3[] = {"cd", "non_existent_directory"};
	int result1, result2, result3;

    result1 = cd_builtin(tokens1);
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("PWD after cd 1: %s\n", cwd);
    } else {
        perror("getcwd");
    }
    printf("Result 1: %d\n", result1);

    result2 = cd_builtin(tokens2);
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("PWD after cd 2: %s\n", cwd);
    } else {
        perror("getcwd");
    }
    printf("Result 2: %d\n", result2);

    result3 = cd_builtin(tokens3);
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("PWD after cd 3: %s\n", cwd);
    } else {
        perror("getcwd");
    }
    printf("Result 3: %d\n", result3);

    return 0;
}
#endif
