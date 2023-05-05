#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long int
 *
 * Description: Prints the binary representation of an unsigned long int
 * starting from the most significant bit to the least significant bit
 * using the `_putchar` function to output each character.
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int found_first_one = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask > 0)
	{
		if ((n & mask) == 0 && found_first_one)
			_putchar('0');
		else if ((n & mask) != 0)
		{
			_putchar('1');
			found_first_one = 1;
		}
		mask >>= 1;
	}
}
