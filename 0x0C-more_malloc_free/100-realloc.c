#include <stdlib.h>

void theCopy(char *newP, void *ptr, unsigned int new_size)
{
    for (unsigned int i = 0; i < new_size; i++)
    {
        *((char *)newP + i) = *((char *)ptr + i);
    }
}

/**
 * _realloc - realloc but with malloc
 * @ptr: pointer created with malloc
 * @old_size: used space
 * @new_size: is the new size
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *newP;

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
    theCopy(newP, ptr, new_size);
    free(ptr);
    return (newP);
}
