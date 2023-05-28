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
	int n, i = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (bus.arg[0] == '-')
			i++;

		for (; bus.arg[i] != '\0'; i++)
		{
			if (!isdigit(bus.arg[i]))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(bus.file);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
		}
	}
	n = atoi(bus.arg);
	if (bus.st_or_que == 0)
		add_node_stack(head, n);
	else
		add_node_queue(head, n);
}
