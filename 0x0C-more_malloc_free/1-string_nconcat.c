#include "main.h"

/**
 * search - search the size
 * @s: string
 * @n: size of string s2
 * @typ: string 1 -> 1, string 2 -> 2
 * Return: size
 */
unsigned int search(char *s, unsigned int n, int typ)
{
    if (s == NULL)
        s = "";
    unsigned int l;
    for (l = 0; s[l] != '\0'; l++)
        ;
    if (n < l && typ == 2)
        l = l - (l - n);
    return (l);
}

/**
 * string_nconcat - concatenate 2 string with limit
 * @s1: string
 * @s2: string
 * @n: size of string s2
 * Return: pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int i, j, l1, l2;
    l1 = search(s1, n, 1);
    l2 = search(s2, n, 2);
    char *newStr = malloc(sizeof(char) * (l1 + l2 + 1));
    if (newStr == NULL)
    {
        free(newStr);
        return (NULL);
    }
    for (i = 0; i < l1; i++)
        newStr[i] = s1[i];
    for (j = 0; j < l2; j++, i++)
        newStr[i] = s2[j];
    newStr[i] = '\0';
    return (newStr);
}
