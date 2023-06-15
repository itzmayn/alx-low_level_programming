#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given position in a doubly linked list
 * @head: Pointer to a pointer to the head node of the list
 * @index: The position in the list to delete the node (starting at 0)
 * Return: 1 if deletion succeeded, or -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *temp;

    if (head == NULL || *head == NULL)
        return -1;

    current = *head;

    if (index == 0)  // Delete the first node
    {
        *head = current->next;
        if (current->next)
            current->next->prev = NULL;
        free(current);
        return 1;
    }

    for (unsigned int i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    if (current == NULL)  // Index is out of range
        return -1;

    temp = current->prev;
    temp->next = current->next;

    if (current->next)
        current->next->prev = temp;

    free(current);
    return 1;
}
