#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = NULL;

	(void)line_number;
	if (!stack || !(*stack))
		return;
	elem = *stack;
	while (elem)
	{
		printf("%d\n", elem->n);
		elem = elem->next;
	}
}
