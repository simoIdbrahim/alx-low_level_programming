#include <math.h>
#include "search_algos.h"

/**
 * jump_list - function one
 * @list: arge one
 * @size: arge two
 * @value: arge three
 * Return: NULL
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *hold = list;
	int indx, j;

	if (list == NULL || size == 0)
	{
		return (NULL);
	}

	j = sqrt(size);

	while (hold->next != NULL)
	{
		list = hold;

		for (indx = 0; indx < j; indx++)
		{
			hold = hold->next;
			if (hold->next == NULL)
			{
				break;
			}
		}

		printf("Value checked at index [%lu] = [%d]\n", hold->index, hold->n);

		if (hold->n >= value)
		{
			break;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]\n", list->index,
	       hold->index);

	while (list != NULL && list != hold->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (list->n == value)
		{
			return (list);
		}
		list = list->next;
	}

	return (NULL);
}
