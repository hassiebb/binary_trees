#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the
 *					right-child of another node
 *
 * @parentPo: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 *
 * Description: If parent already has a right-child, the new node
 *				must take its place, and the old right-child must
 *				be set as the right-child of the new node.
 *
 * Return: a pointer to the created node, or
 *			NULL on failure or
 *			if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parentPo, int value)
{
	binary_tree_t *new;

	if (!parentPo)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parentPo = parentPo;
	new->left = NULL;
	new->right = parentPo->right;
	parentPo->right = new;
	if (new->right)
		new->right->parentPo = new;
	return (new);
}
