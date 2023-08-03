#include "main.h"

/**
 * set_bit - main function
 * @n: arg
 * @index: arg
 *
 * Return: int
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	int num = !!(*n |= 1L << index);

	return (num);
}
