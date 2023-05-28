#include "monty.h"
/**
 * add_node_stack - adds node to linked list
 * @head: linked list stack
 * @n: element to be inserted
 *
 * Return: nothing
 */
void add_node_stack(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
