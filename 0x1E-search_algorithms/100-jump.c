#include "search_algos.h"

/**
 * jump_search - performs jump search
 * @array: the integer array
 * @size: its size
 * @value: value to search for
 *
 * Return: the index found or -1
 */
int jump_search(int *array, size_t size, int value)
{
    // Initialize variables for array traversal and jumping step
	size_t i = 0, j = sqrt(size);

    // Check if the array is NULL
	if (!array)
		return (-1);

    // Perform jump search
	while (i < size && array[i] < value)
	{
        // Print the value being checked
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i += j;  // Jump to the next block
	}

    // Update the block range where the value might be found
	j = i - j;
	printf("Value found between indexes [%lu] and [%lu]\n", j, i);
	i = i >= size ? size - 1 : i;

    // Perform linear search within the identified block
	while (j <= i)
	{
        // Print the value being checked
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);

        // Check if the value is found
		if (array[j] == value)
			return (j);

        // Move to the next element
		j++;
	}

    // Value not found
	return (-1);
}
