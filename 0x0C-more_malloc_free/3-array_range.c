#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers.
 * @min: The minimum value (inclusive).
 * @max: The maximum value (inclusive).
 *
 * Return: A pointer to the newly created array.
 *         NULL if min > max or if malloc fails.
 */
int *array_range(int min, int max)
{
	int *arr, i, len;

	if (min > max)
		return (NULL);

	len = max - min + 1;

	arr = malloc(sizeof(int) * len);

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		*(arr + i) = min + i;

	return (arr);
}
