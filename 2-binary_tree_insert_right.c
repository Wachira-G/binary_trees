#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node
 *  as the right-child of another node
 * If parent already has a right-child,
 *  the new node must take its place,
 *  and the old right-child must be set as the right-child of the new node.
 *
 * @parent: a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL || new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (parent->right != NULL)
	{
		binary_tree_t *old_right_node = parent->right;

		new_node->right = old_right_node;
		old_right_node->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
