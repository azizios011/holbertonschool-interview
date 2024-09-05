#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_avl_node - Creates a new AVL node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
    avl_t *new_node = malloc(sizeof(avl_t));

    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}

/**
 * build_avl_tree - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @start: Start index of the array
 * @end: End index of the array
 * @parent: Pointer to the parent node of the current subtree
 * Return: Pointer to the root of the created subtree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *root = create_avl_node(parent, array[mid]);

    if (!root)
        return (NULL);

    root->left = build_avl_tree(array, start, mid - 1, root);
    root->right = build_avl_tree(array, mid + 1, end, root);

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Size of the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_avl_tree(array, 0, size - 1, NULL));
}
