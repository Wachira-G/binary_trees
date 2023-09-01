#include "binary_trees.h"

void enque(struct queNode **front, struct queNode **rear,
		const binary_tree_t *new_node);
void deque(struct queNode **front);


/**
 *  binary_tree_levelorder - goes through a binary
 *     tree using level-order traversal
 *  @tree: is a pointer to the root node of the tree to traverse
 *  @func: is a pointer to a function to call for each node.
 *    The value in the node must be passed as a parameter to this function.
 *  If tree or func is NULL, do nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	struct queNode *front = NULL;
	struct queNode *rear = NULL;

	if (tree == NULL || func == NULL)
		return;

	enque(&front, &rear, tree);

	while (front != NULL)
	{
		const binary_tree_t *current_node = front->node;

		func(current_node->n);

		if (current_node->left)
			enque(&front, &rear, current_node->left);
		if (current_node->right)
			enque(&front, &rear, current_node->right);

		deque(&front);
	}
}

/**
 * enque - inserts a node onto a queue for later processsing
 * @front: front of the queue
 * @rear: rear of the queue
 * @new_node: pointer to node that we are queing.
 */
void enque(struct queNode **front, struct queNode **rear,
		const binary_tree_t *new_node)
{
	struct queNode *newQueNode = malloc(sizeof(struct queNode));

	if (newQueNode == NULL)
		return;
	newQueNode->node = new_node;
	newQueNode->next = NULL;

	if (*rear == NULL)
	{
		*front = *rear = newQueNode;
	}
	else
	{
		(*rear)->next = newQueNode;
		*rear = newQueNode;
	}
}

/**
 * deque - remove a node from a que
 * @front: - front of the que
 */
void deque(struct queNode **front)
{
	struct queNode *temp = *front;

	if (*front == NULL)
		return;

	*front = (*front)->next;
	free(temp);
}

