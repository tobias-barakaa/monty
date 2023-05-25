#include "monshell.h"


/**
 * error_hand - error capture while push
 * @open_file: description file
 * @exe: line-buffer
 * @stack: stack/q
 * @elem:param ct
 */
void error_hand(FILE *open_file, char *exe, stack_t *stack, int elem)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n", elem);
	fclose(open_file);
	free(exe);
	free_mem(stack);
	exit(EXIT_FAILURE);
}


/**
 * error - Error handler
 * @open_file: file
 * @exe: argument
 * @stack: stack
 * @elem:num co
 * @num: num
 */
void error(FILE *open_file, char *exe, stack_t *stack, char *elem, int num)
{
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", num, elem);
	fclose(open_file);
	free(exe);
	free_mem(stack);
	exit(EXIT_FAILURE);
}
