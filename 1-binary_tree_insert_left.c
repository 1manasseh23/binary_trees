#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_insert_left - A function that inserts a node
 * as the left-child of another node
 * @parent: Is a pointer to the node to insert the left-child in
 * @value: Is the value to store in the new node
 * Return: A pointer to the created node, or NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	new_node->right = NULL;

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
