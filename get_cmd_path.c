#include "shell.h"

char *get_cmd_path(char *command){
    char *path, *path_copy, *path_token, *file_path;
    int cmd_length, dir_length;
    struct stat buffer;

    path = getenv("PATH");
    if(path) {
        path_copy = strdup(path);
        cmd_length = strlen(command);

        path_token = strtok(path_copy, ":");

        while(path_token != NULL) {
            dir_length = strlen(path_token);
            file_path = malloc(cmd_length + dir_length + 2);
            
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            if(stat(file_path, &buffer) == 0){
                free(path_copy);
                return (file_path);
            }
            else {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }

        free(path_copy);
        if(stat(command, &buffer) == 0){
            return (command);
        }
        return (NULL);
    }
    return (NULL);
}