#include "binary_trees.h"

/**
 * is_leaf - a function that checks if a
 * node is a leaf
 * @node: node to check
 * Return: if leaf return 1 else 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - function that returns depth
 * @tree: pointer to the node
 * Return: 1 if leaf else 0
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf -  Get the leaf object
 * @tree: pointer to the root node of a tree
 * Return: a pointer to the first leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - a function that
 * checks for a perfect node recursively
 * @tree: a pointer to  the root of the node to check
 * @leaf_depth: depth of the leaf
 * @level: level of the tree
 * Return: 1 if tree is perfect else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - a function that checks
 * if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: If tree is NULL function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
