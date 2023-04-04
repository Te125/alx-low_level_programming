#include "main.h"
/**
 * _memset - function fills the memory
 * @s: a pointer to a memory
 * @b: a constant byte
 * @n: the number of bytes to be filled
 *
 * Return: a pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
