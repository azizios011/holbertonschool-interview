#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap.
 * @root: is a double pointer to the root node of the Heap.
 * @value: is the value to store in the node to be inserted.
 * Return: a pointer to the inserted node, or 'NULL' on failure.
*/

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = binary_tree_node(NULL, value);
    heap_t *parent = NULL;
    heap_t *current = *root;

    if (!new_node)
        return (NULL);

    if (!*root)
        return (*root = new_node);

    while (current)
    {
        parent = current;

        if (value > current->n)
            current = current->right;
        else
            current = current->left;
    }

    new_node->parent = parent;
    if (value > parent->n)
        parent->right = new_node;
    else
        parent->left = new_node;

    heapify(new_node);

    return (new_node);
}


/**
 * heapify - Fixes the Max Heap property after insertion.
 * @node: Node to start heapifying from.
 * Return: the heapifying node.
*/

void heapify(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(&node->n, &node->parent->n);
		node = node->parent;
	}
}

/**
 * swap_values - Swaps two integer values.
 * @a: Pointer to the first value.
 * @b: Pointer to the second value.
 * Return: Swap intrgers.
*/

void swap_values(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
