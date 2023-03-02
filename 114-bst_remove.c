#include "binary_trees.h"


char which_child(bst_t *parent, bst_t *node);
bst_t *get1child(bst_t *node);
/**
 * bst_remove - removes a node from a Binary Search Tree
 *  Once located, the node containing a value equals to value must be removed and freed
 * @root:  pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return:  pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *removenode, *parent, *successornode, successorparent;
	int hasnochildren, has2children;
	char pos, successorpos;

	if (root == NULL)
		return (NULL);

	removenode = bst_search(root, value);

	hasnochildren = removenode->left == NULL && removenode->right == NULL;
	has2children = removenode->left != NULL && removenode->right != NULL;

	parent = removenode->parent; /*could be null*/

	if (hasnochildren)
	{
		if (parent != NULL)
		{
			pos = which_node(parent, removenode);
			if (pos == 'l')
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		free(removenode);	
		return (root);
	}
	else if (has2children)
	{
		successornode = get_smallest_node(removenode->right);
		successorparent = successornode->parent; /*could be removenode*/
		successorpos = which_node(sucessorparent, successor);

		if (successorparent != removenode)
		{
			if (successorpos == 'l')
				successorparent->left = NULL;
			else
				sucessorparent->right = NULL;
		}

		if (parent != NULL)
		{
			pos = which_node(parent, removenode);
			if (pos == 'l')
				parent->left = successornode;
			else
				parent->right = successornode;
		}
		successornode->parent = parent;

		free(removenode);

	}
	else /*has only 1 child*/
	{
		successornode = get1child(removenode);
		if (parent != NULL)
		{
			pos = which_node(parent, removenode);
			if (pos == 'l')
				parent->left = successornode;
			else
				parent->right = successornode;
		}
		successornode->parent = parent;
		free(removenode);
	}
}

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return:  pointer to the node containing a value equals to value
 *  If tree is NULL or if nothing is found, your function must return NULL
 */
bst_t *bst_search(bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else
		return (tree);
}

/**
 * which_child - return if a child is the left node or right node of parent
 * @parent: the parent node
 * @node: the child node
 * Return: 'l' if node is the left child of parent
 *	return 'r' if node is the right child of parent.
 */
char which_child(bst_t *parent, bst_t *node)
{
	if (node == NULL || parent == NULL)
		return (NULL);

	if (parent->right != NULL && parent->right == node)
		return ('r');
	if (parent->left != NULL && parent->left == node)
		return ('l');
	return (NULL);
}

/**
 * get1child - return one of the children of a node
 * @node: node to return a child
 * Return: pointer to the child returned
 */
bst_t *get1child(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	if (node->right != NULL)
		return (node->right);
	if (parent->left != NULL)
		return (node->left);
	return (NULL);
}

/**
 * get_smallest_node - return the smallest node in a BST tree
 * @root: root of tree to return the smallest node
 * Return: pointer to the smallest node in the tree
 */
bst_t *get_smallest_node(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	if (root->left != NULL)
		return (get_smallest_node(root->left));
	else
		return (root);
}
