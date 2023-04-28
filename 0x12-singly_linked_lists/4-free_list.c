#include "lists.h"

/**
 * free_list - free a linked list and all its nodes
 * @head: a pointer to the first node of the list
 *
 * Description: This function frees all the nodes of the linked list starting
 * from the first node pointed to by head. It also frees the memory allocated
 * for the strings stored in each node.
 */
void free_list(list_t *head)
{
	/* If head is NULL, then we have reached the end of the list */
	if (!head)
		return;

	/* Recursively free the rest of the list starting from head->next */
	free_list(head->next);

	/* Free the memory allocated for the string in the current node */
	free(head->str);

	/* Free the memory allocated for the current node */
	free(head);
}
