#include "main.h"

/**
 * flip_bits - returns number of bits
 * @n: unsigned long int
 * @m: unsigned long int
 *
 * Return: number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int i;

	while (xor)
	{
		i += xor & 1;
		xor >>= 1;
	}
	return (i);
}
