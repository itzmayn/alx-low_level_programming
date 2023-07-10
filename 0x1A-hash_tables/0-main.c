#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - Entry point for the program.
 *
 * Return: Always returns EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    // Create a hash table with a size of 1024
    ht = hash_table_create(1024);

    // Print the memory address of the hash table
    printf("%p\n", (void *)ht);

    return (EXIT_SUCCESS);
}
