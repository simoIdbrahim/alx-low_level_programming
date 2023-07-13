#include "main.h"

/**
 * malloc_checked - main function.
 * @@b: int.
 * Return: pointer to the array initialized or NULL
 */

void *malloc_checked(unsigned int b)
{
	char *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
