#include <stddef.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - function that returns the
 *      nth node of a dlistint_t linked list.
 * @head: head of dlistint_t
 * @index: index of the node, starting from 0
 *
 * Return: if the node does not exist, return NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int c = 0;

	while (current != NULL)
	{
		if (c == index)
		{
			return (current);
		}
		current = current->next;
		c++;
	}
	return (NULL);
}
