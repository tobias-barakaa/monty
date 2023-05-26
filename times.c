#include "monty.h"

void _mul(stack_t **stack, unsigned int line_number)
{
	int status;
	stack_t *var_line = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	var_line = (*stack)->next;
	status = (*stack)->n * var_line->n;
	free(*stack);
	*stack = var_line;
	(*stack)->n = status;
}
