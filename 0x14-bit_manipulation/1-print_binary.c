#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to be printed.
 */
void print_binary(unsigned long int n)
{
	/* Get the size of the number in bits. */
	signed long int size = sizeof(n) * 8 - 1;

	/* Check if the number is zero or one. */
	if (n == 0)
	{
		putchar('0');
		return;
	}
	else if (n == 1)
	{
		putchar('1');
		return;
	}

	/* Flag to indicate if a one has been found. */
	int flag = 0;

	/* Loop through each bit of the number, starting with the most significant bit. */
	while (size >= 0)
	{
		/* Get the value of the current bit (0 or 1). */
		char c = (n >> size) & 1;

		/* If a one has been found, print the current bit. */
		if (flag == 1)
			putchar(c + '0');
		/* Otherwise, if the current bit is one, print it and set the flag. */
		else
		{
			if (c == 1)
			{
				putchar(c + '0');
				flag = 1;
			}
		}

		/* Move on to the next bit. */
		size--;
	}
}
