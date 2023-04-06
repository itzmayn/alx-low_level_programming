#include "main.h"

/**
 * verifyPrime - verify if a number is prime recursively
 * @objective: number to check for primality
 * @candidate: candidate divisor
 *
 * Return: 1 if prime, 0 if not prime
 */
int verifyPrime(int objective, int candidate)
{
	int indi = objective % candidate;

	if (indi == 0 && candidate < objective)
		return (0);
	else if (indi == 0 && candidate == objective)
		return (1);
	else
		return (verifyPrime(objective, candidate + 1));
}

/**
 * is_prime_number - detect prime number
 * @n: input number
 *
 * Return: 1 if prime, 0 if not prime
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (verifyPrime(n, 2));
}
