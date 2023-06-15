#include "lists.h"

/**
 * add_dnodeint_end - Adds a node at the end of a doubly linked list
 * @head: Pointer to a pointer to the head node
 * @n: The data integer for the new node
 * Return: Pointer to the newly added node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *last_node;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    last_node = *head;
    while (last_node->next != NULL)
        last_node = last_node->next;

    last_node->next = new_node;
    new_node->prev = last_node;

    return (new_node);
}
