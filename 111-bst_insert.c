#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *newnode;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		newnode = binary_tree_node(*tree,value);
		*tree = newnode;
		return (newnode);
	}



}
