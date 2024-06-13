# Rotate 2D Matrix
This Python program provides a function to rotate an n x n 2D matrix 90 degrees clockwise in-place.

## Function: rotate_2d_matrix
The `rotate_2d_matrix` function rotates a given n x n 2D matrix 90 degrees clockwise. 

### Function Signature
```python
def rotate_2d_matrix(matrix):
```

### Steps to Rotate the Matrix
1. **Transpose the Matrix**: Swap the elements at position `(i, j)` with those at position `(j, i)`.
2. **Reverse Each Row**: Reverse the elements in each row.

### Transposing the Matrix
- **Loop through the matrix**: 
  ```python
  for i in range(n):
      for j in range(i, n):
          matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
  ```
- **Swap Elements**: The element at `matrix[i][j]` is swapped with the element at `matrix[j][i]`.

### Reversing Each Row
- **Loop through each row**: 
  ```python
  for i in range(n):
      matrix[i].reverse()
  ```
- **Reverse Elements**: The elements in each row are reversed in place.

### Example
```python
if __name__ == "__main__":
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]

    rotate_2d_matrix(matrix)
    print(matrix)
```

### Output
The output of the provided example will be:
```
[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
```

### Explanation
1. **Initial Matrix**:
    ```
    [1, 2, 3]
    [4, 5, 6]
    [7, 8, 9]
    ```
2. **After Transposition**:
    ```
    [1, 4, 7]
    [2, 5, 8]
    [3, 6, 9]
    ```
3. **After Reversing Each Row**:
    ```
    [7, 4, 1]
    [8, 5, 2]
    [9, 6, 3]
    ```

## Usage
You can use the `rotate_2d_matrix` function to rotate any n x n 2D matrix 90 degrees clockwise.

```python
# Example usage
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

rotate_2d_matrix(matrix)
print(matrix)
```
