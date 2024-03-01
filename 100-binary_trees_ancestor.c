#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = first;

	if (first == NULL || second == NULL)
		return (NULL);

	while (ancestor)
	{
		const binary_tree_t *temp = second;

		while (temp)
		{
			if (temp == ancestor)
				return ((binary_tree_t *)ancestor);

			temp = temp->parent;
		}

		ancestor = ancestor->parent;
	}

	return (NULL);
}
