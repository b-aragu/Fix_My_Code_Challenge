#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head, *tmp;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	saved_head = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(saved_head);

		if (*head != NULL)
			(*head)->prev = NULL;

		return (1);
	}

	for (i = 0; i < index && *head != NULL; i++)
		*head = (*head)->next;

	if (*head == NULL)
	{
		*head = saved_head;
		return (-1); // Index out of bounds
	}

	tmp = *head;

	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	tmp->prev->next = tmp->next;

	free(tmp);

	*head = saved_head;

	return (1);
}
