#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - function that prints all elements of dlistint_t list
 * @h: head of dlistint_t list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		c++;
	}

	return (c);
}
