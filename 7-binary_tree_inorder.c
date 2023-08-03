#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @funcPo: pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*funPo)(int))
{
	if (!tree || !funPo)
		return;

	binary_tree_inorder(tree->left, funPo);
	funPo(tree->n);
	binary_tree_inorder(tree->right, funPo);
}
