#include "search_algos.h"

/**
 * interpolation_search - function one
 * @array: arge one
 * @size: arge two
 * @value: arge three
 * Return: index
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t position;
	int lower = 0;
	int height = size - 1;

	if (array == NULL || size == 0)
	{
		return (-1);
	}

	while (lower <= height)
	{
		position = lower + (((double)(height - lower) / (array[height] - array[lower]))
			     * (value - array[lower]));

		if (position > size - 1)
		{
			printf("Value checked array[%ld] is out of range\n", position);
			return (-1);
		}

		printf("Value checked array[%ld] = [%d]\n", position, array[position]);

		if (array[position] == value)
		{
			return (position);
		}
		else
		{
			if (array[position] > value)
			{
				height = position - 1;
			}
			else
			{
				lower = position + 1;
			}
		}
	}

	return (-1);
}
