#include "main.h"

/**
* str_concat - a function that concatenates two strings.
* @s1: First string
* @s2: Second string
* Return: NULL in case of failure, but pointer to new string in
* case of success
*/
char *str_concat(char *s1, char *s2)
{
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	int len1 = 0, len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	char *concat_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat_str == NULL)
		return (NULL);

	int concat_index = 0;
	for (int index = 0; s1[index]; index++)
		concat_str[concat_index++] = s1[index];

	for (int index = 0; s2[index]; index++)
		concat_str[concat_index++] = s2[index];

	concat_str[concat_index] = '\0';

	return (concat_str);
}
