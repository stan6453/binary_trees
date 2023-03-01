#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * Return: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/*
	 * for level order traversal, i used a queue.
	 * where the node to be processed are taken from the front (lindex)
	 * and the new nodes are added to the back (rindex)
	 */
	const binary_tree_t *treelist[100], *temp;
	int lindex = 0, rindex = 0;

	if (tree == NULL)
		return;
	if (func == NULL)
		return;

	treelist[rindex++] = tree;

	while (rindex > lindex)
	{
		temp = treelist[lindex++];
		if (temp->left != NULL)
			treelist[rindex++] = temp->left;
		if (temp->right != NULL)
			treelist[rindex++] = temp->right;
		func(temp->n);
	}
}
