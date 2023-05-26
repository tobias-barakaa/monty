#include "monty.h"

void add(stack_t **stack, unsigned int line_number)
{
	int total;
	stack_t *elem;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	elem = (*stack)->next;
	total = (*stack)->n + elem->n;
	free(*stack);
	(*stack) = elem;
	(*stack)->n = total;
}

