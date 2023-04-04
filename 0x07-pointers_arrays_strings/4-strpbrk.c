#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - function that locates the first occurence
 * @s: string to search
 * @accept: one of the bytes
 *
 * Return: a pointer to the byte
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (s + i);
			}
		}
	}

	return (0);
}
