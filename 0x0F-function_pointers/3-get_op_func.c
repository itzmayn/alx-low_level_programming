#include "function_pointers.h"

/**
 * int_index - Searches for an integer in an array using a comparison function.
 *
 * @array: The array containing the elements.
 * @size: The number of elements in the array.
 * @cmp: The function to compare values.
 *
 * Return: The index of the first corresponding element or -1 if no element matches.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
    int index = 0;

    /* Check if array and function pointer are not NULL */
    if (array == NULL || cmp == NULL)
        return (-1);

    /* Iterate through the array and compare values using the function pointer */
    for (; index < size; index++)
    {
        if (cmp(array[index]) != 0)
            return (index);
    }

    /* Return -1 if no element matches */
    return (-1);
}
