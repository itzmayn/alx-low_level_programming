#include "lists.h"

/**
 * _strlen - calculate the length of a string
 * @str: the string to calculate the length of
 *
 * Return: the length of the string
 */
size_t _strlen(const char *str)
{
	/* initialize a pointer to the start of the string */
	const char *pos = str;

	if (str)
	{
		/* iterate through the string until the null terminator is reached */
		while (*pos)
			++pos;
	}

	/* return the difference between the end and the start pointers */
	return (pos - str);
}

/**
 * _strdup - create a new array containing a copy of the given string
 * @str: a pointer to the string to copy
 *
 * Return: If str is NULL or if memory allocation fails, return NULL.
 * Otherwise a return a pointer to the new copy
 */
char *_strdup(const char *str)
{
	char *dup = NULL;
	size_t size = 0;

	/* if str is NULL, return NULL */
	if (!str)
		return (NULL);

	/* iterate through the string to determine its length */
	while (str[size++])
		;

	/* allocate memory for the duplicate string */
	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);

	/* copy the original string into the duplicate string */
	while (size--)
		dup[size] = str[size];

	/* return the pointer to the duplicate string */
	return (dup);
}

/**
 * add_node_end - add a string at the end of the list
 * @head: a pointer to the address of the first list node
 * @str: the string to add to the list
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = NULL;

	/* if head is NULL, return NULL */
	if (!head)
		return (NULL);

	/* if the head pointer is not NULL, continue traversing the list recursively */
	if (*head)
		return (add_node_end(&(*head)->next, str));

	/* allocate memory for the new node */
	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	/* duplicate the input string */
	new->str = _strdup(str);
	new->len = (_strlen(new->str));
	new->next = *head;

	/* update the head pointer */
	*head = new;

	/* return the pointer to the new node */
	return (new);
}
