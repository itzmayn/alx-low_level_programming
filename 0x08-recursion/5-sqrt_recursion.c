#include "main.h"

/**
 * _findsqr - finds the square root recursively
 * @objetive: target number to find square root of
 * @answer: current answer to check
 *
 * Return: square root of objetive or -1 if not found
 */
int _findsqr(int objetive, int answer)
{
	int r = answer * answer;

	if (r < objetive && r != objetive)
		return (_findsqr(objetive, answer + 1));
	else if (r > objetive)
		return (-1);
	else
		return (answer);
}

/**
 * _sqrt_recursion - calculates the square root of a number
 * @n: number
 *
 * Return: the square root of the base number, or -1 if n < 0
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_findsqr(n, 1));
}
