#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at the given index of a list
 * @head: a pointer to a pointer to the first node
 * @index: the index of the node to delete
 *
 * Return: 1 upon success, -1 upon failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *next;

	if (!head || !*head)
		return (-1);

	if (index > 0)
		return (delete_nodeint_at_index(&(*head)->next, index - 1));

	next = (*head)->next;
	free(*head);
	*head = next;

	return (1);
}
