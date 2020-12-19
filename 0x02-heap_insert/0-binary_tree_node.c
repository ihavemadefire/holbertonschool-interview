#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_node
 * @parent: Parent
 * @value: Value
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	/* malloc and assign */
	new = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	/* If parent is null, start the tree */
	if (parent == NULL)
       	{
		parent = new;
		return (new);
	}
	else
	{
		new->parent = parent;
		return (new);
	}
	return (NULL);
}
