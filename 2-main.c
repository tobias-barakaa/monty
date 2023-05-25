#include "monty.h"
/**
 * pall - Print All stack
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)line_number;
	if (!stack || !(*stack))
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - Print only element of stack
 * @stack: Addres of first element in strack
 * @line_number: Number of actual line
 */
void pint(stack_t **stack, unsigned int line_number)
{

	if ((!stack) || (!(*stack)))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - Delete a stack element
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack) || (!stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
/**
 * swap - swap the first two elements in the list
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int aux;
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	aux = (*stack)->n;
	(*stack)->n = tmp->n;
	tmp->n = aux;
}
/**
 * add - Sum of the first two elements
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	sum = (*stack)->n + tmp->n;
	free(*stack);
	(*stack) = tmp;
	(*stack)->n = sum;
}
