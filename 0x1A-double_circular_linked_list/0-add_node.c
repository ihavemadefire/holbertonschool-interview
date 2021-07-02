#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add node to end
 * @list: The List
 * @str: The String
 * Return: List
 */
List *add_node_end(List **list, char *str)
{
	List *ret, *end;

	ret = malloc(sizeof(List));
	if (ret == NULL)
		return (NULL);
	ret->str = strdup(str);
	if (!ret->str)
		return (NULL);
	ret->next = ret;
	if (*list == NULL)
	{
		ret->prev = ret;
		*list = ret;
		return (*list);
	}
	end = *list;
	while (end->next && end->next != *list)
		end = end->next;
	end->next = ret;
	ret->prev = end;
	ret->next = *list;
	(*list)->prev = ret;
	end = ret;
	return (end);
}

/**
 * add_node_begin - add Node to beginning
 * @list: The List
 * @str: The String
 * Return: void
 */
List *add_node_begin(List **list, char *str)
{
	List *ret, *end;

	ret = malloc(sizeof(List));
	if (ret == NULL)
		return (NULL);
	ret->str = strdup(str);
	if (!ret->str)
		return (NULL);
	if (*list == NULL)
	{
		ret->prev = ret;
		ret->next = ret;
		*list = ret;
		return (*list);
	}
	end = *list;
	while (end->next && end->next != *list)
		end = end->next;
	(*list)->prev = ret;
	ret->next = *list;
	ret->prev = end;
	end->next = ret;
	*list = ret;
	return (*list);
}
