#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
    unsigned int i;

    i = 0;
    while (i < size)
    {
        if (i % 10 == 0 && i > 0)
        {
            printf("\n");
        }
        printf("%02x ", (unsigned char)buffer[i]);
        i++;
    }
    printf("\n");
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[98] = {0};

    simple_print_buffer(buffer, 98);
    memset(buffer, 0x01, 95);
    printf("-------------------------------------------------\n");
    simple_print_buffer(buffer, 98);
    return (0);
}
