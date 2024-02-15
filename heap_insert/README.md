# Binary Tree Node Creation and Max Heap Insertion

This C program provides functions for creating a binary tree node and inserting a value into a Max Binary Heap.

## 1. `binary_tree_node` Function

The `binary_tree_node` function creates a binary tree node.

### Function Signature

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

### Memory Allocation

```c
binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

if (new_node == NULL)
{
    return (NULL);
}
```

Memory is allocated for the new node using `malloc`. If allocation fails, the function returns `NULL`.

### Data Assignment

```c
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;
```

The data fields of the new node are assigned: value (`n`), parent, left child, and right child.

### Return Value

```c
return (new_node);
```

The function returns a pointer to the new node.

## 2. `heap_insert` Function

The `heap_insert` function inserts a value into a Max Binary Heap.

### Function Signature

```c
heap_t *heap_insert(heap_t **root, int value);
```

### Node Creation

```c
heap_t *new_node = binary_tree_node(NULL, value);
```

A new node is created using the `binary_tree_node` function.

### Initial Checks

```c
if (!new_node)
{
    return (NULL);
}

if (!*root)
{
    return (*root = new_node);
}
```

If memory allocation fails or the root is NULL, the function returns `NULL` or sets the root to the new node, respectively.

### Traversal and Insertion

```c
while (current)
{
    parent = current;

    if (value > current->n)
        current = current->right;
    else
        current = current->left;
}
```

The function traverses the tree to find the appropriate position for the new node.

### Node Linking

```c
new_node->parent = parent;
if (value > parent->n)
    parent->right = new_node;
else
    parent->left = new_node;
```

The new node is linked to its parent based on the Max Heap property.

### Heapify and Return

```c
heapify(new_node);

return (new_node);
```

The `heapify` function is called to fix the Max Heap property, and the new node is returned.

## 3. `heapify` Function

The `heapify` function fixes the Max Heap property after insertion.

### Function Signature

```c
void heapify(heap_t *node);
```

### Heapifying Process

```c
while (node->parent && node->n > node->parent->n)
{
    swap_values(&node->n, &node->parent->n);
    node = node->parent;
}
```

The function compares the values with the parent and swaps them if needed until the Max Heap property is restored.

## 4. `swap_values` Function

The `swap_values` function swaps two integer values.

### Function Signature

```c
void swap_values(int *a, int *b);
```

### Swap Process

```c
int temp = *a;
*a = *b;
*b = temp;
```

The values at the provided memory locations are swapped.

This program allows for the creation of binary tree nodes and insertion of values into a Max Binary Heap while maintaining the Max Heap property.

## Usage

You can use these functions to create binary tree nodes and insert values into a Max Binary Heap:

```c
// Example usage
binary_tree_t *root = NULL;
heap_t *inserted_node = heap_insert(&root, 10);
```

This example demonstrates how to use the `binary_tree_node` and `heap_insert` functions.
