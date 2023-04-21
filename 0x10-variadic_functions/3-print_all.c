#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_c - Prints a char
 * @args: A list of arguments pointing to the char to be printed
 */
void print_c(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_i - Prints an int
 * @args: A list of arguments pointing to the int to be printed
 */
void print_i(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_f - Prints a float
 * @args: A list of arguments pointing to the float to be printed
 */
void print_f(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_s - Prints a string
 * @args: A list of arguments pointing to the string to be printed
 */
void print_s(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(nil)";

	printf("%s", s);
}

/**
 * print_all - Prints anything
 * @format: A list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	print_t p[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	};
	va_list args;
	int i = 0, j;
	char *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (p[j].type)
		{
			if (format[i] == *(p[j].type))
			{
				printf("%s", sep);
				p[j].func(args);
				sep = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
