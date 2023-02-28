#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, 0 if not
 *  If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/*
	 * logic here is that for a tree to be full,
	 * all nodes has to have 0 or 2 children
	 * any node with 1 child and the fn return false.
	 */
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	return (minnum(left, right));
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
