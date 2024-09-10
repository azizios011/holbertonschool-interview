---

# README

## Overview of Regular Expressions (RegEx)

### What is RegEx?

Regular Expressions (RegEx) are sequences of characters that define search patterns. They are used in programming for tasks such as searching, replacing, and validating strings based on specific patterns. RegEx is powerful for string manipulation and data extraction.

### How Does RegEx Work?

RegEx operates using a set of special characters and syntax to define patterns. Here are the key components:

1. **Literal Characters**: Directly match the characters in a string. For example, the pattern `hello` matches the string "hello".

2. **Special Characters**:
   - `.`: Matches any single character except a newline.
   - `*`: Matches zero or more occurrences of the preceding character.

3. **Character Classes**:
   - `[abc]`: Matches any single character that is 'a', 'b', or 'c'.
   - `[^abc]`: Matches any character except 'a', 'b', or 'c'.

4. **Quantifiers**:
   - `{n}`: Matches exactly `n` occurrences of the preceding character.
   - `{n,}`: Matches at least `n` occurrences.
   - `{n,m}`: Matches between `n` and `m` occurrences.

5. **Anchors**:
   - `^`: Matches the start of the string.
   - `$`: Matches the end of the string.

6. **Groups and Alternation**:
   - `(abc)`: Groups characters together to apply operators to the group.
   - `|`: Acts as a logical OR. For example, `cat|dog` matches "cat" or "dog".

### Why Use RegEx?

RegEx is useful for:
- **Validation**: Ensuring a string follows a specific format (e.g., email addresses, phone numbers).
- **Search**: Finding patterns within text.
- **Replace**: Substituting parts of a string based on patterns.
- **Split**: Dividing a string into parts based on a pattern.

## Explanation of `regex.h` and `regex.c`

### `regex.h`

This header file contains the prototype for the RegEx matching function.

**Content of `regex.h`:**

```c
#ifndef REGEX_H
#define REGEX_H

int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
```

**Explanation:**

1. `#ifndef REGEX_H`  
   Checks if `REGEX_H` has not been defined. This prevents multiple inclusions of the file.

2. `#define REGEX_H`  
   Defines `REGEX_H` to indicate that the file has been included.

3. `int regex_match(char const *str, char const *pattern);`  
   Declares the `regex_match` function. It takes two constant character pointers: `str` (the string to be matched) and `pattern` (the regex pattern). It returns an integer: `1` if the pattern matches the string, `0` otherwise.

4. `#endif /* REGEX_H */`  
   Ends the conditional inclusion started by `#ifndef`.

### `regex.c`

This file contains the implementation of the `regex_match` function.

**Content of `regex.c`:**

```c
#include "regex.h"

/**
 * regex_match - Checks if a given string matches a given regex pattern
 * @str: String to scan
 * @pattern: Regular expression pattern
 *
 * Return: 1 if the pattern matches the string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
    /* Base case: if pattern is empty */
    if (*pattern == '\0')
        return (*str == '\0');

    /* Case when the next character in the pattern is '*' */
    if (*(pattern + 1) == '*')
    {
        /* Move on if the pattern after '*' matches, or if current character matches */
        return (regex_match(str, pattern + 2) ||
               ((*str != '\0') && (*str == *pattern || *pattern == '.') && regex_match(str + 1, pattern)));
    }

    /* Case when there's no '*' */
    if (*str != '\0' && (*str == *pattern || *pattern == '.'))
        return (regex_match(str + 1, pattern + 1));

    return (0);
}
```

**Explanation:**

1. `#include "regex.h"`  
   Includes the header file `regex.h` to ensure the function prototype is consistent.

2. `int regex_match(char const *str, char const *pattern)`  
   Defines the function `regex_match` that performs regex matching. It takes two arguments: `str` (the string to match) and `pattern` (the regex pattern). It returns `1` if the pattern matches, otherwise `0`.

3. `/* Base case: if pattern is empty */`  
   Comments describing the base case for recursion.

4. `if (*pattern == '\0')`  
   Checks if the `pattern` is empty. If it is, matching is successful only if `str` is also empty.

5. `return (*str == '\0');`  
   Returns `1` if `str` is empty when `pattern` is empty; otherwise, returns `0`.

6. `/* Case when the next character in the pattern is '*' */`  
   Comments explaining the case when `*` is used in the pattern.

7. `if (*(pattern + 1) == '*')`  
   Checks if the character following the current character in `pattern` is `*`. This means that the preceding character can appear zero or more times.

8. `return (regex_match(str, pattern + 2) ||`  
   First attempt to match the pattern after `*` by moving the pattern forward (`pattern + 2`).

9. `((*str != '\0') && (*str == *pattern || *pattern == '.') && regex_match(str + 1, pattern)));`  
   Second attempt to match: check if the current character in `str` matches the current character in `pattern` or if `pattern` is `.`. If it matches, continue with the rest of `str` and the same `pattern`.

10. `/* Case when there's no '*' */`  
    Comments explaining the case when `*` is not used in the pattern.

11. `if (*str != '\0' && (*str == *pattern || *pattern == '.'))`  
    Checks if `str` is not empty and the current characters in `str` and `pattern` match or if `pattern` is `.`.

12. `return (regex_match(str + 1, pattern + 1));`  
    Continues matching the next characters in `str` and `pattern`.

13. `return (0);`  
    Returns `0` if no conditions for a match are met.

This implementation handles basic regex patterns with `.` and `*`. More complex patterns would require additional code.

---
