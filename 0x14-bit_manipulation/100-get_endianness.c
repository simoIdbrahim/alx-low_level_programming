#include "main.h"

/**
 * get_endianness - main function
 * Return: int
 */

int get_endianness(void)
{
	unsigned int num = 1;

	return (*(char *)&num);
}
