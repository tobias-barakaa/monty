#include "monty.h"

void find_file(char *source, stack_t **stack)
{
	FILE *file;
	char *elem;
	size_t n;
	unsigned int line_number = 1;
	char *buffer = NULL;

	if (!source)
	{
		fprintf(stderr, "Error: Can't open file %s\n", source);
		exit(EXIT_FAILURE);
	}

	file = fopen(source, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", source);
		exit(EXIT_FAILURE);
	}
	header.file = file;
	while (getline(&buffer, &n, file) != -1)
	{
		header.buffer = buffer;
		elem = strtok(buffer, " \n\t\r");
		if (elem)
			function_select(stack, line_number, elem);
		line_number++;
	}
	atexit(free_all);
	exit(EXIT_SUCCESS);
}
