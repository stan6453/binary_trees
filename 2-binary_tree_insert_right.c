#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to put in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;
	binary_tree_t *righttemp;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	/*store the right node of parent (this counld be null)*/
	righttemp = parent->right;
	parent->right = node;

	node->parent = parent;
	node->left = NULL;
	node->right = righttemp;
	node->n = value;

	if (righttemp != NULL)
		righttemp->parent = node;

	return (node);
}
