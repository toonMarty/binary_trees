#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_node - Create a node object
 * @node: pointer to a binary tree node
 * Return: pointer to new node else NULL
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *newNode;

	newNode = malloc(sizeof(levelorder_queue_t));

	if (newNode == NULL)
		return (NULL);

	newNode->node = node;
	newNode->next = NULL;
	return (newNode);
}

/**
 * free_queue - a function that
 * deletes the queue
 * @head: pointer to the first element
 * of the queue
 * Return: nothing
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tempNode;

	while (head != NULL)
	{
		tempNode = head->next;
		free(head);
		head = tempNode;
	}
}

/**
 * push - a function that adds children
 * to a queue
 * @node: a pointer to the binary tree
 * @head: a pointer to the head of the queue
 * @tail: a double to the tail of the queue
 * @func: a pointer to  the function call
 * on node
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void(*func)(int))
{
	levelorder_queue_t *newNode;

	func(node->n);

	if (node->left != NULL)
	{
		newNode = create_node(node->left);

		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}

	if (node->right != NULL)
	{
		newNode = create_node(node->right);

		if (newNode == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

/**
 * pop - a function that pops the head of the
 * queue
 * @head: a double pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tempNode;

	tempNode = (*head)->next;
	free(*head);
	*head = tempNode;
}

/**
 * binary_tree_levelorder - a function that goes through
 * a binary tree using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node. The value
 * in the node must be passed as a parameter to this function.
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;
	head = tail = create_node((binary_tree_t *)tree);

	if (head == NULL)
		return;
	while (head != NULL)
	{
		push(head->node, head, &tail, func);
		pop(&head);
	}
}
