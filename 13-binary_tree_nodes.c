#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the node of the tree to count
 *
 * Return: 0 if the tree is null otherwise returns num of nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t c = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		c += 1;

	c += binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

	return (c);
}
