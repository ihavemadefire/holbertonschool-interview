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
	skiplist_t *ret;
	skiplist_t *exp;

	if (list == NULL)
		return NULL
	exp = list;
	ret = list;
	while (ret->express != NULL && ret->next != NULL)
	{            
		if (ret->express->n > value)
		{
			exp = ret;
			ret = ret->express;
			printf("Value checked at index [%zu] = [%d]\n", ret->index, ret->n);
			break;
		}
	else
	{
		exp = ret;
		ret = ret->express;
		printf("Value checked at index [%zu] = [%d]\n", ret->index, ret->n);
	}
	}
	if (!(ret->n > value))
	{
		exp = ret;
		while (ret->next != NULL)
		{
			ret =ret->next;
		}
	}
	printf("Value found between indexes [%zu] and [%zu]\n", exp->index, ret->index);
	while (exp->next != NULL && exp->n <= value)
	{
		printf("Value checked at index [%zu] = [%d]\n", exp->index, exp->n);
		if (exp->n == value)
			return exp;
		exp = exp->next;
	}
	printf("Value checked at index [%zu] = [%d]\n", exp->index, exp->n);
	return NULL;
}
