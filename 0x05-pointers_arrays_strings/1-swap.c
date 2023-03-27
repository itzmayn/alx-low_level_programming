#include "main.h"
/**
 * swap_int - swap the values of 2 integers.
 * @a: pointer a
 * @b: pointer b;
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
