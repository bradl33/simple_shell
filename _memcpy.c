#include "shell.h"

/**
 * _memcpy - copies memory content from src to dest
 * @dest: destination memory
 * @src: source memory
 * @n: number of chars in memory
 *
 * Return: dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		(dest[i] = src[i]);
		i++;
	}
	return (dest);
}
