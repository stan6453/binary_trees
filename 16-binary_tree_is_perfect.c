#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @node: pointer to the root node of the tree to check
 * Return:  1 if tree is perfect, 0 otherwise.
 *  If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lperfect, rperfect;

	if(tree == NULL)
		return (0);

	

	return(minnum(lperfect, rperfect));
}

int is_perfect(binary_tree_t *tree, int *height)
{
	
	lperfect = binary_tree_is_perfect(tree->left);
	rperfect = binary_tree_is_perfect(tree->right);

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
