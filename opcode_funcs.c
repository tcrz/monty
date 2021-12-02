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

/**
 * pint_func - prints the element on top
 * @h: pointer to stack_t object
 * @line_number: line number in file
 */
void pint_func(stack_t **h, unsigned int line_number)
{
	stack_t *head = *h;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * swap_handler - handles the swap instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void swap_func(stack_t **h, unsigned int line_number)
{
	stack_t *temp = *h, *node = NULL;
	int num;

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*h, 0);
	num = temp->n;
	delete_dnodeint_at_index(h, 0);
	node = insert_dnodeint_at_index(h, 1, num);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
