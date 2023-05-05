#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned int
 * @index: index of the bit to be returned
 *
 * Return: value of bit at given index, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask <<= index;

	if ((n & mask) != 0)
		return (1);
	else
		return (0);
}
