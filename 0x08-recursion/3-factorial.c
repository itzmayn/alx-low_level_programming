#include "main.h"

/**
 * factorial - calculate factorial of a number using recursion
 * @n: integer input
 *
 * Return: factorial of the input number, or -1 if n < 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	
	if (n == 1)
		return (1);
	
	return (n * factorial(n - 1));
}
