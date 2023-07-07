#include "main.h"
#include <stdio.h>

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
		printf("%d", *str + 0);
		str++;
	}
	printf("\n");
}
