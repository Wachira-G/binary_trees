#include "binary_trees.h"

int tree_is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * If tree is NULL, return 0
 *
 * Properties of a Binary Search Tree:
 * The left subtree of a node contains only nodes
 * with values less than the node’s value
 * The right subtree of a node contains only nodes
 * with values greater than the node’s value
 * The left and right subtree each must also be a binary search tree
 * There must be no duplicate values
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * tree_is_bst_helper - checks tree is a valid bst - helps the check function
 * @tree: pointer to root of tree
 * @min: the minimum valid value for nodes in the subtree
 * @max: the maximum valid value for nodes in the subtree
 * Return: 1 if the subtree rooted at 'tree' is a valid BST, and 0 otherwise
*/
int tree_is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (tree_is_bst_helper(tree->left, min, tree->n) &&
		tree_is_bst_helper(tree->right, tree->n, max));
}
