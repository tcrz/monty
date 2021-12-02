#include "monty.h"

/**
 * push_func - pushes element onto the stack
 * @h: pointer to stack_t object
 * @line_number: line number in file
 */

void push_func(stack_t **h, unsigned int line_number)
{
	stack_t *newnode;
	int i;

	if (argtoint == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argtoint[i])
	{
		if (isdigit(argtoint[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	line_number = line_number;
	newnode->n = atoi(argtoint);

	if (!*h)
		*h = newnode;
	else
	{
		(*h)->prev = newnode;
		newnode->next = *h;
		*h = newnode;
	}
}

/**
 * pall_func - pushes element onto the stack
 * @h: pointer to stack_t object
 * @line_number: line number in file
 */

void pall_func(stack_t **h, unsigned int line_number)
{
	(void)line_number;
	if (!*h)
		return;

	while (*h)
	{
		fprintf(stdout, "%d\n", (*h)->n);
		(*h) = (*h)->next;
	}
}

/**
 * nop_func - pushes element onto the stack
 * @h: pointer to stack_t object
 * @line_number: line number in file
 */
void nop_func(stack_t **h, unsigned int line_number)
{
	(void)*h;
	(void)line_number;
}