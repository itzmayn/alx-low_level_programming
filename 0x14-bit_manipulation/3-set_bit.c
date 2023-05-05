#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 *
 * @n: A pointer to the unsigned long int number.
 * @index: The index of the bit to set to 1.
 *
 * Return: 1 on success, or -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask <<= index;
	*n |= mask;

	return (1);
}
