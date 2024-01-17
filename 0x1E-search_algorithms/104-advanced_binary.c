#include "search_algos.h"

/**
 * print_array - function one
 * @array: arge one
 * @size: arge two
 * Return: void
 */

void print_array(int *array, int size)
{
	int ind;

	if (array == NULL || size == 0)
	{
		return;
	}

	printf("Searching in array: ");

	for (ind = 0; ind < size; ind++)
	{
		if (ind == 0)
		{
			printf("%d", array[ind]);
		}
		else
		{
			printf(", %d", array[ind]);
		}
	}

	printf("\n");
}

/**
 * recursive_binary_search - function two
 * @array: arge one
 * @low: arge two
 * @high: arge three
 * @value: arge four
 * Return: index
 */

int recursive_binary_search(int *array, int low, int high, int value)
{
	int m;

	if (low > high)
	{
		return (-1);
	}

	m = (low + high) / 2;

	print_array(&array[low], high - low + 1);

	if (array[m] == value)
	{
		if (array[m - 1] != value)
		{
			return (m);
		}
	}

	if (array[m] < value)
		return (recursive_binary_search(array, m + 1, high, value));
	else
		return (recursive_binary_search(array, low, m, value));
}

/**
 * advanced_binary - function three
 * @array: arge one
 * @size: arge two
 * @value: arge three
 * Return: index
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
	{
		return (-1);
	}

	return (recursive_binary_search(array, 0, size - 1, value));
}
