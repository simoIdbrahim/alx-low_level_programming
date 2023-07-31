#include "lists.h"

/**
 * get_nodeint_at_index - main function
 * @head: first node
 * @index: get index node
 *
 * Return: pointer node || NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *node = head;

	while (node && i < index)
	{
		node = node->next;
		i++;
	}

	if (node)
		return (node);

	return (NULL);
}
