#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - iterates over an array and applies function
 * @array: ponter to the first element of the array
 * @size_t: size of array
 * @action: pointer to function that takes int parameter
 *
 * Description: function iterates over the array passed as parameter
 * the function pointed to by action to each element.
 *
 * Return: nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
