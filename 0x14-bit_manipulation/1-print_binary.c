#include "main.h"

/**
 * print_binary - main function
 * @n: arg
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int index, counter = 0;
	unsigned long int currentNum;

	for (index = 63; index >= 0; index--)
	{
		currentNum = n >> index;

		if (currentNum & 1)
		{
			putchar('1');
			counter++;
		}
		else if (counter)
			putchar('0');
	}
	if (counter)
		putchar('0');
}
