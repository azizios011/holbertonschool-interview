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
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *root = malloc(sizeof(avl_t));
    if (!root)
        return NULL;

    root->n = array[mid];
    root->left = sorted_array_to_avl_helper(array, start, mid - 1);
    root->right = sorted_array_to_avl_helper(array, mid + 1, end);
    root->parent = NULL;

    if (root->left)
        root->left->parent = root;
    if (root->right)
        root->right->parent = root;

    return root;
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
        return NULL;
    return sorted_array_to_avl_helper(array, 0, size - 1);
}
