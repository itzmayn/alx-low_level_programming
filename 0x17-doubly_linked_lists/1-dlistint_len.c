#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a doubly linked list
 * @h: Pointer to the head node of the list
 * Return: The number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
    int count_node = 0;

    while (h != NULL)
    {
        h = h->next;    // Move to the next node
        count_node++;   // Increment the node count
    }

    return (count_node);
}
