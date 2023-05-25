#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globalinfo_s - a structure of info that will be accessable globally
 * @fp: a file pointer to our open stream
 * @num: for a push operation the num to be pushed
 * @buffer: the line buffer from get line
 */
typedef struct globalinfo_s
{
	FILE **fp;
	int num;
	char **buffer;
} glbnfo;

extern glbnfo *info;

/* Error Checks and Utils*/
void file_check(FILE *fp, const char *filename);
void cmd_comp(char *cmd[], stack_t **stack,  unsigned int line_num);
void clean_up(FILE **fp, stack_t **stack, char **buffer);
/* These are all our functions in basic_funcs*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
/* These are the moving programs in moves */
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
/* These are the math functions in maths  */
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

#endif
