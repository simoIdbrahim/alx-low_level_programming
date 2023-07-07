#include "main.h"

/**
 * _strlen - check the code
 *
 * @s: string parameter input
 *
 * Return: Always 0.
*/

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; s++)
		++counter;

	return (counter);

}
