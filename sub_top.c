#include "monshell.h"

/**
 * delete_el - substract from the top 
 * @stack: Stack arguments
 * @line_number: line
 */
void delete_el(stack_t **stack, unsigned int line_number)
{
	stack_t *moment = *stack;
	int delete = 0;

	if (!moment || !moment->next)
	{
		fprintf(stderr, "L%d: can't delete, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	delete = moment->next->n - moment->n;
	moment->next->n = delete;
	remove_top(stack, line_number);
}
