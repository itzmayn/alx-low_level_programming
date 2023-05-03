#include "lists.h"

/**
 * _reverse_listint - Reverse a linked list (helper function).
 *
 * @current: A pointer to the first node.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *_reverse_listint(listint_t *current)
{
	listint_t *tail;

	if (!current) /* If the current node is NULL, return NULL. */
		return (NULL);

	tail = _reverse_listint(current->next); /* Recursively reverse the rest of the list. */

	if (!tail) /* If the tail is NULL, this is the last node in the original list. */
		return (current);

	/* Reconnect the current node to the end of the reversed list. */
	current->next->next = current;
	current->next = NULL;

	return (tail); /* Return the tail of the reversed list. */
}
