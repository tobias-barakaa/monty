#include "monty.h"

void _mod(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *elem = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	elem = (*stack)->next;
	total = elem->n % (*stack)->n;
	free(*stack);
	*stack = elem;
	(*stack)->n = total;
}
