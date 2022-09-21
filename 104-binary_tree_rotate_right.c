#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a function that performs a
 * right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return:  a pointer to the new root node
 * of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tempNode;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tempNode = pivot->right;
	pivot->right = tree;
	tree->left = tempNode;

	if (tempNode != NULL)
		tempNode->parent = tree;
	tempNode = tree->parent;
	tree->parent = pivot;
	pivot->parent = tempNode;

	if (tempNode != NULL)
	{
		if (tempNode->left == tree)
			tempNode->left = pivot;
		else
			tempNode->right = pivot;
	}
	return (pivot);
}
