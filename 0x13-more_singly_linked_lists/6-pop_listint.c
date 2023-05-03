#include "lists.h"

/**
 * pop_listint - get the first element of a linked list and remove it
 * @head: a pointer to a pointer to the first node
 *
 * Return: the first list element, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int data; /* Declare a variable to store the data of the first node */
	listint_t *old; /* Declare a pointer to the first node */

	/* If the head pointer is NULL or the first node is NULL, return 0 */
	if (!(head && *head))
		return (0);

	/* Get the data of the first node */
	data = (*head)->n;

	/* Store the address of the first node in a temporary pointer */
	old = *head;

	/* Move the head pointer to the next node */
	*head = old->next;

	/* Free the memory occupied by the first node */
	free(old);

	/* Return the data of the first node */
	return (data);
}
