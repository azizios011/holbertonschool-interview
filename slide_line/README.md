```markdown
# Slide Line Implementation

This C program provides a function for sliding and merging mechanics for the 2048 game on a single horizontal line.

## slide_line Function

The `slide_line` function slides and merges an array of integers to the left or right direction.

Function Signature:
```c
int slide_line(int *line, size_t size, int direction);
```

### Parameters:
- `line`: Pointer to the array of integers.
- `size`: Number of elements in the array.
- `direction`: SLIDE_LEFT or SLIDE_RIGHT.

### Return Value:
- `1` if successful, `0` otherwise.

## Explanation of Code:

1. **Input Validation**:
   - Verify that the `direction` parameter is either `SLIDE_LEFT` or `SLIDE_RIGHT`.

2. **Slide Left Operation**:
   - Iterate through the array to move non-zero elements to the left.
   - Merge adjacent identical elements if they exist.
   - Slide the elements again to fill in the gaps created by merging.

3. **Slide Right Operation**:
   - Iterate through the array to move non-zero elements to the right.
   - Merge adjacent identical elements if they exist.
   - Slide the elements again to fill in the gaps created by merging.

## Example Usage:

```c
#include "slide_line.h"

int main() {
    int line[] = {2, 2, 0, 0};
    size_t size = sizeof(line) / sizeof(line[0]);
    int direction = SLIDE_LEFT;

    if (!slide_line(line, size, direction)) {
        printf("Failed to slide and merge line\n");
        return 1;
    }

    // Print the array
    for (size_t i = 0; i < size; i++) {
        printf("%d ", line[i]);
    }

    return 0;
}
```

This README provides an overview of the slide_line implementation, explaining each line of the code and how to use the `slide_line` function.
```
