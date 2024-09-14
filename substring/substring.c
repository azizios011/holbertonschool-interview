#include "substring.h"

/**
 * build_word_count - Builds a frequency map of the words array
 * @words: Array of words
 * @nb_words: Number of words
 *
 * Return: An array of word counts.
 */
int *build_word_count(char const **words, int nb_words)
{
	int *word_count = calloc(nb_words, sizeof(int));
	int i, j;

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (strcmp(words[i], words[j]) == 0)
			{
				word_count[i]++;
			}
		}
	}

	return (word_count);
}

/**
 * check_match - Checks if a substring matches any word in the list.
 * @sub: The substring to compare.
 * @words: Array of words.
 * @nb_words: Number of words.
 * @word_len: Length of each word.
 *
 * Return: The index of the matching word, or -1 if no match is found.
 */
int check_match(char const *sub, char const **words,
										int nb_words, int word_len)
{
	for (int i = 0; i < nb_words; i++)
	{
		if (strncmp(sub, words[i], word_len) == 0)
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * find_substring - Finds all possible substrings formed by concatenating all
 *                  words in a given list of words.
 * @s: The input string.
 * @words: Array of words to concatenate.
 * @nb_words: Number of words in the array.
 * @n: Pointer to an integer where the number of results will be stored.
 *
 * Return: An allocated array of starting indices of substrings in s, or NULL.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]);
	int s_len = strlen(s);
	int total_len = word_len * nb_words;
	int *indices = NULL;
	int *word_count = NULL, *current_count = NULL;
	int i, j, start;

	*n = 0;
	if (s_len < total_len || nb_words == 0)
		return (NULL);
	word_count = build_word_count(words, nb_words);
	current_count = calloc(nb_words, sizeof(int));
	indices = malloc(s_len * sizeof(int));
	for (i = 0; i <= s_len - total_len; i++)
	{
		memset(current_count, 0, nb_words * sizeof(int));
		start = i;
		for (j = 0; j < nb_words; j++)
		{
			char const *sub = s + start + j * word_len;
			int found = check_match(sub, words, nb_words, word_len);

			if (found == -1 || ++current_count[found] > word_count[found])
				break;

			if (j == nb_words - 1)
			{
				indices[*n] = i;
				(*n)++;
			}
		}
	}
	free(word_count);
	free(current_count);
	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
