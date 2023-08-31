#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 * If tree is NULL, do nothing
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}


/*
 * delete_node - deletes a node
 * @node: pointer to node to delete
 *
*
*void delete_node(binary_tree_t *node)
*{
*	binary_tree_t *temp = node;
*
*	if (node == NULL)
*		return;
*	if (node->left == NULL && node->right == NULL) / no child /
*	{
*		free(temp);
*		node = NULL;
*		return;
*	}
*	else if (node->left && node->right == NULL) / left child /
*	{
*		int is_left_child = isLeftChild(node->parent, node);
*		int is_right_child = isRightChild(node->parent, node);
*
*		node->left->parent = node->parent;
*		if (is_left_child)
*			node->parent->left = node->left;
*		else if (is_right_child)
*			node->parent->right = node->left;
*		free(node);
*		return;
*	}
*	else if (node->right && node->left == NULL) / right child/
**	{
*		int is_left_child = isLeftChild(node->parent, node);
*		int is_right_child = isRightChild(node->parent, node);
*
*		node->right->parent = node->parent;
*		if (is_left_child)
*			node->parent->left = node->right;
*		else if (is_right_child)
*			node->parent->right = node->right;
*		free(node);
*		return;
*	}
*	else / two children /
*	{ / take a successor, put its data in place of current, free successor /
*		binary_tree_t *successor = findInorderSuccessor(node->right);
*
*		node->n = successor->n;
*		if (successor->parent && successor->right)
*			successor->parent->left = successor->right;
*		else if (successor->parent)
*			successor->parent->left = NULL;
*		free(successor);
*		return;
*	}
*}
*/

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
 * findInorderSuccessor - finds a successor node to the node we want to delete
 * @node_right: pointer to the right subtree's root where to find successor
 * Return: pointer to the successor node or NULL if node is NULL
 */
binary_tree_t *findInorderSuccessor(binary_tree_t *node_right)
{
	binary_tree_t *temp = node_right;

	if (node_right == NULL)
		return (NULL);
	while (temp != NULL && temp->left != NULL)
		temp = temp->left;

	return (temp);
}
