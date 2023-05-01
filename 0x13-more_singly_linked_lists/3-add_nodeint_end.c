#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end
 * @head: pointer to pointer
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *temp = *head;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (temp->next != NULL)
	temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
