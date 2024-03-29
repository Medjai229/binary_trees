#include "binary_trees.h"

/**
 * is_bst_recursive - checks if a binary tree
 * is a valid Binary Search Tree recursivly
 * @node: Pointer to the root node of the binary tree or subtree
 * @min: The minimum value of nodes in the subtree
 * @max: The maximum value of nodes in the subtree
 *
 * Return: 1 if the tree is a valid BST 0 otherwise
 */
int is_bst_recursive(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (is_bst_recursive(node->left, min, node->n - 1) &&
			is_bst_recursive(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the binary tree or subtree
 *
 * Return: 1 if the tree is a valid BST 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_recursive(tree, INT_MIN, INT_MAX));
}
