#include "shell.h"

int env_builtin(__attribute((unused)) char **tokens_arr) {
    int env_index = 0;

    while (__environ[env_index]) {
        if (write(STDOUT_FILENO, __environ[env_index], strlen(__environ[env_index])) == -1) {
            return (1);
        }
        if (write(STDOUT_FILENO, "\n", strlen("\n")) == -1) {
            return (1);
        }
        env_index++;
    }

    return (0);
}


/*
int main() {
    char *tokens[] = { NULL };

    int numEnvVars = env_builtin(tokens);
    printf("Total environment variables processed: %d\n", numEnvVars);

    return 0;
}
*/
