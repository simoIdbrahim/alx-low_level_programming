#include "main.h"

/**
 * swap_int - check the code
 *
 * @a: input parameter 1
 * @b: input parameter 2
 *
 * Return: Always 0.
*/

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
