
---

## Cycle Detection Algorithm for Linked Lists

### Overview

The Cycle Detection Algorithm is a method used to detect cycles in a linked list. It works by traversing the list with two pointers, one moving at a slower pace than the other. If there's a cycle in the list, eventually the faster pointer will catch up with the slower one.

### Algorithm Steps

1. **Initialization**:
   - Start with two pointers, usually named slow_ptr and fast_ptr, both initially pointing to the head of the linked list.

2. **Traversal**:
   - Move the slow_ptr one step at a time and the fast_ptr two steps at a time through the linked list.
   - If the fast_ptr reaches the end of the list (becomes NULL), there's no cycle, return 0.
   - If slow_ptr == fast_ptr during traversal, a cycle is detected.

3. **Detecting Cycle**:
   - The fast_ptr moves twice as fast as the slow_ptr.
   - If there's a cycle, the fast_ptr will eventually catch up with the slow_ptr.

4. **Termination**:
   - If the traversal reaches the end of the list without encountering a cycle, return 0.
   - If a cycle is detected during traversal, return 1.

### Pseudocode

```plaintext
slow_ptr = head
fast_ptr = head

while (slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL):
    move slow_ptr by one step
    move fast_ptr by two steps

    if fast_ptr reaches end (NULL):
        return 0 (no cycle)

    if slow_ptr == fast_ptr:
        return 1 (cycle detected)
```

### Benefits

- Efficient: O(n) time complexity where n is the number of nodes in the list.
- Space-efficient: Uses only two pointers without any additional data structures.

---
