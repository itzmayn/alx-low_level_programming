#include "main.h"

/**
 * malloc_checked - test malloc
 * @b: bytes
 * Return: Pointer to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *tmp = malloc(b);
	if (!tmp)
		exit(98);
	return (tmp);
}
