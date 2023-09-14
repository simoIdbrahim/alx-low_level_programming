#include "lists.h"

/**
 * dlistint_len - main function
 * @h: arg one
 * Return: num of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int cou = 0;

	if (h == NULL)
		return (cou);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		cou++;
		h = h->next;
	}

	return (cou);
}
