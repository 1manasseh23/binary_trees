#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using
 * level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node
 * takes an int parameter.
 *
 * Description: The function visits each node level by level,
 * from left to right. If tree or func is NULL, it does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t **queue;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}
