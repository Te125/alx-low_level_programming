#include "hash_tables.h"

/**
 * hash-table_create - function that creates a hash
 * @size: size of the array
 *
 * Return: pointer to new hashtable, NULL if fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash;
	unsigned int p;

	hash = malloc(sizeof(hash_table_t));
	if (hash == NULL)
	{
		return (NULL);
	}
	hash->array = malloc(sizeof(hash_table_t *) * size);
	if (hash->array == NULL)
	{
		/**free(hash);**/
		return (NULL);
	}
	hash->size = size;
	for (p = 0; p < size; p++)
	{
		hash->array[p] = NULL;
	}
	return(hash);
}
