#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - check is a singly linked list is a palindrome
 * @head: head of the linked list
 * Return: Always 0.
 */

int is_palindrome(listint_t **head)
{
	if (*head == NULL)
		return (1);
	return (is_palindrome_rec(head, *head));
}

/**
 * is_palindrome_rec - recursive call
 * @left: double point to head of the linked list
 * @right: pointer to right position
 * Return: returns 0 if true, 1 if false
 */

int is_palindrome_rec(listint_t **left, listint_t *right)
{
	int i, j;

	if (right == NULL)
		return (1);

	i = is_palindrome_rec(left, right->next);
	if (i == 0)
		return (0);

	j = (right->n == (*left)->n);

	*left = (*left)->next;

	return (j);
}
