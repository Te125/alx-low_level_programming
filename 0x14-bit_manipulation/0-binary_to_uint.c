#include "main.h"

/**
 * binary_to_uint - function that converts binary to number
 * @b: pointer
 *
 * Return: the converted number or 0 if there is one or more
 * chars in the string b that is not 0 or 1, b is null
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;

	if (!b)
		return (0);

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
