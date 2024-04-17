
---

# Palindrome Integer Checker

## Overview

This program checks whether a given unsigned integer is a palindrome. A palindrome is a number that reads the same backward as forward.

## Method

The program provides a function called `is_palindrome()` which takes an unsigned integer as input and returns 1 if the number is a palindrome, and 0 otherwise.

### Function Definition

```c
int is_palindrome(unsigned long n);
```

### Algorithm

1. **Initialization**: The function `is_palindrome()` begins with the definition of two unsigned long variables `reversed` and `original`. `reversed` will store the reversed version of the input number, and `original` will store the original input number.

```c
unsigned long reversed = 0, original = n;
```

2. **Digit Reversal**: The function enters a while loop that iterates until the input number `n` becomes 0. Within the loop, it updates the `reversed` variable by multiplying it by 10 and adding the remainder of `n` when divided by 10, effectively reversing the digits of the number.

```c
while (n != 0)
{
    reversed = reversed * 10 + n % 10;
    n /= 10;
}
```

3. **Comparison**: After reversing the digits of the number, the function compares the original number (`original`) with its reversed version (`reversed`). If they are equal, the number is a palindrome, and the function returns 1; otherwise, it returns 0.

```c
return original == reversed ? 1 : 0;
```

## Usage

To use the function, include the header file `palindrome.h` and call `is_palindrome()` with the unsigned integer to be checked.

Example:

```c
#include <stdio.h>
#include "palindrome.h"

int main() {
    unsigned long n = 12321;
    if (is_palindrome(n)) {
        printf("%lu is a palindrome.\n", n);
    } else {
        printf("%lu is not a palindrome.\n", n);
    }
    return 0;
}
```

Compile the program with:

```bash
gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
```

Then run it with:

```bash
./palindrome 12321
```

## Files

- `0-main.c`: Main program file containing the `main()` function.
- `0-is_palindrome.c`: Implementation file containing the `is_palindrome()` function.
- `palindrome.h`: Header file containing the function prototype.

## Requirements

- The program is written in C.
- It does not use dynamic memory allocation functions like `malloc`, `calloc`, etc.

## Author

This program was authored by [Your Name].

---
