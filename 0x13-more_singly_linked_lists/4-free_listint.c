#include "lists.h"

/**
 * free_listint - main function
 * @head: pointer the first element
 *
 * return: void
 */

void free_listint(listint_t *head)
{
	listint_t *el;

	while (head)
	{
		el = head;
		head = head->next;
		free(el);
	}
}
