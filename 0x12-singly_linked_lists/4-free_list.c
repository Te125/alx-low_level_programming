#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list
 * @head: Pointer
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}
