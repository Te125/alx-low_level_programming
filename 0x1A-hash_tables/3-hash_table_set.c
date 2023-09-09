#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: hash table to add or update key/value
 * @key: key
 * @value: associated with the key
 *
 * Return: 1 if it succeeds, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *nodes;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
	{
		return (0);
	}
	index = key_index((const unsigned char *)key, ht->size);
	nodes = ht->array[index];

	while (nodes)
	{
		if (strcmp(nodes->key, key) == 0)
		{
			free(nodes->value);
			nodes->value = strdup(value);
			return (nodes->value ? 1 : 0);
		}
		nodes = nodes->next;
	}
	nodes = malloc(sizeof(hash_node_t));
	if (!nodes)
	{
		return (0);
	}
	nodes->key = strdup(key);
	nodes->value = strdup(value);
	if (!nodes->key || !nodes->value)
	{
		free(nodes->key);
		free(nodes->value);
		free(nodes);
		return (0);
	}
	nodes->next = ht->array[index];
	ht->array[index] = nodes;
	return (1);
}
