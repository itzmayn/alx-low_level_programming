#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the result of simple operations.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
    int num1, num2;
    char *op;

    /* Check for correct number of arguments */
    if (argc != 4)
    {
        printf("Error\n");
        exit(98);
    }

    /* Convert argument strings to integers */
    num1 = atoi(argv[1]);
    op = argv[2];
    num2 = atoi(argv[3]);

    /* Check if operator is valid */
    if (get_op_func(op) == NULL || op[1] != '\0')
    {
        printf("Error\n");
        exit(99);
    }

    /* Check for division by zero */
    if ((*op == '/' && num2 == 0) || (*op == '%' && num2 == 0))
    {
        printf("Error\n");
        exit(100);
    }

    /* Print the result of the operation */
    printf("%d\n", get_op_func(op)(num1, num2));
    return (0);
}
