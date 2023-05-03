#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked list
 * @h: A pointer to the first node of the list
 *
 * Return: The number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
    /* Initialize a counter for the number of nodes */
    size_t count = 0;

    /* Traverse the list until the end is reached */
    while (h != NULL)
    {
        /* Increment the count and move to the next node */
        count++;
        h = h->next;
    }

    /* Return the total count of nodes */
    return (count);
}
