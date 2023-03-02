#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree:   pointer to the root node of the tree to check
 * Return: 1 if tree is a complete tree, and 0 otherwise
 *  If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (is_complete(tree));

}

/**
 * is_complete - checks if a binary tree is complete
 * @tree:   pointer to the root node of the tree to check
 * Return: 1 if tree is a complete tree, and 0 otherwise
 *  If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	/*the idea is that for a binary */

	if (tree == NULL)
		return (0);

	return (is_complete(tree));

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: return the height of the tree
 *  If tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lheight, rheight;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);

	return (maxnum(lheight, rheight) + 1);
}

/**
 * maxnum - return the maximum of two numbers
 * @num1: first number to compare
 * @num2: second number to compare
 * Return: a number of type size_t
 */
size_t maxnum(size_t num1, size_t num2)
{
	return (num1 > num2 ? num1 : num2);
}


int is_completely_filled()
{
}

int 
