#include "lists.h"

/**
 * sum_listint - main function
 * @head: arg pointer first el
 *
 * Return: sum
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *node = head;

	while (node)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}
