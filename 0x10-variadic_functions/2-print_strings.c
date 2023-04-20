#include "variadic_functions.h"

/**
 * print_strings - Prints strings separated by a given separator.
 * @separator: The separator to be printed between strings.
 * @n: The number of strings to be printed.
 *
 * Return: Nothing.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list args; /* Declare a variable of type va_list */
    unsigned int i; /* Declare a variable to store the current index */
    char *str; /* Declare a variable to store the current string */
    
    /* Start the variable argument list */
    va_start(args, n);
    
    /* Loop through the arguments and print the strings */
    for (i = 0; i < n; i++)
    {
        /* Get the next string argument */
        str = va_arg(args, char *);
        
        /* If the string is NULL, print "(nil)", otherwise print the string */
        if (str == NULL)
        {
            printf("(nil)");
        }
        else
        {
            printf("%s", str);
        }
        
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
