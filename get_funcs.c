#include "monty.h"

/**
 * get_func - selects correct function to perform operation
 * @str: func keyword
 * Return: pointer to correct function based on keyword
 */
void (*get_func(char *str))(stack_t **, unsigned int)
{
	int i;

	instruction_t ops_func[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"nop", nop_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{NULL, NULL}};

	i = 0;
	while (ops_func[i].opcode)
	{
		if (strcmp(ops_func[i].opcode, str) == 0)
			return (ops_func[i].f);
		i++;
	}

	return (NULL);
}
