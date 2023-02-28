#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
 * Return: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *treelist[100];
	int index = 0;
	binary_tree_t *temp;

	if (tree == NULL)
		return;
	if (func == NULL)
		return;

	traverse_level(treelist, &index, tree, func);
}
