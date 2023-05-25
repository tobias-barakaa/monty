#include "monty.h"
/**
 * _verify - verify that token is a number converts token to integer
 * @stack: pointer to head
 * @line_number: current line
 */
void _verify(stack_t **stack, unsigned int line_number)
{
	if (check_int(global.token) == 0)
		global.num = atoi(global.token);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		free(global.content);
		fclose(global.file);
		exit(EXIT_FAILURE);
	}
}
/**
 * check_int - checks that operand is a number
 * @num: token value
 * Return: 0 if successful
 */
int check_int(char *num)
{
	int i = 0;

	if (!num)
		return (1);

	if (num[i] == 45)
		i++;
	while (num[i])
	{
		if (num[i] < 48 || num[i] > 57)
			return (-1);
		i++;
	}
	return (0);
}
