#include "lists.h"

/**
 * listint_len - main function
 * @h: arg
 *
 * Return: size
 */

size_t listint_len(const listint_t *h)
{
	size_t number = 0;

	while (h)
	{
		number++;
		h = h->next;
	}

	return (number);
}
