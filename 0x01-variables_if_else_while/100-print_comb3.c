#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;
	int i;

	for (n = 0 ; n < 10 ; n++)
	{
		for (i = n + 1 ; i < 10 ; i++)
		{
			putchar('0' + n);
			putchar('0' + i);
			if (n < 8 || i < 9)
			{
				putchar(',');
				putchar(32);
			}
		}
	}
	putchar('\n');
	return (0);
}
