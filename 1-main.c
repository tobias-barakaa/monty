#include "monty.h"

/**
 * _push - a function to add nodes to stack
 * @stack: a pointer to the top of stack
 * @line_number: the line number for the opcode that call this
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *oldtop;
	stack_t *new_node = malloc(sizeof(stack_t));
	(void) line_number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_up(info->fp, stack, info->buffer);
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	new_node->n = info->num;
	if (*stack == NULL)
		new_node->prev = NULL;
	else
	{
		oldtop = *stack;
		new_node->prev = oldtop;
		oldtop->next = new_node;
	}
	*stack = new_node;
}

/**
 * _pall - a function to print all values in the stack
 * @stack: a pointer to stack
 * @line_number: the line number for the opcode that called pall
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mover = *stack;
	(void) line_number;

	while (mover != NULL)
	{
		printf("%d\n", mover->n);
		mover = mover->prev;
	}
}

/**
 * _pint - a fuction to print the top node's n value
 * @stack: a pointer to the top of our stack
 * @line_number: our line number for this command
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clean_up(info->fp, stack, info->buffer);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * _nop - opcode function that does nothing
 * @stack: top pointer of stack
 * @line_number: line count from given file
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void) **stack;
	(void) line_number;
}
