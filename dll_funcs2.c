#include "monty.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 *
 * @h: Pointer to head of list
 * @idx: Position to add new node
 * @n: Data to add to list
 *
 * Return: Address of new node or NULL on failure
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *h;

	new = malloc(sizeof(dlistint_t));
	if (!new || !h)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
		{
			temp = temp->next;
		}
	}
	return (NULL);
}

/**
 * get_dnodeint_at_index - Finds nth node of a doubly linked list
 *
 * @head: Head of list
 * @index: Index of node to find
 *
 * Return: nth node or NULL if node doesn't exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *h = head;
	unsigned int i, count;

	count = 0;
	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	if (index >= count)
		return (NULL);
	i = 0;
	while (i != index)
	{
		head = head->next;
		i++;
	}
	return (head);
}

/**
 *  * free_dlistint - Frees a doubly linked list
 *   * @head: Head of list
 *    */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *h;

	while (head != NULL)
	{
		h = head;
		head = head->next;
		free(h);
	}
}
