#include "binary_trees.h"

/**
 * node_height - measures the height of a binary tree
 * @tree: a pointer to the node of the tree to measure
 *
 * Return: 0 if the tree is null otherwise returns the height of the tree
 */
size_t node_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = node_height(tree->left);
	right = node_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a node
 * @tree: a pointer to the node of the tree to measure
 *
 * Return: 0 if the tree is null otherwise returns the bf of the node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (node_height(tree->left) - node_height(tree->right));
}
