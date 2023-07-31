#include "lists.h"

/**
 * pop_listint - main function
 * @head: address arg
 *
 * Return: val node
 */

int pop_listint(listint_t **head)
{
	listint_t *no;
	int number;

	if (!head || !*head)
		return (0);

	number = (*head)->n;
	no = (*head)->next;
	free(*head);
	*head = no;

	return (number);
}

