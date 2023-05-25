#include "monshell.h"

/**
 * remove_top - subtracts element on tp
 * @stack: Stack parametree
 * @line_number: line elem
 */
void remove_top(stack_t **stack, unsigned int line_number)
{
	stack_t *moment = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	moment = *stack;

	*stack = moment->next;
	if (moment->next != NULL)
		moment->next->prev = moment->prev;
	free(moment);
}
