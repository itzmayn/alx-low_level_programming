#include "main.h"
#include <stdlib.h>

/**
*_calloc - reserve a memory space
*@nmemb: scale
*@size: bytes
*Return: can return NULL
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *space;
	unsigned int pos = 0;

	if ((nmemb == 0) || (size == 0))
		return (NULL);
	space = malloc(nmemb * size);
	if ((space != NULL) && (size != 0))
	{
		while (pos < (nmemb * size))
		{
			space[pos] = 0;
			pos++;
		}
		return (space);
	}
	else
	{
		return (NULL);
	}
}
