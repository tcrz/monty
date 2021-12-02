#include "monty.h"


/**
 * swap_func - handles the swap instruction
 * @h: double pointer to the stack to push to
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

	(void)line_number;
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

/**
 * add_func - handles the add instruction
 * @h: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void add_func(stack_t **h, unsigned int line_number)
{
	int sum = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*h, 0);
	stack_t *node_1 = get_dnodeint_at_index(*h, 1);

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = node_0->n + node_1->n;
	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	node = add_dnodeint(h, sum);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * sub_func - handles the sub instruction
 * @h: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void sub_func(stack_t **h, unsigned int line_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*h, 0);
	stack_t *node_1 = get_dnodeint_at_index(*h, 1);

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	node = add_dnodeint(h, sub);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * div_func - handles the div instruction
 * @h: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void div_func(stack_t **h, unsigned int line_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*h, 0);
	stack_t *node_1 = get_dnodeint_at_index(*h, 1);

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	node = add_dnodeint(h, div);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_func - handles the mul instruction
 * @h: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mul_func(stack_t **h, unsigned int line_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*h, 0);
	stack_t *node_1 = get_dnodeint_at_index(*h, 1);

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	node = add_dnodeint(h, mul);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
