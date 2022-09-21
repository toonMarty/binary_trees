#include "limits.h"
#include "binary_trees.h"

/**
 * is_bst - a function that checks whether a binary
 * tree is a BST
 * @tree:  a pointer to the root node of the tree to check
 * @lo: value of smallest node visited
 * @hi: value of largest node visited
 * Return: 1
 */
int is_bst(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst(tree->left, lo, tree->n - 1) &&
				is_bst(tree->right, tree->n + 1, hi));
	}
	return (1);
}
/**
 * binary_tree_is_bst - a function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: return 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
