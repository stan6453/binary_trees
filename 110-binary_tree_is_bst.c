#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree:  pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 *  If tree is NULL,  return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int lbst, rbst;

	if (tree == NULL)
		return (0);

	lbst = tree_is_bst(tree->left, tree->n, 0);
	rbst = tree_is_bst(tree->right, tree->n, 1);
	return (minnum(lbst, rbst));
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
		c1bst = tree->n < value ? 1 : 0;
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
