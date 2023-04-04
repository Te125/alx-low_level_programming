#include "main.h"

/**
 * _strchr - locates char in a string
 * @s: pointer to a string
 * @c: points to the first occurence of char
 *
 * Return: NULL if char is not found
 */
char *_strchr(char *s, char c)
{
	while  (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (*s == c)
		return (s);

	return (0);
}
