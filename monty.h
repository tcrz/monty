#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern char *argtoint;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);


void (*get_func(char *str))(stack_t **, unsigned int);


void push_func(stack_t **h, unsigned int line_number);
void pall_func(stack_t **h, unsigned int line_number);
void nop_func(stack_t **h, unsigned int line_number);
void pint_func(stack_t **h, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **h, unsigned int line_number);


#endif
