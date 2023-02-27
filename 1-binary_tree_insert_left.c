#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to put in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;
	binary_tree_t *lefttemp;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	/*store the left node of parent (this counld be null)*/
	lefttemp = parent->left;
	parent->left = node;

	node->parent = parent;
	node->left = lefttemp;
	node->right = NULL;
	node->n = value;
	if (lefttemp != NULL)
		lefttemp->parent = node;

	return (node);
}
