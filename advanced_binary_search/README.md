# Advanced Binary Search

This C program provides a method for performing an advanced binary search, which returns the index of the first occurrence of a value in a sorted array.

## Function: `advanced_binary`

The `advanced_binary` function searches for a value in a sorted array of integers.

### Method Signature
```c
int advanced_binary(int *array, size_t size, int value);
```

### Internal Helper Function: `print_array`
This function prints the current subarray being searched.

#### Parameters
- `int *array`: The array to be printed.
- `size_t left`: The leftmost index of the subarray to print.
- `size_t right`: The rightmost index of the subarray to print.

#### Code Explanation
```c
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}
```
1. `size_t i;`: Declare a variable `i` for iteration.
2. `printf("Searching in array: ");`: Print the initial message for the subarray.
3. `for (i = left; i <= right; i++)`: Loop through the subarray.
4. `if (i > left) printf(", ");`: Print a comma for elements after the first one.
5. `printf("%d", array[i]);`: Print the current element of the subarray.
6. `printf("\n");`: Print a newline at the end.

### Internal Helper Function: `advanced_binary_recursive`
This function recursively performs an advanced binary search.

#### Parameters
- `int *array`: The array to search.
- `size_t left`: The leftmost index of the subarray to search.
- `size_t right`: The rightmost index of the subarray to search.
- `int value`: The value to search for.

#### Code Explanation
```c
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;

    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);
    else if (array[mid] >= value)
        return (advanced_binary_recursive(array, left, mid, value));
    else
        return (advanced_binary_recursive(array, mid + 1, right, value));
}
```
1. `size_t mid;`: Declare a variable `mid` for the middle index.
2. `if (left > right) return (-1);`: Base case: return -1 if the subarray is invalid.
3. `print_array(array, left, right);`: Print the current subarray.
4. `mid = left + (right - left) / 2;`: Calculate the middle index.
5. `if (array[mid] == value && (mid == left || array[mid - 1] != value)) return (mid);`: Return the index if the middle element is the target and it's the first occurrence.
6. `else if (array[mid] >= value) return (advanced_binary_recursive(array, left, mid, value));`: Recur to the left subarray if the middle element is greater than or equal to the target.
7. `else return (advanced_binary_recursive(array, mid + 1, right, value));`: Recur to the right subarray if the middle element is less than the target.

### Function: `advanced_binary`
This function initiates the recursive search.

#### Parameters
- `int *array`: The array to search.
- `size_t size`: The number of elements in the array.
- `int value`: The value to search for.

#### Code Explanation
```c
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
```
1. `if (array == NULL) return (-1);`: Return -1 if the array is NULL.
2. `return (advanced_binary_recursive(array, 0, size - 1, value));`: Start the recursive search with the full array.

## Usage
You can use this function to search for a value in a sorted array and find the first occurrence of that value:

### Example Usage
```c
#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

int main(void)
{
    int array[] = {
        0, 1, 2, 5, 5, 6, 6, 7, 8, 9
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Found %d at index: %d\n\n", 8, advanced_binary(array, size, 8));
    printf("Found %d at index: %d\n\n", 5, advanced_binary(array, size, 5));
    printf("Found %d at index: %d\n", 999, advanced_binary(array, size, 999));
    return (EXIT_SUCCESS);
}
```
This example demonstrates how to use the `advanced_binary` function to search for specific values in a sorted array and print the results.
