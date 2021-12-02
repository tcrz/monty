#include "monty.h"

/**
 * mod_func - handles the mod instruction
 * @h: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */
void mod_func(stack_t **h, unsigned int line_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*h, 0);
	stack_t *node_1 = get_dnodeint_at_index(*h, 1);

	if (dlistint_len(*h) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(h, 0);
	delete_dnodeint_at_index(h, 0);
	node = add_dnodeint(h, mod);
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}