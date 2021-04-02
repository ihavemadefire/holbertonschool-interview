#include <stdio.h>
#include <stdlib.h>

#include "search.h"

/**
 * linear_skip - traverses the express lane to search
 * @list: pointer to list
 * @value: value to be searched for
 * Return: pointer to found index
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *r, *e;

	if (list == NULL)
		return NULL
	e = list;
	r = list;
	while (r->express != NULL && r->next != NULL)
	{
		if (r->express->n > value)
		{
			e = r;
			r = r->express;
			printf("Value checked at index [%zu] = [%d]\n", r->index, r->n);
			break;
		}
	else
	{
		e = r;
		r = r->express;
		printf("Value checked at index [%zu] = [%d]\n", r->index, r->n);
	}
	}
	if (!(r->n > value))
	{
		e = r;
		while (r->next != NULL)
		{
			r = r->next;
		}
	}
	printf("Value found between indexes [%zu] and [%zu]\n", e->index, r->index);
	while (e->next != NULL && e->n <= value)
	{
		printf("Value checked at index [%zu] = [%d]\n", e->index, e->n);
		if (e->n == value)
		  return (e);
		e = e->next;
	}
	printf("Value checked at index [%zu] = [%d]\n", e->index, e->n);
	return (NULL);
}
