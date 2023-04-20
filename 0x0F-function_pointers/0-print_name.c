#include <stdio.h>
#include "function_pointers.h"

/*
 * print_name - prints a name
 * @name: pointer to name
 * @f: pointer to function
 *
 * Description: function that prints a name by passing
 *           it to the function pointed to by f.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	{
		f(name);
	}
}
