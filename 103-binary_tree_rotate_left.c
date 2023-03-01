#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rightchild, *leftgchild;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (NULL);

	rightchild = tree->right;
	/*could be null or a node*/
	leftgchild = tree->right->left;

	tree->parent = rightchild;
	tree->right = leftgchild;

	rightchild->parent = NULL;
	rightchild->left = tree;

	if (leftgchild != NULL)
		leftgchild->parent = tree;

	return (rightchild);
}
