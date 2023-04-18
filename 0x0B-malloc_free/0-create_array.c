#include "main.h"

/**
* create_array - creates an array of chars,
* initializes it with a specific char.
* @size: Size of the array
* @c: Character to insert
* Return: NULL if size is zero or if it fails,
* pointer to array if everything is normal.
*/
char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return (NULL);

	char *array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (unsigned int index = 0; index < size; index++)
		array[index] = c;

	return (array);
}
