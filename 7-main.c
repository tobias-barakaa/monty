#include "monty.h"

/**
 * manage_error - mange error for push function.
 * @value: The value for evaluate for push.
 * @line_number: Execution line.
 * Return: The value in a integer.
 */
int manage_error(char *value, unsigned int line_number)
{
	int j;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (j = 0; value[j] != '\0'; j++)
	{
		if (value[j] < 48 || value[j] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(value));
}
