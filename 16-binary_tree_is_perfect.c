#include "binary_trees.h"

/**
 * height - To measures the height of a binary tree
 * @node: Pointer to the sub_tree to measure the height
 * Return: Returns the height or 0 if sub_tree is NULL
 **/
int height(const binary_tree_t *node)
{
	int left_Height, right_Height;

	if (node == NULL)
		return (0);

	left_Height = height(node->left);
	right_Height = height(node->right);

	return (1 + (left_Height > right_Height ? left_Height : right_Height));
}
/**
 * balance - To measures the balance factor of a binary tree.
 * @tree: being a pointer to the root node of the tree to meansure
 * its balance factor.
 * Return: balance factor or 0 if tree is NULL
 */
int balance(const binary_tree_t *tree)
{
	int left_Height, right_Height;

	if (tree == NULL)
		return (0);
	left_Height = height(tree->left);
	right_Height = height(tree->right);

	return (left_Height - right_Height);
}
/**
 * is_full - checks if a binary tree is full
 * @tree: being a pointer to the root node of the tree to check.
 * Return: 1 if tree is full or 0 if otherwise or tree is NULL.
 */
int is_full(const binary_tree_t *tree)
{
	/* if a tree or a node is NULL */
	if (tree == NULL)
		return (0);

	/* if it is a leaf node returns 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/**
	 * if it is a subtree,
	 * the return value will hence be determined by
	 * both of the child child nodes.
	 */
	return (is_full(tree->left) && is_full(tree->right));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: being a pointer to the root node of the tree to check
 * Return: 1 if perfect, or 0 if otherwise or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* if tree is NULL or node is a leaf node */
	if (tree == NULL)
		return (0);
	if (balance(tree->left) == 0 && balance(tree->right) == 0 &&
			is_full(tree))
		return (1);
	return (0);
}
