#include "monshell.h"
/**
 * create_node - create new node
 * @n: num val
 * Return:node
 */
stack_t *create_node(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

