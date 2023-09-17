#include "shell.h"
#include <sys/stat.h>

char *get_cmd_path(char *command) {
    char *path = getenv("PATH");
    char *path_copy, *path_token, *file_path;
    int cmd_length, dir_length;
    struct stat buffer;

    if (path != NULL) {
        path_copy = strdup(path);
        if (path_copy == NULL) {
            return NULL;
        }

        path_token = strtok(path_copy, ":");

        while (path_token != NULL) {
            cmd_length = strlen(command);
            dir_length = strlen(path_token);
            file_path = malloc(dir_length + cmd_length + 2);

            if (file_path == NULL) {
                free(path_copy);
                return NULL;
            }

            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            file_path[dir_length + cmd_length + 1] = '\0';

            if (stat(file_path, &buffer) == 0) {
                free(path_copy);
                return file_path;
            } else {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }

        free(path_copy);
    }

    return NULL;
}