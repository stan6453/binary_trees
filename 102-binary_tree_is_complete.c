#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:   pointer to the root node of the tree to check
 * Return: 1 if tree is a complete tree, and 0 otherwise
 *  If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *queue[100];
	int front = 0, back = 0, nullfound = 0;
	const binary_tree_t *temp;

	if (tree == NULL)
		return (0);

	queue[back++] = tree;

	while (front < back)
	{
		temp = queue[front++];

		if (temp == NULL && nullfound == 0)
		{
			nullfound = 1;
		}
		else if (temp != NULL && nullfound == 1)
		{
			return (0);
		}
		else
		{
			if (temp != NULL)
			{
				queue[back++] = temp->left;
				queue[back++] = temp->right;
			}
		}
	}
	return (1);
}
