#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: Left index of the subarray to print
 * @right: Right index of the subarray to print
 */
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

/**
 * advanced_binary_recursive - Recursively performs an advanced binary search
 * @array: The array to search
 * @left: The leftmost index of the subarray to search
 * @right: The rightmost index of the subarray to search
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
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

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: The array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
