#include "monty.h"

int manage_error(char *value, unsigned int line_number)
{
	int iterate;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (iterate = 0; value[iterate] != '\0'; iterate++)
	{
		if (value[iterate] < 48 || value[iterate] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(value));
}
