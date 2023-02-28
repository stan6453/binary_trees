#include "binary_trees.h"

/**
 * binary_tree_sibling -  that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return:  pointer to the sibling node
 *  If node is NULL or the parent is NULL, return NULL
 *  If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->right != NULL && parent->right != node)
		return (parent->right);
	if (parent->left != NULL && parent->left != node)
		return (parent->left);
	return (NULL);
}
