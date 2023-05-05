#include "main.h"

/**
 * flip_bits - Counts the number of bits needed to flip to convert n to m.
 *
 * @n: The first unsigned long int number.
 * @m: The second unsigned long int number.
 *
 * Return: The number of bits needed to flip to convert n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int t = n ^ m;
	unsigned int count = 0;

	while (t != 0)
	{
		if ((t & 1) == 1)
			count++;
		t >>= 1;
	}
	return (count);
}
