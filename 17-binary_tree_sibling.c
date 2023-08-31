#include "binary_trees.h"

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
 * binary_tree_sibling - finds the sibling of a node
 * @node: is a pointer to the node to find the sibling
 * Return: a pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (isLeftChild(node->parent, node))
		return (node->parent->right);

	if (isRightChild(node->parent, node))
		return (node->parent->left);

	return (NULL);
}
