#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: a pointer to the node of the tree to measure
 *
 * Return: 0 if the tree is null otherwise returns the size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		size += 1;
		size += tree_size(tree->left);
		size += tree_size(tree->right);
	}
	return (size);
}

/**
 * is_complete_recursive - function that checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to measure the size.
 * @number: number of current node
 * @size: size of the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete_recursive(const binary_tree_t *tree,
		size_t number, size_t size)
{
	if (tree == NULL)
		return (1);
	if (number >= size)
		return (0);
	return (is_complete_recursive(tree->left, (number * 2) + 1, size) &&
		is_complete_recursive(tree->right, (number * 2) + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);
	return (is_complete_recursive(tree, 0, size));
}
