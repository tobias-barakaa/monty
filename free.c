#include "monty.h"

/**
 * free_stack - free list
 * @stack: pointer to head
 */
void free_stack(stack_t **stack)
{
	stack_t *del = *stack;

	while (*stack)
	{
		del = del->next;
		free(*stack);
		*stack = del;
	}
}
