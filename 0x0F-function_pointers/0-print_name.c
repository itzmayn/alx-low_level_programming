#include "function_pointers.h"

/**
 * print_name - Prints a name using a function pointer.
 *
 * @name: The name to be printed.
 * @f: The function pointer to print the name.
 *
 * Return: void.
 */
void print_name(char *name, void (*f)(char *))
{
    /* Check if name and function pointer are not NULL */
    if (name == NULL || f == NULL)
        return;

    /* Call function pointer with name argument */
    f(name);
}
