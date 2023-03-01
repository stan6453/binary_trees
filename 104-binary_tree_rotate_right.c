#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *leftchild, *rightgchild;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (NULL);

	leftchild = tree->left;
	/*could be null or a node*/
	rightgchild = tree->left->right;

	tree->parent = leftchild;
	tree->left = rightgchild;

	leftchild->parent = NULL;
	leftchild->right = tree;

	if (rightgchild != NULL)
		rightgchild->parent = tree;

	return (leftchild);
}

