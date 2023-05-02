#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list
 * @head: pointer
 *
 * Return: size of the list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next, *tortoise, *hare;

	if (h == NULL || *h == NULL)
		return (0);

	tortoise = *h;
	hare = (*h)->next;

	while (hare != NULL && hare < hare->next)
	{
		current = tortoise;
		tortoise = tortoise->next;
		hare = hare->next;
		next = hare->next;

		free(current);
		count++;

		if (hare == tortoise)
		{
			free(hare);
			count++;
			break;
		}

		current = hare;
		hare = next;
		tortoise = tortoise->next;

		free(current);
		count++;
	}

	*h = NULL;

	return (count);
}
