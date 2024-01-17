#include "search_algos.h"

/**
 * print_arr - function one
 * @array: arg one
 * @low: arg two
 * @high: arg three
 * Return: void
 */

void print_arr(int *array, size_t low, size_t high)
{
	size_t ind = 0;

	printf("Searching in array: ");
	for (ind = low; ind <= high; ind++)
	{
		if (ind != high)
		{
			printf("%d, ", array[ind]);
		}
		else
		{
			printf("%d\n", array[ind]);
		}
	}
}

/**
 * binary_search - function two
 * @array: arg one
 * @size: arg two
 * @value: arg three
 * Return: index
 */

int binary_search(int *array, size_t size, int value)
{
	size_t mid = 0;
	size_t lower = 0;
	size_t height = size - 1;

	if (!array || size <= 0)
		return (-1);

	while (lower <= height)
	{
		print_arr(array, lower, height);

		mid = (lower + height) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			height = mid - 1;
		else
			lower = mid + 1;
	}
	return (-1);
}
