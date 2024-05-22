#include "search.h"
/**
 * linear search - a function that searches for a value
 * in a sorted skip list of integers.
 *
 * @list: is a pointer to the head of the skip list to search in.
 * @value: is the value to search for
 * Return: a pointer on the first node where value is located.
 *
 *  Description: Search for a value in the skip list
 * and return its value if found.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list;
	skiplist_t *prev = NULL;

	if (list == NULL && value == 0)
	{
		return (NULL);
	}
	while (node->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		node->express->index, node->express->n);
		if (node->n == value)
		{
			return (node);
		}
		prev = node;
		node = node->express;
	}
	if (node->express == NULL)
	{
		prev = node;
		while (node->next != NULL)
		{
			node = node->next;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	prev->index, node->index);
	node = prev;
	while (node != NULL && node->index <= node->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (node->n == value)
		{
			printf("Found at index: %lu\n", node->index);
			return (node);
		}
		node = node->next;
	}
	printf("Found at index: (nil)\n");
	return (NULL);
}
