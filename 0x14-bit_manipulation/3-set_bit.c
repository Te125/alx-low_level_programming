#include "main.h"
#include <stddef.h>

/**
 * set_bit - function that sets value of a bit
 * @n: pointer
 * @index: number
 *
 * Return: 1 if success, 0 if error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8 || n == NULL)
		return (-1);

	*n = *n | m;

	return (1);
}
