#include "main.h";

/**
 * _strdup - returns a pointer to a newly allocated
 *           memory block containing a duplicate of the input string.
 * @str: Pointer to the input string to be duplicated.
 *
 * Return: Pointer to the duplicate string, or NULL if memory allocation fails
 */
char* _strdup(char* str)
{
    char* cpy;    /* Pointer to the duplicate string */
    int index, len;    /* Variables for loop index and length of the input string */

    if (str == NULL)
        return (NULL);    /* If input string is NULL, return NULL indicating error */

    for (index = 0; str[index]; index++)
        len++;    /* Calculate the length of the input string by counting characters */

    cpy = malloc(sizeof(char) * (len + 1));    /* Allocate memory for the duplicate string */

    if (cpy == NULL)
        return (NULL);    /* If memory allocation fails, return NULL indicating error */

    for (index = 0; str[index]; index++)
        cpy[index] = str[index];    /* Copy characters from input string to the duplicate string */

    cpy[len] = '\0';    /* Null-terminate the duplicate string */

    return (cpy);    /* Return the pointer to the duplicate string */
}
