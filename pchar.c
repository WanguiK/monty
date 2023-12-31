#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar('\n');
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cur = *stack;
	(void)line_number;

	while (cur != NULL && cur->n != 0 && cur->n >= 0 && cur->n <= 127)
	{
		putchar(cur->n);
		cur = cur->next;
	}
	putchar('\n');
}
/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;
	int aux = 0;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	aux = last->n;
	while (last->next)
	{
		last = last->next;
		last->prev->n = last->n;
	}
	last->n = aux;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
	{
		current = current->next;
	}
	last = current;
	current = *stack;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	current->prev->next = NULL;
	last->prev = NULL;
}
