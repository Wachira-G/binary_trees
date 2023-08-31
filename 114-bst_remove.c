#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: is the value to remove in the tree
 *
 * Once located, the node containing a value equals to value
 *   must be removed and freed
 * If the node to be deleted has two children,
 * it must be replaced with its first in-order successor (not predecessor)
 *
 * Return: a pointer to the new root node of the tree
 *   after removing the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = root;

	if (root == NULL)
		return (NULL);

	while (temp != NULL)
	{
		if (temp->n == value)
			removal_sequence(temp);
		else if (value < temp->n)
			temp = temp->left;
		else
			temp = temp->right;
	}

	return (root);
}

/**
 * removal_sequence - processes the removal of a node from bst
 * @node: the node to remove
 */
void removal_sequence(bst_t *node)
{
	int is_left = isLeftChild(*node);
	int is_right = isLeftChild(*node);

	if (node == NULL)
		return;
	if (is_leaf(node))
	{
		if (is_left)
		{
			node->parent->left = NULL;
			free(node);
			return;
		}
		else if (is_right)
		{
			node->parent->right = NULL;
			free(node);
			return;
		}
		free(node);
		node = NULL;
		return;
	}
	/* has a child */
	if (node->left && node->right == NULL)
	{
	}
	if (node->left == NULL && node->right)
	{
	}
	/* has two children */

}

/**
 * isLeftChild - check if a node is a left child
 * @parent: the node's parent
 * @current_node: the node
 * Return: 1 if its a left child or 0 otherwise
*/
int isLeftChild(binary_tree_t *parent, binary_tree_t *current_node)
{
	return (parent && parent->left == current_node);
}

/**
 * isRightChild - check if a node is a right child
 * @parent: the node's parent
 * @current_node: the node
 * Return: 1 if its a right child or 0 otherwise
*/
int isRightChild(binary_tree_t *parent, binary_tree_t *current_node)
{
	return (parent && parent->right == current_node);
}

/**
 * inorderSuccessor - finds an inorder successor to a node
 * @node: pointer to node we want to find successor to
 * Return: pointer to successor node
 */
bst_t *inorderSuccessor(bst_t *node)
{
	return (NULL); /* placeholder */

}
