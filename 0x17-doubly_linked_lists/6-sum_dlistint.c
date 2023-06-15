#include "lists.h"

/**
 * sum_dlistint - Computes the sum of the data (n) in a doubly linked list
 * @head: Pointer to the head node of the list
 * Return: The sum of the data in the list
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;     // Add the value of current node to the sum
        head = head->next;  // Move to the next node
    }

    return sum;
}
