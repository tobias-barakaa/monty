#include "main.h"

void push(stack_t **node, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *node;

    if (*node)
        (*node)->prev = new_node;

    *node = new_node;
}
