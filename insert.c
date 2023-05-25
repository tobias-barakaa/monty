#include "monshell.h"
int value;

/**
 * insert - force insert in
 * @stack:  param
 * @line_number:val
 */
void insert(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	(void)line_number;

	node = create_node(value);

	node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = node;
	*stack = node;
}
