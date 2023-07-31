#include "lists.h"

/**
 * print_listint - main function
 * @h: poiner to node
 *
 * Return: size int.
 */

size_t print_listint(const listint_t *h)
{
	size_t number = 0;

	while (h)
	{
		printf("%d\n", h->n);
		number++;
		h = h->next;
	}

	return (number);
}

