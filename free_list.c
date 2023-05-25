#include "monshell.h"

/**
 * free_mem - Free a list.
 * @stack: node head.
 * Return: (0).
 */
void free_mem(stack_t *stack)
{
	stack_t *moment = NULL;

	moment = stack;

	if (moment != NULL)
	{
		free_mem(moment->next);
		free(moment);
	}
}
