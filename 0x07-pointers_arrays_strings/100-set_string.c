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
	char *new_str = (char *) malloc((strlen(to) + 1) * sizeof(char));

	if (new_str == NULL)
	{
		printf("Error: failed to allocate memory\n");
		return;
	}
	strcpy(new_str, to);
	*s = new_str;
}
