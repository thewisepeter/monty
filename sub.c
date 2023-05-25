#include "monty.h"

/**
 * f_sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, dif;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	dif = temp->next->n - temp->n;
	temp->next->n = dif;

	*head = temp->next;
	free(temp);
}
