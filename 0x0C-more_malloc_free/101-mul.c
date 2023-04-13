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
void multiplies(char *num1, char *num2){
	int len1, len2, i, j, carry;
	int *result;

	len1 = strlen(num1);
	len2 = strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
		print_error();

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			int n1 = num1[i] - '0';
			int n2 = num2[j] - '0';
			int sum = carry + result[i + j + 1] + (n1 * n2);
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}

	i = 0;
	while (i < len1 + len2 && result[i] == 0)
		i++;

	if (i == len1 + len2)
		_putchar('0');
	else
	{
		while (i < len1 + len2)
			_putchar(result[i++] + '0');
	}

	_putchar('\n');
	free(result);
}