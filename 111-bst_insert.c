#include "binary_trees.h"

bst_t *bst_insert_helper(bst_t *parent, bst_t *tree, char pos, int value);
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *newnode;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		newnode = binary_tree_node(*tree, value);
		*tree = newnode;
		return (newnode);
	}

	return (bst_insert_helper(NULL, *tree, 0, value));
}

/**
 * bst_insert_helper - inserts a value in a Binary Search Tree
 * @parent: the parent of the new node
 * @tree: double pointer to the root node of the BST to insert the value
 * @pos: position of new node relative to parent
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert_helper(bst_t *parent, bst_t *tree, char pos, int value)
{
	bst_t *newnode;

	if (tree == NULL)
	{
		newnode = binary_tree_node(tree, value);
		if (pos == 'l')
			parent->left = newnode;
		else if (pos == 'r')
			parent->right = newnode;
		newnode->parent = parent;
		return (newnode);
	}

	if (value < tree->n)
		return (bst_insert_helper(tree, tree->left, 'l', value));
	else if (value > tree->n)
		return (bst_insert_helper(tree, tree->right, 'r', value));
	else
		return (NULL);
}
