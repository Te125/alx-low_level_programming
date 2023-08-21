#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index -  function that inserts a
 *    new node at a given position.
 * @h: pointer to the head of dlistint_t
 * @idx: index of the list where the new node should be added
 * @n: integer for new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	unsigned int i = 0;
	dlistint_t *current = *h;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
		{
			free(new_node);
			return (NULL);
		}
		current = current->next;
	}
	new_node->prev = current;
	if (current != NULL)
	{
		new_node->next = current->next;
		current->next = new_node;
		if (new_node->next != NULL)
			new_node->next->prev = new_node;
	}
	else
	{
		free(new_node);
		return (NULL);
	}
	return (new_node);
}
