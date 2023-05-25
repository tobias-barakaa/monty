#include "monshell.h"

/**
 * print_elem - prints elem
 * @stack: param
 * @n: value
 * Return:0
 */
void print_elem(stack_t **stack, unsigned int n)
{
	stack_t *moment = NULL;
	(void)n;

	moment = *stack;

	while (moment != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", moment->n);
		moment = moment->next;
	}
}
