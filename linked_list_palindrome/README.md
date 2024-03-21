
---

## Linked List Palindrome Checker

### Overview
This algorithm checks whether a singly linked list is a palindrome or not.

### Approach
1. Start with two pointers, `slow` and `fast`, initialized to the head of the list.
2. Move `slow` one step forward and `fast` two steps forward at each iteration until `fast` reaches the end of the list or `fast->next` becomes NULL.
3. When `fast` reaches the end of the list, `slow` will be at the middle of the list.
4. Reverse the second half of the list starting from `slow`.
5. Compare the first half and the reversed second half of the list.
6. If they match, the list is a palindrome. Otherwise, it's not.

### Pseudocode
```plaintext
isPalindrome(head):
    slow = head
    fast = head
    
    while fast is not NULL and fast->next is not NULL:
        move slow one step forward
        move fast two steps forward
    
    if fast is not NULL:   // odd number of nodes
        move slow one step forward
    
    // reverse the second half starting from slow
    second_half = reverse(slow)
    
    // compare the first half with the reversed second half
    while second_half is not NULL:
        if head->value is not equal to second_half->value:
            return False
        move head one step forward
        move second_half one step forward
    
    return True
    
reverse(head):
    prev = NULL
    current = head
    
    while current is not NULL:
        next = current->next
        current->next = prev
        prev = current
        current = next
    
    return prev
```

### Complexity Analysis
- Time complexity: O(n), where n is the number of nodes in the linked list. We traverse the list twice.
- Space complexity: O(1), as we are not using any extra space apart from a few pointers.

---
