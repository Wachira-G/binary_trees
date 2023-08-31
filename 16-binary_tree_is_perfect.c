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
 * tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
*/
int tree_is_full(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	if (tree->left && tree->right &&
	 !tree_is_leaf(tree->left) && !tree_is_leaf(tree->right))
	{
		return (
			tree_is_full(tree->left) != tree_is_full(tree->right)
			 ? 0 : tree_is_full(tree->left));
	}

	if ((!tree->left && tree->right) || (tree->left && !tree->right))
		return (0);
	return (1);
}

/* insert is balance */

#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);

/**
 * tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
*/
int tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, return 0
*/
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = tree_height(tree->left);
	if (tree->right)
		right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree_is_full(tree) && tree_balance(tree) == 0)
		return (1);
	return (0);
}
