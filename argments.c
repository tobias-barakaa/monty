#include "monshell.h"

/**
 * env_com - Read file
 * @argv: param
 * Return: Nothing
 */
void env_com(char *argv)
{
	int elem = 0, output = 0;
	size_t bufsize = 0;
	char *param = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.open_file = fopen(argv, "r");
	if (global.open_file)
	{
		while (getline(&global.exe, &bufsize, global.open_file) != -1)
		{
			elem++;
			param = strtok(global.exe, " \n\t\r");
			if (param == NULL)
			{
				free(param);
				continue;
			}
			else if (*param == '#')
            {
				continue;
            }
			item = strtok(NULL, " \n\t\r");
			output = get_opc(&stack, param, item, elem);
			if (output == 1)
				push_error(global.open_file, global.exe, stack, elem);
			else if (output == 2)
				ins_error(global.open_file, global.exe, stack, param, elem);
		}
		free(global.exe);
		(stack);
		fclose(global.open_file);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}

