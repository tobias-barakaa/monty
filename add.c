[200~#include "monshell.h"

/**
 *  * int_add - adds more than two ints
 *   * @stack: Stack parametere
 *    * @line_number: lines
 *     */
void int_add(stack_t **stack, unsigned int line_number)
{
		stack_t *moment = NULL;
			int result = 0;

				if (!*stack || !(*stack)->next)
						{
									fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
											free_stack(stack);
													exit(EXIT_FAILURE);
														}
					moment = *stack;
						result = moment->n + moment->next->n;
							moment->next->n = result;
								remove_top(stack, line_number);
}

