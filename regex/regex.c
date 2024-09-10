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
