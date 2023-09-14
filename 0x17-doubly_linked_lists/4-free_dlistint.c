#include "lists.h"

/**
 * free_dlistint - main function
 * @head: arg one
 * Return: void
 **/

void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	{
		return;
	}

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
