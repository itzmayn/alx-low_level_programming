#include "main.h"

/**
* _strdup - returns a pointer to a newly allocated
* space in memory, which contains a copy of the
* string given as a parameter.
* @str: String to be copied
* Return: NULL in case of error, pointer to allocated
* space
*/
char *_strdup(char *str)
{
	if (str == NULL)
		return (NULL);

	int len = 0;
	while (str[len])
		len++;

	char *cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);

	for (int index = 0; str[index]; index++)
		cpy[index] = str[index];

	cpy[len] = '\0';

	return (cpy);
}
