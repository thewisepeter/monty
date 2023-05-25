#include "monty.h"

/**
 * f_pall - prints elements in stack
 * @head: linked list stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *head;
	if (temp == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
