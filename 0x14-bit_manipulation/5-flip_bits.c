#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would need
 * to flip to get one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x;
	int i = 63;
	int b = 0;
	unsigned long int p = n ^ m;

	for (; i >= 0; i--)
	{
		x = p >> i;
		if (x & 1)
		{
			b++;
		}
	}
	return (b);
}
