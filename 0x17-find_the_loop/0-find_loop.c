#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - check the code for Holberton School students.
 * @head: begining of linked list
 * Return: Either address of loop or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *tortoise;
    listint_t *hare;

    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return NULL;

    tortoise = head;
    hare = head;
    
    while (hare->next != NULL &&  hare->next->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (hare == tortoise)
        {
            tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
            return (tortoise);
        }
    }

    return NULL;
}
