#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth.
 * Return: return the depth of the tree
 *  If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = -1;

	if (tree == NULL)
		return (0);

	while (tree != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
