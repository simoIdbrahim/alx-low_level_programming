#include "search_algos.h"

/**
 * print_array - function
 * @array: arg one
 * @size: arg one
 * Return: void
 */

void print_array(int *array, int size)
{
	int ind;

	if (array == NULL || size == 0)
		return;

	printf("Searching in array: ");

	for (ind = 0; ind < size; ind++)
	{
		if (ind == 0)
			printf("%d", array[ind]);
		else
			printf(", %d", array[ind]);
	}

	printf("\n");
}

/**
 * binary_search - function two
 * @array: arge one
 * @size: arge two
 * @value: arg three
 * Return: index
 */

int binary_search(int *array, size_t size, int value)
{
	int lower = 0;
	int height = size - 1;
	int m;

	if (array == NULL || size == 0)
		return (-1);

	while (lower <= height)
	{
		m = lower + (height - lower) / 2;

		print_array(&array[lower], (height - lower) + 1);

		if (array[m] == value)
			return (m);

		if (array[m] > value)
			height = m - 1;

		else
			lower = m + 1;
	}

	return (-1);
}

/**
 * exponential_search - function three
 * @array: arge one
 * @size: arge two
 * @value: arge three
 * Return: index
 */

int exponential_search(int *array, size_t size, int value)
{
	int l_bound;
	int u_bound = 1;
	int val_position;

	if (array == NULL || size == 0)
		return (-1);

	while (u_bound < (int)size && array[u_bound] < value)
	{
		printf("Value checked array[%d] = [%d]\n", u_bound, array[u_bound]);
		l_bound = u_bound;
		u_bound *= 2;
	}

	if (u_bound >= (int)size)
		u_bound = size - 1;

	printf("Value found between indexes [%d] and [%d]\n", l_bound,
	       u_bound);
	val_position = binary_search(&array[l_bound],
				       u_bound - l_bound + 1, value);

	if (val_position != -1)
		val_position += l_bound;

	return (val_position);
}
