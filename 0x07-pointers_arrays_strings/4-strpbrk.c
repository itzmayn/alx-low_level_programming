#include "main.h"

/**
 * _strpbrk - Find first occurrence of a character in a string
 * @s: The string to search
 * @accept: The characters to search for
 *
 * Return: Pointer to the first occurrence of a character in the string,
 *         or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
		}
	}

	return (NULL);
}
