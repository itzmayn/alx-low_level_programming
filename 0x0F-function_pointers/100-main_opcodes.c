#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 or 2 in case of failure.
 */
int main(int argc, char *argv[])
{
    int index, bytes;
    int (*address)(int, char **) = main;
    unsigned char opcode;

    // Check if the number of arguments is correct
    if (argc != 2)
    {
        printf("Error\n");
        return (1);
    }

    // Convert the second argument to an integer
    bytes = atoi(argv[1]);

    // Check if the number of bytes is negative
    if (bytes < 0)
    {
        printf("Error\n");
        return (2);
    }

    // Print the opcodes of the function
    for (index = 0; index < bytes; index++)
    {
        opcode = *(unsigned char *)address;
        printf("%.2x", opcode);

        if (index == bytes - 1)
            continue;
        printf(" ");
        address++;
    }
    printf("\n");

    return (0);
}
