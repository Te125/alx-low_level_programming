#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array of nmemb elements
 * @nmemb: The number of elements to allocate.
 * @size: The size of each element.
 *
 * Return: A pointer to the allocated memory.
 *         NULL if nmemb or size is 0 or if malloc fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);

	p = ptr;

	for (i = 0; i < (nmemb * size); i++)
		*(p + i) = 0;

	return (ptr);
}
