#include "main.h"
#include <stddef.h>

/**
 * clear_bit - function that sets the value of a bit at 0
 * @n: pointer
 * @index: number
 *
 * Return: 1 if success, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8 || n == NULL)
		return (-1);

	m = ~m;
	*n = *n & m;

	return (1);
}
