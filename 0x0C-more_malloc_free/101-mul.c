#include "main.h"
#include <stdio.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 * Return: the integer value of s
 */
int _atoi(char *s)
{
	int i, n;

	n = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (_isdigit(s[i]))
			n = n * 10 + (s[i] - '0');
		else
			return (-1);
	}
	return (n);
}

/**
 * print_number - prints an integer
 * @n: the integer to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_number(n / 10);
	_putchar(n % 10 + '0');
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);

	if (num1 == -1 || num2 == -1)
	{
		printf("Error\n");
		return (98);
	}

	result = num1 * num2;
	print_number(result);
	_putchar('\n');

	return (0);
}
