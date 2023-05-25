#include "monty.h"

/**
 * execute - executes opcode
 * @data: content from file
 * @top: pointer to top of stack
 * @line_number: line number
 * @fp: file descriptor to file
 *
 * Return: 0 (success)
 */
int execute(char *data, stack_t **top, unsigned int line_number, FILE *fp)
{
	unsigned int i = 0;
	char *op;
	instruction_t operations[] = {{"push", f_push}, {NULL, NULL}};

	op = strtok(data, " \n\t");
	bus.arg = strtok(NULL, " \n\t");
	
	if (strcmp(op, operations[i].opcode) == 0)
	{
		operations[i].f(top, line_number);
		return (0);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	return (1);

}
