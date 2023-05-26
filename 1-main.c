#include "monty.h"

void find_file(char *source, stack_t **stack)
{
        FILE *file;
        char *command;
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
                command = strtok(buffer, " \n\t\r");
                if (command)
                        function_select(stack, line_number, command);
                line_number++;
        }
        atexit(free_all);
        exit(EXIT_SUCCESS);
}
