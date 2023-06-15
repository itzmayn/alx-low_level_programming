#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a doubly linked list
 * @h: Pointer to a pointer to the head node of the list
 * @idx: Index where the new node should be inserted (starting at 0)
 * @n: The data integer for the new node
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *temp = *h;
    unsigned int i = 0;

    if (idx == 0)   // Insert at the beginning
        return add_dnodeint(h, n);

    while (i < idx - 1)  // Traverse to the node before the desired index
    {
        if (temp == NULL)
            return NULL;
        temp = temp->next;
        i++;
    }

    if (temp == NULL)   // Index is out of range
        return NULL;

    if (temp->next == NULL)  // Insert at the end
        return add_dnodeint_end(h, n);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;

    return new_node;
}
