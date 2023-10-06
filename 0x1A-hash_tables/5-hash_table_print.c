#include "hash_tables.h"

/**
 * hash_table_print - function one
 * @ht: arg one
 * Returne: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int index;
	unsigned char flag = 0;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (flag == 1)
				printf(", ");

			node = ht->array[index];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
