#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Succes)
 */

int main(void)
{
	// Loop over thousands place values
	for (int thousands = 0; thousands < 10; thousands++)
	{
		// Loop over hundreds place values
		for (int hundreds = 0; hundreds < 10; hundreds++)
		{
			// Loop over tens place values
			for (int tens = 0; tens < 10; tens++)
			{
				// Loop over ones place values
				for (int ones = 0; ones < 10; ones++)
				{
					// Print the current number
					putchar('0' + thousands);
					putchar('0' + hundreds);
					putchar(' ');
					putchar('0' + tens);
					putchar('0' + ones);

					// If this isn't the last number, print a comma and space
					if (!(thousands == 9 && hundreds == 9 && tens == 9 && ones == 9))
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	// Print a newline character and return 0 to indicate success
	putchar('\n');
	return (0);
}
