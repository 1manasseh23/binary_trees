#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the tree
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *succParent;
	bst_t *succ;
	bst_t *temp;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		succParent = root;
		succ = root->right;
		while (succ->left != NULL)
		{
			succParent = succ;
			succ = succ->left;
		}
		root->n = succ->n;
		if (succParent != root)
			succParent->left = bst_remove(succParent->left, succ->n);
		else
			succParent->right = bst_remove(succParent->right, succ->n);
	}
	return (root);
}
