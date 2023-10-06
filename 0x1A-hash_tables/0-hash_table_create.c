#include "hash_tables.h"

/**
 * hash_table_create - main function
 * @size: arg one
 * Return: null or hash tabel
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int ind;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (ind = 0; ind < size; ind++)
		ht->array[ind] = NULL;

	return (ht);
}
