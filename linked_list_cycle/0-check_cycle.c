#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: pointer to the head of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *slow_ptr = list;
    listint_t *fast_ptr = list;

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;          // Move slow pointer by one step
        fast_ptr = fast_ptr->next->next;    // Move fast pointer by two steps

        // If the pointers meet, there is a cycle
        if (slow_ptr == fast_ptr)
            return 1;
    }

    // If we reach here, there is no cycle
    return 0;
}