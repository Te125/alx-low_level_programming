#include "main.h"

/**
 * get_bit - function that returns the value of a bit at given index
 * @n: number to get bit
 * @index: index of bit
 *
 * Return: value of the bit at index or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
