#include "lists.h"

/**
 * list_len - Gets the length of a linked list
 * @h: A pointer to the first node of the list
 *
 * Return: The length of the linked list
 */
size_t list_len(const list_t *h)
{
	/* If h is not null, recursively call the function with h->next until h is null */
	if (h != NULL)
		return (list_len(h->next) + 1);

	/* If h is null, return 0 */
	return (0);
}
