#include "monty.h"

void function_select(stack_t **stack, unsigned int line_number, char *str)
{
        instruction_t functions[] = {
                {"pint", pint}, {"pall", pall}, {"push", push},
                {"pop", pop}, {"swap", swap}, {"add", add},
                {"nop", nop}, {"sub", sub}, {"div", _div},
                {"mul", _mul}, {"mod", _mod}, {"pchar", pchar},
                {"pstr", pstr}, {"rotl", _rotl}, {"rotr", _rotr},
                {NULL, NULL}
        };
        int j;

        if (str[0] == '#')
                return;

        for (j = 0; functions[j].opcode != NULL; j++)
        {
                if (strcmp(functions[j].opcode, str) == 0)
                {
                        functions[j].f(stack, line_number);
                        return;
                }
        }
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
        exit(EXIT_FAILURE);
}

