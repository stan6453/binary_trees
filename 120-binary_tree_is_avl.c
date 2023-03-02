#include "binary_trees.h"


int int_binary_tree_height(const binary_tree_t *tree);
int is_avl(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *  If tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree));
}

/**
 * is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *  If tree is NULL, return 0
 */
int is_avl(const binary_tree_t *tree)
{
	/*
	 * the idea is that for a tree to be an avl tree,
	 * it needs to have a balance of -1, 0, or 1
	 * and it needs to be a binary serch tree i.e.
	 * all the elements at the left subtree should be less than the root,
	 * and all the elements at the rigth subtree should be greater than the root
	 * this two condition is tested recursively,
	 * starting fron the root node down to the leaf nodes
	 */

	int lheight, rheight, balfact;
	int is_balanced, is_bst;

	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lheight = int_binary_tree_height(tree->left);
	rheight = int_binary_tree_height(tree->right);
	balfact = lheight - rheight;

	if (balfact == 0 || balfact == 1 || balfact == -1)
		is_balanced = 1;
	else
		is_balanced = 0;

	is_bst = tree_is_bst(tree->left, tree->n, 0) &&
		tree_is_bst(tree->right, tree->n, 1);

	if (is_balanced && is_bst)
		return (is_avl(tree->left) && is_avl(tree->right));
	return (0);
}

/**
 * int_binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: return the height of the tree
 *  If tree is NULL, your function must return 0
 */
int int_binary_tree_height(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lheight = int_binary_tree_height(tree->left);
	rheight = int_binary_tree_height(tree->right);

	return ((lheight > rheight ? lheight : rheight)  + 1);
}


/**
 * tree_is_bst - checks if all the nodes in a tree are greater or less than
 * a value based on the pos value.
 * @tree: tree to check
 * @value: value to compare to tree value
 * @pos: pos of 0 means tree value has to be less than value.
 *  pos of 1 means tree value has to be greater tan value
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

