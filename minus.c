#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	int status, iterate;
	stack_t *elem = *stack;

	for (iterate = 0; elem != NULL; iterate++)
		elem = elem->next;
	if (iterate < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	elem = (*stack)->next;
	status = elem->n - (*stack)->n;
	free(*stack);
	*stack = elem;
	(*stack)->n = status;
}
