#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  pointer to the first node
 * @second:  pointer to the second node
 * Return:  pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(binary_tree_t *first,
		binary_tree_t *second)
{
	int found;

	if (first == NULL)
		return (NULL);

	found = find_node(first, second);

	if (found)
		return (first);
	return (binary_trees_ancestor(first->parent, second));
}

/**
 * find_node - finds a node in a tree
 * @root: node to start search from
 * @node: node to search for
 * Return:  1 of node is found, 0 otherwise
 */
int find_node(const binary_tree_t *root, const binary_tree_t *node)
{
	int lfind, rfind;

	if (node == NULL)
		return (0);
	if (root == NULL)
		return (0);
	if (root == node)
		return (1);

	lfind = find_node(root->left, node);
	rfind = find_node(root->right, node);
	return (maxintnum(lfind, rfind));
}

/**
 * maxintnum - return the maximum of two numbers
 * @num1: first number to compare
 * @num2: second number to compare
 * Return: a number of type size_t
 */
int maxintnum(int num1, int num2)
{
	return (num1 > num2 ? num1 : num2);
}
