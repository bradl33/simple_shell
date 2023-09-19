#include "shell.h"

char *_strcat(char *dest, char *src)
{
	int i, x;

	i = x = 0;

	while (dest[i] != '\0')
	i++;

	while (src[x] != '\0')
	{
	dest[i] = src[x];
	x++;
	i++;
	}

	dest[i] = '\0';

	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	int i, x;

	i = x = 0;

	while (src[i] != '\0')
	i++;

	for (x = 0; x < i; x++)
	dest[x] = src[x];

	dest[x] = '\0';

	return (dest);
}

char *_strdup(char *str)
{
	char *dup_str = NULL;
	unsigned int i, len;

	i = len = 0;

	if (str == NULL)
	return (NULL);

	while (str[len])
	len++;

	dup_str = malloc((len + 1) * sizeof(char));

	if (dup_str == NULL)
	return (NULL);

	while ((dup_str[i] = str[i]) != '\0')
	i++;

	return (dup_str);
}

int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	i++;

	return (i);
}

char *_itos(size_t command_num)
{
	size_t num = command_num;
	int digits_in_num = 0;
	char *string = NULL;
	do {
		num /= 10;
		digits_in_num++;
	} while (num > 0);

	string = (char*)malloc(digits_in_num + 1);

	if (string == NULL)
		return (NULL);

	string[digits_in_num] = '\0';

	do {
		digits_in_num--;
		string[digits_in_num] = '0' + (command_num % 10);
		command_num /= 10;
	} while (digits_in_num > 0);

	return (string);
}