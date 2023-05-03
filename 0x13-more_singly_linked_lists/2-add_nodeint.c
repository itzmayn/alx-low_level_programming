#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: A pointer to a pointer to the head node of the list
 * @n: The value to be added to the new node
 *
 * Return: If the memory allocation fails or head is NULL, return NULL.
 * Otherwise, return the address of the new node.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    /* Declare a pointer for the new node */
    listint_t *new_node;

    /* Check if head is NULL */
    if (!head)
        return (NULL);

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    /* Initialize the new node's data and next pointers */
    new_node->n = n;
    new_node->next = *head;

    /* Update the head pointer to point to the new node */
    *head = new_node;

    /* Return the address of the new node */
    return (new_node);
}
