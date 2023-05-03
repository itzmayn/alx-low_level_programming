#include "lists.h"

/**
 * insert_nodeint_at_index - insert an element at the given index of a list
 * @head: a pointer to a pointer to the first node
 * @idx: the index at which to add the new node (starting at 0)
 * @n: the list element
 *
 * Return: If memory allocation fails or the index is invalid, return NULL.
 * Otherwise, return a pointer to the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *new_node, *temp_node;
    unsigned int i;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    temp_node = *head;
    for (i = 0; temp_node && i < idx - 1; i++)
        temp_node = temp_node->next;

    if (!temp_node)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = temp_node->next;
    temp_node->next = new_node;

    return (new_node);
}
