#include "binary_trees.h"

/**
 * binary_tree_is_leaf - To checks if a Node is a leaf.
 * @node: Node to be checked.
 * Return: 1 if node is a leaf and 0 if otherwise or node is NULL.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}
