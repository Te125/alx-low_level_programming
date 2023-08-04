#include "main.h"

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index
 * @n: pointer to number
 * @index: index of bit to clear
 *
 * Return:1 if successful, -1 if error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i = 63;

	if (index > i)
	{
		return (-1);
	}
	else if (index == i)
	{
		*n &= (1UL << index);
	}
	else
	{
		if (index < i)
		{
			*n = (~(1UL << index) & *n);
		}
	}

	return (1);
}
