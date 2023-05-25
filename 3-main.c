#include "monty.h"

/**
 * sub - substract the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int res, i;
	stack_t *tmp = *stack;

	for (i = 0; tmp != NULL; i++)
		tmp = tmp->next;
	if (i < 2 || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	res = tmp->n - (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}

/**
 * _div - divide the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	res = tmp->n / (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}

/**
 * _mul - multiplicate the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	res = (*stack)->n * tmp->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}
/**
 * _mod - get the module of the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int res;
	stack_t *tmp = *stack;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	res = tmp->n % (*stack)->n;
	free(*stack);
	*stack = tmp;
	(*stack)->n = res;
}

/**
 * pchar - Print ascii character.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
