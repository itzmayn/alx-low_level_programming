#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to head of linked list
 *
 * Return: Number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *tmp;

    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        tmp = head;
        head = head->next;

        if (tmp <= head)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            exit(98);
        }
    }

    return (count);
}
