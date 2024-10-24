#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to node to insert left-child in
 * @value: value to store in the new node
 * Return: pointer to created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL) /* check if parent is NULL */
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t)); /* alloc memory for new node */
	if (new_node == NULL)
		return (NULL);
	new_node->n = value; /* initialize the new node */
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;
	/* if parent already has a left-child, update its parent pointer */
	if (parent->left != NULL)
		parent->left->parent = new_node;
	parent->left = new_node; /* set new node as left-child of parent */
	return (new_node);
}
