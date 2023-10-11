#include "search_algos.h"

int binary_search_helper(int *array, int value,
			 size_t low, size_t high);
size_t min(size_t a, size_t b);

/**
 * min - finds the minimum of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: minimum value
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * binary_search_helper - searches for a value in a sorted array of
 *			integers using the Binary search algorithm
 * @array: pointer to first element of array to seach in
 * @value: value to search for
 * @low: starting index
 * @high: ending index
 *
 * Return: index where value is located.
 *	Otherwise -1 if value not found or array is NULL
 */

int binary_search_helper(int *array, int value,
			 size_t low, size_t high)
{
	size_t mid, x;

	if (!array)
		return (-1);

	while (low <= high)
	{
		mid = (low + high) / 2;
		printf("Searching in array: ");
		for (x = low; x <= high; x++)
			printf("%i%s", array[x], x == high ? "\n" : ", ");
		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return ((int)mid);
	}

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted array of
 *			integers using an exponential search algorithm
 * @array: pointer to first element of array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located.
 *	-1, If value is not present in array or if array is NULL.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t low, high, x = 1;

	if (!array || size == 0)
		return (-1);

	while (x < size && array[x] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       x, array[x]);
		x *= 2;
	}

	low = x / 2;
	high = min(x, size - 1);
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_helper(array, value, low, high));
}