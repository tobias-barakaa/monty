#include "monty.h"

/**
 * s_push - pushes an element to the stack (or queue)
 * @stack: head
 * @line_number: current line number
 */
void s_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	_verify(stack, line_number);
	if (global.token)
	{
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fputs("Error: malloc failed\n", stderr);
			exit(EXIT_FAILURE);
		}
		new->n = global.num, new->next = NULL;
		new->prev = NULL;
		if (*stack)
		{
			if (global.flag == 1)
			{
				new->next = *stack;
				(*stack)->prev = new;
				*stack = new;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = new, new->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = new;
	}
	else
	{
		free(global.content), fclose(global.file);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * s_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: head
 * @line_number: current line number
 */
void s_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
		return;
	if (line_number)
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}
