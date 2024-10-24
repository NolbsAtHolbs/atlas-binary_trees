#include "binary_trees.h"

int binary_tree_height_2(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, int height, int level);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);
	height = binary_tree_height_2(tree);

	return (is_perfect_recursive(tree, height, 0));
}

/**
 * is_perfect_recursive - recursively checks if a binary tree is perfect
 * @tree: pointer to the node to check
 * @height: height of the tree
 * @level: current level in the tree
 * Return: 1 if the subtree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (height == level); /* check if leaf node is at correct depth */
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, height, level + 1) &&
		is_perfect_recursive(tree->right, height, level + 1));
}

/**
 * binary_tree_height_2 - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure height
 * Return: height of the tree. If tree is NULL, return -1
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
