#include "main.h"

/**
 * print_binary - main function
 * @n: arg
 * Return: void
 */

void print_binary(unsigned long int n)
{
	int b = sizeof(n) * 8, print = 0;

	while (b)
	{
		if (n & 1L << --b)
		{
			putchar('1');
			print++;
		}
		else if (print)
			putchar('0');
	}

	if (!print)
		putchar('0');
}
