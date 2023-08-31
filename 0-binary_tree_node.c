#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new node in a binary tree.
 * @parent: Pointer to a parent node to the new node to be created.
 * @value: The value/data of the node to be created.
 * Return: pointer to the newly created node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL; // Memory allocation failed
    }

    new_node->val = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}
