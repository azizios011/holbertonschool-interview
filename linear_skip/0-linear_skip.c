#include "search.h"

/**
 * linear search - a function that searches for a value in a sorted skip list of integers.
 * @list: is a pointer to the head of the skip list to search in.
 * @value: is the value to search for
 * Return: a pointer on the first node where value is located.
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node = list;
    if (list == NULL && value == 0)
    {
        return (NULL);
    }

    while (node != NULL)
    {
        if (node->n == value)
        { 
            return (node);
        }
        node = node->express;
    }
    return (node);
}
