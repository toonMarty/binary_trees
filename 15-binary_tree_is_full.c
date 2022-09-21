#include "binary_trees.h"

/**
 * is_full_recursive - a function that checks
 * whether a binary tree is full
 * @tree: a pointer to  the root node of the
 * tree
 * Return: 0 if tree is not full else 1.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
				(tree->left == NULL && tree->right != NULL) ||
				is_full_recursive(tree->left) == 0 ||
				is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}
/**
 * binary_tree_is_full - a function that checks
 * if a binary tree is full
 * @tree:  a pointer to the root node of the tree to check
 * Return: If tree is NULL function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
