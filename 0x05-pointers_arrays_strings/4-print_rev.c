#include "main.h"

/**
 * print_rev - check the code
 *
 * @s: pointer to the string to print
 *
 * Return: void.
*/

void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	while (i--)
	{
		putchar(s[i]);
	}
	putchar('\n');
}
