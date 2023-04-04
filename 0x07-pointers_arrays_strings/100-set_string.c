#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_string - function that sets the value of a pointer
 * @s: pointer to pointer
 * @to: char
 */
void set_string(char **s, char *to)
{
	*s = to;
}
