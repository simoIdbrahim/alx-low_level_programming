#include "hash_tables.h"

/**
 * key_index - function one
 * @key: arg one
 * @size: arg two
 * Return: ind key
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	int result = hash_djb2(key) % size;
	return (result);
}
