#include "hash_tables.h"

/**
 * hash_table_set - function one
 * @ht: arg one
 * @key: arg two
 * @value: arg three
 * Return: int 0 or 1
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *valCopy;
	unsigned long int ind, num;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	valCopy = strdup(value);
	if (valCopy == NULL)
	{
		return (0);
	}

	ind = key_index((const unsigned char *)key, ht->size);
	for (num = ind; ht->array[num]; num++)
	{
		if (strcmp(ht->array[num]->key, key) == 0)
		{
			free(ht->array[num]->value);
			ht->array[num]->value = valCopy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(valCopy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = valCopy;
	new->next = ht->array[ind];
	ht->array[ind] = new;

	return (1);
}
