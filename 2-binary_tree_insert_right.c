#include "binary_trees.h"

/**
 * binary_tree_insert_right - To inserts node to the right node of
 * another node, and if parent already has a right child, the
 * new node must take its place, and the old right child must
 * be set as right child of the new node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to which to insert to the new node.
 * Return: Pointer to the newly created node, or NULL if failed
 * or parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->right == NULL)
	{
		new_node->parent = parent;
		parent->right = new_node;
	}
	else
	{
		parent->right->parent = new_node;
		new_node->right = parent->right;
		parent->right = new_node;
		new_node->parent = parent;
	}

	return (new_node);
}
