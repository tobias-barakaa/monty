#define _GNU_SOURCE
#include "monty.h"
global_t global;

/**
 * main - entry point of program
 * @argc: argumemt count
 * @argv: argument vector
 * Return: 0 (success)
 */
int main(int argc, char *argv[])
{
	int nbytes = 0;
	size_t nsize = 0;
	unsigned int count = 1;
	stack_t *stack = NULL;

	global.flag = 1;
	global.content = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nbytes = getline(&global.content, &nsize, global.file)) != EOF)
	{
		add_null(global.content);
		if (global.content[0] != 35)
		{
			global.token = strtok(global.content, " \t\n");
			global.code = global.token;
			if (global.code != NULL)
			{
				global.token = strtok(NULL, " \t\n");
				funct(global.code)(&stack, count);
			}
			count++;
		}
	}
	free_stack(&stack);
	free(global.content);
	fclose(global.file);
	return (0);
}
