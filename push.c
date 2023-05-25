#include "monty.h"

/**
 * f_push - add to the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int line_number)
{
	int n, i = 0, flag = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.data);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.data);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(bus.arg);
	add_node(head, n);
}
