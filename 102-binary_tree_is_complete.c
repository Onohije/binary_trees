#include "binary_trees.h"

/**
 * tree_height - To measures the height of a binary tree
 * @node: Pointer to the sub_tree to measure the height
 * Return: Returns the height or 0 if sub_tree is NULL
 **/
int tree_height(const binary_tree_t *node)
{
	int leftHeight, rightHeight;

	if (node == NULL)
		return (0);

	leftHeight = tree_height(node->left);
	rightHeight = tree_height(node->right);

	return (1 + (leftHeight > rightHeight ? leftHeight : rightHeight));
}
/**
 * update_array - Populates the contents of an array from a
 * binary tree.
 * @array: Being the array to be populated with data.
 * @tree: Being the binary tree to collect data from.
 * @index: Being the index of the current node in the
 * array.
 */
void update_array(int *array, const binary_tree_t *tree, int index)
{
	if (tree == NULL)
	{
		array[index] = 0;
		return;
	}

	array[index] = tree->n;
	update_array(array, tree->left, 2 * index + 1);
	update_array(array, tree->right, 2 * index + 2);
}
/**
 * tree_to_array - To converts a binary tree to array representation.
 * @tree: Being the tree to convert to its equivallent array representation.
 * Return: pointer to the start of the array or NULL if tree is NULL.
 */
int *tree_to_array(const binary_tree_t *tree)
{
	int height, i;
	int *array;

	if (tree == NULL)
		return (NULL);

	height = tree_height(tree);
	array = malloc(((1 << height) - 1) * sizeof(int));
	if (array == NULL)
		return (NULL);

	/**
	 * NOTE TO SELF:
	 * In the future adapt this to array of `binary_tree_t`
	 * instead of array of int, to escape having to set empty
	 * nodes to 0.
	 */
	for (i = 0; i < ((1 << height) - 1); i++)
		array[i] = 0;
	update_array(array, tree, 0);

	return (array);
}
/**
 * binary_tree_is_complete - To checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is complete or 0 if otherwise or tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int *array = NULL;
	int height, nodes_total, i, null_flag = 0;

	printf("from: binary_tree_is_complete\n");
	if (tree == NULL)
		return (0);

	array = tree_to_array(tree);
	height = tree_height(tree);
	nodes_total = (1 << height) - 1;

	for (i = 0; i < nodes_total; i++)
	{
		printf("array index [%d] = %d\n", i, array[i]);
		if (array[i] == 0 && null_flag == 0)
		{
			null_flag = 1;
			continue;
		}
		if (array[i] != 0 && null_flag == 1)
		{
			free(array);
			return (0);
		}
	}
	free(array);
	return (1);
}
