#include "main.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[256];
    unsigned int line_number = 0;

    while (fgets(line, sizeof(line), file))
    {
        line_number++;

        // Tokenize the line
        char *opcode = strtok(line, " \t\n");
        char *argument = strtok(NULL, " \t\n");

        if (!opcode)
            continue; // Empty line, skip to the next iteration

        if (strcmp(opcode, "push") == 0)
        {
            if (!argument || !isdigit(*argument))
            {
                printf("L%d: usage: push integer\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }

            int value = atoi(argument);
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack);
        }
        else
        {
            printf("L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
