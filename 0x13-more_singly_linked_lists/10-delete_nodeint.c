#include "lists.h"

/**
 * delete_nodeint_at_index - main function
 * @head: argaddress pointer firts el
 * @index: position index delete
 *
 * Return: 1 || -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node = *head;
	listint_t *curr = NULL;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(node);
		return (1);
	}

	for (int i = 0; i < index - 1; i++)
	{
		if (!node || !(node->next))
			return (-1);
		node = node->next;
	}

	curr = node->next;
	node->next = curr->next;
	free(curr);

	return (1);
}


