/**
 * _strdup - Returns a pointer to a newly allocated duplicate string.
 * @str: Pointer to the input string.
 *
 * Return: Pointer to the duplicate string, or NULL on error.
 */
char *_strdup(char *str)
{
	char *cpy; /* Pointer to the duplicate string */
	int i, len; /* Variables for loop index and length of the input string */

	if (str == NULL)
		return (NULL); /* If input string is NULL, return NULL indicating error */

	for (i = 0; str[i]; i++)
		len++; /* Calculate the length of the input string by counting characters */

	cpy = malloc(sizeof(char) * (len + 1)); /* Allocate memory for the duplicate string */

	if (cpy == NULL)
		return (NULL); /* If memory allocation fails, return NULL indicating error */

	for (i = 0; str[i]; i++)
		cpy[i] = str[i]; /* Copy characters from input string to the duplicate string */

	cpy[len] = '\0'; /* Null-terminate the duplicate string */

	return (cpy); /* Return the pointer to the duplicate string */
}
