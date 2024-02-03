#include "monty.h"
/**
 * pint - print top of the stack
 * @head: head ptr
 * @line_num: counter
 *
 * Return: void
 */

void pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%u\n", (*head)->n);
}
/**
 * pop - delete the top element of the stack
 * @head: head ptr
 * @line_num: counter
 *
 * Return: void
 */

void pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}
