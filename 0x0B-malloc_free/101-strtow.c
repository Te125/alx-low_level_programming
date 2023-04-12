#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words in the string.
 */
static int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;

		if (str[i] && str[i] != ' ')
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}

	return (count);
}

/**
 * alloc_words - allocates memory for an array of words
 * @str: string to split into words
 * @word_count: number of words to allocate memory
 *
 * Return: a pointer to an array pf words, or null if malloc fails.
 */
static char **alloc_words(char *str, int word_count)
{
	char **words;
	int i;

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		while (*str && *str == ' ')
			str++;

		words[i] = str;
		while (*str && *str != ' ')
			str++;

		if (*str)
			*str++ = '\0';
	}

	words[word_count] = NULL;

	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings(words) or NULL if str == NULL,
 *        str == "" or if the function fails.
 */
char **strtow(char *str)
{
	int word_count;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);

	return (alloc_words(str, word_count));
}
