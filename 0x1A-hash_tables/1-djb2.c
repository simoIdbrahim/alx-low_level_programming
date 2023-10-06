#include "hash_tables.h"

/**
 * hash_djb2 - function one
 * @str: arg one
 * Return: calc hash
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int h;
	int calc;

	h = 5381;
	while ((calc = *str++))
	{
		h = ((h << 5) + h) + calc;
	}

	return (h);
}
