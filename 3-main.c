#include "monty.h"

/**
 * sub - substract the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int res, i;
	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; i++)
		tmp = tmp->next;
	if (i < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	res = tmp->n - (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}
