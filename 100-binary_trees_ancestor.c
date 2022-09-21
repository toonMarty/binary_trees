#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the lowest
 * common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *m, *p;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	m = first->parent;
	p = second->parent;

	if (first == p || !m || (!m->parent && p))
		return (binary_trees_ancestor(first, p));
	else if (m == second || !p || (!p->parent && m))
		return (binary_trees_ancestor(m, second));

	return (binary_trees_ancestor(m, p));
}
