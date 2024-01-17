#include "search_algos.h"

/**
 * linear_search - function one
 * @array: arg one arr
 * @size: arg two int
 * @value: art three val
 * Return: int index
 */

int linear_search(int *array, size_t size, int value)
{
	size_t ind;

	if (!array || size <= 0)
	{
		return (-1);
	}

	ind = 0;
	while (ind < size)
	{
		printf("Value checked array[%ld] = [%d]\n", ind, array[ind]);
		if (array[ind] == value)
			return (ind);
		ind++;
	}
	return (-1);
}
