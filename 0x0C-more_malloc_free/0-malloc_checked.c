#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - function that allocates memory
 * @b: size of memory to alocate.
 *
 * Return: pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
	{
		exit(98);
	}
	return (p);
}
