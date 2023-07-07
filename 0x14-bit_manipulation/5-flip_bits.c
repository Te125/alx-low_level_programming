#include "main.h"

/**
 * flip_bits - function that returns the number of bits to flip
 * @n: number
 * @m: number
 *
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff != 0)
	{
		count = count + (diff & 1);
		diff = diff >> 1;
	}
	return (count);
}
