#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 * @node: pointer to the sub_tree to measure the height
 * Return: The height of the subtree, or 0 if the subtree is NULL.
 **/

int height(const binary_tree_t *node)
{
	int left_Height, righ_tHeight;

	if (node == NULL)
		return (0);
	left_Height = height(node->left);
	right_Height = height(node->right);
	return (1 + (lef_tHeight > righ_tHeight ? left_Height : right_Height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to meansure
 * its balance factor.
 * Return: The balance factor of the tree, or 0 if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_Height, right_Height;

	if (tree == NULL)
		return (0);

	left_Height = height(tree->left);
	right_Height = height(tree->right);
	return (left_Height - right_Height);
}
