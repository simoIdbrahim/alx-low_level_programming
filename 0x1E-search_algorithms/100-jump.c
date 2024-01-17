#include <math.h>
#include "search_algos.h"

/**
 * jump_search - function one
 * @array: arg one
 * @size: arg two
 * @value: arg three
 * Return: index
 */

int jump_search(int *array, size_t size, int value)
{
	int j = sqrt(size);
	int s = 0;
	int sec_end = 0;

	if (array == NULL || size == 0 || array[s] > value)
	{
		return (-1);
	}

	while (sec_end < (int)size)
	{
		if (array[sec_end] < value)
		{
			printf("Value checked array[%d] = [%d]\n", sec_end, array[sec_end]);

			s = sec_end;
			sec_end += j;
		}
		else
		{
			break;
		}
	}

	printf("Value found between indexes [%d] and [%d]\n", s, sec_end);

	if (sec_end > (int)size - 1)
	{
		sec_end = size - 1;
	}

	while (s <= sec_end)
	{
		printf("Value checked array[%d] = [%d]\n", s, array[s]);
		if (array[s] == value)
		{
			return (s);
		}
		s++;
	}

	return (-1);
}
