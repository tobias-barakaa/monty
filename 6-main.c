#include "monty.h"
global_t header;

void start_stack(stack_t **stack)
{
	*stack = NULL;
	header.first = stack;
}

void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(header.first);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(header.buffer);
	fclose(header.file);
}

int main(int argc, char *argv[])
{
	stack_t *stack;

	start_stack(&stack);
	if (argc == 2)
	{
		find_file(argv[1], &stack);
	}
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
