#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using
 * pre-order travesal.
 * @tree: Pointer to the root node of the tree to
 * traverse.
 * @func: being a pointer to a function to call for each node,
 * the value in the node is required to be passed into `func`.
 * if `tree` or `func` is NULL do nothing.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->val);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
