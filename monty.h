#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

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

void push(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void division(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);

int _isdigit(int);
void is_opcode(char *, stack_t **, unsigned int);
char **parse(char *);
void freestack(stack_t **);
void check_push(stack_t **, char **, unsigned int);

#endif
