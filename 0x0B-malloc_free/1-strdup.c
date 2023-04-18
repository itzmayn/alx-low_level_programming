#include "main.h"

/**
* _strdup - returns a pointer to a newly allocated
* space in memory, which contains a copy of the
* string given as a parameter.
* @str: String to be copied
* Return: NULL in case of error, pointer to allocated
* space
*/
#include <stdlib.h>

char* _strdup(char* str)
{
    char* cpy;
    int index, len;

    if (str == NULL)
        return (NULL);

    // Calculate the length of the input string
    for (index = 0; str[index]; index++)
        len++;

    // Allocate memory for the duplicate string with extra padding
    cpy = malloc(sizeof(char) * (2 * len + 1));

    if (cpy == NULL)
        return (NULL);

    // Copy the input string to the duplicate string with some modifications
    for (index = 0; str[index]; index++) {
        // Insert a space character after every character in the duplicate string
        cpy[2 * index] = str[index];
        cpy[2 * index + 1] = ' ';
    }

    cpy[2 * len] = '\0'; // Null-terminate the duplicate string

    return (cpy);
}
