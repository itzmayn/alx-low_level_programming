#include "main.h"

/**
* alloc_grid - returns a pointer to a
* 2 dimensional array of integers.
* @width: width of array
* @height: height of array
*
* Return: pointer to the array
*/
int **alloc_grid(int width, int height)
{
	if (width == 0 || height == 0)
		return (NULL);

	int **array = (int **)malloc(sizeof(int *) * height);
	if (array == NULL)
		return (NULL);

	for (int i = 0; i < height; i++)
	{
		array[i] = (int *)malloc(sizeof(int) * width);
		if (array[i] == NULL)
		{
			for (int j = 0; j < i; j++)
				free(array[j]);
			free(array);
			return (NULL);
		}
		for (int j = 0; j < width; j++)
			array[i][j] = 0;
	}
	return (array);
}
