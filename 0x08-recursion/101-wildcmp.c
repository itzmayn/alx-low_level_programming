#include "main.h"

/**
 * wildcmp - compare strings with wildcard pattern matching
 * @s1: input string 1
 * @s2: input string 2 with wildcard pattern
 *
 * Return: 1 if strings are identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		else if (!*s1)
			return (wildcmp(s1, s2 + 1));
		else
			return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	else if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);
		else
			return (wildcmp(s1 + 1, s2 + 1));
	}
	else
	{
		return (0);
	}
}
