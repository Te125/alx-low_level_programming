#include "main.h"

/**
 * binary_to_uint - function that converts binary number to an unsigned int
 * @b: pointer to string
 *
 * Return: converted number or 0 if one or more chars
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;

	if (!b)
	{
		return (0);
	}

	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			i = i << 1;
			i += *b - '0';
			b++;
		}
		else
		{
			return (0);
		}
	}
	return (i);
}
