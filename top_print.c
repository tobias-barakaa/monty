#include "monshell.h"

/**
 * print_top - top of stack print
 * @stack: linked lines
 * @line_number: Number of the line
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

