#include "lists.h"

/**
 * sum_listint - returns sum of data
 * @head: pointer
 *
 * Return: sum of all the data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
