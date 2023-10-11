#include "search_algos.h"

/**
 * binary_search - performs binary search
 * @array: the integer array
 * @size: its size
 * @value: value to search for
 *
 * Return: the index found or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i = 0;
	int *a = array;

	/* Check for NULL array */
	if (!array)
		return (-1);

	while (size)
	{
		/* Print the current sub-array being searched */
		printf("Searching in array: ");
		for (i = 0; i < size; i++)
			printf("%d%s", a[i], i + 1 == size ? "\n" : ", ");

		i = (size - 1) / 2;
		
		/* Check if the value is found at the middle of the current sub-array */
		if (a[i] == value)
			return ((a - array) + i);
		else if (a[i] > value)
			size = i;  /* Update the size to search in the left half */
		else
		{
			a += (i + 1);  /* Move the array pointer to the right half */
			size -= (i + 1);  /* Update the size to search in the right half */
		}
	}

	/* Value not found */
	return (-1);
}
