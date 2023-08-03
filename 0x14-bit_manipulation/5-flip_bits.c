#include "main.h"

/**
 * flip_bits - main funtion
 * @n: first arg
 * @m: seconder arg
 * Return: int
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int index, counter = 0;
	unsigned long int currentNum;
	unsigned long int not = n ^ m;

	for (index = 63; index >= 0; index--)
	{
		currentNum = not >> index;
		if (currentNum & 1)
			counter++;
	}

	return (counter);
}
