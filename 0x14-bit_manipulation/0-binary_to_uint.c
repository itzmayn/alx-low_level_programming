#include "main.h"
/**
 * binary_to_uint - convert binary string to decimal
 * @b: binary string
 *
 * Return: decimal (unsigned int)
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	unsigned int i = 0;

	if (!b)
		return (0);

	while (b[i])
	{
		if (b[i] == '1')
			decimal = (decimal << 1) | 1;
		else if (b[i] == '0')
			decimal <<= 1;
		else
			return (0);
		i++;
	}

	return (decimal);
}
