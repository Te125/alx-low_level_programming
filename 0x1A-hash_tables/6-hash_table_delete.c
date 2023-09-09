#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table
 * @ht: the hash table
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *begin, *end;
	unsigned long int j, n;

	n = ht->size;
	if (ht == NULL)
	{
		return;
	}
	if (ht->array == NULL)
	{
		free(ht);
		return;
	}
	for (j = 0; j < n; j++)
	{
		begin = ht->array[j];
		while (begin)
		{
			end = begin;
			begin = begin->next;
			free(end->key);
			free(end->value);
			free(end);
		}
	}
	free(ht->array);
	free(ht);
}
