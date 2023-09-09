#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table
 * @h: hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nodes;
	unsigned long int j;
	int key_i = 0;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			if (key_i == 1)
			{
				printf(", ");
			}
			nodes = ht->array[j];
			while (nodes != NULL)
			{
				printf("'%s': '%s'", nodes->key, nodes->value);
				nodes =nodes->next;
				if (nodes != NULL)
				{
					printf(", ");
				}
			}
			key_i = 1;
		}
	}
	printf("}\n");
}
