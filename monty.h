#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @token: operand
 * @num: value to store in stack
 * @code: instruction
 * @file: pointer to monty file descriptor
 * @content: line content
 * @flag: change stack <-> queue
 * Description: carries values through the program
 */
typedef struct global_s
{
	char *code;
	char *token;
	FILE *file;
	char *content;
	int flag;
	int num;
}  global_t;

extern global_t global;

/* line_mod */
char add_null(char *line);
int line_len(char *line);

/* free_stack */
void free_stack(stack_t **stack);

/*execute_op*/
void (*funct(char *token))(stack_t **stack, unsigned int line_number);

/*tasks*/
void s_push(stack_t **stack, unsigned int line_number);
void s_pall(stack_t **stack, unsigned int line_number);
void s_pint(stack_t **stack, unsigned int line_number);
void s_pop(stack_t **stack, unsigned int line_number);
void s_swap(stack_t **stack, unsigned int line_number);
void s_add(stack_t **stack, unsigned int line_number);
void s_nop(stack_t **stack, unsigned int line_number);
void s_sub(stack_t **stack, unsigned int line_number);
void s_error(stack_t **stack, unsigned int line_number);
void s_div(stack_t **stack, unsigned int line_number);
void s_mul(stack_t **stack, unsigned int line_number);
void s_mod(stack_t **stack, unsigned int line_number);
void s_pchar(stack_t **stack, unsigned int line_number);
void s_pstr(stack_t **stack, unsigned int line_number);
void s_rotl(stack_t **stack, unsigned int line_number);
void s_rotr(stack_t **stack, unsigned int line_number);
void s_queue(stack_t **stack, unsigned int line_number);
void s_stack(stack_t **stack, unsigned int line_number);
/*verify*/
void _verify(stack_t **stack, unsigned int line_number);
int check_int(char *num);

#endif /*monty.h*/
