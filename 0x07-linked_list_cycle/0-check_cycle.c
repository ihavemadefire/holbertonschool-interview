#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks for cycle
 * @list - Points to head node of list
 * Return: returns 1 if the is a cycle and 0 is not 
 */
int check_cycle(listint_t *list)
{
    listint_t *tortoise = list;
    listint_t *hare = list;

    if (list == NULL)
      return (0);
    
    while (hare != NULL)
    {
        hare = hare->next->next;
        tortoise = tortoise->next; 
        if (hare == tortoise)
            return (1);
    }

    return (0);
}
