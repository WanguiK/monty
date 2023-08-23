#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * _push-  pushes an element to the stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int value = 0;
	int i;
	char value_str[100];

	for (i = 0; value_str[i] != 0; i++)
	{
		if (!_isdigit(value_str[i]))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(value_str);

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = value;
	top->next = *stack;
	top->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = top;
	}
	*stack = top;
}
/**
 *_isdigit- checks for digits from 0 to 9
 *@c: character to print
 *Return: 1 if character is a digit and 0 for otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
	return (1);
	}
	else
	{
	return (0);
	}
}
/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
