#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, return 0
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/*
 * The above implementation is a bit problematic. a classic implementation:
 * size_t binary_tree_height(const binary_tree_t *tree)
 * {
 *	 if (tree == NULL)
 *		 return -1;
 *
 *	 size_t left_height = binary_tree_height(tree->left);
 *	 size_t right_height = binary_tree_height(tree->right);
 *
 *	 return 1 + (left_height > right_height ? left_height : right_height);
}
*/
