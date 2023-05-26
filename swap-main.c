#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *elem;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	elem = (*stack)->next;
	data = (*stack)->n;
	(*stack)->n = elem->n;
	elem->n = data;
}
