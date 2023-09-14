#include "lists.h"

/**
 * sum_dlistint - main function
 * @head: arg one
 * Return: sum data
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head != NULL)
	{
		for (; head->prev != NULL; head = head->prev)
		{

		}

		for (; head != NULL; head = head->next)
		{
			sum += head->n;
		}
	}

	return (sum);
}
