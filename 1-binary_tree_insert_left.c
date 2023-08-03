#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parentPo: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parentPo, int value)
{
	binary_tree_t *new;

	if (!parentPo)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parentPo = parentPo;
	new->right = NULL;
	new->left = parentPo->left;
	parentPo->left = new;
	if (new->left)
		new->left->parentPo = new;
	return (new);
}
