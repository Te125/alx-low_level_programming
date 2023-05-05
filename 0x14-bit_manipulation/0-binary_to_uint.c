#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 * @b:pointer
 *
 * Return: the converted number or 0 if one or more
 *        chars in the string b is not 0 or 1 or null.
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
