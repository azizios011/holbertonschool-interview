#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @start: Starting index of the array
 * @end: Ending index of the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end)
{
	avl_t *root = malloc(sizeof(avl_t));
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	if (!root)
		return (NULL);

	root->n = array[mid];
	root->left = sorted_array_to_avl_helper(array, start, mid - 1);
	root->right = sorted_array_to_avl_helper(array, mid + 1, end);
	root->parent = NULL;

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
	free_tree(root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (sorted_array_to_avl_helper(array, 0, size - 1));
}

/**
 * free_tree - Frees the memory allocated for an AVL tree
 * @root: Pointer to the root node of the AVL tree
 *
 * This function recursively traverses the AVL tree rooted at 'root' and
 * frees the memory allocated for each node. It uses a post-order traversal
 * to ensure that child nodes are freed before their parent node.
 */
void free_tree(avl_t *root)
{
	if (root == NULL)
	{
		return;
	}
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}
