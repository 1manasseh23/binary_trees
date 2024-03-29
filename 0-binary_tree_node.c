#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - A . function that create a binary tree node
 * @parent: Is a pointer to the parent node of the node to create
 * @value: Is the value to put in the new node
 * Return: The pointer to the created node or NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
