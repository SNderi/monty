#include "monty.h"

/**
 * dlistint_len - Counts the number of elements in a linked list
 *
 * @h: Pointer to head of list
 * Return: Number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * print_dlistint - Prints all elements of a doubly linked list
 *
 * @h: Pointer to head of list
 * Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		printf("%d\n", h->n);
		h = h->next;
											}
	return (count);
}

/**
 * add_dnodeint - Adds a new node at the beginning of a doubly linked list
 *
 * @head: Pointer to head of list
 * @n: Data to store in list
 *
 * Return: Address of the new element or NULL on failure
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 *
 * @head: Pointer to head of list
 * @n: Data to add to list
 *
 * Return: Address of new element or NULL on failure
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last = *head;
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (*head);
	}

	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (*head);
}

/**
 * delete_dnodeint_at_index - Deletes the node at a given position
 *
 * @head: Pointer to list's head
 * @index: Position to delete
 * Return: 1 on success -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (*head == NULL || dlistint_len(temp) < index + 1)
		return (-1);

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
																}

	while (i < index)
	{
		temp = temp->next;
		i++;
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}
