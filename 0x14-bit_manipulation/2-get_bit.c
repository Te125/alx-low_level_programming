#include "main.h"
#include <limits.h>

/**
 * get_bit - function that returns the value of a bit
 * @n: number
 * @index: index number
 *
 * Return: value of the bit at index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int m = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	if ((n & m) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
