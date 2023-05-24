#include "main.h"

void push(char *argument);
void pall(void);

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;

        /* Trim leading and trailing whitespace */
        char *trimmed_line = strtok(line, " \t\n");

        /* Ignore empty lines and comments */
        if (trimmed_line == NULL || trimmed_line[0] == '#')
            continue;

        /* Tokenize the line to separate opcode and argument */
        char *opcode = strtok(trimmed_line, " ");
        char *argument = strtok(NULL, " ");

        /* Execute the opcode instruction */
        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(argument);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall();
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
