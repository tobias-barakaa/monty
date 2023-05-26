#include "monty.h"

void find_file(char *source, stack_t **stack)
{
	FILE *open_file;
	char *elem;
	size_t n;
	unsigned int line_number = 1;
	char *buffer = NULL;

	if (!source) 
	{
		fprintf(stderr, "Error: Can't open  %s\n", source);
		exit(EXIT_FAILURE);
	}

	open_file = fopen(source, "r");
	if (!open_file)
	{
		fprintf(stderr, "Error: Can't open open_file %s\n", source);
		exit(EXIT_FAILURE);
	}
	header.open_file = open_file;
	while (getline(&buffer, &n, open_file) != -1)
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
