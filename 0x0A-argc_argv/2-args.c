#include <stdio.h>
#include "main.h"

/**
 * main - progam that prints all arguments it recieves
 * @argv: vector
 * @argc: count
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
