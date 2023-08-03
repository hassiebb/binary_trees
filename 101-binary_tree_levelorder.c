#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @funPo: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*funPo)(int))
{
	size_t level, maxlevel;

	if (!tree || !funPo)
		return;

	maxlevel = binary_tree_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tree, funPo, level);
}

/**
 * btlo_helper - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @funPo: pointer to a function to call for each node
 * @level: the level of the tree to call funPo upon
 */
void btlo_helper(const binary_tree_t *tree, void (*funPo)(int), size_t level)
{
	if (level == 1)
		funPo(tree->n);
	else
	{
		btlo_helper(tree->left, funPo, level - 1);
		btlo_helper(tree->right, funPo, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
