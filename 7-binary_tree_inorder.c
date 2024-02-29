#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_inorder - Performs in-order traversal
 * of a binary tree.
 * @tree: Pointer to the root node of
 * the tree to traverse.
 * @func: Pointer to a function to call for each
 * node (takes an int parameter).
 *
 * Description: This function applies the provided function to
 * each node in the binary tree using in-order traversal.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);

	func(tree->n);

	binary_tree_inorder(tree->right, func);
}
