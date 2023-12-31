#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 *  The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 * preorder is (root, left ,right)
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* visit current node*/
	func(tree->n);

	/* traverse left subtree */
	binary_tree_preorder(tree->left, func);

	/* traverse right subtree */
	binary_tree_preorder(tree->right, func);
}
