#include "lists.h"

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: a pointer to a pointer to the first node of the list
 *
 * Description: This function frees a linked list and sets the head to NULL.
 * It frees each node in the list by recursively calling itself until it
 * reaches the end of the list. When the end is reached, it frees the last node
 * and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
	if (head && *head)
	{
		free_listint2(&(*head)->next);
		free(*head);
		*head = NULL;
	}
}
