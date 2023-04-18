#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory, which contains a copy of the
 * string given as a parameter.
 * @str: String to be copied
 *
 * Return: NULL in case of error, pointer to allocated
 * space
 */
char *_strdup(char *str)
{
	char *cpy;
	int index, len;

	if (str == NULL) /* Check if input string is NULL */
		return (NULL);

	/* Calculate length of input string */
	for (index = 0; str[index]; index++)
		len++;

	/* Allocate memory for copy of input string */
	cpy = malloc(sizeof(char) * (len + 1));

	if (cpy == NULL) /* Check if memory allocation failed */
		return (NULL);

	/* Copy input string to newly allocated memory */
	for (index = 0; str[index]; index++)
		cpy[index] = str[index];

	cpy[len] = '\0'; /* Add null terminator at the end of copied string */

	return (cpy);
}
