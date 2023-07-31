#include "lists.h"

/**
 * insert_nodeint_at_index - main function
 * @head: arg address pointer
 * @idx: arg index
 * @n: nn val of new node
 *
 * Return: node address || NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *nw = malloc(sizeof(listint_t));
	listint_t *node = *head;

	if (!nw || !head)
		return (NULL);

	nw->n = n;
	nw->next = NULL;

	if (idx == 0)
	{
		nw->next = *head;
		*head = nw;
		return (nw);
	}

	for (i = 0; node && i < idx; i++)
	{
		if (i == idx - 1)
		{
			nw->next = node->next;
			node->next = nw;
			return (nw);
		}
		else
			node = node->next;
	}

	return (NULL);
}

