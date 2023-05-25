#include "monty.h"

/**
 * freestack - enrty point
 * @stack: stack_t variable
*/

void freestack(stack_t **stack)
{
	stack_t *tmp;

	while ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

/**
 * _isdigit - function that checks for a digit (0 through 9)..
 * @c: digit
 * Return:Returns 1 when c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
