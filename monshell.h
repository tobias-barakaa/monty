#ifndef MONSHELL_H
#define MONSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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

/**
 * struct wide_struc - function variable
 * @open_file: file
 * @exe:execute
 *
 * Description: To handle the file and getline
 */
typedef struct wide_struc
{
	FILE *open_file;
	char *exe;
} glob_t;


extern glob_t global;
extern int value;

stack_t *create_node(int n);
void insert(stack_t **stack, unsigned int num_elem);
void print_elem(stack_t **stack, unsigned int n);
void free_mem(stack_t *stack);
void free_stack(stack_t **stack);
void interchange(stack_t **stack, unsigned int line_number);
void remove_top(stack_t **stack, unsigned int line_number);
void delete_el(stack_t **stack, unsigned int line_number);
void nothing(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void int_add(stack_t **stack, unsigned int line_number);
void env_com(char *argv);
int num_elem(char *j);



void error_hand(FILE *open_file, char *exe, stack_t *stack, int count);
void error(FILE *open_file, char *exe, stack_t *stack, char *elem, int num);

#endif
