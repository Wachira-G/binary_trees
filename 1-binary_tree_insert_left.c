#include "binary_trees.h"


/**
 * binary_tree_insert_left - a function that inserts a node
 *  as the left-child of another node
 *
 * If parent already has a left-child,
 *  the new node must take its place,
 *  and the old left-child must be set as the left-child of the new node.
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL || new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		binary_tree_t *old_left_node = parent->left;

		old_left_node->parent = new_node;
		new_node->left = old_left_node;
		parent->left = new_node;
	}
	else
	{
		parent->left = new_node;
	}

	return (new_node);
}
