#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return:  pointer to the uncle node
 *  If node is NULL, return NULL
 *  If node has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	grandparent = node->parent->parent;
	parent = node->parent;

	if (grandparent->right != NULL && grandparent->right != parent)
		return (grandparent->right);
	if (grandparent->left != NULL && grandparent->left != parent)
		return (grandparent->left);
	return (NULL);
}
