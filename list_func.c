#include "monty.h"

/**
 * dlistint_len - returns the number of nodes in a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const stack_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * delete_dnodeint_at_index - deltes a node in a doubly linked list
 * at a given index
 * @head: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

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
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * get_dnodeint_at_index - gets the nth node of a doubly linked list
 * @head: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * in a doubly linked list
 * @h: double pointer to the list
 * @idx: index of the node to insert
 * @n: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	unsigned int i;
	stack_t *new;
	stack_t *temp = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(h, n));
			new = malloc(sizeof(stack_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}
