#include <stdio.h>
#include "lists.h"

/**
 * check_cycle -
 * @list - Points to head node of list
 * Return: 
 */
int check_cycle(listint_t *list)
{
    listint_t *tortoise = list;
    listint_t *hare = list;

    while (hare != NULL)
    {
        hare = hare->next->next;
        tortoise = tortoise->next; 
        if (hare == tortoise)
            return (1);
    }

    return (0);
}