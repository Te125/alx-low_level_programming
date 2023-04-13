#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory
 * @old_size: Size of the allocated space for ptr
 * @new_size: New size of the new memory block
 *
 * Return: Pointer to the reallocated memory block
 *         NULL if new_size = 0 and ptr is not NULL
 *         NULL if memory allocation fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *q;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	p = ptr;
	q = malloc(new_size);

	if (q == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		q[i] = p[i];

	free(ptr);

	return (q);
}
