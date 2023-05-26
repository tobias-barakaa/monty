#include "monty.h"



/**
 * find_file - Mange of the path for know the function for use.
 * @stack: Head of the double linked list.
 * @path: The file for execute him commands.
 * Return: Nothing.
 */
void find_file(char *path, stack_t **stack)
{
        FILE *file;
        char *command;
        size_t n;
        unsigned int line_number = 1;
        char *buffer = NULL;

        if (!path)
        {
                fprintf(stderr, "Error: Can't open file %s\n", path);
                exit(EXIT_FAILURE);
        }

        file = fopen(path, "r");
        if (!file)
        {
                fprintf(stderr, "Error: Can't open file %s\n", path);
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
        /* free(buffer); */
        /* fclose(file); */
        exit(EXIT_SUCCESS);
}
