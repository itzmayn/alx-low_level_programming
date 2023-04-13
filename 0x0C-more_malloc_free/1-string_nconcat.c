#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenate two strings with a limit
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated memory with concatenated string,
 *         or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int i, j, len1, len2;
    char *concatenated;

    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";

    for (len1 = 0; s1[len1] != '\0'; len1++)
        ;
    for (len2 = 0; s2[len2] != '\0'; len2++)
        ;

    if (n >= len2)
        n = len2;

    concatenated = malloc(sizeof(char) * (len1 + n + 1));

    if (concatenated == NULL)
        return (NULL);

    for (i = 0; i < len1; i++)
        concatenated[i] = s1[i];

    for (j = 0; j < n; j++, i++)
        concatenated[i] = s2[j];

    concatenated[i] = '\0';

    return (concatenated);
}
