#include "monty.h"

/**
 * push - Inizialice a node in the begin of the list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *value;
	int operator;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	value = strtok(NULL, " \n\t\r");
	operator = manage_error(value, line_number);
	new_node->n = operator;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new_node, new_node->next = NULL;
		return;
	}
	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * nop - Do nothing.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _rotl - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1;
	stack_t *tmp2;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	(void)line_number;
	tmp1 = *stack;
	tmp2 = *stack;

	while (tmp1->next != NULL)
		tmp1 = tmp1->next;

	*stack = tmp2->next;
	(*stack)->prev = tmp2->prev;

	tmp2->next = tmp1->next;
	tmp1->next = tmp2;
	tmp2->prev = tmp1;
}

/**
 * _rotr - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *final, *b_final;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	(void)line_number;
	tmp = *stack;
	final = *stack;

	while (final->next != NULL)
		final = final->next;

	b_final = final->prev;
	b_final->next = final->next;

	final->next = tmp;
	final->prev = tmp->prev;
	tmp->prev = final;

	*stack = final;
}
