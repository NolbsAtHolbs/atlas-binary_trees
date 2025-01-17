#include "binary_trees.h"

int binary_tree_height_2(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure balance factor
 * Return: balance factor. If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = (int)binary_tree_height_2(tree->left);
	right_height = (int)binary_tree_height_2(tree->right);
	return (left_height - right_height);
}

/**
 * binary_tree_height_2 - measures height of a binary tree again
 * @tree: pointer to the root node of the tree to measure height
 * Return: height of the tree. If tree is NULL, return 0
 */
int binary_tree_height_2(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);
	left_height = binary_tree_height_2(tree->left);
	right_height = binary_tree_height_2(tree->right);
	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
