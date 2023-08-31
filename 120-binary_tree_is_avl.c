#include "binary_trees.h"

int tree_is_bst_helper(const binary_tree_t *tree, int min, int max);
size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * If tree is NULL, return 0
 *
 * Properties of an AVL Tree:
 *   An AVL Tree is a BST
 *   The difference between heights
 *     of left and right subtrees cannot be more than one
 *   The left and right subtrees must also be AVL trees
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bst = binary_tree_is_bst(tree);
	int balance = binary_tree_balance(tree);

	printf("balance = %d\n", balance);
	if (tree == NULL)
		return (0);

	if (!is_bst || balance < -1 || balance > 1)
		return (0);

	return (1);
}


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


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
*/
int binary_tree_balance(const binary_tree_t *tree)
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
