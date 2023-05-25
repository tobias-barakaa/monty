#include "monshell.h"

/**
 * free_stack - frees & closes
 * @stack: param
 */
void free_stack(stack_t **stack)
{
	stack_t *moment = *stack;

	for (; moment; moment = *stack)
	{
		*stack = (*stack)->next;
		free(moment);
	}
	fclose(global.open_file);
	free(global.exe);
}
