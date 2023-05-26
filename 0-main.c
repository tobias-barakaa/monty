#include "monty.h"

void function_select(stack_t **stack, unsigned int line_number, char *elem)
{
	instruction_t functions[] = {
		{"pint", pint}, {"pall", pall}, {"push", push},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", _rotl}, {"rotr", _rotr},
		{NULL, NULL}
	};
	int iterate;

	if (elem[0] == '#')
		return;

	for (iterate = 0; functions[iterate].opcode != NULL; iterate++)
	{
		if (strcmp(functions[iterate].opcode, elem) == 0)
		{
			functions[iterate].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, elem);
	exit(EXIT_FAILURE);
}
