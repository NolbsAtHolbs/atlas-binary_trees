#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL) /* check if parent is NULL */
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t)); /* alloc memory for new node */
	if (new_node == NULL)
		return (NULL);
	new_node->n = value; /* initialize the new node */
	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;
	/* if parent already has a right-child, update its parent pointer */
	if (parent->right != NULL)
		parent->right->parent = new_node;
	parent->right = new_node; /* set new node as right-child of parent */
	return (new_node);
}
