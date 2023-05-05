#include "main.h"

/**
 * clear_bit - sets value of a bit to 0 at given index
 * @n: pointer
 * @index: index starting from 0
 *
 * Return: 1 if successful, -1 if error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
