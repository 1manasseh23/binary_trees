#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 *
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	current = *tree;
	while (current)
	{
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				current->left = binary_tree_node(current, value);
				return (current->left);
			}
			current = current->left;
		}
		else if (value > current->n)
		{
			if (current->right == NULL)
			{
				current->right = binary_tree_node(current, value);
				return (current->right);
			}
			current = current->right;
		}
		else
		{
			return (NULL);
		}
	}

	return (NULL);
}
