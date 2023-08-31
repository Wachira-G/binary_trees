#include "binary_trees.h"


/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 *  The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 * inorder is (left, root, right)
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* traverse left subtree */
	binary_tree_inorder(tree->left, func);

	/* visit current node*/
	func(tree->n);

	/* traverse right subtree */
	binary_tree_inorder(tree->right, func);
}
