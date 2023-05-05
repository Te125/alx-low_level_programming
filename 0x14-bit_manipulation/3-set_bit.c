#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at given index
 * @n: pointer
 * @index: index starting from 0
 *
 * Return: 1 if it worked, or -1 if error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	*n |= 1ul << index;

	return (1);
}
