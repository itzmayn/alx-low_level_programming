#include "lists.h"

/**
 * print_list - Prints all the elements of a linked list.
 *
 * @h: Pointer to the head of the list.
 *
 * Description: Prints each element of the linked list, prefixed by its length,
 *              formatted using "[%d] %s\n". If a list item is NULL, print it
 *              as "(nil)" with zero length.
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_list(const list_t *h)
{
    /* If h is not NULL, we print the contents of the current node and
     * recursively call the print_list function on the next node until we
     * reach the end of the list. */
    if (h)
    {
        /* If the str element of the current node is not NULL, print its
         * length and contents using the specified format. Otherwise, print
         * "(nil)" with a length of 0. */
        if (h->str)
            printf("[%d] %s\n", h->len, h->str);
        else
            printf("[0] (nil)\n");

        /* Recursively call the print_list function on the next node and add 1
         * to the result to include the current node in the count. */
        return (print_list(h->next) + 1);
    }

    /* If h is NULL, we've reached the end of the list, so return 0. */
    return (0);
}
