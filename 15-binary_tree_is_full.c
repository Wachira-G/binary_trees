#include "binary_trees.h"

/**
 *  tree_is_leaf - checks if a node is a leaf
 * @node: is a pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
*/
int tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	else if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_full(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right &&
	 !tree_is_leaf(tree->left) && !tree_is_leaf(tree->right))
	{
		return (
			binary_tree_is_full(tree->left) != binary_tree_is_full(tree->right)
			 ? 0 : binary_tree_is_full(tree->left));
	}

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);
	return (1);
}
