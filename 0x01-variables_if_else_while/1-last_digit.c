#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints the last digit of a randomly generated number 
 * and whether it is greater than 5, less than 6, or 0.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int ld;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	ld= n % 10;
	if (ld > 5)
	{
		printf("Last digit of %d is %d and is greater than 5", n, ld);
	}
	else if (ld == 0)
	{
		printf("Last digit of %d is %d and is 0", n, ld);
	}
	else
	{
		printf("Last digit of %d is %d and less than 6 and not 0", n, ld);
	}
	return (0);
}
