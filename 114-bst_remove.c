#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removing the value,
 * or NULL if the value is not found or if the tree is empty
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			tmp = root->left ? root->left : root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		tmp = root->right;

		while (tmp->left)
			tmp = tmp->left;

		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}

	return (root);
}
