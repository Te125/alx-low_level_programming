#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value associated
 *       with a key
 * @ht: hash table to look into
 * @key: key to look for
 *
 * Return: value associated with the element,
 *       or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nodes;
	unsigned long int index;

	if (ht == NULL || key == NULL)
	{
		return (NULL);
	}
	index = key_index((const unsigned char *)key, ht->size);
	nodes = ht->array[index];
	if (nodes == NULL)
	{
		return (NULL);
	}
	while (nodes != NULL)
	{
		if (strcmp(nodes->key, key) == 0)
		{
			return (nodes->value);
		}
		nodes = nodes->next;
	}
	return (NULL);
}
