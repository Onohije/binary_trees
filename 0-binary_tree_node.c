#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a binary tree.
 * @parent: Pointer to a parent node to the new node to be created.
 * @value: The value/data of the node to be created.
<<<<<<< HEAD
 * Return: Pointer to the newly created node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
