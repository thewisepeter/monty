#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}
