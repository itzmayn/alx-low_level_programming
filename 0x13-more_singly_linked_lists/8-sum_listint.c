#include "lists.h"

/**
 * sum_listint - Computes the sum of all elements in a linked list.
 *
 * @head: A pointer to the first node in the list.
 *
 * Return: The sum of all list elements, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
    /* Initialize sum variable */
    int sum = 0;

    /* Traverse the list and add each element's value to the sum */
    while (head)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}
