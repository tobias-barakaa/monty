#include "monty.h"

/**
 * cmd_comp - compare arg to avaiable op codes
 * @line_num: line_number counter
 * @cmd: parsed getline for opcode and args
 * @stack: a double pointer to the top of the stack
 * Return: Nothing
 */

void cmd_comp(char *cmd[], stack_t **stack, unsigned int line_num)
{
	int i = 0;
	instruction_t opcodes[] = {
		{"pall", _pall}, {"push", _push}, {"pint", _pint},
		{"pop", _pop}, {"add", _add}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"nop", _nop}, {"mod", _mod},
		{"swap", _swap}, {NULL, NULL}
	};
	
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, cmd[0]) == 0)
		{
			if (strcmp(opcodes[i].opcode, "push") == 0)
			{
				if (cmd[1] == NULL || isdigit(cmd[1][0]) == 0)
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_num);
					clean_up(info->fp, stack, info->buffer);
					exit(EXIT_FAILURE);
				}
				if (isdigit(cmd[1][0]) != 0)
				{
					info->num = atoi(cmd[1]);
					opcodes[i].f(stack, line_num);
					return;
				}
			}
			else
			{
				opcodes[i].f(stack, line_num);
				return;
			}
		}
	}
	if (opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, cmd[0]);
		clean_up(info->fp, stack, info->buffer);
		exit(EXIT_FAILURE);
	}
}
