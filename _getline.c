#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n) {
    size_t buffer_size = *n, line_length = 0;
    char c, *line = *lineptr, *new_line = NULL;
    int leading_space = 0;

    if (lineptr == NULL) {
        perror("Invalid arguments.");
        return (-1);
    }
    prompt();
    /* check for and skip leading whitespace */
    while (read(STDIN_FILENO, &c, 1) != -1 && c != '\n') {
        if (c == ' ' || c == '\t') {
            leading_space++;
            continue;
        } else
            break;
    }
    if (c == '\n')
        return (-1);

    /* Check if the buffer is large enough */
    if (line == NULL || buffer_size == 0) {
        buffer_size = BUFFER; /* Initial buffer size 1024 */
        line = (char *)malloc(buffer_size);
        if (line == NULL) {
            perror("Memory allocation error");
            return (-1);
        }
    }

    line[line_length++] = (char)c; /* store beginning char to line */

    /* continue with subsequent chars */
    while (read(STDIN_FILENO, &c, 1) != -1 && c != '\n') {
        if (line_length + 1 >= buffer_size) {
            buffer_size *= 2; /* Resize the buffer if it's not large enough */
            new_line = (char *)malloc(buffer_size);
            if (new_line == NULL) {
                perror("Memory allocation error");
                free(line);
                return (-1); /* Memory allocation error */
            }
            line = new_line;
            free(new_line);
        }

        if (line != new_line)
            free(new_line);
        line[line_length++] = (char)c; /* store subsequent chars in line */
    }

    line[line_length] = '\0'; /* Null-terminate the string */
    *lineptr = line;
    *n = buffer_size;

    return (line_length);
}