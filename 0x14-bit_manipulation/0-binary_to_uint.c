#include "main.h"

/**
 * binary_to_uint - main function
 * @b: arg
 * Return: int
 */

unsigned int binary_to_uint(const char *b)
{
	int index;
	unsigned int num = 0;

	if (!b)
		return (0);

	for (index = 0; b[index]; index++)
	{
		if (b[index] < '0' || b[index] > '1')
			return (0);
		num = 2 * num + (b[index] - '0');
	}

	return (num);
}
