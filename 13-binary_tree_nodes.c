#include "binary_trees.h"


/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with at least 1 child
 *  If tree is NULL, your function must return 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lcount, rcount;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	lcount = binary_tree_nodes(tree->left);
	rcount = binary_tree_nodes(tree->right);

	return (lcount + rcount + 1);
}
