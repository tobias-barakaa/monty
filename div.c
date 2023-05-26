#include "monty.h"

void _div(stack_t **stack, unsigned int line_number)
{
	int status;
	stack_t *elems = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	elems = (*stack)->next;
	status = elems->n / (*stack)->n;
	free(*stack);
	*stack = elems;
	(*stack)->n = status;
}
