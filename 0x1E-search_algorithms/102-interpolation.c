#include "search_algos.h"

/**
 * interpolation_search - performs interpolation search
 * @array: the integer array
 * @size: its size
 * @value: value to search for
 *
 * Return: the index found or -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos = 0, low = 0, high = size - 1;

	/* Check for NULL array or zero size */
	if (!array || size == 0)
		return (-1);

	while (1)
	{
		/* Calculate the estimated position using interpolation formula */
		pos = low + (((double)(high - low) /
			  (array[high] - array[low])) * (value - array[low]));

		/* Check if the estimated position is out of range */
		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}

		/* Print the value being checked */
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		/* Check if the value is found */
		if (array[pos] == value)
			return (pos);
		else if (array[pos] > value)
			high = pos - 1;
		else
			low = pos + 1;
	}

	/* Value not found */
	return (-1);
}
