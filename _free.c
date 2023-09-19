#include "shell.h"

/**
 * free_tokens_arr - frees tokens_arr
 * @tokens_arr: double pointer to array of characters
 * @token_count: count of tokens
 * @line: pointer to character
 *
 * Return: void
*/
void free_tokens_arr(char **tokens_arr, int token_count, char *line)
{
	int i;

	for (i = 0; i < token_count; i++)
	{
		free(tokens_arr[i]);
	}
	free(tokens_arr);
	free(line);
}
