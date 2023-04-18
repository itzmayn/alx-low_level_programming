#include "main.h"

/**
* argstostr - concatenates all the arguments of your program
* @ac: count of args passed to the function
* @av: array of arguments
*
* Return: pointer to the new string
*/
char *argstostr(int ac, char **av)
{
	if (ac == 0 || av == NULL)
		return (NULL);

	int total_len = 0;
	for (int i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);

		int len = 0;
		while (av[i][len] != '\0')
			len++;

		total_len += len + 1; /* add 1 for newline character */
	}

	char *new_string = (char *)malloc(sizeof(char) * (total_len + 1));
	if (new_string == NULL)
		return (NULL);

	int index = 0;
	for (int i = 0; i < ac; i++)
	{
		int len = 0;
		while (av[i][len] != '\0')
		{
			new_string[index++] = av[i][len++];
		}
		new_string[index++] = '\n';
	}

	new_string[index] = '\0';

	return (new_string);
}
