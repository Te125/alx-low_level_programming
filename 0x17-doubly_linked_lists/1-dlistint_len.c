#include <stddef.h>
#include "lists.h"

/**
 * dlistint_len - function that returns the number of elements of a linked list
 * @h: head of dlistint_len
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		h = h->next;
		c++;
	}

	return (c);
}
