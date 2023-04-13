#include "main.h"

/**
 * array_range - array of integers.
 * @min: start of array
 * @max: end of array
 * Return: pointer to array of integers
 */
int *array_range(int min, int max)
{
	if (min > max)
		return NULL;

	int l = max - min + 1;
	int *space = malloc(sizeof(int) * l);

	if (space)
	{
		for (int i = 0; i < l; i++)
			space[i] = min++;
	}

	return space;
}
