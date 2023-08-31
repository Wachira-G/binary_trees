#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	binary_tree_t *temp1 = (binary_tree_t *)first;
	binary_tree_t *temp2 = (binary_tree_t *)second;
	binary_tree_t *ancestors1[1000] = {0};
	binary_tree_t *ancestors2[1000] = {0};
	binary_tree_t *lca = NULL;
	size_t i, j, count1 = 0, count2 = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return (temp1);
	while (temp1)
	{
		ancestors1[count1++] = temp1;
		temp1 = temp1->parent;
	}

	while (temp2)
	{
		ancestors2[count2++] = temp2;
		temp2 = temp2->parent;
	}

	for (i = 0; i < count1; i++)
	{
		for (j = 0; j < count2; j++)
		{
			if (ancestors1[i] == ancestors2[j])
			{
				lca = ancestors1[i];
				break;
			}
		}
		if (lca)
			break;
	}
	return (lca);
}
