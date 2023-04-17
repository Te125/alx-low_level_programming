#include <stdio.h>

/**
 * main - program that prints name of file it was
 *        compiled from
 *
 * Return: 0(success)
 */
int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
