#include "shell.h"

/**
 * tokenize_line - splits a line into tokens
 * @line: line to be tokenized
 * @token_count: count of tokens
 *
 * Return: array of tokens
*/
char **tokenize_line(char *line, int *token_count)
{
	char **tokens_arr = NULL, **new_tokens_arr = NULL;
	char *token;
	int i;

	*token_count = 0;

	token = strtok(line, " \n");

	while (token != NULL)
	{
		new_tokens_arr = (char **)malloc((*token_count + 2) * sizeof(char *));

		if (new_tokens_arr == NULL)
		{
			perror("memory allocation error.");
			exit(EXIT_FAILURE);
		}

		if (tokens_arr != NULL)
		{
			for (i = 0; i < *token_count; i++)
				new_tokens_arr[i] = tokens_arr[i];
			free(tokens_arr);
		}

		new_tokens_arr[*token_count] = _strdup(token);
		tokens_arr = new_tokens_arr;
		tokens_arr[*token_count + 1] = NULL;
		(*token_count)++;
		token = strtok(NULL, " \n");
	}
	return (tokens_arr);
}
