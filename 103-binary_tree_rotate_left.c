#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a
 * left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return:  a pointer to the new root node
 * of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tempNode;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	pivot = tree->right;
	tempNode = pivot->left;
	pivot->left = tree;
	tree->right = tempNode;

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
