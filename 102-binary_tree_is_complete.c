#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *current;
	binary_tree_t **queue;
	int front = 0, rear = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		current = queue[front++];
		if (current == NULL)
		{
			while (front < rear)
			{
				if (queue[front++] != NULL)
				{
					free(queue);
					return (0);
				}
			}
		}
		else
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
	}

	free(queue);
	return (1);
}
