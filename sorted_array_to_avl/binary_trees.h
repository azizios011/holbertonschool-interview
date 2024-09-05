#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Function Prototypes */
avl_t *sorted_array_to_avl(int *array, size_t size);

/* Utility functions */
avl_t *create_avl_node(avl_t *parent, int value);
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent);

/* Function to print the binary tree */
void binary_tree_print(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
