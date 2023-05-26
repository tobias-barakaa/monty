#include "monty.h"
/**
 * function_select - func to use
 * @stack: Head param
 * @line_number:line
 * @str: The str .
 * Return: 0.
 */
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
        int loop;

        if (str[0] == '#')
                (return);

        for (loop = 0; functions[loop].opcode != NULL; loop++)
        {
                if (strcmp(functions[loop].opcode, str) == 0)
                {
                        functions[loop].f(stack, line_number);
                        return;
                }
        }
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
        exit(EXIT_FAILURE);
}

/**
 * find_file - function to execute
 * @stack: stack
 * @source: source
 * Return: (0).
 */
void find_file(char *source, stack_t **stack)
{
        FILE *open_file;
        char *argument;
        size_t n;
        unsigned int line_number = 1;
        char *data = NULL;

        if (!source)
        {
                fprintf(stderr, "Error: Can't open open_file %s\n", source);
                exit(EXIT_FAILURE);
        }

        open_file = fopen(source, "r");
        if (!open_file)
        {
                fprintf(stderr, "Error: Can't open open_file %s\n", source);
                exit(EXIT_FAILURE);
        }
        header.open_file = open_file;
        while (getline(&data, &n, open_file) != -1)
        {
                header.data = data;
                argument = strtok(data, " \n\t\r");
                if (argument)
                        function_select(stack, line_number, argument);
                line_number++;
        }
        atexit(free_all);
        exit(EXIT_SUCCESS);
}
