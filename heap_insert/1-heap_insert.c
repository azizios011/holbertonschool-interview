#include "binary_trees.h"

/**
 * swap_values - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_values(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify - Orders a binary tree node to respect max heap ordering
 * @node: Node to order
 */
void heapify(heap_t *node)
{
    heap_t *largest;

    while (node->parent && node->n > node->parent->n)
    {
        largest = node;
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;

        if (largest != node)
        {
            swap_values(&(node->n), &(largest->n));
            node = largest;
        }
        else
        {
            break;
        }
    }
}

#include "binary_trees.h"

/**
 * find_insert_position - Finds the position to insert a new value in the heap
 * @root: Double pointer to the root node of the Heap
 * Return: Pointer to the parent node where the new node should be inserted
 */
heap_t *find_insert_position(heap_t *root)
{
    heap_t *node;
    int path;
    int leftmost = 0, rightmost = 0;
    int mask = 1;

    if (!root)
        return (NULL);

    for (node = root; node; node = node->left)
        leftmost |= mask, mask <<= 1;

    mask = 1;
    for (node = root; node; node = node->right)
        rightmost |= mask, mask <<= 1;

    for (path = (leftmost + 1) >> 1; path > 1; path >>= 1)
        root = (path & 1) ? root->right : root->left;

    return (root);
}

/**
 * insert_value - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *insert_value(heap_t **root, int value)
{
    heap_t *parent, *node;

    if (!root)
        return (NULL);

    parent = find_insert_position(*root);
    node = binary_tree_node(parent, value);
    if (!node)
        return (NULL);

    if (!parent)
        *root = node;
    else
    {
        if (!parent->left)
            parent->left = node;
        else
            parent->right = node;
    }

    return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node = insert_value(root, value);
    if (!node)
        return (NULL);

    heapify(node);
    return (node);
}
