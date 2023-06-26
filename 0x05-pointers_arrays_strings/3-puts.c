#include "main.h"

/**
 * _puts - check the code
 *
 * @str: string parameter to print
 *
 * Return: Nothing.
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		putchar(*str + 0);
		str++;
	}
	putchar('\n');
}
