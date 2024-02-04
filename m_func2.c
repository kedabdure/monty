#include "monty.h"

/**
 * add - add top two elements
 * @head: head pointer
 * @line_num: counter
 *
 * Return: void
 */

void add(stack_t **head, unsigned int line_num)
{
	stack_t *temp1, *temp2;
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp1 = *head;
	temp2 = (*head)->next;
	temp2->n = temp2->n + (*head)->n;
	if ((*head)->next != NULL)
		*head = (*head)->next;
	free(temp1);
}
