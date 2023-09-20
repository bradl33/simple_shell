#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: 0 if equal, <0 is s1 less than s2, >0 otherwise
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);

		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strchr - locates a character in a string
 * @s: string to search in
 * @c: character to be located
 *
 * Return: pointer to 1st occurence of c, or NULL if not found
*/
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);

		s++;
	}

	if (*s == c)
		return (s);

	return (NULL);
}
