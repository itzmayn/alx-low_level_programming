#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers followed by a newline.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers to be passed.
 *
 * Return: Nothing.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args; /* Declare a variable of type va_list */
    unsigned int i; /* Declare a variable to store the current index */
    
    /* Start the variable argument list */
    va_start(args, n);
    
    /* Loop through the arguments and print them */
    for (i = 0; i < n; i++)
    {
        /* Print the current argument */
        printf("%d", va_arg(args, int));
        
        /* If we're not at the end of the list and there's a separator, print it */
        if (i != n - 1 && separator != NULL)
        {
            printf("%s", separator);
        }
    }
    
    /* Print a newline character */
    printf("\n");
    
    /* End the variable argument list */
    va_end(args);
}
