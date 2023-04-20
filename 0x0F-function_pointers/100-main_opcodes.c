#include <stdio.h>
#include <stdlib.h>

#define OP_CODE_SIZE 2

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	int num_bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	unsigned char *op_codes = (unsigned char *) main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", op_codes[i]);
	}

	printf("\n");

	return (0);
}
