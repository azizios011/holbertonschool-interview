
---

# Substring Concatenation Problem Solver

## Problem and Solution Description:

This C program solves a common substring concatenation problem: given a string `s` and a list of words `words`, the goal is to find all starting indices of substring(s) in `s` that is a concatenation of each word from `words` exactly once, without any intervening characters. All words have the same length.

### Problem Constraints:
- Each word in the list has the same length.
- The words can be concatenated in any order to form the substring.
- The task is to return all starting indices of such substrings.
- If no such concatenation exists, the program returns `NULL`.

### Solution:
The solution employs a sliding window approach combined with hash maps (arrays) to keep track of word counts. It iterates over the string `s`, checking all potential starting indices to see if they can form a valid concatenation of the words from the list.

The program builds a word count map for the list of words and compares this with the words found in the substring being checked. If all words are found in correct frequency, the starting index is added to the result list.

---

## Code Explanation (Line-by-Line):

### Command-line Arguments and Imports:

```c
#include "substring.h"
#include <stdlib.h>
#include <string.h>
```
- `substring.h`: This is the custom header file containing the function prototype for `find_substring`.
- `stdlib.h`: Provides functions for memory management (`malloc`, `calloc`) and standard library functions.
- `string.h`: Includes string manipulation functions like `strlen`, `strcmp`, and `strncmp`.

### Helper Function to Build Word Frequency Map:

```c
int *build_word_count(char const **words, int nb_words)
{
    int *word_count = calloc(nb_words, sizeof(int));
    int i, j;
```
- `build_word_count`: Initializes and returns an array that tracks the frequency of each word in the list `words`.
- `calloc(nb_words, sizeof(int))`: Allocates memory for the `word_count` array, initializing all elements to zero.
- Loop variables `i` and `j` are used to iterate over the list of words.

```c
    for (i = 0; i < nb_words; i++) {
        for (j = 0; j < nb_words; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_count[i]++;
            }
        }
    }
    return word_count;
}
```
- Double loop: Compares each word in the list with every other word and increments the corresponding count in `word_count` when a match is found.
- `strcmp`: Compares two strings and returns `0` if they are identical.
- The `word_count` array is returned, storing the number of occurrences of each word.

### Helper Function to Check if Substring Matches a Word:

```c
int check_match(char const *sub, char const **words, int nb_words, int word_len)
{
    for (int i = 0; i < nb_words; i++) {
        if (strncmp(sub, words[i], word_len) == 0) {
            return i;
        }
    }
    return -1;
}
```
- `check_match`: Checks if a substring of `s` matches any word in `words`.
- `sub`: The substring of `s` currently being checked.
- `words`: Array of words to be matched.
- `word_len`: The length of each word (since all words have the same length).
- `strncmp`: Compares up to `word_len` characters of `sub` and `words[i]`.
- Returns the index of the matching word, or `-1` if no match is found.

### Main Function (`find_substring`):

```c
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int word_len = strlen(words[0]);
    int s_len = strlen(s);
    int total_len = word_len * nb_words;
    int *indices = NULL;
    int *word_count = NULL, *current_count = NULL;
    int i, j, start;
```
- `find_substring`: Main function that implements the substring search logic.
- `word_len`: Length of each word, determined by the first word in the list.
- `s_len`: Length of the input string `s`.
- `total_len`: The total length of the substring to check, calculated as `word_len * nb_words`.
- `indices`: An array that will store the starting indices of valid substrings.
- `word_count` and `current_count`: Arrays to store word frequencies and track the count of words encountered in the current substring.
- `i`, `j`, `start`: Loop variables for iteration.

```c
    *n = 0;
    if (s_len < total_len || nb_words == 0)
        return NULL;
```
- Initializes `*n` (the number of valid substrings found) to `0`.
- If the length of the string `s` is shorter than the required substring length, or there are no words, return `NULL` because no valid substrings exist.

```c
    word_count = build_word_count(words, nb_words);
    current_count = calloc(nb_words, sizeof(int));
    indices = malloc(s_len * sizeof(int));
```
- `build_word_count`: Calls the helper function to initialize `word_count` with the frequency of words.
- `calloc(nb_words, sizeof(int))`: Allocates memory for `current_count` to track word occurrences during substring matching.
- `malloc(s_len * sizeof(int))`: Allocates memory for `indices` to store all potential starting indices.

### Loop Over Each Possible Substring:

```c
    for (i = 0; i <= s_len - total_len; i++) {
        memset(current_count, 0, nb_words * sizeof(int));
        start = i;
```
- The loop starts from each possible index `i` in the string `s`, where the substring could start.
- `memset(current_count, 0, ...)`: Resets the `current_count` array to zero before processing the next substring.
- `start = i`: Marks the current starting index for this substring.

```c
        for (j = 0; j < nb_words; j++) {
            char const *sub = s + start + j * word_len;
            int found = check_match(sub, words, nb_words, word_len);
```
- A nested loop iterates over each word in the list `words`.
- `sub = s + start + j * word_len`: Points to the substring in `s` to be checked against `words[j]`.
- `check_match`: Calls the helper function to determine if the current substring matches any word.

### Check Word Match and Update Count:

```c
            if (found == -1 || ++current_count[found] > word_count[found])
                break;
```
- If no matching word is found (`found == -1`), or the current word occurs more than its frequency in `word_count`, the loop breaks.
  
```c
            if (j == nb_words - 1) {
                indices[*n] = i;
                (*n)++;
            }
        }
    }
```
- If all words in the substring match the required frequency, the starting index `i` is stored in `indices`, and `*n` is incremented.

### Memory Cleanup and Return:

```c
    free(word_count);
    free(current_count);
    if (*n == 0) {
        free(indices);
        return NULL;
    }
    return indices;
}
```
- Frees the allocated memory for `word_count` and `current_count`.
- If no valid substrings were found (`*n == 0`), frees the `indices` array and returns `NULL`.
- Otherwise, returns the `indices` array containing the starting indices of valid substrings.

---
