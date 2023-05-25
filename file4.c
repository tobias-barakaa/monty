#include "monty.h"

/**
 * mod - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void mod(stack_t **stack, unsigned int line_number)
{
	unsigned int module;
	(void)line_number;

	if ((*stack == NULL) || ((*stack)->next == NULL && (*stack)->prev == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	module = (*stack)->next->n % (*stack)->n;

	pop(stack, 0);
	pop(stack, 0);
	push(stack, module);
}

/**
 * pchar - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	letter = (*stack)->n;

	if (letter >= 0 && letter <= 255)
	{
		putchar(letter);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range,\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - entry point
 * @stack: stack_t variable
 * @line_number: unsigned int variable
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	int string;
	stack_t *tmp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	while (tmp)
	{
		string = tmp->n;
		if (string > 0 && string <= 127)
			putchar(string);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}
