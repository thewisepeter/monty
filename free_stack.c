#include "monty.h"

/**
 * free_stack - frees the stack
 * @top: stack
 *
 * Return: nothing
 */
void free_stack(stack_t *top)
{
	stack_t *temp;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}
