#include "main.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

/**
 * multiplies - multiplies two positive numbers represented as strings
 * @num1: First number
 * @num2: Second number
 */
void multiplies(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, k, carry, size;
	int *result;

	/* Calculate lengths of input numbers */
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	/* Allocate memory for result */
	size = len1 + len2;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	/* Initialize result array with 0 */
	for (i = 0; i < size; i++)
		result[i] = 0;

	/* multiplies each digit of num1 with num2 */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1, k = size - (len1 - i); j >= 0; j--, k--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0') + carry + result[k];
			result[k] = product % 10;
			carry = product / 10;
		}
		if (carry > 0)
			result[k] += carry;
	}

	/* Skip leading zeros in result */
	i = 0;
	while (i < size - 1 && result[i] == 0)
		i++;

	/* Print result */
	if (i == size)
		printf("0\n");
	else
	{
		for (; i < size; i++)
			printf("%d", result[i]);
		printf("\n");
	}

	/* Free dynamically allocated memory */
	free(result);
}

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return 98;
	}

	char *num1 = argv[1];
	char *num2 = argv[2];

	/* Check if num1 and num2 are composed of digits only */
	for (int i = 0; num1[i]; i++)
	{
		if (num1[i] < '0' || num1[i] > '9')
		{
			printf("Error\n");
			return 98;
		}
	}

	for (int i = 0; num2[i]; i++)
	{
		if (num2[i] < '0' || num2[i] > '9')
		{
			printf("Error\n");
			return 98;
		}
	}

	multiplies(num1, num2);

	return 0;
}
