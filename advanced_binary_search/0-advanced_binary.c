#include "search_algos.h"

/**
 * advanced binary - a function that searches
 * for a value in a sorted array of integers.
 * @array: is a pointer to the first element of the array to search in.
 * @size: is the number of elements in array.
 * @value: is the value to search for.
 * Returns: the index where value is located,
 * or -1 if value is not present in array or if array is NULL.
*/
int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1;
    }
    return binary_search_recursive(array, 0, size - 1, value);
}

/**
 * advanced_binary_recursive - Recursively performs the binary search
 * @array: The array to search in
 * @left: The starting index of the subarray
 * @right: The ending index of the subarray
 * @value: The value to search for
 *
 * Return: The index of the first occurrence of the value, or -1 if not found
 */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
    if (left > right) {
        return -1;
    }
    
    print_array(array, left, right);
    
    size_t mid = left + (right - left) / 2;

    if (array[mid] == value) {
        if (mid == left || array[mid - 1] != value) {
            return mid;
        }
        return binary_search_recursive(array, left, mid, value);
    } else if (array[mid] < value) {
        return binary_search_recursive(array, mid + 1, right, value);
    } else {
        if (mid == right || array[mid + 1] != value) {
            return mid;
        }
        return binary_search_recursive(array, mid + 1, right, value);
    }
}

/**
 * print_array - Prints the array being searched
 * @array: The array to be printed
 * @left: The starting index
 * @right: The ending index
 * Returns: true if the array was printed.
 */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++) {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}
