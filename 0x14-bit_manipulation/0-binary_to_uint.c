#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number as an unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int k = 1; /* current power of 2 */
	unsigned int i = 0; /* accumulated result */
	int c; /* counter */
	unsigned int len; /* length of input string */

	if (b == NULL) /* check for NULL input */
		return (0);

	len = _strlen(b); /* get length of input string */

	for (c = len - 1; c >= 0; c--) /* loop through input string from right to left */
	{
		if (b[c] != '0' && b[c] != '1') /* check for invalid characters */
			return (0);
		if (b[c] == '1') /* if current character is 1, add current power of 2 to result */
		{
			i += k;
		}
		k *= 2; /* multiply current power of 2 by 2 for next iteration */
	}
	return (i);
}
