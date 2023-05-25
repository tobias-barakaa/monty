#include "monty.h"

/**
 * _pop - removes top node of stack
 * @stack: pointer to top node
 * @line_number: line number count for given file
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *mover;

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clean_up(info->fp, stack, info->buffer);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
		free((*stack));
	else
	{
		mover = (*stack);
		(*stack) = (*stack)->prev;
		free(mover);
	}
}

/**
 * _swap - a function to swap the top node and second node in a stack
 * @stack: a pointer to the top of our stack
 * @line_number: the line number of the command that called swap
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *prev;

	if (stack == NULL || (*stack) == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clean_up(info->fp, stack, info->buffer);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	prev = (*stack)->prev;
	(*stack)->n = prev->n;
	prev->n = tmp;
}
