#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree
 * using pre-order traversal.
 * @tree: A pointer to the root node of
 * the tree to traverse.
 * @func: A pointer to a function to call for each
 * node (takes an int parameter).
 *
 * Description: The function applies the given function to each node
 * in the tree using pre-order traversal (Root-Left-Right).
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);
}
