#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *elem;

	if (!(*stack) || (!stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	elem = *stack;
	*stack = (*stack)->next;
	free(elem);
}
