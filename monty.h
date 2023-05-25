#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

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
 * struct bus_t - carries vriables around
 * @arg: argument to functions
 * @data: string from file
 *
 * Description: this helps to move variables across the 
 * program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *data;
} bus_t;
extern bus_t bus;
void f_push(stack_t **head, unsigned int line_number);
int execute(char *data, stack_t **top, unsigned int line_number, FILE *fp);

#endif /* _LISTS_H_ */
