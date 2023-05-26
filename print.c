#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *num = NULL;

	(void)line_number;
	if (!stack || !(*stack))
		return;
	num = *stack;
	while (num)
	{
		printf("%d\n", num->n);
		num = num->next;
	}
}
