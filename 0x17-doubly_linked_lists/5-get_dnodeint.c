#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list
 * @head: Pointer to the head node of the list
 * @index: The index of the node to retrieve
 * Return: Pointer to the nth node, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int counter = 0;

    while (counter < index)
    {
        if (head == NULL)   // If the head is NULL, the list is empty or the index is out of range
            return (NULL);
        head = head->next;  // Move to the next node
        counter++;
    }

    return (head);
}
