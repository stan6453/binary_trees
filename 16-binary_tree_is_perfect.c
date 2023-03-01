#include "binary_trees.h"



int is_perfect(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return:  1 if tree is perfect, 0 otherwise.
 *  If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect(tree));
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return:  1 if tree is perfect, 0 otherwise.
 *  If tree is NULL, return 1
 */
int is_perfect(const binary_tree_t *tree)
{
	/*
	 * the idead here is that for a tree to be perfect,
	 * it must have 0 or 2 children and the left height
	 * must be equal to the right height.
	 * this condition  is applied recursively on the
	 * root node first, down to its children
	 * till we get to the leaf nodes
	 */
	size_t lheight, rheight, has2children, issameheight;

	if (tree == NULL)
		return (1);

	has2children = (tree->left != NULL && tree->right != NULL) ||
		(tree->left == NULL && tree->right == NULL);

	lheight = binary_tree_height(tree->left);
	rheight = binary_tree_height(tree->right);

	issameheight = (lheight - rheight == 0);

	if (has2children && issameheight)
		return (is_perfect(tree->left) && is_perfect(tree->right));
	else
		return (0);
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
