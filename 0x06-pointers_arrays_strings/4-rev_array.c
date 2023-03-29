#include "main.h"

/**
 * reverse_array - reverses the order of elements in an integer array
 * @a: array to be reversed
 * @n: size of the array
 * Return: viod
 */
void reverse_array(int *a, int n)
{
    int i, tmp;
    
    for (i = 0; i < n/2; i++)
    {
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
}
