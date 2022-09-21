#include "binary_trees.h"

/**
 * bst_insert - a function that inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to
 * insert the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *newNode;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			newNode = binary_tree_node(current, value);
			if (newNode == NULL)
				return (NULL);
			return (*tree = newNode);
		}

		if (value < current->n)
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));
			newNode = binary_tree_node(current, value);

			if (newNode == NULL)
				return (NULL);
			return (current->left = newNode);
		}

		if (value > current->n)
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));
			newNode = binary_tree_node(current, value);

			if (newNode == NULL)
				return (NULL);
			return (current->right = newNode);
		}
	}
	return (NULL);
}
