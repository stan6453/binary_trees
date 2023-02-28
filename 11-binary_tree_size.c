#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: the size of a binary tree
 *  If tree is NULL, your function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sleft, sright;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	sleft = binary_tree_size(tree->left);
	sright = binary_tree_size(tree->right);

	return (sleft + sright + 1);
}
