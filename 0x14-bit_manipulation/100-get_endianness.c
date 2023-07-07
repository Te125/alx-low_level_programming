#include "main.h"

/**
 * get_endianness - function that check endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *ptr = (unsigned char *)&num;

	if (*ptr)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
