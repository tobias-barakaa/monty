#include "monshell.h"

/**
 * get_opc - function to handle the opcode
 * @stack: is a stack or queue
 * @arg: is a parameter
 * @item: is a parameter
 * @count: is a line command
 * Return: nothing
 */
int get_opc(stack_t **stack, char *arg, char *item, int count)
{
	int i = 0;
    
    instruction_t op[] = {
		{"push", insert},
		{"pall", print_elem},
		{"pint", print_top},
		{"pop", remove_top},
		{"swap", interchange},
		{"add", int_add},
		{"sub", delete_el},
		{"nop", nothing},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(arg, op[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (num_elem(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			op[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
		return (2);

	return (0);
}


