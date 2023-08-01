#include "lists.h"

/**
 * free_listint_safe - main function
 * @h: arg
 * Return: number of elements
 */

size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int dif;
	listint_t *node;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		dif = *h - (*h)->next;
		if (dif > 0)
		{
			node = (*h)->next;
			free(*h);
			*h = node;
			length++;
		}
		else
		{
			free(*h);
			*h = NULL;
			length++;
			break;
		}
	}

	*h = NULL;

	return (length);
}

