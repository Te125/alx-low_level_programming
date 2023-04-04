#include "main.h"

/**
 * _memcpy - function that copies from memory
 * @dest: pointer to destination
 * @src: pointer to a memory
 * @n: number of bytes to copy
 *
 * Return: pointer to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
