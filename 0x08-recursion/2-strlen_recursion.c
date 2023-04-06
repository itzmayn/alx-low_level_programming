#include "main.h"

/**
 * _strlen_recursion - get length of a string using recursion
 * @s: char pointer to the string
 *
 * Return: size of the string
 */
int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	
	return (_strlen_recursion(s + 1) + 1);
}
