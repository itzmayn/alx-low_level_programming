#include "main.h"

/**
 * strtow - Splits a string into an array of words.
 *
 * @str: The string to be split.
 *
 * Return: Pointer to an array of strings (words).
 *         NULL if str == NULL, str == "" or in case of failure.
 */

char **strtow(char *str)
{
	char **words;
	int i, j, k, len, word_count;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			word_count++;
	}

	words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;

		if (str[i] == '\0')
			break;

		len = 0;
		while (str[i + len] != ' ' && str[i + len] != '\0')
			len++;

		words[k] = (char *)malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			for (j = 0; j < k; j++)
				free(words[j]);
			free(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[i++];

		words[k][j] = '\0';
		k++;
	}

	words[k] = NULL;
	return (words);
}
