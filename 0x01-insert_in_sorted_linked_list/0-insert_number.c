#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - evaluates code for node and inserts a new value
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *tmp;

	if (head == NULL)
		return (NULL);
	new_node = (listint_t *) malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	if (*head == NULL || (*head)->n >= number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	/* If Node is in the middle  */
	tmp = *head;
	while (tmp->next != NULL && tmp->next->n < number)
	{
		tmp = tmp->next;
	}
	/* if node is at the end */
	new_node->next = tmp->next;
	tmp->next = new_node;
	return (new_node);
}
