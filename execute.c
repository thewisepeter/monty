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
	instruction_t operations[] = {{"push", f_push},
		{"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap},
		{"add", f_add}, {"nop", f_nop},
		{"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod},
		{"pchar", f_pchar}, {"pstr", f_pstr},
		{"rotl", f_rotl}, {"rotr", f_rotr},
		{"stack", f_stack}, {"queue", f_queue},
		{NULL, NULL}};

	op = strtok(data, " \n\t");
	bus.arg = strtok(NULL, " \n\t");

	if (op == NULL || op[0] == '#')
		return (0);

	while (operations[i].opcode != NULL)
	{
		if (strcmp(op, operations[i].opcode) == 0)
		{
			operations[i].f(top, line_number);
			return (0);
		}
		i++;
	}

	if (op || operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(fp);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	return (1);
}
