
# UTF-8 Validation

## Overview:

This README file provides a line-by-line explanation of the `validUTF8` function, which determines if a given data set represents a valid UTF-8 encoding.

## Function Definition:
```

```python
def validUTF8(data):
```

- This line defines a function named `validUTF8` that takes one parameter, `data`, which is a list of integers representing bytes of data.

## Variable Initialization:

```python
    num_bytes = 0
```

- This line initializes a variable `num_bytes` to 0. This variable will be used to keep track of the number of continuation bytes following the leading byte of a multi-byte character sequence.

## Loop Through Data:

```python
    for num in data:
```

- This line starts a loop that iterates over each integer in the `data` list.

## Check for Single-Byte Characters:

```python
        if num >> 7 == 0b0:
```

- This line checks if the most significant bit (MSB) of the byte represented by `num` is 0. If it is, it means that `num` represents a single-byte character in UTF-8 encoding.

## Check for Multi-Byte Characters:

```python
            elif num >> 3 == 0b11110:
                num_bytes = 3
            elif num >> 4 == 0b1110:
                num_bytes = 2
            elif num >> 5 == 0b110:
                num_bytes = 1
```

- These lines check the leading bits in the binary representation of `num` to determine the number of bytes required to represent a UTF-8 character sequence.
  - `num_bytes` is updated accordingly to reflect the number of continuation bytes following the leading byte.

## Check Continuation Bytes:

```python
        else:
            if num >> 6 != 0b10:
                return False
            num_bytes -= 1
```

- These lines check if the current integer `num` is a continuation byte by ensuring that its two most significant bits (after shifting by 6 bits) are `10`. If the condition is not met, it means that `num` is not a valid continuation byte, and the function returns `False`.
- If `num` is a valid continuation byte, `num_bytes` is decremented by 1 to indicate that one continuation byte has been processed.

## Check for Unprocessed Bytes:

```python
    return num_bytes == 0
```

- This line checks if all bytes have been processed by ensuring that `num_bytes` is equal to 0. If `num_bytes` is not 0, it means that there are unprocessed bytes in the UTF-8 encoding, and the function returns `False`. Otherwise, it returns `True`.
``` 

This README file provides a detailed explanation of the `validUTF8` function, helping users understand its functionality and implementation details.
