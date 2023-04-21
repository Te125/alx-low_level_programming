#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * struct print - struct for format and function pointers
 * @type: The data type to be printed
 * @func: The function pointer to print the data type
 */
typedef struct print
{
	char *type;
	void (*func)(va_list);
} print_t;

void print_all(const char * const format, ...);
void print_c(va_list args);
void print_i(va_list args);
void print_f(va_list args);
void print_s(va_list args);

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
