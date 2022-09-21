#include "binary_trees.h"
/**
 * bst_search - a function that searches for a
 * value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
