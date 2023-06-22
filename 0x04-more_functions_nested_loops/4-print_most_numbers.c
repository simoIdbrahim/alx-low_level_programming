#include "main.h"

/**
 * print_most_numbers - print 0 -9 apart from 2 and 4
 *
 * Return: Always 0 (Success)
*/

void print_most_numbers(void)
{
	for (int i = 0; i <= 8; i++)
	{
		if (i == 2 || i == 4)
			continue;
		_putchar(i + 48);
	}
	_putchar('\n');
}
