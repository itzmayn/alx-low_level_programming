#include "function_pointers.h"

/**
 * array_iterator - Executes a function on each element of an array.
 *
 * @array: The array to be targeted.
 * @size: The size of the array.
 * @action: The function to be executed.
 *
 * Return: void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
    /* Check if array and function pointer are not NULL */
    if (array == NULL || action == NULL)
        return;

    /* Iterate through the array and apply function to each element */
    while (size-- > 0)
    {
        action(*array);
        array++;
    }
}
