#include "monshell.h"

/**
 * interchange - interchanges two nodes
 * @stack: Stack arguments 
 * @line_number:elmt line
 */
void interchange(stack_t **stack, unsigned int line_number)
{
	stack_t *moment = *stack;
	int duplic = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	duplic = moment->n;
	moment->n = moment->next->n;
	moment->next->n = duplic;
}
