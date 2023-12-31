#include "lists.h"

/**
 * print_dlistint - main function
 * @h: first arg
 * Return: num nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int cou = 0;

	if (h == NULL)
		return (cou);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		cou++;
		h = h->next;
	}

	return (cou);
}
