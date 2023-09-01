#include "binary_trees.h"

/**
 * binary_tree_leaves - To counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to
 * count the number of leaves. if tree is NULL the function
 * must return 0. A NULL pointer is not regarded as a leaf.
 * Return: The total number of leaves present in the tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
