#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints the array being searched
 * @array: Pointer to the first element of the array
 * @left: Left boundary of the array
 * @right: Right boundary of the array
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++) {
        printf("%d", array[i]);
        if (i < right) {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive binary search for the first occurrence
 * @array: Pointer to the first element of the array to search in
 * @left: Left boundary of the array
 * @right: Right boundary of the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value) {
    if (right >= left) {
        size_t mid = left + (right - left) / 2;
        print_array(array, left, right);
        
        if (array[mid] == value) {
            if (mid == left || array[mid - 1] != value) {
                return mid;
            } else {
                return advanced_binary_recursive(array, left, mid - 1, value);
            }
        } else if (array[mid] > value) {
            return advanced_binary_recursive(array, left, mid - 1, value);
        } else {
            return advanced_binary_recursive(array, mid + 1, right, value);
        }
    }
    return -1;
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the value in the array or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1;
    }
    return advanced_binary_recursive(array, 0, size - 1, value);
}
