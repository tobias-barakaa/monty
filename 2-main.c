#include "main.h"

void pall(stack_t **snode)
{
    stack_t *current = *snode;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

