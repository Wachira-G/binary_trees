#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, your function must return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp = (bst_t *) tree;

	if (tree == NULL)
		return (NULL);

	while (temp != NULL)
	{
		if (temp->n == value)
			break;
		else if (value < temp->n)
			temp = bst_search(tree->left, value);
		else
			temp = bst_search(tree->right, value);
	}
	return (temp);
}
