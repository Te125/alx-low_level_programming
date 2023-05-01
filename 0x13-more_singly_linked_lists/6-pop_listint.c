#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * and returns the head node's data (n)
 * @head: pointer
 *
 * Return: the head node(n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	if (head == NULL || *head == NULL)
		return (0);

	n = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (n);
}
