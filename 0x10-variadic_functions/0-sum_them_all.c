#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Sums all its parameters.
 * @n: The number of parameters passed.
 *
 * Return: If @n is 0, returns 0, otherwise returns the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
    va_list args;  /* Declare a variable of type va_list */
    int sum = 0;   /* Initialize the sum to 0 */
    unsigned int i; /* Declare a variable to store the current index */
    
    /* Start the variable argument list */
    va_start(args, n);
    
    /* Loop through the arguments and add them to the sum */
    if (n != 0)
    {
        for (i = 0; i < n; i++)
        {
            sum += va_arg(args, int);
        }
    }
    
    /* End the variable argument list */
    va_end(args);
    
    /* Return the sum */
    return sum;
}
