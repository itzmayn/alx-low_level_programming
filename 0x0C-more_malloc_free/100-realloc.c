#include "main.h"
#include <stdlib.h>

/**
 * _realloc - realloc but with malloc
 * @ptr: pointer created with malloc
 * @old_size: used space
 * @new_size: is the new size
 *
 * Return: pointer to the reallocated memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *newP;
    unsigned int i;

    if (ptr == NULL)
        return (malloc(new_size));
    if (new_size == old_size)
        return (ptr);
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    newP = malloc(new_size);
    if (newP == NULL)
        return (NULL);

    for (i = 0; i < old_size && i < new_size; i++)
        *((char *)newP + i) = *((char *)ptr + i);

    free(ptr);

    return (newP);
}
