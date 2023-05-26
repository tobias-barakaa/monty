#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *elem = (*stack);

	(void)line_number;
	if (!stack || !(*stack))
		goto exi;

	while (elem)
	{
		if (elem->n == 0)
			goto exi;
		if (elem->n < 32 || elem->n > 126)
			goto exi;
		printf("%c", elem->n);
		elem = elem->next;
	}
exi: printf("\n");
}
