# Find the Loop

## Find the Loop Script README

This README explains each line of the code in the `0-find_loop.c` script.

## Code Explanation

```c
#include "lists.h"
This line includes the header file `lists.h` which contains the necessary definitions and prototypes for working with the linked list.

listint_t *find_listint_loop(listint_t *head)
This is the prototype of the function that finds the loop in a linked list. It takes a pointer to the head of the list as an argument and returns the address of the node where the loop starts, or `NULL` if there is no loop.

{
    listint_t *slow = head;
    listint_t *fast = head;
These lines declare two pointers, `slow` and `fast`, both initially pointing to the head of the list. These pointers will be used to traverse the list at different speeds to detect a loop.

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
This block is a loop that continues as long as `slow`, `fast`, and `fast->next` are not `NULL`. Inside the loop, `slow` moves one step forward, while `fast` moves two steps forward.

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow);
        }
    }
If `slow` and `fast` meet, it indicates a loop in the list. At this point, `slow` is reset to the head of the list, and both `slow` and `fast` move one step at a time until they meet again. The meeting point is the start of the loop, which is returned.

    return (NULL);
}
If no loop is detected, the function returns `NULL`.
```

### lists.h
Ensure your `lists.h` header file is include guarded and contains the necessary definitions and prototypes:

```c
#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif /* _LISTS_H_ */
```
