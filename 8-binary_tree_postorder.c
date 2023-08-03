#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @funPo: pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*funPo)(int))
{
	if (!tree || !funPo)
		return;

	binary_tree_postorder(tree->left, funPo);
	binary_tree_postorder(tree->right, funPo);
	funPo(tree->n);
}
