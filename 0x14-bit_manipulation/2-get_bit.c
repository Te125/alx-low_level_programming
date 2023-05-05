#include "main.h"

/**
 * get_bit - returns value of a bit at a given index
 * @n: number
 * @index: index starting from 0 of the bit
 *
 * Return: the value of the bit at index or -1 if error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}
