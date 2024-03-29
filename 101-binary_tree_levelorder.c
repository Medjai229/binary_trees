#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: a pointer to the node of the tree to measure
 *
 * Return: 0 if the tree is null otherwise returns the height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * print_level - function that prints the level
 * @tree: a pointer to the root node of the tree to traverse
 * @level: the level of the nodes
 * @func: a pointer to a function to call for each node
 */
void print_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		print_level(tree->left, --level, func);
		print_level(tree->right, level, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, level;

	if (tree == NULL || func == NULL)
		return;

	level = tree_height(tree);
	for (i = 0; i <= level; i++)
		print_level(tree, i, func);
}
