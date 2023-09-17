#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n) {
    size_t buffer_size = *n;
    size_t line_length = 0;
    char *line = *lineptr;
    char c;
    char *new_line = NULL;
    int leading_space = 0;

    if (lineptr == NULL) {
        return -1; /* Invalid arguments */
    }

    prompt();

    /* check for and skip leading whitespace */
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == ' ' || c == '\t') {
            leading_space++;
            /* Skip leading white spaces. */
            continue;
        } else {
            break;
        }
    }

    /* check if next character is a newline */
    if (c == '\n') {
        return (-1);
    }

    /* Check if the buffer is large enough */
    if (line == NULL || buffer_size == 0) {
        buffer_size = BUFFER; /* Initial buffer size 1024 */
        line = (char *)malloc(buffer_size);
        if (line == NULL) {
            return -1; /* Memory allocation error */
        }
    }

    /* store beginning char to line */
    line[line_length++] = (char)c;

    /* continue with subsequent chars */
    while ((c = getchar()) != EOF && c != '\n') {
        if (line_length + 1 >= buffer_size) {
            /* Resize the buffer if it's not large enough */
            buffer_size *= 2;
            new_line = (char *)realloc(line, buffer_size);
            if (new_line == NULL) {
                free(line);
                return -1; /* Memory allocation error */
            }
            line = new_line;
            free(new_line);
        }

        if (line != new_line) {
            free(new_line);
        }

        /* store subsequent chars in line */
        line[line_length++] = (char)c;
    }

    line[line_length] = '\0'; /* Null-terminate the string */

    *lineptr = line;
    *n = buffer_size;

    return line_length;
}