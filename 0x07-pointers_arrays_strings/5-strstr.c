#include "main.h"
/**
 * _strstr - functions that locates a substring
 * @needle: substring
 * @haystack: string
 *
 * Return: pointer to the beginning of the located substring
 */
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
	{
		return (haystack);
	}
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *sub = needle;

		while (*haystack != '\0' && *sub != '\0' && *haystack == *sub)
		{
			haystack++;
			sub++;
		}
		if (*sub == '\0')
		{
			return (start);
		}
		haystack = start + 1;
	}
	return (0);
}
