#include "main.h"

/**
 * _calloc - reserve a memory space
 * @nmemb: scale
 * @size: bytes
 * Return: Pointer to allocated memory, or NULL if fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	if (nmemb == 0 || size == 0)
		return NULL;

	void *space = malloc(nmemb * size);
	if (space)
		memset(space, 0, nmemb * size);

	return space;
}
