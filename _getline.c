#include "shell.h"

/**
 * _getline - gets a line from input stream
 * @lineptr: double pointer to characters where line will be saved
 * @stream: FILE input stream
 *
 * Return: pointer to lineptr
*/
char *_getline(char **lineptr, FILE *stream)
{
	static char buffer[BUFFER];
	static int current_buffer = BUFFER;
	static int i, chars_read;
	int Lsize = 0, j;
	char c;
	char *new_lineptr;
	bool one_midspace = false;

	if (*lineptr == NULL)
	{
		*lineptr = malloc(current_buffer * sizeof(char));
		if (*lineptr == NULL)
		{
			perror("memory allocation error");
			exit(EXIT_FAILURE);
		}
	}

	while (1)
	{
		if (i == chars_read)
		{
			chars_read = read(fileno(stream), buffer, BUFFER);
			if (chars_read == -1)
			{
				perror("read error");
				exit(EXIT_FAILURE);
			}
			if (chars_read == 0)
			{
				/* write(STDOUT_FILENO, "\n", 1); */
				exit(EXIT_SUCCESS);
			}
			i = 0;
		}
		c = buffer[i++];
		if (c == ' ' && i >= 1)
		{
			if (i < 2)
				continue;
			if ((buffer[i - 2] != ' ') && one_midspace == false)
			{
				(*lineptr)[Lsize] = c;
				Lsize++;
				one_midspace = true;
			}
			continue;
		}
		if (c == '\n')
		{
			j = i;
			while (j < chars_read && buffer[j] == ' ')
			{
				j++;
			}

			if (j == chars_read)
			{
				(*lineptr)[Lsize] = '\0';
				break;
			} else
			{
				(*lineptr)[Lsize] = '\0';
				break;
			}

		}
		if (Lsize + 1 == current_buffer)
		{
			current_buffer *= 2;
			new_lineptr = malloc(current_buffer * sizeof(char));
			if (new_lineptr == NULL)
			{
				perror("memory allocation error");
				exit(EXIT_FAILURE);
			}
			_memcpy(new_lineptr, *lineptr, Lsize);
			free(*lineptr);
			*lineptr = new_lineptr;
		}
		(*lineptr)[Lsize] = c;
		Lsize++;
	}
	return (*lineptr);
}
