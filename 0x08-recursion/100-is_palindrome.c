#include "main.h"

/**
 * is_palindrome - check if a string is palindrome
 * @s: input string
 *
 * Return: 1 if palindrome, 0 if not palindrome
 */
int is_palindrome(char *s)
{
	int length = 0;
	int finPos = 0;

	while (s[length] != '\0')
		length++;

	finPos = length - 1;

	while (s[0] == s[finPos] && length > 0)
	{
		s++;
		finPos--;
		length -= 2;
	}

	return (length <= 1);
}
