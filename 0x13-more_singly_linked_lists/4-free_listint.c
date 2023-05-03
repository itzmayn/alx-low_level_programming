#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: A pointer to the first node of the linked list.
 *
 * Return: void.
 */
void free_listint(listint_t *head)
{
	if (head)
	{
		free_listint(head->next);
		free(head);
	}
}
