# Skip List Linear Search

This C program provides functions for creating a skip list, printing it, freeing it, and searching for a value using a linear search optimized with an express lane.

## 1. `create_skiplist` Function

The `create_skiplist` function creates a skip list from an array of integers.

### Function Signature

```c
skiplist_t *create_skiplist(int *array, size_t size);
```

### Memory Allocation

```c
skiplist_t *new_node = malloc(sizeof(skiplist_t));
```

Memory is allocated for each new node using `malloc`. If allocation fails, the function returns `NULL`.

### Data Assignment

```c
new_node->n = array[i];
new_node->index = i;
new_node->next = NULL;
new_node->express = NULL;
```

The data fields of each new node are assigned: value (`n`), index, next pointer, and express pointer.

### Express Lane Assignment

Nodes are linked using both the `next` pointer and the `express` pointer. The `express` lane is set for nodes at indices that are multiples of the square root of the list size.

### Return Value

```c
return (head);
```

The function returns a pointer to the head of the skip list.

## 2. `print_skiplist` Function

The `print_skiplist` function prints the skip list and its express lane.

### Function Signature

```c
void print_skiplist(const skiplist_t *list);
```

### Printing Nodes

```c
printf("Index[%lu] = [%d]\n", list->index, list->n);
```

The function prints the value and index of each node in the skip list and the express lane.

## 3. `free_skiplist` Function

The `free_skiplist` function frees the memory allocated for the skip list.

### Function Signature

```c
void free_skiplist(skiplist_t *list);
```

### Memory Deallocation

```c
skiplist_t *temp;
while (list)
{
    temp = list->next;
    free(list);
    list = temp;
}
```

The function iterates through the list and frees each node.

## 4. `linear_skip` Function

The `linear_skip` function searches for a value in a sorted skip list of integers.

### Function Signature

```c
skiplist_t *linear_skip(skiplist_t *list, int value);
```

### Initial Checks

```c
if (!list)
    return (NULL);
```

If the list is `NULL`, the function returns `NULL`.

### Traversing the Express Lane

```c
while (express)
{
    printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
    if (express->n >= value)
        break;
    prev = express;
    express = express->express;
}
```

The function traverses the list using the express lane pointers, printing the value at each express lane node.

### Linear Search between Previous and Express Nodes

```c
while (prev && prev->index <= express->index)
{
    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    if (prev->n == value)
        return (prev);
    prev = prev->next;
}
```

The function performs a linear search between the `prev` node and the `express` node, printing each value checked.

### Return Value

```c
return (NULL);
```

If the value is not found, the function returns `NULL`.

## Usage

You can use these functions to create a skip list, print it, free it, and search for values within it:

```c
// Example usage
int array[] = {0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
size_t size = sizeof(array) / sizeof(array[0]);

skiplist_t *list = create_skiplist(array, size);
print_skiplist(list);

skiplist_t *res = linear_skip(list, 53);
printf("Found %d at index: %lu\n\n", 53, res->index);

res = linear_skip(list, 2);
printf("Found %d at index: %lu\n\n", 2, res->index);

res = linear_skip(list, 999);
printf("Found %d at index: %p\n", 999, (void *) res);

free_skiplist(list);
```

This example demonstrates how to use the `create_skiplist`, `print_skiplist`, `linear_skip`, and `free_skiplist` functions.
