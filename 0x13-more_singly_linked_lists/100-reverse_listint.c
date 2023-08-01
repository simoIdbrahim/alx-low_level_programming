#include "lists.h"

/**
 * reverse_listint - main functio,
 * @head: address pointer of first node
 *
 * Return: address of head
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *node = NULL, *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = node;
		node = *head;
		*head = next;
	}

	*head = node;

	return (*head);
}
