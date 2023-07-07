#include "main.h"

/**
 * print_binary - function that prints the binary
 * representation of a number
 * @n: number to print
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int m = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int i = 1;

	while (m != 0)
	{
		if (n & m)
		{
			i = 0;
			_putchar('1');
		}
		else if (!i)
		{
			_putchar('0');
		}
		m >>= 1;
	}

	if (i)
	{
		_putchar('0');
	}
}
