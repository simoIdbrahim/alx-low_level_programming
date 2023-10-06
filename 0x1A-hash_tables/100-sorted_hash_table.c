#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - function one
 * @size: arg one
 * Return: if err Null or new sorted hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int ind;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		return (NULL);
	}
	for (ind = 0; ind < size; ind++)
	{
		ht->array[ind] = NULL;
	}
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - function two
 * @ht: arg one
 * @key: arg two
 * @value: arg three
 * Return: 0 || 1
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *valCopy;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	{
		return (0);
	}

	valCopy = strdup(value);
	if (valCopy == NULL)
	{
		return (0);
	}

	i = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = valCopy;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(valCopy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(valCopy);
		free(new);
		return (0);
	}
	new->value = valCopy;
	new->next = ht->array[i];
	ht->array[i] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - function three
 * @ht: arg one
 * @key: arg two
 * Return: Null || value associated with key in ht
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int i;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	i = key_index((const unsigned char *)key, ht->size);
	if (i >= ht->size)
	{
		return (NULL);
	}

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
	{
		node = node->snext;
	}

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - function four
 * @ht: arg one
 * Return: void
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
		{
			printf(", ");
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - function five
 * @ht: arg one
 * Return: void
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
		{
			printf(", ");
		}
	}
	printf("}\n");
}

/**
 * shash_table_delete - function sex
 * @ht: arg one
 * Return: void
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	if (ht == NULL)
	{
		return;
	}

	node = ht->shead;
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(head->array);
	free(head);
}
