## Sorted Array to AVL Tree Converter

This C program is designed to convert a sorted array into an AVL tree, a self-balancing binary search tree. An AVL tree ensures that the heights of two child subtrees of any node differ by no more than one, which keeps the tree balanced and provides efficient search, insert, and delete operations. 

### Code Explanation:

#### Function `sorted_array_to_avl`

This is the main function that converts the given sorted array into an AVL tree. It calls the helper function `build_avl_tree` to recursively create nodes and build the tree.

- **Parameters:**
  - `array`: A pointer to the sorted array of integers.
  - `size`: The number of elements in the array.

- **Returns:**
  - A pointer to the root of the constructed AVL tree.

```c
avl_t *sorted_array_to_avl(int *array, size_t size) {
    if (!array || size == 0)
        return NULL;
    return build_avl_tree(array, 0, size - 1, NULL);
}
```

#### Function `build_avl_tree`

This is a recursive function that constructs the AVL tree by splitting the array and creating nodes for each subarray.

- **Parameters:**
  - `array`: The sorted array.
  - `start`: The starting index of the current subarray.
  - `end`: The ending index of the current subarray.
  - `parent`: A pointer to the parent node.

- **Returns:**
  - A pointer to the root of the constructed subtree.

The function selects the middle element of the current subarray as the root of the subtree. It then recursively constructs the left and right subtrees from the left and right halves of the array, respectively.

```c
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *node = create_avl_node(parent, array[mid]);

    if (!node)
        return NULL;

    node->left = build_avl_tree(array, start, mid - 1, node);
    node->right = build_avl_tree(array, mid + 1, end, node);

    return node;
}
```

#### Function `create_avl_node`

This helper function creates a new AVL tree node with the given value and parent.

- **Parameters:**
  - `parent`: A pointer to the parent node.
  - `value`: The value to be stored in the new node.

- **Returns:**
  - A pointer to the newly created node.

```c
avl_t *create_avl_node(avl_t *parent, int value) {
    avl_t *new_node = malloc(sizeof(avl_t));

    if (!new_node)
        return NULL;

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
```

### Key Concepts:

- **Balanced Binary Search Tree:** The AVL tree balances itself by ensuring that the heights of left and right subtrees differ by no more than one.
- **Recursion:** The `build_avl_tree` function uses recursion to divide the array and construct the tree in a balanced manner.
- **Tree Node:** Each node in the AVL tree is created with a value from the array, pointers to its parent, left, and right child nodes.

### Usage:

To compile and run the program, include the appropriate source files along with the function to print the binary tree:

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-sorted_array_to_avl.c -o sorted_array_to_avl
./sorted_array_to_avl
```

This program takes a sorted array and builds a balanced AVL tree. The `binary_tree_print` function is provided to visually print the tree structure in the terminal.
