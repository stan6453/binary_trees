#include "binary_trees.h"


int is_heap(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *  If tree is NULL, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_heap(tree) && binary_tree_is_complete(tree));
}

/**
 * is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *  If tree is NULL, return 0
 */
int is_heap(const binary_tree_t *tree)
{
	int l_isless, r_isless;

	if (tree == NULL)
		return (1);

	l_isless = tree_is_bst(tree->left, tree->n, 0);
	r_isless = tree_is_bst(tree->right, tree->n, 0);

	if (l_isless && r_isless)
		return (is_heap(tree->left) && is_heap(tree->right));
	return (0);
}

/**
 * tree_is_bst - checks if all the nodes in a tree are greater or less than
 * a value based on the pos value.
 * @tree: tree to check
 * @value: value to compare to tree value
 * @pos: pos of 0 means tree value has to be less than value.
 *  pos of 1 means tree value has to be greater than value
 * Return: 1 if condition holds, 0 if not.
 */
int tree_is_bst(const binary_tree_t *tree, int value, int pos)
{
	int lbst = 1, rbst = 1, c1bst = 1,  c2bst = 1;

	if (tree == NULL)
		return (1);

	lbst = tree_is_bst(tree->left, value, pos);
	rbst = tree_is_bst(tree->right, value, pos);

	if (pos == 0)
	{
		c1bst = tree->n <= value ? 1 : 0;
	}
	else
		c2bst = tree->n > value ? 1 : 0;

	return (minnum(minnum(lbst, rbst), minnum(c1bst, c2bst)));
}

/**
 * minnum - return the minimum of two numbers
 * @num1: first number to compare
 * @num2: second number to compare
 * Return: a number of type int
*/
int minnum(int num1, int num2)
{
	return (num1 < num2 ? num1 : num2);
}

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
