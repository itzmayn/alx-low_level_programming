#include "lists.h"

/**
 * get_nodeint_at_index - Get the node at a given index of a linked list.
 * @head: A pointer to the first node.
 * @index: The index of the desired node (starting at 0).
 *
 * Return: If the node does not exist, return NULL. Otherwise, return a pointer
 *         to the requested node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (head && index)
	{
		return (get_nodeint_at_index(head->next, index - 1));
	}
	
	return (head);
}
