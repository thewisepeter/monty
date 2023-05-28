#include "monty.h"
/**
 * add_node_queue - adds node to linked list
 * @head: linked list stack
 * @n: element to be inserted
 *
 * Return: nothing
 */
void add_node_queue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
