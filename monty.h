#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
 * struct bus_s - carries vriables around
 * @arg: argument to functions
 * @data: string from file
 * @file: file descriptor
 * @st_or_que: determines if implementation is LIFO or FIFO
 *
 * Description: this helps to move variables across the
 * program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *data;
	int st_or_que;
} bus_t;
extern bus_t bus;
void f_push(stack_t **head, unsigned int line_number);
int execute(char *data, stack_t **top, unsigned int line_number, FILE *fp);
void add_node_stack(stack_t **head, int n);
void f_pall(stack_t **head, unsigned int line_number);
void free_stack(stack_t *top);
void f_pint(stack_t **head, unsigned int line_number);
void f_pop(stack_t **head, unsigned int line_number);
void f_swap(stack_t **head, unsigned int line_number);
void f_add(stack_t **head, unsigned int line_number);
void f_nop(stack_t **head, unsigned int line_number);
void f_sub(stack_t **head, unsigned int line_number);
void f_div(stack_t **head, unsigned int line_number);
void f_mul(stack_t **head, unsigned int line_number);
void f_mod(stack_t **head, unsigned int line_number);
void f_pchar(stack_t **head, unsigned int line_number);
void f_pstr(stack_t **head, unsigned int line_number);
void f_rotl(stack_t **head, unsigned int line_number);
void f_rotr(stack_t **head, unsigned int line_number);
void f_stack(stack_t **head, unsigned int line_number);
void f_queue(stack_t **head, unsigned int line_number);
void add_node_queue(stack_t **head, int n);

#endif /* _LISTS_H_ */
