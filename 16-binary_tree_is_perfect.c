#include "binary_trees.h"

/**
 * depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node of the tree to measure
 *
 * Return: 0 if the tree is null otherwise returns the depth of the tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - checks if a binary tree is perfect recursively
 * @tree: A pointer to the node of the tree to check
 * @depth: The depth of the tree
 * @level: The level of the current node
 *
 * Return: 1 if it is perfect, othrwise 0
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 0 if the tree is NULL or if it is not perfect,otherwise it returns 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(tree), 0));
}
